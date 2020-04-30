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

#include <iostream>
#include <random>
#include <sstream>

#include <queue>

/* tree node */
class Node
{
  public:
    Node(int input_data) { 
      data = input_data;
      left = nullptr;
      right = nullptr;
    }
    virtual ~Node() = default;

    /* I always spell these out because it's easier for me to follow. */
    int GetData() { return data; }
    void SetData(int input_data) { data = input_data; }
    void SetLeftNodePtr(Node* node) { left = node; }
    Node* GetLeftNodePtr() { return left; }
    void SetRightNodePtr(Node* node) { right = node; }
    Node* GetRightNodePtr() { return right; }

  private:
    int data;
    Node* left;
    Node* right;
};

/* tree class */
class Tree
{
  public:
    Tree() {};
    virtual ~Tree() = default;
    Node* CreateNode(int input_data) { return new Node(input_data); }
    void InsertNode(Node* root, int input_data) {
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
    Node* SearchNode(Node* root, int data) {
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
    
    void SetExtremeRightToNull(Node* root, Node* extremeRight) {
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
    
    void DeleteNode(Node* root, int input_data) {
      std::queue<Node*> q;
      Node* node = SearchNode(root, input_data);
      if (node != nullptr) {
        q.push(root);
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
        SetExtremeRightToNull(root, temp);
        node->SetData(keyAtDeepestRight);
      }
    }

    // DFT (pre-order traversal)
    void DFT_PreOrder(Node* root)
    {
      if (root == nullptr) {
        return;
      }
      
      std::cout << root->GetData() << " ";
      DFT_PreOrder(root->GetLeftNodePtr());
      DFT_PreOrder(root->GetRightNodePtr());
    }
  
    // DFT (in-order traversal)
    void DFT_InOrder(Node* root)
    {
      if (root == nullptr) {
        return;
      }
      
      DFT_InOrder(root->GetLeftNodePtr());
      std::cout << root->GetData() << " ";
      DFT_InOrder(root->GetRightNodePtr());
    }

    // DFT (post-order traversal)
    void DFT_PostOrder(Node* root)
    {
      if (root == nullptr) {
        return;
      }
      
      DFT_PostOrder(root->GetLeftNodePtr());
      DFT_PostOrder(root->GetRightNodePtr());
      std::cout << root->GetData() << " ";
    }
    
    
    // BFS
    void BFS(Node* root)
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
    std::string BFS_Recursive(Node* root, int level)
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
    
    void BFS_DumpTree(Node* root, int height)
    {
      std::stringstream bfs_order;
      for (int i = 1; i < 1 + height; i++) {
        bfs_order << BFS_Recursive(root, i) << " ";
      }
      
      std::cout << bfs_order.str() << std::endl;
    }

    int GetMaximumValue(Node* root, int current_max)
    {
      if (root == nullptr) {
        return current_max;
      }
      
      if (root->GetData() > current_max) {
        current_max = root->GetData();
      }
      
      GetMaximumValue(root->GetLeftNodePtr(), current_max);
      GetMaximumValue(root->GetRightNodePtr(), current_max);      
    }

    int GetMinimumValue(Node* root, int current_min)
    {
      if (root == nullptr) {
        return current_min;
      }
      
      if (root->GetData() < current_min) {
        current_min = root->GetData();
      }
      
      GetMinimumValue(root->GetLeftNodePtr(), current_min);
      GetMinimumValue(root->GetRightNodePtr(), current_min);      
    }

    int GetHeight(Node* root)
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

    int GetNodeCount(Node* root)
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
    
    int GetLeafCount(Node* root)
    {
      if (root == nullptr) {
        return 0;
      }
      
      if (root->GetLeftNodePtr() == nullptr && root->GetRightNodePtr() == nullptr) {
          return 1;
      }
      
      return GetLeafCount(root->GetLeftNodePtr()) + GetLeafCount(root->GetRightNodePtr());
    }
    
    void DumpNodeInfo(Node* node) {
      if (node != nullptr) {
        Node* left = node->GetLeftNodePtr();
        Node* right = node->GetRightNodePtr(); 
        std::stringstream output_data;
        output_data << "node: " << node->GetData()
                    << ", left: ";
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
  
  private:
    Node* root;
};

int main()
{
  std::cout << "Hello Trees!" << std::endl;
  std::cout << "=================================================" << std::endl;
  Tree* tree = new Tree();
  Node *root = tree->CreateNode(1);
  for (int i = 2; i < 8; i++) {
    tree->InsertNode(root, i);
  }

  //       1
  //     /   \
  //    2     3
  //   / \   / \
  //  4   5 6   7
  std::cout << "\n       1"
            << "\n     /   \\"
            << "\n    2     3"
            << "\n   / \\   / \\"
            << "\n  4   5 6   7";
  
  std::cout << "\n\nA perfect binary tree (& full since all children have"
            << " 0/2 children & complete since every level filled"
            << std::endl;
  Node* node = tree->SearchNode(root, 1);
  tree->DumpNodeInfo(node);

  node = tree->SearchNode(root, 2);
  tree->DumpNodeInfo(node);

  node = tree->SearchNode(root, 3);
  tree->DumpNodeInfo(node);
  
  std::cout << "\nSearch for a node value 8 that doesn't exist..." << std::endl;
  node = tree->SearchNode(root, 8);
  tree->DumpNodeInfo(node);

  std::cout << "\nDelete a node and print new tree layout" << std::endl;
  tree->DeleteNode(root, 3);
  
  //       1
  //     /   \
  //    2     7
  //   / \   / \
  //  4   5 6  - 
  std::cout << "\n       1"
            << "\n     /   \\"
            << "\n    2     7"
            << "\n   / \\   / \\"
            << "\n  4   5 6   -\n";

  
  node = tree->SearchNode(root, 1);
  tree->DumpNodeInfo(node);

  node = tree->SearchNode(root, 2);
  tree->DumpNodeInfo(node);

  node = tree->SearchNode(root, 7);
  tree->DumpNodeInfo(node);

  std::cout << "\nInsert a new mode to bring it back to its former glory..." << std::endl;
  tree->InsertNode(root, 8);

  //       1
  //     /   \
  //    2     7
  //   / \   / \
  //  4   5 6   8 
  std::cout << "\n       1"
            << "\n     /   \\"
            << "\n    2     7"
            << "\n   / \\   / \\"
            << "\n  4   5 6   8\n";

  
  node = tree->SearchNode(root, 1);
  tree->DumpNodeInfo(node);

  node = tree->SearchNode(root, 2);
  tree->DumpNodeInfo(node);

  node = tree->SearchNode(root, 7);
  tree->DumpNodeInfo(node);

  std::cout << "\nDFT Pre-order traversal..." << std::endl;
  tree->DFT_PreOrder(root);

  std::cout << "\nDFT In-order traversal..." << std::endl;
  tree->DFT_InOrder(root); 

  std::cout << "\nDFT Post-order traversal..." << std::endl;
  tree->DFT_PostOrder(root);

  std::cout << "\nBFS traversal iteratively..." << std::endl;
  tree->BFS(root);

  std::cout << "BFS traversal recursively..." << std::endl;
  tree->BFS_DumpTree(root, 3);
  
  std::cout << "Find the maximum value in tree..." << std::endl;
  std::cout << tree->GetMaximumValue(root, root->GetData()) << std::endl;

  std::cout << "Find the minimum value in tree..." << std::endl;
  std::cout << tree->GetMinimumValue(root, root->GetData()) << std::endl;

  std::cout << "Find the height of tree..." << std::endl;
  std::cout << tree->GetHeight(root) << std::endl;

  std::cout << "Inserting more nodes..." << std::endl;
  for (int i = 9; i < 61; i++) {
    tree->InsertNode(root, i);
  }
  std::cout << "Find the height of tree..." << std::endl;
  std::cout << tree->GetHeight(root) << std::endl;
  
  std::cout << "Find the number of nodes of tree..." << std::endl;
  std::cout << tree->GetNodeCount(root) << std::endl;

  std::cout << "Find the number of leafs of tree..." << std::endl;
  std::cout << tree->GetLeafCount(root) << std::endl;

  std::cout << "BFS traversal recursively..." << std::endl;
  tree->BFS_DumpTree(root, 6);
  std::cout << "\n=================================================" << std::endl;
  return 0;
}

/*
Hello Trees!                                                                                                                                                                       
=================================================     

       1                                                                                                                                                                             
     /   \                                                                                                                                                                           
    2     3                                                                                                                                                                          
   / \   / \                                                                                                                                                                         
  4   5 6   7                                                                                                                                                                        

A perfect binary tree (& full since all children have 0/2 children & complete since every level filled                                                                               
node: 1, left: 2, right: 3                                                                                                                                                           
node: 2, left: 4, right: 5                                                                                                                                                           
node: 3, left: 6, right: 7                                                                                                                                                           

Search for a node value 8 that doesn't exist...                                                                                                                                      
Node not found!                                                                                                                                                                      

Delete a node and print new tree layout                                                                                                                                              

       1                                                                                                                                                                             
     /   \                                                                                                                                                                           
    2     7                                                                                                                                                                          
   / \   / \                                                                                                                                                                         
  4   5 6   -                                                                                                                                                                        
node: 1, left: 2, right: 7                                                                                                                                                           
node: 2, left: 4, right: 5                                                                                                                                                           
node: 7, left: 6, right: nullptr                                                                                                                                                     

Insert a new mode to bring it back to its former glory...                                                                                                                            

       1                                                                                                                                                                             
     /   \                                                                                                                                                                           
    2     7                                                                                                                                                                          
   / \   / \                                                                                                                                                                         
  4   5 6   8                                                                                                                                                                        
node: 1, left: 2, right: 7                                                                                                                                                           
node: 2, left: 4, right: 5                                                                                                                                                           
node: 7, left: 6, right: 8                                                                                                                                                           
DFT Pre-order traversal...                                                                                                                                                               
1 2 4 5 7 6 8                                                                                                                                                                        
DFT In-order traversal...                                                                                                                                                                
4 2 5 1 6 7 8                                                                                                                                                                        
DFT Post-order traversal...                                                                                                                                                              
4 5 2 6 8 7 1                                                                                                                                                                        
BFS traversal iteratively...                                                                                                                                                       
1 2 7 4 5 6 8                                                                                                                                                                      
BFS traversal recursively...                                                                                                                                                       
1 2 7 4 5 6 8      
Find the maximum value in tree...                                                                                                                                                  
8
Find the minimum value in tree...                                                                                                                                                  
1
Find the height of tree...                                                                                                                                                         
3                                                                                                                                                                                  
Inserting more nodes...                                                                                                                                                            
Find the height of tree...                                                                                                                                                         
6                                                                                                                                                                                  
Find the number of nodes of tree...                                                                                                                                                
59
Find the number of leafs of tree...                                                                                                                                                
30                                                                                                                                                                                 
BFS traversal recursively...                                                                                                                                                       
1 2 7 4 5 6 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 - - - -   
=================================================
*/
