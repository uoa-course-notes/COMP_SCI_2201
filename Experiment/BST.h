#ifndef __BST__
#define __BST__

#include <vector>
#include "Node.h"


class BST{
    private:
        Node* root;
    public:
        BST(Node* root);
        BST(std::vector<int> values);
        BST();

        Node* getRoot() const;
        void insert(int key);
        void delKey(int key);
        int getHeight();
        bool isBST();
        Node* search(int key);
        
        void output();
        void INORDER_WALK();
        void POST_ORDER_WALK();
        void PRE_ORDER_WALK();
};




#endif  