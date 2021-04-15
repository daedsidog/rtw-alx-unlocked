#pragma once

#define IMAGE_BASE 0x400000

#ifndef STEAM
#define abilities_ifchain_end_vaddr                  0x8d479d
#define formations_fix_start_vaddr                   0x8d4964
#define formations_fix_end_vaddr                     0x8d4970
#define swimming_ability_enable_fix_start_vaddr      0x8d43c1
#define swimming_ability_enable_fix_end_vaddr        0x8d43c9
#define hording_ability_enable_fix_start_vaddr       0x8d43d8
#define hording_ability_enable_fix_end_vaddr         0x8d43e0
#define hording_enable_flag_vaddr                    0x103ba34
#define hording_functionality_enable_fix_start_vaddr 0x8ac6b4
#define hording_functionality_enable_fix_end_vaddr   0x8ac794
// #define hording_functionality_enable_fix_start_vaddr 0x8ac6b4
// #define hording_functionality_enable_fix_end_vaddr   0x8ac6b9
#define some_parsing_func_vaddr                       0xdbe9b4
#define strparse_func_vaddr                           0xdbedf0
#define horde_min_units_vaddr                         0x29e56a0
#define horde_max_units_vaddr                         0x29e56b0
#define horde_max_units_reduction_every_horde_vaddr   0x29e56c0
#define horde_unit_per_settlement_population_vaddr    0x29e56e8
#define horde_min_named_characters_vaddr              0x29e5710
#define horde_max_percent_army_stack_vaddr            0x29e572c
#define horde_disband_percent_on_settlement_cap_vaddr 0x29e574c
#define horde_unit_vaddr                              0x29e5778
#else
#define abilities_ifchain_end_vaddr             0x919fd7
#define swimming_ifchain_end_vaddr              0x919a3d
#define hording_ifchain_end_vaddr               0x919a56
#define formations_fix_start_vaddr              0x91a30f
#define formations_fix_end_vaddr                0x91a32c
#define swimming_ability_enable_fix_start_vaddr 0x919a31
#define swimming_ability_enable_fix_end_vaddr   0x919a38
#define hording_ability_enable_fix_start_vaddr  0x919a4d
#define hording_ability_enable_fix_end_vaddr    0x919a51
#endif

class special_abilities {
    special_abilities() = delete;

    static void __declspec(naked) enable_bi_formations();
    static void __declspec(naked) enable_swimming_ability();
    static void __declspec(naked) enable_hording_ability();
    static void __declspec(naked) enable_hording_functionality();

  public:
    static void patch();
};
