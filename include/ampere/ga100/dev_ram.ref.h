// --------------------------------------------------------------------------------
// 
// CONTENTS
// 
//     Introduction
// 
//     GPU Instance RAM (RAMIN)
// 
//     FIFO Context RAM (RAMFC)
// 
//     User-Driver Accessible RAM (RAMUSERD)
// 
//     Run-List RAM (RAMRL)
// 
//     Host Pushbuffer Format (FIFO_DMA)
// 
//     Key
// 
// INTRODUCTION
// ==================
// 
//      This device describes the various memory formats used by Host and the
// engines on the GPU.  It also defines the PRAMIN bar0 space controlled by
// NV_PBUS_BAR0_WINDOW.
// 
// Mnemonic  Description           Size  Interface
// --------  -----------           ----  ---------
// PRAMIN    Priv Ram BAR0 Window    1M  HOST

#define NV_PRAMIN                             0x007FFFFF:0x00700000 /* RW--M */




// GPU INSTANCE RAM (RAMIN)
// ==============================
// 
//      A GPU contains a block called "XVE" that manages the interface with PCI, a
// block called "Host" that fetches graphics instructions, blocks called "engines"
// that execute graphics instructions, and blocks that manage the interface with
// memory.
// 
//                .-----.                    .------.
//                |     |<------------------>|      |
//                |     |                    |      |
//                |     |     .---------.    |      |
//                |     |<--->| Engine1 |<---|      |
//                |     |     `---------'    |      |
// .---------.    |     |                    |      |
// |   GPU   |    |     |     .---------.    | ESC  |
// |  Local  |<-->|  FB |<--->| Engine2 |<---|      |
// | Memory  |    | MMU |     `---------'    |      |
// `---------'    | Hub |         ...        |      |   .--------.
//                |     |     .---------.    |      |   | System |
//                |     |<--->| EngineN |<---|      |   | Memory |
//                |     |     `---------'    `------'   `--------'
//                |     |                       ^           ^
//                |     |                       |           |
// .---------.    |     |                    .--V--. PCI .--V--.     .-----.
// | Display |<-->|     |<------------------>| XVE |<--->| NB  |<--->| CPU |
// `---------'    `-----'                    `-----'     `-----'     `-----'
// 
//      A GPU context is a virtualization of the GPU for a particular software
// application.  A GPU instance block is a block of memory that contains the state
// for a GPU context.  A GPU context's instance block consists of Host state,
// pointers to each engine's state, and memory management state.  A GPU instance
// block also contains a pointer to a block of memory that contains that part of a
// GPU context's state that a user-level driver may access.  A GPU instance block
// fits within a single 4K-byte page of memory.
// 
//      Runlist
//     .--------------.
//     | TSG0         |                       Channel RAM NV_CHRAM
//     |.-----------. |                       .------------.
//     || chid0 inst ||--+-------.            | Ch0 status |
//     || chid1 inst ||  |       |            | Ch1 status |
//     || chid2 inst ||  |       |    chid    |    ...     |
//     ||    ....    ||  |       `----------->| ChI status |
//     || chidN inst ||  |                    |    ...     |
//     |`------------'|  |                    | ChN status |
//     | ...          |  |                    `------------'
//     | TSGN         |  |
//     |.-----------. |  |
//     || chid0 inst ||  |
//     || chid1 inst ||  | inst ctx pointer
//     || chid2 inst ||  |
//     ||    ....    ||  |
//     || chidN inst ||  |
//     |`------------'|  |
//     | ...          |  |
//     `--------------'  |
//                       |
//  .--------------------'
//  |
//  |    GPU Instance Block                                 GPFIFO
//  `-->.-----------------.                        GP_GET .--------.     PB Seg
//      |                 |------------------------------>|GP Entry|    .--------.
//      |   Host State    |                               |GP Entry|--->|PB Entry|
//      |     (RAMFC)     |          User-Driver State    |        |    |PB Entry|
//      |                 |              .-------.        |GP Entry|    |   ...  |
//      |                 |------------->|(USERD)| GP_PUT |GP Entry|    |PB Entry|
//      |                 |              |       |------->`--------'    `--------'
//      |                 |              |       |
//      +-----------------+              |       |
//      |     Memory      |              `-------'
//      |   Management    |---------.  Page Directory  Page Directory   Page Table
//      |     State       |         |   .-------.       .-------.        .-------.
//      +-----------------+         `-->|  PDE  |       |  PDE  |        |  PTE  |
//      |   Pointer to    |             |  PDE  |       |  PDE  |---...->|  PTE  |
//      |     Engine0     |--------.    |  ...  |       |  ...  |        |  ...  |
//      |      State      |        |    |  PDE  |------>|  PDE  |        |  PTE  |
//      +-----------------+        |    `-------'       `-------'        `-------'
//      |   Pointer to    |        |
//      |     Engine1     |-----.  |   Engine0 State
//      |      State      |     |  |     .-------.
//      +-----------------+     |  `---->|       |
//             ...              |        `-------'
//      +-----------------+     |
//      |   Pointer to    |     |      Engine1 State
//      |     EngineN     |--.  |        .-------.
//      |      State      |  |  `------->|       |
//      `-----------------'  |           `-------'
//                           |               ...
//                           |
//                           |         EngineN State
//                           |           .-------.
//                           `---------->|       |
//                                       `-------'
// 
//      The GPU context's Host state occupies the first 128 double words of an
// instance block.  A GPU context's Host state is called "RAMFC". Please see
// the NV_RAMFC section below for a description of Host state.
// 
//      The GPU context's memory-management state defines the virtual address space
// that the GPU context uses.  Memory management state consists of page and
// directory tables (that specify the mapping between virtual addresses and
// physical addresses, and the attributes of memory pages), and the limit of the
// virtual address space.  The NV_RAMIN_PAGE_DIR_BASE entry contains the address of
// base of the GPU context's page directory table (PDB).  NV_RAMIN_PAGE_DIR_BASE is
// 4K-byte aligned.
// 
//      The NV_RAMIN_ENG*_WFI_PTR entry contains the address of a block of memory
// for storing an engine's context state.  Blocks of memory that contain engine state
// are 4K-byte aligned.  Only one engine context is supported per instance block.
// 
//      The NV_RAMIN_ENG*_CS field is deprecated, it was used to indicate whether
// GPU state should be restored from the FGCS pointer or from the WFI CS pointer.
// Engines only need/support one CTXSW pointer and all state is stored there
// whether a WFI CS or other form of preemption was performed.  This field must
// always be set to WFI for legacy reasons, and will eventually be deleted.


#define NV_RAMIN                                                    /* ----G */

// The instance block must be 4k-aligned.
#define NV_RAMIN_BASE_SHIFT                                      12 /*       */

// The instance block size fits within a single 4k block.
#define NV_RAMIN_ALLOC_SIZE                                    4096 /*       */

// Host State
#define NV_RAMIN_RAMFC                         (127*32+31):(0*32+0) /* RWXUF */

// Memory-Management State

    // The following fields are used for non-VEID engines.  The NV_RAMIN_SC_* described later
    // are used for VEID engines.
    // 
    // NV_RAMIN_PAGE_DIR_BASE_TARGET determines if the top level of the page tables
    // is in video memory or system memory (peer is not allowed), and the CPU cache
    // coherency for system memory.
    // Using INVALID, unbinds the selected engine.

#define NV_RAMIN_PAGE_DIR_BASE_TARGET               (128*32+1):(128*32+0) /* RWXUF */
#define NV_RAMIN_PAGE_DIR_BASE_TARGET_VID_MEM                  0x00000000 /* RW--V */
#define NV_RAMIN_PAGE_DIR_BASE_TARGET_INVALID                  0x00000001 /* RW--V */
#define NV_RAMIN_PAGE_DIR_BASE_TARGET_SYS_MEM_COHERENT         0x00000002 /* RW--V */
#define NV_RAMIN_PAGE_DIR_BASE_TARGET_SYS_MEM_NONCOHERENT      0x00000003 /* RW--V */

    // NV_RAMIN_PAGE_DIR_BASE_VOL identifies the volatile behavior
    // of top level of the page table (whether local L2 can cache it or not).

#define NV_RAMIN_PAGE_DIR_BASE_VOL                  (128*32+2):(128*32+2) /* RWXUF */
#define NV_RAMIN_PAGE_DIR_BASE_VOL_TRUE                        0x00000001 /* RW--V */
#define NV_RAMIN_PAGE_DIR_BASE_VOL_FALSE                       0x00000000 /* RW--V */


    // These bits specify whether the MMU will treats faults as replayable or not.
    // The engine will send these bits to the MMU as part of the instance bind.

#define NV_RAMIN_PAGE_DIR_BASE_FAULT_REPLAY_TEX     (128*32+4):(128*32+4) /* RWXUF */
#define NV_RAMIN_PAGE_DIR_BASE_FAULT_REPLAY_TEX_DISABLED       0x00000000 /* RW--V */
#define NV_RAMIN_PAGE_DIR_BASE_FAULT_REPLAY_TEX_ENABLED        0x00000001 /* RW--V */
#define NV_RAMIN_PAGE_DIR_BASE_FAULT_REPLAY_GCC     (128*32+5):(128*32+5) /* RWXUF */
#define NV_RAMIN_PAGE_DIR_BASE_FAULT_REPLAY_GCC_DISABLED       0x00000000 /* RW--V */
#define NV_RAMIN_PAGE_DIR_BASE_FAULT_REPLAY_GCC_ENABLED        0x00000001 /* RW--V */

    // NV_RAMIN_USE_NEW_PT_FORMAT determines which page table format to use.
    // When NV_RAMIN_USE_NEW_PT_FORMAT is false, the page table uses the old format.
    // When NV_RAMIN_USE_NEW_PT_FORMAT is true, the page table uses the new format.
    // 
    // Volta only supports the new format.  Selecting the old format results in an UNBOUND_INSTANCE fault.


