#pragma once

#define IMAGE_BASE 0x400000

#ifdef STEAM
#define naval_invasions_patch_start_vaddr 0x8faaf9
#define naval_invasions_patch_end_vaddr   0x8faafe
#else
#define naval_invasions_patch_start_vaddr 0x8ac81e
#define naval_invasions_patch_end_vaddr   0x8ac825
#endif

class naval_invasions {
    naval_invasions() = delete;
    static void __declspec(naked) fix_naval_invasions();

  public:
    static void patch();
};
