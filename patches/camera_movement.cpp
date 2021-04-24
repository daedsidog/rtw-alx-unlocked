#include <iostream>

#include "camera_movement.hpp"
#include "../assembler-hooker-injector/ahi.hpp"

uintptr_t camera_movement_mode;
void __declspec(naked) camera_movement::fix_camera_jump() {

    // This doesn't actually "fix" the underlying problem, but instead works
    // around it by speeding up the camera in a way which emulates the
    // correct behaviour.
    asm {
#ifndef STEAM
        push eax
        mov eax, camera_movement_mode
        mov edx, dword ptr [eax]

        // 0x2 - Camera is slowly moving to target.
        // 0x1 - Camera is going fast.
        cmp edx, 0x2
        jne skip_fix

        mov dword ptr [eax], 0x1
        pop eax
#else
        push edx
        mov edx, camera_movement_mode
        mov eax, dword ptr [edx]
        cmp eax, 0x2
        jne skip_fix
        mov dword ptr [edx], 0x1
        pop edx
#endif
        skip_fix:
        ret
    }
}

void camera_movement::patch() {
    AHI::init();
    std::cout << "Fixing camera jump bug..." << std::endl;
    camera_movement_mode =
        AHI::get_abs_addr(IMAGE_BASE, camera_movement_mode_vaddr);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, camera_jump_patch_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, camera_jump_patch_end_vaddr),
                     (LPVOID)fix_camera_jump);
}
