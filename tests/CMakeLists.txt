add_executable(test_aes256 test_aes256.cpp)
add_dependencies(test_aes256 aes256)
target_link_libraries(test_aes256 aes256)

IF (MSVC)
    IF (NOT CMAKE_BUILD_TYPE)
        SET(LIB_BUILT_PATH ${CMAKE_BINARY_DIR}/src/Release)
    ELSE (NOT CMAKE_BUILD_TYPE)
        SET(LIB_BUILT_PATH ${CMAKE_BINARY_DIR}/src/${CMAKE_BUILD_TYPE})
    ENDIF (NOT CMAKE_BUILD_TYPE)
    add_test(
        NAME test_aes256 
        COMMAND test_aes256
        WORKING_DIRECTORY ${LIB_BUILT_PATH}
    )
ELSE (MSVC)
    add_test(
        NAME test_aes256 
        COMMAND test_aes256
    )
ENDIF (MSVC)
