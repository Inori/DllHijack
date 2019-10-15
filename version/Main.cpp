#include <Windows.h>
#include <process.h>
#include <cstring>
#include <filesystem>


typedef DWORD(WINAPI*PFUNC_VerFindFileA)(DWORD, LPCSTR, LPCSTR, LPCSTR, LPSTR, PUINT, LPSTR, PUINT);
PFUNC_VerFindFileA OldVerFindFileA;
DWORD WINAPI VerFindFileA(DWORD uFlags, LPCSTR szFileName, LPCSTR szWinDir, LPCSTR szAppDir, LPSTR szCurDir, PUINT puCurDirLen, LPSTR szDestDir, PUINT puDestDirLen)
{
	return (OldVerFindFileA)(uFlags, szFileName, szWinDir, szAppDir, szCurDir, puCurDirLen, szDestDir, puDestDirLen);
}

typedef DWORD(WINAPI*PFUNC_VerFindFileW)(DWORD, LPCWSTR, LPCWSTR, LPCWSTR, LPWSTR, PUINT, LPWSTR, PUINT);
PFUNC_VerFindFileW OldVerFindFileW;
DWORD WINAPI VerFindFileW(DWORD uFlags, LPCWSTR szFileName, LPCWSTR szWinDir, LPCWSTR szAppDir, LPWSTR szCurDir, PUINT puCurDirLen, LPWSTR szDestDir, PUINT puDestDirLen)
{
	return (OldVerFindFileW)(uFlags, szFileName, szWinDir, szAppDir, szCurDir, puCurDirLen, szDestDir, puDestDirLen);
}

typedef DWORD(WINAPI*PFUNC_VerInstallFileA)(DWORD, LPCSTR, LPCSTR, LPCSTR, LPCSTR, LPCSTR, LPSTR, PUINT);
PFUNC_VerInstallFileA OldVerInstallFileA;
DWORD WINAPI VerInstallFileA(DWORD uFlags, LPCSTR szSrcFileName, LPCSTR szDestFileName, LPCSTR szSrcDir, LPCSTR szDestDir, LPCSTR szCurDir, LPSTR szTmpFile, PUINT puTmpFileLen)
{
	return (OldVerInstallFileA)(uFlags, szSrcFileName, szDestFileName, szSrcDir, szDestDir, szCurDir, szTmpFile, puTmpFileLen);
}

typedef DWORD(WINAPI*PFUNC_VerInstallFileW)(DWORD, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPWSTR, PUINT);
PFUNC_VerInstallFileW OldVerInstallFileW;
DWORD WINAPI VerInstallFileW(DWORD uFlags, LPCWSTR szSrcFileName, LPCWSTR szDestFileName, LPCWSTR szSrcDir, LPCWSTR szDestDir, LPCWSTR szCurDir, LPWSTR szTmpFile, PUINT puTmpFileLen)
{
	return (OldVerInstallFileW)(uFlags, szSrcFileName, szDestFileName, szSrcDir, szDestDir, szCurDir, szTmpFile, puTmpFileLen);
}

typedef DWORD(WINAPI*PFUNC_GetFileVersionInfoSizeA)(LPCSTR, LPDWORD);
PFUNC_GetFileVersionInfoSizeA OldGetFileVersionInfoSizeA;
DWORD WINAPI GetFileVersionInfoSizeA(LPCSTR lptstrFilename, LPDWORD lpdwHandle)
{
	return (OldGetFileVersionInfoSizeA)(lptstrFilename, lpdwHandle);
}

typedef DWORD(WINAPI*PFUNC_GetFileVersionInfoSizeW)(LPCWSTR, LPDWORD);
PFUNC_GetFileVersionInfoSizeW OldGetFileVersionInfoSizeW;
DWORD WINAPI GetFileVersionInfoSizeW(LPCWSTR lptstrFilename, LPDWORD lpdwHandle)
{
	return (OldGetFileVersionInfoSizeW)(lptstrFilename, lpdwHandle);
}

typedef DWORD(WINAPI*PFUNC_GetFileVersionInfoA)(LPCSTR, DWORD, DWORD, LPVOID);
PFUNC_GetFileVersionInfoA OldGetFileVersionInfoA;
BOOL WINAPI GetFileVersionInfoA(LPCSTR lptstrFilename, DWORD dwHandle, DWORD dwLen, LPVOID lpData)
{
	return (OldGetFileVersionInfoA)(lptstrFilename, dwHandle, dwLen, lpData);
}

