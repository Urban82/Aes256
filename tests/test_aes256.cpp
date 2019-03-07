/*
 * test_aes256.cpp
 *
 * Copyright (c) 2014, Danilo Treffiletti <urban82@gmail.com>
 * All rights reserved.
 *
 *     This file is part of Aes256.
 *
 *     Aes256 is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU Lesser General Public License as
 *     published by the Free Software Foundation, either version 2.1
 *     of the License, or (at your option) any later version.
 *
 *     Aes256 is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *     GNU Lesser General Public License for more details.
 *
 *     You should have received a copy of the GNU Lesser General Public
 *     License along with Aes256.
 *     If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>

#include "aes256.hpp"

#define KEY_LEN    32
#define TEXT_SIZE 100
#define ENC_SIZE  113

unsigned char test_key[KEY_LEN] =   { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
                                      0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f };

unsigned char test_enc[ENC_SIZE] =  { 0x0c,
                                      0x8e, 0xa2, 0xb7, 0xca, 0x51, 0x67, 0x45, 0xbf, 0xea, 0xfc, 0x49, 0x90, 0x4b, 0x49, 0x60, 0x89,
                                      0x3e, 0x8d, 0x89, 0x22, 0xaf, 0x24, 0xef, 0x56, 0x57, 0x96, 0x84, 0x29, 0xfe, 0x01, 0xcd, 0xa0,
                                      0xd2, 0xfb, 0x4c, 0xd1, 0xf1, 0x95, 0x62, 0xea, 0x68, 0x7f, 0xce, 0x26, 0xc6, 0x34, 0xa8, 0xc2,
                                      0xda, 0xd8, 0x22, 0x75, 0xcc, 0x1c, 0x87, 0x3d, 0x77, 0xde, 0x14, 0xfc, 0x09, 0x38, 0x4c, 0xc2,
                                      0x40, 0xec, 0xbb, 0x5a, 0x2d, 0x7f, 0x53, 0xbc, 0x64, 0xef, 0x45, 0x16, 0xbf, 0xee, 0x3a, 0xac,
                                      0xa3, 0xc9, 0x9c, 0x16, 0x87, 0x39, 0xf3, 0x9e, 0xad, 0x0a, 0xbd, 0xae, 0x19, 0x1a, 0x5a, 0xb5,
                                      0xb9, 0x5f, 0xe8, 0xea, 0x96, 0x99, 0xf3, 0x47, 0x83, 0x20, 0x69, 0x9e, 0xcd, 0xf3, 0xc8, 0x6e };

unsigned char test_dec[TEXT_SIZE] = { 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff,
                                      0x10, 0x21, 0x32, 0x43, 0x54, 0x65, 0x76, 0x87, 0x98, 0xa9, 0xba, 0xcb, 0xdc, 0xed, 0xfe, 0x0f,
                                      0x20, 0x31, 0x42, 0x53, 0x64, 0x75, 0x86, 0x97, 0xa8, 0xb9, 0xca, 0xdb, 0xec, 0xfd, 0x0e, 0x1f,
                                      0x30, 0x41, 0x52, 0x63, 0x74, 0x85, 0x96, 0xa7, 0xb8, 0xc9, 0xda, 0xeb, 0xfc, 0x0d, 0x1e, 0x2f,
                                      0x40, 0x51, 0x62, 0x73, 0x84, 0x95, 0xa6, 0xb7, 0xc8, 0xd9, 0xea, 0xfb, 0x0c, 0x1d, 0x2e, 0x3f,
                                      0x50, 0x61, 0x72, 0x83, 0x94, 0xa5, 0xb6, 0xc7, 0xd8, 0xe9, 0xfa, 0x0b, 0x1c, 0x2d, 0x3e, 0x4f,
                                      0x60, 0x71, 0x82, 0x93 };

// Test vectors
#define TEST_VECTOR_NUM   4
#define TEST_VECTOR_SIZE 16
unsigned char testv_key[KEY_LEN] = { 0x60, 0x3d, 0xeb, 0x10, 0x15, 0xca, 0x71, 0xbe, 0x2b, 0x73, 0xae, 0xf0, 0x85, 0x7d, 0x77, 0x81,
                                     0x1f, 0x35, 0x2c, 0x07, 0x3b, 0x61, 0x08, 0xd7, 0x2d, 0x98, 0x10, 0xa3, 0x09, 0x14, 0xdf, 0xf4 };
unsigned char testv_dec[TEST_VECTOR_SIZE][TEST_VECTOR_SIZE] = {
                                   { 0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a },
                                   { 0xae, 0x2d, 0x8a, 0x57, 0x1e, 0x03, 0xac, 0x9c, 0x9e, 0xb7, 0x6f, 0xac, 0x45, 0xaf, 0x8e, 0x51 },
                                   { 0x30, 0xc8, 0x1c, 0x46, 0xa3, 0x5c, 0xe4, 0x11, 0xe5, 0xfb, 0xc1, 0x19, 0x1a, 0x0a, 0x52, 0xef },
                                   { 0xf6, 0x9f, 0x24, 0x45, 0xdf, 0x4f, 0x9b, 0x17, 0xad, 0x2b, 0x41, 0x7b, 0xe6, 0x6c, 0x37, 0x10 }
};
unsigned char testv_enc[TEST_VECTOR_SIZE][TEST_VECTOR_SIZE + 1] = {
                                   { 0x00, 0xf3, 0xee, 0xd1, 0xbd, 0xb5, 0xd2, 0xa0, 0x3c, 0x06, 0x4b, 0x5a, 0x7e, 0x3d, 0xb1, 0x81, 0xf8 },
                                   { 0x00, 0x59, 0x1c, 0xcb, 0x10, 0xd4, 0x10, 0xed, 0x26, 0xdc, 0x5b, 0xa7, 0x4a, 0x31, 0x36, 0x28, 0x70 },
                                   { 0x00, 0xb6, 0xed, 0x21, 0xb9, 0x9c, 0xa6, 0xf4, 0xf9, 0xf1, 0x53, 0xe7, 0xb1, 0xbe, 0xaf, 0xed, 0x1d },
                                   { 0x00, 0x23, 0x30, 0x4b, 0x7a, 0x39, 0xf9, 0xf3, 0xff, 0x06, 0x7d, 0x8d, 0x8f, 0x9e, 0x24, 0xec, 0xc7 }
};

void init_key(ByteArray& key) {
    for (unsigned char i = 0; i < KEY_LEN;i++)
        key.push_back(test_key[i]);
}

void init_key(ByteArray& key, unsigned char index) {
    for (unsigned char i = 0; i < KEY_LEN;i++) {
        if (index < TEST_VECTOR_NUM)
            key.push_back(testv_key[i]);
        else
            key.push_back(0);
    }
}

void init_txt(ByteArray& txt) {
    for (unsigned char i = 0; i < TEXT_SIZE; ++i)
        txt.push_back(test_dec[i]);
}

void init_txt(unsigned char* txt) {
    for (unsigned char i = 0; i < TEXT_SIZE; ++i)
        txt[i] = test_dec[i];
}

void init_txt(ByteArray& txt, unsigned char index) {
    for (unsigned char i = 0; i < TEST_VECTOR_SIZE; ++i) {
        if (index < TEST_VECTOR_NUM)
            txt.push_back(testv_dec[index][i]);
        else
            txt.push_back(0);
    }
}

void init_enc(ByteArray& enc) {
    for (unsigned char i = 0; i < ENC_SIZE; ++i)
        enc.push_back(test_enc[i]);
}

void init_enc(unsigned char* enc) {
    for (unsigned char i = 0; i < ENC_SIZE; ++i)
        enc[i] = test_enc[i];
}

int test_encrypts_bytearray() {
    std::cout << "Starting test encrypts bytearray..." << std::endl;

    ByteArray key;
    init_key(key);
    std::cout << " Key initialized..." << std::endl;

    ByteArray txt, enc;
    init_txt(txt);
    std::cout << " Text initialized..." << std::endl;

    ByteArray::size_type enc_len = Aes256::encrypt(key, txt, enc);
    std::cout << " Encrypted..." << std::endl;

    if (enc_len != ENC_SIZE) {
        std::cerr << "Wrong encrypted length: " << enc_len << " instead of " << ENC_SIZE << std::endl;
        return -1;
    }

    for (unsigned char i = 0; i < ENC_SIZE; ++i)
        if (enc[i] != test_enc[i]) {
            std::cerr << "Wrong encrypted byte in position " << i << ": found " << std::hex << (int)enc[i] << " instead of " << (int)test_enc[i] << std::endl;
            return -2;
        }

    std::cout << " Done!" << std::endl;
    return 0;
}

int test_encrypts_char() {
    std::cout << "Starting test encrypts char..." << std::endl;

    ByteArray key;
    init_key(key);
    std::cout << " Key initialized..." << std::endl;

    unsigned char txt[TEXT_SIZE];
    ByteArray enc;
    init_txt(txt);
    std::cout << " Text initialized..." << std::endl;

    ByteArray::size_type enc_len = Aes256::encrypt(key, txt, TEXT_SIZE, enc);
    std::cout << " Encrypted..." << std::endl;

    if (enc_len != ENC_SIZE) {
        std::cerr << "Wrong encrypted length: " << enc_len << " instead of " << ENC_SIZE << std::endl;
        return -1;
    }

    for (unsigned char i = 0; i < ENC_SIZE; ++i)
        if (enc[i] != test_enc[i]) {
            std::cerr << "Wrong encrypted byte in position " << i << ": found " << std::hex << (int)enc[i] << " instead of " << (int)test_enc[i] << std::endl;
            return -2;
        }

    std::cout << " Done!" << std::endl;
    return 0;
}

int test_decrypts_bytearray() {
    std::cout << "Starting test decrypts bytearray..." << std::endl;

    ByteArray key;
    init_key(key);
    std::cout << " Key initialized..." << std::endl;

    ByteArray enc, dec;
    init_enc(enc);
    std::cout << " Encrypted initialized..." << std::endl;

    ByteArray::size_type dec_len = Aes256::decrypt(key, enc, dec);
    std::cout << " Decrypted..." << std::endl;

    if (dec_len != TEXT_SIZE) {
        std::cerr << "Wrong decrypted length: " << dec_len << " instead of " << TEXT_SIZE << std::endl;
        return -1;
    }

    for (unsigned char i = 0; i < TEXT_SIZE; ++i)
        if (dec[i] != test_dec[i]) {
            std::cerr << "Wrong decrypted byte in position " << i << ": found " << std::hex << (int)dec[i] << " instead of " << (int)test_dec[i] << std::endl;
            return -2;
        }

    std::cout << " Done!" << std::endl;
    return 0;
}

int test_decrypts_char() {
    std::cout << "Starting test decrypts char..." << std::endl;

    ByteArray key;
    init_key(key);
    std::cout << " Key initialized..." << std::endl;

    unsigned char enc[ENC_SIZE];
    ByteArray dec;
    init_enc(enc);
    std::cout << " Encrypted initialized..." << std::endl;

    ByteArray::size_type dec_len = Aes256::decrypt(key, enc, ENC_SIZE, dec);
    std::cout << " Decrypted..." << std::endl;

    if (dec_len != TEXT_SIZE) {
        std::cerr << "Wrong decrypted length: " << dec_len << " instead of " << TEXT_SIZE << std::endl;
        return -1;
    }

    for (unsigned char i = 0; i < TEXT_SIZE; ++i)
        if (dec[i] != test_dec[i]) {
            std::cerr << "Wrong decrypted byte in position " << i << ": found " << std::hex << (int)dec[i] << " instead of " << (int)test_enc[i] << std::endl;
            return -2;
        }

    std::cout << " Done!" << std::endl;
    return 0;
}

int test_encrypts_decrypts() {
    std::cout << "Starting test encrypts/decrypts..." << std::endl;

    ByteArray key;
    init_key(key);
    std::cout << " Key initialized..." << std::endl;

    ByteArray txt, enc, dec;
    init_txt(txt);
    std::cout << " Text initialized..." << std::endl;

    ByteArray::size_type enc_len = Aes256::encrypt(key, txt, enc);
    std::cout << " Encrypted..." << std::endl;

    if (enc_len != ENC_SIZE) {
        std::cerr << "Wrong encrypted length: " << enc_len << " instead of " << ENC_SIZE << std::endl;
        return -1;
    }

    for (unsigned char i = 0; i < ENC_SIZE; ++i)
        if (enc[i] != test_enc[i]) {
            std::cerr << "Wrong encrypted byte in position " << i << ": found " << std::hex << (int)enc[i] << " instead of " << (int)test_enc[i] << std::endl;
            return -2;
        }

    ByteArray::size_type dec_len = Aes256::decrypt(key, enc, dec);
    std::cout << " Decrypted..." << std::endl;

    if (dec_len != TEXT_SIZE) {
        std::cerr << "Wrong decrypted length: " << dec_len << " instead of " << TEXT_SIZE << std::endl;
        return -1;
    }

    for (unsigned char i = 0; i < TEXT_SIZE; ++i)
        if (dec[i] != test_dec[i]) {
            std::cerr << "Wrong decrypted byte in position " << i << ": found " << std::hex << (int)dec[i] << " instead of " << (int)test_dec[i] << std::endl;
            return -2;
        }

    std::cout << " Done!" << std::endl;
    return 0;
}

int test_vectors() {
    std::cout << "Starting test vectors..." << std::endl;

    for (int i = 0; i < TEST_VECTOR_NUM; ++i) {
        ByteArray key;
        init_key(key, i);
        std::cout << " Key initialized..." << std::endl;

        ByteArray txt, enc;
        init_txt(txt, i);
        std::cout << " Text initialized..." << std::endl;

        ByteArray::size_type enc_len = Aes256::encrypt(key, txt, enc);
        std::cout << " Encrypted..." << std::endl;

        if (enc_len != TEST_VECTOR_SIZE + 1) {
            std::cerr << "Wrong encrypted length: " << enc_len << " instead of " << TEST_VECTOR_SIZE + 1 << std::endl;
            return -1;
        }

        for (unsigned char j = 0; j < TEST_VECTOR_SIZE; ++j)
            if (enc[j] != testv_enc[i][j]) {
                std::cerr << "Wrong encrypted byte in position " << j << ": found " << std::hex << (int)enc[j] << " instead of " << (int)testv_enc[i][j] << std::endl;
                return -2;
            }
    }

    std::cout << " Done!" << std::endl;
    return 0;
}

int main(int argc, char *argv[])
{
    if (test_encrypts_bytearray() != 0)
        return -1;
    if (test_encrypts_char() != 0)
        return -2;
    if (test_decrypts_bytearray() != 0)
        return -3;
    if (test_decrypts_char() != 0)
        return -4;
    if (test_encrypts_decrypts() != 0)
        return -5;
    if (test_vectors() != 0)
        return -6;

    return 0;
} /* main */
