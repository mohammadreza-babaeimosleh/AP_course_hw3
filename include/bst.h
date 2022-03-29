#ifndef BST_H
#define BST_H

#include <iostream>
#include <functional>
#include <iomanip>
#include<vector>
#include<compare>
#include<initializer_list>
#include<string>



class BST
{
public:
    class Node;
    BST(Node _root); //BST normal constructor
    BST(const BST& bst); //BST copy constructor
    BST(BST&& bst); // BST constructor : move version
    BST();
    ~BST(); 
    BST(std::initializer_list<int> args); //BST multiargument constructor
    Node*& get_root();
    void bfs(std::function<void(Node*& node)> func);
    size_t length();
    bool add_node(int value);
    Node** find_node(int value);
    Node** find_parrent(int value);
    Node** find_successor(int value);
    bool delete_node(int value);
    
    BST& operator++();
    BST operator++(int); // right ++
    BST& operator=(const BST& bst);
    BST& operator=(BST&& bst); // operator = :move version
    
private:
    Node* root;
};


class BST::Node
{
public:
    Node(int value, Node* left = nullptr , Node* right = nullptr) //Node normal constructor
    {
        this->value = value;
        this->left = left;
        this->right = right;
    }

    Node()
        : Node(0, nullptr , nullptr)
    {
    }

    Node(const Node& node) //copy constructor
        : value{ node.value } 
        , left{ node.left }
        , right{ node.right }
    {
    }

    // using <=> for defininig eqaulitis 
    std::partial_ordering operator<=>(const Node& node) const {return value <=> node.value; }
    bool operator==(const Node& node) const { return value == node.value; }
    std::partial_ordering operator<=>(const int& num) const {return value <=> num; }
    bool operator==(const int& num) const { return value == num; }

    int value;
    Node* left;
    Node* right;

};

std::ostream& operator<<(std::ostream& os, BST::Node node);

std::ostream& operator<<(std::ostream& os, BST bst);


#endif //BST_H