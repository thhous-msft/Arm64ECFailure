if(POLICY CMP0091)
    cmake_policy(SET CMP0091 NEW)
    message(STATUS "Setting policy 0091")
else()
    message(WARNING "CMake version too old to support Policy 0091; CRT static linking won't work")
endif()

if (POLICY CMP0111)
    cmake_policy(SET CMP0111 NEW)
endif()

project(Arm64ECFailure)
cmake_minimum_required(VERSION 3.16)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

add_library(ectestdll SHARED ectestdll.c)
    SET_TARGET_PROPERTIES(ectestdll
        PROPERTIES LINK_FLAGS "/DEF:\"${CMAKE_CURRENT_SOURCE_DIR}/ectestdll.def\"")

add_executable(ectest ectest.c)
target_link_libraries(ectest ectestdll)

if (_MSVC_CXX_ARCHITECTURE_FAMILY STREQUAL "ARM64EC")
target_link_libraries(ectestdll softintrin)
target_link_libraries(ectest softintrin)
endif()
