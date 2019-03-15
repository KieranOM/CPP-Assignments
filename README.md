# C/C++ Assignments

- [Assignment 0 (GCD)](#assignment-0-gcd)
- [Assignment 1 (T-Test)](#assignment-1-t-test)
- [Assignment 2 (Trees)](#assignment-2-trees)

## Assignment 0 (GCD)

### Task 1

Create a file `gcd.c` and write the C function `gcd( ...)` which receives two positive integers a and b and returns the greatest common divisor.The application program interface (API)of the function should be as follows:

```c
int gcd(int a, int b);
```

The `main( )` function reads `a` and `b` from the user, then calls `gcd( )` to compute the greatest common divisor, and finally prints the result. The contents of `main()` are available in the `gcd_main.c` file.

### Task 2

The above program can compute correct GCD only for positive integers. Change the program so that it can compute GCD for arbitrary integers.

## Assignment 1 (T-Test)

In statistics, Welch's t-test, or unequal variances t-test, is a two-sample location test which
is used to test the hypothesis that two populations have equal means.

### Task 1

Write a function that discards outliers from measurements that are `< 0.5 * median` and `> 1.5 * median`.

### Task 2

Compute the t-value from the values produced from the function in task 1.

## Assignment 2 (Trees)

A good way to understand the challenges of pointers and memory management is to implement tree data structures. A binary search tree will be implemented using the structure struct Node. 

### Task 1

```c
Node* insertNode(Node *root, int value);
```

This function is used to insert a new node in the tree as a leaf node. The member ‘data’ of the new node is assigned the input ‘value’. During the insertion, a traversal starts from the root of the tree. The traversal follows the right branch if the value of the new node is greater than the value of the currently visited node. Otherwise the traversal follows the
left branch. 

### Task 2

```c
Node* deleteNode(Node *root, int value);
```

This function is used to delete an existing node in the tree. For this question we will restrict there to being unique data values (that is to say there will be no duplicates) for simplicity.

### Task 3

```c
void printSubtree(Node *N);
```

This function is for Inorder printing of the node values. It prints i) the values in the left subtree ii) then the value of the node and iii) finally the values in the right subtree. The function prints the node values in sorted ascending format. 

### Task 4

```c
int countNodes(Node *N);
```

This function returns the number of nodes in the subtree rooted at node N.

### Task 5

```c
void freeSubtree(Node *N);
```

This function deallocates the entire subtree rooted at N. Here you will need to free each node exactly once, so that there are neither double frees nor memory leaks. Note that the tree could be empty, so freeSubtree() should work, but do nothing, as there are no nodes to free.

## Assignment 3 (Optimisation)
In this exercise, you will be optimizing a program for multiplying two squarematrices over GF(2). We have provided a reference implementation of the program.

GF(2) is the Galois field of the two elements: 0 and 1. Arithmetic operations in GF(2) are computed modulo 2, thus resulting in either 0 or 1. A matrix over GF(2) is a binary matrix containing only 0s and 1s. 

We expect a minimum 5 factor speedup with respect to the reference implementation, 140+ speedup factor for full marks.
