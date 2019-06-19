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

#include <algorithm>

namespace toolbox::container
{

    /// Test whether \p source collection contains any of the elements from \p whitelist collection.
    /// \tparam SourceContainer Source container type.
    /// \tparam WhitelistContainer Whitelist container type.
    /// \param source Source container to be tested.
    /// \param whitelist Whitelist elements to be searched for.
    /// \return True if \p source contains only elements from the \p whitelist collection, false otherwise.
    /// \remark containsAny(empty, empty) == true
    /// \remark containsAny(not_empty, empty) == true
    /// \remark containsAny(empty, not_empty) == false
    template <class SourceContainer, class WhitelistContainer>
    constexpr bool containsAny(const SourceContainer& source, const WhitelistContainer& whitelist)
    {
        if (whitelist.empty() && source.empty())
        {
            return true;
        }

        if (whitelist.empty())
        {
            return false;
        }

        if (source.empty())
        {
            return false;
        }

        return std::find_first_of(source.cbegin(), source.cend(), whitelist.cbegin(), whitelist.cend()) != source.cend();
    }

    /// Test whether \p source collection contains \p element.
    /// \tparam SourceContainer Source container type.
    /// \tparam ElementType Search element type.
    /// \param source Source container to be tested.
    /// \param element Value to be searched for.
    /// \return True if element is part of the \p source collection, false otherwise.
    /// \remark contains(empty, element) == false
    template <class SourceContainer, class ElementType>
    constexpr bool contains(const SourceContainer& source, const ElementType& element)
    {
        return std::find(source.cbegin(), source.cend(), element) != source.cend();
    }


    /// Test whether \p source collection contains only elements from \p whitelist collection.
    /// \tparam SourceContainer Source container type.
    /// \tparam WhitelistContainer Whitelist container type.
    /// \param source Source container to be tested.
    /// \param whitelist Whitelist elements to be searched for.
    /// \return True if \p source contains only elements from the \p whitelist collection, false otherwise.
    /// \remark containsOnly(empty, empty) == true
    /// \remark containsOnly(not_empty, empty) == false
    /// \remark containsOnly(empty, not_empty) == false
    template <class SourceContainer, class WhitelistContainer>
    constexpr bool containsOnly(const SourceContainer& source, const WhitelistContainer& whitelist)
    {
        if (whitelist.empty() && source.empty())
        {
            return true;
        }

        if (whitelist.empty())
        {
            return false;
        }

        if (source.empty())
        {
            return false;
        }

        for (const auto &elem : source)
        {
            if(!contains(whitelist, elem))
            {
                return false;
            }
        }

        return true;
    }
}