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

#include "Stack.h"

/* stack class */
template <typename T>
Stack<T>::Stack()
{
  SetTopPtr(nullptr);
}

/* basic stack methods; Pushes next node onto stack */
template <typename T>
void Stack<T>::Push(T const& input_data) {
  NodeTypes::NextNode* node = new NodeTypes::NextNode(input_data);
  node->SetNextNodePtr(GetTopPtr());
  SetTopPtr(node);
  std::cout << "[Push] " << top << std::endl;
}

/* Pops next node */
template <typename T>
T Stack<T>::Pop() {
  T value = GetTopPtr()->GetData();
  NodeTypes::NextNode* newTop = GetTopPtr()->GetNextNodePtr();
  delete GetTopPtr();
  SetTopPtr(newTop);
  std::cout << "[Pop ] " << top << std::endl;
  return value;
}

/* Returns top value */
template <typename T>
T Stack<T>::Peek() const {
  return (GetTopPtr() != nullptr) ? GetTopPtr()->GetData() : -1;
}

template <typename T>
bool Stack<T>::IsEmpty() {
  return GetTopPtr() == nullptr;
}

/* I always spell these out because it's easier for me to follow. */
template <typename T>
NodeTypes::NextNode* Stack<T>::GetTopPtr() const
{
  return top;
}

template <typename T>
void Stack<T>::SetTopPtr(NodeTypes::NextNode* node)
{
  top = node;
}
