// --------------------------------------------------------------------------------
// 
#define NV_RUNLIST_CONFIG                                      0x000 /* RW-4R */
#define NV_RUNLIST_CONFIG_SEM_ACQ_STRENGTH                        0:0 /* RWIVF */
#define NV_RUNLIST_CONFIG_SEM_ACQ_STRENGTH_WEAK            0x00000000 /* RWI-V */
#define NV_RUNLIST_CONFIG_SEM_ACQ_STRENGTH_STRONG          0x00000001 /* RW--V */
#define NV_RUNLIST_CONFIG_SEM_REL_STRENGTH                        4:4 /* RWIVF */
#define NV_RUNLIST_CONFIG_SEM_REL_STRENGTH_WEAK            0x00000000 /* RW--V */
#define NV_RUNLIST_CONFIG_SEM_REL_STRENGTH_STRONG          0x00000001 /* RWI-V */
#define NV_RUNLIST_CONFIG_L2_EVICT                                9:8 /* RWIVF */
#define NV_RUNLIST_CONFIG_L2_EVICT_FIRST                   0x00000000 /* RWI-V */
#define NV_RUNLIST_CONFIG_L2_EVICT_NORMAL                  0x00000001 /* RW--V */
#define NV_RUNLIST_CONFIG_L2_EVICT_LAST                    0x00000002 /* RW--V */
#define NV_RUNLIST_CONFIG_SUBCH4                                10:10 /* RWXVF */
#define NV_RUNLIST_CONFIG_SUBCH4_INACTIVE                  0x00000000 /* RW--V */
#define NV_RUNLIST_CONFIG_SUBCH4_ACTIVE                    0x00000001 /* RW--V */
#define NV_RUNLIST_CHANNEL_CONFIG                              0x004 /* R--4R */
#define NV_RUNLIST_CHANNEL_CONFIG_NUM_CHANNELS_LOG2              3:0 /* C--UF */
#define NV_RUNLIST_CHANNEL_CONFIG_NUM_CHANNELS_LOG2_2K  11 /* C---V */
#define NV_RUNLIST_CHANNEL_CONFIG_CHRAM_BAR0_OFFSET             31:4 /* R-XVF */
#define NV_RUNLIST_DOORBELL_CONFIG                             0x008 /* R--4R */
#define NV_RUNLIST_DOORBELL_CONFIG_ID                          31:16 /* R-XVF */
#define NV_RUNLIST_FB_CONFIG                                   0x00C /* R--4R */
#define NV_RUNLIST_FB_CONFIG_FB_THREAD_ID                        7:0 /* R-XVF */
#define NV_RUNLIST_FB_CONFIG_ESC_ID                             15:8 /* R-XVF */
#define NV_RUNLIST_VIRTUAL_CHANNEL_CFG(i)              (0x300+(i)*4) /* RW-4A */
#define NV_RUNLIST_VIRTUAL_CHANNEL_CFG__SIZE_1   64 /*       */
#define NV_RUNLIST_VIRTUAL_CHANNEL_CFG_MASK          11:0 /*       */
#define NV_RUNLIST_VIRTUAL_CHANNEL_CFG_MASK_HW          10:0 /* RWIVF */
#define NV_RUNLIST_VIRTUAL_CHANNEL_CFG_MASK_HW_INIT      2047 /* RWI-V */
#define NV_RUNLIST_VIRTUAL_CHANNEL_CFG_SET  27:16 /*       */
#define NV_RUNLIST_VIRTUAL_CHANNEL_CFG_SET_HW  26:16 /* RWIVF */
#define NV_RUNLIST_VIRTUAL_CHANNEL_CFG_SET_HW_INIT                     0x0 /* RWI-V */
#define NV_RUNLIST_VIRTUAL_CHANNEL_CFG_PENDING_ENABLE                31:31 /* RWIVF */
#define NV_RUNLIST_VIRTUAL_CHANNEL_CFG_PENDING_ENABLE_TRUE               1 /* RW--V */
#define NV_RUNLIST_VIRTUAL_CHANNEL_CFG_PENDING_ENABLE_FALSE              0 /* RWI-V */
#define NV_RUNLIST_PBDMA_CONFIG(i)                     (0x010+(i)*4) /* R--4A */
#define NV_RUNLIST_PBDMA_CONFIG__SIZE_1 2 /*       */
#define NV_RUNLIST_PBDMA_CONFIG_PBDMA_BAR0_OFFSET              25:10 /* R-XUF */
#define NV_RUNLIST_PBDMA_CONFIG_VALID                          31:31 /* R-XUF */
#define NV_RUNLIST_PBDMA_CONFIG_VALID_TRUE                0x00000001 /* R---V */
#define NV_RUNLIST_PBDMA_CONFIG_VALID_FALSE               0x00000000 /* R---V */
#define NV_RUNLIST_ACQ_PRETEST                                 0x020 /* RW-4R */
#define NV_RUNLIST_ACQ_PRETEST_TIMEOUT                            7:0 /* RWIUF */
#define NV_RUNLIST_ACQ_PRETEST_TIMEOUT_8                   0x00000008 /* RWI-V */
#define NV_RUNLIST_ACQ_PRETEST_TIMESCALE                        15:12 /* RWIUF */
#define NV_RUNLIST_ACQ_PRETEST_TIMESCALE_0                 0x00000000 /* RWI-V */
#define NV_RUNLIST_ACQ_PRETEST_TIMESCALE_10                0x0000000a /* RW--V */
#define NV_RUNLIST_IDLE_FILTER                                 0x024 /* RW-4R */
#define NV_RUNLIST_IDLE_FILTER_PERIOD                             7:0 /* RWIUF */
#define NV_RUNLIST_IDLE_FILTER_PERIOD_INIT                 0x00000050 /* RWI-V */
#define NV_RUNLIST_IDLE_FILTER_PERIOD__PROD                0x00000064 /* RW--V */
#define NV_RUNLIST_IDLE_FILTER_PERIOD_8                    0x00000008 /* RW--V */
#define NV_RUNLIST_IDLE_FILTER_PERIOD_32                   0x00000020 /* RW--V */
#define NV_CHRAM_CHANNEL(i)                            (0x000+(i)*4) /* RW-4A */
#define NV_CHRAM_CHANNEL__SIZE_1   2048 /*       */
#define NV_CHRAM_CHANNEL_WRITE_CONTROL                          0:0 /* -WIVF */
#define NV_CHRAM_CHANNEL_WRITE_CONTROL_ONES_SET_BITS     0x00000000 /* -WI-V */
#define NV_CHRAM_CHANNEL_WRITE_CONTROL_ONES_CLEAR_BITS   0x00000001 /* -W--V */
#define NV_CHRAM_CHANNEL_ENABLE                                 1:1 /* RWIVF */
#define NV_CHRAM_CHANNEL_ENABLE_NOT_IN_USE               0x00000000 /* RWI-V */
#define NV_CHRAM_CHANNEL_ENABLE_IN_USE                   0x00000001 /* RW--V */
#define NV_CHRAM_CHANNEL_NEXT                                   2:2 /* RWIVF */
#define NV_CHRAM_CHANNEL_NEXT_FALSE                      0x00000000 /* RWI-V */
#define NV_CHRAM_CHANNEL_NEXT_TRUE                       0x00000001 /* RW--V */
#define NV_CHRAM_CHANNEL_BUSY                                   3:3 /* R-IVF */
#define NV_CHRAM_CHANNEL_BUSY_FALSE                      0x00000000 /* R-I-V */
#define NV_CHRAM_CHANNEL_BUSY_TRUE                       0x00000001 /* R---V */
#define NV_CHRAM_CHANNEL_PBDMA_FAULTED                          4:4 /* RWIVF */
#define NV_CHRAM_CHANNEL_PBDMA_FAULTED_FALSE             0x00000000 /* RWI-V */
#define NV_CHRAM_CHANNEL_PBDMA_FAULTED_TRUE              0x00000001 /* RW--V */
#define NV_CHRAM_CHANNEL_ENG_FAULTED                            5:5 /* RWIVF */
#define NV_CHRAM_CHANNEL_ENG_FAULTED_FALSE               0x00000000 /* RWI-V */
#define NV_CHRAM_CHANNEL_ENG_FAULTED_TRUE                0x00000001 /* RW--V */
#define NV_CHRAM_CHANNEL_ON_PBDMA                               6:6 /* R-IVF */
#define NV_CHRAM_CHANNEL_ON_PBDMA_FALSE                  0x00000000 /* R-I-V */
#define NV_CHRAM_CHANNEL_ON_PBDMA_TRUE                   0x00000001 /* R---V */
#define NV_CHRAM_CHANNEL_ON_ENG                                 7:7 /* R-IVF */
#define NV_CHRAM_CHANNEL_ON_ENG_FALSE                    0x00000000 /* R-I-V */
#define NV_CHRAM_CHANNEL_ON_ENG_TRUE                     0x00000001 /* R---V */
#define NV_CHRAM_CHANNEL_PENDING                                8:8 /* RWIVF */
#define NV_CHRAM_CHANNEL_PENDING_FALSE                   0x00000000 /* RWI-V */
#define NV_CHRAM_CHANNEL_PENDING_TRUE                    0x00000001 /* RW--V */
#define NV_CHRAM_CHANNEL_CTX_RELOAD                             9:9 /* RWIVF */
#define NV_CHRAM_CHANNEL_CTX_RELOAD_FALSE                0x00000000 /* RWI-V */
#define NV_CHRAM_CHANNEL_CTX_RELOAD_TRUE                 0x00000001 /* RW--V */
#define NV_CHRAM_CHANNEL_PBDMA_BUSY                           10:10 /* R-IVF */
#define NV_CHRAM_CHANNEL_PBDMA_BUSY_FALSE                0x00000000 /* R-I-V */
#define NV_CHRAM_CHANNEL_PBDMA_BUSY_TRUE                 0x00000001 /* R---V */
#define NV_CHRAM_CHANNEL_ENG_BUSY                             11:11 /* R-IVF */
#define NV_CHRAM_CHANNEL_ENG_BUSY_FALSE                  0x00000000 /* R-I-V */
#define NV_CHRAM_CHANNEL_ENG_BUSY_TRUE                   0x00000001 /* R---V */
#define NV_CHRAM_CHANNEL_ACQUIRE_FAIL                         12:12 /* RWIVF */
#define NV_CHRAM_CHANNEL_ACQUIRE_FAIL_FALSE              0x00000000 /* RWI-V */
#define NV_CHRAM_CHANNEL_ACQUIRE_FAIL_TRUE               0x00000001 /* RW--V */
#define NV_CHRAM_CHANNEL_UPDATE                                31:0 /*       */
#define NV_CHRAM_CHANNEL_UPDATE_ENABLE_CHANNEL           0x00000002 /*       */
#define NV_CHRAM_CHANNEL_UPDATE_DISABLE_CHANNEL          0x00000003 /*       */
#define NV_CHRAM_CHANNEL_UPDATE_FORCE_CTX_RELOAD         0x00000200 /*       */
#define NV_CHRAM_CHANNEL_UPDATE_RESET_PBDMA_FAULTED      0x00000011 /*       */
#define NV_CHRAM_CHANNEL_UPDATE_RESET_ENG_FAULTED        0x00000021 /*       */
#define NV_CHRAM_CHANNEL_UPDATE_CLEAR_CHANNEL            0xFFFFFFFF /*       */
#define NV_RUNLIST_SUBMIT_BASE_LO                              0x080 /* RW-4R */
#define NV_RUNLIST_SUBMIT_BASE_LO_PTR_LO                       31:12 /* RWIUF */
#define NV_RUNLIST_SUBMIT_BASE_LO_PTR_LO_NULL             0x00000000 /* RWI-V */
#define NV_RUNLIST_SUBMIT_BASE_LO_TARGET                         1:0 /* RWIVF */
#define NV_RUNLIST_SUBMIT_BASE_LO_TARGET_VID_MEM                 0x0 /* RWI-V */
#define NV_RUNLIST_SUBMIT_BASE_LO_TARGET_SYS_MEM_COHERENT        0x2 /* RW--V */
#define NV_RUNLIST_SUBMIT_BASE_LO_TARGET_SYS_MEM_NONCOHERENT     0x3 /* RW--V */
#define NV_RUNLIST_SUBMIT_BASE_LO_PTR_ALIGN_SHIFT                 12 /*       */
#define NV_RUNLIST_SUBMIT_BASE_HI                              0x084 /* RW-4R */
#define NV_RUNLIST_SUBMIT_BASE_HI_PTR_HI                         7:0 /* RWIUF */
#define NV_RUNLIST_SUBMIT_BASE_HI_PTR_HI_NULL             0x00000000 /* RWI-V */
#define NV_RUNLIST_SUBMIT                                      0x088 /* RW-4R */
#define NV_RUNLIST_SUBMIT_LENGTH                        15:0 /* RWIUF */
#define NV_RUNLIST_SUBMIT_LENGTH_ZERO             0x00000000 /* RWI-V */
#define NV_RUNLIST_SUBMIT_LENGTH_MAX              0x0000ffff /* RW--V */
#define NV_RUNLIST_SUBMIT_OFFSET                       31:16 /* RWIVF */
#define NV_RUNLIST_SUBMIT_OFFSET_ZERO             0x00000000 /* RWI-V */
#define NV_RUNLIST_SUBMIT_INFO                                 0x08C /* R--4R */
#define NV_RUNLIST_SUBMIT_INFO_PREEMPTED_TSGID                     13:0 /*       */
#define NV_RUNLIST_SUBMIT_INFO_PREEMPTED_TSGID_HW    10:0 /* R-IUF */
#define NV_RUNLIST_SUBMIT_INFO_PREEMPTED_TSGID_HW_DEFAULT    0x00000000 /* R-I-V */
#define NV_RUNLIST_SUBMIT_INFO_PREEMPTED_TSGID_VALID              14:14 /* R-IUF */
#define NV_RUNLIST_SUBMIT_INFO_PREEMPTED_TSGID_VALID_FALSE   0x00000000 /* R-I-V */
#define NV_RUNLIST_SUBMIT_INFO_PREEMPTED_TSGID_VALID_TRUE    0x00000001 /* R---V */
#define NV_RUNLIST_SUBMIT_INFO_PENDING                            15:15 /* R-IVF */
#define NV_RUNLIST_SUBMIT_INFO_PENDING_FALSE                 0x00000000 /* R-I-V */
#define NV_RUNLIST_SUBMIT_INFO_PENDING_TRUE                  0x00000001 /* R---V */
#define NV_RUNLIST_SUBMIT_INFO_PREEMPTED_OFFSET                   31:16 /* R-IVF */
#define NV_RUNLIST_SUBMIT_INFO_PREEMPTED_OFFSET_ZERO         0x00000000 /* R-I-V */
#define NV_RUNLIST_INTR_VECTORID(i)                    (0x160+(i)*4) /* RW-4A */
#define NV_RUNLIST_INTR_VECTORID__SIZE_1          2 /*       */
#define NV_RUNLIST_INTR_VECTORID__PRIV_LEVEL_MASK  "NV_RUNLIST_INTR_PRIV_LEVEL_MASK" /*       */
#define NV_RUNLIST_INTR_VECTORID_VECTOR                                         11:0 /* RWXUF */
#define NV_RUNLIST_INTR_VECTORID_GSP                                           30:30 /* RWIUF */
#define NV_RUNLIST_INTR_VECTORID_GSP_DISABLE                                       0 /* RW--V */
#define NV_RUNLIST_INTR_VECTORID_GSP_ENABLE                                        1 /* RWI-V */
#define NV_RUNLIST_INTR_VECTORID_CPU                                           31:31 /* RWIUF */
#define NV_RUNLIST_INTR_VECTORID_CPU_DISABLE                                       0 /* RW--V */
#define NV_RUNLIST_INTR_VECTORID_CPU_ENABLE                                        1 /* RWI-V */
#define NV_RUNLIST_INTR_RETRIGGER(i)                   (0x180+(i)*4) /* -W-4A */
#define NV_RUNLIST_INTR_RETRIGGER__SIZE_1           2 /*       */
#define NV_RUNLIST_INTR_RETRIGGER__PRIV_LEVEL_MASK   "NV_RUNLIST_INTR_PRIV_LEVEL_MASK" /*       */
#define NV_RUNLIST_INTR_RETRIGGER_TRIGGER                                          0:0 /* -W-VF */
#define NV_RUNLIST_INTR_RETRIGGER_TRIGGER_TRUE                                       1 /* -W--V */
#define NV_RUNLIST_INTR_0                                      0x100 /* RW-4R */
#define NV_RUNLIST_INTR_0_CTXSW_TIMEOUT_ENG0                      0:0 /* RWIVF */
#define NV_RUNLIST_INTR_0_CTXSW_TIMEOUT_ENG0_NOT_PENDING   0x00000000 /* R-I-V */
#define NV_RUNLIST_INTR_0_CTXSW_TIMEOUT_ENG0_PENDING       0x00000001 /* R---V */
#define NV_RUNLIST_INTR_0_CTXSW_TIMEOUT_ENG0_RESET         0x00000001 /* -W--V */
#define NV_RUNLIST_INTR_0_CTXSW_TIMEOUT_ENG1                      1:1 /* RWIVF */
#define NV_RUNLIST_INTR_0_CTXSW_TIMEOUT_ENG1_NOT_PENDING   0x00000000 /* R-I-V */
#define NV_RUNLIST_INTR_0_CTXSW_TIMEOUT_ENG1_PENDING       0x00000001 /* R---V */
#define NV_RUNLIST_INTR_0_CTXSW_TIMEOUT_ENG1_RESET         0x00000001 /* -W--V */
#define NV_RUNLIST_INTR_0_CTXSW_TIMEOUT_ENG2                      2:2 /* RWIVF */
#define NV_RUNLIST_INTR_0_CTXSW_TIMEOUT_ENG2_NOT_PENDING   0x00000000 /* R-I-V */
#define NV_RUNLIST_INTR_0_CTXSW_TIMEOUT_ENG2_PENDING       0x00000001 /* R---V */
#define NV_RUNLIST_INTR_0_CTXSW_TIMEOUT_ENG2_RESET         0x00000001 /* -W--V */
#define NV_RUNLIST_INTR_0_CTXSW_TIMEOUT_ENG(i)                (i):(i) /*       */
#define NV_RUNLIST_INTR_0_CTXSW_TIMEOUT_ENG__SIZE_1  3 /*       */
#define NV_RUNLIST_INTR_0_CTXSW_TIMEOUT_ENG_NOT_PENDING    0x00000000 /*       */
#define NV_RUNLIST_INTR_0_CTXSW_TIMEOUT_ENG_PENDING        0x00000001 /*       */
#define NV_RUNLIST_INTR_0_CTXSW_TIMEOUT_ENG_RESET          0x00000001 /*       */
#define NV_RUNLIST_INTR_0_CTXSW_TIMEOUT_GRCE(i)       ((i)+1):((i)+1) /*       */
#define NV_RUNLIST_INTR_0_CTXSW_TIMEOUT_GRCE__SIZE_1  2 /*       */
#define NV_RUNLIST_INTR_0_CTXSW_TIMEOUT_GRCE_NOT_PENDING   0x00000000 /*       */
#define NV_RUNLIST_INTR_0_CTXSW_TIMEOUT_GRCE_PENDING       0x00000001 /*       */
#define NV_RUNLIST_INTR_0_CTXSW_TIMEOUT_GRCE_RESET         0x00000001 /*       */
#define NV_RUNLIST_INTR_0_RUNLIST_IDLE                            4:4 /* RWIVF */
#define NV_RUNLIST_INTR_0_RUNLIST_IDLE_NOT_PENDING         0x00000000 /* R-I-V */
#define NV_RUNLIST_INTR_0_RUNLIST_IDLE_PENDING             0x00000001 /* R---V */
#define NV_RUNLIST_INTR_0_RUNLIST_IDLE_RESET               0x00000001 /* -W--V */
#define NV_RUNLIST_INTR_0_RUNLIST_AND_ENG_IDLE                    5:5 /* RWXVF */
#define NV_RUNLIST_INTR_0_RUNLIST_AND_ENG_IDLE_NOT_PENDING 0x00000000 /* R---V */
#define NV_RUNLIST_INTR_0_RUNLIST_AND_ENG_IDLE_PENDING     0x00000001 /* R---V */
#define NV_RUNLIST_INTR_0_RUNLIST_AND_ENG_IDLE_RESET       0x00000001 /* -W--V */
#define NV_RUNLIST_INTR_0_RUNLIST_ACQUIRE                         6:6 /* RWXVF */
#define NV_RUNLIST_INTR_0_RUNLIST_ACQUIRE_NOT_PENDING      0x00000000 /* R---V */
#define NV_RUNLIST_INTR_0_RUNLIST_ACQUIRE_PENDING          0x00000001 /* R---V */
#define NV_RUNLIST_INTR_0_RUNLIST_ACQUIRE_RESET            0x00000001 /* -W--V */
#define NV_RUNLIST_INTR_0_RUNLIST_ACQUIRE_AND_ENG_IDLE                      7:7 /* RWXVF */
#define NV_RUNLIST_INTR_0_RUNLIST_ACQUIRE_AND_ENG_IDLE_NOT_PENDING   0x00000000 /* R---V */
#define NV_RUNLIST_INTR_0_RUNLIST_ACQUIRE_AND_ENG_IDLE_PENDING       0x00000001 /* R---V */
#define NV_RUNLIST_INTR_0_RUNLIST_ACQUIRE_AND_ENG_IDLE_RESET         0x00000001 /* -W--V */
#define NV_RUNLIST_INTR_0_BAD_TSG                                         12:12 /* RWIVF */
#define NV_RUNLIST_INTR_0_BAD_TSG_NOT_PENDING                        0x00000000 /* R-I-V */
#define NV_RUNLIST_INTR_0_BAD_TSG_PENDING                            0x00000001 /* R---V */
#define NV_RUNLIST_INTR_0_BAD_TSG_RESET                              0x00000001 /* -W--V */
#define NV_RUNLIST_INTR_0_TSG_PREEMPT_COMPLETE                    8:8 /* RWIVF */
#define NV_RUNLIST_INTR_0_TSG_PREEMPT_COMPLETE_NOT_PENDING 0x00000000 /* R-I-V */
#define NV_RUNLIST_INTR_0_TSG_PREEMPT_COMPLETE_PENDING     0x00000001 /* R---V */
#define NV_RUNLIST_INTR_0_TSG_PREEMPT_COMPLETE_RESET       0x00000001 /* -W--V */
#define NV_RUNLIST_INTR_0_PBDMA0_INTR_TREE_0                    16:16 /* R-XVF */
#define NV_RUNLIST_INTR_0_PBDMA0_INTR_TREE_0_NOT_PENDING   0x00000000 /* R---V */
#define NV_RUNLIST_INTR_0_PBDMA0_INTR_TREE_0_PENDING       0x00000001 /* R---V */
#define NV_RUNLIST_INTR_0_PBDMA1_INTR_TREE_0                    17:17 /* R-XVF */
#define NV_RUNLIST_INTR_0_PBDMA1_INTR_TREE_0_NOT_PENDING   0x00000000 /* R---V */
#define NV_RUNLIST_INTR_0_PBDMA1_INTR_TREE_0_PENDING       0x00000001 /* R---V */
#define NV_RUNLIST_INTR_0_PBDMA0_INTR_TREE_1                    18:18 /* R-XVF */
#define NV_RUNLIST_INTR_0_PBDMA0_INTR_TREE_1_NOT_PENDING   0x00000000 /* R---V */
#define NV_RUNLIST_INTR_0_PBDMA0_INTR_TREE_1_PENDING       0x00000001 /* R---V */
#define NV_RUNLIST_INTR_0_PBDMA1_INTR_TREE_1                    19:19 /* R-XVF */
#define NV_RUNLIST_INTR_0_PBDMA1_INTR_TREE_1_NOT_PENDING   0x00000000 /* R---V */
#define NV_RUNLIST_INTR_0_PBDMA1_INTR_TREE_1_PENDING       0x00000001 /* R---V */
#define NV_RUNLIST_INTR_0_PBDMAi_INTR_TREE_j(i,j) (16+(i)+(j)*2):(16+(i)+(j)*2) /*       */
#define NV_RUNLIST_INTR_0_PBDMAi_INTR_TREE_j__SIZE_1  2 /*       */
#define NV_RUNLIST_INTR_0_PBDMAi_INTR_TREE_j__SIZE_2  2 /*       */
#define NV_RUNLIST_INTR_0_PBDMAi_INTR_TREE_j_NOT_PENDING   0x00000000 /*       */
#define NV_RUNLIST_INTR_0_PBDMAi_INTR_TREE_j_PENDING       0x00000001 /*       */
#define NV_RUNLIST_INTR_0_RUNLIST_PREEMPT_COMPLETE                    9:9 /* RWIVF */
#define NV_RUNLIST_INTR_0_RUNLIST_PREEMPT_COMPLETE_NOT_PENDING 0x00000000 /* R-I-V */
#define NV_RUNLIST_INTR_0_RUNLIST_PREEMPT_COMPLETE_PENDING     0x00000001 /* R---V */
#define NV_RUNLIST_INTR_0_RUNLIST_PREEMPT_COMPLETE_RESET       0x00000001 /* -W--V */
#define NV_RUNLIST_INTR_0_RUNLIST_EVENT                               9:9 /*       */
#define NV_RUNLIST_INTR_0_MASK_SET                             0x110 /* RW-4R */
#define NV_RUNLIST_INTR_0_MASK_SET_TSG_PREEMPT_COMPLETE                     8:8 /* RWIVF */
#define NV_RUNLIST_INTR_0_MASK_SET_TSG_PREEMPT_COMPLETE_DISABLED     0x00000000 /* RWI-V */
#define NV_RUNLIST_INTR_0_MASK_SET_TSG_PREEMPT_COMPLETE_ENABLED      0x00000001 /* RW--V */
#define NV_RUNLIST_INTR_0_MASK_CLEAR                           0x118 /* RW-4R */
#define NV_RUNLIST_INTR_0_MASK_CLEAR_TSG_PREEMPT_COMPLETE                   8:8 /* RWIVF */
#define NV_RUNLIST_INTR_0_MASK_CLEAR_TSG_PREEMPT_COMPLETE_DISABLED   0x00000000 /* RWI-V */
#define NV_RUNLIST_INTR_0_MASK_CLEAR_TSG_PREEMPT_COMPLETE_ENABLED    0x00000001 /* RW--V */
#define NV_RUNLIST_INTR_0_EN_SET_TREE(i)               (0x120+(i)*8) /* RW-4A */
#define NV_RUNLIST_INTR_0_EN_SET_TREE__SIZE_1         2 /*       */
#define NV_RUNLIST_INTR_0_EN_SET_TREE__PRIV_LEVEL_MASK "NV_RUNLIST_INTR_PRIV_LEVEL_MASK" /*       */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_CTXSW_TIMEOUT_ENG0                             0:0 /* RWIVF */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_CTXSW_TIMEOUT_ENG0_DISABLED             0x00000000 /* RWI-V */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_CTXSW_TIMEOUT_ENG0_ENABLED              0x00000001 /* RW--V */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_CTXSW_TIMEOUT_ENG1                             1:1 /* RWIVF */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_CTXSW_TIMEOUT_ENG1_DISABLED             0x00000000 /* RWI-V */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_CTXSW_TIMEOUT_ENG1_ENABLED              0x00000001 /* RW--V */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_CTXSW_TIMEOUT_ENG2                             2:2 /* RWIVF */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_CTXSW_TIMEOUT_ENG2_DISABLED             0x00000000 /* RWI-V */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_CTXSW_TIMEOUT_ENG2_ENABLED              0x00000001 /* RW--V */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_CTXSW_TIMEOUT_ENG(i)                       (i):(i) /*       */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_CTXSW_TIMEOUT_ENG__SIZE_1  3 /*       */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_CTXSW_TIMEOUT_ENG_DISABLED              0x00000000 /*       */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_CTXSW_TIMEOUT_ENG_ENABLED               0x00000001 /*       */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_CTXSW_TIMEOUT_GRCE(i)              ((i)+1):((i)+1) /*       */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_CTXSW_TIMEOUT_GRCE__SIZE_1  2 /*       */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_CTXSW_TIMEOUT_GRCE_DISABLED             0x00000000 /*       */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_CTXSW_TIMEOUT_GRCE_ENABLED              0x00000001 /*       */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_RUNLIST_IDLE                                   4:4 /* RWIVF */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_RUNLIST_IDLE_DISABLED                   0x00000000 /* RWI-V */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_RUNLIST_IDLE_ENABLED                    0x00000001 /* RW--V */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_RUNLIST_AND_ENG_IDLE                           5:5 /* RWIVF */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_RUNLIST_AND_ENG_IDLE_DISABLED           0x00000000 /* RWI-V */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_RUNLIST_AND_ENG_IDLE_ENABLED            0x00000001 /* RW--V */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_RUNLIST_ACQUIRE                                6:6 /* RWIVF */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_RUNLIST_ACQUIRE_DISABLED                0x00000000 /* RWI-V */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_RUNLIST_ACQUIRE_ENABLED                 0x00000001 /* RW--V */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_RUNLIST_ACQUIRE_AND_ENG_IDLE                   7:7 /* RWIVF */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_RUNLIST_ACQUIRE_AND_ENG_IDLE_DISABLED   0x00000000 /* RWI-V */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_RUNLIST_ACQUIRE_AND_ENG_IDLE_ENABLED    0x00000001 /* RW--V */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_TSG_PREEMPT_COMPLETE                           8:8 /* RWIVF */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_TSG_PREEMPT_COMPLETE_DISABLED           0x00000000 /* RWI-V */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_TSG_PREEMPT_COMPLETE_ENABLED            0x00000001 /* RW--V */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_RUNLIST_PREEMPT_COMPLETE                       9:9 /* RWIVF */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_RUNLIST_PREEMPT_COMPLETE_DISABLED       0x00000000 /* RWI-V */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_RUNLIST_PREEMPT_COMPLETE_ENABLED        0x00000001 /* RW--V */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_BAD_TSG                                      12:12 /* RWIVF */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_BAD_TSG_DISABLED                        0x00000000 /* RWI-V */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_BAD_TSG_ENABLED                         0x00000001 /* RW--V */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_PBDMA0_INTR_TREE_0                           16:16 /* RWIVF */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_PBDMA0_INTR_TREE_0_DISABLED             0x00000000 /* RWI-V */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_PBDMA0_INTR_TREE_0_ENABLED              0x00000001 /* RW--V */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_PBDMA1_INTR_TREE_0                           17:17 /* RWIVF */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_PBDMA1_INTR_TREE_0_DISABLED             0x00000000 /* RWI-V */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_PBDMA1_INTR_TREE_0_ENABLED              0x00000001 /* RW--V */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_PBDMA0_INTR_TREE_1                           18:18 /* RWIVF */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_PBDMA0_INTR_TREE_1_DISABLED             0x00000000 /* RWI-V */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_PBDMA0_INTR_TREE_1_ENABLED              0x00000001 /* RW--V */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_PBDMA1_INTR_TREE_1                           19:19 /* RWIVF */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_PBDMA1_INTR_TREE_1_DISABLED             0x00000000 /* RWI-V */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_PBDMA1_INTR_TREE_1_ENABLED              0x00000001 /* RW--V */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_PBDMAi_INTR_TREE_j(i,j) (16+(i)+(j)*2):(16+(i)+(j)*2) /*       */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_PBDMAi_INTR_TREE_j__SIZE_1 2 /*       */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_PBDMAi_INTR_TREE_j__SIZE_2 2 /*       */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_PBDMAi_INTR_TREE_j_DISABLED             0x00000000 /*       */
#define NV_RUNLIST_INTR_0_EN_SET_TREE_PBDMAi_INTR_TREE_j_ENABLED              0x00000001 /*       */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE(i)             (0x140+(i)*8) /* RW-4A */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE__SIZE_1         2 /*       */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE__PRIV_LEVEL_MASK "NV_RUNLIST_INTR_PRIV_LEVEL_MASK" /*       */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_CTXSW_TIMEOUT_ENG0                             0:0 /* RWIVF */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_CTXSW_TIMEOUT_ENG0_DISABLED             0x00000000 /* RWI-V */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_CTXSW_TIMEOUT_ENG0_ENABLED              0x00000001 /* RW--V */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_CTXSW_TIMEOUT_ENG1                             1:1 /* RWIVF */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_CTXSW_TIMEOUT_ENG1_DISABLED             0x00000000 /* RWI-V */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_CTXSW_TIMEOUT_ENG1_ENABLED              0x00000001 /* RW--V */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_CTXSW_TIMEOUT_ENG2                             2:2 /* RWIVF */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_CTXSW_TIMEOUT_ENG2_DISABLED             0x00000000 /* RWI-V */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_CTXSW_TIMEOUT_ENG2_ENABLED              0x00000001 /* RW--V */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_CTXSW_TIMEOUT_ENG(i)                       (i):(i) /*       */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_CTXSW_TIMEOUT_ENG__SIZE_1  3 /*       */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_CTXSW_TIMEOUT_ENG_DISABLED              0x00000000 /*       */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_CTXSW_TIMEOUT_ENG_ENABLED               0x00000001 /*       */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_CTXSW_TIMEOUT_GRCE(i)              ((i)+1):((i)+1) /*       */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_CTXSW_TIMEOUT_GRCE__SIZE_1  2 /*       */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_CTXSW_TIMEOUT_GRCE_DISABLED             0x00000000 /*       */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_CTXSW_TIMEOUT_GRCE_ENABLED              0x00000001 /*       */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_RUNLIST_IDLE                                   4:4 /* RWIVF */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_RUNLIST_IDLE_DISABLED                   0x00000000 /* RWI-V */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_RUNLIST_IDLE_ENABLED                    0x00000001 /* RW--V */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_RUNLIST_AND_ENG_IDLE                           5:5 /* RWIVF */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_RUNLIST_AND_ENG_IDLE_DISABLED           0x00000000 /* RWI-V */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_RUNLIST_AND_ENG_IDLE_ENABLED            0x00000001 /* RW--V */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_RUNLIST_ACQUIRE                                6:6 /* RWIVF */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_RUNLIST_ACQUIRE_DISABLED                0x00000000 /* RWI-V */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_RUNLIST_ACQUIRE_ENABLED                 0x00000001 /* RW--V */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_RUNLIST_ACQUIRE_AND_ENG_IDLE                   7:7 /* RWIVF */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_RUNLIST_ACQUIRE_AND_ENG_IDLE_DISABLED   0x00000000 /* RWI-V */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_RUNLIST_ACQUIRE_AND_ENG_IDLE_ENABLED    0x00000001 /* RW--V */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_TSG_PREEMPT_COMPLETE                           8:8 /* RWIVF */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_TSG_PREEMPT_COMPLETE_DISABLED           0x00000000 /* RWI-V */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_TSG_PREEMPT_COMPLETE_ENABLED            0x00000001 /* RW--V */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_RUNLIST_PREEMPT_COMPLETE                       9:9 /* RWIVF */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_RUNLIST_PREEMPT_COMPLETE_DISABLED       0x00000000 /* RWI-V */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_RUNLIST_PREEMPT_COMPLETE_ENABLED        0x00000001 /* RW--V */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_BAD_TSG                                      12:12 /* RWIVF */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_BAD_TSG_DISABLED                        0x00000000 /* RWI-V */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_BAD_TSG_ENABLED                         0x00000001 /* RW--V */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_PBDMA0_INTR_TREE_0                           16:16 /* RWIVF */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_PBDMA0_INTR_TREE_0_DISABLED             0x00000000 /* RWI-V */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_PBDMA0_INTR_TREE_0_ENABLED              0x00000001 /* RW--V */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_PBDMA1_INTR_TREE_0                           17:17 /* RWIVF */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_PBDMA1_INTR_TREE_0_DISABLED             0x00000000 /* RWI-V */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_PBDMA1_INTR_TREE_0_ENABLED              0x00000001 /* RW--V */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_PBDMA0_INTR_TREE_1                           18:18 /* RWIVF */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_PBDMA0_INTR_TREE_1_DISABLED             0x00000000 /* RWI-V */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_PBDMA0_INTR_TREE_1_ENABLED              0x00000001 /* RW--V */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_PBDMA1_INTR_TREE_1                           19:19 /* RWIVF */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_PBDMA1_INTR_TREE_1_DISABLED             0x00000000 /* RWI-V */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_PBDMA1_INTR_TREE_1_ENABLED              0x00000001 /* RW--V */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_PBDMAi_INTR_TREE_j(i,j) (16+(i)+(j)*2):(16+(i)+(j)*2) /*       */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_PBDMAi_INTR_TREE_j__SIZE_1 2 /*       */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_PBDMAi_INTR_TREE_j__SIZE_2 2 /*       */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_PBDMAi_INTR_TREE_j_DISABLED             0x00000000 /*       */
#define NV_RUNLIST_INTR_0_EN_CLEAR_TREE_PBDMAi_INTR_TREE_j_ENABLED              0x00000001 /*       */
#define NV_RUNLIST_ENGINE_CTXSW_TIMEOUT_INFO(i)       (0x224+(i)*64) /* R--4A */
#define NV_RUNLIST_ENGINE_CTXSW_TIMEOUT_INFO__SIZE_1 3 /*       */
#define NV_RUNLIST_ENGINE_CTXSW_TIMEOUT_INFO_PREV_TSGID                    13:0 /* R-IUF */
#define NV_RUNLIST_ENGINE_CTXSW_TIMEOUT_INFO_PREV_TSGID_DEFAULT      0x00000000 /* R-I-V */
#define NV_RUNLIST_ENGINE_CTXSW_TIMEOUT_INFO_CTXSW_STATE                  15:14 /* R-IUF */
#define NV_RUNLIST_ENGINE_CTXSW_TIMEOUT_INFO_CTXSW_STATE_LOAD        0x00000001 /* R-I-V */
#define NV_RUNLIST_ENGINE_CTXSW_TIMEOUT_INFO_CTXSW_STATE_SAVE        0x00000002 /* R---V */
#define NV_RUNLIST_ENGINE_CTXSW_TIMEOUT_INFO_CTXSW_STATE_SWITCH      0x00000003 /* R---V */
#define NV_RUNLIST_ENGINE_CTXSW_TIMEOUT_INFO_NEXT_TSGID                   29:16 /* R-IUF */
#define NV_RUNLIST_ENGINE_CTXSW_TIMEOUT_INFO_NEXT_TSGID_DEFAULT      0x00000000 /* R-I-V */
#define NV_RUNLIST_ENGINE_CTXSW_TIMEOUT_INFO_STATUS                       31:30 /* R-IUF */
#define NV_RUNLIST_ENGINE_CTXSW_TIMEOUT_INFO_STATUS_AWAITING_ACK     0x00000000 /* R-I-V */
#define NV_RUNLIST_ENGINE_CTXSW_TIMEOUT_INFO_STATUS_ENG_WAS_RESET    0x00000001 /* R---V */
#define NV_RUNLIST_ENGINE_CTXSW_TIMEOUT_INFO_STATUS_ACK_RECEIVED     0x00000002 /* R---V */
#define NV_RUNLIST_ENGINE_CTXSW_TIMEOUT_INFO_STATUS_DROPPED_TIMEOUT  0x00000003 /* R---V */
#define NV_RUNLIST_INFO                                        0x108 /* R--4R */
#define NV_RUNLIST_INFO_RUNLIST_IDLE_INTR_ARM                                 0:0 /* R-IUF */
#define NV_RUNLIST_INFO_RUNLIST_IDLE_INTR_ARM_UNARMED                  0x00000000 /* R-I-V */
#define NV_RUNLIST_INFO_RUNLIST_IDLE_INTR_ARM_ARMED                    0x00000001 /* R---V */
#define NV_RUNLIST_INFO_RUNLIST_ACQUIRE_INTR_ARM                              1:1 /* R-IUF */
#define NV_RUNLIST_INFO_RUNLIST_ACQUIRE_INTR_ARM_UNARMED               0x00000000 /* R-I-V */
#define NV_RUNLIST_INFO_RUNLIST_ACQUIRE_INTR_ARM_ARMED                 0x00000001 /* R---V */
#define NV_RUNLIST_INFO_RUNLIST_AND_ENG_IDLE_INTR_ARM                         4:4 /* R-IUF */
#define NV_RUNLIST_INFO_RUNLIST_AND_ENG_IDLE_INTR_ARM_UNARMED          0x00000000 /* R-I-V */
#define NV_RUNLIST_INFO_RUNLIST_AND_ENG_IDLE_INTR_ARM_ARMED            0x00000001 /* R---V */
#define NV_RUNLIST_INFO_RUNLIST_ACQUIRE_AND_ENG_IDLE_INTR_ARM                 5:5 /* R-IUF */
#define NV_RUNLIST_INFO_RUNLIST_ACQUIRE_AND_ENG_IDLE_INTR_ARM_UNARMED  0x00000000 /* R-I-V */
#define NV_RUNLIST_INFO_RUNLIST_ACQUIRE_AND_ENG_IDLE_INTR_ARM_ARMED    0x00000001 /* R---V */
#define NV_RUNLIST_INFO_ENG_IDLE                                              8:8 /* R-IUF */
#define NV_RUNLIST_INFO_ENG_IDLE_FALSE                                 0x00000000 /* R---V */
#define NV_RUNLIST_INFO_ENG_IDLE_TRUE                                  0x00000001 /* R-I-V */
#define NV_RUNLIST_INFO_RUNLIST_IDLE                                          9:9 /* R-IUF */
#define NV_RUNLIST_INFO_RUNLIST_IDLE_FALSE                             0x00000000 /* R---V */
#define NV_RUNLIST_INFO_RUNLIST_IDLE_TRUE                              0x00000001 /* R-I-V */
#define NV_RUNLIST_INFO_RUNLIST_FETCH_STATUS                                10:10 /* R-IVF */
#define NV_RUNLIST_INFO_RUNLIST_FETCH_STATUS_IDLE                      0x00000000 /* R-I-V */
#define NV_RUNLIST_INFO_RUNLIST_FETCH_STATUS_BUSY                      0x00000001 /* R---V */
#define NV_RUNLIST_INFO_ACQUIRE_STILL_PENDING                               12:12 /* R-IUF */
#define NV_RUNLIST_INFO_ACQUIRE_STILL_PENDING_FALSE                    0x00000000 /* R-I-V */
#define NV_RUNLIST_INFO_ACQUIRE_STILL_PENDING_TRUE                     0x00000001 /* R---V */
#define NV_RUNLIST_INFO_RUNLIST_FETCH_NACKED                                13:13 /* R-IUF */
#define NV_RUNLIST_INFO_RUNLIST_FETCH_NACKED_FALSE                     0x00000000 /* R-I-V */
#define NV_RUNLIST_INFO_RUNLIST_FETCH_NACKED_TRUE                      0x00000001 /* R---V */
#define NV_RUNLIST_INTR_BAD_TSG                                0x174 /* R--4R */
#define NV_RUNLIST_INTR_BAD_TSG_CODE                               3:0 /* R-IVF */
#define NV_RUNLIST_INTR_BAD_TSG_CODE_NO_ERROR               0x00000000 /* R-I-V */
#define NV_RUNLIST_INTR_BAD_TSG_CODE_ZERO_LENGTH_TSG        0x00000001 /* R---V */
#define NV_RUNLIST_INTR_BAD_TSG_CODE_MAX_LENGTH_EXCEEDED    0x00000002 /* R---V */
#define NV_RUNLIST_INTR_BAD_TSG_CODE_RUNLIST_OVERFLOW       0x00000003 /* R---V */
#define NV_RUNLIST_INTR_BAD_TSG_CODE_EXPECTED_A_CHID_ENTRY  0x00000004 /* R---V */
#define NV_RUNLIST_INTR_BAD_TSG_CODE_EXPECTED_A_TSG_HEADER  0x00000005 /* R---V */
#define NV_RUNLIST_INTR_BAD_TSG_CODE_INVALID_RUNQUEUE       0x00000006 /* R---V */
#define NV_RUNLIST_ENGINE_CTXSW_TIMEOUT_CONFIG(i)     (0x220+(i)*64) /* RW-4A */
#define NV_RUNLIST_ENGINE_CTXSW_TIMEOUT_CONFIG__SIZE_1 3 /*       */
#define NV_RUNLIST_ENGINE_CTXSW_TIMEOUT_CONFIG_PERIOD                      30:0 /* RWIVF */
#define NV_RUNLIST_ENGINE_CTXSW_TIMEOUT_CONFIG_PERIOD_INIT           0x003fffff /* RWI-V */
#define NV_RUNLIST_ENGINE_CTXSW_TIMEOUT_CONFIG_PERIOD_MAX            0x7fffffff /* RW--V */
#define NV_RUNLIST_ENGINE_CTXSW_TIMEOUT_CONFIG_DETECTION                  31:31 /* RWIVF */
#define NV_RUNLIST_ENGINE_CTXSW_TIMEOUT_CONFIG_DETECTION_DISABLED    0x00000000 /* RW--V */
#define NV_RUNLIST_ENGINE_CTXSW_TIMEOUT_CONFIG_DETECTION_ENABLED     0x00000001 /* RWI-V */
#define NV_RUNLIST_BLKCG                                       0x050 /* RW-4R */
#define NV_RUNLIST_BLKCG_IDLE_CG_DLY_CNT                         5:0 /* RWIVF */
#define NV_RUNLIST_BLKCG_IDLE_CG_DLY_CNT_INIT             0x00000000 /* RWI-V */
#define NV_RUNLIST_BLKCG_IDLE_CG_DLY_CNT__PROD            0x00000002 /* RW--V */
#define NV_RUNLIST_BLKCG_IDLE_CG_EN                              6:6 /* RWIVF */
#define NV_RUNLIST_BLKCG_IDLE_CG_EN_ENABLED               0x00000001 /* RW--V */
#define NV_RUNLIST_BLKCG_IDLE_CG_EN_DISABLED              0x00000000 /* RWI-V */
#define NV_RUNLIST_BLKCG_IDLE_CG_EN__PROD                 0x00000001 /* RW--V */
#define NV_RUNLIST_BLKCG_STATE_CG_EN                             7:7 /*       */
#define NV_RUNLIST_BLKCG_STATE_CG_EN_ENABLED              0x00000001 /*       */
#define NV_RUNLIST_BLKCG_STATE_CG_EN_DISABLED             0x00000000 /*       */
#define NV_RUNLIST_BLKCG_STATE_CG_EN__PROD                0x00000000 /*       */
#define NV_RUNLIST_BLKCG_STALL_CG_DLY_CNT                       13:8 /*       */
#define NV_RUNLIST_BLKCG_STALL_CG_DLY_CNT_INIT            0x00000000 /*       */
#define NV_RUNLIST_BLKCG_STALL_CG_DLY_CNT__PROD           0x00000002 /*       */
#define NV_RUNLIST_BLKCG_STALL_CG_EN                           14:14 /* RWIVF */
#define NV_RUNLIST_BLKCG_STALL_CG_EN_ENABLED              0x00000001 /* RW--V */
#define NV_RUNLIST_BLKCG_STALL_CG_EN_DISABLED             0x00000000 /* RWI-V */
#define NV_RUNLIST_BLKCG_STALL_CG_EN__PROD                0x00000001 /* RW--V */
#define NV_RUNLIST_BLKCG_QUIESCENT_CG_EN                       15:15 /*       */
#define NV_RUNLIST_BLKCG_QUIESCENT_CG_EN_ENABLED          0x00000001 /*       */
#define NV_RUNLIST_BLKCG_QUIESCENT_CG_EN_DISABLED         0x00000000 /*       */
#define NV_RUNLIST_BLKCG_QUIESCENT_CG_EN__PROD            0x00000001 /*       */
#define NV_RUNLIST_BLKCG_WAKEUP_DLY_CNT                        19:16 /* RWIVF */
#define NV_RUNLIST_BLKCG_WAKEUP_DLY_CNT_INIT              0x00000000 /* RWI-V */
#define NV_RUNLIST_BLKCG_WAKEUP_DLY_CNT__PROD             0x00000000 /* RW--V */
#define NV_RUNLIST_BLKCG_THROT_CLK_CNT                         23:20 /*       */
#define NV_RUNLIST_BLKCG_THROT_CLK_CNT_INIT               0x0000000f /*       */
#define NV_RUNLIST_BLKCG_THROT_CLK_CNT_FULLSPEED          0x0000000f /*       */
#define NV_RUNLIST_BLKCG_THROT_CLK_CNT__PROD              0x00000000 /*       */
#define NV_RUNLIST_BLKCG_DI_DT_SKEW_VAL                        27:24 /*       */
#define NV_RUNLIST_BLKCG_DI_DT_SKEW_VAL_INIT              0x00000000 /*       */
#define NV_RUNLIST_BLKCG_DI_DT_SKEW_VAL__PROD             0x00000000 /*       */
#define NV_RUNLIST_BLKCG_THROT_CLK_EN                          28:28 /*       */
#define NV_RUNLIST_BLKCG_THROT_CLK_EN_ENABLED             0x00000001 /*       */
#define NV_RUNLIST_BLKCG_THROT_CLK_EN_DISABLED            0x00000000 /*       */
#define NV_RUNLIST_BLKCG_THROT_CLK_EN__PROD               0x00000000 /*       */
#define NV_RUNLIST_BLKCG_THROT_CLK_SW_OVER                     29:29 /*       */
#define NV_RUNLIST_BLKCG_THROT_CLK_SW_OVER_EN             0x00000001 /*       */
#define NV_RUNLIST_BLKCG_THROT_CLK_SW_OVER_DIS            0x00000000 /*       */
#define NV_RUNLIST_BLKCG_THROT_CLK_SW_OVER__PROD          0x00000000 /*       */
#define NV_RUNLIST_BLKCG_PAUSE_CG_EN                           30:30 /*       */
#define NV_RUNLIST_BLKCG_PAUSE_CG_EN_ENABLED              0x00000001 /*       */
#define NV_RUNLIST_BLKCG_PAUSE_CG_EN_DISABLED             0x00000000 /*       */
#define NV_RUNLIST_BLKCG_PAUSE_CG_EN__PROD                0x00000000 /*       */
#define NV_RUNLIST_BLKCG_HALT_CG_EN                            31:31 /*       */
#define NV_RUNLIST_BLKCG_HALT_CG_EN_ENABLED               0x00000001 /*       */
#define NV_RUNLIST_BLKCG_HALT_CG_EN_DISABLED              0x00000000 /*       */
#define NV_RUNLIST_BLKCG_HALT_CG_EN__PROD                 0x00000000 /*       */
#define NV_RUNLIST_BLKCG1                                      0x054 /* RW-4R */
#define NV_RUNLIST_BLKCG1_MONITOR_CG_EN                          0:0 /* RWIVF */
#define NV_RUNLIST_BLKCG1_MONITOR_CG_EN_ENABLED           0x00000001 /* RW--V */
#define NV_RUNLIST_BLKCG1_MONITOR_CG_EN_DISABLED          0x00000000 /* RWI-V */
#define NV_RUNLIST_BLKCG1_SLCG                                  16:1 /*       */
#define NV_RUNLIST_BLKCG1_SLCG_ENABLED                    0x00000000 /*       */
#define NV_RUNLIST_BLKCG1_SLCG_DISABLED                   0x0000FFFF /*       */
#define NV_RUNLIST_BLKCG1_SLCG__PROD                      0x00000001 /*       */
#define NV_RUNLIST_BLKCG1_SLCG_RLP                               1:1 /* RWIVF */
#define NV_RUNLIST_BLKCG1_SLCG_RLP_ENABLED                0x00000000 /* RW--V */
#define NV_RUNLIST_BLKCG1_SLCG_RLP_DISABLED               0x00000001 /* RWI-V */
#define NV_RUNLIST_BLKCG1_SLCG_RLP__PROD                  0x00000001 /* RW--V */
#define NV_RUNLIST_BLKCG1_SLCG_EVH                               3:3 /* RWIVF */
#define NV_RUNLIST_BLKCG1_SLCG_EVH_ENABLED                0x00000000 /* RW--V */
#define NV_RUNLIST_BLKCG1_SLCG_EVH_DISABLED               0x00000001 /* RWI-V */
#define NV_RUNLIST_BLKCG1_SLCG_EVH__PROD                  0x00000000 /* RW--V */
#define NV_RUNLIST_BLKCG1_SLCG_EISM                              7:7 /* RWIVF */
#define NV_RUNLIST_BLKCG1_SLCG_EISM_ENABLED               0x00000000 /* RW--V */
#define NV_RUNLIST_BLKCG1_SLCG_EISM_DISABLED              0x00000001 /* RWI-V */
#define NV_RUNLIST_BLKCG1_SLCG_EISM__PROD                 0x00000000 /* RW--V */
#define NV_RUNLIST_BLKCG1_SLCG_LB                                8:8 /* RWIVF */
#define NV_RUNLIST_BLKCG1_SLCG_LB_ENABLED                 0x00000000 /* RW--V */
#define NV_RUNLIST_BLKCG1_SLCG_LB_DISABLED                0x00000001 /* RWI-V */
#define NV_RUNLIST_BLKCG1_SLCG_LB__PROD                   0x00000000 /* RW--V */
#define NV_RUNLIST_BLKCG1_SLCG_PBDMA_CTL                         9:9 /* RWIVF */
#define NV_RUNLIST_BLKCG1_SLCG_PBDMA_CTL_ENABLED          0x00000000 /* RW--V */
#define NV_RUNLIST_BLKCG1_SLCG_PBDMA_CTL_DISABLED         0x00000001 /* RWI-V */
#define NV_RUNLIST_BLKCG1_SLCG_PBDMA_CTL__PROD            0x00000000 /* RW--V */
#define NV_RUNLIST_BLKCG1_SLCG_PBDMA_GP                        10:10 /* RWIVF */
#define NV_RUNLIST_BLKCG1_SLCG_PBDMA_GP_ENABLED           0x00000000 /* RW--V */
#define NV_RUNLIST_BLKCG1_SLCG_PBDMA_GP_DISABLED          0x00000001 /* RWI-V */
#define NV_RUNLIST_BLKCG1_SLCG_PBDMA_GP__PROD             0x00000000 /* RW--V */
#define NV_RUNLIST_BLKCG1_SLCG_PBDMA_PB                        11:11 /* RWIVF */
#define NV_RUNLIST_BLKCG1_SLCG_PBDMA_PB_ENABLED           0x00000000 /* RW--V */
#define NV_RUNLIST_BLKCG1_SLCG_PBDMA_PB_DISABLED          0x00000001 /* RWI-V */
#define NV_RUNLIST_BLKCG1_SLCG_PBDMA_PB__PROD             0x00000000 /* RW--V */
#define NV_RUNLIST_BLKCG1_SLCG_PRI                             13:13 /* RWIVF */
#define NV_RUNLIST_BLKCG1_SLCG_PRI_ENABLED                0x00000000 /* RW--V */
#define NV_RUNLIST_BLKCG1_SLCG_PRI_DISABLED               0x00000001 /* RWI-V */
#define NV_RUNLIST_BLKCG1_SLCG_PRI__PROD                  0x00000000 /* RW--V */
#define NV_RUNLIST_BLKCG1_SLCG_CHSW                            14:14 /* RWIVF */
#define NV_RUNLIST_BLKCG1_SLCG_CHSW_ENABLED               0x00000000 /* RW--V */
#define NV_RUNLIST_BLKCG1_SLCG_CHSW_DISABLED              0x00000001 /* RWI-V */
#define NV_RUNLIST_BLKCG1_SLCG_CHSW__PROD                 0x00000000 /* RW--V */
#define NV_RUNLIST_BLKCG1_SLCG_XBAR                            15:15 /* RWIVF */
#define NV_RUNLIST_BLKCG1_SLCG_XBAR_ENABLED               0x00000000 /* RW--V */
#define NV_RUNLIST_BLKCG1_SLCG_XBAR_DISABLED              0x00000001 /* RWI-V */
#define NV_RUNLIST_BLKCG1_SLCG_XBAR__PROD                 0x00000000 /* RW--V */
#define NV_RUNLIST_INTERNAL_DOORBELL                           0x090 /* -W-4R */
#define NV_RUNLIST_INTERNAL_DOORBELL_CHID      11:0 /*       */
#define NV_RUNLIST_INTERNAL_DOORBELL_CHID_HW      10:0 /* -WXUF */
#define NV_RUNLIST_INTERNAL_DOORBELL_GFID                      21:16 /* -WXUF */
#define NV_RUNLIST_SCHED_DISABLE                               0x094 /* RW-4R */
#define NV_RUNLIST_SCHED_DISABLE_RUNLIST                         0:0 /* RWIVF */
#define NV_RUNLIST_SCHED_DISABLE_RUNLIST_ENABLED          0x00000000 /* RWI-V */
#define NV_RUNLIST_SCHED_DISABLE_RUNLIST_DISABLED         0x00000001 /* RW--V */
#define NV_RUNLIST_SCHED_DISABLE_RUNLIST_FALSE            0x00000000 /*       */
#define NV_RUNLIST_SCHED_DISABLE_RUNLIST_TRUE             0x00000001 /*       */
#define NV_RUNLIST_PREEMPT                                     0x098 /* RW-4R */
#define NV_RUNLIST_PREEMPT_ID                                    11:0 /*       */
#define NV_RUNLIST_PREEMPT_ID_HW                   10:0 /* RWIUF */
#define NV_RUNLIST_PREEMPT_ID_HW_NULL                      0x00000000 /* RWI-V */
#define NV_RUNLIST_PREEMPT_TSG_PREEMPT_PENDING                  20:20 /* R-IVF */
#define NV_RUNLIST_PREEMPT_TSG_PREEMPT_PENDING_FALSE       0x00000000 /* R-I-V */
#define NV_RUNLIST_PREEMPT_TSG_PREEMPT_PENDING_TRUE        0x00000001 /* R---V */
#define NV_RUNLIST_PREEMPT_RUNLIST_PREEMPT_PENDING              21:21 /* R-IVF */
#define NV_RUNLIST_PREEMPT_RUNLIST_PREEMPT_PENDING_FALSE   0x00000000 /* R-I-V */
#define NV_RUNLIST_PREEMPT_RUNLIST_PREEMPT_PENDING_TRUE    0x00000001 /* R---V */
#define NV_RUNLIST_PREEMPT_TYPE                                 25:24 /* RWIVF */
#define NV_RUNLIST_PREEMPT_TYPE_RUNLIST                    0x00000000 /* RWI-V */
#define NV_RUNLIST_PREEMPT_TYPE_TSG                        0x00000001 /* RW--V */
#define NV_RUNLIST_ENGINE_STATUS0(i)                  (0x200+(i)*64) /* R--4A */
#define NV_RUNLIST_ENGINE_STATUS0__SIZE_1 3 /*       */
#define NV_RUNLIST_ENGINE_STATUS0_TSGID          11:0 /*       */
#define NV_RUNLIST_ENGINE_STATUS0_TSGID_HW          10:0 /* R-XUF */
#define NV_RUNLIST_ENGINE_STATUS0_CTX_STATUS                     15:13 /* R-IVF */
#define NV_RUNLIST_ENGINE_STATUS0_CTX_STATUS_INVALID        0x00000000 /* R-I-V */
#define NV_RUNLIST_ENGINE_STATUS0_CTX_STATUS_VALID          0x00000001 /* R---V */
#define NV_RUNLIST_ENGINE_STATUS0_CTX_STATUS_CTXSW_SAVE     0x00000005 /* R---V */
#define NV_RUNLIST_ENGINE_STATUS0_CTX_STATUS_CTXSW_LOAD     0x00000006 /* R---V */
#define NV_RUNLIST_ENGINE_STATUS0_CTX_STATUS_CTXSW_SWITCH   0x00000007 /* R---V */
#define NV_RUNLIST_ENGINE_STATUS0_CTX                            13:13 /*       */
#define NV_RUNLIST_ENGINE_STATUS0_CTX_INVALID               0x00000000 /*       */
#define NV_RUNLIST_ENGINE_STATUS0_CTX_VALID                 0x00000001 /*       */
#define NV_RUNLIST_ENGINE_STATUS0_CTXLOAD                        14:14 /*       */
#define NV_RUNLIST_ENGINE_STATUS0_CTXLOAD_NOT_IN_PROGRESS   0x00000000 /*       */
#define NV_RUNLIST_ENGINE_STATUS0_CTXLOAD_IN_PROGRESS       0x00000001 /*       */
#define NV_RUNLIST_ENGINE_STATUS0_CTXSW                          15:15 /*       */
#define NV_RUNLIST_ENGINE_STATUS0_CTXSW_NOT_IN_PROGRESS     0x00000000 /*       */
#define NV_RUNLIST_ENGINE_STATUS0_CTXSW_IN_PROGRESS         0x00000001 /*       */
#define NV_RUNLIST_ENGINE_STATUS0_NEXT_TSGID  27:16 /*       */
#define NV_RUNLIST_ENGINE_STATUS0_NEXT_TSGID_HW  26:16 /* R-XUF */
#define NV_RUNLIST_ENGINE_STATUS0_ENG_RELOAD                     29:29 /* R-IVF */
#define NV_RUNLIST_ENGINE_STATUS0_ENG_RELOAD_FALSE          0x00000000 /* R-I-V */
#define NV_RUNLIST_ENGINE_STATUS0_ENG_RELOAD_TRUE           0x00000001 /* R---V */
#define NV_RUNLIST_ENGINE_STATUS0_FAULTED                        30:30 /* R-IVF */
#define NV_RUNLIST_ENGINE_STATUS0_FAULTED_FALSE             0x00000000 /* R-I-V */
#define NV_RUNLIST_ENGINE_STATUS0_FAULTED_TRUE              0x00000001 /* R---V */
#define NV_RUNLIST_ENGINE_STATUS0_ENGINE                         31:31 /* R-IVF */
#define NV_RUNLIST_ENGINE_STATUS0_ENGINE_IDLE               0x00000000 /* R-I-V */
#define NV_RUNLIST_ENGINE_STATUS0_ENGINE_BUSY               0x00000001 /* R---V */
#define NV_RUNLIST_ENGINE_STATUS1(i)                  (0x204+(i)*64) /* R--4A */
#define NV_RUNLIST_ENGINE_STATUS1__SIZE_1 3 /*       */
#define NV_RUNLIST_ENGINE_STATUS1_GFID                             5:0 /* R-XVF */
#define NV_RUNLIST_ENGINE_STATUS1_NEXT_GFID                       13:8 /* R-XVF */
#define NV_RUNLIST_ENGINE_STATUS1_INTR_ID                        20:16 /* R-XVF */
#define NV_RUNLIST_ENGINE_STATUS1_GFID_VALID                     30:30 /* R-IVF */
#define NV_RUNLIST_ENGINE_STATUS1_GFID_VALID_FALSE          0x00000000 /* R-I-V */
#define NV_RUNLIST_ENGINE_STATUS1_GFID_VALID_TRUE           0x00000001 /* R---V */
#define NV_RUNLIST_ENGINE_STATUS1_NEXT_GFID_VALID                31:31 /* R-IVF */
#define NV_RUNLIST_ENGINE_STATUS1_NEXT_GFID_VALID_FALSE     0x00000000 /* R-I-V */
#define NV_RUNLIST_ENGINE_STATUS1_NEXT_GFID_VALID_TRUE      0x00000001 /* R---V */
#define NV_RUNLIST_ENGINE_STATUS_CHANNEL(i,j)    (0x208+(i)*64+(j)*4) /* R--4A */
#define NV_RUNLIST_ENGINE_STATUS_CHANNEL__SIZE_1 3 /*       */
#define NV_RUNLIST_ENGINE_STATUS_CHANNEL__SIZE_2 2 /*       */
#define NV_RUNLIST_ENGINE_STATUS_CHANNEL_CHID                11:0 /*       */
#define NV_RUNLIST_ENGINE_STATUS_CHANNEL_CHID_HW                10:0 /* R-XUF */
#define NV_RUNLIST_ENGINE_STATUS_CHANNEL_VALID                               15:15 /* R-IVF */
#define NV_RUNLIST_ENGINE_STATUS_CHANNEL_VALID_FALSE                    0x00000000 /* R-I-V */
#define NV_RUNLIST_ENGINE_STATUS_CHANNEL_VALID_TRUE                     0x00000001 /* R---V */
#define NV_RUNLIST_ENGINE_STATUS_CHANNEL_NEXT_CHID  27:16 /*       */
#define NV_RUNLIST_ENGINE_STATUS_CHANNEL_NEXT_CHID_HW  26:16 /* R-XUF */
#define NV_RUNLIST_ENGINE_STATUS_CHANNEL_NEXT_VALID                          31:31 /* R-IVF */
#define NV_RUNLIST_ENGINE_STATUS_CHANNEL_NEXT_VALID_FALSE               0x00000000 /* R-I-V */
#define NV_RUNLIST_ENGINE_STATUS_CHANNEL_NEXT_VALID_TRUE                0x00000001 /* R---V */
#define NV_RUNLIST_ENGINE_STATUS_DEBUG(i)             (0x228+(i)*64) /* R--4A */
#define NV_RUNLIST_ENGINE_STATUS_DEBUG__SIZE_1 3 /*       */
#define NV_RUNLIST_ENGINE_STATUS_DEBUG_IF_EN                          0:0 /* R-IVF */
#define NV_RUNLIST_ENGINE_STATUS_DEBUG_IF_EN_DISABLED          0x00000000 /* R---V */
#define NV_RUNLIST_ENGINE_STATUS_DEBUG_IF_EN_ENABLED           0x00000001 /* R-I-V */
#define NV_RUNLIST_ENGINE_STATUS_DEBUG_PIPE0_NO_CREDITS               8:8 /* R-IVF */
#define NV_RUNLIST_ENGINE_STATUS_DEBUG_PIPE0_NO_CREDITS_FALSE  0x00000000 /* R-I-V */
#define NV_RUNLIST_ENGINE_STATUS_DEBUG_PIPE0_NO_CREDITS_TRUE   0x00000001 /* R---V */
#define NV_RUNLIST_ENGINE_STATUS_DEBUG_PIPE0_WFI                    12:12 /* R-IVF */
#define NV_RUNLIST_ENGINE_STATUS_DEBUG_PIPE0_WFI_FALSE         0x00000000 /* R-I-V */
#define NV_RUNLIST_ENGINE_STATUS_DEBUG_PIPE0_WFI_TRUE          0x00000001 /* R---V */
#define NV_RUNLIST_ENGINE_STATUS_DEBUG_PIPE1_NO_CREDITS             16:16 /* R-IVF */
#define NV_RUNLIST_ENGINE_STATUS_DEBUG_PIPE1_NO_CREDITS_FALSE  0x00000000 /* R-I-V */
#define NV_RUNLIST_ENGINE_STATUS_DEBUG_PIPE1_NO_CREDITS_TRUE   0x00000001 /* R---V */
#define NV_RUNLIST_ENGINE_STATUS_DEBUG_PIPE1_WFI                    20:20 /* R-IVF */
#define NV_RUNLIST_ENGINE_STATUS_DEBUG_PIPE1_WFI_FALSE         0x00000000 /* R-I-V */
#define NV_RUNLIST_ENGINE_STATUS_DEBUG_PIPE1_WFI_TRUE          0x00000001 /* R---V */
#define NV_RUNLIST_ENGINE_STATUS_INST(i)              (0x210+(i)*64) /* R--4A */
#define NV_RUNLIST_ENGINE_STATUS_INST__SIZE_1 3 /*       */
#define NV_RUNLIST_ENGINE_STATUS_INST_TARGET                            1:0 /* R-XUF */
#define NV_RUNLIST_ENGINE_STATUS_INST_TARGET_VID_MEM             0x00000000 /* R---V */
#define NV_RUNLIST_ENGINE_STATUS_INST_TARGET_SYS_MEM_COHERENT    0x00000002 /* R---V */
#define NV_RUNLIST_ENGINE_STATUS_INST_TARGET_SYS_MEM_NONCOHERENT 0x00000003 /* R---V */
#define NV_RUNLIST_ENGINE_STATUS_INST_VALID                           11:11 /* R-IVF */
#define NV_RUNLIST_ENGINE_STATUS_INST_VALID_FALSE                0x00000000 /* R-I-V */
#define NV_RUNLIST_ENGINE_STATUS_INST_VALID_TRUE                 0x00000001 /* R---V */
#define NV_RUNLIST_ENGINE_STATUS_INST_PTR_LO                          31:12 /* R-XUF */
#define NV_RUNLIST_ENGINE_STATUS_INST_HI(i)           (0x214+(i)*64) /* R--4A */
#define NV_RUNLIST_ENGINE_STATUS_INST_HI__SIZE_1 3 /*       */
#define NV_RUNLIST_ENGINE_STATUS_INST_HI_PTR_HI                        31:0 /* R-XUF */
#define NV_RUNLIST_ENGINE_STATUS_INST_HI_PTR_HI_ZERO             0x00000000 /* R---V */
#define NV_RUNLIST_ENGINE_STATUS_NEXT_INST(i)         (0x218+(i)*64) /* R--4A */
#define NV_RUNLIST_ENGINE_STATUS_NEXT_INST__SIZE_1 3 /*       */
#define NV_RUNLIST_ENGINE_STATUS_NEXT_INST_TARGET                            1:0 /* R-XUF */
#define NV_RUNLIST_ENGINE_STATUS_NEXT_INST_TARGET_VID_MEM             0x00000000 /* R---V */
#define NV_RUNLIST_ENGINE_STATUS_NEXT_INST_TARGET_SYS_MEM_COHERENT    0x00000002 /* R---V */
#define NV_RUNLIST_ENGINE_STATUS_NEXT_INST_TARGET_SYS_MEM_NONCOHERENT 0x00000003 /* R---V */
#define NV_RUNLIST_ENGINE_STATUS_NEXT_INST_VALID                           11:11 /* R-IVF */
#define NV_RUNLIST_ENGINE_STATUS_NEXT_INST_VALID_FALSE                0x00000000 /* R-I-V */
#define NV_RUNLIST_ENGINE_STATUS_NEXT_INST_VALID_TRUE                 0x00000001 /* R---V */
#define NV_RUNLIST_ENGINE_STATUS_NEXT_INST_PTR_LO                          31:12 /* R-XUF */
#define NV_RUNLIST_ENGINE_STATUS_NEXT_INST_HI(i)      (0x21C+(i)*64) /* R--4A */
#define NV_RUNLIST_ENGINE_STATUS_NEXT_INST_HI__SIZE_1 3 /*       */
#define NV_RUNLIST_ENGINE_STATUS_NEXT_INST_HI_PTR_HI                      31:0 /* R-XUF */
#define NV_RUNLIST_ENGINE_STATUS_NEXT_INST_HI_PTR_HI_ZERO           0x00000000 /* R---V */
// 
// --------------------------------------------------------------------------------
// Channel Teardown Sequence
// ===============================================================================
// 
//      This section describes the sequence software (specifically RM) can use to
// tear down a channel for robust channels (RC) recovery or in the case of a fault.
// 
//      In the case of a fault, the esched does not guarantee that a PBDMA has
// saved out prior to RM receiving notification of the fault.  RM must determine
// which context has faulted by processing the fault buffer as described in the
// NV_PFB_PRI_MMU_FAULT_BUFFER_* register documentation in pri_mmu_hub.ref and in
// the fault buffer NV_MMU_FAULT_BUF_ENTRY documentation in dev_mmu_fault.ref.
// This context can then be torn down using the following procedure.
// 
//      Note when a PBDMA fault or CE fault occurs, the PBDMA will save out
// automatically.  The TSG related to the context in which the fault occurred will
// not be scheduled again until the fault is handled.
// 
//      In the case of some other issue requiring the engine to be reset, the TSG
// will need to be manually preempted.
// 
//      In all cases, a PBDMA interrupt may occur prior to the PBDMA being able to
// switch out.  SW must handle these interrupts according to the relevant handling
// procedure before the PBDMA preempt can complete.
// 
// Context TSG teardown procedure:
// 
//   1. Disable scheduling for the engine's runlist via NV_RUNLIST_SCHED_DISABLE.
//      This enables SW to determine whether a context has hung later in the
//      process: otherwise, ongoing work on the runlist may keep ENGINE_STATUS0
//      from reaching a steady state.
// 
//   2. Disable all channels in the TSG being torn down or submit a new runlist
//      that does not contain the TSG.  This is to prevent the TSG from being
//      rescheduled once scheduling is reenabled in step 6.
// 
//   3. Initiate a preempt of the engine by writing the bit associated with its
//      runlist to NV_RUNLIST_PREEMPT with TYPE=RUNLIST.  This allows us to begin
//      the preempt process prior to doing the slow register reads needed to
//      determine whether the context has hit any interrupts or is hung.  Do not
//      poll NV_RUNLIST_PREEMPT_RUNLIST_PREEMPT_PENDING for the preempt to
//      complete.
// 
//   4. Check for interrupts or hangs while waiting for the preempt to complete.
//      During the below polling, any stalling interrupts relating to the runlist
//      must be detected and handled in order for the preemption to complete.  SW
//      should follow the following sub-steps to cleanly tear down the context:
// 
//     a. Wait for PBDMA preempt completion: For each PBDMA which serves the
//        runlist, poll NV_PPBDMA_STATUS_SCHED(pbdma_id) to reach CHAN_STATUS
//        INVALID, indicating that no further work will run on the PBDMA during the
//        teardown sequence.  Interleaved with the polling, PBDMA interrupts must
//        be serviced as they arise: such an interrupt can prevent the PBDMA from
//        completing its channel save.
// 
//        Note: SW can use the RUNLIST_PREEMPT_COMPLETE notification intr instead
//        of polling.
// 
//     b. Wait for engine context preempt completion: For each engine served by the
//        runlist, read NV_RUNLIST_ENGINE_STATUS0(engine_id) to verify the
//        channel/TSG has saved off the engine, or tell if the CTXSW is hung, via
//        the CTX_STATUS, ID, and NEXT_ID fields.  Take action based on the
//        following values for the CTX_STATUS field:
// 
//       i. CTX_STATUS_SWITCH: Engine save hasn't started yet, continue to poll
//          (repeat step 4b).
// 
//       ii. CTX_STATUS_INVALID: The engine context has switched off.  The
//          preemption step for this engine is complete.
// 
//       iii. CTX_STATUS_VALID or CTX_STATUS_CTXSW_SAVE: check the ID field:
//         * If ID matches the TSG for the context being torn down, the engine
//           reset procedure can be performed (see step 5), or SW can continue
//           waiting by repeating step 4b.
//         * If ID does NOT match, then skip engine reset (skip step 5) for this
//           engine.  The context isn't running on the engine.
// 
//       iv. CTX_STATUS_LOAD: check the NEXT_ID field:
//         * If NEXT_ID matches the TSG of the context being torn down, the engine
//           is loading the context and reset (see step 5) can be performed
//           immediately or after a delay to allow the context a chance to load and
//           be saved off.
//         * If NEXT_ID does not match the TSG ID then the context is no longer on
//           the engine.  Skip engine reset (skip step 5) for this engine.
// 
//        SW may alternatively wait for the CTX_STATUS to reach INVALID, but this
//        may take longer if an unrelated context is currently on the engine or
//        being switched to.
// 
//   5. If a reset is needed as determined by step 4:
// 
//     a. Halt the memory interface for the engine (as per the relevant engine
//        procedure).
// 
//     b. Reset the engine via NV_PMC_ENABLE.
// 
//     c. Take the engine out of reset and reinit the engine (as per the relevant
//        engine procedure)
// 
//   6. Re-enable scheduling for the engine's runlist via NV_RUNLIST_SCHED_ENABLE.
// 
//   7. Finally, reset the channel RAM state for the channels in the TSG torn down
//      by writing NV_CHRAM_CHANNEL_UPDATE_CLEAR_CHANNEL to each channel in the
//      TSG.
// 
// After this sequence, resources for the channels in the TSG may be reclaimed.
// 
// KEY
// ===============================================================================
//     Runlist-Specific Resets (3rd Field: [> --I-- <])
//      'I' = Initialized with hot_sysclk_reset_.
// 
