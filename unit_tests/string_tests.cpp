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

#include <toolbox/string/remove.hpp>

TEST_CASE("String: remove character from string and return copy - removeCharFromString", "[string][remove]")
{
    SECTION("Remove 'a' in 'Bear' pattern")
    {
        const std::string pattern{"Bear"};
        const auto result = toolbox::string::removeCharFromString(pattern, 'a');

        REQUIRE(pattern == "Bear");
        REQUIRE(result == "Ber");
    }

    SECTION("Remove 'e' in 'beer' pattern")
    {
        const std::string pattern{"beer"};
        const auto result = toolbox::string::removeCharFromString(pattern, 'e');

        REQUIRE(pattern == "beer");
        REQUIRE(result == "br");
    }

    SECTION("Remove 'c' in 'CCCc' pattern")
    {
        const std::string pattern{"CCCc"};
        const auto result = toolbox::string::removeCharFromString(pattern, 'c');

        REQUIRE(pattern == "CCCc");
        REQUIRE(result == "CCC");
    }

    SECTION("Remove 'c' in 'cCCC' pattern")
    {
        const std::string pattern{"cCCC"};
        const auto result = toolbox::string::removeCharFromString(pattern, 'c');

        REQUIRE(pattern == "cCCC");
        REQUIRE(result == "CCC");
    }

    SECTION("Remove 'c' in 'cCCcCCc' pattern")
    {
        const std::string pattern{"cCCcCCc"};
        const auto result = toolbox::string::removeCharFromString(pattern, 'c');

        REQUIRE(pattern == "cCCcCCc");
        REQUIRE(result == "CCCC");
    }

    SECTION("Remove ' ' in 'cCCcCCc' pattern")
    {
        const std::string pattern{"cCCcCCc"};
        const auto result = toolbox::string::removeCharFromString(pattern, ' ');

        REQUIRE(pattern == result);
    }

    SECTION("Remove ' ' in empty pattern")
    {
        const std::string pattern{""};
        const auto result = toolbox::string::removeCharFromString(pattern, ' ');

        REQUIRE(pattern.empty());
        REQUIRE(result.empty());
    }

    SECTION("Remove 'a' in 'aaa' pattern")
    {
        const std::string pattern{"aaa"};
        const auto result = toolbox::string::removeCharFromString(pattern, 'a');

        REQUIRE(pattern == "aaa");
        REQUIRE(result.empty());
    }
}

TEST_CASE("String: remove character from string in place - removeCharFromStringInPlace", "[string][remove]")
{
    SECTION("Remove 'a' in 'Bear' pattern")
    {
        std::string pattern{"Bear"};
        toolbox::string::removeCharFromStringInPlace(pattern, 'a');

        REQUIRE(pattern == "Ber");
    }

    SECTION("Remove 'e' in 'beer' pattern")
    {
        std::string pattern{"beer"};
        toolbox::string::removeCharFromStringInPlace(pattern, 'e');

        REQUIRE(pattern == "br");
    }

    SECTION("Remove 'c' in 'CCCc' pattern")
    {
        std::string pattern{"CCCc"};
        toolbox::string::removeCharFromStringInPlace(pattern, 'c');

        REQUIRE(pattern == "CCC");
    }

    SECTION("Remove 'c' in 'cCCC' pattern")
    {
        std::string pattern{"cCCC"};
        toolbox::string::removeCharFromStringInPlace(pattern, 'c');

        REQUIRE(pattern == "CCC");
    }

    SECTION("Remove 'c' in 'cCCcCCc' pattern")
    {
        std::string pattern{"cCCcCCc"};
        toolbox::string::removeCharFromStringInPlace(pattern, 'c');

        REQUIRE(pattern == "CCCC");
    }

    SECTION("Remove ' ' in 'cCCcCCc' pattern")
    {
        std::string pattern{"cCCcCCc"};
        toolbox::string::removeCharFromStringInPlace(pattern, ' ');

        REQUIRE(pattern == "cCCcCCc");
    }

    SECTION("Remove ' ' in empty pattern")
    {
        std::string pattern{""};
        toolbox::string::removeCharFromStringInPlace(pattern, ' ');

        REQUIRE(pattern.empty());
    }

    SECTION("Remove 'a' in 'aaa' pattern")
    {
        std::string pattern{"aaa"};
        toolbox::string::removeCharFromStringInPlace(pattern, 'a');

        REQUIRE(pattern.empty());
    }
}

