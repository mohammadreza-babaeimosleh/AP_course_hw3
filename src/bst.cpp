#include "bst.h"


BST::Node::Node(int value, Node* left, Node* right)
{
    std::cout << "normal constructor" << std::endl;
    this->value = value;
    this->left = left;
    this->right = right;
}

BST::Node::Node()
    : BST::Node(0, nullptr , nullptr)
{
    std::cout << "defualt constructor" << std::endl;
}

BST::Node::Node(const Node& node)
    : value{ node.value} 
    , left{ node.left }
    , right{ node.right }
{
   std::cout << " copy constructor " << std::endl;
}

