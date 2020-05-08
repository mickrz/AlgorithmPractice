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

/* binary search tree class */
class BinarySearchTree
{
  public:
    BinarySearchTree() {};
    virtual ~BinarySearchTree() = default;

    Node* InsertNode(Node* node, int input_data) {
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

    Node* SearchNode(Node* node, int input_data) {
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
    
    Node* GetMinValue(Node* node) {
      Node* temp = node;
      
      while (temp->GetLeftNodePtr() != nullptr && temp != nullptr) {
        temp = temp->GetLeftNodePtr();
      }
      
      return temp;
    }
    
    Node* DeleteNode(Node* node, int input_data) {
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
    void DFT_InOrder(Node* root)
    {
      if (root == nullptr) {
        return;
      }
      
      DFT_InOrder(root->GetLeftNodePtr());
      std::cout << root->GetData() << " " << std::endl;
      DFT_InOrder(root->GetRightNodePtr());
    }

  private:
    Node* root;
    Node* CreateNode(int input_data) { return new Node(input_data); }

};

int main()
{
  std::cout << "Hello Binary Search Trees!" << std::endl;
  std::cout << "=================================================" << std::endl;
  BinarySearchTree* tree = new BinarySearchTree();
  std::cout << "Inserting nodes 10, 2, 50, 1, 3" << std::endl;
  Node* root = tree->InsertNode(nullptr, 10);
  tree->InsertNode(root, 2);
  tree->InsertNode(root, 50);
  tree->InsertNode(root, 1);
  tree->InsertNode(root, 3);
  tree->DFT_InOrder(root);
  std::cout << "=================================================" << std::endl;
  std::cout << "Searching if node with key 3 exists" << std::endl;
  Node* searchNode = tree->SearchNode(root, 3);
  std::cout << "Found!" << std::endl;
  std::cout << "=================================================" << std::endl;
  std::cout << "Delete node with key 1" << std::endl;
  Node* deleteNode = tree->DeleteNode(root, 1);
  tree->DFT_InOrder(root);
  std::cout << "Delete node with key 2" << std::endl;
  deleteNode = tree->DeleteNode(root, 2);
  tree->DFT_InOrder(root);
  std::cout << "Delete node with key 10" << std::endl;
  deleteNode = tree->DeleteNode(root, 10);
  tree->DFT_InOrder(root);
  std::cout << "=================================================" << std::endl;
  std::cout << "Searching if node with key 3 exists" << std::endl;
  searchNode = tree->SearchNode(root, 3);
  std::cout << "Not Found!" << std::endl;
  std::cout << "=================================================" << std::endl;
}

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

/* binary search tree class */
class BinarySearchTree
{
  public:
    BinarySearchTree() {};
    virtual ~BinarySearchTree() = default;

    Node* InsertNode(Node* node, int input_data) {
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

    Node* SearchNode(Node* node, int input_data) {
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
    
    Node* GetMinValue(Node* node) {
      Node* temp = node;
      
      while (temp->GetLeftNodePtr() != nullptr && temp != nullptr) {
        temp = temp->GetLeftNodePtr();
      }
      
      return temp;
    }
    
    Node* DeleteNode(Node* node, int input_data) {
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
    void DFT_InOrder(Node* root)
    {
      if (root == nullptr) {
        return;
      }
      
      DFT_InOrder(root->GetLeftNodePtr());
      std::cout << root->GetData() << " " << std::endl;
      DFT_InOrder(root->GetRightNodePtr());
    }

  private:
    Node* root;
    Node* CreateNode(int input_data) { return new Node(input_data); }

};

int main()
{
  std::cout << "Hello Binary Search Trees!" << std::endl;
  std::cout << "=================================================" << std::endl;
  BinarySearchTree* tree = new BinarySearchTree();
  std::cout << "Inserting nodes 10, 2, 50, 1, 3" << std::endl;
  Node* root = tree->InsertNode(nullptr, 10);
  tree->InsertNode(root, 2);
  tree->InsertNode(root, 50);
  tree->InsertNode(root, 1);
  tree->InsertNode(root, 3);
  tree->DFT_InOrder(root);
  std::cout << "=================================================" << std::endl;
  std::cout << "Searching if node with key 3 exists" << std::endl;
  Node* searchNode = tree->SearchNode(root, 3);
  std::cout << "Found!" << std::endl;
  std::cout << "=================================================" << std::endl;
  std::cout << "Delete node with key 1" << std::endl;
  Node* deleteNode = tree->DeleteNode(root, 1);
  tree->DFT_InOrder(root);
  std::cout << "Delete node with key 2" << std::endl;
  deleteNode = tree->DeleteNode(root, 2);
  tree->DFT_InOrder(root);
  std::cout << "Delete node with key 10" << std::endl;
  deleteNode = tree->DeleteNode(root, 10);
  tree->DFT_InOrder(root);
  std::cout << "=================================================" << std::endl;
  std::cout << "Searching if node with key 3 exists" << std::endl;
  searchNode = tree->SearchNode(root, 3);
  std::cout << "Not Found!" << std::endl;
  std::cout << "=================================================" << std::endl;
}

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

/* binary search tree class */
class BinarySearchTree
{
  public:
    BinarySearchTree() {};
    virtual ~BinarySearchTree() = default;

    Node* InsertNode(Node* node, int input_data) {
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

    Node* SearchNode(Node* node, int input_data) {
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
    
    Node* GetMinValue(Node* node) {
      Node* temp = node;
      
      while (temp->GetLeftNodePtr() != nullptr && temp != nullptr) {
        temp = temp->GetLeftNodePtr();
      }
      
      return temp;
    }
    
    Node* DeleteNode(Node* node, int input_data) {
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
    void DFT_InOrder(Node* root)
    {
      if (root == nullptr) {
        return;
      }
      
      DFT_InOrder(root->GetLeftNodePtr());
      std::cout << root->GetData() << " " << std::endl;
      DFT_InOrder(root->GetRightNodePtr());
    }

  private:
    Node* root;
    Node* CreateNode(int input_data) { return new Node(input_data); }

};

int main()
{
  std::cout << "Hello Binary Search Trees!" << std::endl;
  std::cout << "=================================================" << std::endl;
  BinarySearchTree* tree = new BinarySearchTree();
  std::cout << "Inserting nodes 10, 2, 50, 1, 3" << std::endl;
  Node* root = tree->InsertNode(nullptr, 10);
  tree->InsertNode(root, 2);
  tree->InsertNode(root, 50);
  tree->InsertNode(root, 1);
  tree->InsertNode(root, 3);
  tree->DFT_InOrder(root);
  std::cout << "=================================================" << std::endl;
  std::cout << "Searching if node with key 3 exists" << std::endl;
  Node* searchNode = tree->SearchNode(root, 3);
  std::cout << "Found!" << std::endl;
  std::cout << "=================================================" << std::endl;
  std::cout << "Delete node with key 1" << std::endl;
  Node* deleteNode = tree->DeleteNode(root, 1);
  tree->DFT_InOrder(root);
  std::cout << "Delete node with key 2" << std::endl;
  deleteNode = tree->DeleteNode(root, 2);
  tree->DFT_InOrder(root);
  std::cout << "Delete node with key 10" << std::endl;
  deleteNode = tree->DeleteNode(root, 10);
  tree->DFT_InOrder(root);
  std::cout << "=================================================" << std::endl;
  std::cout << "Searching if node with key 3 exists" << std::endl;
  searchNode = tree->SearchNode(root, 3);
  std::cout << "Not Found!" << std::endl;
  std::cout << "=================================================" << std::endl;
}

/*
Hello Binary Search Trees!                                                                                                                                                           
=================================================                                                                                                                                    
Inserting nodes 10, 2, 50, 1,3                                                                                                                                                       
1                                                                                                                                                                                    
2                                                                                                                                                                                    
3                                                                                                                                                                                    
10                                                                                                                                                                                   
50                                                                                                                                                                                   
=================================================                                                                                                                                    
Searching if node with key 3 exists                                                                                                                                                  
Found!                                                                                                                                                                               
=================================================                                                                                                                                    
Delete node with key 1                                                                                                                                                               
2                                                                                                                                                                                    
3                                                                                                                                                                                    
10                                                                                                                                                                                   
50                                                                                                                                                                                   
Delete node with key 2                                                                                                                                                               
3                                                                                                                                                                                    
10                                                                                                                                                                                   
50                                                                                                                                                                                   
Delete node with key 10                                                                                                                                                              
3                                                                                                                                                                                    
50                                                                                                                                                                                   
=================================================                                                                                                                                    
Searching if node with key 3 exists                                                                                                                                                  
Not Found!                                                                                                                                                                           
=================================================                                                                                                                                    
*/
