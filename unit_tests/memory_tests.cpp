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

#include "../external/Catch2/single_include/catch2/catch.hpp"

#include <toolbox/memory/chopping.hpp>

TEST_CASE("Memory: endianness", "[memory][endianness]")
{
    SECTION("Checking endianness in two different ways")
    {
        REQUIRE(toolbox::memory::get_endianness() == toolbox::memory::test_endianness());
    }
}

TEST_CASE("Memory: splicing, uint16_t -> uint8_t", "[memory][chopping][spliceBytes]")
{
    using big_t = uint16_t;
    using small_t = uint8_t;
    SECTION("0xDEAD pattern")
    {
        big_t test_value = 0xDEAD;
        const auto spliced = toolbox::memory::sliceBytes<small_t>(test_value);
        REQUIRE(spliced.size() == 2);
        REQUIRE(spliced[0] == 0xDE);
        REQUIRE(spliced[1] == 0xAD);
    }

    SECTION("0 value")
    {
        big_t test_value = 0;
        const auto spliced = toolbox::memory::sliceBytes<small_t>(test_value);
        REQUIRE(spliced.size() == 2);
        REQUIRE(spliced[0] == 0x00);
        REQUIRE(spliced[1] == 0x00);
    }

    SECTION("1 value")
    {
        big_t test_value = 1;
        const auto spliced = toolbox::memory::sliceBytes<small_t>(test_value);
        REQUIRE(spliced.size() == 2);
        REQUIRE(spliced[0] == 0x00);
        REQUIRE(spliced[1] == 1);
    }

    SECTION("max value")
    {
        auto test_value = std::numeric_limits<big_t>::max();
        const auto spliced = toolbox::memory::sliceBytes<small_t>(test_value);
        REQUIRE(spliced.size() == 2);
        REQUIRE(spliced[0] == std::numeric_limits<small_t>::max());
        REQUIRE(spliced[1] == std::numeric_limits<small_t>::max());
    }
}

TEST_CASE("Memory: splicing, uint32_t -> uint8_t", "[memory][chopping][spliceBytes]")
{
    using big_t = uint32_t;
    using small_t = uint8_t;

    SECTION("0xDEADBEEF pattern")
    {
        big_t test_value = 0xDEADBEEF;
        const auto spliced = toolbox::memory::sliceBytes<small_t>(test_value);
        REQUIRE(spliced.size() == 4);
        REQUIRE(spliced[0] == 0xDE);
        REQUIRE(spliced[1] == 0xAD);
        REQUIRE(spliced[2] == 0xBE);
        REQUIRE(spliced[3] == 0xEF);
    }

    SECTION("0 value")
    {
        big_t test_value = 0;
        const auto spliced = toolbox::memory::sliceBytes<small_t>(test_value);
        REQUIRE(spliced.size() == 4);
        REQUIRE(spliced[0] == 0x00);
        REQUIRE(spliced[1] == 0x00);
        REQUIRE(spliced[2] == 0x00);
        REQUIRE(spliced[3] == 0x00);
    }

    SECTION("1 value")
    {
        big_t test_value = 1;
        const auto spliced = toolbox::memory::sliceBytes<small_t>(test_value);
        REQUIRE(spliced.size() == 4);
        REQUIRE(spliced[0] == 0x00);
        REQUIRE(spliced[1] == 0x00);
        REQUIRE(spliced[2] == 0x00);
        REQUIRE(spliced[3] == 1);
    }

    SECTION("max value")
    {
        auto test_value = std::numeric_limits<big_t>::max();
        const auto spliced = toolbox::memory::sliceBytes<small_t>(test_value);
        REQUIRE(spliced.size() == 4);
        REQUIRE(spliced[0] == std::numeric_limits<small_t>::max());
        REQUIRE(spliced[1] == std::numeric_limits<small_t>::max());
        REQUIRE(spliced[2] == std::numeric_limits<small_t>::max());
        REQUIRE(spliced[3] == std::numeric_limits<small_t>::max());
    }
}

TEST_CASE("Memory: splicing, uint32_t -> uint16_t", "[memory][chopping][spliceBytes]")
{
    using big_t = uint32_t;
    using small_t = uint16_t;

    SECTION("0xDEADBEEF pattern")
    {
        big_t test_value = 0xDEADBEEF;
        const auto spliced = toolbox::memory::sliceBytes<small_t>(test_value);
        REQUIRE(spliced.size() == 2);
        REQUIRE(spliced[0] == 0xDEAD);
        REQUIRE(spliced[1] == 0xBEEF);
    }

    SECTION("0 value")
    {
        big_t test_value = 0;
        const auto spliced = toolbox::memory::sliceBytes<small_t>(test_value);
        REQUIRE(spliced.size() == 2);
        REQUIRE(spliced[0] == 0x00);
        REQUIRE(spliced[1] == 0x00);
    }

    SECTION("1 value")
    {
        big_t test_value = 1;
        const auto spliced = toolbox::memory::sliceBytes<small_t>(test_value);
        REQUIRE(spliced.size() == 2);
        REQUIRE(spliced[0] == 0x00);
        REQUIRE(spliced[1] == 1);
    }

    SECTION("max value")
    {
        auto test_value = std::numeric_limits<big_t>::max();
        const auto spliced = toolbox::memory::sliceBytes<small_t>(test_value);
        REQUIRE(spliced.size() == 2);
        REQUIRE(spliced[0] == std::numeric_limits<small_t>::max());
        REQUIRE(spliced[1] == std::numeric_limits<small_t>::max());
    }
}

