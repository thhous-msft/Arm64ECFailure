#include "Windows.h"

_IRQL_requires_max_(PASSIVE_LEVEL)
HRESULT
__cdecl
ECTest1Argument(
    void* Arg1
    );

_IRQL_requires_max_(PASSIVE_LEVEL)
HRESULT
__cdecl
ECTest2Arguments(
    void* Arg1,
    void* Arg2
    );

_IRQL_requires_max_(PASSIVE_LEVEL)
HRESULT
__cdecl
ECTest3Arguments(
    void* Arg1,
    void* Arg2,
    void* Arg3
    );
