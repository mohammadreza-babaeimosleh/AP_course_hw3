#ifndef BST_H
#define BST_H

#include <iostream>
class BST
{
public:
    class Node;
private:
    Node* root;
};


class BST::Node
{
public:
	Node(int value, Node* left = nullptr, Node* right =nullptr);
	Node();
	Node(const Node& node);

	int value;
	Node* left;
	Node* right;
};

#endif //BST_H