#define NV_RAMIN_USE_VER2_PT_FORMAT             (128*32+10):(128*32+10) /*       */
#define NV_RAMIN_USE_VER2_PT_FORMAT_FALSE 0x00000000 /*       */
#define NV_RAMIN_USE_VER2_PT_FORMAT_TRUE   0x00000001 /*       */

    // When NV_PFB_PRI_MMU_CTRL_USE_PDB_BIG_PAGE_SIZE is bit TRUE, the bit selects the big page size.
    // When NV_PFB_PRI_MMU_CTRL_USE_PDB_BIG_PAGE_SIZE is bit FALSE, NV_PFB_PRI_MMU_CTRL_VM_PG_SIZE selects the big page size.
    // 
    // Volta only supports 64KB for big pages.  Selecting 128KB for big pages results in an UNBOUND_INSTANCE fault.

#define NV_RAMIN_BIG_PAGE_SIZE                    (128*32+11):(128*32+11) /* RWXUF */
#define NV_RAMIN_BIG_PAGE_SIZE_128KB                           0x00000000 /* RW--V */
#define NV_RAMIN_BIG_PAGE_SIZE_64KB                            0x00000001 /* RW--V */

    // NV_RAMIN_PAGE_DIR_BASE_LO and NV_RAMIN_PAGE_DIR_BASE_HI
    // identify the page directory base (start of the page table)
    // location for this context.
    // NV_RAMIN_ADR_LIMIT was deprecated when sub-contexts was added to GV100.

#define NV_RAMIN_PAGE_DIR_BASE_LO                 (128*32+31):(128*32+12) /* RWXUF */
#define NV_RAMIN_PAGE_DIR_BASE_HI                  (129*32+31):(129*32+0) /* RWXUF */

// Single engine pointer channels cannot support multiple
// engines with CTXSW pointers
#define NV_RAMIN_ENGINE_CS                          (132*32+3):(132*32+3) /*       */
#define NV_RAMIN_ENGINE_CS_WFI                                 0x00000000 /*       */
#define NV_RAMIN_ENGINE_CS_FG                                  0x00000001 /*       */
#define NV_RAMIN_ENGINE_WFI_TARGET                  (132*32+1):(132*32+0) /*       */
#define NV_RAMIN_ENGINE_WFI_TARGET_LOCAL_MEM                   0x00000000 /*       */
#define NV_RAMIN_ENGINE_WFI_TARGET_SYS_MEM_COHERENT            0x00000002 /*       */
#define NV_RAMIN_ENGINE_WFI_TARGET_SYS_MEM_NONCOHERENT         0x00000003 /*       */
#define NV_RAMIN_ENGINE_WFI_MODE                    (132*32+2):(132*32+2) /*       */
#define NV_RAMIN_ENGINE_WFI_MODE_PHYSICAL                      0x00000000 /*       */
#define NV_RAMIN_ENGINE_WFI_MODE_VIRTUAL                       0x00000001 /*       */
#define NV_RAMIN_ENGINE_WFI_PTR_LO                (132*32+31):(132*32+12) /*       */
#define NV_RAMIN_ENGINE_WFI_PTR_HI                  (133*32+7):(133*32+0) /*       */

#define NV_RAMIN_ENGINE_WFI_VEID             (134*32+(6-1)):(134*32+0) /*       */
#define NV_RAMIN_ENABLE_ATS                        (135*32+31):(135*32+31) /* RWXUF */
#define NV_RAMIN_ENABLE_ATS_TRUE                                0x00000001 /* RW--V */
#define NV_RAMIN_ENABLE_ATS_FALSE                               0x00000000 /* RW--V */
#define NV_RAMIN_PASID                 (135*32+(20-1)):(135*32+0) /* RWXUF */


//      Pointer to a method buffer in BAR2 memory where a faulted engine can save
// out methods. BAR2 accesses are assumed to be virtual, so the address saved here
// is a virtual address.

#define NV_RAMIN_ENG_METHOD_BUFFER_ADDR_LO                   (136*32+31):(136*32+0)  /* RWXUF */
#define NV_RAMIN_ENG_METHOD_BUFFER_ADDR_HI                   (137*32+(((49-1)-32))):(137*32+0)  /* RWXUF */


    // These entries are used to inform FECS which of the below array of PDBs are
    // valid/filled in and need to subsequently be bound.
    // 
    // This needs to reserve at least NV_LITTER_NUM_SUBCTX entries.  Currently
    // there is enough space reserved for 64 subcontexts.
#define NV_RAMIN_SC_PDB_VALID(i)             (166*32+(i)):(166*32+(i)) /* RWXUF */
#define NV_RAMIN_SC_PDB_VALID__SIZE_1         64 /*       */
#define NV_RAMIN_SC_PDB_VALID_FALSE                     0x00000000 /* RW--V */
#define NV_RAMIN_SC_PDB_VALID_TRUE                      0x00000001 /* RW--V */

// Memory-Management VEID array


    // The NV_RAMIN_SC_PAGE_DIR_BASE_* entries are an array of page table settings
    // for each subcontext. When a context supports subcontexts, the page table
    // information for a given VEID/Subcontext needs to be filled in or else page
    // faults will result on access.
    // 
    // These properties for the page table must be filled in for all channels
    // sharing the same context as any channel's NV_RAMIN may be used to load the
    // context.
    // 
    // The non-subcontext page table information such as NV_RAMIN_PAGE_DIR_BASE*
    // are used by non-subcontext engines and clients such as Host, CE, or the
    // video engines.
    // 
    // NV_RAMIN_SC_PAGE_DIR_BASE_TARGET(i) determines if the top level of the page tables
    // is in video memory or system memory (peer is not allowed), and the CPU cache
    // coherency for system memory.
    // Using INVALID, unbinds the selected subcontext.

#define NV_RAMIN_SC_PAGE_DIR_BASE_TARGET(i)             ((168+(i)*4)*32+1):((168+(i)*4)*32+0) /* RWXUF */
#define NV_RAMIN_SC_PAGE_DIR_BASE_TARGET__SIZE_1                         64 /*       */
#define NV_RAMIN_SC_PAGE_DIR_BASE_TARGET_VID_MEM                  0x00000000 /* RW--V */
//Note: INVALID should match PEER
#define NV_RAMIN_SC_PAGE_DIR_BASE_TARGET_INVALID                  0x00000001 /* RW--V */
#define NV_RAMIN_SC_PAGE_DIR_BASE_TARGET_SYS_MEM_COHERENT         0x00000002 /* RW--V */
#define NV_RAMIN_SC_PAGE_DIR_BASE_TARGET_SYS_MEM_NONCOHERENT      0x00000003 /* RW--V */

    // NV_RAMIN_SC_PAGE_DIR_BASE_VOL(i) identifies the volatile behavior
    // of the top level of the page table (whether local L2 can cache it or not).

#define NV_RAMIN_SC_PAGE_DIR_BASE_VOL(i)                  ((168+(i)*4)*32+2):((168+(i)*4)*32+2) /* RWXUF */
#define NV_RAMIN_SC_PAGE_DIR_BASE_VOL__SIZE_1                         64 /*       */
#define NV_RAMIN_SC_PAGE_DIR_BASE_VOL_TRUE                        0x00000001 /* RW--V */
#define NV_RAMIN_SC_PAGE_DIR_BASE_VOL_FALSE                       0x00000000 /* RW--V */

    // NV_RAMIN_SC_PAGE_DIR_BASE_FAULT_REPLAY_TEX(i) and
    // NV_RAMIN_SC_PAGE_DIR_BASE_FAULT_REPLAY_GCC(i) bits specify whether
    // the MMU will treats faults from TEX and GCC as replayable or
    // not. Based on that fault packets are written into replayable fault
    // buffer (or not) and faulting requests are put into replay request
    // buffer (or not).
    // The last bind that does not unbind a sub-context determines the REPLAY_TEX and REPLAY_GCC for all sub-contexts.

#define NV_RAMIN_SC_PAGE_DIR_BASE_FAULT_REPLAY_TEX(i)     ((168+(i)*4)*32+4):((168+(i)*4)*32+4) /* RWXUF */
#define NV_RAMIN_SC_PAGE_DIR_BASE_FAULT_REPLAY_TEX__SIZE_1                         64 /*       */
#define NV_RAMIN_SC_PAGE_DIR_BASE_FAULT_REPLAY_TEX_DISABLED       0x00000000 /* RW--V */
#define NV_RAMIN_SC_PAGE_DIR_BASE_FAULT_REPLAY_TEX_ENABLED        0x00000001 /* RW--V */

#define NV_RAMIN_SC_PAGE_DIR_BASE_FAULT_REPLAY_GCC(i)     ((168+(i)*4)*32+5):((168+(i)*4)*32+5) /* RWXUF */
#define NV_RAMIN_SC_PAGE_DIR_BASE_FAULT_REPLAY_GCC__SIZE_1                         64 /*       */
#define NV_RAMIN_SC_PAGE_DIR_BASE_FAULT_REPLAY_GCC_DISABLED       0x00000000 /* RW--V */
#define NV_RAMIN_SC_PAGE_DIR_BASE_FAULT_REPLAY_GCC_ENABLED        0x00000001 /* RW--V */

    // NV_RAMIN_SC_USE_VER2_PT_FORMAT determines which page table format to use.
    // When NV_RAMIN_SC_USE_VER2_PT_FORMAT is false, the page table uses
    // the old format(2-level page table). When
    // NV_RAMIN_SC_USE_VER2_PT_FORMAT is true, the page table uses the
    // new format (5-level 49-bit VA format).
    // The last bind that does not unbind a sub-context determines the page table format for all sub-contexts.
    // Volta only supports the new format.  Selecting the old format results in an UNBOUND_INSTANCE fault.

