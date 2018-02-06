typedef struct jb_Node {
	char* key;
	int value;
	struct jb_Node* left;
	struct jb_Node* right;
} jb_Node;

void insertRaw(struct jb_Node* root, struct jb_Node* new);
jb_Node* find(struct jb_Node* root, char* key, struct jb_Node* fail);
struct jb_Node create(char* key, int value);
void insert(struct jb_Node* root, char* key, int value);
void printAll(jb_Node* root);
