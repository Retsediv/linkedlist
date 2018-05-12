#ifndef LIST_H_
#define LIST_H_

#include <cstdio>
#include "Node.hpp"

template <class T>
class List {
private:
    size_t size_;
    std::shared_ptr<Node<T>> tail_, head_;

public:
    void List(): size_(0), tail_(nullptr), head_(nullptr){};


    void push_back(const T& val);
//
//    void pop();
//
//    void remove(size_t index);
};

template<class T>
void List<T>::push_back(const T &val) {
    if(tail_ == nullptr){
        tail_ = new Node(val);
        head_ = tail_;
    } else {
        auto tmp = new Node(val, head_);
        (*head_).setRight(tmp);
        head_ = tmp;
    }
}

#endif