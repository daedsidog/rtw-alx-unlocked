#pragma once

// GOD HAVE MERCY ON YE VIMLESS SOULS...

#define IMAGE_BASE        0x400000
#define NEW_REGION_COUNT  1024
#define REGION_ENTRY_SIZE 0x120

#define regions_arr_0_vaddr  0x012EA780
#define regions_arr_1_vaddr  0x012EA784
#define regions_arr_2_vaddr  0x012EA788
#define regions_arr_3_vaddr  0x012EA78A
#define regions_arr_4_vaddr  0x012EA78C
#define regions_arr_5_vaddr  0x012EA7A0
#define regions_arr_6_vaddr  0x012EA7AC
#define regions_arr_7_vaddr  0x012EA7B0
#define regions_arr_8_vaddr  0x012EA7B4
#define regions_arr_9_vaddr  0x012EA7B8
#define regions_arr_10_vaddr 0x012EA7BC
#define regions_arr_11_vaddr 0x012EA7C8
#define regions_arr_12_vaddr 0x012EA7CC
#define regions_arr_13_vaddr 0x012EA7D0
#define regions_arr_14_vaddr 0x012EA7D4
#define regions_arr_15_vaddr 0x012EA7D8
#define regions_arr_16_vaddr 0x012EA7DC
#define regions_arr_17_vaddr 0x012EA7E0
#define regions_arr_18_vaddr 0x012EA7E4
#define regions_arr_19_vaddr 0x012EA7E8
#define regions_arr_20_vaddr 0x012EA7EC
#define regions_arr_21_vaddr 0x012EA7F0
#define regions_arr_22_vaddr 0x012EA7F4

#define rar_1_start_vaddr  0x008B1438
#define rar_1_end_vaddr    0x008B1440
#define rar_2_start_vaddr  0x008B1F57
#define rar_2_end_vaddr    0x008B1F5D
#define rar_3_start_vaddr  0x008B207A
#define rar_3_end_vaddr    0x008B2080
#define rar_4_start_vaddr  0x008B2597
#define rar_4_end_vaddr    0x008B259D
#define rar_5_start_vaddr  0x008B26E1
#define rar_5_end_vaddr    0x008B26EE
#define rar_6_start_vaddr  0x008B2092
#define rar_6_end_vaddr    0x008B2098
#define rar_7_start_vaddr  0x008B1682
#define rar_7_end_vaddr    0x008B1688
#define rar_8_start_vaddr  0x008B1F80
#define rar_8_end_vaddr    0x008B1FB0
#define rar_9_start_vaddr  0x008B21B0
#define rar_9_end_vaddr    0x008B21B7
#define rar_10_start_vaddr 0x008B2705
#define rar_10_end_vaddr   0x008B270C
#define rar_11_start_vaddr 0x008B1664
#define rar_11_end_vaddr   0x008B166A
#define rar_12_start_vaddr 0x008B1646
#define rar_12_end_vaddr   0x008B164C
#define rar_13_start_vaddr 0x008B2196
#define rar_13_end_vaddr   0x008B219D
#define rar_14_start_vaddr 0x008B21A1
#define rar_14_end_vaddr   0x008B21A8
#define rar_15_start_vaddr 0x008B26F2
#define rar_15_end_vaddr   0x008B26F9
#define rar_16_start_vaddr 0x008B1463
#define rar_16_end_vaddr   0x008B1469
#define rar_17_start_vaddr 0x008B1475
#define rar_17_end_vaddr   0x008B147C
#define rar_18_start_vaddr 0x008B2785
#define rar_18_end_vaddr   0x008B278B
#define rar_19_start_vaddr 0x008B27AE
#define rar_19_end_vaddr   0x008B27B4
#define rar_20_start_vaddr 0x008B27E0
#define rar_20_end_vaddr   0x008B27E7
#define rar_21_start_vaddr 0x008B2802
#define rar_21_end_vaddr   0x008B2809
#define rar_22_start_vaddr 0x008B2819
#define rar_22_end_vaddr   0x008B2828
#define rar_23_start_vaddr 0x008B283B
#define rar_23_end_vaddr   0x008B28B0
#define rar_24_start_vaddr 0x008B1FB6
#define rar_24_end_vaddr   0x008B1FC4
#define rar_25_start_vaddr 0x008B1FD6
#define rar_25_end_vaddr   0x008B1FDD
#define rar_26_start_vaddr 0x008B1FE3
#define rar_26_end_vaddr   0x008B1FF1
#define rar_27_start_vaddr 0x008B1FF6
#define rar_27_end_vaddr   0x008B2002
#define rar_28_start_vaddr 0x008B1505
#define rar_28_end_vaddr   0x008B150B
#define rar_29_start_vaddr 0x008B1514
#define rar_29_end_vaddr   0x008B151B
#define rar_30_start_vaddr 0x008B1555
#define rar_30_end_vaddr   0x008B1561
#define rar_31_start_vaddr 0x008B1585
#define rar_31_end_vaddr   0x008B158D
#define rar_32_start_vaddr 0x008B15CB
#define rar_32_end_vaddr   0x008B15D1
#define rar_33_start_vaddr 0x008B15D3
#define rar_33_end_vaddr   0x008B15D9
#define rar_34_start_vaddr 0x008B1696
#define rar_34_end_vaddr   0x008B169D
#define rar_35_start_vaddr 0x008B169F
#define rar_35_end_vaddr   0x008B16B1
#define rar_36_start_vaddr 0x008B16FF
#define rar_36_end_vaddr   0x008B1706
#define rar_37_start_vaddr 0x008B1743
#define rar_37_end_vaddr   0x008B1749
#define rar_38_start_vaddr 0x008B1761
#define rar_38_end_vaddr   0x008B1767
#define rar_39_start_vaddr 0x008B179C
#define rar_39_end_vaddr   0x008B17FC
#define rar_40_start_vaddr 0x008B189D
#define rar_40_end_vaddr   0x008B18A4
#define rar_41_start_vaddr 0x008B1A49
#define rar_41_end_vaddr   0x008B1A5A
#define rar_42_start_vaddr 0x008B1A86
#define rar_42_end_vaddr   0x008B1A8C
#define rar_43_start_vaddr 0x008B1AD6
#define rar_43_end_vaddr   0x008B1ADC
#define rar_44_start_vaddr 0x008B2250
#define rar_44_end_vaddr   0x008B2256
#define rar_45_start_vaddr 0x008B2221
#define rar_45_end_vaddr   0x008B2227

