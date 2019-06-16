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

#include "./endianness.hpp"

#include <algorithm>
#include <cstdint>
#include <limits>
#include <type_traits>
#include <array>

namespace toolbox::memory
{

    /// Slices bit form of an integer value to the array of smaller chunks.
    /// \example Slicing \p 0xBEEF value of \p uint16_t to \p uint8_t array will give us 2 elements array with values {0xBE, 0xEF}.
    /// \tparam SmallerType A destination type of array's element (type of divided chunk)..
    /// \tparam BiggerType Source type to be divided.
    /// \tparam slices_count Automatically calculated size of the result array.
    /// \param value Value to be sliced.
    /// \return Array of the sliced \p value.
    template
            <
                    typename SmallerType,
                    typename BiggerType,
                    size_t slices_count = std::numeric_limits<BiggerType>::digits / std::numeric_limits<SmallerType>::digits
            >
    constexpr std::array<SmallerType, slices_count> sliceToChunks(BiggerType value)
    {
        // initial assumptions:
        static_assert(slices_count > 1, "BiggerType should be wider than 'SmallerType'.");
        static_assert(std::is_integral<BiggerType>::value, "'BiggerType' should be fundamental integral type.");
        static_assert(!std::is_same<BiggerType, bool>::value, "'BiggerType' should not be the boolean type.");
        static_assert(std::is_unsigned<BiggerType>::value, "'BiggerType' should not store the sign bit.");

        static_assert(std::is_integral<SmallerType>::value, "'SmallerType' should be fundamental integral type.");
        static_assert(!std::is_same<SmallerType, bool>::value, "'SmallerType' should not be the boolean type.");
        static_assert(std::is_unsigned<SmallerType>::value, "'SmallerType' should not store the sign bit.");


        std::array<SmallerType, slices_count> slices{};

        size_t shift{0};
        auto get_next_slice = [value, &shift]([[maybe_unused]]auto &slice)
        {
            const auto current_shift = shift;
            shift += std::numeric_limits<SmallerType>::digits;
            return static_cast<SmallerType>((value >> current_shift) & std::numeric_limits<SmallerType>::max());
        };

        if (get_endianness() == endianness_t::big)
        {
            std::transform(slices.begin(), slices.end(), slices.begin(), get_next_slice);
        }
        else
        {
            std::transform(slices.rbegin(), slices.rend(), slices.rbegin(), get_next_slice);
        }

        return slices;
    }


}
