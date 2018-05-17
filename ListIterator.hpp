#ifndef LIST_ITERATOR_H_
#define LIST_ITERATOR_H_

template<class T>
class ListIterator {
private:
    Node<T>* p_;
public:
    typedef T value_type;
    typedef intmax_t difference_type;
    typedef T *pointer;
    typedef T &reference;
    typedef std::bidirectional_iterator_tag iterator_category;

    explicit ListIterator(Node<T>* p) : p_(p) {}

    ListIterator &operator=(const ListIterator<T> &rhs) noexcept {
        p_ = rhs.p_;

        return *this;
    }

    ListIterator &operator++() {
//        if(p_->getRight() != nullptr){
            p_ = p_->getRight();
            return *this;
//        }
//        throw OutOfBoundException();
    }

    ListIterator operator++(int) {
        ListIterator tmp(*this);
        operator++();
        return tmp;
    }

    ListIterator &operator--() {
//        if(p_->getLeft() != nullptr){
            p_ = p_->getLeft();
            return *this;
//        }
//
//        throw OutOfBoundException();
    }

    ListIterator operator--(int) {
        ListIterator tmp(*this);
        operator--();
        return tmp;
    }

    bool operator==(const ListIterator &rhs) const {
        return p_ == rhs.p_;
    }

    bool operator!=(const ListIterator &rhs) const {
        return p_ != rhs.p_;
    }

    Node<T> *operator*() const {
        return p_;
    };

    ListIterator& next(size_t n){
        for (int i = 0; i < n; ++i) {
            operator++();
        }
        return *this;
    }

    ListIterator& prev(size_t n){
        for (int i = 0; i < n; ++i) {
            operator--();
        }
        return *this;
    }

    Node<T>* getPointer() const {
        return p_;
    }
};

#endif