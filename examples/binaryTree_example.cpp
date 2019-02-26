// https://www.tutorialspoint.com/data_structures_algorithms/tree_traversal_in_c.htm
// Binary tree traversal: post-, pre- and in-order traversal
// The left child always holds a number smaller than that of the parent node; the right
// child always hold a value equal to or larger than that of the parent node
#include <iostream>
using namespace std;

// Object for nodes: the value held by the node, and two pointers: one for\
// its left child and another for its right child
struct node {
   int data; 
   struct node *leftChild;
   struct node *rightChild;
};

// Create the first node a.k.a. the root
struct node *root = NULL;

// Insert a node in the tree. To do so, keep in mind that any left child holds a value\
// smaller than that of its parent and any right child holds a value equal to or larger\
// than that of its parent
void insert (int data) {
   // Create a new node which will be inserted in the tree
   struct node *tempNode = (struct node*) malloc(sizeof(struct node));
   // The node that we currently looking at (just declare the pointer for now)
   struct node *current;
   // Pointer to the parent of a given node (just declare the pointer for now)
   struct node *parent;
   // Set the data held by the new node (the argument of the function)
   tempNode->data = data;
   // The new node has neither left or right child at first
   tempNode->leftChild = NULL;
   tempNode->rightChild = NULL;

   // No root means empty tree
   if (root == NULL) {
	  root = tempNode;
   } 
   // Tree is not empty
   else {
	  // Node currently being looked at (start at the root)
	  current = root;
	  // The root has no parent node
	  parent = NULL;

	  // Keep looping until the function returns, i.e., the node was inserted
	  while (1) { 
	  	// The parent node is the node currently being looked at (so that we\
	  	// can keep moving down to the children nodes until we find where to\
	  	// insert the new node)
	  	parent = current;
		 
		// If the new node holds a lower value than the parent node, then it will\
	  	// be inserted in the left subtree
		 if (data < parent->data) {
		 	// Move down to the left child
			current = current->leftChild;
			// If the node does not have a left child, insert the new node as the\
			// left child
			if (current == NULL) {
			   parent->leftChild = tempNode;
			   return;
			}
		 }  
		 // If the new node holds a value larger or equal to that of the parent, then\
		 // it will be inserted in the right subtree
		 else {
		 	// Move down to the right child
			current = current->rightChild;
			// If the node does not have a right child, insert the new node as the\
			// right child
			if (current == NULL) {
			   parent->rightChild = tempNode;
			   return;
			}
		 }
	  }            
   }
}

// Search for a given number in the tree
struct node* search (int data) {
	// Pointer for the node we are currently looking at (start at the root)
   struct node *current = root;
   cout << "Visiting elements: " << endl;

   // Keep looking in the tree until either the number is found or the tree\
   // is fully searched
   while (current->data != data) {
	  
	  // If the current node exists, then print its value so we know where\
	  // we are
	  if (current != NULL) {
		 cout << current->data << " "; 
	  }

	  // Since the left child holds a number smaller than that of the parent,\
	  // if the value of the current node is larger than the one we are looking\
	  // for, then move down to its left child
	  if (current->data > data) {
		 current = current->leftChild;
	  }
	  // Otherwise, move to the current node's right child
	  else {                
		 current = current->rightChild;
	  }

	  // If the current node does not exist, that is, it is `NULL`, it means we have\
	  // searched the tree without finding the value: end the function by returning `NULL`
	  if (current == NULL) {
		 return NULL;
	  }
   }
   // Return the current node, that is, the node that holds the value we were looking for
   return current;
}

// Pre-order traversal
void preOrderTraversal (struct node* root) {
   if (root != NULL) {
	  cout << root->data << " ";
	  preOrderTraversal(root->leftChild);
	  preOrderTraversal(root->rightChild);
   }
}

// In-order traversal
void inOrderTraversal (struct node* root) {
   if (root != NULL) {
	  inOrderTraversal(root->leftChild);
	  cout << root->data << " ";          
	  inOrderTraversal(root->rightChild);
   }
}

// Post-order traversal
void postOrderTraversal (struct node* root) {
   if (root != NULL) {
	  postOrderTraversal(root->leftChild);
	  postOrderTraversal(root->rightChild);
	  cout << root->data << " ";
   }
}



int main() {
   int i;
   int array[7] = { 27, 14, 35, 10, 19, 31, 42 };
   // Insert all the numbers in the `array` array into the tree
   for (i = 0; i < 7; i++) {
	  insert(array[i]);
   }

   // Search for 31 in the tree
   i = 31;
   struct node * temp = search(i);
   if (temp != NULL) {
	  cout << "[" << temp->data << "] Element found.\n";
   }
   else {
	  cout << "[ x ] Element not found (" << i << ").\n";
   }

   // Search for 15 in the tree
   i = 15;
   temp = search(i);
   if (temp != NULL) {
	  cout << "[" << temp ->data << "] Element found.\n";
   }
   else {
	  cout << "[ x ] Element not found (" << i << ").\n";
   }            

   cout << "Preorder traversal: ";
   preOrderTraversal(root);
   cout << endl;

   cout << "Inorder traversal: ";
   inOrderTraversal(root);
   cout << endl;

   cout << "Post order traversal: ";
   postOrderTraversal(root);
   cout << endl;

   return 0;
}