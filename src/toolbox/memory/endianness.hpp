/*
    This file is distributed under MIT License.

    Copyright (c) 2019 draghan

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

#pragma once


#include <cstdint>
#include <limits>
#include <cstddef>

namespace toolbox::memory
{
    enum class endianness_t
    {
        unknown,
        big,
        little
    };

    constexpr endianness_t get_endianness()
    {
        // write tested value to the memory:
        constexpr uint16_t pattern = 0xDEADu;
        constexpr auto first_byte = static_cast<uint8_t>(pattern >> static_cast<size_t>(std::numeric_limits<uint8_t>::digits) & std::numeric_limits<uint8_t>::max());

        if(first_byte == 0xAD)
        {
            return endianness_t::big;
        }
        else if(first_byte == 0xDE)
        {
            return endianness_t::little;
        }
        else
        {
            return endianness_t::unknown;
        }
    }

    inline endianness_t test_endianness()
    {
        // initial assumptions:
        static_assert(std::numeric_limits<uint8_t>::digits == 8);
        static_assert(std::numeric_limits<uint16_t>::digits == 16);
        static_assert(std::numeric_limits<uint8_t>::is_signed == false);
        static_assert(std::numeric_limits<uint32_t>::is_signed == false);

        // write tested value to the memory:
        const uint16_t pattern = 0xBEEF;

        // look at the first byte from the tested value:
        auto first_byte = reinterpret_cast<const uint8_t*>(&pattern);

        if (*first_byte == 0xBE)
        {
            // if first byte looks like 0xFF, than we have BIG ENDIAN CPU
            return endianness_t::big;
        }
        else if (*first_byte == 0xEF)
        {
            // if first byte looks like 0x00, than we have LITTLE ENDIAN CPU (most of the modern platforms have little endian; at least all of x86, x64)
            return endianness_t::little;
        }
        else
        {
            return endianness_t::unknown;
        }
    }
}
