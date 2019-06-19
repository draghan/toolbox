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
#include "../src/toolbox/containers/query.hpp"
#include "../src/toolbox/containers/remove.hpp"
#include <vector>
#include <list>

TEST_CASE("Container: - containsAny", "[container][query]")
{
    SECTION("std::vector, negative")
    {
        std::vector<int> source{1, 2, 3};
        std::vector<int> whitelist_int{4, 5, 6};
        std::vector<double> whitelist_double{1.2, 2.1, 3.14};

        REQUIRE_FALSE(toolbox::container::containsAny(source, whitelist_int));
        REQUIRE_FALSE(toolbox::container::containsAny(source, whitelist_double));
    }

    SECTION("std::vector, corner cases")
    {
        std::vector<int> empty;
        std::vector<int> not_empty{1, 2, 3};
        REQUIRE(toolbox::container::containsAny(empty, empty));
        REQUIRE_FALSE(toolbox::container::containsAny(not_empty, empty));
        REQUIRE_FALSE(toolbox::container::containsAny(empty, not_empty));
    }

    SECTION("std::vector, positive")
    {
        std::vector<int> source{1, 2, 3};
        std::vector<int> whitelist_int{3};
        std::vector<double> whitelist_double{1.0, 2.1, 3.14};
        REQUIRE(toolbox::container::containsAny(source, whitelist_int));
        REQUIRE(toolbox::container::containsAny(source, whitelist_double));
    }

    SECTION("std::list, negative")
    {
        std::list<int> source{1, 2, 3};
        std::list<int> whitelist_int{4, 5, 6};
        std::list<double> whitelist_double{1.2, 2.1, 3.14};

        REQUIRE_FALSE(toolbox::container::containsAny(source, whitelist_int));
        REQUIRE_FALSE(toolbox::container::containsAny(source, whitelist_double));
    }

    SECTION("std::list, corner cases")
    {
        std::list<int> empty;
        std::list<int> not_empty{1, 2, 3};
        REQUIRE(toolbox::container::containsAny(empty, empty));
        REQUIRE_FALSE(toolbox::container::containsAny(not_empty, empty));
        REQUIRE_FALSE(toolbox::container::containsAny(empty, not_empty));
    }

    SECTION("std::list, positive")
    {
        std::list<int> source{1, 2, 3};
        std::list<int> whitelist_int{3};
        std::list<double> whitelist_double{1.0, 2.1, 3.14};
        REQUIRE(toolbox::container::containsAny(source, whitelist_int));
        REQUIRE(toolbox::container::containsAny(source, whitelist_double));
    }

    SECTION("std::list + std::vector, negative")
    {
        std::vector<int> source{1, 2, 3};
        std::list<int> whitelist_int{4, 5, 6};
        std::list<double> whitelist_double{1.2, 2.1, 3.14};

        REQUIRE_FALSE(toolbox::container::containsAny(source, whitelist_int));
        REQUIRE_FALSE(toolbox::container::containsAny(source, whitelist_double));
    }

    SECTION("std::list + std::vector, corner cases")
    {
        std::vector<int> empty;
        std::list<int> not_empty{1, 2, 3};
        REQUIRE(toolbox::container::containsAny(empty, empty));
        REQUIRE_FALSE(toolbox::container::containsAny(not_empty, empty));
        REQUIRE_FALSE(toolbox::container::containsAny(empty, not_empty));
    }

    SECTION("std::list + std::vector, positive")
    {
        std::vector<int> source{1, 2, 3};
        std::list<int> whitelist_int{3};
        std::list<double> whitelist_double{1.0, 2.1, 3.14};
        REQUIRE(toolbox::container::containsAny(source, whitelist_int));
        REQUIRE(toolbox::container::containsAny(source, whitelist_double));
    }
}

