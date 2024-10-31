#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode {
    int key;
    int height;
    struct AVLNode* left;
    struct AVLNode* right;
} AVLNode;

// Utility function to create a new node
AVLNode* create_node(int key) {
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    node->key = key;
    node->height = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Get the height of the node
int get_height(AVLNode* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Get the balance factor of the node
int get_balance(AVLNode* node) {
    if (node == NULL)
        return 0;
    return get_height(node->left) - get_height(node->right);
}

// Right rotation
AVLNode* right_rotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + (get_height(y->left) > get_height(y->right) ? get_height(y->left) : get_height(y->right));
    x->height = 1 + (get_height(x->left) > get_height(x->right) ? get_height(x->left) : get_height(x->right));

    return x;
}

// Left rotation
AVLNode* left_rotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + (get_height(x->left) > get_height(x->right) ? get_height(x->left) : get_height(x->right));
    y->height = 1 + (get_height(y->left) > get_height(y->right) ? get_height(y->left) : get_height(y->right));

    return y;
}

// Insert a key into the AVL tree
AVLNode* insert(AVLNode* node, int key) {
    if (node == NULL)
        return create_node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // Duplicate keys are not allowed

    node->height = 1 + (get_height(node->left) > get_height(node->right) ? get_height(node->left) : get_height(node->right));

    int balance = get_balance(node);

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return right_rotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return left_rotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    return node;
}

// Get the node with the maximum value in the left subtree
AVLNode* get_max_value_node(AVLNode* node) {
    AVLNode* current = node;
    while (current->right != NULL)
        current = current->right;
    return current;
}

// Delete a node from the AVL tree
AVLNode* delete_node(AVLNode* root, int key) {
    if (root == NULL)
        return root;


    if (key < root->key)
        root->left = delete_node(root->left, key);
    else if (key > root->key)
        root->right = delete_node(root->right, key);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            AVLNode* temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            free(temp);
        } else {
            AVLNode* temp = get_max_value_node(root->left);
            root->key = temp->key;
            root->left = delete_node(root->left, temp->key);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + (get_height(root->left) > get_height(root->right) ? get_height(root->left) : get_height(root->right));

    int balance = get_balance(root);

    // Left Left Case
    if (balance > 1 && get_balance(root->left) >= 0)
        return right_rotate(root);

    // Left Right Case
    if (balance > 1 && get_balance(root->left) < 0) {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }

    // Right Right Case
    if (balance < -1 && get_balance(root->right) <= 0)
        return left_rotate(root);

    // Right Left Case
    if (balance < -1 && get_balance(root->right) > 0) {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}

// In-order traversal of the AVL tree
void inorder_traversal(AVLNode* root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->key);
        inorder_traversal(root->right);
    }
}

int main() {
    AVLNode* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("Inorder traversal of the AVL tree:\n");
    inorder_traversal(root);
    printf("\n");

    root = delete_node(root, 20);
    printf("Inorder traversal after deletion:\n");
    inorder_traversal(root);
    printf("\n");

    return 0;
}