TEST_CASE("String: remove multiple characters from string and return copy", "[string][remove]")
{
    SECTION("Remove characters 'AB' from pattern 'ABC'")
    {
        std::string pattern{"ABC"};
        auto result = toolbox::string::removeCharsFromString(pattern, "AB");

        REQUIRE(pattern == "ABC");
        REQUIRE(result == "C");
    }

    SECTION("Remove characters 'BA' from pattern 'ABC'")
    {
        std::string pattern{"ABC"};
        auto result = toolbox::string::removeCharsFromString(pattern, "BA");

        REQUIRE(pattern == "ABC");
        REQUIRE(result == "C");
    }

    SECTION("Remove characters 'AB' from pattern 'abc'")
    {
        std::string pattern{"abc"};
        auto result = toolbox::string::removeCharsFromString(pattern, "AB");

        REQUIRE(pattern == "abc");
        REQUIRE(result == "abc");
    }

    SECTION("Remove characters 'A' from pattern 'ABBA'")
    {
        std::string pattern{"ABBA"};
        auto result = toolbox::string::removeCharsFromString(pattern, "A");

        REQUIRE(pattern == "ABBA");
        REQUIRE(result == "BB");
    }

    SECTION("Remove characters 'A' from empty pattern")
    {
        std::string pattern{""};
        auto result = toolbox::string::removeCharsFromString(pattern, "A");

        REQUIRE(pattern == "");
        REQUIRE(result == "");
    }

    SECTION("Remove empty blacklist from pattern 'ABBA'")
    {
        std::string pattern{"ABBA"};
        auto result = toolbox::string::removeCharsFromString(pattern, "");

        REQUIRE(pattern == "ABBA");
        REQUIRE(result == "ABBA");
    }

    SECTION("Remove empty blacklist from empty pattern")
    {
        std::string pattern{""};
        auto result = toolbox::string::removeCharsFromString(pattern, "");

        REQUIRE(pattern == "");
        REQUIRE(result == "");
    }

    SECTION("Remove characters 'ABBA' from pattern 'A'")
    {
        std::string pattern{"A"};
        auto result = toolbox::string::removeCharsFromString(pattern, "ABBA");

        REQUIRE(pattern == "A");
        REQUIRE(result == "");
    }

    SECTION("Remove characters 'ABBA' from pattern 'Ac'")
    {
        std::string pattern{"Ac"};
        auto result = toolbox::string::removeCharsFromString(pattern, "ABBA");

        REQUIRE(pattern == "Ac");
        REQUIRE(result == "c");
    }
}

TEST_CASE("String: remove multiple characters from string in place", "[string][remove]")
{
    SECTION("Remove characters 'AB' from pattern 'ABC'")
    {
        std::string pattern{"ABC"};
        toolbox::string::removeCharsFromStringInPlace(pattern, "AB");

        REQUIRE(pattern == "C");
    }

    SECTION("Remove characters 'BA' from pattern 'ABC'")
    {
        std::string pattern{"ABC"};
        toolbox::string::removeCharsFromStringInPlace(pattern, "BA");

        REQUIRE(pattern == "C");
    }

    SECTION("Remove characters 'AB' from pattern 'abc'")
    {
        std::string pattern{"abc"};
        toolbox::string::removeCharsFromStringInPlace(pattern, "AB");

        REQUIRE(pattern == "abc");
    }

    SECTION("Remove characters 'A' from pattern 'ABBA'")
    {
        std::string pattern{"ABBA"};
        toolbox::string::removeCharsFromStringInPlace(pattern, "A");

        REQUIRE(pattern == "BB");
    }

    SECTION("Remove characters 'A' from empty pattern")
    {
        std::string pattern{""};
        toolbox::string::removeCharsFromStringInPlace(pattern, "A");

        REQUIRE(pattern == "");
    }

    SECTION("Remove empty blacklist from pattern 'ABBA'")
    {
        std::string pattern{"ABBA"};
        auto result = toolbox::string::removeCharsFromString(pattern, "");

        REQUIRE(pattern == "ABBA");
        REQUIRE(result == "ABBA");
    }

    SECTION("Remove empty blacklist from empty pattern")
    {
        std::string pattern{""};
        toolbox::string::removeCharsFromStringInPlace(pattern, "");

        REQUIRE(pattern == "");
    }

    SECTION("Remove characters 'ABBA' from pattern 'A'")
    {
        std::string pattern{"A"};
        toolbox::string::removeCharsFromStringInPlace(pattern, "ABBA");

        REQUIRE(pattern == "");
    }

    SECTION("Remove characters 'ABBA' from pattern 'Ac'")
    {
        std::string pattern{"Ac"};
        toolbox::string::removeCharsFromStringInPlace(pattern, "ABBA");

        REQUIRE(pattern == "c");
    }
}