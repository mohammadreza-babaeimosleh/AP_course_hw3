#include <iostream>
#include <gtest/gtest.h>
#include "bst.h"

int main(int argc, char **argv)
{
    if (true) // make false to run unit-tests
    {
        BST tree{};
        tree.add_node(10);
        tree.add_node(5);
        tree.add_node(15);
        tree.add_node(2);
        tree.add_node(4);
        tree.add_node(12);
        tree.add_node(13);
        tree.add_node(16);
        

        // std::function<void(BST::Node*& node)> print = [&](BST::Node* node)->void
        // {
        //     std::cout << node->value << "\t" ;
        //     if(node->left != nullptr)
        //     {
        //         std::cout << (node->left)->value << "\t" ;
        //     }
        //     else
        //     {
        //        if(node->right == nullptr)
        //        {
        //             std::cout<< "" <<std::endl;
        //        } 

        //     }

        //     if(node->right != nullptr)
        //     {
        //         std::cout << (node->right)->value << std::endl;
        //     }
        //     else
        //     {
        //        std::cout<< "" <<std::endl;
        //     }
        // };

        //tree++;
        // tree.add_node(20);
        //std::cout<< tree.length() << std::endl;
        //tree.find_node(13);
        //tree.find_parrent(13);
        //tree.find_successor(15);
        //tree.delete_node(13);
        //tree.bfs(print);
        //std::cout << tree << std::endl;
        //std::cout << (((tree.get_root())->right)->right)->value << std::endl;
        
        
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