TEST_CASE("Container: - contains", "[container][query]")
{
    SECTION("std::vector, negative")
    {
        std::vector<int> source{1, 2, 3};

        REQUIRE_FALSE(toolbox::container::contains(source, 0));
        REQUIRE_FALSE(toolbox::container::contains(source, 3.14));
    }

    SECTION("std::vector, corner cases")
    {
        std::vector<int> empty;
        REQUIRE_FALSE(toolbox::container::contains(empty, 15));
    }

    SECTION("std::vector, positive")
    {
        std::vector<int> source{1, 2, 3};
        REQUIRE(toolbox::container::contains(source, 1));
        REQUIRE(toolbox::container::contains(source, 3.0));
    }
}

TEST_CASE("Container: - containsOnly", "[container][query]")
{
    SECTION("std::vector, negative")
    {
        std::vector<int> source{1, 2, 3};
        std::vector<int> whitelist_int{1, 2};
        std::vector<double> whitelist_double{2.0, 3.0, 4.0};

        REQUIRE_FALSE(toolbox::container::containsOnly(source, whitelist_int));
        REQUIRE_FALSE(toolbox::container::containsOnly(source, whitelist_double));
    }

    SECTION("std::vector, corner cases")
    {
        std::vector<int> empty;
        std::vector<int> not_empty{1, 2, 3};
        REQUIRE(toolbox::container::containsOnly(empty, empty));
        REQUIRE_FALSE(toolbox::container::containsOnly(not_empty, empty));
        REQUIRE_FALSE(toolbox::container::containsOnly(empty, not_empty));
    }

    SECTION("std::vector, positive")
    {
        std::vector<int> source{1, 2, 3};
        std::vector<int> whitelist_int{1, 2, 3, 4};
        std::vector<double> whitelist_double{1.0, 2.0, 3.0};
        REQUIRE(toolbox::container::containsOnly(source, whitelist_int));
        REQUIRE(toolbox::container::containsOnly(source, whitelist_double));
    }
}

TEST_CASE("Container: - removeElements", "[container][remove]")
{
    SECTION("std::vector positive")
    {
        std::vector<int> source{1, 2, 3, 4, 1, 2, 3, 4};
        std::vector<int> toRemove{1, 3};
        const auto result = toolbox::container::removeElements(source, toRemove);
        REQUIRE(result.size() == source.size() - 4);
        REQUIRE_FALSE(toolbox::container::contains(result, 1));
        REQUIRE_FALSE(toolbox::container::contains(result, 3));
    }

    SECTION("std::list positive")
    {
        std::list<int> source{1, 2, 3, 4, 1, 2, 3, 4};
        std::vector<int> toRemove{1, 3};
        const std::list<int> result = toolbox::container::removeElements(source, toRemove);
        REQUIRE(result.size() == source.size() - 4);
        REQUIRE_FALSE(toolbox::container::contains(result, 1));
        REQUIRE_FALSE(toolbox::container::contains(result, 3));
    }

    SECTION("std::list corner cases")
    {
        std::list<int> empty_list;
        std::list<int> not_empty{1, 3};
        auto result = toolbox::container::removeElements(empty_list, not_empty);
        REQUIRE(result.empty());

        result = toolbox::container::removeElements(not_empty, empty_list);
        REQUIRE(result.size() == not_empty.size());
        REQUIRE(result.size() > 0);

        result = toolbox::container::removeElements(empty_list, empty_list);
        REQUIRE(result.empty());
    }
}

TEST_CASE("Container: - removeElement", "[container][remove]")
{
    SECTION("std::vector positive")
    {
        std::vector<int> source{1, 2, 3, 4, 1, 2, 3, 4};
        int toRemove = 1;
        const auto result = toolbox::container::removeElement(source, toRemove);
        REQUIRE(result.size() == source.size() - 2);
        REQUIRE_FALSE(toolbox::container::contains(result, 1));
        REQUIRE(toolbox::container::contains(result, 2));
        REQUIRE(toolbox::container::contains(result, 3));
        REQUIRE(toolbox::container::contains(result, 4));
    }

    SECTION("std::list positive")
    {
        std::list<int> source{1, 2, 3, 4, 1, 2, 3, 4};
        int toRemove{1};
        const std::list<int> result = toolbox::container::removeElement(source, toRemove);
        REQUIRE(result.size() == source.size() - 2);
        REQUIRE_FALSE(toolbox::container::contains(result, 1));
        REQUIRE(toolbox::container::contains(result, 2));
        REQUIRE(toolbox::container::contains(result, 3));
        REQUIRE(toolbox::container::contains(result, 4));
    }

    SECTION("std::list corner cases")
    {
        std::list<int> empty_list;
        auto result = toolbox::container::removeElement(empty_list, 1);
        REQUIRE(result.empty());
    }
}

