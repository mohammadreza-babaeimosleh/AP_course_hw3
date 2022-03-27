#ifndef BST_H
#define BST_H

#include <iostream>
#include <functional>

class BST
{
public:
    class Node;
    Node*& get_root();
    void bfs(std::function<void(Node*& node)> func);
    size_t length();

    
private:
    Node* root;
};

class BST::Node
{
public:
    Node(int value, Node* left = nullptr , Node* right = nullptr)
    {
        std::cout << "normal constructor" << std::endl;
        this->value = value;
        this->left = left;
        this->right = right;
    }


    Node()
        : Node(0, nullptr , nullptr)
    {
        std::cout << "defualt constructor" << std::endl;
    }


    Node(const Node& node)
        : value{ node.value } 
        , left{ node.left }
        , right{ node.right }
    {
        std::cout << " copy constructor " << std::endl;
    }

    int value;
    Node* left;
    Node* right;
};

#endif //BST_H