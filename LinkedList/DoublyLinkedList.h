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

#include "Node.h"

/* Technically this is a doubly linked list because there is also a tail 
   pointer */
class LinkedList
{
  public:
    LinkedList();
    virtual ~LinkedList() {};

    /* basic linked list methods;
       appends to head node */
    void Append(int input_data);

    /* Deletes any node */
    void Delete(Node* node);
    
    /* Dumps node values of list */
    void Dump();

    /* I always spell these out because it's easier for me to follow. */
    Node* GetHeadPtr();
    void SetHeadPtr(Node* node);
    Node* GetTailPtr();
    void SetTailPtr(Node* node);
    int GetListLength();

  private:    
    Node* head;
    Node* tail;
    int length;
};

