#include <iostream>
#include <gtest/gtest.h>
#include "bst.h"

int main(int argc, char **argv)
{
    if (true) // make false to run unit-tests
    {
        BST::Node root{10};
        BST tree{&root};
        BST::Node node1{5};
        BST::Node node2{15};
        BST::Node node3{2};
        BST::Node node4{4};
        BST::Node node5{12};
        BST::Node node6{13};
        
        root.left = &node1;
        root.right = &node2;
        node1.left = &node3;
        node3.right = &node4;
        node2.left = &node5;
        node5.right = &node6;

        std::function<void(BST::Node*& node)> print = [&](BST::Node* node)->void
        {
            std::cout << node->value << "\t" ;
            if(node->left != nullptr)
            {
                std::cout << (node->left)->value << "\t" ;
            }
            else
            {
               if(node->right == nullptr)
               {
                    std::cout<< "" <<std::endl;
               } 

            }

            if(node->right != nullptr)
            {
                std::cout << (node->right)->value << std::endl;
            }
            else
            {
               std::cout<< "" <<std::endl;
            }
        };
        tree.add_node(16);
        // tree.add_node(20);
        // std::cout << ((root.right)->right)->value<< "  " << ((root.right)->right)->right << "  " << ((root.right)->right)->left<< std::endl;
        // std::cout<< tree.length() << std::endl;
        tree.bfs(print);
        // tree.find_node(20);
        // tree.find_parrent(20);
        //tree.find_successor(15);
        tree.delete_node(4);
        tree.bfs(print);

        
        
    }
    else
    {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret{RUN_ALL_TESTS()};
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    return 0;   
}