class regions {
    regions() = delete;

    static __declspec(naked) void redirect_regions_arr_1();
    static __declspec(naked) void redirect_regions_arr_2();
    static __declspec(naked) void redirect_regions_arr_3();
    static __declspec(naked) void redirect_regions_arr_4();
    static __declspec(naked) void redirect_regions_arr_5();
    static __declspec(naked) void redirect_regions_arr_6();
    static __declspec(naked) void redirect_regions_arr_7();
    static __declspec(naked) void redirect_regions_arr_8();
    static __declspec(naked) void redirect_regions_arr_9();
    static __declspec(naked) void redirect_regions_arr_10();
    static __declspec(naked) void redirect_regions_arr_11();
    static __declspec(naked) void redirect_regions_arr_12();
    static __declspec(naked) void redirect_regions_arr_13();
    static __declspec(naked) void redirect_regions_arr_14();
    static __declspec(naked) void redirect_regions_arr_15();
    static __declspec(naked) void redirect_regions_arr_16();
    static __declspec(naked) void redirect_regions_arr_17();
    static __declspec(naked) void redirect_regions_arr_18();
    static __declspec(naked) void redirect_regions_arr_19();
    static __declspec(naked) void redirect_regions_arr_20();
    static __declspec(naked) void redirect_regions_arr_21();
    static __declspec(naked) void redirect_regions_arr_22();
    static __declspec(naked) void redirect_regions_arr_23();
    static __declspec(naked) void redirect_regions_arr_24();
    static __declspec(naked) void redirect_regions_arr_25();
    static __declspec(naked) void redirect_regions_arr_26();
    static __declspec(naked) void redirect_regions_arr_27();
    static __declspec(naked) void redirect_regions_arr_28();
    static __declspec(naked) void redirect_regions_arr_29();
    static __declspec(naked) void redirect_regions_arr_30();
    static __declspec(naked) void redirect_regions_arr_31();
    static __declspec(naked) void redirect_regions_arr_32();
    static __declspec(naked) void redirect_regions_arr_33();
    static __declspec(naked) void redirect_regions_arr_34();
    static __declspec(naked) void redirect_regions_arr_35();
    static __declspec(naked) void redirect_regions_arr_36();
    static __declspec(naked) void redirect_regions_arr_37();
    static __declspec(naked) void redirect_regions_arr_38();
    static __declspec(naked) void redirect_regions_arr_39();
    static __declspec(naked) void redirect_regions_arr_40();
    static __declspec(naked) void redirect_regions_arr_41();
    static __declspec(naked) void redirect_regions_arr_42();
    static __declspec(naked) void redirect_regions_arr_43();
    static __declspec(naked) void redirect_regions_arr_44();
    static __declspec(naked) void redirect_regions_arr_45();
    static __declspec(naked) void redirect_regions_arr_46();

public:
    static void patch();
};