typedef DWORD(WINAPI*PFUNC_GetFileVersionInfoW)(LPCWSTR, DWORD, DWORD, LPVOID);
PFUNC_GetFileVersionInfoW OldGetFileVersionInfoW;
BOOL WINAPI GetFileVersionInfoW(LPCWSTR lptstrFilename, DWORD dwHandle, DWORD dwLen, LPVOID lpData)
{
	return (OldGetFileVersionInfoW)(lptstrFilename, dwHandle, dwLen, lpData);
}

typedef DWORD(WINAPI*PFUNC_GetFileVersionInfoSizeExA)(DWORD, LPCSTR, LPDWORD);
PFUNC_GetFileVersionInfoSizeExA OldGetFileVersionInfoSizeExA;
DWORD WINAPI GetFileVersionInfoSizeExA(DWORD dwFlags, LPCSTR lpwstrFilename, LPDWORD lpdwHandle)
{
	return (OldGetFileVersionInfoSizeExA)(dwFlags, lpwstrFilename, lpdwHandle);
}

typedef DWORD(WINAPI*PFUNC_GetFileVersionInfoSizeExW)(DWORD, LPCWSTR, LPDWORD);
PFUNC_GetFileVersionInfoSizeExW OldGetFileVersionInfoSizeExW;
DWORD WINAPI GetFileVersionInfoSizeExW(DWORD dwFlags, LPCWSTR lpwstrFilename, LPDWORD lpdwHandle)
{
	return (OldGetFileVersionInfoSizeExW)(dwFlags, lpwstrFilename, lpdwHandle);
}

typedef DWORD(WINAPI*PFUNC_GetFileVersionInfoExA)(DWORD, LPCSTR, DWORD, DWORD, LPVOID);
PFUNC_GetFileVersionInfoExA OldGetFileVersionInfoExA;
BOOL WINAPI GetFileVersionInfoExA(DWORD dwFlags, LPCSTR lpwstrFilename, DWORD dwHandle, DWORD dwLen, LPVOID lpData)
{
	return (OldGetFileVersionInfoExA)(dwFlags, lpwstrFilename, dwHandle, dwLen, lpData);
}

typedef DWORD(WINAPI*PFUNC_GetFileVersionInfoExW)(DWORD, LPCWSTR, DWORD, DWORD, LPVOID);
PFUNC_GetFileVersionInfoExW OldGetFileVersionInfoExW;
BOOL WINAPI GetFileVersionInfoExW(DWORD dwFlags, LPCWSTR lpwstrFilename, DWORD dwHandle, DWORD dwLen, LPVOID lpData)
{
	return (OldGetFileVersionInfoExW)(dwFlags, lpwstrFilename, dwHandle, dwLen, lpData);
}

typedef DWORD(WINAPI*PFUNC_VerLanguageNameA)(DWORD, LPSTR, DWORD);
PFUNC_VerLanguageNameA OldVerLanguageNameA;
DWORD WINAPI VerLanguageNameA(DWORD wLang, LPSTR szLang, DWORD cchLang)
{
	return (OldVerLanguageNameA)(wLang, szLang, cchLang);
}

typedef DWORD(WINAPI*PFUNC_VerLanguageNameW)(DWORD, LPWSTR, DWORD);
PFUNC_VerLanguageNameW OldVerLanguageNameW;
DWORD WINAPI VerLanguageNameW(DWORD wLang, LPWSTR szLang, DWORD cchLang)
{
	return (OldVerLanguageNameW)(wLang, szLang, cchLang);
}

typedef DWORD(WINAPI*PFUNC_VerQueryValueA)(LPCVOID, LPCSTR, LPVOID*, PUINT);
PFUNC_VerQueryValueA OldVerQueryValueA;
BOOL WINAPI VerQueryValueA(LPCVOID pBlock, LPCSTR lpSubBlock, LPVOID * lplpBuffer, PUINT puLen)
{
	return (OldVerQueryValueA)(pBlock, lpSubBlock, lplpBuffer, puLen);
}

typedef DWORD(WINAPI*PFUNC_VerQueryValueW)(LPCVOID, LPCWSTR, LPVOID*, PUINT);
PFUNC_VerQueryValueW OldVerQueryValueW;
BOOL WINAPI VerQueryValueW(LPCVOID pBlock, LPCWSTR lpSubBlock, LPVOID * lplpBuffer, PUINT puLen)
{
	return (OldVerQueryValueW)(pBlock, lpSubBlock, lplpBuffer, puLen);
}

