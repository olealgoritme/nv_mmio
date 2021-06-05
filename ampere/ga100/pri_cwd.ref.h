// --------------------------------------------------------------------------------
// 
#define NV_PGRAPH_PRI_CWD_FS                                    0x00405B00 /* RWE4R */
#define NV_PGRAPH_PRI_CWD_FS_NUM_GPCS                                  7:0 /* RWEVF */
#define NV_PGRAPH_PRI_CWD_FS_NUM_GPCS_INIT                             0x0 /* RWE-V */
#define NV_PGRAPH_PRI_CWD_FS_NUM_TPCS                                 15:8 /* RWEVF */
#define NV_PGRAPH_PRI_CWD_FS_NUM_TPCS_INIT                             0x0 /* RWE-V */
#define NV_PGRAPH_PRI_CWD_DELAY_CILP_PREEMPT                         0x00405B24 /* RWI4R */
#define NV_PGRAPH_PRI_CWD_DELAY_CILP_PREEMPT_TIMEOUT                       31:0 /* RWIVF */
#define NV_PGRAPH_PRI_CWD_DELAY_CILP_PREEMPT_TIMEOUT_INIT            0x00000000 /* RWI-V */
#define NV_PGRAPH_PRI_CWD_PARTITION_CTL                            0x00405B2c /* RWI4R */
#define NV_PGRAPH_PRI_CWD_PARTITION_CTL_PARTITIONING_SELECT                1:0 /* RWIVF */
#define NV_PGRAPH_PRI_CWD_PARTITION_CTL_PARTITIONING_SELECT_NONE           0x0 /* RWI-V */
#define NV_PGRAPH_PRI_CWD_PARTITION_CTL_PARTITIONING_SELECT_STATIC         0x1 /* RW--V */
#define NV_PGRAPH_PRI_CWD_PARTITION_CTL_PARTITIONING_SELECT_DYNAMIC        0x2 /* RW--V */
#define NV_PGRAPH_PRI_CWD_PARTITION_CTL_TBL_SEL                             3:2 /* RWIVF */
#define NV_PGRAPH_PRI_CWD_PARTITION_CTL_TBL_SEL_NONE                        0x0 /* RWI-V */
#define NV_PGRAPH_PRI_CWD_PARTITION_CTL_TBL_SEL_PARTITIONING_ENABLE        0x1 /* RW--V */
#define NV_PGRAPH_PRI_CWD_PARTITION_CTL_TBL_SEL_PARTITIONING_LMEM_BLK      0x2 /* RW--V */
#define NV_PGRAPH_PRI_CWD_PARTITION_CTL_VEID_OFFSET                          21:16 /* RWIVF */
#define NV_PGRAPH_PRI_CWD_PARTITION_CTL_VEID_OFFSET_ZERO                     0x0  /* RWI-V */
#define NV_PGRAPH_PRI_CWD_PARTITION_CTL_VEID_OFFSET_MAX                      0x3f /* RW--V */
#define NV_PGRAPH_PRI_CWD_PARTITION_CTL_TBL_OFFSET                                               29:24 /* RWIVF */
#define NV_PGRAPH_PRI_CWD_PARTITION_CTL_TBL_OFFSET_ZERO                                            0x0 /* RWI-V */
#define NV_PGRAPH_PRI_CWD_PARTITION_CTL_TBL_OFFSET_PARTITIONING_ENABLE_MAX    1 /* RW--V */
#define NV_PGRAPH_PRI_CWD_PARTITION_CTL_TBL_OFFSET_PARTITIONING_LMEM_BLK_MAX  15  /* RW--V */
#define NV_PGRAPH_PRI_CWD_PARTITION_DATA                            0x00405B30 /* RWI4R */
#define NV_PGRAPH_PRI_CWD_PARTITION_DATA_REG                              31:0 /* RWIVF */
#define NV_PGRAPH_PRI_CWD_PARTITION_DATA_REG_INIT                          0x0 /* RWI-V */
#define NV_PGRAPH_PRI_CWD_GPC_TPC_ID(i)                        (0x00405B60+(i)*4) /* RWE4A */
#define NV_PGRAPH_PRI_CWD_GPC_TPC_ID__SIZE_1                                   16 /*       */
#define NV_PGRAPH_PRI_CWD_GPC_TPC_ID_TPC0                                     3:0 /* RWEVF */
#define NV_PGRAPH_PRI_CWD_GPC_TPC_ID_TPC0_INIT                         0x00000000 /* RWE-V */
#define NV_PGRAPH_PRI_CWD_GPC_TPC_ID_GPC0                                     7:4 /* RWEVF */
#define NV_PGRAPH_PRI_CWD_GPC_TPC_ID_GPC0_INIT                         0x00000000 /* RWE-V */
#define NV_PGRAPH_PRI_CWD_GPC_TPC_ID_TPC1                                    11:8 /* RWEVF */
#define NV_PGRAPH_PRI_CWD_GPC_TPC_ID_TPC1_INIT                         0x00000000 /* RWE-V */
#define NV_PGRAPH_PRI_CWD_GPC_TPC_ID_GPC1                                   15:12 /* RWEVF */
#define NV_PGRAPH_PRI_CWD_GPC_TPC_ID_GPC1_INIT                         0x00000000 /* RWE-V */
#define NV_PGRAPH_PRI_CWD_GPC_TPC_ID_TPC2                                   19:16 /* RWEVF */
#define NV_PGRAPH_PRI_CWD_GPC_TPC_ID_TPC2_INIT                         0x00000000 /* RWE-V */
#define NV_PGRAPH_PRI_CWD_GPC_TPC_ID_GPC2                                   23:20 /* RWEVF */
#define NV_PGRAPH_PRI_CWD_GPC_TPC_ID_GPC2_INIT                         0x00000000 /* RWE-V */
#define NV_PGRAPH_PRI_CWD_GPC_TPC_ID_TPC3                                   27:24 /* RWEVF */
#define NV_PGRAPH_PRI_CWD_GPC_TPC_ID_TPC3_INIT                         0x00000000 /* RWE-V */
#define NV_PGRAPH_PRI_CWD_GPC_TPC_ID_GPC3                                   31:28 /* RWEVF */
#define NV_PGRAPH_PRI_CWD_GPC_TPC_ID_GPC3_INIT                         0x00000000 /* RWE-V */
#define NV_PGRAPH_PRI_CWD_SM_ID(i)                        (0x00405Ba0+(i)*4) /* RWE4A */
#define NV_PGRAPH_PRI_CWD_SM_ID__SIZE_1                                   16 /*       */
#define NV_PGRAPH_PRI_CWD_SM_ID_TPC0                                     7:0 /* RWEVF */
#define NV_PGRAPH_PRI_CWD_SM_ID_TPC0_INIT                         0x00000000 /* RWE-V */
#define NV_PGRAPH_PRI_CWD_SM_ID_TPC1                                    15:8 /* RWEVF */
#define NV_PGRAPH_PRI_CWD_SM_ID_TPC1_INIT                         0x00000000 /* RWE-V */
#define NV_PGRAPH_PRI_CWD_SM_ID_TPC2                                   23:16 /* RWEVF */
#define NV_PGRAPH_PRI_CWD_SM_ID_TPC2_INIT                         0x00000000 /* RWE-V */
#define NV_PGRAPH_PRI_CWD_SM_ID_TPC3                                   31:24 /* RWEVF */
#define NV_PGRAPH_PRI_CWD_SM_ID_TPC3_INIT                         0x00000000 /* RWE-V */
#define NV_PGRAPH_PRI_CWD_CG                          0x00405BF0 /* RWE4R */
#define NV_PGRAPH_PRI_CWD_CG_IDLE_CG_DLY_CNT                 5:0 /* RWEVF */
#define NV_PGRAPH_PRI_CWD_CG_IDLE_CG_DLY_CNT_HWINIT   0x00000000 /* RWE-V */
#define NV_PGRAPH_PRI_CWD_CG_IDLE_CG_DLY_CNT__PROD    0x00000004 /* RW--V */
#define NV_PGRAPH_PRI_CWD_CG_IDLE_CG_EN                      6:6 /* RWEVF */
#define NV_PGRAPH_PRI_CWD_CG_IDLE_CG_EN_ENABLED       0x00000001 /* RW--V */
#define NV_PGRAPH_PRI_CWD_CG_IDLE_CG_EN_DISABLED      0x00000000 /* RWE-V */
#define NV_PGRAPH_PRI_CWD_CG_IDLE_CG_EN__PROD         0x00000001 /* RW--V */
#define NV_PGRAPH_PRI_CWD_CG_STATE_CG_EN                     7:7 /*       */
#define NV_PGRAPH_PRI_CWD_CG_STATE_CG_EN_ENABLED      0x00000001 /*       */
#define NV_PGRAPH_PRI_CWD_CG_STATE_CG_EN_DISABLED     0x00000000 /*       */
#define NV_PGRAPH_PRI_CWD_CG_STATE_CG_EN__PROD        0x00000000 /*       */
#define NV_PGRAPH_PRI_CWD_CG_STALL_CG_DLY_CNT               13:8 /*       */
#define NV_PGRAPH_PRI_CWD_CG_STALL_CG_DLY_CNT_HWINIT  0x00000000 /*       */
#define NV_PGRAPH_PRI_CWD_CG_STALL_CG_DLY_CNT__PROD   0x00000004 /*       */
#define NV_PGRAPH_PRI_CWD_CG_STALL_CG_EN                   14:14 /* RWEVF */
#define NV_PGRAPH_PRI_CWD_CG_STALL_CG_EN_ENABLED      0x00000001 /* RW--V */
#define NV_PGRAPH_PRI_CWD_CG_STALL_CG_EN_DISABLED     0x00000000 /* RWE-V */
#define NV_PGRAPH_PRI_CWD_CG_STALL_CG_EN__PROD        0x00000001 /* RW--V */
#define NV_PGRAPH_PRI_CWD_CG_QUIESCENT_CG_EN               15:15 /*       */
#define NV_PGRAPH_PRI_CWD_CG_QUIESCENT_CG_EN_ENABLED  0x00000001 /*       */
#define NV_PGRAPH_PRI_CWD_CG_QUIESCENT_CG_EN_DISABLED 0x00000000 /*       */
#define NV_PGRAPH_PRI_CWD_CG_QUIESCENT_CG_EN__PROD    0x00000001 /*       */
#define NV_PGRAPH_PRI_CWD_CG_WAKEUP_DLY_CNT                19:16 /* RWEVF */
#define NV_PGRAPH_PRI_CWD_CG_WAKEUP_DLY_CNT_HWINIT    0x00000000 /* RWE-V */
#define NV_PGRAPH_PRI_CWD_CG_WAKEUP_DLY_CNT__PROD     0x00000000 /* RW--V */
#define NV_PGRAPH_PRI_CWD_CG_THROT_CLK_CNT                 23:20 /*       */
#define NV_PGRAPH_PRI_CWD_CG_THROT_CLK_CNT_FULLSPEED  0x0000000f /*       */
#define NV_PGRAPH_PRI_CWD_CG_THROT_CLK_CNT__PROD      0x00000000 /*       */
#define NV_PGRAPH_PRI_CWD_CG_DI_DT_SKEW_VAL                27:24 /*       */
#define NV_PGRAPH_PRI_CWD_CG_DI_DT_SKEW_VAL_HWINIT    0x00000000 /*       */
#define NV_PGRAPH_PRI_CWD_CG_DI_DT_SKEW_VAL__PROD     0x00000000 /*       */
#define NV_PGRAPH_PRI_CWD_CG_THROT_CLK_EN                  28:28 /*       */
#define NV_PGRAPH_PRI_CWD_CG_THROT_CLK_EN_ENABLED     0x00000001 /*       */
#define NV_PGRAPH_PRI_CWD_CG_THROT_CLK_EN_DISABLED    0x00000000 /*       */
#define NV_PGRAPH_PRI_CWD_CG_THROT_CLK_EN__PROD       0x00000000 /*       */
#define NV_PGRAPH_PRI_CWD_CG_THROT_CLK_SW_OVER             29:29 /*       */
#define NV_PGRAPH_PRI_CWD_CG_THROT_CLK_SW_OVER_EN     0x00000001 /*       */
#define NV_PGRAPH_PRI_CWD_CG_THROT_CLK_SW_OVER_DIS    0x00000000 /*       */
#define NV_PGRAPH_PRI_CWD_CG_THROT_CLK_SW_OVER__PROD  0x00000000 /*       */
#define NV_PGRAPH_PRI_CWD_CG_PAUSE_CG_EN                   30:30 /*       */
#define NV_PGRAPH_PRI_CWD_CG_PAUSE_CG_EN_ENABLED      0x00000001 /*       */
#define NV_PGRAPH_PRI_CWD_CG_PAUSE_CG_EN_DISABLED     0x00000000 /*       */
#define NV_PGRAPH_PRI_CWD_CG_PAUSE_CG_EN__PROD        0x00000000 /*       */
#define NV_PGRAPH_PRI_CWD_CG_HALT_CG_EN                    31:31 /*       */
#define NV_PGRAPH_PRI_CWD_CG_HALT_CG_EN_ENABLED       0x00000001 /*       */
#define NV_PGRAPH_PRI_CWD_CG_HALT_CG_EN_DISABLED      0x00000000 /*       */
#define NV_PGRAPH_PRI_CWD_CG_HALT_CG_EN__PROD         0x00000000 /*       */
#define NV_PGRAPH_PRI_CWD_CG1                               0x00405BF4 /* RWE4R */
#define NV_PGRAPH_PRI_CWD_CG1_MONITOR_CG_EN                      0:0 /* RWEVF */
#define NV_PGRAPH_PRI_CWD_CG1_MONITOR_CG_EN_ENABLED       0x00000001 /* RW--V */
#define NV_PGRAPH_PRI_CWD_CG1_MONITOR_CG_EN_DISABLED      0x00000000 /* RWE-V */
#define NV_PGRAPH_PRI_CWD_CG1_MONITOR_CG_EN__PROD         0x00000000 /* RW--V */
#define NV_PGRAPH_PRI_CWD_CG1_SLCG                            1:1 /* RWEVF */
#define NV_PGRAPH_PRI_CWD_CG1_SLCG_ENABLED                0x00000000 /* RW--V */
#define NV_PGRAPH_PRI_CWD_CG1_SLCG_DISABLED               0x00000001 /* RWE-V */
#define NV_PGRAPH_PRI_CWD_CG1_SLCG__PROD                  0x00000000 /* RW--V */
// 
// --------------------------------------------------------------------------------
