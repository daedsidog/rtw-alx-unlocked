#pragma once

#define IMAGE_BASE 0x400000

#ifndef STEAM

// Formations
#define abilities_ifchain_end_vaddr 0x8d479d
#define formations_fix_start_vaddr  0x8d4964
#define formations_fix_end_vaddr    0x8d4970

// Swimming
#define swimming_ability_enable_fix_start_vaddr 0x8d43c1
#define swimming_ability_enable_fix_end_vaddr   0x8d43c9

// Hording (Ability)
#define hording_ability_enable_fix_start_vaddr 0x8d43d8
#define hording_ability_enable_fix_end_vaddr   0x8d43e0

// Hording (Functionality)
#define hording_functionality_enable_fix_start_vaddr  0x8ac6b4
#define hording_functionality_enable_fix_end_vaddr    0x8ac794
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

// Formations
#define abilities_ifchain_end_vaddr             0x919fd7
#define formations_fix_start_vaddr              0x91a30f
#define formations_fix_end_vaddr                0x91a32c

// Swimming
#define swimming_ability_enable_fix_start_vaddr 0x919a31
#define swimming_ability_enable_fix_end_vaddr   0x919a38
#define swimming_ifchain_end_vaddr              0x919a3d

// Hording (Ability)
#define hording_ifchain_end_vaddr               0x919a56
#define hording_ability_enable_fix_start_vaddr  0x919a4a
#define hording_ability_enable_fix_end_vaddr    0x919a51

// Hording (Functionality)
#define hording_functionality_enable_fix_start_vaddr                           \
    0x8f9d3d // Arbitrary location at the start of the descr_sm_factions.txt
             // parsing location. hording_enabled_flag will be set to true
             // there. It is not clear whether enabling this flag is enough to
             // enable hording functionality on the Steam version.
#define hording_functionality_enable_fix_end_vaddr 0x8f9d43
#define hording_enabled_flag_vaddr                 0x12c67f8
#endif

class bi_features {
    bi_features() = delete;

    static void __declspec(naked) enable_bi_formations();
    static void __declspec(naked) enable_swimming_ability();
    static void __declspec(naked) enable_hording_ability();
    static void __declspec(naked) enable_hording_functionality();

  public:
    static void patch();
};
