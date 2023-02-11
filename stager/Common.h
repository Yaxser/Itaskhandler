#pragma once

//export
#define DllExport __declspec( dllexport )


#if __cplusplus
extern "C" {
#endif
	DWORD WINAPI init();
	long g_nComObjsInUse;
#if __cplusplus
}
#endif