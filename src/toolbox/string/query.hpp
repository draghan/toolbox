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

#include <string_view>
#include "../containers/query.hpp"

namespace toolbox::string
{
    /// Test whether \p source string starts with \p starting character.
    /// \param source Source string to be tested.
    /// \param starting Starting char to be searched for.
    /// \return True if \p source starts with \p starting string, false otherwise.
    /// \remark Empty string starts only with empty string. Any string starts with empty starting string.
    constexpr bool startsWith(const std::string_view source, char starting)
    {
        if(source.empty())
        {
            return false;
        }

        return source[0] == starting;
    }

    /// Test whether \p source string starts with \p starting string.
    /// \param source Source string to be tested.
    /// \param starting Starting string to be searched for.
    /// \return True if \p source starts with \p starting string, false otherwise.
    /// \remark Empty string starts only with empty string. Any string starts with empty starting string.
    constexpr bool startsWith(const std::string_view source, const std::string_view starting)
    {
        if(source.size() < starting.size())
        {
            return false;
        }

        for(size_t i = 0; i < starting.size(); ++i)
        {
            if(source[i] != starting[i])
            {
                return false;
            }
        }

        return true;
    }

    /// Test whether \p source string ends with \p ending char.
    /// \param source Source string to be tested.
    /// \param ending Ending string to be searched for.
    /// \return True if \p source ends with \p ending string, false otherwise.
    /// \remark Empty string ends only with empty string. Any string ends with empty string.
    constexpr bool endsWith(const std::string_view source, char ending)
    {
        if(source.empty())
        {
            return false;
        }

        return *(source.end()-1) == ending;
    }

    /// Test whether \p source string ends with \p ending string.
    /// \param source Source string to be tested.
    /// \param ending Ending string to be searched for.
    /// \return True if \p source ends with \p ending string, false otherwise.
    /// \remark Empty string ends only with empty string. Any string ends with empty string.
    constexpr bool endsWith(const std::string_view source, const std::string_view ending)
    {
        if(source.size() < ending.size())
        {
            return false;
        }

        for(auto sourceIterator = source.rbegin(), whatIterator = ending.rbegin();
            whatIterator < ending.rend(); ++sourceIterator, ++whatIterator)
        {
            if(*sourceIterator != *whatIterator)
            {
                return false;
            }
        }

        return true;
    }

    /// Test whether \p source string contains \p content string.
    /// \param source Source string to be tested.
    /// \param content Content string to be searched for.
    /// \return True if \p source contains \p content string, false otherwise.
    /// \remark Empty string contains only empty string. Any string contains empty string.
    constexpr bool contains(const std::string_view source, const std::string_view content)
    {
        if(source.size() < content.size())
        {
            return false;
        }

        return source.find(content) != std::string::npos;
    }

    /// Test whether \p source string contains \p content character.
    /// \param source Source string to be tested.
    /// \param content Content string to be searched for.
    /// \return True if \p source contains \p content string, false otherwise.
    /// \remark Empty string contains only empty string. Any string contains empty string.
    constexpr bool contains(const std::string_view source, char content)
    {
        if(source.empty())
        {
            return false;
        }

        return source.find(content) != std::string::npos;
    }

    /// Test whether \p source string contains any of the characters from the \p content string.
    /// \param source Source string to be tested.
    /// \param ending Content string to be searched for.
    /// \return True if \p source contains any of the characters from the \p content string, false otherwise.
    /// \remark Empty string contains only empty string. Any string contains empty string.
    constexpr bool containsAny(const std::string_view source, const std::string_view content)
    {
        return toolbox::container::containsAny(source, content);
    }

    /// Test whether \p source string contains only characters from \p whitelist string.
    /// \param source Source string to be tested.
    /// \param whitelist Whitelist characters to be searched for.
    /// \return True if \p source contains only characters from the \p whitelist string, false otherwise.
    /// \remark "" contains only ""; "" does not contain not empty whitelist; any source does not contain only "".
    constexpr bool containsOnly(const std::string_view source, const std::string_view whitelist)
    {
        return toolbox::container::containsOnly(source, whitelist);
    }
}