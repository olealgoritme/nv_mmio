// --------------------------------------------------------------------------------
// 
#define NV_PMC                                0x00000fff:0x00000000 /* RW--D */
#define NV_PMC_BOOT_0                                    0x00000000 /* R--4R */
#define NV_PMC_BOOT_0_ID                                       31:0 /*       */
#define NV_PMC_BOOT_0_MINOR_REVISION                            3:0 /* R--VF */
#define NV_PMC_BOOT_0_MINOR_REVISION_1                   0x00000001 /* R---V */
#define NV_PMC_BOOT_0_MINOR_REVISION_2                   0x00000002 /* R---V */
#define NV_PMC_BOOT_0_MINOR_REVISION_3                   0x00000003 /* R---V */
#define NV_PMC_BOOT_0_MINOR_REVISION_4                   0x00000004 /* R---V */
#define NV_PMC_BOOT_0_MINOR_REVISION_5                   0x00000005 /* R---V */
#define NV_PMC_BOOT_0_MINOR_REVISION_6                   0x00000006 /* R---V */
#define NV_PMC_BOOT_0_MINOR_REVISION_7                   0x00000007 /* R---V */
#define NV_PMC_BOOT_0_MINOR_REVISION_8                   0x00000008 /* R---V */
#define NV_PMC_BOOT_0_MINOR_REVISION_9                   0x00000009 /* R---V */
#define NV_PMC_BOOT_0_MINOR_REVISION_10                  0x0000000A /* R---V */
#define NV_PMC_BOOT_0_MINOR_REVISION_11                  0x0000000B /* R---V */
#define NV_PMC_BOOT_0_MINOR_REVISION_12                  0x0000000C /* R---V */
#define NV_PMC_BOOT_0_MINOR_REVISION_13                  0x0000000D /* R---V */
#define NV_PMC_BOOT_0_MINOR_REVISION_14                  0x0000000E /* R---V */
#define NV_PMC_BOOT_0_MINOR_REVISION_15                  0x0000000F /* R---V */
#define NV_PMC_BOOT_0_MINOR_REVISION_INIT                0x00000001 /* R---V */
#define NV_PMC_BOOT_0_MAJOR_REVISION                            7:4 /* R--VF */
#define NV_PMC_BOOT_0_MAJOR_REVISION_A                   0x0000000A /* R---V */
#define NV_PMC_BOOT_0_MAJOR_REVISION_B                   0x0000000B /* R---V */
#define NV_PMC_BOOT_0_MAJOR_REVISION_C                   0x0000000C /* R---V */
#define NV_PMC_BOOT_0_MAJOR_REVISION_D                   0x0000000D /* R---V */
#define NV_PMC_BOOT_0_MAJOR_REVISION_E                   0x0000000E /* R---V */
#define NV_PMC_BOOT_0_MAJOR_REVISION_F                   0x0000000F /* R---V */
#define NV_PMC_BOOT_0_MAJOR_REVISION_INIT                0x00000000 /* R---V */
#define NV_PMC_BOOT_0_RESERVED_0                               11:8 /*       */
#define NV_PMC_BOOT_0_IMPLEMENTATION                          23:20 /* R--VF */
#define NV_PMC_BOOT_0_IMPLEMENTATION_0                   0x00000000 /* R---V */
#define NV_PMC_BOOT_0_IMPLEMENTATION_1                   0x00000001 /* R---V */
#define NV_PMC_BOOT_0_IMPLEMENTATION_2                   0x00000002 /* R---V */
#define NV_PMC_BOOT_0_IMPLEMENTATION_3                   0x00000003 /* R---V */
#define NV_PMC_BOOT_0_IMPLEMENTATION_4                   0x00000004 /* R---V */
#define NV_PMC_BOOT_0_IMPLEMENTATION_5                   0x00000005 /* R---V */
#define NV_PMC_BOOT_0_IMPLEMENTATION_6                   0x00000006 /* R---V */
#define NV_PMC_BOOT_0_IMPLEMENTATION_7                   0x00000007 /* R---V */
#define NV_PMC_BOOT_0_IMPLEMENTATION_8                   0x00000008 /* R---V */
#define NV_PMC_BOOT_0_IMPLEMENTATION_9                   0x00000009 /* R---V */
#define NV_PMC_BOOT_0_IMPLEMENTATION_A                   0x0000000A /* R---V */
#define NV_PMC_BOOT_0_IMPLEMENTATION_B                   0x0000000B /* R---V */
#define NV_PMC_BOOT_0_IMPLEMENTATION_C                   0x0000000C /* R---V */
#define NV_PMC_BOOT_0_IMPLEMENTATION_D                   0x0000000D /* R---V */
#define NV_PMC_BOOT_0_IMPLEMENTATION_E                   0x0000000E /* R---V */
#define NV_PMC_BOOT_0_IMPLEMENTATION_F                   0x0000000F /* R---V */
#define NV_PMC_BOOT_0_IMPLEMENTATION_INIT                0x00000000 /* R---V */
#define NV_PMC_BOOT_0_ARCHITECTURE                            28:24 /* R--VF */
#define NV_PMC_BOOT_0_ARCHITECTURE_GF100                 0x0000000C /* R---V */
#define NV_PMC_BOOT_0_ARCHITECTURE_GF110                 0x0000000D /* R---V */
#define NV_PMC_BOOT_0_ARCHITECTURE_GK100                 0x0000000E /* R---V */
#define NV_PMC_BOOT_0_ARCHITECTURE_GK110                 0x0000000F /* R---V */
#define NV_PMC_BOOT_0_ARCHITECTURE_GK200                 0x00000010 /* R---V */
#define NV_PMC_BOOT_0_ARCHITECTURE_GM000                 0x00000011 /* R---V */
#define NV_PMC_BOOT_0_ARCHITECTURE_GM100                 0x00000011 /* R---V */
#define NV_PMC_BOOT_0_ARCHITECTURE_GM200                 0x00000012 /* R---V */
#define NV_PMC_BOOT_0_ARCHITECTURE_GP100                 0x00000013 /* R---V */
#define NV_PMC_BOOT_0_ARCHITECTURE_GV100                 0x00000014 /* R---V */
#define NV_PMC_BOOT_0_ARCHITECTURE_GV110                 0x00000015 /* R---V */
#define NV_PMC_BOOT_0_ARCHITECTURE_TU100                 0x00000016 /* R---V */
#define NV_PMC_BOOT_0_ARCHITECTURE_TU110                 0x00000016 /* R---V */
#define NV_PMC_BOOT_0_ARCHITECTURE_GA100                 0x00000017 /* R---V */
#define NV_PMC_BOOT_1                                    0x00000004 /* C--4R */
#define NV_PMC_BOOT_1_VGPU8                                     8:8 /* C--VF */
#define NV_PMC_BOOT_1_VGPU8_REAL                         0x00000000 /* C---V */
#define NV_PMC_BOOT_1_VGPU8_VIRTUAL                      0x00000001 /* ----V */
#define NV_PMC_BOOT_1_VGPU16                                  16:16 /*       */
#define NV_PMC_BOOT_1_VGPU16_REAL                        0x00000000 /*       */
#define NV_PMC_BOOT_1_VGPU16_VIRTUAL                     0x00000001 /*       */
#define NV_PMC_BOOT_1_VGPU                                    17:16 /* C--VF */
#define NV_PMC_BOOT_1_VGPU_REAL                          0x00000000 /* C---V */
#define NV_PMC_BOOT_2                                    0x00000008 /* R--4R */
#define NV_PMC_BOOT_2_MINOR_EXTENDED_REVISION                   3:0 /* R-XVF */
#define NV_PMC_BOOT_2_MINOR_EXTENDED_REVISION_0          0x00000000 /* R---V */
#define NV_PMC_BOOT_2_MINOR_EXTENDED_REVISION_1          0x00000001 /* R---V */
#define NV_PMC_BOOT_2_MINOR_EXTENDED_REVISION_2          0x00000002 /* R---V */
#define NV_PMC_BOOT_2_MINOR_EXTENDED_REVISION_3          0x00000003 /* R---V */
#define NV_PMC_BOOT_2_MINOR_EXTENDED_REVISION_4          0x00000004 /* R---V */
#define NV_PMC_BOOT_2_MINOR_EXTENDED_REVISION_5          0x00000005 /* R---V */
#define NV_PMC_BOOT_2_MINOR_EXTENDED_REVISION_6          0x00000006 /* R---V */
#define NV_PMC_BOOT_2_MINOR_EXTENDED_REVISION_7          0x00000007 /* R---V */
#define NV_PMC_BOOT_2_MINOR_EXTENDED_REVISION_8          0x00000008 /* R---V */
#define NV_PMC_BOOT_2_MINOR_EXTENDED_REVISION_9          0x00000009 /* R---V */
#define NV_PMC_BOOT_2_MINOR_EXTENDED_REVISION_A          0x0000000A /* R---V */
#define NV_PMC_BOOT_2_MINOR_EXTENDED_REVISION_B          0x0000000B /* R---V */
#define NV_PMC_BOOT_2_MINOR_EXTENDED_REVISION_C          0x0000000C /* R---V */
#define NV_PMC_BOOT_2_MINOR_EXTENDED_REVISION_D          0x0000000D /* R---V */
#define NV_PMC_BOOT_2_MINOR_EXTENDED_REVISION_E          0x0000000E /* R---V */
#define NV_PMC_BOOT_2_MINOR_EXTENDED_REVISION_F          0x0000000F /* R---V */
#define NV_PMC_BOOT_2_FAB_ID                                    7:4 /* R-XVF */
#define NV_PMC_BOOT_2_FAB_ID_0                           0x00000000 /* R---V */
#define NV_PMC_BOOT_2_FAB_ID_1                           0x00000001 /* R---V */
#define NV_PMC_BOOT_2_FAB_ID_2                           0x00000002 /* R---V */
#define NV_PMC_BOOT_2_FAB_ID_3                           0x00000003 /* R---V */
#define NV_PMC_BOOT_42                                   0x00000A00 /* R--4R */
#define NV_PMC_BOOT_42_MINOR_EXTENDED_REVISION                 11:8 /* R-XVF */
#define NV_PMC_BOOT_42_MINOR_EXTENDED_REVISION_0         0x00000000 /* R---V */
#define NV_PMC_BOOT_42_MINOR_EXTENDED_REVISION_1         0x00000001 /* R---V */
#define NV_PMC_BOOT_42_MINOR_EXTENDED_REVISION_2         0x00000002 /* R---V */
#define NV_PMC_BOOT_42_MINOR_EXTENDED_REVISION_3         0x00000003 /* R---V */
#define NV_PMC_BOOT_42_MINOR_EXTENDED_REVISION_4         0x00000004 /* R---V */
#define NV_PMC_BOOT_42_MINOR_EXTENDED_REVISION_5         0x00000005 /* R---V */
#define NV_PMC_BOOT_42_MINOR_EXTENDED_REVISION_6         0x00000006 /* R---V */
#define NV_PMC_BOOT_42_MINOR_EXTENDED_REVISION_7         0x00000007 /* R---V */
#define NV_PMC_BOOT_42_MINOR_EXTENDED_REVISION_8         0x00000008 /* R---V */
#define NV_PMC_BOOT_42_MINOR_EXTENDED_REVISION_9         0x00000009 /* R---V */
#define NV_PMC_BOOT_42_MINOR_EXTENDED_REVISION_A         0x0000000A /* R---V */
#define NV_PMC_BOOT_42_MINOR_EXTENDED_REVISION_B         0x0000000B /* R---V */
#define NV_PMC_BOOT_42_MINOR_EXTENDED_REVISION_C         0x0000000C /* R---V */
#define NV_PMC_BOOT_42_MINOR_EXTENDED_REVISION_D         0x0000000D /* R---V */
#define NV_PMC_BOOT_42_MINOR_EXTENDED_REVISION_E         0x0000000E /* R---V */
#define NV_PMC_BOOT_42_MINOR_EXTENDED_REVISION_F         0x0000000F /* R---V */
#define NV_PMC_BOOT_42_MINOR_REVISION                         15:12 /* R-XVF */
#define NV_PMC_BOOT_42_MINOR_REVISION_1                  0x00000001 /* R---V */
#define NV_PMC_BOOT_42_MINOR_REVISION_2                  0x00000002 /* R---V */
#define NV_PMC_BOOT_42_MINOR_REVISION_3                  0x00000003 /* R---V */
#define NV_PMC_BOOT_42_MINOR_REVISION_4                  0x00000004 /* R---V */
#define NV_PMC_BOOT_42_MINOR_REVISION_5                  0x00000005 /* R---V */
#define NV_PMC_BOOT_42_MINOR_REVISION_6                  0x00000006 /* R---V */
#define NV_PMC_BOOT_42_MINOR_REVISION_7                  0x00000007 /* R---V */
#define NV_PMC_BOOT_42_MINOR_REVISION_8                  0x00000008 /* R---V */
#define NV_PMC_BOOT_42_MINOR_REVISION_9                  0x00000009 /* R---V */
#define NV_PMC_BOOT_42_MINOR_REVISION_10                 0x0000000A /* R---V */
#define NV_PMC_BOOT_42_MINOR_REVISION_11                 0x0000000B /* R---V */
#define NV_PMC_BOOT_42_MINOR_REVISION_12                 0x0000000C /* R---V */
#define NV_PMC_BOOT_42_MINOR_REVISION_13                 0x0000000D /* R---V */
#define NV_PMC_BOOT_42_MINOR_REVISION_14                 0x0000000E /* R---V */
#define NV_PMC_BOOT_42_MINOR_REVISION_15                 0x0000000F /* R---V */
#define NV_PMC_BOOT_42_MAJOR_REVISION                         19:16 /* R-XVF */
#define NV_PMC_BOOT_42_MAJOR_REVISION_A                  0x0000000A /* R---V */
#define NV_PMC_BOOT_42_MAJOR_REVISION_B                  0x0000000B /* R---V */
#define NV_PMC_BOOT_42_MAJOR_REVISION_C                  0x0000000C /* R---V */
#define NV_PMC_BOOT_42_MAJOR_REVISION_D                  0x0000000D /* R---V */
#define NV_PMC_BOOT_42_MAJOR_REVISION_E                  0x0000000E /* R---V */
#define NV_PMC_BOOT_42_MAJOR_REVISION_F                  0x0000000F /* R---V */
#define NV_PMC_BOOT_42_IMPLEMENTATION                         23:20 /*       */
#define NV_PMC_BOOT_42_IMPLEMENTATION_0                  0x00000000 /*       */
#define NV_PMC_BOOT_42_IMPLEMENTATION_1                  0x00000001 /*       */
#define NV_PMC_BOOT_42_IMPLEMENTATION_2                  0x00000002 /*       */
#define NV_PMC_BOOT_42_IMPLEMENTATION_3                  0x00000003 /*       */
#define NV_PMC_BOOT_42_IMPLEMENTATION_4                  0x00000004 /*       */
#define NV_PMC_BOOT_42_IMPLEMENTATION_5                  0x00000005 /*       */
#define NV_PMC_BOOT_42_IMPLEMENTATION_6                  0x00000006 /*       */
#define NV_PMC_BOOT_42_IMPLEMENTATION_7                  0x00000007 /*       */
#define NV_PMC_BOOT_42_IMPLEMENTATION_8                  0x00000008 /*       */
#define NV_PMC_BOOT_42_IMPLEMENTATION_9                  0x00000009 /*       */
#define NV_PMC_BOOT_42_IMPLEMENTATION_A                  0x0000000A /*       */
#define NV_PMC_BOOT_42_IMPLEMENTATION_B                  0x0000000B /*       */
#define NV_PMC_BOOT_42_IMPLEMENTATION_C                  0x0000000C /*       */
#define NV_PMC_BOOT_42_IMPLEMENTATION_D                  0x0000000D /*       */
#define NV_PMC_BOOT_42_IMPLEMENTATION_E                  0x0000000E /*       */
#define NV_PMC_BOOT_42_IMPLEMENTATION_F                  0x0000000F /*       */
#define NV_PMC_BOOT_42_ARCHITECTURE                           28:24 /*       */
#define NV_PMC_BOOT_42_ARCHITECTURE_GP100                0x00000013 /*       */
#define NV_PMC_BOOT_42_ARCHITECTURE_GV100                0x00000014 /*       */
#define NV_PMC_BOOT_42_ARCHITECTURE_GV110                0x00000015 /*       */
#define NV_PMC_BOOT_42_ARCHITECTURE_GA100                0x00000017 /*       */
#define NV_PMC_BOOT_42_CHIP_ID                                28:20 /* R-XVF */
#define NV_PMC_BOOT_42_CHIP_ID_GP000                     0x00000131 /* R---V */
#define NV_PMC_BOOT_42_CHIP_ID_GP100                     0x00000130 /* R---V */
#define NV_PMC_BOOT_42_CHIP_ID_GP102                     0x00000132 /* R---V */
#define NV_PMC_BOOT_42_CHIP_ID_GP104                     0x00000134 /* R---V */
#define NV_PMC_BOOT_42_CHIP_ID_GP104V                    0x00000139 /* R---V */
#define NV_PMC_BOOT_42_CHIP_ID_GP106                     0x00000136 /* R---V */
#define NV_PMC_BOOT_42_CHIP_ID_GP107                     0x00000137 /* R---V */
#define NV_PMC_BOOT_42_CHIP_ID_GP108                     0x00000138 /* R---V */
#define NV_PMC_BOOT_42_CHIP_ID_GP108V                    0x0000013A /* R---V */
#define NV_PMC_BOOT_42_CHIP_ID_GV100                     0x00000140 /* R---V */
#define NV_PMC_BOOT_42_CHIP_ID_GV10B                     0x0000014B /* R---V */
#define NV_PMC_BOOT_42_CHIP_ID_TU100                     0x00000160 /* R---V */
#define NV_PMC_BOOT_42_CHIP_ID_TU102                     0x00000162 /* R---V */
#define NV_PMC_BOOT_42_CHIP_ID_TU104                     0x00000164 /* R---V */
#define NV_PMC_BOOT_42_CHIP_ID_TU105                     0x00000165 /* R---V */
#define NV_PMC_BOOT_42_CHIP_ID_TU106                     0x00000166 /* R---V */
#define NV_PMC_BOOT_42_CHIP_ID_TU107                     0x00000167 /* R---V */
#define NV_PMC_BOOT_42_CHIP_ID_TU117                     0x00000167 /* R---V */
#define NV_PMC_BOOT_42_CHIP_ID_TU116                     0x00000168 /* R---V */
#define NV_PMC_BOOT_42_CHIP_ID_GA100                     0x00000170 /* R---V */
#define NV_PMC_ENABLE                                    0x00000200 /* RW-4R */
#define NV_PMC_ENABLE_DEVICE(i)                             (i):(i) /*       */
#define NV_PMC_ENABLE_DEVICE__SIZE_1                             32 /*       */
#define NV_PMC_ENABLE_DEVICE_DISABLE                     0x00000000 /*       */
#define NV_PMC_ENABLE_DEVICE_ENABLE                      0x00000001 /*       */
#define NV_PMC_ENABLE_ZPW             26:26 /* RWIVF */
#define NV_PMC_ENABLE_ZPW_DISABLED                       0x00000000 /* RWI-V */
#define NV_PMC_ENABLE_ZPW_ENABLED                        0x00000001 /* RW--V */
#define NV_PMC_ENABLE_BLG            27:27 /*       */
#define NV_PMC_ENABLE_BLG_DISABLED                      0x00000000 /*       */
#define NV_PMC_ENABLE_BLG_ENABLED                       0x00000001 /*       */
#define NV_PMC_ENABLE_PERFMON    28:28 /* RWIVF */
#define NV_PMC_ENABLE_PERFMON_DISABLED                  0x00000000 /* RWI-V */
#define NV_PMC_ENABLE_PERFMON_ENABLED                   0x00000001 /* RW--V */
#define NV_PMC_ENABLE_PDISP         30:30 /* RWIVF */
#define NV_PMC_ENABLE_PDISP_DISABLED                     0x00000000 /* RW--V */
#define NV_PMC_ENABLE_PDISP_ENABLED                      0x00000001 /* RWI-V */
#define NV_PMC_DEVICE_ENABLE(i)                                 (0x000000600+(i)*4) /* RW-4A */
#define NV_PMC_DEVICE_ENABLE__SIZE_1              1 /*       */
#define NV_PMC_DEVICE_ENABLE__PRIV_LEVEL_MASK  0x00000084 /*       */
#define NV_PMC_DEVICE_ENABLE_STATUS                                            31:0 /* RWIVF */
#define NV_PMC_DEVICE_ENABLE_STATUS_DISABLE_ALL                          0x00000000 /* RWI-V */
#define NV_PMC_DEVICE_ENABLE_STATUS_BIT(i)                                  (i):(i) /*       */
#define NV_PMC_DEVICE_ENABLE_STATUS_BIT__SIZE_1   32 /*       */
#define NV_PMC_DEVICE_ENABLE_STATUS_BIT_DISABLE                          0x00000000 /*       */
#define NV_PMC_DEVICE_ENABLE_STATUS_BIT_ENABLE                           0x00000001 /*       */
#define NV_PMC_PRI_PMC_CG1                             0x00000800 /* RW-4R */
#define NV_PMC_PRI_PMC_CG1_MONITOR_CG_EN                      0:0 /* RWIVF */
#define NV_PMC_PRI_PMC_CG1_MONITOR_CG_EN_ENABLED       0x00000001 /* RW--V */
#define NV_PMC_PRI_PMC_CG1_MONITOR_CG_EN_DISABLED      0x00000000 /* RWI-V */
#define NV_PMC_PRI_PMC_CG1_MONITOR_CG_EN__PROD         0x00000000 /* RW--V */
#define NV_PMC_PRI_PMC_CG1_SLCG                              1:1  /* RWIVF */
#define NV_PMC_PRI_PMC_CG1_SLCG_ENABLED                0x00000000 /* RW--V */
#define NV_PMC_PRI_PMC_CG1_SLCG_DISABLED               0x00000001 /* RWI-V */
#define NV_PMC_PRI_PMC_CG1_SLCG__PROD                  0x00000001 /* RW--V */
// 
// --------------------------------------------------------------------------------
