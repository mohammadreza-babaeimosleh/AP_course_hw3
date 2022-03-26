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