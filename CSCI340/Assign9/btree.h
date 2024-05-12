#ifndef H_BTREE
#define H_BTREE

#include "node.h"

typedef enum {left_side, right_side } SIDE;
    SIDE rnd()
    {
        return rand() % 2 ? right_side : left_side;
    }

template <typename T> 
class BinaryTree
{

public:
    BinaryTree()                // default constructor
    {
        root = nullptr;
    }
    unsigned     getSize() const;                        // returns size of tree
    unsigned     getHeight() const;                      // returns height of tree
    virtual void Insert(const T& value);                 // inserts node in tree
    void         Inorder(void (*func)(const T& x));      // inorder traversal of tree
	
protected:
    Node<T> *root;                                      // root of tree

private:

    unsigned _getSize(Node<T> * node) const;                     // private version of getSize()
    unsigned _getHeight(Node<T> * node) const;                   // private version of getHeight()
    void _Insert(Node<T> *& node, const T& value);               // private version of Insert()
    void _Inorder(Node<T> * node, void (*func)(const T& x));     // private version of Inorder()
 
};

//public functions

    /**
     * @brief This is the public getSize function. It allows the user to get the
     *        the size of the binary tree, using the private getSize function.
     * 
     * @tparam T This function is a template function so the type T can be any type.
     * @return unsigned returns the size of the tree.
     ************************************************************************/
    template <typename T> 
    unsigned BinaryTree<T>::getSize() const    // returns size of tree
    {
	    return _getSize(root);
    }

    /**
     * @brief This is the public getHeight function. It allows the user to get the
     *        the height of the binary tree, using the private getHeight function.
     * 
     * @tparam T This function is a template function so the type T can be any type.
     * @return unsigned returns the height of the tree.
     ************************************************************************/
    template <typename T> 
    unsigned BinaryTree<T>::getHeight() const  // returns height of tree
	{
		return _getHeight(root);
	}	
	
    /**
     * @brief This is the public Insert function. It allows the user to insert
     *        values into the tree, using the private Insert function.
     * 
     * @tparam T This function is a template function so the type T can be any type.
     * @param value This is the value, defined by the user, to insert into the tree.
     ************************************************************************/
    template <typename T> 
    void BinaryTree<T>::Insert(const T& value)                     // inserts node in tree
    {
   	    _Insert(root, value);
	    return;
    }

    /**
     * @brief This is the public Inorder function. It allows the user to print 
     *        the tree using an inorder traversal, using the private Inorder function.
     * 
     * @tparam T This function is a template function so the type T can be any type.
     * @param func This is the function the user can use to print out the tree
     *             or do anything else with the data as they want. The order the
     *             data will be put into the user defined function is inorder.
     ************************************************************************/
    template <typename T> 
    void BinaryTree<T>::Inorder(void (*func)(const T& x))   // inorder traversal of tree
	{
		_Inorder(root, func);
		return;
	}

//private

    /**
     * @brief This is the private getSize function. It allows the programmer to give the
     *        the size of the binary tree to the user.
     * 
     * @tparam T This function is a template function so the type T can be any type.
     * @param node this is a pointer to the root of the binary tree.
     * @return unsigned Returns the size of the binary tree. 
     ************************************************************************/
    template <typename T> 
    unsigned BinaryTree<T>::_getSize(Node<T> * node) const                  // private version of getSize()
    {
        //check to see if the node does not exist
        if (node == nullptr)
        {
            return 0;
        }

        //if the node exists, recursivly run through all of the data points that exist
        else
        {
            return (_getSize(node->left) + 1 + _getSize(node->right));
        }
    }

    /**
     * @brief This is the private getHeight function. It allows the programmer to give the
     *        height of the binary tree to the user.
     * 
     * @tparam T This function is a template function so the type T can be any type. 
     * @param node this is a pointer to the root of the binary tree.
     * @return unsigned Returns the height of the binary tree.
     ************************************************************************/
    template <typename T> 
    unsigned BinaryTree<T>::_getHeight(Node<T> * node) const               // private version of getHeight()
    {

        //check if the node does not exist
        if (node == nullptr)
        {
            return 0;
        }

        //if the node exists calulate the height
        else
        {
            //recursivly set the heights of the left and right nodes
            int lHeight = _getHeight(node->left);
            int rHeight = _getHeight(node->right);
        
            //add 1 to the larger height and return
            if (lHeight > rHeight) 
            {
                return lHeight + 1;
            } 
            else
            {
                return rHeight + 1;
            }
        }
        
    }   

    /**
     * @brief This is the private Insert function. It allows to programmer to insert
     *        a user defined value into the binary tree. 
     * 
     * @tparam T This function is a template function so the type T can be any type.
     * @param node this is a pointer to the root of the binary tree.
     * @param value This is the value to be inserted into the binary tree, it is 
     *              given to the private function through the public function.
     ************************************************************************/
    template <typename T> 
    void BinaryTree<T>::_Insert(Node<T> *& node, const T& value)          // private version of Insert()
    {
        //check to see if the node does not exist
        if (node == nullptr)
        {   
            //create a new node and insert the value for that node
            node = new Node<T>(value);
 
        }   

        //if the node exists randomly choose left or right to insert the node and recursivly try to insert the value.
        else
        {
            SIDE s = rnd();
            if (s == left_side)
            {   
                _Insert(node->left, value);
            }
            else
            {
                _Insert(node->right, value);
            }
        }
    }

    /**
     * @brief This is the private Inorder function. It traverses the tree inorder
     *        so the user can do something with the data through the use of the 
     *        function pointer.
     * 
     * @tparam T This function is a template function so the type T can be any type.
     * @param node this is a pointer to the root of the binary tree.
     * @param func This allows the user to pass the data of the tree to a function inorder.
     ************************************************************************/
    template <typename T> 
    void BinaryTree<T>::_Inorder(Node<T> * node, void (*func)(const T& x))   // private version of Inorder()
    {
        //check to see if the node does not exist
        if (node == nullptr)
        {
          return;
        }
        
        //inorder traversal
        _Inorder(node->left, func);
        func(node->data); //use the users function to process the data. For this assignment the user is printing the data.
        _Inorder(node->right, func);
    }



#endif // End of H_BTREE