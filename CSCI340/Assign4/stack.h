#ifndef STACK_H
#define STACK_H
#include <queue>

template<typename T>
class Stack
{
private:
    std::queue<T> q1;	// These queues are where the stack's elements 
    std::queue<T> q2;	// are to be saved.

public:
    bool empty() const;
    int size() const;
    const T& top();
    void push(const T &val);
    void pop();
};


// Note that the members of a template go into a .h file since 
// they are not compiled directly into a .o file like the members 
// of regular/non-template classes.




// Place your Stack class member implementations here.
    
    /**
     * @brief This method is used to determing if the stack is empty
     * 
     * @return true means the stack is empty
     * @return false means there is at least 1 element in the stack
    ***************************************************************************/
    template<typename T>
    bool Stack<T>::empty() const
    {
        return q1.empty();
    }

    /**
     * @brief This method returns the number of elements in the stack
     * 
     * @return int is returned based upon the number of elements
    ***************************************************************************/
    template<typename T>
    int Stack<T>::size() const
    {
        return q1.size();
    }

    /**
     * @brief This method returns the top element of the stack
     * 
     * @return const T& returns the top element
    ***************************************************************************/
    template<typename T>
    const T& Stack<T>::top()
    {
        if (q1.empty())
        {
            std::cerr << "Stack is empty!\n";
        }
        
        return q1.front();
    }

    /**
     * @brief This method pushes a value on top to the stack
     * 
     * @param val the value that will be added on top of the stack
    ***************************************************************************/
    template<typename T>
    void Stack<T>::push(const T &val)
    {
        q2.push(val);

        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        std::queue<T> q3 = q1;
        q1 = q2;
        q2 = q3;

        return;
    }

    /**
     * @brief This method will pop the top element off the stack
     * 
    ***************************************************************************/
    template<typename T>
    void Stack<T>::pop()
    {
        if(!q1.empty())
        {
            q1.pop();
        }
        return;
    }



#endif // STACK_H
