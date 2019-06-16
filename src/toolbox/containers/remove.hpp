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

    /// Remove from the \p source container all occurrences of any elements given in \p elementsToRemove.
    /// \tparam SourceContainer Some container type, should provide cbegin(), cend(), compatibility with std::back_inserter.
    /// \tparam BlacklistContainer Some container type, should provide cbegin(), cend().
    /// \param source Source container to remove elements from. It won't be changed in any way.
    /// \param elementsToRemove Blacklist in a form of a \p BlacklistContainer, storing all elements which should be removed.
    /// \return New \p SourceContainer object based on \p source with removed all unwanted elements.
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

    /// Remove from the \p source container all occurrences of the element given in \p elementToRemove.
    /// \tparam SourceContainer Some container type, should provide cbegin(), cend(), compatibility with std::back_inserter.
    /// \tparam Element An element type, should be compatible with elements in container and provides != operator.
    /// \param source Source container to remove elements from. It won't be changed in any way.
    /// \param elementToRemove An element which should be removed.
    /// \return New \p SourceContainer object based on \p source with removed all unwanted elements.
    template <class SourceContainer, class Element>
    constexpr SourceContainer removeElement(const SourceContainer& source, const Element& elementToRemove)
    {
        SourceContainer wantedElements;
        std::copy_if(source.cbegin(), source.cend(), std::back_inserter(wantedElements), [&elementToRemove](
                const auto currentElement)
        {
            return currentElement != elementToRemove;
        });
        return wantedElements;
    }

    /// Remove in-place from the \p source container all occurrences of the element given in \p elementToRemove.
    /// \tparam SourceContainer Some container type, should provide begin(), end().
    /// \tparam Element An element type, should be compatible with elements in container and provides == operator.
    /// \param source Source container to remove elements from. It will be modified if contains the \p elementToRemove.
    /// \param elementToRemove An element which should be removed.
    template <class SourceContainer, class Element>
    constexpr void removeElementInPlace(SourceContainer& source, const Element& elementToRemove)
    {
        source.erase(std::remove(source.begin(), source.end(), elementToRemove), source.end());
    }

    /// Remove in-place from the \p source container all occurrences of of any elements given in \p elementsToRemove.
    /// \tparam SourceContainer Some container type, should provide begin(), end().
    /// \tparam BlacklistContainer Some container type, should provide cbegin(), cend().
    /// \param source Source container to remove elements from. It will be modified if contains any the \p elementsToRemove.
    /// \param elementsToRemove Blacklist in a form of a \p BlacklistContainer, storing all elements which should be removed.
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