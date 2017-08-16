/*
 * encrypt.cpp
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

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "aes256.hpp"

#define BUFFER_SIZE 1024*1024

#ifdef __APPLE__
#  define fseeko64 fseeko
#endif

int main(int argc, char **argv)
{
    ByteArray key, enc;
    size_t file_len;

    FILE *input, *output;

    srand(time(0));

    if (argc != 4) {
        fprintf(stderr, "Missing argument\n");
        fprintf(stderr, "Usage: %s <key> <input file> <output file>\n", argv[0]);
        return 1;
    }

    size_t key_len = 0;
    while(argv[1][key_len] != 0)
        key.push_back(argv[1][key_len++]);

    input = fopen(argv[2], "rb");
    if (input == 0) {
        fprintf(stderr, "Cannot read file '%s'\n", argv[2]);
        return 1;
    }

    output = fopen(argv[3], "wb");
    if (output == 0) {
        fprintf(stderr, "Cannot write file '%s'\n", argv[3]);
        return 1;
    }

    Aes256 aes(key);

    fseeko64(input, 0, SEEK_END);
    file_len = ftell(input);
    fseeko64(input, 0, SEEK_SET);
    printf("File is %zd bytes\n", file_len);

    enc.clear();
    aes.encrypt_start(file_len, enc);
    fwrite(enc.data(), enc.size(), 1, output);

    while (!feof(input)) {
        unsigned char buffer[BUFFER_SIZE];
        size_t buffer_len;

        buffer_len = fread(buffer, 1, BUFFER_SIZE, input);
        printf("Read %zd bytes\n", buffer_len);
        if (buffer_len > 0) {
            enc.clear();
            aes.encrypt_continue(buffer, buffer_len, enc);
            fwrite(enc.data(), enc.size(), 1, output);
        }
    }

    enc.clear();
    aes.encrypt_end(enc);
    fwrite(enc.data(), enc.size(), 1, output);

    fclose(input);
    fclose(output);

    return 0;
}
