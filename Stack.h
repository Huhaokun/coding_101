//
// Created by 胡昊坤 on 17/5/28.
//

#ifndef CODING_101_STACK_H
#define CODING_101_STACK_H

#include <vector>
#include <boost/thread/mutex.hpp>

// a thread-safe template stack impl
template <class T>
class Stack {

public:
    /*
     * default constructor
     * */
    Stack();

    /*
     *  default deconstructor
     * */
    virtual ~Stack();

    /*
     * push an element to top of the stack
     * */
    void Push(const T& element);

    /*
     *  pop an element from the top of the stack
     *
     * */
    void Pop(T& element);

    /*
     *  return the top element of the stack
     */
    void Top(T& element);
    /*
     *  if the stack is empty, return true
     *  else return false
     * */
    bool IsEmpty();


private:

    // TODO refine it with own vector type
    std::vector<T> elements_;
    boost::mutex mtx_;
};

template <class T>
Stack<T>::Stack() {

}

template <class T>
Stack<T>::~Stack() {

}

template <class T>
void Stack<T>::Push(const T &element) {
    boost::mutex::scoped_lock lock(mtx_);
    elements_.push_back(element);
}

template <class T>
void Stack<T>::Pop(T &element) {
    boost::mutex::scoped_lock lock(mtx_);
    Top(element);
    elements_.pop_back();
}

template <class T>
bool Stack<T>::IsEmpty() {
    return elements_.empty();
}

template <class T>
void Stack<T>::Top(T &element) {
    element = elements_.back();
}

#endif //CODING_101_STACK_H
