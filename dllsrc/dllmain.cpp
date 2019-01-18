// dllmain.cpp : Defines the entry point for the DLL application.
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
extern "C" {

#if _MSC_VER >= 1900
#pragma comment(lib, "legacy_stdio_definitions.lib")

	_ACRTIMP_ALT FILE* __cdecl __acrt_iob_func(unsigned _Ix);

	FILE* __cdecl __iob_func(unsigned i) {
		return __acrt_iob_func(i);
	}

	FILE * __cdecl _imp___iob(unsigned i) {
		return __acrt_iob_func(i);
	}

	int __cdecl _imp____mb_cur_max()
	{
		return MB_CUR_MAX;
	}

	int _get_output_format(void) {
		return 0;
	}
#endif
}