#define NV_RAMIN_SC_USE_VER2_PT_FORMAT(i)          ((168+(i)*4)*32+10):((168+(i)*4)*32+10) /* RWXUF */
#define NV_RAMIN_SC_USE_VER2_PT_FORMAT__SIZE_1                   64 /*       */
#define NV_RAMIN_SC_USE_VER2_PT_FORMAT_FALSE                       0x00000000 /* RW--V */
#define NV_RAMIN_SC_USE_VER2_PT_FORMAT_TRUE                        0x00000001 /* RW--V */

    // The last bind that does not unbind a sub-context determines the big page size for all sub-contexts.
    // Volta only supports 64KB for big pages.

#define NV_RAMIN_SC_BIG_PAGE_SIZE(i)                    ((168+(i)*4)*32+11):((168+(i)*4)*32+11) /* RWXUF */
#define NV_RAMIN_SC_BIG_PAGE_SIZE__SIZE_1                   64 /*       */
#define NV_RAMIN_SC_BIG_PAGE_SIZE_64KB                            0x00000001 /* RW--V */

    // NV_RAMIN_SC_PAGE_DIR_BASE_LO(i) and NV_RAMIN_SC_PAGE_DIR_BASE_HI(i)
    // identify the page directory base (start of the page table)
    // location for subcontext i.

#define NV_RAMIN_SC_PAGE_DIR_BASE_LO(i)                ((168+(i)*4)*32+31):((168+(i)*4)*32+12) /* RWXUF */
#define NV_RAMIN_SC_PAGE_DIR_BASE_LO__SIZE_1                   64 /*       */
#define NV_RAMIN_SC_PAGE_DIR_BASE_HI(i)                 ((169+(i)*4)*32+31):((169+(i)*4)*32+0) /* RWXUF */
#define NV_RAMIN_SC_PAGE_DIR_BASE_HI__SIZE_1                   64 /*       */





    // NV_RAMIN_SC_ENABLE_ATS(i) tells whether subcontext i is ATS
    // enabled or not. In case, set to TRUE, GMMU will look for VA->PA
    // translations into both GMMU and ATS page tables.
    // ATS can be enabled or disabled per subcontext.

#define NV_RAMIN_SC_ENABLE_ATS(i)                       ((170+(i)*4)*32+31):((170+(i)*4)*32+31) /* RWXUF */
#define NV_RAMIN_SC_ENABLE_ATS__SIZE_1                                     64 /*       */

    // NV_RAMIN_SC_PASID(i) identifies the PASID (process address space
    // ID) in CPU for subcontext i. PASID is used to get ATS
    // translation when ATS page table lookup is needed. During ATS TLB
    // shootdown, PASID is also used to match against the one coming with
    // shootdown request.

#define NV_RAMIN_SC_PASID(i)                       ((170+(i)*4)*32+(20-1)):((170+(i)*4)*32+0) /* RWXUF */
#define NV_RAMIN_SC_PASID__SIZE_1                                     64 /*       */



// 
// FIFO CONTEXT RAM (RAMFC)
// ==============================
// 
// 
//      The NV_RAMFC part of a GPU-instance block contains Host's part of a virtual
// GPU's state.  Host is referred to as "FIFO". "FC" stands for FIFO Context.
// When Host switches from serving one GPU context to serving a second, Host saves
// state for the first GPU context to the first GPU context's RAMFC area, and loads
// state for the second GPU context from the second GPU context's RAMFC area.
// 
//      RAMFC is located at NV_RAMIN_RAMFC within the GPU instance block.  In
// Kepler, this is at the start of the block.  RAMFC is 4KB aligned.
// 
//      Every Host word entry in RAMFC directly corresponds to a PRI-accessible
// register.  For a description of the contents of a RAMFC entry, please see the
// description of the corresponding register in "manuals/dev_pbdma.ref".  The
// offsets of the fields within each entry in RAMFC match those of the
// corresponding register in the associated PBDMA unit's PRI space.
// 
// 
//     RAMFC Entry                     PBDMA Register
//     ------------------------------- ----------------------------------
//     NV_RAMFC_SIGNATURE               NV_PPBDMA_SIGNATURE(i)
//     NV_RAMFC_GP_BASE                 NV_PPBDMA_GP_BASE(i)
//     NV_RAMFC_GP_BASE_HI              NV_PPBDMA_GP_BASE_HI(i)
//     NV_RAMFC_GP_FETCH                NV_PPBDMA_GP_FETCH(i)
//     NV_RAMFC_GP_GET                  NV_PPBDMA_GP_GET(i)
//     NV_RAMFC_GP_PUT                  NV_PPBDMA_GP_PUT(i)
//     NV_RAMFC_PB_FETCH                NV_PPBDMA_PB_FETCH(i)
//     NV_RAMFC_PB_FETCH_HI             NV_PPBDMA_PB_FETCH_HI(i)
//     NV_RAMFC_PB_GET                  NV_PPBDMA_GET(i)
//     NV_RAMFC_PB_GET_HI               NV_PPBDMA_GET_HI(i)
//     NV_RAMFC_PB_PUT                  NV_PPBDMA_PUT(i)
//     NV_RAMFC_PB_PUT_HI               NV_PPBDMA_PUT_HI(i)
//     NV_RAMFC_PB_TOP_LEVEL_GET        NV_PPBDMA_TOP_LEVEL_GET(i)
//     NV_RAMFC_PB_TOP_LEVEL_GET_HI     NV_PPBDMA_TOP_LEVEL_GET_HI(i)
//     NV_RAMFC_GP_CRC                  NV_PPBDMA_GP_CRC(i)
//     NV_RAMFC_PB_HEADER               NV_PPBDMA_PB_HEADER(i)
//     NV_RAMFC_PB_COUNT                NV_PPBDMA_PB_COUNT(i)
//     NV_RAMFC_PB_CRC                  NV_PPBDMA_PB_CRC(i)
//     NV_RAMFC_SUBDEVICE               NV_PPBDMA_SUBDEVICE(i)
//     NV_RAMFC_METHOD0                 NV_PPBDMA_METHOD0(i)
//     NV_RAMFC_METHOD1                 NV_PPBDMA_METHOD1(i)
//     NV_RAMFC_METHOD2                 NV_PPBDMA_METHOD2(i)
//     NV_RAMFC_METHOD3                 NV_PPBDMA_METHOD3(i)
//     NV_RAMFC_DATA0                   NV_PPBDMA_DATA0(i)
//     NV_RAMFC_DATA1                   NV_PPBDMA_DATA1(i)
//     NV_RAMFC_DATA2                   NV_PPBDMA_DATA2(i)
//     NV_RAMFC_DATA3                   NV_PPBDMA_DATA3(i)
//     NV_RAMFC_TARGET                  NV_PPBDMA_TARGET(i)
//     NV_RAMFC_REF                     NV_PPBDMA_REF(i)
//     NV_RAMFC_RUNTIME                 NV_PPBDMA_RUNTIME(i)
//     NV_RAMFC_SEM_ADDR_LO             NV_PPBDMA_SEM_ADDR_LO(i)
//     NV_RAMFC_SEM_ADDR_HI             NV_PPBDMA_SEM_ADDR_HI(i)
//     NV_RAMFC_SEM_PAYLOAD_LO          NV_PPBDMA_SEM_PAYLOAD_LO(i)
//     NV_RAMFC_SEM_PAYLOAD_HI          NV_PPBDMA_SEM_PAYLOAD_HI(i)
//     NV_RAMFC_SEM_EXECUTE             NV_PPBDMA_SEM_EXECUTE(i)
//     NV_RAMFC_ACQUIRE_DEADLINE        NV_PPBDMA_ACQUIRE_DEADLINE(i)
//     NV_RAMFC_ACQUIRE                 NV_PPBDMA_ACQUIRE(i)
//     NV_RAMFC_MEM_OP_A                NV_PPBDMA_MEM_OP_A(i)
//     NV_RAMFC_MEM_OP_B                NV_PPBDMA_MEM_OP_B(i)
//     NV_RAMFC_MEM_OP_C                NV_PPBDMA_MEM_OP_C(i)
//     NV_RAMFC_HCE_CTRL                NV_PPBDMA_HCE_CTRL(i)
//     NV_RAMFC_CONFIG                  NV_PPBDMA_CONFIG(i)
//     NV_RAMFC_SET_CHANNEL_INFO        NV_PPBDMA_SET_CHANNEL_INFO(i)
//     ------------------------------- ----------------------------------

#define NV_RAMFC                                                    /* ----G */
#define NV_RAMFC_BASE_SHIFT                                      12 /*       */

    // Size of the full range of RAMFC in bytes.
#define NV_RAMFC_SIZE_VAL                                0x00000200 /*       */


