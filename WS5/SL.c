#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


struct skipNode{
    int key;
    int value;
    struct skipNode** next;
};
typedef struct skipNode* skipNodePointer;

struct skipList{
    int level;
    struct skipNode* header;
};
typedef struct skipList* skipListPointer;

skipListPointer skipList_init(skipListPointer list){
    int i;
    skipNodePointer head = (skipNodePointer) malloc(sizeof(skipNodePointer));
    list -> header = head;
    head -> key = INT_MAX;


}








int main(int argc, char* argv[]){
    int arr[] = {12, 4,- 4, 21, 45, 5};
    struct skipList* list;
    list = (skipListPointer) malloc(sizeof(skipListPointer));
    
    printf("inserting-------------------\n");



    return 0;
}