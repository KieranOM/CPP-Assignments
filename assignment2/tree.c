#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};
typedef struct Node Node;

Node* insertNode(Node *root, int value)
{
	if (root == NULL) {
		// If the node is null, make a new node
		root = (Node*) malloc(sizeof(Node));
		// Check if the memory allocation was successful
		if (root == NULL) {
			printf("Error allocating memory\n");
			exit(-1);
		}
		// Initialise the values
		root->data = value;
		root->left = NULL;
		root->right = NULL;
	} else {
		if (value > root->data) {
			// Go right
			root->right = insertNode(root->right, value);
		}
		else {
			// Go left
			root->left = insertNode(root->left, value);
		} 
	}
	return root;
}

void freeSubtree(Node *N)
{
	// Only free trees that aren't already null
	if (N != NULL) {
		// Recursively free the left tree
		freeSubtree(N->left);
		// Recursively free the right tree
		freeSubtree(N->right);
		// Free the current node after its children
		free (N);
	}
}

void printSubtree(Node *N)
{
	// Only print nodes that aren't null
	if (N != NULL) {
		// In order traversal (left, node, right)
		printSubtree(N->left);
		printf("%d\n", N->data);
		printSubtree(N->right);
	}
}

int countNodes(Node *N)
{
	// Don't count the node if it is null
	if (N == NULL)
		return 0;
	// 1 for this node, then the counts of left and right
	return 1 + countNodes(N->left) + countNodes(N->right);
}	

Node* deleteNode(Node* root, int value)
{
	if (root != NULL) {
		// Find the node to delete from
		if (value < root->data)
			root->left = deleteNode(root->left, value);
		else if (value > root->data)
			root->right = deleteNode(root->right, value);
		else {
			// This is the node to delete the value from

			// Check if trees need moving up
			if (root->left == NULL) {
				// Case where the node has no children, or no left child
				// Move the right tree up
				Node *temp = root->right;
				free (root);
				return temp;
			} else if (root->right == NULL) {
				// Case where there is no right child only
				// Move the left tree up
				Node *temp = root->left;
				free (root);
				return temp;
			}

			// Find the smallest value after this one
			// (left-most value in right sub-tree)
			Node* temp = root->right;
			while (temp->left != NULL)
				temp = temp->left;
			int smallest = temp->data;

			// Move the smallest value into current node
			root->data = smallest;

			// Delete this value from the node it came from
			root->right = deleteNode(temp, smallest);
		}
	} else {
		printf("Value %d not found in tree\n", value);
	}
  	return root; // parent node can update reference
}

int main()
{
	Node *root=NULL;
	
    root=insertNode(root, 14);
	root=insertNode(root, 12);
	root=insertNode(root, 6);
	root=insertNode(root, 17);
	root=insertNode(root, 8);
   	printSubtree(root);
	printf("\n");
	root=deleteNode(root,14);
	root=deleteNode(root,8);
   	printSubtree(root);
	freeSubtree(root);
	root = NULL;
	printf("Number of nodes=%d\n", countNodes(root));
	return 0;
}