#define NV_RAMFC_GP_PUT                          (0*32+31):(0*32+0) /* RW-UF */
#define NV_RAMFC_MEM_OP_A                        (1*32+31):(1*32+0) /* RW-UF */
#define NV_RAMFC_RESERVED2                       (2*32+31):(2*32+0) /* RW-UF */
#define NV_RAMFC_RESERVED3                       (3*32+31):(3*32+0) /* RW-UF */
#define NV_RAMFC_SIGNATURE                       (4*32+31):(4*32+0) /* RW-UF */
#define NV_RAMFC_GP_GET                          (5*32+31):(5*32+0) /* RW-UF */
#define NV_RAMFC_PB_GET                          (6*32+31):(6*32+0) /* RW-UF */
#define NV_RAMFC_PB_GET_HI                       (7*32+31):(7*32+0) /* RW-UF */
#define NV_RAMFC_PB_TOP_LEVEL_GET                (8*32+31):(8*32+0) /* RW-UF */
#define NV_RAMFC_PB_TOP_LEVEL_GET_HI             (9*32+31):(9*32+0) /* RW-UF */
#define NV_RAMFC_REF                           (10*32+31):(10*32+0) /* RW-UF */
#define NV_RAMFC_RUNTIME                       (11*32+31):(11*32+0) /* RW-UF */
#define NV_RAMFC_ACQUIRE                       (12*32+31):(12*32+0) /* RW-UF */
#define NV_RAMFC_ACQUIRE_DEADLINE              (13*32+31):(13*32+0) /* RW-UF */
#define NV_RAMFC_SEM_ADDR_HI                   (14*32+31):(14*32+0) /* RW-UF */
#define NV_RAMFC_SEM_ADDR_LO                   (15*32+31):(15*32+0) /* RW-UF */
#define NV_RAMFC_SEM_PAYLOAD_LO                (16*32+31):(16*32+0) /* RW-UF */
#define NV_RAMFC_SEM_EXECUTE                   (17*32+31):(17*32+0) /* RW-UF */
#define NV_RAMFC_GP_BASE                       (18*32+31):(18*32+0) /* RW-UF */
#define NV_RAMFC_GP_BASE_HI                    (19*32+31):(19*32+0) /* RW-UF */
#define NV_RAMFC_GP_FETCH                      (20*32+31):(20*32+0) /* RW-UF */
#define NV_RAMFC_PB_FETCH                      (21*32+31):(21*32+0) /* RW-UF */
#define NV_RAMFC_PB_FETCH_HI                   (22*32+31):(22*32+0) /* RW-UF */
#define NV_RAMFC_PB_PUT                        (23*32+31):(23*32+0) /* RW-UF */
#define NV_RAMFC_PB_PUT_HI                     (24*32+31):(24*32+0) /* RW-UF */
#define NV_RAMFC_MEM_OP_B                      (25*32+31):(25*32+0) /* RW-UF */
#define NV_RAMFC_RESERVED27                    (27*32+31):(27*32+0) /* RW-UF */
#define NV_RAMFC_RESERVED28                    (28*32+31):(28*32+0) /* RW-UF */
#define NV_RAMFC_GP_CRC                        (29*32+31):(29*32+0) /* RW-UF */
#define NV_RAMFC_PB_HEADER                     (33*32+31):(33*32+0) /* RW-UF */
#define NV_RAMFC_PB_COUNT                      (34*32+31):(34*32+0) /* RW-UF */
#define NV_RAMFC_SUBDEVICE                     (37*32+31):(37*32+0) /* RW-UF */
#define NV_RAMFC_PB_CRC                        (38*32+31):(38*32+0) /* RW-UF */
#define NV_RAMFC_SEM_PAYLOAD_HI                (39*32+31):(39*32+0) /* RW-UF */
#define NV_RAMFC_MEM_OP_C                      (40*32+31):(40*32+0) /* RW-UF */
#define NV_RAMFC_RESERVED20                    (41*32+31):(41*32+0) /* RW-UF */
#define NV_RAMFC_RESERVED21                    (42*32+31):(42*32+0) /* RW-UF */
#define NV_RAMFC_TARGET                        (43*32+31):(43*32+0) /* RW-UF */
#define NV_RAMFC_RESERVED44                    (44*32+31):(44*32+0) /* RW-UF */
#define NV_RAMFC_METHOD(i)                     ((48+(i)*2)*32+31):((48+(i)*2)*32+0) /* RW-UF */
#define NV_RAMFC_METHOD__SIZE_1          4 /*       */
#define NV_RAMFC_DATA(i)                       ((49+(i)*2)*32+31):((49+(i)*2)*32+0) /* RW-UF */
#define NV_RAMFC_DATA__SIZE_1            4 /*       */
#define NV_RAMFC_METHOD0                       (48*32+31):(48*32+0) /* RW-UF */
#define NV_RAMFC_DATA0                         (49*32+31):(49*32+0) /* RW-UF */
#define NV_RAMFC_METHOD1                       (50*32+31):(50*32+0) /* RW-UF */
#define NV_RAMFC_DATA1                         (51*32+31):(51*32+0) /* RW-UF */
#define NV_RAMFC_METHOD2                       (52*32+31):(52*32+0) /* RW-UF */
#define NV_RAMFC_DATA2                         (53*32+31):(53*32+0) /* RW-UF */
#define NV_RAMFC_METHOD3                       (54*32+31):(54*32+0) /* RW-UF */
#define NV_RAMFC_DATA3                         (55*32+31):(55*32+0) /* RW-UF */
#define NV_RAMFC_HCE_CTRL                      (57*32+31):(57*32+0) /* RW-UF */
#define NV_RAMFC_CONFIG                        (61*32+31):(61*32+0) /* RW-UF */
#define NV_RAMFC_SET_CHANNEL_INFO              (63*32+31):(63*32+0) /* RW-UF */

// USER-DRIVER ACCESSIBLE RAM (RAMUSERD)
// =========================================
// 
//      A user-level driver is allowed to access only a small portion of a GPU
// context's state.  The portion of a GPU context's state that a user-level driver
// can access is stored in a block of memory called NV_RAMUSERD.  NV_RAMUSERD is a
// user-level driver's window into NV_RAMFC.  The NV_RAMUSERD state for each GPU
// context is stored in an aligned NV_RAMUSERD_CHAN_SIZE-byte block of memory.
// 
//      To submit more methods, a user driver writes a PB segment to
// memory, writes a GP entry that points to the PB segment, updates GP_PUT in
// RAMUSERD, and writes the channel's handle to the
// NV_USERMODE_NOTIFY_CHANNEL_PENDING register (see dev_usermode.ref).
// 
//      The RAMUSERD data structure is updated at regular intervals as controlled
// by the NV_PFIFO_USERD_WRITEBACK setting (see dev_fifo.ref). For a particular
// channel, RAMUSERD writeback can be disabled and it is reccomended that SW track
// pushbuffer and channel progress via Host WFI_DIS semaphores rather than reading
// the RAMUSERD data structure.
// 
//      When write-back is enabled a user driver can check the GPU progress in
// executing a channel's PB segments. The driver can use:
//     * GP_GET to monitor the index of the next GP entry the GPU will process
//     * PB_GET to monitor the address of the next PB entry the GPU will process
//     * TOP_LEVEL_GET (see NV_PPBDMA_TOP_LEVEL_GET) to monitor the address of the
//       next "top-level" (non-SUBROUTINE) PB entry the GPU will process
//     * REF to monitor the current "reference count" value see NV_PPBDMA_REF.
// 
//      Each entry in RAMUSERD corresponds to a PRI-accessible PBDMA register in Host.
// For a description of the behavior and contents of a RAMUSERD entry, please see
// the description of the corresponding register in "manuals/dev_pbdma.ref".
// 
//     RAMUSERD Entry                   PBDMA Register                 Access
//     -------------------------------  -----------------------------  ----------
//     NV_RAMUSERD_GP_PUT               NV_PPBDMA_GP_PUT(i)            Read/Write
//     NV_RAMUSERD_GP_GET               NV_PPBDMA_GP_GET(i)            Read-only
//     NV_RAMUSERD_GET                  NV_PPBDMA_GET(i)               Read-only
//     NV_RAMUSERD_GET_HI               NV_PPBDMA_GET_HI(i)            Read-only
//     NV_RAMUSERD_PUT                  NV_PPBDMA_PUT(i)               Read-only
//     NV_RAMUSERD_PUT_HI               NV_PPBDMA_PUT_HI(i)            Read-only
//     NV_RAMUSERD_TOP_LEVEL_GET        NV_PPBDMA_TOP_LEVEL_GET(i)     Read-only
//     NV_RAMUSERD_TOP_LEVEL_GET_HI     NV_PPBDMA_TOP_LEVEL_GET_HI(i)  Read-only
//     NV_RAMUSERD_REF                  NV_PPBDMA_REF(i)               Read-only
//     -------------------------------  -----------------------------  ----------
// 
//      A user driver may write to NV_RAMUSERD_GP_PUT to kick off more work in a
// channel.  Although writes to the other, read-only, entries can alter memory,
// writes to those entries will not affect the operation of the GPU, and can be
// overwritten by the GPU.
// 
//      When Host loads its part of a GPU context's state from RAMFC memory, it
// may not immediately read RAMUSERD_GP_PUT.  Host can use the GP_PUT values from
// RAMFC directly from RAMFC while waiting for the RAMUSERD_GP_PUT to synchronize.
// Because reads of RAMUSERD_GP_PUT can be delayed, the value in NV_PPBDMA_GP_PUT
// can be older than the value in NV_RAMUSERD_GP_PUT.
// 
//      When Host saves a GPU context's state to NV_RAMFC, it also writes to
// NV_RAMUSERD the values of the entries other than GP_PUT.
// Because Host does not continuously write the read-only RAMFC entries, the
// read-only values in USERD memory can be older than the values in the Host PBDMA
// unit.

#define NV_RAMUSERD                                                 /* ----G */
#define NV_RAMUSERD_BASE_SHIFT             9 /*       */
#define NV_RAMUSERD_CHAN_SIZE               512 /*       */
#define NV_RAMUSERD_PUT                        (16*32+31):(16*32+0) /* RW-UF */
#define NV_RAMUSERD_GET                        (17*32+31):(17*32+0) /* RW-UF */
#define NV_RAMUSERD_REF                        (18*32+31):(18*32+0) /* RW-UF */
#define NV_RAMUSERD_PUT_HI                     (19*32+31):(19*32+0) /* RW-UF */
// FIXME REMOVE THIS ALIAS once SW removes REF_THRESHOLD
#define NV_RAMUSERD_REF_THRESHOLD              (20*32+31):(20*32+0) /*       */
#define NV_RAMUSERD_TOP_LEVEL_GET              (22*32+31):(22*32+0) /* RW-UF */
#define NV_RAMUSERD_TOP_LEVEL_GET_HI           (23*32+31):(23*32+0) /* RW-UF */
#define NV_RAMUSERD_GET_HI                     (24*32+31):(24*32+0) /* RW-UF */
#define NV_RAMUSERD_GP_GET                     (34*32+31):(34*32+0) /* RW-UF */
#define NV_RAMUSERD_GP_PUT                     (35*32+31):(35*32+0) /* RW-UF */



