# Aes256

Welcome to Aes256 library

Author: Danilo Treffiletti <urban82@gmail.com>

## About

Aes256 is a library written in C++ that offer AES 256 bit encryption
and decryption.

It use a salt to extend the encryption key to 256 bit. The encrypted
stream is aware of this salt and of the padding added to complete last
encryption block.

A test of functionalities (with test of the AES 256 test vectors) is
included.

Two utilities to encrypt and decrypt files are also included.


## Compile

To compile Aes256, use cmake:

```shell
$ mkdir build
$ cd build
$ cmake ..
$ make
```

The library is compiled as shared library, so it can be linked in any
project.

To execute the test, type:

```shell
$ make test
```

## License

Copyright (c) 2014, Danilo Treffiletti <urban82@gmail.com>  
All rights reserved.

Aes256 is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as
published by the Free Software Foundation, either version 2.1
of the License, or (at your option) any later version.

Aes256 is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with Aes256.
If not, see <http://www.gnu.org/licenses/>.

A copy of the license is included in the files COPYING and COPYING.LESSER.
