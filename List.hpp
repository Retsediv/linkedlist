#ifndef LIST_H_
#define LIST_H_

#include <cstdio>
#include "Node.hpp"

template <class T>
class List {
private:
    class ListIterator : public std::iterator<std::forward_iterator_tag, Node> {
    private:
        std::shared_ptr<Node> p_;
    public:
        ListIterator(): p_(nullptr){};
        explicit ListIterator(Node* p): p_(p){};
        explicit ListIterator(const ListIterator& li): p_(li.p_){};

        ListIterator& operator++() {
            p_ = p_->getRight();
            return *this;
        }

        ListIterator operator++(int) {
            ListIterator tmp(*this);
            operator++();
            return tmp;
        }
    };

    size_t size_;
    ListIterator tail_, head_;

    public:
    List(): size_(0), tail_(nullptr), head_(nullptr){};

    void push_back(const T& val);
};

//template<class T>
//void List<T>::push_back(const T &val) {
//    if(tail_ == nullptr){
//        tail_ = new Node(val);
//        head_ = tail_;
//    } else {
//        auto tmp = new Node(val, head_);
//        (*head_).setRight(tmp);
//        head_ = tmp;
//    }
//}

#endif