// 
// RUN-LIST RAM (RAMRL)
// ========================
// 
//      Software specifies the GPU contexts that hardware should "run" by writing a
// list of entries (known as a "runlist") to a 4k-aligned area of memory (beginning
// at the runlist base address as specified by the NV_PFIFO_RUNLIST_BASE_LO and
// NV_PFIFO_RUNLIST_BASE_HI registers), and by notifying Host that a new list is
// available (by writing to the NV_PFIFO_RUNLIST_SUBMIT register).
//      Submission of a new runlist causes Host to expire the timeslice of all work
// scheduled by the previous runlist, allowing it to schedule the channels present
// in the new runlist once they are fetched.  SW can check the status of the
// runlist by polling the PENDING bit of the NV_PFIFO_RUNLIST_SUBMIT_INFO register.
// See chapter 4 of dev_fifo.ref for a full description of the runlist submit
// mechanism.
//      Runlists can be stored in system memory or video memory (as specified by
// the TARGET field of the NV_PFIFO_RUNLIST_BASE_LO register).  If a runlist is
// stored in video memory, then in order to guarantee coherency software must
// execute flush or read the last runlist entry written before submitting the
// runlist to Host .
//      The size of a runlist entry data structure is 16 bytes.  Each entry
// specifies either a channel entry or a TSG header; the type is determined by the
// NV_RAMRL_ENTRY_TYPE.
// 
// 
// Runlist Channel Entry Type:
// 
//      A runlist entry of type NV_RAMRL_ENTRY_TYPE_CHAN specifies a channel to
// run.  All such entries must occur within the span of some TSG as specified by
// the NV_RAMRL_ENTRY_TYPE_TSG described below.  If a channel entry is encountered
// outside a TSG, Host will raise the NV_PFIFO_INTR_0_SCHED_ERROR interrupt with
// the NV_PFIFO_INTR_SCHED_ERROR_CODE_BAD_TSG error code.
// 
//      The fields available in a channel runlist entry are as follows (Fig 5.1):
// 
//   ENTRY_TYPE (T)        : type of this entry: ENTRY_TYPE_CHAN
//   CHID (ID)             : identifier of the channel to run (overlays ENTRY_ID)
//   RUNQUEUE_SELECTOR (Q) : selects which PBDMA should run this channel if
//                           more than one PBDMA is supported by the runlist
// 
//   INST_PTR_LO           : lower 20 bits of the 4k-aligned instance block pointer
//   INST_PTR_HI           : upper 32 bit of instance block pointer
//   INST_TARGET (TGI)     : aperture of the instance block
// 
//   USERD_PTR_LO          : upper 24 bits of the low 32 bits, of the 512-byte-aligned USERD pointer
//   USERD_PTR_HI          : upper 32 bits of USERD pointer
//   USERD_TARGET (TGU)    : aperture of the USERD data structure
// 
//      CHID is a channel identifier that uniquely specifies the channel described
// by this runlist entry to the scheduling hardware and is reported in various
// status registers.
// 
//      RUNQUEUE_SELECTOR determines to which runqueue the channel belongs, and
// thereby which PBDMA will run the channel.  Increasing values select increasingly
// numbered PBDMA IDs serving the runlist.  If the selector value exceeds the
// number of PBDMAs on the runlist, the hardware will silently reassign the channel
// to run on the first PBDMA as though RUNQUEUE_SELECTOR had been set to 0.  (In
// current hardware, this is used by SCG on the graphics runlist only to determine
// which FE pipe should service a given channel.  A value of 0 targets the first FE
// pipe, which can process all FE driven engines: Graphics, Compute, Inline2Memory,
// and TwoD.  A value of 1 targets the second FE pipe, which can only process
// Compute work.  Note that GRCE work is allowed on either runqueue.)
// 
//      The INST fields specify the physical address of the channel's instance
// block, the in-memory data structure that stores the context state.
// The target aperture of the instance block is given by INST_TARGET, and the byte
// offset within that aperture is calculated as
// 
//  (INST_PTR_HI << 32) | (INST_PTR_LO  << NV_RAMRL_ENTRY_CHAN_INST_PTR_ALIGN_SHIFT)
// 
// See NV_RAMIN and NV_RAMFC for the format of the instance block.
// 
// Note: If an INVALID aperture is provided hardware will silently use
// INST_TARGET_VID_MEM.
// 
//      The USERD fields specify the physical address of the USERD memory region
// used by software to submit additional work to the channel.  The target aperture
// of the USERD region is given by USERD_TARGET, and the byte offset within that
// aperture is calculated as
// 
//  (USERD_PTR_HI << 32) | (USERD_PTR_LO  << NV_RAMRL_ENTRY_CHAN_USERD_PTR_ALIGN_SHIFT)
// 
// 
// SW uses the NV_RAMUSERD_CHAN_SIZE define to allocate and align a channel's
// RAMUSERD data structure.  See the documentation for NV_RAMUSERD for a
// description of the use of USERD and its format.
// The hardware uses NV_RAMRL_ENTRY_CHAN_USERD_PTR_LO and
// NV_RAMRL_ENTRY_CHAN_USERD_PTR_HI fields for USERD pointer. The pointer is
// specified in each channel entry in the runlist.
// 
// 
// Runlist TSG Entry Type:
// 
//      The other type of runlist entry is Timeslice Group (TSG) header entry
// (Fig 5.2).  This type of entry is specified by NV_RAMRL_ENTRY_TYPE_TSG.  A TSG
// entry describes a collection of channels all of which share the same context and
// are scheduled as a single unit by Host.  All runlists support this type of
// entry.
// 
//      The fields available in a TSG header runlist entry are as follows (Fig 5.2):
// 
//   ENTRY_TYPE (T)      : type of this entry: ENTRY_TYPE_TSG
//   TSGID               : identifier of the Timeslice group (overlays ENTRY_ID)
//   TSG_LENGTH          : number of channels that are part of this timeslice group
//   GFID                : GPU function id (for future)
//   TIMESLICE_SCALE     : scale factor for the TSG's timeslice
//   TIMESLICE_TIMEOUT   : timeout amount for the TSG's timeslice
// 
//      A timeslice group entry consists of an integer identifier along with a
// length which specifies the number of channels in the TSG.  After a TSG header
// runlist entry, the next TSG_LENGTH runlist entries are considered to be part of
// the timeslice group.  Note that the minimum length of a TSG is at least one entry.
// 
//      All channels in a TSG share the same runlist timeslice which specifies how
// long a single context runs on an engine or PBDMA before being swapped for a
// different context.  The timeslice period is set in the TSG header by specifying
// TSG_TIMESLICE_TIMEOUT and TSG_TIMESLICE_SCALE.  The TSG timeslice period is
// calculated as follows:
// 
//   timeslice = (TSG_TIMESLICE_TIMEOUT << TSG_TIMESLICE_SCALE) * 1024 nanoseconds
// 
//      The timeslice period should normally not be set to zero.  A timeslice of
// zero will be treated as a timeslice period of one .  The runlist
// timeslice period begins after the context has been loaded on a PBDMA but is
// paused while the channel has an outstanding context load to an engine.  Time
// spent switching a context into an engine is not part of the runlist timeslice.
// 
//      If Host reaches the end of the runlist or receives another entry of type
// NV_RAMRL_ENTRY_TYPE_TSG before processing TSG_LENGTH additional runlist entries,
// or if it encounters a TSG of length 0, a SCHED_ERROR interrupt will be generated
// with ERROR_CODE_BAD_TSG.
// 
// 
// Host Scheduling Memory Layout:
// 
// Example of graphics runlist entry to GPU context mapping via channel id:
// 
// 
//                            .------Ints_ptr -------.
//                            |                      |
//      Graphics Runlist      |    Channel-Map RAM   |          GPU Instance Block
//      .------------ .       |  .----------------.  |        .-------------------.
//      | TSG Hdr L=m |--.----'  |Ch0 Inst Blk Ptr|--'------->| Host State        |
//      | RL Entry T1 |  |       |Ch1 Inst Blk Ptr|    .------| Memory State      |
//      | RL Entry T2 |  |       |       ...      |    |      | Engine0 State Ptr |
//      |    ...      |  |-chid->|ChI Inst Blk Ptr|    |      | Engine1 State Ptr |
//      | RL Entry Tm |  |       |       ...      |    |      |     ...           |
//      | TSG Hdr L=n |  |       |ChN Inst Blk Ptr|    |    .-| EngineN State Ptr |
//      | RL Entry T1 |  |       `----------------'    |    | `-------------------'
//      | RL Entry T2 |userd_ptr                       |    |
//      |    ...      |  |        .--------------.     |    |   .--------------.
//      | RL Entry Tn |  |        |    USERD     |     |    |   |  Engine Ctx  |
//      |             |  '------->|              |<----'    '-->|    State N   |
//      `-------------'           |              |              |              |
//                                `--------------'              `--------------'
// 
// Runlist Diagram Description:
//     Here we have (M+N) number of channel type (ENTRY_TYPE_CHID) runlist entries
// grouped together within two TSGs. The first entry in the runlist is a TSG header
// entry (ENTRY_TYPE_TSG) that describes the first TSG. The TSG header specifies m
// as the length of the TSG. The header would also contain the timeslice
// information for the TSG (SCALE/TIMEOUT), as well as the TSG id specified in the
// TSGID field.
// Note: The timeslice cannot be disabled. Timeslice value of 0 will be used as
// 1 us by hardware.
//     Because the length here is M, the Runlist *must* contain M additional
// runlist entries of type ENTRY_TYPE_CHAN that will be part of this TSG.
// Similarly, the next (N+1) number of entries, a TSG header entry followed by N
// number of regular channel entry, correspond to the second TSG.

