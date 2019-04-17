project(AES256)

cmake_minimum_required(VERSION 2.6)

enable_testing()

set(compiler_common_flags "-ggdb -Wall -Wsign-compare -Wformat-security -Wpointer-arith")
set(compiler_common_flags "${compiler_common_flags} -fPIC -fdiagnostics-show-option")
set(compiler_common_flags "${compiler_common_flags} -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -D_REENTRANT")

set(CMAKE_C_FLAGS "${compiler_common_flags} -Wmissing-prototypes ${CMAKE_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${compiler_common_flags} -Wnon-virtual-dtor -Woverloaded-virtual ${CMAKE_CXX_FLAGS}")

IF (NOT LIB_SUFFIX)
    IF (CMAKE_SIZEOF_VOID_P EQUAL 4)
        SET(LIB_SUFFIX "")
    ELSE (CMAKE_SIZEOF_VOID_P EQUAL 4)
        SET(LIB_SUFFIX 64)
    ENDIF (CMAKE_SIZEOF_VOID_P EQUAL 4)
ENDIF (NOT LIB_SUFFIX)

include_directories(src)

add_subdirectory(src)

add_subdirectory(utils)

add_subdirectory(tests)
