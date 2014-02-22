add_executable(test_aes256 test_aes256.cpp)
target_link_libraries(test_aes256 aes256)
add_test(test_aes256 test_aes256)