#define NV_RAMRL_ENTRY_RANGE                          0xF:0x00000000 /* RW--M */
#define NV_RAMRL_ENTRY                                               /* ----G */
#define NV_RAMRL_ENTRY_SIZE                                       16 /*       */
// Runlist base must be 4k-aligned.
#define NV_RAMRL_ENTRY_BASE_SHIFT                                 12 /*       */


#define NV_RAMRL_ENTRY_TYPE                        (0+0*32):(0+0*32) /* RWXUF */
#define NV_RAMRL_ENTRY_TYPE_CHAN                          0x00000000 /* RW--V */
#define NV_RAMRL_ENTRY_TYPE_TSG                           0x00000001 /* RW--V */

#define NV_RAMRL_ENTRY_ID                         (11+2*32):(0+2*32) /* RWXUF */
#define NV_RAMRL_ENTRY_ID_HW                      10:0 /* RWXUF */
#define NV_RAMRL_ENTRY_ID_MAX              (2048-1) /* RW--V */





#define NV_RAMRL_ENTRY_CHAN_RUNQUEUE_SELECTOR      (1+0*32):(1+0*32) /* RWXUF */

#define NV_RAMRL_ENTRY_CHAN_INST_TARGET                   (5+0*32):(4+0*32) /* RWXUF */
#define NV_RAMRL_ENTRY_CHAN_INST_TARGET_VID_MEM                  0x00000000 /* RW--V */
#define NV_RAMRL_ENTRY_CHAN_INST_TARGET_SYS_MEM_COHERENT         0x00000002 /* RW--V */
#define NV_RAMRL_ENTRY_CHAN_INST_TARGET_SYS_MEM_NONCOHERENT      0x00000003 /* RW--V */

#define NV_RAMRL_ENTRY_CHAN_USERD_TARGET                  (7+0*32):(6+0*32) /* RWXUF */
#define NV_RAMRL_ENTRY_CHAN_USERD_TARGET_VID_MEM                 0x00000000 /* RW--V */
#define NV_RAMRL_ENTRY_CHAN_USERD_TARGET_VID_MEM_NVLINK_COHERENT 0x00000001 /* RW--V */
#define NV_RAMRL_ENTRY_CHAN_USERD_TARGET_SYS_MEM_COHERENT        0x00000002 /* RW--V */
#define NV_RAMRL_ENTRY_CHAN_USERD_TARGET_SYS_MEM_NONCOHERENT     0x00000003 /* RW--V */

#define NV_RAMRL_ENTRY_CHAN_USERD_PTR_LO          (31+0*32):(8+0*32) /* RWXUF */
#define NV_RAMRL_ENTRY_CHAN_USERD_PTR_HI          (31+1*32):(0+1*32) /* RWXUF */
#define NV_RAMRL_ENTRY_CHAN_USERD_PTR_HI_HW        (7+1*32):(0+1*32) /* RWXUF */

#define NV_RAMRL_ENTRY_CHAN_CHID                  (11+2*32):(0+2*32) /* RWXUF */

#define NV_RAMRL_ENTRY_CHAN_INST_PTR_LO          (31+2*32):(12+2*32) /* RWXUF */
#define NV_RAMRL_ENTRY_CHAN_INST_PTR_HI           (31+3*32):(0+3*32) /* RWXUF */



// Macros for shifting out low bits of INST_PTR and USERD_PTR.
#define NV_RAMRL_ENTRY_CHAN_INST_PTR_ALIGN_SHIFT                  12 /*       */
#define NV_RAMRL_ENTRY_CHAN_USERD_PTR_ALIGN_SHIFT                  8 /*       */
// Define specifying the location of the INST target in bind requests to FB
#define NV_RAMRL_ENTRY_CHAN_INST_TARGET_FB_BIND_SHIFT             28 /*       */






#define NV_RAMRL_ENTRY_TSG_GFID                   (11+0*32):(4+0*32) /* RWXUF */
#define NV_RAMRL_ENTRY_TSG_TIMESLICE_SCALE       (19+0*32):(16+0*32) /* RWXUF */
#define NV_RAMRL_ENTRY_TSG_TIMESLICE_SCALE_3              0x00000003 /* RWI-V */
#define NV_RAMRL_ENTRY_TSG_TIMESLICE_TIMEOUT     (31+0*32):(24+0*32) /* RWXUF */
#define NV_RAMRL_ENTRY_TSG_TIMESLICE_TIMEOUT_128          0x00000080 /* RWI-V */
#define NV_RAMRL_ENTRY_TSG_TIMESLICE_TIMEOUT_1            0x00000000 /* RW--V */

#define NV_RAMRL_ENTRY_TSG_LENGTH                  (7+1*32):(0+1*32) /* RWXUF */
#define NV_RAMRL_ENTRY_TSG_LENGTH_INIT                    0x00000000 /* RW--V */
#define NV_RAMRL_ENTRY_TSG_LENGTH_MIN                     0x00000001 /* RW--V */
#define NV_RAMRL_ENTRY_TSG_LENGTH_MAX                     0x00000080 /* RW--V */

#define NV_RAMRL_ENTRY_TSG_TSGID                  (11+2*32):(0+2*32) /* RWXUF */




// Host Pushbuffer Format (FIFO_DMA)
// =======================================
// 
//      "FIFO" refers to Host.  "FIFO_DMA" means data that Host reads from memory:
// the pushbuffer.  Host autonomously reads pushbuffer data from memory and
// generates method address/data pairs from the data.
// 
//      Pushbuffer terminology:
// 
//      - A channel is the logical sequence of instructions associated with a GPU
//        context.
// 
//      - The pushbuffer is a stream of data in memory containing the
//        specifications of the operations that a channel is to perform for a
//        particular client.  Pushbuffer data consists of pushbuffer entries.
// 
//      - A pushbuffer entry (PB entry) is a 32-bit (doubleword) sized unit of
//        pushbuffer data.  This is the smallest granularity at which Host consumes
//        pushbuffer data.  A PB entry is either a PB instruction (which is either
//        a PB control entry or a PB method header), or a method data entry.
// 
//      - A pushbuffer segment (PB segment) is a contiguous block of memory
//        containing pushbuffer entries.  The location and size of a pushbuffer
//        segment is defined by its respective GP entry in the GPFIFO.
// 
//      - A pushbuffer control entry (PB control entry) is a single PB entry of
//        type SET_SUBDEVICE_MASK, STORE_SUBDEVICE_MASK, USE_SUBDEVICE_MASK,
//        END_PB_SEGMENT, or a universal NOP (NV_FIFO_DMA_NOP).
// 
//      - A pushbuffer compressed method sequence is a sequence of pushbuffer
//        entries starting with a method header and a variable-length sequence of
//        method data entries (the length being defined by the method header).  A
//        single PB compressed method sequence expands into one or more methods.
//        This may also be known as a "pushbuffer method" (PB method), but that
//        terminology is ambiguous and not preferred.
// 
//      - A pushbuffer method header (PB method header) is the first PB entry found
//        in a PB compressed method sequence.  A PB method header is a PB
//        instruction performed on method data entries.
// 
//      - A pushbuffer instruction (PB instruction) is a PB entry that is not a PB
//        method data entry.  A PB instruction is either a PB control entry or a PB
//        method header.
// 
//      - A method is an address/data pair representing an operation to perform.
// 
//      - A method data entry is the 32-bit operand for its corresponding method.



#define NV_FIFO_DMA_PB_ENTRY_SIZE                                 4 /*       */


