#include <iostream>

#include "regions.hpp"
#include "../assembler-hooker-injector/ahi.hpp"

static byte regions_arr[NEW_REGION_COUNT * REGION_ENTRY_SIZE];

// This macro essentially maps the old memory references to the new ones.
#define def_regions_arr(X)                                                     \
    uintptr_t regions_arr_##X = (uintptr_t)&regions_arr +                       \
                               (regions_arr_##X##_vaddr - regions_arr_0_vaddr)
def_regions_arr(0);
def_regions_arr(1);
def_regions_arr(2);
def_regions_arr(3);
def_regions_arr(4);
def_regions_arr(5);
def_regions_arr(6);
def_regions_arr(7);
def_regions_arr(8);
def_regions_arr(9);
def_regions_arr(10);
def_regions_arr(11);
def_regions_arr(12);
def_regions_arr(13);
def_regions_arr(14);
def_regions_arr(15);
def_regions_arr(16);
def_regions_arr(17);
def_regions_arr(18);
def_regions_arr(19);
def_regions_arr(20);
def_regions_arr(21);
def_regions_arr(22);

__declspec(naked) void regions::redirect_regions_arr_1() {
    asm {
        // sub ebp, eax
        // lea ebx, regions_arr_0[ebp]
        sub ebp, eax
        mov ebx, regions_arr_0
        add ebx, ebp
        ret
    }
}
__declspec(naked) void regions::redirect_regions_arr_2() {
    asm {
        // lea ebx, regions_arr_0[ebp]
        mov ebx, regions_arr_0
        add ebx, ebp
        ret
    }
}
__declspec(naked) void regions::redirect_regions_arr_3() {
    asm {
        // mov edi, regions_arr_0[eax]
        mov edi, regions_arr_0
        add edi, eax
        mov edi, [edi]
        ret
    }
}
__declspec(naked) void regions::redirect_regions_arr_4() {
    asm {
        // mov edx, offset regions_arr_0
        mov edx, regions_arr_0
        ret
    }
}
__declspec(naked) void regions::redirect_regions_arr_5() {
    asm {
        // lea ebx, regions_arr_0[ebp]
        // movzx ecx, ss:regions_arr_3[ebp]
        mov ebx, regions_arr_0
        add ebx, ebp
        push eax
        mov eax, regions_arr_3
        add eax, ebp
        mov eax, [eax]
        movzx ecx, byte ptr [eax]
        pop eax
        ret
    }
}
__declspec(naked) void regions::redirect_regions_arr_6() {
    asm {
        // cmp ebx, regions_arr_1[eax]
        push edx
        mov edx, regions_arr_1
        add edx, eax
        mov edx, [edx]
        cmp ebx, edx
        pop edx
        ret
    }
}
__declspec(naked) void regions::redirect_regions_arr_7() {
    asm {
        // mov byte ptr ss:regions_arr_2[ebp], al
        push eax
        mov eax, regions_arr_2
        add eax, ebp
        mov byte ptr [eax], al
        pop eax
        ret
    }
}
__declspec(naked) void regions::redirect_regions_arr_8() {
    asm {
        // mov ss:regions_arr_2[ebp], cx
        // mov ss:regions_arr_3[ebp], cl
        // mov ss:regions_arr_4[ebp], ecx
        // mov ss:regions_arr_5[ebp], ecx
        // mov ss:regions_arr_6[ebp], 15h
        // mov [esp+24h+var_4], ecx
        // xor ecx, ecx
        // cmp ss:regions_arr_7[ebp], 0
        push eax

        mov eax, regions_arr_2
        add eax, ebp
        mov [eax], cx

        mov eax, regions_arr_3
        add eax, ebp
        mov [eax], cl

        mov eax, regions_arr_4
        add eax, ebp
        mov dword ptr [eax], ecx

        mov eax, regions_arr_5
        add eax, ebp
        mov dword ptr [eax], ecx

        mov eax, regions_arr_6
        add eax, ebp
        mov dword ptr [eax], 0x15

        mov [esp + 0x24], ecx

        xor ecx, ecx
        mov eax, regions_arr_7
        add eax, ebp
        mov eax, [eax]
        cmp eax, 0x0
        pop eax
        ret
    }
}
__declspec(naked) void regions::redirect_regions_arr_9() {
    asm {
        // movzx esi, byte ptr ss:regions_arr_2[ebp]
        push eax
        mov eax, regions_arr_2
        add eax, ebp
        movzx esi, byte ptr [eax]
        pop eax
        ret
    }
}
__declspec(naked) void regions::redirect_regions_arr_10() {
    asm {
        // movzx ecx, byte ptr ss:regions_arr_2[ebp]
        push eax
        mov eax, regions_arr_2
        add eax, ebp
        movzx ecx, byte ptr [eax]
        pop eax
        ret
    }
}
__declspec(naked) void regions::redirect_regions_arr_11() {
    asm {
        // mov byte ptr ss:(regions_arr_2+1)[ebp], al
        push eax
        mov eax, regions_arr_2
        add eax, 0x1
        add eax, ebp
        mov [eax], al
        pop eax
        ret
    }
}
__declspec(naked) void regions::redirect_regions_arr_12() {
    asm {
        // mov ss:regions_arr_3[ebp], al
        push eax
        mov eax, regions_arr_3
        add eax, ebp
        mov [eax], al
        pop eax
        ret
    }
}
__declspec(naked) void regions::redirect_regions_arr_13() {
    asm {
        // movzx edi, ss:regions_arr_3[ebp]
        push eax
        mov eax, regions_arr_3
        add eax, ebp
        movzx edi, byte ptr [eax]
        pop eax
        ret
    }
}
__declspec(naked) void regions::redirect_regions_arr_14() {
    asm {
        // movzx esi, byte ptr ptr ss:(regions_arr_2+1)[ebp]
        push eax
        mov eax, regions_arr_2
        add eax, 0x1
        add eax, ebp
        movzx esi, byte ptr [eax]
        pop eax
        ret
    }
}
__declspec(naked) void regions::redirect_regions_arr_15() {
    asm {
        // movzx ecx, byte ptr ss:(regions_arr_2+1)[ebp]
        push eax
        mov eax, regions_arr_2
        add eax, 0x1
        add eax, ebp
        movzx ecx, byte ptr [eax]
        pop eax
        ret
    }
}
__declspec(naked) void regions::redirect_regions_arr_16() {
    asm {
        // mov ss:regions_arr_4[ebp], eax
        push ebx
        mov ebx, regions_arr_4
        add ebx, ebp
        mov dword ptr [ebx], eax
        pop ebx
        ret
    }
}
__declspec(naked) void regions::redirect_regions_arr_17() {
    asm {
        // cmp ss:regions_arr_4[ebp], 0
        push eax
        mov eax, regions_arr_4
        add eax, ebp
        mov eax, [eax]
        cmp eax, 0x0
        pop eax
        ret
    }
}
__declspec(naked) void regions::redirect_regions_arr_18() {
    asm {
        // mov eax, ss:regions_arr_4[ebp]
        push edi
        mov edi, regions_arr_4
        add edi, ebp
        mov eax, dword ptr [edi]
        pop edi
        ret
    }
}
__declspec(naked) void regions::redirect_regions_arr_19() {
    asm {
        // mov eax, ss:regions_arr_5[ebp]
        push edi
        mov edi, regions_arr_5
        add edi, ebp
        mov eax, dword ptr [edi]
        pop edi
        ret
    }
}
__declspec(naked) void regions::redirect_regions_arr_20() {
    asm {
        // mov edx, ss:regions_arr_8[ebp+eax*4]
        push edi
        mov edi, regions_arr_8
        add edi, ebp
        add edi, eax
        add edi, eax
        add edi, eax
        add edi, eax
        mov edx, dword ptr [edi]
        pop edi
        ret
    }
}
__declspec(naked) void regions::redirect_regions_arr_21() {
    asm {
        // mov edx, ss:regions_arr_10[ebp+eax*4]
        push edi
        mov edi, regions_arr_10
        add edi, ebp
        add edi, eax
        add edi, eax
        add edi, eax
        add edi, eax
        mov edx, dword ptr [edi]
        pop edi
        ret
    }
}
__declspec(naked) void regions::redirect_regions_arr_22() {
    asm {
        // mov eax, ss:regions_arr_6[ebp]
        // mov     [esi+68h], eax
        // mov edx, ss:regions_arr_11[ebp]
        push edi
        mov edi, regions_arr_6
        add edi, ebp
        mov eax, dword ptr [edi]
        mov [esi + 0x68], eax
        mov edi, regions_arr_11
        add edi, ebp
        mov edx, dword ptr [edi]
        pop edi
        ret
    }
}
__declspec(naked) void regions::redirect_regions_arr_23() {
    asm {
        // mov eax, ss:regions_arr_13[ebp]
        // lea ecx, [ebx+50h]
        // mov [esi+0B0h], eax
        // mov edx, ss:regions_arr_14[ebp]
        // mov [esi+0B4h], edx
        // mov edi, ss:regions_arr_15[ebp]
        // mov [esi+0B8h], edi
        // mov eax, ss:regions_arr_16[ebp]
        // mov [esi+0BCh], eax
        // mov eax, ss:regions_arr_17[ebp]
        // mov [esi+0C0h], eax
        // mov eax, ss:regions_arr_18[ebp]
        // mov [esi+0C4h], eax
        // mov eax, ss:regions_arr_19[ebp]
        // mov [esi+0C8h], eax
        // mov eax, ss:regions_arr_20[ebp]
        // mov [esi+0CCh], eax
        // mov eax, ss:regions_arr_21[ebp]
        // mov [esi+0D0h], eax
        // mov ebp, ss:regions_arr_22[ebp]
        push edi
        mov edi, regions_arr_13
        add edi, ebp
        mov eax, dword ptr [edi]
        lea ecx, [ebx+0x50]
        mov [esi+0x0B0], eax
        mov edi, regions_arr_14
        add edi, ebp
        mov edx, dword ptr [edi]
        mov [esi+0x0B4], edx
        mov edi, regions_arr_15
        add edi, ebp
        mov edi, [edi]
        mov [esi+0x0B8], edi
        mov edi, regions_arr_16
        add edi, ebp
        mov eax, dword ptr [edi]
        mov [esi+0x0BC], eax
        mov edi, regions_arr_17
        add edi, ebp
        mov eax, dword ptr [edi]
        mov [esi+0x0C0], eax
        mov edi, regions_arr_18
        add edi, ebp
        mov eax, dword ptr [edi]
        mov [esi+0x0C4], eax
        mov edi, regions_arr_19
        add edi, ebp
        mov eax, dword ptr [edi]
        mov [esi+0x0C8], eax
        mov edi, regions_arr_20
        add edi, ebp
        mov eax, dword ptr [edi]
        mov [esi+0x0CC], eax
        mov edi, regions_arr_21
        add edi, ebp
        mov eax, dword ptr [edi]
        mov [esi+0x0D0], eax
        mov edi, regions_arr_22
        add edi, ebp
        mov ebp, dword ptr [edi]
        pop edi
        ret
    }
}
__declspec(naked) void regions::redirect_regions_arr_24() {
    asm {
        // mov ss:regions_arr_8[ebp+ecx*4], ebx
        // inc ecx
        // cmp ecx, ss:regions_arr_7[ebp]
        push edi
        mov edi, regions_arr_8
        add edi, ebp
        add edi, ecx
        add edi, ecx
        add edi, ecx
        add edi, ecx
        mov dword ptr [edi], ebx
        inc ecx
        mov edi, regions_arr_7
        add edi, ebp
        mov edi, [edi]
        cmp ecx, edi
        pop edi
        ret
    }
}
__declspec(naked) void regions::redirect_regions_arr_25() {
    asm {
        // cmp ss:regions_arr_9[ebp], 0
        push edi
        mov edi, regions_arr_9
        add edi, ebp
        mov dword ptr [edi], 0x0
        pop edi
        ret
    }
}
__declspec(naked) void regions::redirect_regions_arr_26() {
    asm {
        // mov ss:regions_arr_10[ebp+ecx*4], ebx
        // inc ecx
        // cmp ecx, ss:regions_arr_9[ebp]
        push edi
        mov edi, regions_arr_10
        add edi, ebp
        add edi, ecx
        add edi, ecx
        add edi, ecx
        add edi, ecx
        mov dword ptr [edi], ebx
        inc ecx
        mov edi, regions_arr_9
        add edi, ebp
        mov edi, [edi]
        cmp ecx, edi
        pop edi
        ret
    }
}
__declspec(naked) void regions::redirect_regions_arr_27() {
    asm {
        // mov ss:regions_arr_11[ebp], ecx
        // mov ss:regions_arr_12[ebp], ecx
        push edi
        mov edi, regions_arr_11
        add edi, ebp
        mov dword ptr [edi], ecx
        mov edi, regions_arr_12
        add edi, ebp
        mov dword ptr [edi], ecx
        pop edi
        ret
    }
}
__declspec(naked) void regions::redirect_regions_arr_28() {
    asm {
        // mov ss:regions_arr_5[ebp], eax
        push edi
        mov edi, regions_arr_5
        add edi, ebp
        mov dword ptr [edi], eax
        pop edi
        ret
    }
}
__declspec(naked) void regions::redirect_regions_arr_29() {
    asm {
        // cmp ss:regions_arr_5[ebp], 0
        push edi
        mov edi, regions_arr_5
        add edi, ebp
        mov edi, [edi]
        cmp edi, 0x0
        pop edi
        ret
    }
}
__declspec(naked) void regions::redirect_regions_arr_30() {
    asm {
        // test edx, edx
        // mov ss:regions_arr_6[ebp], 0
        test edx, edx
        push edi
        mov edi, regions_arr_6
        add edi, ebp
        mov dword ptr [edi], 0x0
        pop edi
        ret
    }
}
__declspec(naked) void regions::redirect_regions_arr_31() {
    asm {
        // mov esi, eax
        // push ss:regions_arr_6[ebp]
        mov esi, eax
        push [esp]
        push edi
        mov edi, regions_arr_6
        add edi, ebp
        mov edi, [edi]
        mov [esp + 0x8], edi
        pop edi
        ret
    }
}
__declspec(naked) void regions::redirect_regions_arr_32() {
    asm {
        // mov eax, ss:regions_arr_6[ebp]
        push edi
        mov edi, regions_arr_6
        add edi, ebp
        mov eax, dword ptr [edi]
        pop edi
        ret
    }
}
__declspec(naked) void regions::redirect_regions_arr_33() {
    asm {
        // mov ss:regions_arr_6[ebp], eax
        push edi
        mov edi, regions_arr_6
        add edi, ebp
        mov dword ptr [edi], eax
        pop edi
        ret
    }
}
__declspec(naked) void regions::redirect_regions_arr_34() {
    asm {
        // cmp ss:regions_arr_7[ebp], 0
        push edi
        mov edi, regions_arr_7
        add edi, ebp
        mov dword ptr [edi], 0x0
        pop edi
        ret
    }
}
__declspec(naked) void regions::redirect_regions_arr_35() {
    asm {
        // mov ss:regions_arr_8[ebp+eax*4], 0
        // inc eax
        // cmp eax, ss:regions_arr_7[ebp]
        push edi
        mov edi, regions_arr_8
        add edi, ebp
        add edi, eax
        add edi, eax
        add edi, eax
        add edi, eax
        mov dword ptr [edi], 0x0
        inc eax
        mov edi, regions_arr_7
        add edi, ebp
        mov edi, [edi]
        cmp eax, edi
        pop edi
        ret
    }
}
__declspec(naked) void regions::redirect_regions_arr_36() {
    asm {
        // or ss:regions_arr_8[ebp+ebx*4], edx
        push edi
        mov edi, regions_arr_8
        add edi, ebp
        add edi, ebx
        add edi, ebx
        add edi, ebx
        add edi, ebx
        or dword ptr [edi], edx
        pop edi
        ret
    }
}
__declspec(naked) void regions::redirect_regions_arr_37() {
    asm {
        // mov ss:regions_arr_11[ebp], eax
        push edi
        mov edi, regions_arr_11
        add edi, ebp
        mov dword ptr [edi], eax
        pop edi
        ret
    }
}
__declspec(naked) void regions::redirect_regions_arr_38() {
    asm {
        // mov ss:regions_arr_12[ebp], eax
        push edi
        mov edi, regions_arr_12
        add edi, ebp
        mov dword ptr [edi], eax
        pop edi
        ret
    }
}
__declspec(naked) void regions::redirect_regions_arr_39() {
    asm {
        // mov ss:regions_arr_13[ebp], eax
        // mov edx, [esp+34h]
        // mov ss:regions_arr_14[ebp], edx
        // mov ecx, [esp+38h]
        // mov ss:regions_arr_15[ebp], ecx
        // mov ebx, [esp+3Ch]
        // mov ss:regions_arr_16[ebp], ebx
        // mov esi, [esp+40h]
        // mov ss:regions_arr_17[ebp], esi
        // mov edi, [esp+44h]
        // mov ss:regions_arr_18[ebp], edi
        // mov eax, [esp+48h]
        // mov ss:regions_arr_19[ebp], eax
        // mov eax, [esp+4Ch]
        // mov ss:regions_arr_20[ebp], eax
        // mov eax, [esp+50h]
        // mov ss:regions_arr_21[ebp], eax
        // mov eax, [esp+54h]
        // mov ss:regions_arr_22[ebp], eax
        push edi
        mov edi, regions_arr_13
        add edi, ebp
        mov dword ptr [edi], eax
        mov edx, [esp+0x34]
        mov edi, regions_arr_14
        add edi, ebp
        mov dword ptr [edi], edx
        mov ecx, [esp+0x38]
        mov edi, regions_arr_15
        add edi, ebp
        mov dword ptr [edi], ecx
        mov ebx, [esp+0x3C]
        mov edi, regions_arr_16
        add edi, ebp
        mov dword ptr [edi], ebx
        mov esi, [esp+0x40]
        mov edi, regions_arr_17
        add edi, ebp
        mov dword ptr [edi], esi
        mov edi, [esp+0x44]
        mov edi, regions_arr_18
        add edi, ebp
        mov dword ptr [edi], edi
        mov eax, [esp+0x48]
        mov edi, regions_arr_19
        add edi, ebp
        mov dword ptr [edi], eax
        mov eax, [esp+0x4C]
        mov edi, regions_arr_20
        add edi, ebp
        mov dword ptr [edi], eax
        mov eax, [esp+0x50]
        mov edi, regions_arr_21
        add edi, ebp
        mov dword ptr [edi], eax
        mov eax, [esp+0x54]
        mov edi, regions_arr_22
        add edi, ebp
        mov dword ptr [edi], eax
        pop edi
        ret
    }
}
__declspec(naked) void regions::redirect_regions_arr_40() {
    asm {
        // or ss:regions_arr_10[ebp+ebx*4], edx
        push edi
        mov edi, regions_arr_10
        add edi, ebp
        add edi, ebx
        add edi, ebx
        add edi, ebx
        add edi, ebx
        or dword ptr [edi], edx
        pop edi
        ret
    }
}
uintptr_t byte_103ba34;
__declspec(naked) void regions::redirect_regions_arr_41() {
    asm {
        // mov ss:regions_arr_6[ebp], 0
        // movzx eax, byte_103BA34
        push edi
        mov edi, regions_arr_6
        add edi, ebp
        mov dword ptr [edi], 0x0
        mov edi, byte_103ba34
        movzx eax, byte ptr [edi]
        pop edi
        ret
    }
}
__declspec(naked) void regions::redirect_regions_arr_42() {
    asm {
        // push ss:regions_arr_6[ebp]
        push [esp]
        push edi
        mov edi, regions_arr_6
        add edi, ebp
        mov edi, [edi]
        mov [esp + 0x8], edi
        pop edi
        ret
    }
}
__declspec(naked) void regions::redirect_regions_arr_43() {
    asm {
        // mov ss:regions_arr_6[ebp], eax
        push edi
        mov edi, regions_arr_6
        add edi, ebp
        mov dword ptr [edi], eax
        pop edi
        ret
    }
}
__declspec(naked) void regions::redirect_regions_arr_44() {
    asm {
        // mov ecx, regions_arr_6[ebx]
        push edi
        mov edi, regions_arr_6
        add edi, ebx
        mov ecx, dword ptr [edi]
        pop edi
        ret
    }
}
__declspec(naked) void regions::redirect_regions_arr_45() {
    asm {
        // mov eax, regions_arr_12[eax]
        push edi
        mov edi, regions_arr_12
        add edi, eax
        mov eax, dword ptr [edi]
        pop edi
        ret
    }
}

void regions::patch() {
    std::cout << "Extending region limit to " << NEW_REGION_COUNT << "..."
              << std::endl;
    AHI::init();
    std::cout << "regions_arr location: " << (LPVOID)regions_arr << std::endl;

#define print_regions_arr(X) std::cout << "regions_arr_" << #X << " loaction: " << (LPVOID)regions_arr_##X << std::endl;
    print_regions_arr(1);
    print_regions_arr(2);
    print_regions_arr(3);
    print_regions_arr(4);
    print_regions_arr(5);
    print_regions_arr(6);
    print_regions_arr(7);
    print_regions_arr(8);
    print_regions_arr(9);
    print_regions_arr(10);
    print_regions_arr(11);
    print_regions_arr(12);
    print_regions_arr(13);
    print_regions_arr(14);
    print_regions_arr(15);
    print_regions_arr(16);
    print_regions_arr(17);
    print_regions_arr(18);
    print_regions_arr(19);
    print_regions_arr(20);
    print_regions_arr(21);
    print_regions_arr(22);

    byte_103ba34 = AHI::get_abs_addr(IMAGE_BASE, byte_103ba34_vaddr);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, rar_1_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, rar_1_end_vaddr),
                     (LPVOID)redirect_regions_arr_1);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, rar_2_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, rar_2_end_vaddr),
                     (LPVOID)redirect_regions_arr_2);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, rar_3_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, rar_3_end_vaddr),
                     (LPVOID)redirect_regions_arr_3);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, rar_4_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, rar_4_end_vaddr),
                     (LPVOID)redirect_regions_arr_4);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, rar_5_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, rar_5_end_vaddr),
                     (LPVOID)redirect_regions_arr_5);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, rar_6_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, rar_6_end_vaddr),
                     (LPVOID)redirect_regions_arr_6);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, rar_7_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, rar_7_end_vaddr),
                     (LPVOID)redirect_regions_arr_7);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, rar_8_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, rar_8_end_vaddr),
                     (LPVOID)redirect_regions_arr_8);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, rar_9_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, rar_9_end_vaddr),
                     (LPVOID)redirect_regions_arr_9);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, rar_10_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, rar_10_end_vaddr),
                     (LPVOID)redirect_regions_arr_10);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, rar_11_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, rar_11_end_vaddr),
                     (LPVOID)redirect_regions_arr_11);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, rar_12_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, rar_12_end_vaddr),
                     (LPVOID)redirect_regions_arr_12);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, rar_13_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, rar_13_end_vaddr),
                     (LPVOID)redirect_regions_arr_13);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, rar_14_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, rar_14_end_vaddr),
                     (LPVOID)redirect_regions_arr_14);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, rar_15_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, rar_15_end_vaddr),
                     (LPVOID)redirect_regions_arr_15);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, rar_16_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, rar_16_end_vaddr),
                     (LPVOID)redirect_regions_arr_16);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, rar_17_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, rar_17_end_vaddr),
                     (LPVOID)redirect_regions_arr_17);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, rar_18_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, rar_18_end_vaddr),
                     (LPVOID)redirect_regions_arr_18);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, rar_19_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, rar_19_end_vaddr),
                     (LPVOID)redirect_regions_arr_19);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, rar_20_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, rar_20_end_vaddr),
                     (LPVOID)redirect_regions_arr_20);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, rar_21_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, rar_21_end_vaddr),
                     (LPVOID)redirect_regions_arr_21);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, rar_22_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, rar_22_end_vaddr),
                     (LPVOID)redirect_regions_arr_22);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, rar_23_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, rar_23_end_vaddr),
                     (LPVOID)redirect_regions_arr_23);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, rar_24_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, rar_24_end_vaddr),
                     (LPVOID)redirect_regions_arr_24);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, rar_25_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, rar_25_end_vaddr),
                     (LPVOID)redirect_regions_arr_25);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, rar_26_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, rar_26_end_vaddr),
                     (LPVOID)redirect_regions_arr_26);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, rar_27_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, rar_27_end_vaddr),
                     (LPVOID)redirect_regions_arr_27);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, rar_28_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, rar_28_end_vaddr),
                     (LPVOID)redirect_regions_arr_28);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, rar_29_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, rar_29_end_vaddr),
                     (LPVOID)redirect_regions_arr_29);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, rar_30_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, rar_30_end_vaddr),
                     (LPVOID)redirect_regions_arr_30);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, rar_31_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, rar_31_end_vaddr),
                     (LPVOID)redirect_regions_arr_31);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, rar_32_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, rar_32_end_vaddr),
                     (LPVOID)redirect_regions_arr_32);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, rar_33_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, rar_33_end_vaddr),
                     (LPVOID)redirect_regions_arr_33);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, rar_34_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, rar_34_end_vaddr),
                     (LPVOID)redirect_regions_arr_34);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, rar_35_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, rar_35_end_vaddr),
                     (LPVOID)redirect_regions_arr_35);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, rar_36_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, rar_36_end_vaddr),
                     (LPVOID)redirect_regions_arr_36);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, rar_37_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, rar_37_end_vaddr),
                     (LPVOID)redirect_regions_arr_37);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, rar_38_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, rar_38_end_vaddr),
                     (LPVOID)redirect_regions_arr_38);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, rar_39_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, rar_39_end_vaddr),
                     (LPVOID)redirect_regions_arr_39);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, rar_40_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, rar_40_end_vaddr),
                     (LPVOID)redirect_regions_arr_40);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, rar_41_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, rar_41_end_vaddr),
                     (LPVOID)redirect_regions_arr_41);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, rar_42_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, rar_42_end_vaddr),
                     (LPVOID)redirect_regions_arr_42);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, rar_43_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, rar_43_end_vaddr),
                     (LPVOID)redirect_regions_arr_43);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, rar_44_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, rar_44_end_vaddr),
                     (LPVOID)redirect_regions_arr_44);
    AHI::inject_func(AHI::get_offset(IMAGE_BASE, rar_45_start_vaddr),
                     AHI::get_offset(IMAGE_BASE, rar_45_end_vaddr),
                     (LPVOID)redirect_regions_arr_45);
}
