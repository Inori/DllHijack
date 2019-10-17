#include <Windows.h>
#include <d3d9.h>

#include "detours.h"


typedef IDirect3D9* (WINAPI *PFUNC_Direct3DCreate9)(UINT SDKVersion);
PFUNC_Direct3DCreate9 OldDirect3DCreate9 = NULL;
IDirect3D9* WINAPI NewDirect3DCreate9(UINT SDKVersion)
{
	IDirect3D9* pD3D9 = NULL;
	static bool bOcStarted = false;
	do
	{
		pD3D9 = OldDirect3DCreate9(SDKVersion);
		if (!pD3D9)
		{
			break;
		}

	} while (false);

	return pD3D9;
}

void Init()
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());

	DetourAttach((void**)&OldDirect3DCreate9, NewDirect3DCreate9);

	DetourTransactionCommit();
}


BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ulCallReason,
	LPVOID lpReserved
)
{
	switch (ulCallReason)
	{
	case DLL_PROCESS_ATTACH:
		Init();
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}