//      Some engines such as Graphics internally support a double-wide method FIFO;
// these are known as "data-hi" methods.  It is Host that performs the packing of
// two methods into one double-wide entry.  Host will only generate data-hi methods
// if the following conditions are satisfied:
// 
//      1. The two methods come from the same PB method (in other words they share
//         the same method header).
// 
//      2. The method header specifies a non-incrementing method, an incrementing
//         method, or an increment-once method.
// 
//      3. The paired methods either have the same method address, or the first
//         method has an even NV_FIFO_DMA_METHOD_ADDRESS field and the second
//         (data-hi) method is the increment of the first.  (That is, the
//         left-shifted method address as listed in the class files must be
//         divisible by 8 for this condition to hold.)
// 
//      4. The second method is available at the time of pushing the first one into
//         the engine's method FIFO. In other words, Host will not wait to pack
//         methods.  Note that if the engine's method fifo is full, the
//         back-pressure will in itself create a "wait time".
// 
// The first three conditions are under SW's control.  Only the graphics engine
// supports data-hi methods.
// 
// 
// Types of PB Entries
// 
//      PB entries can be classified into three types: PB method headers, PB
// control entries, and PB method data.  Different types of PB entries have
// different formats.  Because PB compressed method sequences are of variable
// length, it is impossible to determine the type of a PB entry without tracking
// the pushbuffer from the beginning or from the location of a PB entry that is
// known to not be a PB method data entry.
// 
//      A PB method data entry is always found in a method data sequence
// immediately following a PB method header in the logical stream of PB entries.
// The PB method header contains a NV_FIFO_DMA_METHOD_COUNT field, the value of
// which is equal to the length of the method data sequence.  Note a PB method
// header does not necessarily come with PB method data entries (see details below
// about immediate-data method headers and method headers for which COUNT is zero).
// Also note the PB method data entries may be located in a PB segment separate
// from their corresponding method header.  The format of any given PB method data
// entry is defined in the "NV_UDMA" section of dev_pbdma.ref.
// 
//      A PB entry that is either a PB method header or PB control entry is known
// as a PB instruction.  The type of a PB instruction is specified by the
// NV_FIFO_DMA_SEC_OP field and the NV_FIFO_DMA_TERT_OP field.
// 
//    secondary  tertiary
//     opcode     opcode   entry type
//    ---------  --------  --------------------------------
//       000        01     SET_SUBDEVICE_MASK
//       000        10     STORE_SUBDEVICE_MASK
//       000        11     USE_SUBDEVICE_MASK
//       001        xx     incrementing method header
//       011        xx     non-incrementing method header
//       100        xx     immediate-data method header
//       101        xx     increment-once method header
//       111        xx     END_PB_SEGMENT
//    ---------  --------  --------------------------------
// 
//      Types of methods:
// 
//      - A Host method is a method whose address is defined in the NV_UDMA device
//        range.
// 
//      - A Host-only method is any Host method excluding SetObject (also known as
//        NV_UDMA_OBJECT).
// 
//      - An engine method is a method whose address is not defined within the
//        NV_UDMA device range.  There are multiple engines designated by a
//        subchannel ID.  Software methods are included in this category.
// 
//      - A software method (SW method) is a method which causes an interrupt for
//        the express purpose of being handled by software.  For details see the
//        section on software methods below.
// 
//      For more information about types of methods see "HOST METHODS" and
// "RESERVED METHOD ADDRESSES" in dev_pbdma.ref.
// 
//      The method address in a PB method header (stored in the
// NV_FIFO_DMA_METHOD_ADDRESS field) is a dword-address, not a byte-address.  In
// other words the least significant two bits of the address are not stored because
// the byte-address is dword-aligned (thus the least significant two bits are
// always zero).
// 
//      The subchannel in a PB method header (stored in the
// NV_FIFO_DMA_*_SUBCHANNEL field) determines the engine to which a method will be
// sent if the method is SetObject or an engine method (otherwise, the SUBCHANNEL
// field is ignored).  SetObject enables SW to request HW to check the expectation
// that a given subchannel serves the specified class ID; see the description of
// "NV_UDMA_OBJECT" in dev_pbdma.ref.
// 
//      The mapping between subchannels and engines is fixed.  A subchannel is
// bound to a given class according to the runlist.  Each engine method is applied
// to an "object," which itself is an instance of an NV class as defined by the
// master MFS class files.  Each object belongs to an engine.  For SetObject and
// engine methods, the engine is determined entirely by the SUBCHANNEL field of
// the method's header via a fixed mapping that depends on the runlist on which the
// method arrives.
// 
//      Methods on subchannels 0-4 are handled by the primary engine served by the
// runlist, except that subchannel 4 targets GRCOPY0 and GRCOPY1 on the graphics
// runlist.  For Graphics/Compute, SetObject associates subchannels 0, 1, 2, and 3
// with class identifiers for 3D, compute, I2M, and 2D respectively.  On other
// runlists, the subchannel is ignored, and Host does not send the subchannel ID to
// the engine.  It is recommended that SW only use subchannel 4 on the dedicated
// copy engines for consistency with GRCOPY usage.
// 
//      Subchannels 5-7 are for software methods.  Any methods on these subchannels
// (including SetObject methods) are kicked back to software for handling via the
// SW method dispatch mechanism using the NV_PPBDMA_INTR_*_DEVICE interrupt.  SW
// may choose to send a SetObject method to each engine subchannel before sending
// any methods on that particular subchannel in order to support multiple software
// classes.
// 
//      If a method stream subchannel-switches from targeting graphics/compute to a
// copy engine or vice-versa, that is, to or from subchannel 4 on GR, Host will:
// 
//      1. Wait until the first engine has completed all its methods,
// 
//      2. Wait until that engine indicates that it is idle (WFI), and
// 
//      3. Send a sysmem barrier flush and wait until it completes.
// 
// Only then will Host send methods to the newly targeted engine.
// 
//      Note that this WFI will not occur for sending Host-only methods on the new
// subchannel, since Host-only methods ignore the subchannel field.  Additionally,
// when switching from CE to graphics/compute, Host forces FE to perform a cache
// invalidate.  Other subchannel switch semantics may be provided by the engines
// themselves, such as switching between subchannels 0-3 within FE.


#define NV_FIFO_DMA                                                 /* ----G */
#define NV_FIFO_DMA_METHOD_ADDRESS_OLD                         12:2 /* RWXUF */
#define NV_FIFO_DMA_METHOD_ADDRESS                             11:0 /* RWXUF */

#define NV_FIFO_DMA_SUBDEVICE_MASK                             15:4 /* RWXUF */

#define NV_FIFO_DMA_METHOD_SUBCHANNEL                         15:13 /* RWXUF */

#define NV_FIFO_DMA_TERT_OP                                   17:16 /* RWXUF */
#define NV_FIFO_DMA_TERT_OP_GRP0_SET_SUB_DEV_MASK        0x00000001 /* RW--V */
#define NV_FIFO_DMA_TERT_OP_GRP0_STORE_SUB_DEV_MASK      0x00000002 /* RW--V */
#define NV_FIFO_DMA_TERT_OP_GRP0_USE_SUB_DEV_MASK        0x00000003 /* RW--V */

#define NV_FIFO_DMA_METHOD_COUNT_OLD                          28:18 /* RWXUF */
#define NV_FIFO_DMA_METHOD_COUNT                              28:16 /* RWXUF */

#define NV_FIFO_DMA_SEC_OP                                    31:29 /* RWXUF */
#define NV_FIFO_DMA_SEC_OP_GRP0_USE_TERT                 0x00000000 /* RW--V */
#define NV_FIFO_DMA_SEC_OP_INC_METHOD                    0x00000001 /* RW--V */
#define NV_FIFO_DMA_SEC_OP_NON_INC_METHOD                0x00000003 /* RW--V */
#define NV_FIFO_DMA_SEC_OP_IMMD_DATA_METHOD              0x00000004 /* RW--V */
#define NV_FIFO_DMA_SEC_OP_ONE_INC                       0x00000005 /* RW--V */
#define NV_FIFO_DMA_SEC_OP_RESERVED6                     0x00000006 /* RW--V */
#define NV_FIFO_DMA_SEC_OP_END_PB_SEGMENT                0x00000007 /* RW--V */


// Incrementing PB Method Header Format
// 
//      An incrementing PB method header specifies that Host generate a sequence of
// methods.  The length of the sequence is defined by the method header.  The
// method data for each method in this sequence is found in a sequence of PB
// entries immediately following the method header.
// 
//      The dword-address of the first method is specified by the method header,
// and the dword-address of each subsequent method is equal to the dword-address of
// the previous method plus one.  Or in other words, the byte-address of each
// subsequent method is equal to the byte-address of the previous method plus four.
// 
// Example sequence of methods generated from an incrementing method header:
// 
//      addr    data0
//      addr+1  data1
//      addr+2  data2
//      addr+3  data3
//      ...      ...
// 
//      The NV_FIFO_DMA_INCR_COUNT field contains the number of methods in the
// generated sequence.  This is the same as the number of method data entries that
// follow the method header.  If the COUNT field is zero, the other fields are
// ignored, and the PB method effectively becomes a no-op with no method data
// entries following it.
// 
//      The NV_FIFO_DMA_INCR_SUBCHANNEL field contains the subchannel to use for
// the methods generated from the method header.  See the documentation above for
// NV_FIFO_DMA_*_SUBCHANNEL.
// 
//      The NV_FIFO_DMA_INCR_ADDRESS field contains the method address for the
// first method in the generated sequence.  The dword-address of the method is
// incremented by one each time a method is generated.  A method address specifies
// an operation to be performed.  Note that because the ADDRESS is a dword-address
// and not a byte-address, the least two significant bits of the method's
// byte-address are not stored.
// 
//      The NV_FIFO_DMA_INCR_DATA fields contain the method data for the methods in
// the generated sequence.  The number of method data entries is defined by the
// COUNT field.  A method data entry contains an operand for its respective method.
// 
//      Bit 12 is reserved for the future expansion of either the subchannel or the
// address fields.


#define NV_FIFO_DMA_INCR                                            /* ----G */
#define NV_FIFO_DMA_INCR_OPCODE                 (0*32+31):(0*32+29) /* RWXUF */
#define NV_FIFO_DMA_INCR_OPCODE_VALUE                    0x00000001 /* ----V */
#define NV_FIFO_DMA_INCR_COUNT                  (0*32+28):(0*32+16) /* RWXUF */
#define NV_FIFO_DMA_INCR_SUBCHANNEL             (0*32+15):(0*32+13) /* RWXUF */
#define NV_FIFO_DMA_INCR_ADDRESS                 (0*32+11):(0*32+0) /* RWXUF */
#define NV_FIFO_DMA_INCR_DATA                    (1*32+31):(1*32+0) /* RWXUF */


// Non-Incrementing PB Method Header Format
// 
//      A non-incrementing PB method header specifies that Host generate a sequence
// of methods.  The length of the sequence is defined by the method header.  The
// method data for each method in this sequence is contained within the PB entries
// immediately following the method header.
// 
//      Unlike with the incrementing PB method header, the sequence of methods
// generated all have the same method address.  The dword-address of every method
// in this sequence is specified by the method header.  Although the methods all
// have the same address, the method data entries may be different.
// 
// Example sequence of methods generated from a non-incrementing method header:
// 
//      addr    data0
//      addr    data1
//      addr    data2
//      addr    data3
//      ...      ...
// 
//      The NV_FIFO_DMA_NONINCR_COUNT field contains the number of methods
// in the generated sequence.  This is the same as the number of method data
// entries that follow the method header.  If the COUNT field is zero, the other
// fields are ignored, and the PB method effectively becomes a no-op with no method
// data entries following it.
// 
//      The NV_FIFO_DMA_NONINCR_SUBCHANNEL field contains the subchannel to use for
// the methods generated from the method header.  See the documentation above for
// NV_FIFO_DMA_*_SUBCHANNEL.
// 
//      The NV_FIFO_DMA_NONINCR_ADDRESS field contains the method address for every
// method in the generated sequence.  A method address specifies an operation to be
// performed.  Note that because the ADDRESS field is a dword-address and not a
// byte-address, the least two significant bits of the method's byte-address are
// not stored.
// 
//      The NV_FIFO_DMA_NONINCR_DATA fields contain the method data for the methods
// in the generated sequence.  The number of method data entries is defined by the
// COUNT field.  A method data entry contains an operand for its respective method.
// 
//      Bit 12 is reserved for the future expansion of either the subchannel or the
// address fields.


