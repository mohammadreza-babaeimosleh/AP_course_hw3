#include "bst.h"

BST::BST(Node* _root)
    : root{_root}
{
    std::cout << "counstructor" << std::endl;
}

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
    std::function<void(size_t& count, Node*& root)> length_cal = [&](size_t count, Node* root)->void
    {
        if(root != nullptr)
        {
            counter += 1;
        }
        else
        {
            return;
        }

        length_cal(count, root->left);
        length_cal(count, root->right);

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
                Node* node{new Node{value}};
                root->left = node;
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
                Node* node {new Node{value}};
                root->right = node ;
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

    return finder(value, &root);

}


BST::Node** BST::find_parrent(int value)
{

    if(find_node(value) == nullptr)
    {
        std::cout << "the value does not exist" << std::endl;
        return nullptr;
    }

    std::function<Node**(int value, Node** root)> parrent_finder = [&](int value, Node** root)->Node**
    {
        Node** parrent{nullptr};

        if((*root) == nullptr)
        {
            return nullptr;
        }

        if((*root)->value == value)
        {
            std::cout << "given valuue is the root and has no parrents" << std::endl;
            return nullptr;
        }

        if(((*root)->left) !=nullptr && ((*root)->left)->value == value)
        {
            std::cout << "parrent is   " << (*root)->value << std::endl;
            return root;
        }

        
        if(((*root)->right) !=nullptr && ((*root)->right)->value == value)
        {
            std::cout << "parrent is   " << (*root)->value << std::endl;
            return root;
        }

        if((*root)->value > value)
        {
            Node* tmp{(*root)->left};
            parrent = parrent_finder(value, &tmp);
        }

        if((*root)->value < value)
        {
            Node* tmp{(*root)->right};
            parrent = parrent_finder(value, &tmp);
        }

        return parrent;
        
    };

    return parrent_finder(value, &root);

}


BST::Node** BST::find_successor(int value)
{
    if(find_node(value) == nullptr)
    {
        std::cout << "value does not exist" << std::endl;
        return nullptr;
    }
    else
    {

        Node** target_node{ find_node(value) };
        Node** successor{ target_node };
        if((*target_node)->left == nullptr)
        {
            std::cout << (*successor)->value << std::endl;
            return successor;
        }
        else
        {
            successor = &((*target_node)->left);

            while(true)
            {
                if((*successor)->right != nullptr)
                {
                    successor = &((*successor)->right);
                }
                else
                {
                    std::cout << (*successor)->value << std::endl;
                    return successor;
                }
            }

        }

    }

}