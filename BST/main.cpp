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
