#include "bst.h"

BST::Node*& BST::get_root()
{
    return root ; 
}


void BST::bfs(std::function<void(Node*& node)> func)
{

    std::function<size_t(Node*& node)> depth = [&](Node* root)->size_t
    {

        if(root == nullptr)
        {
            return 0;
        }
        else
        {
            size_t left_depth{ depth(root->left) };
            size_t right_depth{ depth(root->right) };
            
            if(left_depth > right_depth)
            {
                return left_depth + 1 ;
            }
            else
            {
                return right_depth + 1 ;
            }
        }

    };

    std::function<void(size_t current_depth, Node*& node)> apply = [&](size_t current_depth , Node* node)->void
    {

        if(node == nullptr)
        {
            return;
        }

        if(current_depth == 1)
        { 
            func(node);
        }
        else if(current_depth > 1 )
        {
            apply(current_depth - 1 , node->left );
            apply(current_depth - 1 , node->right);
        }

    };

    size_t tree_depth{ depth(root) };
    if(tree_depth == 0)
    {
        return;
    }
    else
    {
        for(size_t current_depth{ 1 } ; current_depth <= tree_depth ; current_depth++)
        {
            apply(current_depth, root);
        }
    }

}


size_t BST::length()
{

    size_t counter{};
    std::function<void(size_t counter, Node*& root)> length_cal = [&](size_t counter, Node* root)->void
    {
        if(root != nullptr)
        {
            counter += 1;
        }
        else
        {
            return;
        }

        length_cal(counter, root->left);
        length_cal(counter, root->right);

    };

    length_cal(counter, root);

    return counter;
}


bool BST::add_node(int value)
{

    std::function<void(int value, Node*& root)> adder = [&](int value, Node* root)->void
    {

        if(root->value == value)
        {
            std::cout << "this value already exists in the tree" << std::endl;
            return;
        }
        else if(root->value > value)
        {

            if(root->left == nullptr)
            {
                Node tmp{value};
                root->left = &tmp ;
            }
            else
            {
                adder(value, root->left);
            }

        }
        else if(root->value < value)
        {

            if(root->right == nullptr)
            {
                Node tmp{value};
                root->right = &tmp;
            }
            else
            {
                adder(value, root->right);
            }

        }

    };

    adder(value, root);
    return true;

}


BST::Node** BST::find_node(int value)
{

    std::function<Node**(int value, Node** root)> finder = [&](int value, Node** root)->Node**
    {
        Node** node{nullptr};
        if((*root)->value == value)
        {
            std::cout << "value found" << std::endl;
            return root;
        }
        else if((*root)->value > value)
        {

            if((*root)->left == nullptr)
            {
                std::cout << "value does not exist" << std::endl;
                return nullptr;
            }
            else
            {   
                Node* tmp{(*root)->left};
                node = finder(value, &tmp);
            }

        }
        else if((*root)->value < value)
        {

            if((*root)->right == nullptr)
            {
                std::cout << "value does not exist" << std::endl;
                return nullptr; 
            }
            else
            {
                Node* tmp{(*root)->right};
                node = finder(value, &tmp);
            }

        }

        return node;

    };

    Node** tmp{finder(value, &root)};
    return tmp;

}


// BST::Node** BST::find_parrent(int value)
// {

//     std::function<Node**(int value, Node** root)> parrent_finder = [&](int value, Node** root)->Node**
//     {

//         if((*root) == nullptr)
//         {
//             return nullptr;
//         }

//         if(((*root)->left)->value =
        
//     }

// }