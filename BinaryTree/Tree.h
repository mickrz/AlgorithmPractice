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
#include <limits>

/* tree class */
class Tree
{
  public:
    Tree();
    virtual ~Tree() = default;
    Node* CreateNode(int input_data);
    
    void InsertNode(Node* root, int input_data);
    // BFS
    Node* SearchNode(Node* root, int data);
    
    void SetExtremeRightToNull(Node* root, Node* extremeRight);
    
    void DeleteNode(Node* root, int input_data);
    
    // DFT (pre-order traversal)
    void DFT_PreOrder(Node* root);
  
    // DFT (in-order traversal)
    void DFT_InOrder(Node* root);

    // DFT (post-order traversal)
    void DFT_PostOrder(Node* root);
    
    // BFS
    void BFS(Node* root);

    // BFS Recursive
    std::string BFS_Recursive(Node* root, int level);

    void BFS_DumpTree(Node* root, int height);

    int GetMaximumValue(Node* root);

    int GetMinimumValue(Node* root);

    int GetHeight(Node* root);

    int GetNodeCount(Node* root);
    
    int GetLeafCount(Node* root);
    
    void DumpNodeInfo(Node* node);
  
  private:
    Node* root;
};

