#include "functions.h"
#include <stdio.h>

_IRQL_requires_max_(PASSIVE_LEVEL)
HRESULT
__cdecl
ECTest1Argument(
    void* Arg1
    )
{
    printf("Called 1 arg function\n");
    UNREFERENCED_PARAMETER(Arg1);
    return S_OK;
}

_IRQL_requires_max_(PASSIVE_LEVEL)
HRESULT
__cdecl
ECTest2Arguments(
    void* Arg1,
    void* Arg2
    )
{
    printf("Called 2 arg function\n");
    UNREFERENCED_PARAMETER(Arg1);
    UNREFERENCED_PARAMETER(Arg2);
    return S_OK;
}

_IRQL_requires_max_(PASSIVE_LEVEL)
HRESULT
__cdecl
ECTest3Arguments(
    void* Arg1,
    void* Arg2,
    void* Arg3
    )
{
    printf("Called 3 arg function\n");
    UNREFERENCED_PARAMETER(Arg1);
    UNREFERENCED_PARAMETER(Arg2);
    UNREFERENCED_PARAMETER(Arg3);
    return S_OK;
}

BOOL
__stdcall
DllMain(
    _In_ HINSTANCE Instance,
    _In_ DWORD Reason,
    _In_ LPVOID Reserved
    )
{
    UNREFERENCED_PARAMETER(Reserved);

    switch (Reason) {

    case DLL_PROCESS_ATTACH:
#ifndef _MT // Don't disable thread library calls with static CRT!
        DisableThreadLibraryCalls(Instance);
#else
        UNREFERENCED_PARAMETER(Instance);
#endif
        break;

    case DLL_PROCESS_DETACH:
        break;
    }

    return TRUE;
}
