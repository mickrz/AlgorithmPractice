```
zulu@WINDOWS:~/desktop/AlgorithmPractice/BinaryTree$ make
g++ -std=c++14 -O0 -pedantic -Wall  -Wfatal-errors -Wextra  -MMD -MP -g -c  main.cpp -o .objs/main.o
g++ -std=c++14 -O0 -pedantic -Wall  -Wfatal-errors -Wextra  -MMD -MP -g -c  Node.cpp -o .objs/Node.o
g++ -std=c++14 -O0 -pedantic -Wall  -Wfatal-errors -Wextra  -MMD -MP -g -c  Tree.cpp -o .objs/Tree.o
g++ .objs/main.o .objs/Node.o .objs/Tree.o -std=c++14  -o main
zulu@WINDOWS:~/desktop/AlgorithmPractice/BinaryTree$ ./main

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

Delete node value 2 and print new tree layout

       1
     /   \
    5     3
   / \   / \
  4   - 6   7
node: 1, left: 5, right: 3
node: 5, left: 4, right: nullptr
node: 3, left: 6, right: 7

Insert a new mode to bring it back to its former glory...

       1
     /   \
    5     3
   / \   / \
  4   8 6   7
node: 1, left: 5, right: 3
node: 5, left: 4, right: 8
node: 3, left: 6, right: 7

DFT Pre-order traversal...
1 5 4 8 3 6 7
DFT In-order traversal...
4 5 8 1 6 3 7
DFT Post-order traversal...
4 8 5 6 7 3 1
BFS traversal iteratively...
1 5 3 4 8 6 7
BFS traversal recursively...
1 5 3 4 8 6 7
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
1 5 3 4 8 6 7 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 - - - -

=================================================
```
