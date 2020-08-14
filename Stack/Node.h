/*
MIT License

Copyright (c) 2020 Mike Rzucidlo

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

#include <iostream>
#include <random>
#include <sstream>

namespace NodeTypes {
  template <typename T>
  /* stack node */
  class NextNode
  {
    public:
      NextNode(T const& input_data) : data(input_data), next(nullptr) {};
      virtual ~NextNode() = default;
      
      /* I always spell these out because it's easier for me to follow. */
      T GetData() const
      {
        return data;
      };

      void SetNextNodePtr(NextNode* node)
      {
        next = node;
      };
            
      NextNode* GetNextNodePtr() const
      {
        return next;
      };
      
      // An overloaded operator<<, allowing us to print the node via `cout<<`:
      template <typename U>
      friend std::ostream& operator<<(std::ostream& os, NextNode<U>* node)
      {
        NextNode<U>* currentNode = node;

        while (currentNode != nullptr) {
          os << currentNode->GetData() << " ";
          currentNode = currentNode->GetNextNodePtr();
        }
        return os;;
      }

    private:
      T data;
      NextNode* next;
  };
}
