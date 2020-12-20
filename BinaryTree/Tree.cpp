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

#include "Tree.h"

/* tree class */
Tree::Tree()
{
  root = nullptr; 
}

Node* Tree::CreateNode(int input_data)
{
  return new Node(input_data);
}

void Tree::InsertNode(Node* root, int input_data)
{
  Node* node = CreateNode(input_data);

  std::queue<Node*> q;
  q.push(root);

  while (!q.empty()) {
    Node* temp = q.front();
    q.pop();

    if (temp->GetLeftNodePtr() == nullptr) {
      temp->SetLeftNodePtr(node);
      return;
    }
    else {
      q.push(temp->GetLeftNodePtr());
    }

    if (temp->GetRightNodePtr() == nullptr) {
      temp->SetRightNodePtr(node);
      return;
    }
    else {
      q.push(temp->GetRightNodePtr());
    }
  }
}
    
// BFS
Node* Tree::SearchNode(Node* root, int data)
{
  if (root == nullptr) {
    return nullptr;
  }

  std::queue<Node*> q;
  Node* node = nullptr;

  q.push(root);

  while (!q.empty()) {
    Node* temp = q.front();
    q.pop();

    if (temp->GetData() == data) {
      node = temp;
    }

    if (temp->GetLeftNodePtr() != nullptr) {
      q.push(temp->GetLeftNodePtr());
    }

    if (temp->GetRightNodePtr() != nullptr) {
      q.push(temp->GetRightNodePtr());
    }
  }
  return node;
}

void Tree::SetExtremeRightToNull(Node* root, Node* extremeRight)
{
  std::queue<Node*> q;
  q.push(root);
  Node* temp = nullptr;
  while (!q.empty()) {
    temp = q.front();
    q.pop();

    if (temp->GetLeftNodePtr() != nullptr) {
      if (temp->GetLeftNodePtr() == extremeRight) {
        temp->SetLeftNodePtr(nullptr);
        return;
      }
      else {
        q.push(temp->GetLeftNodePtr());
      }
    }

    if (temp->GetRightNodePtr() != nullptr) {
      if (temp->GetRightNodePtr() == extremeRight) {
        temp->SetRightNodePtr(nullptr);
        return;
      }
      else {
        q.push(temp->GetRightNodePtr());
      }
    }
  }
}

void Tree::DeleteNode(Node* root, int input_data)
{
  std::queue<Node*> q;
  Node* node = SearchNode(root, input_data);
  if (node != nullptr) {
    q.push(node);
    Node* temp = nullptr;

    while (!q.empty()) {
      temp = q.front();
      q.pop();

      if (temp->GetLeftNodePtr() != nullptr) {
        q.push(temp->GetLeftNodePtr());
      }

      if (temp->GetRightNodePtr() != nullptr) {
        q.push(temp->GetRightNodePtr());
      }
    }

    int keyAtDeepestRight = temp->GetData();
    SetExtremeRightToNull(node, temp);
    node->SetData(keyAtDeepestRight);
  }
}

// DFT (pre-order traversal)
void Tree::DFT_PreOrder(Node* root)
{
  if (root == nullptr) {
    return;
  }

  std::cout << root->GetData() << " ";
  DFT_PreOrder(root->GetLeftNodePtr());
  DFT_PreOrder(root->GetRightNodePtr());
}

// DFT (in-order traversal)
void Tree::DFT_InOrder(Node* root)
{
  if (root == nullptr) {
    return;
  }

  DFT_InOrder(root->GetLeftNodePtr());
  std::cout << root->GetData() << " ";
  DFT_InOrder(root->GetRightNodePtr());
}

// DFT (post-order traversal)
void Tree::DFT_PostOrder(Node* root)
{
  if (root == nullptr) {
    return;
  }
      
  DFT_PostOrder(root->GetLeftNodePtr());
  DFT_PostOrder(root->GetRightNodePtr());
  std::cout << root->GetData() << " ";
}
    
