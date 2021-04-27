#include <iostream>

#include "regions.hpp"
#include "../assembler-hooker-injector/ahi.hpp"

static byte new_regions_arr[NEW_REGION_COUNT * REGION_ENTRY_SIZE];

__declspec(naked) void regions::redirect_regions_arr_1(){
    asm {
        sub     ebp, eax
        lea     ebx, regions_arr_0[ebp]
        mov     ecx, ebx
    }
}
__declspec(naked) void regions::redirect_regions_arr_2(){
    asm {
        lea     ebx, regions_arr_0[ebp]
        mov     ecx, ebx
    }
}
__declspec(naked) void regions::redirect_regions_arr_3(){
    asm {
        mov     edi, regions_arr_0[eax]
        test    edi, edi
    }
}
__declspec(naked) void regions::redirect_regions_arr_4(){
    asm {
        mov     word_12F05F4, ax
        mov     edx, offset regions_arr_0
    }
}
__declspec(naked) void regions::redirect_regions_arr_5(){
    asm {
        lea     ebx, regions_arr_0[ebp]
        movzx   ecx, ss:regions_arr_3[ebp]
        cmp     ecx, eax
    }
}
__declspec(naked) void regions::redirect_regions_arr_6(){
    asm {
        cmp     ebx, regions_arr_1[eax]
        jnz     short loc_8B20CF
    }
}
__declspec(naked) void regions::redirect_regions_arr_7(){
    asm {
        mov     byte ptr ss:regions_arr_2[ebp], al
        lea     ecx, [esp+0B0h+var_2C]
    }
}
__declspec(naked) void regions::redirect_regions_arr_8(){
    asm {
        mov     ss:regions_arr_2[ebp], cx
        mov     ss:regions_arr_3[ebp], cl
        mov     ss:regions_arr_4[ebp], ecx
        mov     ss:regions_arr_5[ebp], ecx
        mov     ss:regions_arr_6[ebp], 15h
        mov     [esp+24h+var_4], ecx
        xor     ecx, ecx
        cmp     ss:regions_arr_7[ebp], 0
        jbe     short loc_8B1FC6
    }
}
__declspec(naked) void regions::redirect_regions_arr_9(){
    asm {
        movzx   esi, byte ptr ss:regions_arr_2[ebp]
        movzx   edi, byte ptr [ebx]
    }
}
__declspec(naked) void regions::redirect_regions_arr_10(){
    asm {
        movzx   ecx, byte ptr ss:regions_arr_2[ebp]
        mov     esi, [esp+20h+arg_4]
    }
}
__declspec(naked) void regions::redirect_regions_arr_11(){
    asm {
        mov     byte ptr ss:(regions_arr_2+1)[ebp], al
        lea     ecx, [esp+0B0h+var_2C]
    }
}
__declspec(naked) void regions::redirect_regions_arr_12(){
    asm {
        mov     ss:regions_arr_3[ebp], al
        lea     ecx, [esp+0B0h+var_2C]
    }
}
__declspec(naked) void regions::redirect_regions_arr_13(){
    asm {
        movzx   edi, ss:regions_arr_3[ebp]
        cmp     edi, eax        ; copied only this line
    }
}
__declspec(naked) void regions::redirect_regions_arr_14(){
    asm {
        movzx   esi, byte ptr ss:(regions_arr_2+1)[ebp]
        movzx   edi, byte ptr [ebx+1]
    }
}
__declspec(naked) void regions::redirect_regions_arr_15(){
    asm {
        movzx   ecx, byte ptr ss:(regions_arr_2+1)[ebp]
        mov     esi, [esp+20h+arg_4]
    }
}
__declspec(naked) void regions::redirect_regions_arr_16(){
    asm {
        mov     ss:regions_arr_4[ebp], eax
        lea     ecx, [esp+0B0h+var_30]
    }
}
__declspec(naked) void regions::redirect_regions_arr_17(){
    asm {
        cmp     ss:regions_arr_4[ebp], 0
        jz      loc_8B1B60
    }
}
__declspec(naked) void regions::redirect_regions_arr_18(){
    asm {
        mov     eax, ss:regions_arr_4[ebp]
        test    eax, eax
    }
}
__declspec(naked) void regions::redirect_regions_arr_19(){
    asm {
        mov     eax, ss:regions_arr_5[ebp]
        test    eax, eax
    }
}
__declspec(naked) void regions::redirect_regions_arr_20(){
    asm {
        mov     edx, ss:regions_arr_8[ebp+eax*4]
        mov     [esi+eax*4+180h], edx
    }
}
__declspec(naked) void regions::redirect_regions_arr_21(){
    asm {
        mov     edx, ss:regions_arr_10[ebp+eax*4]
        mov     [esi+eax*4+188h], edx
    }
}
__declspec(naked) void regions::redirect_regions_arr_22(){
    asm {
        mov     eax, ss:regions_arr_6[ebp]
        mov     [esi+68h], eax
        mov     edx, ss:regions_arr_11[ebp]
        mov     [esi+1CCh], edx
    }
}
__declspec(naked) void regions::redirect_regions_arr_23(){
    asm {
        mov     eax, ss:regions_arr_13[ebp]
        lea     ecx, [ebx+50h]
        mov     [esi+0B0h], eax
        mov     edx, ss:regions_arr_14[ebp]
        mov     [esi+0B4h], edx
        mov     edi, ss:regions_arr_15[ebp]
        mov     [esi+0B8h], edi
        mov     eax, ss:regions_arr_16[ebp]
        mov     [esi+0BCh], eax
        mov     eax, ss:regions_arr_17[ebp]
        mov     [esi+0C0h], eax
        mov     eax, ss:regions_arr_18[ebp]
        mov     [esi+0C4h], eax
        mov     eax, ss:regions_arr_19[ebp]
        mov     [esi+0C8h], eax
        mov     eax, ss:regions_arr_20[ebp]
        mov     [esi+0CCh], eax
        mov     eax, ss:regions_arr_21[ebp]
        mov     [esi+0D0h], eax
        mov     ebp, ss:regions_arr_22[ebp]
        lea     eax, [esp+20h+var_20]
    }
}
__declspec(naked) void regions::redirect_regions_arr_24(){
    asm {
        mov     ss:regions_arr_8[ebp+ecx*4], ebx
        inc     ecx
        cmp     ecx, ss:regions_arr_7[ebp]
        jb      short loc_8B1FB2
    }
}
__declspec(naked) void regions::redirect_regions_arr_25(){
    asm {
        cmp     ss:regions_arr_9[ebp], 0
        jbe     short loc_8B1FF3
    }
}
__declspec(naked) void regions::redirect_regions_arr_26(){
    asm {
        mov     ss:regions_arr_10[ebp+ecx*4], ebx
        inc     ecx
        cmp     ecx, ss:regions_arr_9[ebp]
        jb      short loc_8B1FDF
    }
}
__declspec(naked) void regions::redirect_regions_arr_27(){
    asm {
        mov     ss:regions_arr_11[ebp], ecx
        mov     ss:regions_arr_12[ebp], ecx
        add     ebp, 78h
    }
}
__declspec(naked) void regions::redirect_regions_arr_28(){
    asm {
        mov     ss:regions_arr_5[ebp], eax
        lea     ecx, [esp+0B0h+var_34]
    }
}
__declspec(naked) void regions::redirect_regions_arr_29(){
    asm {
        cmp     ss:regions_arr_5[ebp], 0
        jz      loc_8B1AE1
    }
}
__declspec(naked) void regions::redirect_regions_arr_30(){
    asm {
        test    edx, edx
        mov     ss:regions_arr_6[ebp], 0
        jnz     short loc_8B15D9
    }
}
__declspec(naked) void regions::redirect_regions_arr_31(){
    asm {
        mov     esi, eax
        push    ss:regions_arr_6[ebp]
        call    sub_DCBB1C
    }
}
__declspec(naked) void regions::redirect_regions_arr_32(){
    asm {
        mov     eax, ss:regions_arr_6[ebp]
        jmp     short loc_8B15D9
    }
}
__declspec(naked) void regions::redirect_regions_arr_33(){
    asm {
        mov     ss:regions_arr_6[ebp], eax
    }
}
__declspec(naked) void regions::redirect_regions_arr_34(){
    asm {
        cmp     ss:regions_arr_7[ebp], 0
        jbe     short loc_8B16B3
    }
}
__declspec(naked) void regions::redirect_regions_arr_35(){
    asm {
        mov     ss:regions_arr_8[ebp+eax*4], 0
        inc     eax
        cmp     eax, ss:regions_arr_7[ebp]
        jb      short loc_8B169F
    }
}
__declspec(naked) void regions::redirect_regions_arr_36(){
    asm {
        or      ss:regions_arr_8[ebp+ebx*4], edx
    }
}
__declspec(naked) void regions::redirect_regions_arr_37(){
    asm {
        mov     ss:regions_arr_11[ebp], eax
        lea     ecx, [esp+0B0h+var_2C]
    }
}
__declspec(naked) void regions::redirect_regions_arr_38(){
    asm {
        mov     ss:regions_arr_12[ebp], eax
        lea     ecx, [esp+0B0h+var_2C]
    }
}
__declspec(naked) void regions::redirect_regions_arr_39(){
    asm {
        mov     ss:regions_arr_13[ebp], eax
        mov     edx, [esp+0B0h+var_7C]
        mov     ss:regions_arr_14[ebp], edx
        mov     ecx, [esp+0B0h+var_78]
        mov     ss:regions_arr_15[ebp], ecx
        mov     ebx, [esp+0B0h+var_74]
        mov     ss:regions_arr_16[ebp], ebx
        mov     esi, [esp+0B0h+var_70]
        mov     ss:regions_arr_17[ebp], esi
        mov     edi, [esp+0B0h+var_6C]
        mov     ss:regions_arr_18[ebp], edi
        mov     eax, [esp+0B0h+var_68]
        mov     ss:regions_arr_19[ebp], eax
        mov     eax, [esp+0B0h+var_64]
        mov     ss:regions_arr_20[ebp], eax
        mov     eax, [esp+0B0h+var_60]
        mov     ss:regions_arr_21[ebp], eax
        mov     eax, [esp+0B0h+var_5C]
        mov     ss:regions_arr_22[ebp], eax
        movzx   ebp, [esp+0B0h+var_14]
    }
}
__declspec(naked) void regions::redirect_regions_arr_40(){
    asm {
        or      ss:regions_arr_10[ebp+ebx*4], edx
        jmp     loc_8B1706
    }
}
__declspec(naked) void regions::redirect_regions_arr_41(){
    asm {
        mov     ss:regions_arr_6[ebp], 0
        movzx   eax, byte_103BA34
        test    eax, eax
    }
}
__declspec(naked) void regions::redirect_regions_arr_42(){
    asm {
        push    ss:regions_arr_6[ebp]
        call    sub_DCBB1C
    }
}
__declspec(naked) void regions::redirect_regions_arr_43(){
    asm {
        mov     ss:regions_arr_6[ebp], eax
        jmp     loc_8B15E2
    }
}
__declspec(naked) void regions::redirect_regions_arr_44(){
    asm {
        mov     ecx, regions_arr_6[ebx]
        mov     edx, 1
    }
}
__declspec(naked) void regions::redirect_regions_arr_45(){
    asm {
        mov     eax, regions_arr_12[eax]
        pop     ebx
    }
}

void regions::patch() {
    std::cout << "Extending region limit to " << NEW_REGION_COUNT << "..."
              << std::endl;
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