TEST_CASE("Container: - removeElementInPlace", "[container][remove]")
{
    SECTION("std::vector positive")
    {
        std::vector<int> source{1, 2, 3, 4, 1, 2, 3, 4};
        size_t originalSize = source.size();
        int toRemove = 1;
        toolbox::container::removeElementInPlace(source, toRemove);
        REQUIRE(source.size() == originalSize - 2);
        REQUIRE_FALSE(toolbox::container::contains(source, 1));
        REQUIRE(toolbox::container::contains(source, 2));
        REQUIRE(toolbox::container::contains(source, 3));
        REQUIRE(toolbox::container::contains(source, 4));
    }

    SECTION("std::list positive")
    {
        std::list<int> source{1, 2, 3, 4, 1, 2, 3, 4};
        size_t originalSize = source.size();
        int toRemove{1};
        toolbox::container::removeElementInPlace(source, toRemove);
        REQUIRE(source.size() == originalSize - 2);
        REQUIRE_FALSE(toolbox::container::contains(source, 1));
        REQUIRE(toolbox::container::contains(source, 2));
        REQUIRE(toolbox::container::contains(source, 3));
        REQUIRE(toolbox::container::contains(source, 4));
    }

    SECTION("std::list corner cases")
    {
        std::list<int> empty_list;
        REQUIRE_NOTHROW(toolbox::container::removeElementInPlace(empty_list, 1));
        REQUIRE(empty_list.empty());
    }
}

TEST_CASE("Container: - removeElementsInPlace", "[container][remove]")
{
    SECTION("std::vector positive")
    {
        std::vector<int> source{1, 2, 3, 4, 1, 2, 3, 4};
        size_t originalSize = source.size();
        std::vector<int> toRemove{1, 3};
        toolbox::container::removeElementsInPlace(source, toRemove);
        REQUIRE(source.size() == originalSize - 4);
        REQUIRE_FALSE(toolbox::container::contains(source, 1));
        REQUIRE_FALSE(toolbox::container::contains(source, 3));
        REQUIRE(toolbox::container::contains(source, 2));
        REQUIRE(toolbox::container::contains(source, 4));
    }

    SECTION("std::list positive")
    {
        std::list<int> source{1, 2, 3, 4, 1, 2, 3, 4};
        size_t originalSize = source.size();
        std::vector<int> toRemove{1, 3};
        toolbox::container::removeElementsInPlace(source, toRemove);
        REQUIRE(source.size() == originalSize - 4);
        REQUIRE_FALSE(toolbox::container::contains(source, 1));
        REQUIRE_FALSE(toolbox::container::contains(source, 3));
        REQUIRE(toolbox::container::contains(source, 2));
        REQUIRE(toolbox::container::contains(source, 4));
    }

    SECTION("std::list corner cases")
    {
        std::list<int> empty_list;
        std::list<int> not_empty{1, 3};
        REQUIRE_NOTHROW(toolbox::container::removeElementsInPlace(empty_list, not_empty));
        REQUIRE(empty_list.empty());
        REQUIRE(not_empty.size() == 2);

        REQUIRE_NOTHROW(toolbox::container::removeElementsInPlace(not_empty, empty_list));
        REQUIRE(empty_list.empty());
        REQUIRE(not_empty.size() == 2);

        REQUIRE_NOTHROW(toolbox::container::removeElementsInPlace(empty_list, empty_list));
        REQUIRE(empty_list.empty());
    }
}