typedef void(WINAPI*PFUNC_GetFileVersionInfoByHandle)();
PFUNC_GetFileVersionInfoByHandle OldGetFileVersionInfoByHandle;
void WINAPI GetFileVersionInfoByHandle()
{
	(OldGetFileVersionInfoByHandle)();
}


void LoadPatchDlls()
{
	do
	{
		HMODULE hModule = GetModuleHandleA(NULL);
		if (!hModule)
		{
			break;
		}

		CHAR szPath[MAX_PATH] = { 0 };
		DWORD dwRet = GetModuleFileNameA(hModule, szPath, MAX_PATH);
		if (!dwRet)
		{
			break;
		}

		std::string exePath(szPath);
		std::string rootDir = exePath.substr(0, exePath.find_last_of('\\'));
		std::filesystem::path rootPath(rootDir);
		auto patchPath = rootPath / "patch";

		if (!std::filesystem::exists(patchPath))
		{
			break;
		}

		for (const auto & entry : std::filesystem::directory_iterator(patchPath))
		{
			LoadLibraryW(entry.path().c_str());
		}

	} while (false);
}



static unsigned int __stdcall InitSymbols(void*)
{
	do
	{
		CHAR szDllPath[MAX_PATH] = { 0 };
		UINT nRet = GetSystemDirectoryA(szDllPath, MAX_PATH);
		if (!nRet)
		{
			break;
		}

		strcat_s(szDllPath, "\\version.dll");
		HMODULE hVerDll = LoadLibraryA(szDllPath);
		if (!hVerDll)
		{
			break;
		}

		OldVerFindFileA = (PFUNC_VerFindFileA)GetProcAddress(hVerDll, "VerFindFileA");
		OldVerFindFileW = (PFUNC_VerFindFileW)GetProcAddress(hVerDll, "VerFindFileW");
		OldVerInstallFileA = (PFUNC_VerInstallFileA)GetProcAddress(hVerDll, "VerInstallFileA");
		OldVerInstallFileW = (PFUNC_VerInstallFileW)GetProcAddress(hVerDll, "VerInstallFileW");
		OldGetFileVersionInfoA = (PFUNC_GetFileVersionInfoA)GetProcAddress(hVerDll, "GetFileVersionInfoA");
		OldGetFileVersionInfoW = (PFUNC_GetFileVersionInfoW)GetProcAddress(hVerDll, "GetFileVersionInfoW");
		OldGetFileVersionInfoSizeA = (PFUNC_GetFileVersionInfoSizeA)GetProcAddress(hVerDll, "GetFileVersionInfoSizeA");
		OldGetFileVersionInfoSizeW = (PFUNC_GetFileVersionInfoSizeW)GetProcAddress(hVerDll, "GetFileVersionInfoSizeW");
		OldGetFileVersionInfoExA = (PFUNC_GetFileVersionInfoExA)GetProcAddress(hVerDll, "GetFileVersionInfoExA");
		OldGetFileVersionInfoExW = (PFUNC_GetFileVersionInfoExW)GetProcAddress(hVerDll, "GetFileVersionInfoExW");
		OldGetFileVersionInfoSizeExA = (PFUNC_GetFileVersionInfoSizeExA)GetProcAddress(hVerDll, "GetFileVersionInfoSizeExA");
		OldGetFileVersionInfoSizeExW = (PFUNC_GetFileVersionInfoSizeExW)GetProcAddress(hVerDll, "GetFileVersionInfoSizeExW");
		OldVerLanguageNameA = (PFUNC_VerLanguageNameA)GetProcAddress(hVerDll, "VerLanguageNameA");
		OldVerLanguageNameW = (PFUNC_VerLanguageNameW)GetProcAddress(hVerDll, "VerLanguageNameW");
		OldVerQueryValueA = (PFUNC_VerQueryValueA)GetProcAddress(hVerDll, "VerQueryValueA");
		OldVerQueryValueW = (PFUNC_VerQueryValueW)GetProcAddress(hVerDll, "VerQueryValueW");
		OldGetFileVersionInfoByHandle = (PFUNC_GetFileVersionInfoByHandle)GetProcAddress(hVerDll, "GetFileVersionInfoByHandle");

		LoadPatchDlls();

	} while (false);
	return 0;
}

void Init()
{
	HANDLE hThread = NULL;
	unsigned int uiThreadId = 0 ;
	hThread = (HANDLE)_beginthreadex(NULL,
		0,
		InitSymbols,
		NULL,
		0,
		&uiThreadId);
	CloseHandle(hThread);
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ulReason,
	LPVOID lpReserved
)
{
	switch (ulReason)
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