#define NV_FIFO_DMA_NONINCR                                         /* ----G */
#define NV_FIFO_DMA_NONINCR_OPCODE              (0*32+31):(0*32+29) /* RWXUF */
#define NV_FIFO_DMA_NONINCR_OPCODE_VALUE                 0x00000003 /* ----V */
#define NV_FIFO_DMA_NONINCR_COUNT               (0*32+28):(0*32+16) /* RWXUF */
#define NV_FIFO_DMA_NONINCR_SUBCHANNEL          (0*32+15):(0*32+13) /* RWXUF */
#define NV_FIFO_DMA_NONINCR_ADDRESS              (0*32+11):(0*32+0) /* RWXUF */
#define NV_FIFO_DMA_NONINCR_DATA                 (1*32+31):(1*32+0) /* RWXUF */


// Increment-Once PB Method Header Format
// 
//      An increment-once PB method header specifies that Host generate a sequence
// of methods.  The length of the sequence is defined by the method header.  The
// method data for each method in this sequence is found in a sequence of PB
// entries immediately following the method header.
// 
//      The dword-address of the first method is specified by the method header.
// The address of the second and all following methods is equal to the
// dword-address of the first method plus one.  In other words, the byte-address of
// the second and all following methods is equal to the byte-address of the first
// method plus four.
// 
// Example sequence of methods generated from an increment-once method header:
// 
//      addr     data0
//      addr+1   data1
//      addr+1   data2
//      addr+1   data3
//      ...      ...
// 
//      The NV_FIFO_DMA_ONEINCR_COUNT field contains the number of methods in the
// generated sequence.  This is the same as the number of method data entries that
// follow the method header.  If the COUNT field is zero, the other fields are
// ignored, and the PB method effectively becomes a no-op method with no method
// data entries following it.
// 
//      The NV_FIFO_DMA_ONEINCR_SUBCHANNEL field contains the subchannel to use for
// the methods generated from the method header.  See the documentation above for
// NV_FIFO_DMA_*_SUBCHANNEL.
// 
//      The NV_FIFO_DMA_ONEINCR_ADDRESS field contains the method address for the
// first method in the generated sequence.  A method address specifies an operation
// to be performed.  Note that because the ADDRESS is a dword-address and not a
// byte-address, the least two significant bits of the method's byte-address are
// not stored.
// 
//      The NV_FIFO_DMA_ONEINCR_DATA fields contain the method data for the methods
// in the generated sequence.  The number of method data entries is defined by the
// COUNT field.  A method data entry contains an operand for its respective method.
// 
//      Bit 12 is reserved for the future expansion of either the subchannel or the
// address fields.


#define NV_FIFO_DMA_ONEINCR                                         /* ----G */
#define NV_FIFO_DMA_ONEINCR_OPCODE              (0*32+31):(0*32+29) /* RWXUF */
#define NV_FIFO_DMA_ONEINCR_OPCODE_VALUE                 0x00000005 /* ----V */
#define NV_FIFO_DMA_ONEINCR_COUNT               (0*32+28):(0*32+16) /* RWXUF */
#define NV_FIFO_DMA_ONEINCR_SUBCHANNEL          (0*32+15):(0*32+13) /* RWXUF */
#define NV_FIFO_DMA_ONEINCR_ADDRESS              (0*32+11):(0*32+0) /* RWXUF */
#define NV_FIFO_DMA_ONEINCR_DATA                 (1*32+31):(1*32+0) /* RWXUF */

// 
// No-Operation PB Instruction Formats
// 
//      The method header for a no-op PB method may be specified in multiple ways,
// but the preferred way is to set the PB instruction to NV_FIFO_DMA_NOP.
// In any case NV_FIFO_DMA_NOP is a universal NOP entry that bypasses any method
// header format check, and is not considered a method header.


#define NV_FIFO_DMA_NOP                                  0x00000000 /* ----C */


// Immediate-Data PB Method Header Format
// 
//      If a method's operand fits within 13 bits, a PB method may be specified in
// a single PB entry, using the immediate-data PB method header format.  Exactly
// one method is generated from this method header.
// 
//      The NV_FIFO_DMA_IMMD_SUBCHANNEL field contains the subchannel to use for
// the method generated from the method header.  See the documentation above for
// NV_FIFO_DMA_*_SUBCHANNEL.
// 
//      The NV_FIFO_DMA_IMMD_ADDRESS field contains the method address for the
// single generated method.  A method address specifies an operation to be
// performed.  Note that because the ADDRESS is a dword-address and not a
// byte-address, the least two significant bits of the method's byte-address are
// not stored.
// 
//      The single NV_FIFO_DMA_IMMD_DATA field contains the method data for the
// generated method.  This method data contains an operand for the generated
// method.


#define NV_FIFO_DMA_IMMD                                            /* ----G */
#define NV_FIFO_DMA_IMMD_ADDRESS                               11:0 /* RWXUF */
#define NV_FIFO_DMA_IMMD_SUBCHANNEL                           15:13 /* RWXUF */
#define NV_FIFO_DMA_IMMD_DATA                                 28:16 /* RWXUF */
#define NV_FIFO_DMA_IMMD_OPCODE                               31:29 /* RWXUF */
#define NV_FIFO_DMA_IMMD_OPCODE_VALUE                    0x00000004 /* ----V */


// Set Sub-Device Mask PB Control Entry Format
// 
//      The SET_SUBDEVICE_MASK (SSDM) PB control entry is used when multiple GPU
// contexts are using the same pushbuffer (for example, for SLI or for stereo
// rendering) and there is data in the push buffer that is for only a subset of the
// GPU contexts.  This instruction allows the pushbuffer to tell a specific GPU
// context to use or ignore methods following the SET_SUBDEVICE_MASK.  While the
// logical-AND of NV_FIFO_DMA_SET_SUBDEVICE_MASK_VALUE and the GPU context's
// NV_PPBDMA_SUBDEVICE_ID value is zero, methods are ignored.  Pushbuffer control
// entries (like SET_SUBDEVICE_MASK) are not ignored.
// 
// ********************************************************************************
// Warning: When using subdevice masking, one must take care to synchronize
// properly with any later GP entries marked FETCH_CONDITIONAL.  If GP fetching
// gets too far ahead of PB processing, it is possible for a later conditional PB
// segment to be discarded prior to reaching an SSDM command that sets
// SUBDEVICE_STATUS to ACTIVE.  This would cause Host to execute garbage data.  One
// way to avoid this would be to set the SYNC_WAIT flag on any FETCH_CONDITIONAL
// segments following a subdevice reenable.
// ********************************************************************************
// 


#define NV_FIFO_DMA_SET_SUBDEVICE_MASK                              /* ----G */
#define NV_FIFO_DMA_SET_SUBDEVICE_MASK_VALUE                   15:4 /* RWXUF */
#define NV_FIFO_DMA_SET_SUBDEVICE_MASK_OPCODE                 31:16 /* RWXUF */
#define NV_FIFO_DMA_SET_SUBDEVICE_MASK_OPCODE_VALUE      0x00000001 /* ----V */


// Store Sub-Device Mask PB Control Entry Format
// 
//      The STORE_SUBDEVICE_MASK PB control entry is used to save a subdevice mask
// value to be used later by a USE_SUBDEVICE_MASK PB instruction.
// 

#define NV_FIFO_DMA_STORE_SUBDEVICE_MASK                            /* ----G */
#define NV_FIFO_DMA_STORE_SUBDEVICE_MASK_VALUE                 15:4 /* RWXUF */
#define NV_FIFO_DMA_STORE_SUBDEVICE_MASK_OPCODE               31:16 /* RWXUF */
#define NV_FIFO_DMA_STORE_SUBDEVICE_MASK_OPCODE_VALUE    0x00000002 /* ----V */


// Use Sub-Device Mask PB Control Entry Format
// 
//      The USE_SUBDEVICE_MASK PB control entry is used to apply the subdevice mask
// value saved by a STORE_SUBDEVICE_MASK PB instruction.  The effect of the mask is
// the same as for a SET_SUBDEVICE_MASK PB instruction.


#define NV_FIFO_DMA_USE_SUBDEVICE_MASK                              /* ----G */
#define NV_FIFO_DMA_USE_SUBDEVICE_MASK_OPCODE                 31:16 /* RWXUF */
#define NV_FIFO_DMA_USE_SUBDEVICE_MASK_OPCODE_VALUE      0x00000003 /* ----V */

// 
// End-PB-Segment PB Control Entry Format
// 
//      Engines may write PB segments themselves, but they cannot write GP entries.
// Because they cannot write GP entries, they cannot alter the size of a PB
// segment.  If an engine is writing a PB segment, and if it does not need to fill
// the entire PB segment it was allocated, instead of filling the remainder of the
// PB segment with no-op PB instructions, it may write a single End-PB-Segment
// control entry to indicate that the pushbuffer data contains no further valid
// data.  No further PB entries from that PB segment will be decoded or processed.
// Host may have already issued requests to fetch the remainder of the PB segment
// before an End-PB-Segment PB instruction is processed.  Host may or may not fetch
// the remainder of the PB segment.  Also note that doing a PB CRC check on this
// segment via NV_PPBDMA_GP_ENTRY1_OPCODE_PB_CRC will be indeterminate.


#define NV_FIFO_DMA_ENDSEG_OPCODE                             31:29 /* RWXUF */
#define NV_FIFO_DMA_ENDSEG_OPCODE_VALUE                  0x00000007 /* ----V */
