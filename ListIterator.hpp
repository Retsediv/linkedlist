#ifndef LIST_ITERATOR_H_
#define LIST_ITERATOR_H_

template<class T>
class ListIterator {
private:
    Node<T> *p_;
public:
    typedef T value_type;
    typedef intmax_t difference_type;
    typedef T *pointer;
    typedef T &reference;
    typedef std::bidirectional_iterator_tag iterator_category;

    explicit ListIterator(Node<T> *p) : p_(p) {}

    explicit ListIterator(const Node<T> *p) : p_(p) {}

    ListIterator<T> &operator=(const ListIterator<T> &rhs) noexcept {
        p_ = rhs.p_;

        return *this;
    }

    ListIterator<T> &operator++() {
//        if(p_->getRight() != nullptr){
        p_ = p_->getRight();
        return *this;
//        }
//        throw OutOfBoundException();
    }

    ListIterator<T> operator++(int) {
        ListIterator<T> tmp(*this);
        operator++();
        return tmp;
    }

    ListIterator<T> operator+(size_t size) const {
        ListIterator<T> tmp(*this);
        return tmp.next(size);
    }

    ListIterator<T> &operator--() {
//        if(p_->getLeft() != nullptr){
        p_ = p_->getLeft();
        return *this;
//        }
//
//        throw OutOfBoundException();
    }

    ListIterator<T> operator--(int) {
        ListIterator<T> tmp(*this);
        operator--();
        return tmp;
    }

    ListIterator<T> operator-(size_t size) const {
        ListIterator<T> tmp(*this);
        return tmp.prev(size);
    }

    bool operator==(const ListIterator<T> &rhs) const {
        return p_ == rhs.p_;
    }

    bool operator!=(const ListIterator<T> &rhs) const {
        return p_ != rhs.p_;
    }

    Node<T> *operator*() const {
        return p_;
    };

    ListIterator<T> &next(size_t n) {
        for (size_t i = 0; i < n; ++i) {
            operator++();
        }
        return *this;
    }

    ListIterator<T> &prev(size_t n) {
        for (size_t i = 0; i < n; ++i) {
            operator--();
        }
        return *this;
    }

    Node<T> *getPointer() const {
        return p_;
    }
};

#endif