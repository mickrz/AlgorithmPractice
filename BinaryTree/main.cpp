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

int main()
{
  std::cout << "Hello Trees!" << std::endl;
  std::cout << "=================================================" << std::endl;
  Tree* tree = new Tree();
  Node *root = tree->CreateNode(1);
  for (int i = 2; i < 8; i++) {
    tree->InsertNode(root, i);
  }

  /*       1
         /   \
        2     3
       / \   / \
      4   5 6   7
  */
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

  std::cout << "\nDelete node value 2 and print new tree layout" << std::endl;
  tree->DeleteNode(root, 2);
  
  /*       1
         /   \
        5     3
       / \   / \
      4   - 6   7
  */      
  std::cout << "\n       1"
            << "\n     /   \\"
            << "\n    5     3"
            << "\n   / \\   / \\"
            << "\n  4   - 6   7\n";

  
  node = tree->SearchNode(root, 1);
  tree->DumpNodeInfo(node);

  node = tree->SearchNode(root, 5);
  tree->DumpNodeInfo(node);

  node = tree->SearchNode(root, 3);
  tree->DumpNodeInfo(node);

  std::cout << "\nInsert a new mode to bring it back to its former glory..." << std::endl;
  tree->InsertNode(root, 8);

  /*       1
         /   \
        2     7
       / \   / \
      4   5 6   8
  */      
  std::cout << "\n       1"
            << "\n     /   \\"
            << "\n    5     3"
            << "\n   / \\   / \\"
            << "\n  4   8 6   7\n";

  
  node = tree->SearchNode(root, 1);
  tree->DumpNodeInfo(node);

  node = tree->SearchNode(root, 5);
  tree->DumpNodeInfo(node);

  node = tree->SearchNode(root, 3);
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
  std::cout << tree->GetMaximumValue(root) << std::endl;

  std::cout << "Find the minimum value in tree..." << std::endl;
  std::cout << tree->GetMinimumValue(root) << std::endl;

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
