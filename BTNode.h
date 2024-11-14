#ifndef BTNODE_H_
#define BTNODE_H_

#include <sstream>
#include <string>

/** A node for a Binary Tree. */
template<typename Item_Type>
struct BTNode {
    Item_Type data;
    BTNode<Item_Type>* left;
    BTNode<Item_Type>* right;

    // Constructor
    BTNode(const Item_Type& the_data, BTNode<Item_Type>* left_val = nullptr, BTNode<Item_Type>* right_val = nullptr)
        : data(the_data), left(left_val), right(right_val) {}

    // Destructor
    virtual ~BTNode() {}

    // Convert to string
    virtual std::string to_string() const {
        std::ostringstream os;
        os << data;
        return os.str();
    }
};

// Overload the ostream insertion operator
template<typename Item_Type>
std::ostream& operator<<(std::ostream& out, const BTNode<Item_Type>& node) {
    return out << node.to_string();
}

#endif // BTNODE_H_
