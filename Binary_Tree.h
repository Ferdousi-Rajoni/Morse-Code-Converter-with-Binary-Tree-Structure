#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include "BTNode.h"

template<typename Item_Type>
class Binary_Tree {
public:
    // Default constructor
    Binary_Tree() : root(nullptr) {}

    // Constructor that initializes the tree with data and optional children
    Binary_Tree(const Item_Type& the_data, const Binary_Tree<Item_Type>& left_child = Binary_Tree(),
                const Binary_Tree<Item_Type>& right_child = Binary_Tree())
        : root(new BTNode<Item_Type>(the_data, left_child.root, right_child.root)) {}

    // New constructor that takes a BTNode pointer directly
    Binary_Tree(BTNode<Item_Type>* root_node) : root(root_node) {}

    // Destructor to clean up memory
    virtual ~Binary_Tree() {
        delete root;
    }

    // Utility functions
    bool is_null() const { return root == nullptr; }
    bool is_leaf() const { return root && root->left == nullptr && root->right == nullptr; }
    BTNode<Item_Type>* get_root() const { return root; }

protected:
    BTNode<Item_Type>* root;
};

#endif // BINARY_TREE_H_
