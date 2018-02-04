typedef struct jb_Node {
	char* key;
	int value;
	struct jb_Node* left;
	struct jb_Node* right;
} jb_Node;

void insert(struct jb_Node root, struct jb_Node new);
jb_Node find(struct jb_Node root, char* key);
int isBefore(char* a, char* b);
