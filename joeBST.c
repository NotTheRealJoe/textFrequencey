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
	switch(isBefore(root->key, new->key)) {
		case 0:
			if (root->left) {
				if(DEBUG) printf("Go left\n");
				insertRaw(root->left, new);
			} else {
				if(DEBUG) printf("Set to left\n");
				root->left = new;
			}
			break;
		case 1:
			if(root->right) {
				if(DEBUG) printf("Go right\n");
				insertRaw(root->right, new);
			} else {
				if(DEBUG) printf("Set to right\n");
				root->right = new;
			}
			break;
		case -1:
		if(DEBUG) printf("Key found, incrementing value\n");
			root->value++;
			break;
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
	switch(isBefore(root->key, key)) {
		case 0:
			if(DEBUG) printf("Go left\n");
			if (root->left) {
				find(root->left, key, fail);
			} else {
				return fail;
			}
			break;
		case 1:
			if(DEBUG) printf("Go right\n");
			if(root->right) {
				find(root->right, key, fail);
			} else {
				return fail;
			}
			break;
		case -1:
			return root;
			break;
	}
}

/**
 * Determine whether string A is before string B in alphabetical order
 * @param a The first string to consider
 * @param b The second string to consider
 * @return Returns 1 if string A is before string B in alphabetical order, or 0 if string B is before string A. Returns -1 if the strings are identical
 */
int isBefore(char* a, char* b) {
  int i = 0;
  while(a[i] == b[i]) {
    if(a[i] == '\0') {
      return -1;
    }
    i++;
  }
  if(a[i] == '\0' && b[i] != '\0') {
    return 1;
  } else if (a[i] != '\0' && b[i] == '\0') {
    return 0;
  } else if(toupper(a[i]) < toupper(b[i])) {
    return 1;
  } else {
    return 0;
  }
}
