#include <iostream>
#include <cstdlib>
#include <ctime>
#include <memory>
#include <limits>

#define MAX_LEVEL 4  // Maximum level for the skip list

// Node structure
struct Node {
    int value;
    std::unique_ptr<Node*[]> forward;  // Array of forward pointers (unique pointer array)

    Node(int level, int value) : value(value), forward(new Node*[level + 1]) {
        for (int i = 0; i <= level; ++i) {
            forward[i] = nullptr;
        }
    }
};

// SkipList structure
class SkipList {
public:
    SkipList() : level(0), header(std::make_unique<Node>(MAX_LEVEL, std::numeric_limits<int>::min())) {}

    void insert(int value);
    void search(int value);

private:
    int level;
    std::unique_ptr<Node> header;

    int randomLevel() {
        int lvl = 0;
        while (rand() % 2 && lvl < MAX_LEVEL) {
            lvl++;
        }
        return lvl;
    }
};

// Insert a value into the skip list
void SkipList::insert(int value) {
    Node* update[MAX_LEVEL + 1];
    Node* current = header.get();

    for (int i = level; i >= 0; i--) {
        while (current->forward[i] != nullptr && current->forward[i]->value < value) {
            current = current->forward[i];
        }
        update[i] = current;
    }

    current = current->forward[0];

    if (current == nullptr || current->value != value) {
        int newLevel = randomLevel();

        if (newLevel > level) {
            for (int i = level + 1; i <= newLevel; i++) {
                update[i] = header.get();
            }
            level = newLevel;
        }

        Node* newNode = new Node(newLevel, value);

        for (int i = 0; i <= newLevel; i++) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }

        std::cout << "Inserted " << value << std::endl;
    }
}

// Search for a value in the skip list
void SkipList::search(int value) {
    Node* current = header.get();

    for (int i = level; i >= 0; i--) {
        while (current->forward[i] != nullptr && current->forward[i]->value < value) {
            current = current->forward[i];
        }
    }

    current = current->forward[0];

    if (current != nullptr && current->value == value) {
        std::cout << "Found " << value << std::endl;
    } else {
        std::cout << "Not found: " << value << std::endl;
    }
}

// Main function
int main() {
    srand(time(0));

    SkipList list;

    list.insert(10);
    list.insert(20);
    list.insert(15);
    list.insert(25);

    list.search(15);
    list.search(30);

    return 0;
}
