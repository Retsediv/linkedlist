#ifndef LIST_H_
#define LIST_H_

#include <cstdio>
#include "Node.hpp"

template <class T>
class List {
private:
    size_t size_;
    Node<T>* tail_, head_;

//    class ListIterator {
//
//    };
public:
    void List(): size_(0), tail_(nullptr), head_(nullptr){};

    void List(size_t size, const T& val): size_(size){
//        for (int i = 0; i < size; ++i) {
//            head_ = new Node<T>(val);
//        }
    }

//    void push_back(const T& val);
//
//    void pop();
//
//    void remove(size_t index);
};

#endif