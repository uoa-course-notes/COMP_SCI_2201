#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// Node class
class Node {
public:
    int value;
    std::vector<Node*> next;

    Node(int value, int height) : value(value), next(height, nullptr) {}
};

// SkipList class
class SkipList {
private:
    Node* head; // Head node
    int maxHeight; // Maximum height of the skip list
    float prob; // Probability for random height
    int maxLevel; // Maximum number of levels

    // Random height generator
    int randomHeight() {
        int height = 1;
        while ((rand() % 2) == 0 && height < maxLevel) {
            height++;
        }
        return height;
    }

public:
    // Constructor
    SkipList(int maxLevel, float prob) : maxLevel(maxLevel), prob(prob) {
        head = new Node(-1, maxLevel); // Sentinel head node with dummy value
        maxHeight = 1; // Initially, the max height is 1
    }

    // Insert function
    void insert(int value) {
        vector<Node*> update(maxLevel, nullptr);
        Node* current = head;

        // Find the place to insert the new node at each level
        for (int i = maxHeight - 1; i >= 0; i--) {
            while (current->next[i] != nullptr && current->next[i]->value < value) {
                current = current->next[i];
            }
            update[i] = current;
        }

        // Generate random height for the new node
        int newHeight = randomHeight();

        if (newHeight > maxHeight) {
            for (int i = maxHeight; i < newHeight; i++) {
                update[i] = head;
            }
            maxHeight = newHeight;
        }

        // Create the new node
        Node* newNode = new Node(value, newHeight);

        // Update the forward pointers at each level
        for (int i = 0; i < newHeight; i++) {
            newNode->next[i] = update[i]->next[i];
            update[i]->next[i] = newNode;
        }
    }

    // Search function
    bool search(int value) {
        Node* current = head;
        for (int i = maxHeight - 1; i >= 0; i--) {
            while (current->next[i] != nullptr && current->next[i]->value < value) {
                current = current->next[i];
            }
        }
        current = current->next[0];
        return current != nullptr && current->value == value;
    }

    // Remove function
    void remove(int value) {
        vector<Node*> update(maxLevel, nullptr);
        Node* current = head;

        // Find the node to be removed
        for (int i = maxHeight - 1; i >= 0; i--) {
            while (current->next[i] != nullptr && current->next[i]->value < value) {
                current = current->next[i];
            }
            update[i] = current;
        }

        current = current->next[0];

        if (current != nullptr && current->value == value) {
            // Update pointers to bypass the node
            for (int i = 0; i < maxHeight; i++) {
                if (update[i]->next[i] != current) {
                    break;
                }
                update[i]->next[i] = current->next[i];
            }

            // Reduce the max height if necessary
            while (maxHeight > 1 && head->next[maxHeight - 1] == nullptr) {
                maxHeight--;
            }

            delete current;
        }
    }

    // Print the SkipList
    void printList() {
        for (int i = maxHeight - 1; i >= 0; i--) {
            Node* current = head->next[i];
            std::cout<< "Level " << i + 1 << ": ";
            while (current != nullptr) {
                std::cout<< current->value << " ";
                current = current->next[i];
            }
            std::cout<< std::endl;
        }
    }
};

int main() {
    srand(time(0)); // Seed for random number generation
    SkipList list(6, 0.5); // Max level 6, probability 0.5

    // Inserting elements
    list.insert(3);
    list.insert(6);
    list.insert(7);
    list.insert(9);
    list.insert(12);
    list.insert(19);
    list.insert(17);
    list.insert(26);

    // Printing the skip list
    list.printList();

    // Searching for an element
    if (list.search(7)) {
        std::cout<< "Element 7 found!" << std::endl;
    } else {
        std::cout<< "Element 7 not found!" << std::endl;
    }

    // Removing an element
    list.remove(7);
    list.printList();

    return 0;
}
