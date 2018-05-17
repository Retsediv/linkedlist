#ifndef LIST_H_
#define LIST_H_

#include <cstdio>
#include "Node.hpp"
#include "exception.h"
#include "ListIterator.hpp"


template<class T>
class List {
private:
    size_t size_;
    Node<T> *tail_;
    Node<T> *head_;

public:
    List() : size_(0), tail_(nullptr), head_(new GuardNode<T>()) {};

    inline size_t getSize() const { return size_; };

    inline Node<T> *getTail() const { return tail_; };

    inline Node<T> *getHead() const { return head_; };

    inline ListIterator<T> begin() noexcept { return ListIterator<T>(tail_); }

    inline ListIterator<T> end() noexcept { return ListIterator<T>(head_); }

    std::reverse_iterator<T> rbegin() noexcept { return std::reverse_iterator<T>(end()); };

    std::reverse_iterator<T> rend() noexcept { return std::reverse_iterator<T>(begin()); };

    ListIterator<T> next(ListIterator<T> &iterator, size_t n);

    ListIterator<T> prev(ListIterator<T> &iterator, size_t n);

    void push_back(const T &val);
};

template<class T>
void List<T>::push_back(const T &val) {
    auto * new_node = new Node<T>{val};

    if (tail_ == nullptr) {
        tail_ = new_node;
        new_node->setRight(head_);
        head_->setLeft(new_node);
    } else {
        auto prev = head_->getLeft();
        prev->setRight(new_node);
        new_node->setLeft(prev);
        new_node->setRight(head_->getRight());
        head_->setLeft(new_node);
    }

    ++size_;
}

template<class T>
ListIterator<T> List<T>::next(ListIterator<T> &iterator, size_t n) {
    ListIterator<T> new_iter{iterator};
    new_iter.next(n);
    return new_iter;
}

template<class T>
ListIterator<T> List<T>::prev(ListIterator<T> &iterator, size_t n) {
    ListIterator<T> new_iter{iterator};
    new_iter.prev(n);
    return new_iter;
}

#endif