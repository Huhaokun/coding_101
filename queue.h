//
// Created by 胡昊坤 on 17/5/28.
//

#ifndef CODING_101_QUEUE_H
#define CODING_101_QUEUE_H

#include <vector>
#include <boost/thread/mutex.hpp>

template <class T>

/*
 *  thread-safe queue
 * */
class Queue {
public:
    Queue();

    virtual ~Queue();

    void Push(const T& element);

    void Pop(T& element);

    void Top(T& element);

    size_t Size();

private:
    std::vector<T> elements_;
    boost::mutex mtx_;
};

template <class T>
Queue::Queue() {

}

template <class T>
Queue::~Queue() {

}

template <class T>
void Queue::Push(const T &element) {
    boost::mutex::scoped_lock lock;
    elements_.push_back(element);
}

template <class T>
void Queue::Pop(T &element) {
    boost::mutex::scoped_lock lock;
    Top(element);
    elements_.erase(elements_.begin());
}

template <class T>
void Queue::Top(T &element) {
    element = elements_.front();
}

template <class T>
size_t Queue::Size() {
    return elements_.size();
}

#endif //CODING_101_QUEUE_H

