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
    Node<T> *head_;
    Node<T> *tail_;

public:
    typedef T value_type;
    typedef ListIterator<T> iterator;
    typedef ListIterator<const T> const_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;


    List() : size_(0), head_(nullptr), tail_(new GuardNode<T>()) {};

    inline size_t getSize() const { return size_; };

    inline Node<T> *getTail() const { return tail_; };

    inline Node<T> *getHead() const { return head_; };

    inline iterator begin() noexcept { return iterator (head_); }
    inline const_iterator cbegin() noexcept { return const_iterator(head_); }
    inline iterator end() noexcept { return iterator (tail_); }
    inline const_iterator cend() noexcept { return const_iterator(tail_); }

    reverse_iterator rbegin() noexcept { return reverse_iterator(end()); };
    reverse_iterator rend() noexcept { return reverse_iterator(begin()); };

    iterator next(const iterator &iterator, size_t n){
        List<T>::iterator new_iter{iterator};
        new_iter.next(n);
        return new_iter;
    }
    iterator prev(const iterator &iterator, size_t n){
        List<T>::iterator new_iter{iterator};
        new_iter.prev(n);
        return new_iter;
    }

    void push_front(const T &val){
        auto *new_node = new Node<T>{val};

        new_node->setRight(head_);
        if (head_ != nullptr) {
            head_->setLeft(new_node);
        }

        head_ = new_node;

        ++size_;
    }
    void push_back(const T &val){
        auto *new_node = new Node<T>{val};

        if (head_ == nullptr) {
            head_ = new_node;
            new_node->setRight(tail_);
            tail_->setLeft(new_node);
        } else {
            auto prev = tail_->getLeft();
            prev->setRight(new_node);
            new_node->setLeft(prev);
            new_node->setRight(tail_);
            tail_->setLeft(new_node);
        }

        ++size_;
    }

    iterator insert(size_t index, const T &val){
        return insert(begin().next(index), val);

    }
    iterator insert(const iterator &iterator, const T &val){
        auto *new_node = new Node<T>{val};

        Node<T> *current_node = iterator.getPointer();
        auto next = current_node->getRight();

        current_node->setRight(new_node);
        next->setLeft(new_node);

        new_node->setLeft(current_node);
        new_node->setRight(next);

        List<T>::iterator current{new_node};
        ++size_;

        return current;
    }

    iterator remove(size_t index){
        return remove(begin().next(index), ++(begin().next(index)));
    }

    iterator remove(const iterator &iterator){
        auto next_node = iterator + 1;
        return remove(iterator, next_node);
    }

    iterator remove(size_t from, size_t to) {
        return remove(begin().next(from), begin().next(to));
    }

    iterator remove(const iterator &from, const iterator &to){
        Node<T> *left = from.getPointer()->getLeft();
        Node<T> *right = to.getPointer();

        if(from == begin())
            head_ = right;

        Node<T> *current = from.getPointer();
        while(current != right){
            Node<T> *tmp(current);
            current = current->getRight();
            tmp->~Node();
        }

        if(left != nullptr)
            left->setRight(right);

        if(right != nullptr)
            right->setLeft(left);

        --size_;

        return iterator {current};
    }

};

#endif