#include <ctype.h>
#include "JoeBST.h"
/**
 * Adds a new node to the binary search tree
 * @param root The root node of the tree to insert to
 * @param new The new node to insert into the tree
 */
void insert(struct jb_Node root, struct jb_Node new) {
	switch(isBefore(root.key, new.key)) {
		case 0:
			if (root.left) {
				insert(root.left)
			} else {
				root.left = new;
			}
			break;
		case 1:
			if(root.right) {
				insert(root.right);
			} else {
				root.right = new;
			}
			break;
		case -1:
			root.value++;
			break;
	}
}

/**
 * Retrieves the jb_Node identified by key
 * @param root The root node of the BST to search within
 * @param key The key of the node to search for
 * @return If the node specified by key is found, returns the node. If the node is not found, returns null.
 */
jb_Node find(struct jb_Node root, char* key) {
	switch(isBefore(root.key, key)) {
		case 0:
			if (root.left) {
				insert(root.left)
			} else {
				return NULL;
			}
			break;
		case 1:
			if(root.right) {
				insert(root.right);
			} else {
				return NULL;
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
