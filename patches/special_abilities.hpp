#pragma once

#define IMAGE_BASE 0x400000

#ifndef STEAM
#define abilities_ifchain_end_vaddr             0x8d479d
#define formations_fix_start_vaddr              0x8d4964
#define formations_fix_end_vaddr                0x8d4970
#define swimming_ability_enable_fix_start_vaddr 0x8d43c1
#define swimming_ability_enable_fix_end_vaddr   0x8d43c9
#define hording_ability_enable_fix_start_vaddr  0x8d43d8
#define hording_ability_enable_fix_end_vaddr    0x8d43e0
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

  public:
    static void patch();
};
