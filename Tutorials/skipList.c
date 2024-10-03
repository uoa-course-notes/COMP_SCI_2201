#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>




#define MAX_LEVEL 4  // Max number of levels in the skip list

// Node structure
typedef struct Node {
    int value;
    struct Node** forward;  // Array of forward pointers
} Node;

// SkipList structure
typedef struct SkipList {
    int level;  // Current level of the skip list
    Node* header;  // Pointer to the header node
} SkipList;

// Function to create a new node
Node* createNode(int level, int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->forward = (Node**)malloc(sizeof(Node*) * (level + 1));

    for (int i = 0; i <= level; i++) {
        node->forward[i] = NULL;
    }
    return node;
}

// Function to create a skip list
SkipList* createSkipList() {
    SkipList* list = (SkipList*)malloc(sizeof(SkipList));
    list->level = 0;  // Start with the lowest level
    list->header = createNode(MAX_LEVEL, INT_MIN);  // Header node with sentinel value
    return list;
}

// Random level generator (probabilistic leveling)
int randomLevel() {
    int level = 0;
    while (rand() % 2 && level < MAX_LEVEL) {
        level++;
    }
    return level;
}

// Insert a value into the skip list
void insert(SkipList* list, int value) {
    Node* update[MAX_LEVEL + 1];
    Node* current = list->header;

    for (int i = list->level; i >= 0; i--) {
        while (current->forward[i] != NULL && current->forward[i]->value < value) {
            current = current->forward[i];
        }
        update[i] = current;  // Save the path
    }

    current = current->forward[0];

    if (current == NULL || current->value != value) {
        int newLevel = randomLevel();

        if (newLevel > list->level) {
            for (int i = list->level + 1; i <= newLevel; i++) {
                update[i] = list->header;
            }
            list->level = newLevel;
        }

        Node* newNode = createNode(newLevel, value);

        for (int i = 0; i <= newLevel; i++) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }

        printf("Inserted %d\n", value);
    }
}

// Search for a value in the skip list
Node* search(SkipList* list, int value) {
    Node* current = list->header;

    for (int i = list->level; i >= 0; i--) {
        while (current->forward[i] != NULL && current->forward[i]->value < value) {
            current = current->forward[i];
        }
    }

    current = current->forward[0];

    if (current != NULL && current->value == value) {
        printf("Found %d\n", value);
        return current;
    }

    printf("Not found: %d\n", value);
    return NULL;
}

// Main function
int main() {
    srand(time(0));

    SkipList* list = createSkipList();

    insert(list, 10);
    insert(list, 20);
    insert(list, 15);
    insert(list, 25);

    search(list, 15);
    search(list, 30);

    return 0;
}



/*
Useful websites for implementation
https://www.baeldung.com/cs/skip-lists

*/