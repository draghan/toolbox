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

#include "../containers/remove.hpp"

#include <string>
#include <string_view>

namespace toolbox::string
{
    inline std::string removeCharsFromString(const std::string& source, const std::string& charactersToRemove)
    {
        return toolbox::container::removeElements(source, charactersToRemove);
    }

    inline std::string removeCharFromString(const std::string& source, char characterToRemove)
    {
        return toolbox::container::removeElement(source, characterToRemove);
    }

    inline void removeCharFromStringInPlace(std::string &source, char characterToRemove)
    {
        toolbox::container::removeElementInPlace(source, characterToRemove);
    }

    inline void removeCharsFromStringInPlace(std::string &source, std::string_view charactersToRemove)
    {
        toolbox::container::removeElementsInPlace(source, charactersToRemove);
    }
}