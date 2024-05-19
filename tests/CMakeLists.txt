add_executable(test_aes256 test_aes256.cpp)
add_dependencies(test_aes256 aes256)
target_link_libraries(test_aes256 aes256)

IF (AES256_SHARED_LIB)
    IF (MSVC)
        IF (NOT CMAKE_BUILD_TYPE)
            SET(LIB_BUILT_PATH ${CMAKE_BINARY_DIR}/src/Release)
        ELSE (NOT CMAKE_BUILD_TYPE)
            SET(LIB_BUILT_PATH ${CMAKE_BINARY_DIR}/src/${CMAKE_BUILD_TYPE})
        ENDIF (NOT CMAKE_BUILD_TYPE)
    ELSE (MSVC)
        SET(LIB_BUILT_PATH ${CMAKE_BINARY_DIR}/lib)
    ENDIF (MSVC)
    MESSAGE(STATUS "LIB: ${LIB_BUILT_PATH}")
    add_test(
        NAME test_aes256 
        COMMAND test_aes256
        WORKING_DIRECTORY ${LIB_BUILT_PATH}
    )
ELSE (AES256_SHARED_LIB)
    add_test(
        NAME test_aes256 
        COMMAND test_aes256
    )
ENDIF (AES256_SHARED_LIB)
