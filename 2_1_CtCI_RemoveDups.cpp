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

// Remove any nodes with a repeated value
LinkedList* RemoveDups(LinkedList* list)
{
  std::cout << "2.1: Remove Dups:" << std::endl;
  std::bitset<10> bits{0};
  Node* node = list->GetHeadPtr();
  while (node != nullptr) {
    int val = node->GetCurrentData();
    Node* nextNode = node->GetNextNodePtr();
    if (!bits.test(val-1)) {
        bits.set(val-1);
        list->Dump();
    }
    else {
        std::cout << "Delete " << std::to_string(val) << std::endl;
        list->Delete(node);
    }
    node = nextNode;
  }
  list->Dump();
  return list;
}


/**
Time Complexity/Space Complexity: Iterating through the list once is O(n)
 where n is the number of nodes. If the bitset is considered, then space
 complexity takes O(n+m) where m is the number of bits which is negligible.

2.1: Remove Dups:
The list randomly generated:
5 <-> 1 <-> 2 <-> 3 <-> 4 <-> (2) <-> 3 <-> 3 <-> 3 <-> 1
Delete 2
5 <-> 1 <-> 2 <-> 3 <-> 4 <-> (3) <-> 3 <-> 3 <-> 1
Delete 3
5 <-> 1 <-> 2 <-> 3 <-> 4 <-> (3) <-> 3 <-> 1
Delete 3
5 <-> 1 <-> 2 <-> 3 <-> 4 <-> (3) <-> 1
Delete 3
5 <-> 1 <-> 2 <-> 3 <-> 4 <-> (1)
Delete 1
Final list with no duplicates:
5 <-> 1 <-> 2 <-> 3 <-> 4
*/