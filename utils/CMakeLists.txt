add_executable(encrypt encrypt.cpp)
target_link_libraries(encrypt aes256)

add_executable(decrypt decrypt.cpp)
target_link_libraries(decrypt aes256)
