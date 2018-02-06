#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include "JoeBST.h"
#define DEBUG 1

/**
 * Create a new BST with the given key and value for the root
 * @param key The key for the root node
 * @param value The value for the root node
 * @return Returns a struct jb_Node that should be stored as the root of the tree
 */
struct jb_Node create(char* key, int value) {
	struct jb_Node new;
	new.key = key;
	new.value = value;
	new.left = NULL;
	new.right = NULL;
	return new;
}

/**
 * Create a new node with the specified data and insert it into the binary
 * search tree.
 * @param root The root of the tree to insert to
 * @param key The key for the new node to insert
 * @param value The value for the new node to insert
 */
void insert(struct jb_Node* root, char* key, int value) {
	struct jb_Node new;
	new.key = key;
	new.value = value;
	new.left = NULL;
	new.right = NULL;

	insertRaw(root, &new);
}

/**
 * Adds a new node to the binary search tree
 * @param root The root node of the tree to insert to
 * @param new The new node to insert into the tree
 */
void insertRaw(struct jb_Node* root, struct jb_Node* new) {
	new->left = NULL;
	new->right = NULL;
	if(DEBUG) printf("Begin insert\n");
	int compared = strcmp(new->key, root->key);
	if(compared < 0) {
		//new->key is "less than" root->key
		if(root->left) {
			if(DEBUG) printf("Go left\n");
			insertRaw(root->left, new);
		} else {
			if(DEBUG) printf("Set left\n");
			root->left = new;
		}
	} else if(compared > 0) {
		//new->key is greater than root->key
		if(root->right) {
			if(DEBUG) printf("Go right\n");
			insertRaw(root->right, new);
		} else {
			if(DEBUG) printf("Set right\n");
			root->right = new;
		}
	} else {
		//new->key and root->key are the same
		if(DEBUG) printf("Key found, incrementing\n")
		root->value += 1;
	}
}

/**
 * Retrieves the jb_Node identified by key
 * @param root The root node of the BST to search within
 * @param key The key of the node to search for
 * @param fail The jb_Node to return, should the search fail
 * @return If the node specified by key is found, returns the node. If the node is not found, returns null.
 */
struct jb_Node* find(struct jb_Node* root, char* key, struct jb_Node* fail) {
	int compared = strcmp(root->key, key);
	if(compared < 0) {
		//root->key is "less than" key
		if(DEBUG) printf("Go left\n");
		if(root->left) {
			find(root->left, key, fail);
		} else {
			return fail;
		}
	} else if(compared > 0) {
		// root->key is "greater than" key
		if(DEBUG) printf("Go right\n");
		if(root->right) {
			find(root->right, key, fail);
		} else {
			return fail;
		}
	} else {
		//root->key and key are the same
		return root;
	}
}

/**
 * Print the entire tree to the terminal using depth-first search for debugging purposes
 * @param root The root node of the tree to print
 */
void printAll(jb_Node* root) {
	printf("%s\t\t%i\n", root->key, root->value);
	if(root->left) {
		printAll(root->left);
	}
	if(root->right) {
		printAll(root->right);
	}
}

/**
 * Returns the number of nodes in the tree
 * @param root The root node of the tree to count
 * @return The number of nodes in the tree
 */
int countNodes(jb_Node* root) {
	int counter = 0;
	counter += 1;
	if(root->left) {
		counter += countNodes(root->left);
	}
	if(root->right) {
		counter += countNodes(root->right);
	}
}
