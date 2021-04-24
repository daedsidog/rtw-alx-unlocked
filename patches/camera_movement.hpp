#pragma once

#define IMAGE_BASE 0x400000

#ifndef STEAM
    #define camera_movement_mode_vaddr    0x1528ed0
    #define camera_jump_patch_start_vaddr 0x917383
    #define camera_jump_patch_end_vaddr   0x917389
#else
    #define camera_movement_mode_vaddr    0x17af540
    #define camera_jump_patch_start_vaddr 0x964204
    #define camera_jump_patch_end_vaddr   0x96420e
#endif

class camera_movement {
    camera_movement() = delete;
    static void __declspec(naked) fix_camera_jump();

public:
    static void patch();
};
