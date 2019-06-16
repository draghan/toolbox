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

    /// Remove from the \p source string all occurrences of any character given in \p charactersToRemove.
    /// \param source Source string to remove chars from. It won't be changed in any way.
    /// \param charactersToRemove Blacklist in a form of a std::string_view, storing all characters which should be removed.
    /// \return New std::string object based on \p source with removed all unwanted characters.
    inline std::string removeChars(const std::string &source, std::string_view charactersToRemove)
    {
        return toolbox::container::removeElements(source, charactersToRemove);
    }

    /// In-place remove from the \p source string all occurrences of any character given in \p charactersToRemove.
    /// \param source Source string to remove chars from. It will be modified if contains any char from \p charactersToRemove.
    /// \param charactersToRemove Blacklist in a form of a std::string_view, storing all characters which should be removed.
    inline void removeCharsInPlace(std::string &source, std::string_view charactersToRemove)
    {
        toolbox::container::removeElementsInPlace(source, charactersToRemove);
    }

    /// Remove from the \p source string all occurrences of the \p characterToRemove character.
    /// \param source Source string to remove chars from. It won't be changed in any way.
    /// \param characterToRemove Character which should be removed.
    /// \return New std::string object based on \p source with removed all unwanted characters.
    inline std::string removeChar(const std::string &source, char characterToRemove)
    {
        return toolbox::container::removeElement(source, characterToRemove);
    }

    /// In-place remove from the \p source string all occurrences of the \p characterToRemove character.
    /// \param source Source string to remove chars from. It will be modified if contains the \p characterToRemove character.
    /// \param characterToRemove Character which should be removed.
    inline void removeCharInPlace(std::string &source, char characterToRemove)
    {
        toolbox::container::removeElementInPlace(source, characterToRemove);
    }
}