// BFS
void Tree::BFS(Node* root)
{
  std::queue<Node*> q;
  q.push(root);
  Node* temp = nullptr;
  std::stringstream bfs_order;
      
  while (!q.empty()) {
    temp = q.front();
    q.pop();
    bfs_order << temp->GetData() << " ";
    if (temp->GetLeftNodePtr() != nullptr) {
      q.push(temp->GetLeftNodePtr());
    }

    if (temp->GetRightNodePtr() != nullptr) {
      q.push(temp->GetRightNodePtr());
    }
  }    
  std::cout << bfs_order.str() << std::endl;
}

// BFS Recursive
std::string Tree::BFS_Recursive(Node* root, int level)
{
  if (root == nullptr) {
    return "-";
  }  
       
  if (level == 1) {
    return std::to_string(root->GetData());
  }

  if (level > 1) {
    return BFS_Recursive(root->GetLeftNodePtr(), level - 1) + " " + BFS_Recursive(root->GetRightNodePtr(), level - 1);
  }

  return "";  
}

void Tree::BFS_DumpTree(Node* root, int height)
{
  std::stringstream bfs_order;
  for (int i = 1; i < 1 + height; i++) {
    bfs_order << BFS_Recursive(root, i) << " ";
  }

  std::cout << bfs_order.str() << std::endl;
}

int Tree::GetMaximumValue(Node* root)
{
  if (root == nullptr) {
    return -1;
  }

  int max_val = root->GetData();
  int left_val = GetMaximumValue(root->GetLeftNodePtr());
  int right_val = GetMaximumValue(root->GetRightNodePtr());

  if (left_val > max_val) {
    max_val = left_val;
  }

  if (right_val > max_val) {
    max_val = right_val;
  }

  return max_val;
}

int Tree::GetMinimumValue(Node* root)
{
  if (root == nullptr) {
    return std::numeric_limits<int>::max();
  }

  int min_val = root->GetData();
  int left_val = GetMinimumValue(root->GetLeftNodePtr());
  int right_val = GetMinimumValue(root->GetRightNodePtr());

  if (left_val < min_val) {
    min_val = left_val;
  }

  if (right_val < min_val) {
    min_val = right_val;
  }

  return min_val;
}

int Tree::GetHeight(Node* root)
{
  if (root == nullptr) {
    return 0;
  }

  int left = GetHeight(root->GetLeftNodePtr());
  int right = GetHeight(root->GetRightNodePtr());      

  if (left > right) {
    return left + 1;          
  }
  return right + 1;
}

int Tree::GetNodeCount(Node* root)
{
  if (root == nullptr) {
    return 0;
  }

  int node_count = 1;        

  if (root->GetLeftNodePtr() != nullptr) {
    node_count += GetNodeCount(root->GetLeftNodePtr());
  }

  if ( root->GetRightNodePtr() != nullptr) {
    node_count += GetNodeCount(root->GetRightNodePtr());
  }
  return node_count;
}

int Tree::GetLeafCount(Node* root)
{
  if (root == nullptr) {
    return 0;
  }

  if (root->GetLeftNodePtr() == nullptr && root->GetRightNodePtr() == nullptr) {
    return 1;
  }

  return GetLeafCount(root->GetLeftNodePtr()) + GetLeafCount(root->GetRightNodePtr());
}

void Tree::DumpNodeInfo(Node* node) {
  if (node != nullptr) {
    Node* left = node->GetLeftNodePtr();
    Node* right = node->GetRightNodePtr(); 
    std::stringstream output_data;
    output_data << "node: " << node->GetData() << ", left: ";
    if (left != nullptr) {
      output_data << left->GetData();    
    } 
    else {
      output_data << "nullptr";
    }
        
    output_data << ", right: ";
    if (right != nullptr) {
      output_data << right->GetData();    
    } 
    else {
      output_data << "nullptr";
    }

    std::cout << output_data.str() << std::endl;
  }
  else {
    std::cout << "Node not found!" << std::endl;
  }
}
