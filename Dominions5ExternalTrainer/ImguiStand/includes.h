#pragma once
#include <d3d11.h>
#include <d3d9.h>
#include <Windows.h>
#include <iostream>
#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_dx11.h"
#include "ImGui/imgui_impl_win32.h"
#include <libmem.hpp>
#include <libmem.h>

namespace Dom5 {
	void Player3_GetWaterPerl() 
	{
		lm_process_t proc;
		lm_module_t module_t;
		lm_byte_t byt;
		lm_size_t size_x;
		if (LM_FindProcess("Dominions5.exe", &proc)) 
		{
			LM_FindModule("Dominions5.exe", &module_t);
			uintptr_t inf = 100000;
			uint32_t player3addr_watergem = module_t.base + 0x26A0532;
			size_x = LM_ReadMemory(player3addr_watergem, &byt, module_t.size);
			MessageBoxA(0, (LPCSTR)size_x, 0, 0);
		}
	}
}