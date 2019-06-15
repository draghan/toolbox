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

#include <string>
#include <algorithm>

namespace toolbox::container
{

    template <class SourceContainer, class BlacklistContainer>
    constexpr SourceContainer removeElements(const SourceContainer& source, const BlacklistContainer& elementsToRemove)
    {
        SourceContainer wantedElements;
        std::copy_if(source.cbegin(), source.cend(), std::back_inserter(wantedElements), [&elementsToRemove](
                const auto currentElement)
        {
            return std::find(elementsToRemove.cbegin(), elementsToRemove.cend(), currentElement) == elementsToRemove.end();
        });
        return wantedElements;
    }

    template <class SourceContainer>
    constexpr SourceContainer removeElement(const SourceContainer& source, const typename SourceContainer::value_type & elementToRemove)
    {
        SourceContainer wantedElements;
        std::copy_if(source.cbegin(), source.cend(), std::back_inserter(wantedElements), [&elementToRemove](
                const auto currentElement)
        {
            return currentElement != elementToRemove;
        });
        return wantedElements;
    }

    template <class SourceContainer>
    constexpr void removeElementInPlace(SourceContainer& source, const typename SourceContainer::value_type & elementToRemove)
    {
        source.erase(std::remove(source.begin(), source.end(), elementToRemove), source.end());
    }

    template <class SourceContainer, class BlacklistContainer>
    constexpr void removeElementsInPlace(SourceContainer& source, const BlacklistContainer& elementsToRemove)
    {
        source.erase(std::remove_if(source.begin(), source.end(),
                                    [elementsToRemove](const auto currentElement)
                                    {
                                        return std::find(elementsToRemove.cbegin(), elementsToRemove.cend(), currentElement) != elementsToRemove.cend();
                                    }), source.end());
    }

}