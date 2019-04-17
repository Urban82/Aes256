add_executable(encrypt encrypt.cpp)
target_link_libraries(encrypt aes256)
install(TARGETS encrypt DESTINATION bin)

add_executable(decrypt decrypt.cpp)
target_link_libraries(decrypt aes256)
install(TARGETS decrypt DESTINATION bin)
