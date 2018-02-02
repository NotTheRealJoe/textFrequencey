#define _GNU_SOURCE
#include <search.h>
typedef struct hsearch_data hsearch_data;
void main(int argc, char** argv);
struct hsearch_data wordFrequency(char* path);
int wordCount(char* path);
