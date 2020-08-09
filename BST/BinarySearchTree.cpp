/*
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

#include "BinarySearchTree.h"

/* binary search tree class */
BinarySearchTree::BinarySearchTree()
{
  root = nullptr;
};

Node* BinarySearchTree::InsertNode(Node* node, int input_data) {
  if (node == nullptr) {
    node = CreateNode(input_data);
  }    
  else if (input_data < node->GetData()) {
    node->SetLeftNodePtr(InsertNode(node->GetLeftNodePtr(), input_data));
  }
  else if (input_data > node->GetData()) {
    node->SetRightNodePtr(InsertNode(node->GetRightNodePtr(), input_data));
  }
  return node;
}

Node* BinarySearchTree::SearchNode(Node* node, int input_data) {
  if (node == nullptr || node->GetData() == input_data) {
    return node;
  }
  else if (input_data < node->GetData()) {
    return SearchNode(node->GetLeftNodePtr(), input_data);
  }
  else if (input_data > node->GetData()) {
    return SearchNode(node->GetRightNodePtr(), input_data);
  }
}

Node* BinarySearchTree::GetMinValue(Node* node) {
  Node* temp = node;

  while (temp->GetLeftNodePtr() != nullptr && temp != nullptr) {
    temp = temp->GetLeftNodePtr();
  }

  return temp;
}

Node* BinarySearchTree::DeleteNode(Node* node, int input_data) {
  if (node == nullptr) {
    return node;
  }

  if (input_data < node->GetData()) {
    node->SetLeftNodePtr(DeleteNode(node->GetLeftNodePtr(), input_data));
  }
  else if (input_data > node->GetData()) {
    node->SetRightNodePtr(DeleteNode(node->GetRightNodePtr(), input_data));
  }
  else {
    // node with 0 or 1 child
    if (node->GetLeftNodePtr() == nullptr) {
      Node* temp = node->GetRightNodePtr();
      delete node;
      return temp;
    }
    else if (node->GetRightNodePtr() == nullptr) {
      Node* temp = node->GetLeftNodePtr();
      delete node;
      return temp;
    }

    Node* temp = GetMinValue(node->GetRightNodePtr());

    node->SetData(temp->GetData());
    node->SetRightNodePtr(DeleteNode(node->GetRightNodePtr(), temp->GetData()));
  }
  return node;
}

// DFT (in-order traversal)
void BinarySearchTree::DFT_InOrder(Node* root)
{
  if (root == nullptr) {
    return;
  }

  DFT_InOrder(root->GetLeftNodePtr());
  std::cout << root->GetData() << " " << std::endl;
  DFT_InOrder(root->GetRightNodePtr());
}

Node* CreateNode(int input_data)
{
  return new Node(input_data);
}