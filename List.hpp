#ifndef LIST_H_
#define LIST_H_

#include <cstdio>
#include "Node.hpp"

template<class T>
class List {
private:
    size_t size_;
    std::shared_ptr<const Node<T>> tail_, head_;

public:
    typedef T value_type;
    typedef ptrdiff_t difference_type;
    typedef T* pointer;
    typedef T& reference ;
    typedef std::bidirectional_iterator_tag iterator_category ;

    class ListIterator {
    private:
        const std::shared_ptr<const Node<T>> p_;
    public:
        ListIterator(std::shared_ptr<const Node<T>> p): p_(p){};

        ListIterator& operator++(){
            p_ = p_->getRight();
            return *this;
        }

        ListIterator operator++(int){
            ListIterator tmp(*this);
            operator++();
            return tmp;
        }

        ListIterator& operator--(){
            p_ = p_->getLeft();
            return *this;
        }

        ListIterator operator--(int){
            ListIterator tmp(*this);
            operator--();
            return tmp;
        }

        bool operator==(const ListIterator& rhs) const {
            return p_ == rhs.p_;
        }

        bool operator!=(const ListIterator& rhs) const {
            return p_ != rhs.p_;
        }

        T&operator*() const {
            return *p_;
        };
    };

//    List() : size_(0), tail_(new Node(nullptr)), head_(new Node(nullptr)) {};

//    void push_back(const T& val);
};

#endif