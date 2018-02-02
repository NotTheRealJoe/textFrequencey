#define _GNU_SOURCE
#include <search.h>
typedef struct hsearch_data hsearch_data;
void main(int argc, char** argv);
hsearch_data* wordFrequency(int fd);
int wordCount(int fd);
