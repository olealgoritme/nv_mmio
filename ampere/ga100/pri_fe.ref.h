// --------------------------------------------------------------------------------
// 
#define NV_PGRAPH_PRI_FE_HWW_ESR                              0x00404000 /* RWE4R */
#define NV_PGRAPH_PRI_FE_HWW_ESR_INJECTED_BUNDLE_ERROR               0:0 /* R-EVF */
#define NV_PGRAPH_PRI_FE_HWW_ESR_INJECTED_BUNDLE_ERROR_NOT_PENDING   0x0 /* R-E-V */
#define NV_PGRAPH_PRI_FE_HWW_ESR_INJECTED_BUNDLE_ERROR_PENDING       0x1 /* R---V */
#define NV_PGRAPH_PRI_FE_HWW_ESR_CLASS_SUBCH_MISMATCH                1:1 /* R-EVF */
#define NV_PGRAPH_PRI_FE_HWW_ESR_CLASS_SUBCH_MISMATCH_NOT_PENDING    0x0 /* R-E-V */
#define NV_PGRAPH_PRI_FE_HWW_ESR_CLASS_SUBCH_MISMATCH_PENDING        0x1 /* R---V */
#define NV_PGRAPH_PRI_FE_HWW_ESR_SPECULATIVE_GO_IDLE                 3:3 /* R-EVF */
#define NV_PGRAPH_PRI_FE_HWW_ESR_SPECULATIVE_GO_IDLE_NOT_PENDING     0x0 /* R-E-V */
#define NV_PGRAPH_PRI_FE_HWW_ESR_SPECULATIVE_GO_IDLE_PENDING         0x1 /* R---V */
#define NV_PGRAPH_PRI_FE_HWW_ESR_ILLEGAL_FE_ATOMIC_SEQ               4:4 /* R-EVF */
#define NV_PGRAPH_PRI_FE_HWW_ESR_ILLEGAL_FE_ATOMIC_SEQ_NOT_PENDING   0x0 /* R-E-V */
#define NV_PGRAPH_PRI_FE_HWW_ESR_ILLEGAL_FE_ATOMIC_SEQ_PENDING       0x1 /* R---V */
#define NV_PGRAPH_PRI_FE_HWW_ESR_ILLEGAL_SMC_MEM_PARTITIONING               5:5 /* R-EVF */
#define NV_PGRAPH_PRI_FE_HWW_ESR_ILLEGAL_SMC_MEM_PARTITIONING_NOT_PENDING   0x0 /* R-E-V */
#define NV_PGRAPH_PRI_FE_HWW_ESR_ILLEGAL_SMC_MEM_PARTITIONING_PENDING       0x1 /* R---V */
#define NV_PGRAPH_PRI_FE_HWW_ESR_RESET                             30:30 /* -WEVF */
#define NV_PGRAPH_PRI_FE_HWW_ESR_RESET_V_0                           0x0 /* -WE-V */
#define NV_PGRAPH_PRI_FE_HWW_ESR_RESET_ACTIVE                        0x1 /* -W--T */
#define NV_PGRAPH_PRI_FE_HWW_ESR_EN                                31:31 /* RWEVF */
#define NV_PGRAPH_PRI_FE_HWW_ESR_EN_DISABLE                          0x0 /* RW--V */
#define NV_PGRAPH_PRI_FE_HWW_ESR_EN_ENABLE                           0x1 /* RWE-V */
#define NV_PGRAPH_PRI_FE_HWW_ESR_INFO                              0x004041B0 /* R--4R */
#define NV_PGRAPH_PRI_FE_HWW_ESR_INFO_CLASS_SUBCH_MISMATCH_CLASS         15:0 /* R-EVF */
#define NV_PGRAPH_PRI_FE_HWW_ESR_INFO_CLASS_SUBCH_MISMATCH_CLASS_0        0x0 /* R-E-V */
#define NV_PGRAPH_PRI_FE_HWW_ESR_INFO_CLASS_SUBCH_MISMATCH_SUBCH        18:16 /* R-EVF */
#define NV_PGRAPH_PRI_FE_HWW_ESR_INFO_CLASS_SUBCH_MISMATCH_SUBCH_0        0x0 /* R-E-V */
#define NV_PGRAPH_PRI_FE_HWW_ESR_INFO_CLASS_SUBCH_MISMATCH_SUBCH_1        0x1 /* R---V */
#define NV_PGRAPH_PRI_FE_HWW_ESR_INFO_CLASS_SUBCH_MISMATCH_FEPIPE       19:19 /* R-EVF */
#define NV_PGRAPH_PRI_FE_HWW_ESR_INFO_CLASS_SUBCH_MISMATCH_FEPIPE_FE0     0x0 /* R-E-V */
#define NV_PGRAPH_PRI_FE_HWW_ESR_INFO_CLASS_SUBCH_MISMATCH_FEPIPE_FE1     0x1 /* R---V */
#define NV_PGRAPH_PRI_FE_HWW_ESR_INFO_ILLEGAL_FE_ATOMIC_SEQ_FEPIPE      21:21 /* R-EVF */
#define NV_PGRAPH_PRI_FE_HWW_ESR_INFO_ILLEGAL_FE_ATOMIC_SEQ_FEPIPE_FE0    0x0 /* R-E-V */
#define NV_PGRAPH_PRI_FE_HWW_ESR_INFO_ILLEGAL_FE_ATOMIC_SEQ_FEPIPE_FE1    0x1 /* R---V */
#define NV_PGRAPH_PRI_FE_HWW_ESR_INFO_VEID     6+23:24 /* R-EVF */
#define NV_PGRAPH_PRI_FE_HWW_ESR_INFO_VEID_INIT                           0x0 /* R-E-V */
#define NV_PGRAPH_PRI_FE_CHIP_DEF_INFO                                     0x00404030 /* C--4R */
#define NV_PGRAPH_PRI_FE_CHIP_DEF_INFO_MAX_VEID_COUNT                            11:0 /* C--UF */
#define NV_PGRAPH_PRI_FE_CHIP_DEF_INFO_MAX_VEID_COUNT_INIT       64 /* C--UV */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_A                      0x0040413C /* R--4R */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_A_OFFSET_UPPER                7:0 /* R-XVF */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_B                      0x00404140 /* R--4R */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_B_OFFSET_LOWER               31:0 /* R-XVF */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_C                      0x00404144 /* R--4R */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_C_PAYLOAD                    31:0 /* R-XVF */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D                                              0x00404148 /* R--4R */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_OPERATION                                           3:0 /* R-XVF */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_OPERATION_RELEASE                            0x00000000 /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_OPERATION_REPORT_ONLY                        0x00000002 /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_OPERATION_TRAP                               0x00000003 /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_OPERATION_FLUSH_PENDING_WRITES               0x00000004 /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_PIPELINE_LOCATION                                   7:4 /* R-XVF */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_PIPELINE_LOCATION_WORLD                      0x00000000 /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_PIPELINE_LOCATION_WORLD_ALPHA                0x00000001 /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_PIPELINE_LOCATION_WORLD_BETA                 0x00000002 /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_PIPELINE_LOCATION_CWD                        0x00000003 /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_PIPELINE_LOCATION_SCREEN                     0x00000004 /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_PIPELINE_LOCATION_FE                         0x00000005 /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_PIPELINE_LOCATION_SCREEN_CROP                0x00000006 /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_COMPARISON                                          8:8 /* R-XVF */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_COMPARISON_EQ                                0x00000000 /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_COMPARISON_GE                                0x00000001 /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_AWAKEN_ENABLE                                       9:9 /* R-XVF */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_AWAKEN_ENABLE_FALSE                          0x00000000 /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_AWAKEN_ENABLE_TRUE                           0x00000001 /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_REPORT                                            14:10 /* R-XVF */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_REPORT_NONE                                  0x00000000 /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_REPORT_DA_VERTICES_GENERATED                 0x00000001 /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_REPORT_ZPASS_PIXEL_CNT                       0x00000002 /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_REPORT_DA_PRIMITIVES_GENERATED               0x00000003 /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_REPORT_ALPHA_BETA_CLOCKS                     0x00000004 /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_REPORT_VS_INVOCATIONS                        0x00000005 /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_REPORT_STREAMING_PRIMITIVES_NEEDED_MIN_SUCC  0x00000006 /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_REPORT_GS_INVOCATIONS                        0x00000007 /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_REPORT_GS_PRIMITIVES_GENERATED               0x00000009 /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_REPORT_ZCULL_STATS0                          0x0000000A /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_REPORT_STREAMING_PRIMITIVES_SUCCEEDED        0x0000000B /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_REPORT_ZCULL_STATS1                          0x0000000C /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_REPORT_STREAMING_PRIMITIVES_NEEDED           0x0000000D /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_REPORT_ZCULL_STATS2                          0x0000000E /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_REPORT_CLIPPER_INVOCATIONS                   0x0000000F /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_REPORT_ZCULL_STATS3                          0x00000010 /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_REPORT_CLIPPER_PRIMITIVES_GENERATED          0x00000011 /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_REPORT_VTG_PRIMITIVES_OUT                    0x00000012 /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_REPORT_PS_INVOCATIONS                        0x00000013 /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_REPORT_ZPASS_PIXEL_CNT64                     0x00000015 /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_REPORT_IEEE_CLEAN_COLOR_TARGET               0x00000018 /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_REPORT_IEEE_CLEAN_ZETA_TARGET                0x00000019 /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_REPORT_STREAMING_BYTE_COUNT                  0x0000001A /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_REPORT_TI_INVOCATIONS                        0x0000001B /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_REPORT_TS_INVOCATIONS                        0x0000001D /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_REPORT_TOTAL_STREAMING_PRIMS_NEEDED_MIN_SUCC 0x0000001E /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_REPORT_TS_PRIMITIVES_GENERATED               0x0000001F /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_STRUCTURE_SIZE                                    15:15 /* R-XVF */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_STRUCTURE_SIZE_FOUR_WORDS                    0x00000000 /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_STRUCTURE_SIZE_ONE_WORD                      0x00000001 /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_SUB_REPORT                                        18:16 /* R-XVF */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_FLUSH_DISABLE                                     19:19 /* R-XVF */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_FLUSH_DISABLE_FALSE                          0x00000000 /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_FLUSH_DISABLE_TRUE                           0x00000001 /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_REPORT_SIZE                                       20:20 /* R-XVF */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_REPORT_SIZE_FOUR_BYTES                       0x00000000 /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_REPORT_SIZE_EIGHT_BYTES                      0x00000001 /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_REPORT_DWORD_NUM                                  21:21 /* R-XVF */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_REPORT_DWORD_NUM_LOWER                       0x00000000 /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_REPORT_DWORD_NUM_UPPER                       0x00000001 /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_VEID                     6+23:24 /* R-XVF */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_D_VEID_0                                       0x00000000 /* R---V */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_REPORT                     0x0040414C /* R--4R */
#define NV_PGRAPH_PRI_FE_SEMAPHORE_STATE_REPORT_V                         31:0 /* R-XVF */
#define NV_PGRAPH_PRI_FE_GO_IDLE_TIMEOUT                            0x00404154 /* RWI4R */
#define NV_PGRAPH_PRI_FE_GO_IDLE_TIMEOUT_COUNT                            31:0 /* RWIVF */
#define NV_PGRAPH_PRI_FE_GO_IDLE_TIMEOUT_COUNT_INIT                 0x7FFFFFFF /* RWI-V */
#define NV_PGRAPH_PRI_FE_GO_IDLE_TIMEOUT_COUNT__PROD                0x00001800 /* RW--V */
#define NV_PGRAPH_PRI_FE_GO_IDLE_TIMEOUT_COUNT_DISABLED             0x00000000 /* RW--V */
#define NV_PGRAPH_PRI_FE_PWR_MODE                                  0x00404170 /* RWE4R */
#define NV_PGRAPH_PRI_FE_PWR_MODE_MODE                                    1:0 /* RWEVF */
#define NV_PGRAPH_PRI_FE_PWR_MODE_MODE_AUTO                               0x0 /* RWE-V */
#define NV_PGRAPH_PRI_FE_PWR_MODE_MODE_SLOW                               0x1 /* RW--V */
#define NV_PGRAPH_PRI_FE_PWR_MODE_MODE_FORCE_ON                           0x2 /* RW--V */
#define NV_PGRAPH_PRI_FE_PWR_MODE_MODE_FORCE_POWER                        0x3 /* RW--V */
#define NV_PGRAPH_PRI_FE_PWR_MODE_REQ                                     4:4 /* RWEVF */
#define NV_PGRAPH_PRI_FE_PWR_MODE_REQ_DONE                                0x0 /* R-E-V */
#define NV_PGRAPH_PRI_FE_PWR_MODE_REQ_PENDING                             0x1 /* R---V */
#define NV_PGRAPH_PRI_FE_PWR_MODE_REQ_SEND                                0x1 /* -W--T */
#define NV_PGRAPH_PRI_FE_GO_IDLE_INFO                                       0x00404194 /* RWI4R */
#define NV_PGRAPH_PRI_FE_GO_IDLE_INFO_GPM_CNT                                      3:0 /* RWIVF */
#define NV_PGRAPH_PRI_FE_GO_IDLE_INFO_GPM_CNT_INIT                                 0x0 /* RWI-V */
#define NV_PGRAPH_PRI_FE_GO_IDLE_INFO_ROP_CNT                                      7:4 /* RWIVF */
#define NV_PGRAPH_PRI_FE_GO_IDLE_INFO_ROP_CNT_INIT                                 0x0 /* RWI-V */
#define NV_PGRAPH_PRI_FE_GO_IDLE_INFO_MAX_GPM_ROP_CNT                             11:8 /* RWIVF */
#define NV_PGRAPH_PRI_FE_GO_IDLE_INFO_MAX_GPM_ROP_CNT_INIT                         0x7 /* RWI-V */
#define NV_PGRAPH_PRI_FE_GO_IDLE_INFO_SKED_OUTSTANDING_GO_IDLE                   13:12 /* R-IVF */
#define NV_PGRAPH_PRI_FE_GO_IDLE_INFO_SKED_OUTSTANDING_GO_IDLE_IS_NONE             0x0 /* R-I-V */
#define NV_PGRAPH_PRI_FE_GO_IDLE_INFO_SKED_OUTSTANDING_GO_IDLE_IS_SINGLE           0x1 /* R---V */
#define NV_PGRAPH_PRI_FE_GO_IDLE_INFO_SKED_OUTSTANDING_GO_IDLE_IS_ALL              0x2 /* R---V */
#define NV_PGRAPH_PRI_FE_GO_IDLE_INFO_SKED_CNT                                   16:16 /* R-IVF */
#define NV_PGRAPH_PRI_FE_GO_IDLE_INFO_SKED_CNT_MAX                                 0x1 /* R---V */
#define NV_PGRAPH_PRI_FE_GO_IDLE_INFO_SKED_CNT_INIT                                0x0 /* R-I-V */
#define NV_PGRAPH_PRI_FE_GO_IDLE_INFO_I2M_CNT                                    20:20 /* R-IVF */
#define NV_PGRAPH_PRI_FE_GO_IDLE_INFO_I2M_CNT_MAX                                  0x1 /* R---V */
#define NV_PGRAPH_PRI_FE_GO_IDLE_INFO_I2M_CNT_INIT                                 0x0 /* R-I-V */
#define NV_PGRAPH_PRI_FE_GO_IDLE_INFO_GFX_LAST_EMITTER_IS_GO_IDLE                24:24 /* RWIVF */
#define NV_PGRAPH_PRI_FE_GO_IDLE_INFO_GFX_LAST_EMITTER_IS_GO_IDLE_TRUE             0x1 /* R-I-V */
#define NV_PGRAPH_PRI_FE_GO_IDLE_INFO_GFX_LAST_EMITTER_IS_GO_IDLE_FALSE            0x0 /* R---V */
#define NV_PGRAPH_PRI_FE_GFXP_WFI_TIMEOUT                          0x004041C0  /* RWI4R */
#define NV_PGRAPH_PRI_FE_GFXP_WFI_TIMEOUT_COUNT                          31:0  /* RWIVF */
#define NV_PGRAPH_PRI_FE_GFXP_WFI_TIMEOUT_COUNT_INIT               0x00000800  /* RWI-V */
#define NV_PGRAPH_PRI_FE_GFXP_WFI_TIMEOUT_COUNT_DISABLED           0x00000000  /* RW--V */
#define NV_PGRAPH_PRI_FE_CG                          0x004041F0 /* RWE4R */
#define NV_PGRAPH_PRI_FE_CG_IDLE_CG_DLY_CNT                 5:0 /* RWEVF */
#define NV_PGRAPH_PRI_FE_CG_IDLE_CG_DLY_CNT_HWINIT   0x00000000 /* RWE-V */
#define NV_PGRAPH_PRI_FE_CG_IDLE_CG_DLY_CNT__PROD    0x00000006 /* RW--V */
#define NV_PGRAPH_PRI_FE_CG_IDLE_CG_EN                      6:6 /* RWEVF */
#define NV_PGRAPH_PRI_FE_CG_IDLE_CG_EN_ENABLED       0x00000001 /* RW--V */
#define NV_PGRAPH_PRI_FE_CG_IDLE_CG_EN_DISABLED      0x00000000 /* RWE-V */
#define NV_PGRAPH_PRI_FE_CG_IDLE_CG_EN__PROD         0x00000001 /* RW--V */
#define NV_PGRAPH_PRI_FE_CG_STATE_CG_EN                     7:7 /*       */
#define NV_PGRAPH_PRI_FE_CG_STATE_CG_EN_ENABLED      0x00000001 /*       */
#define NV_PGRAPH_PRI_FE_CG_STATE_CG_EN_DISABLED     0x00000000 /*       */
#define NV_PGRAPH_PRI_FE_CG_STATE_CG_EN__PROD        0x00000000 /*       */
#define NV_PGRAPH_PRI_FE_CG_STALL_CG_DLY_CNT               13:8 /*       */
#define NV_PGRAPH_PRI_FE_CG_STALL_CG_DLY_CNT_HWINIT  0x00000000 /*       */
#define NV_PGRAPH_PRI_FE_CG_STALL_CG_DLY_CNT__PROD   0x00000006 /*       */
#define NV_PGRAPH_PRI_FE_CG_STALL_CG_EN                   14:14 /* RWEVF */
#define NV_PGRAPH_PRI_FE_CG_STALL_CG_EN_ENABLED      0x00000001 /* RW--V */
#define NV_PGRAPH_PRI_FE_CG_STALL_CG_EN_DISABLED     0x00000000 /* RWE-V */
#define NV_PGRAPH_PRI_FE_CG_STALL_CG_EN__PROD        0x00000001 /* RW--V */
#define NV_PGRAPH_PRI_FE_CG_QUIESCENT_CG_EN               15:15 /*       */
#define NV_PGRAPH_PRI_FE_CG_QUIESCENT_CG_EN_ENABLED  0x00000001 /*       */
#define NV_PGRAPH_PRI_FE_CG_QUIESCENT_CG_EN_DISABLED 0x00000000 /*       */
#define NV_PGRAPH_PRI_FE_CG_QUIESCENT_CG_EN__PROD    0x00000001 /*       */
#define NV_PGRAPH_PRI_FE_CG_WAKEUP_DLY_CNT                19:16 /* RWEVF */
#define NV_PGRAPH_PRI_FE_CG_WAKEUP_DLY_CNT_HWINIT    0x00000000 /* RWE-V */
#define NV_PGRAPH_PRI_FE_CG_WAKEUP_DLY_CNT__PROD     0x00000000 /* RW--V */
#define NV_PGRAPH_PRI_FE_CG_THROT_CLK_CNT                 23:20 /*       */
#define NV_PGRAPH_PRI_FE_CG_THROT_CLK_CNT_FULLSPEED  0x0000000f /*       */
#define NV_PGRAPH_PRI_FE_CG_THROT_CLK_CNT__PROD      0x00000000 /*       */
#define NV_PGRAPH_PRI_FE_CG_DI_DT_SKEW_VAL                27:24 /*       */
#define NV_PGRAPH_PRI_FE_CG_DI_DT_SKEW_VAL_HWINIT    0x00000000 /*       */
#define NV_PGRAPH_PRI_FE_CG_DI_DT_SKEW_VAL__PROD     0x00000000 /*       */
#define NV_PGRAPH_PRI_FE_CG_THROT_CLK_EN                  28:28 /*       */
#define NV_PGRAPH_PRI_FE_CG_THROT_CLK_EN_ENABLED     0x00000001 /*       */
#define NV_PGRAPH_PRI_FE_CG_THROT_CLK_EN_DISABLED    0x00000000 /*       */
#define NV_PGRAPH_PRI_FE_CG_THROT_CLK_EN__PROD       0x00000000 /*       */
#define NV_PGRAPH_PRI_FE_CG_THROT_CLK_SW_OVER             29:29 /*       */
#define NV_PGRAPH_PRI_FE_CG_THROT_CLK_SW_OVER_EN     0x00000001 /*       */
#define NV_PGRAPH_PRI_FE_CG_THROT_CLK_SW_OVER_DIS    0x00000000 /*       */
#define NV_PGRAPH_PRI_FE_CG_THROT_CLK_SW_OVER__PROD  0x00000000 /*       */
#define NV_PGRAPH_PRI_FE_CG_PAUSE_CG_EN                   30:30 /*       */
#define NV_PGRAPH_PRI_FE_CG_PAUSE_CG_EN_ENABLED      0x00000001 /*       */
#define NV_PGRAPH_PRI_FE_CG_PAUSE_CG_EN_DISABLED     0x00000000 /*       */
#define NV_PGRAPH_PRI_FE_CG_PAUSE_CG_EN__PROD        0x00000000 /*       */
#define NV_PGRAPH_PRI_FE_CG_HALT_CG_EN                    31:31 /*       */
#define NV_PGRAPH_PRI_FE_CG_HALT_CG_EN_ENABLED       0x00000001 /*       */
#define NV_PGRAPH_PRI_FE_CG_HALT_CG_EN_DISABLED      0x00000000 /*       */
#define NV_PGRAPH_PRI_FE_CG_HALT_CG_EN__PROD         0x00000000 /*       */
#define NV_PGRAPH_PRI_FE_CG1                               0x004041F4 /* RWE4R */
#define NV_PGRAPH_PRI_FE_CG1_MONITOR_CG_EN                      0:0 /* RWEVF */
#define NV_PGRAPH_PRI_FE_CG1_MONITOR_CG_EN_ENABLED       0x00000001 /* RW--V */
#define NV_PGRAPH_PRI_FE_CG1_MONITOR_CG_EN_DISABLED      0x00000000 /* RWE-V */
#define NV_PGRAPH_PRI_FE_CG1_MONITOR_CG_EN__PROD         0x00000000 /* RW--V */
#define NV_PGRAPH_PRI_FE_CG1_SLCG                            27:1 /* RWEVF */
#define NV_PGRAPH_PRI_FE_CG1_SLCG_ENABLED                0x00000000 /* RW--V */
#define NV_PGRAPH_PRI_FE_CG1_SLCG_DISABLED               0x07FFFFFF /* RWE-V */
#define NV_PGRAPH_PRI_FE_CG1_SLCG__PROD                  0x00000000 /* RW--V */
#define NV_PGRAPH_PRI_FE_OBJECT_TABLE(i)                    (0x00404200+(i)*4) /* R--4A */
#define NV_PGRAPH_PRI_FE_OBJECT_TABLE__SIZE_1                               4  /*       */
#define NV_PGRAPH_PRI_FE_OBJECT_TABLE_NVCLASS                            15:0  /* R--VF */
#define NV_PGRAPH_PRI_FE_GO_IDLE_INFO_COMPUTE(i)                    (0x00404210+(i)*4) /* RWI4A */
#define NV_PGRAPH_PRI_FE_GO_IDLE_INFO_COMPUTE__SIZE_1                               2  /*       */
#define NV_PGRAPH_PRI_FE_GO_IDLE_INFO_COMPUTE_LAST_EMITTER_IS_GO_IDLE            31:0  /* RWIVF */
#define NV_PGRAPH_PRI_FE_GO_IDLE_INFO_COMPUTE_LAST_EMITTER_IS_GO_IDLE_INIT 0xffffffff  /* R-I-V */
#define NV_PGRAPH_PRI_FE_GO_IDLE_INFO_COMPUTE_LAST_EMITTER_IS_GO_IDLE_TRUE        0x1  /* R---V */
#define NV_PGRAPH_PRI_FE_GO_IDLE_INFO_COMPUTE_LAST_EMITTER_IS_GO_IDLE_FALSE       0x0  /* R---V */
#define NV_PGRAPH_PRI_FE_TPC_FS(i)                   (0x0040A200+(i)*4)                /* R--4A */
#define NV_PGRAPH_PRI_FE_TPC_FS__SIZE_1              8                                 /*       */
#define NV_PGRAPH_PRI_FE_TPC_FS_MASK                 31:0                               /* R-IVF */
#define NV_PGRAPH_PRI_FE_TPC_FS_MASK_TPC_DISABLED    0x00000000                        /* R-I-V */
#define NV_PGRAPH_PRI_FE_TPC_FS_MASK_TPC_ENABLED     0x00000001                        /* R---V */
// 
// --------------------------------------------------------------------------------
