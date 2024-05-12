/*	Mike Rasmussen
*	z1696323
*	CSCI340 PE1
* 
*	I certify that this is my own work and where appropriate an extension 
* 	of the starter code provided for the assignment.
*/

#include "btree.h"
#include "node.h"

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

template <typename T>
class BinarySearchTree : public BinaryTree<T>
{
public:
    void Insert(const T & value);       // inserts node with value x
    bool Search(const T & value) const; // searches leaf with value x
    bool Remove(const T & value);       // removes leaf with value x
private:
    void _Insert(Node<T> *& node, const T & value);      // private version of insert
    bool _Search(Node<T> * node, const T & value) const; // private version of search
    void _Remove(Node<T> *& node, const T & value);      // private version of remove
    bool _Leaf(Node<T> * node) const;                    // checks if node is leaf
};

//public functions

/**
 * @brief This is the public Insert function, It allows the user to 
 *        insert a value into the Binary search tree.
 * 
 * @tparam T This function is a template function so the type T can be any type.
 * @param value The value the the user wants to insert.
 ************************************************************************/
template <typename T>
void BinarySearchTree<T>::Insert(const T & value)                 // inserts node with value x
{
    _Insert(this->root, value);
    return;
}

/**
 * @brief This is the public search function, it allows the user to 
 *        search the Binary Search Tree for a value.
 * 
 * @tparam T This function is a template function so the type T can be any type.
 * @param value The value the user wants to search for.
 * @return true Return true if the value is found.
 * @return false Return false if the value is not found.
 ************************************************************************/
template <typename T>
bool BinarySearchTree<T>::Search(const T & value) const           // searches leaf with value x
{
    return _Search(this->root, value);
}

/**
 * @brief This is the public remove funtion. It allows the user to 
 *        remove a value from the binary search tree. It checks to see
 *        if that value can be removed, and if it can it will remove it.
 * 
 * @tparam T This function is a template function so the type T can be any type.
 * @param value The value to user wants to remove.
 * @return true Returns true if the value is removed.
 * @return false Returns false if the value is not removed.
 ************************************************************************/
template <typename T>
bool BinarySearchTree<T>::Remove(const T & value)                 // removes leaf with value x
{
    //if the value is found    
    if (Search(value))
    {
        //remove the value
        _Remove(this->root, value);
        return true;
    }
    return false;
}

//private functions
/**
 * @brief This is the private insert funtion. It allows the programer to insert
 *        a valuse that is given to us by the user. It searches the binary
 *        search tree recursivly until it finds a node that doesnt exist
 *        and inserts it. 
 * 
 * @tparam T This function is a template function so the type T can be any type.
 * @param node this is a pointer to a node of the binary search tree.
 * @param value The value to be inserted.
 ************************************************************************/
template <typename T>
void BinarySearchTree<T>::_Insert(Node<T> *& node, const T & value)       // private version of insert
{
    //check to see if the node does not exist
    if (node == nullptr)
    {   
        //create a new node and insert the value for that node
        node = new Node<T>(value); 
        return;
    } 

    //if the node does exist
    else 
    {
        //check to see if the value is greater than the current node's data value
        if (value > node->data)
        {
            //recursivly enter the right subtree
            return _Insert(node->right, value);
        }

        //check to see if the value is less than the current node's data value
        else if (value < node->data) 
        {
            //recursivly enter the left subtree
            return _Insert(node->left, value);
        }

        //If the value is equal to the current node's data value, return beacuse binary 
        //search tree do not have duplicate values
        else
        {
            return;
        }
    }    
}

/**
 * @brief This is the private search funtion. It allows the programer to search for
 *        a valuse that is given to us by the user. It searches the tree
 *        recursivly until it find a node with a data value equal to the value the
 *        user specified.
 * 
 * @tparam T This function is a template function so the type T can be any type.
 * @param node this is a pointer to a node of the binary search tree.
 * @param value The value to be searched for.
 * @return true Returns true if the value is found.
 * @return false Returns false if the value is not found.
 ************************************************************************/
template <typename T>
bool BinarySearchTree<T>::_Search(Node<T> * node, const T & value) const  // private version of search
{
    //if node does not exist
    if (node == nullptr)
    {
        //value not found
        return false;
    }

    //if the value is found and is a leaf node
    if (value == node->data && _Leaf(node))
    {
        //value found
        return true;
    }

    //if the value is greater than the current node's data value
    else if (value > node->data)
    {
        //recursivly enter the right subtree
        return _Search(node->right, value);
    }

     //if the value is less than the current node's data value
    else
    {
        //recursivly enter the left subtree
        return _Search(node->left, value);
    }

    return false;
}

/**
 * @brief This is the private remove funtion. It allows the programer to remove
 *        a valuse that is given to us by the user. It recursivly searches for the 
 *        value specified by the user. Once found, it is checked to see if it is a
 *        leaf node and if it is, the node is deleted and repointed to the nullptr.
 *        
 * @tparam T This function is a template function so the type T can be any type.
 * @param node this is a pointer to a node of the binary search tree.
 * @param value The value that is to be removed. 
 ************************************************************************/
template <typename T>
void BinarySearchTree<T>::_Remove(Node<T> *& node, const T & value)       // private version of remove
{
    //check to see if the node does not exist
    if (node == nullptr)
    {
        return;
    }

    //check to see if the value is greater than the current node's data value
    else if (value > node->data)
    {
        //recursivly enter the right subtree
        _Remove(node->right, value);
    }

    //check to see if the value is less than the current node's data value
    else if (value < node->data)
    {
        //recursivly enter the left subtree
        _Remove(node->left, value);
    }
    //if the value exists and is neither greater than or less than the current node's data value
    //then we have found the node we wish to remove
    else
    {
        //check to see if the node is a leaf
        if (_Leaf(node))
        {
            //remove the node
            delete node;
            node = nullptr; //reset the node to the nullptr
        }
    }
}

/**
 * @brief This function determines if the calling object is a leaf.
 * 
 * @tparam T This function is a template function so the type T can be any type.
 * @param node this is a pointer to a node of the binary search tree.
 * @return true Returns true is the node is a leaf.
 * @return false Returns false is the node is not a leaf.
 ************************************************************************/
template <typename T>
bool BinarySearchTree<T>::_Leaf(Node<T> * node) const           // checks if node is leaf
{
    //check to see if the node has any children
    if (node->left == nullptr && node->right == nullptr)
    {
        //no childeren means it is a leaf
        return true;
    }

    //if it has children it is not a leaf
    return false;
}

#endif // End of BINARYSEARCHTREE_H_