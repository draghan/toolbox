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

#include "../memory/chopping.hpp"
#include "./query.hpp"

#include <vector>

namespace toolbox::string
{

    /// Convert hex string to a numeric value.
    /// \tparam T Requested destination type for conversion.
    /// \param hexString Input hex string. Could contains 0x prefix and leading zeros.
    /// \return Converted numeric value.
    /// \throws If the value given as a \p hexString is too wide for type /p T, \p std::out_of_range exception is thrown. 
    template <typename T>
    constexpr T convertHexString(const std::string& hexString)
    {
        if(hexString.empty())
        {
            return T{0};
        }

        std::string_view sss {hexString};
        size_t offset = sss.find_first_not_of("0x");
        sss.remove_prefix(offset);
        if(sss.size() > std::numeric_limits<T>::digits)
        {
            throw std::out_of_range{"Input string '" + hexString + "' is too wide for requested type T."};
        }

        if(!toolbox::string::containsOnly(sss, "0123456789abcdefABCDEF"))
        {
            throw std::invalid_argument{"Input string '" + hexString + "' isn't valid hex value!"};
        }

        auto value = std::stoull(hexString, nullptr, 16);
        constexpr auto maxValue = std::numeric_limits<T>::max();
        if(value > maxValue)
        {
            throw std::out_of_range{"Input string '" + hexString + "' is too wide for requested type - max value: " + std::to_string(maxValue) + "."};
        }
        return static_cast<T>(value);
    }
}