TEST_CASE("Memory: splicing, uint64_t -> uint16_t", "[memory][chopping][spliceBytes]")
{
    using big_t = uint64_t;
    using small_t = uint16_t;

    SECTION("0xDeadBeefAbbaBabe pattern")
    {
        big_t test_value = 0xDeadBeefAbbaBabe;
        const auto spliced = toolbox::memory::sliceBytes<small_t>(test_value);
        REQUIRE(spliced.size() == 4);
        REQUIRE(spliced[0] == 0xDEAD);
        REQUIRE(spliced[1] == 0xBEEF);
        REQUIRE(spliced[2] == 0xABBA);
        REQUIRE(spliced[3] == 0xBABE);
    }

    SECTION("0 value")
    {
        big_t test_value = 0;
        const auto spliced = toolbox::memory::sliceBytes<small_t>(test_value);
        REQUIRE(spliced.size() == 4);
        REQUIRE(spliced[0] == 0x00);
        REQUIRE(spliced[1] == 0x00);
        REQUIRE(spliced[2] == 0x00);
        REQUIRE(spliced[3] == 0x00);
    }

    SECTION("1 value")
    {
        big_t test_value = 1;
        const auto spliced = toolbox::memory::sliceBytes<small_t>(test_value);
        REQUIRE(spliced.size() == 4);
        REQUIRE(spliced[0] == 0x00);
        REQUIRE(spliced[1] == 0x00);
        REQUIRE(spliced[2] == 0x00);
        REQUIRE(spliced[3] == 1);
    }

    SECTION("max value")
    {
        auto test_value = std::numeric_limits<big_t>::max();
        const auto spliced = toolbox::memory::sliceBytes<small_t>(test_value);
        REQUIRE(spliced.size() == 4);
        REQUIRE(spliced[0] == std::numeric_limits<small_t>::max());
        REQUIRE(spliced[1] == std::numeric_limits<small_t>::max());
        REQUIRE(spliced[2] == std::numeric_limits<small_t>::max());
        REQUIRE(spliced[3] == std::numeric_limits<small_t>::max());
    }
}

TEST_CASE("Memory: splicing, uint64_t -> uint8_t", "[memory][chopping][spliceBytes]")
{
    using big_t = uint64_t;
    using small_t = uint8_t;

    SECTION("0xDeadBeefAbbaBabe pattern")
    {
        big_t test_value = 0xDeadBeefAbbaBabe;
        const auto spliced = toolbox::memory::sliceBytes<small_t>(test_value);
        REQUIRE(spliced.size() == 8);
        REQUIRE(spliced[0] == 0xDE);
        REQUIRE(spliced[1] == 0xAD);
        REQUIRE(spliced[2] == 0xBE);
        REQUIRE(spliced[3] == 0xEF);
        REQUIRE(spliced[4] == 0xAB);
        REQUIRE(spliced[5] == 0xBA);
        REQUIRE(spliced[6] == 0xBA);
        REQUIRE(spliced[7] == 0xBE);
    }

    SECTION("0 value")
    {
        big_t test_value = 0;
        const auto spliced = toolbox::memory::sliceBytes<small_t>(test_value);
        REQUIRE(spliced.size() == 8);
        REQUIRE(spliced[0] == 0x00);
        REQUIRE(spliced[1] == 0x00);
        REQUIRE(spliced[2] == 0x00);
        REQUIRE(spliced[3] == 0x00);
        REQUIRE(spliced[4] == 0x00);
        REQUIRE(spliced[5] == 0x00);
        REQUIRE(spliced[6] == 0x00);
        REQUIRE(spliced[7] == 0x00);
    }

    SECTION("1 value")
    {
        big_t test_value = 1;
        const auto spliced = toolbox::memory::sliceBytes<small_t>(test_value);
        REQUIRE(spliced.size() == 8);
        REQUIRE(spliced[0] == 0x00);
        REQUIRE(spliced[1] == 0x00);
        REQUIRE(spliced[2] == 0x00);
        REQUIRE(spliced[3] == 0x00);
        REQUIRE(spliced[4] == 0x00);
        REQUIRE(spliced[5] == 0x00);
        REQUIRE(spliced[6] == 0x00);
        REQUIRE(spliced[7] == 1);
    }

    SECTION("max value")
    {
        auto test_value = std::numeric_limits<big_t>::max();
        const auto spliced = toolbox::memory::sliceBytes<small_t>(test_value);
        REQUIRE(spliced.size() == 8);
        REQUIRE(spliced[0] == std::numeric_limits<small_t>::max());
        REQUIRE(spliced[1] == std::numeric_limits<small_t>::max());
        REQUIRE(spliced[2] == std::numeric_limits<small_t>::max());
        REQUIRE(spliced[3] == std::numeric_limits<small_t>::max());
        REQUIRE(spliced[4] == std::numeric_limits<small_t>::max());
        REQUIRE(spliced[5] == std::numeric_limits<small_t>::max());
        REQUIRE(spliced[6] == std::numeric_limits<small_t>::max());
        REQUIRE(spliced[7] == std::numeric_limits<small_t>::max());
    }
}