#ifndef LIST_ITERATOR_H_
#define LIST_ITERATOR_H_

template<class T>
class ListIterator {
private:
    Node<T> *data_;
public:
    typedef T value_type;
    typedef intmax_t difference_type;
    typedef T *pointer;
    typedef T &reference;
    typedef std::bidirectional_iterator_tag iterator_category;

    explicit ListIterator(Node<T> *data) : data_(data) {}
    explicit ListIterator(const Node<T> *data) : data_(data) {}

    ListIterator<T> &operator=(const ListIterator<T> &rhs) noexcept {
        data_ = rhs.data_;
        return *this;
    }

    ListIterator<T> &operator++() {
//        if(data_->getRight() != nullptr){
        data_ = data_->getRight();
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
//        if(data_->getLeft() != nullptr){
        data_ = data_->getLeft();
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
        return data_ == rhs.data_;
    }

    bool operator!=(const ListIterator<T> &rhs) const {
        return data_ != rhs.data_;
    }

    const T &operator*() const {
        return data_->getValue();
    };

    T &operator*() {
        return data_->getValue();
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
        return data_;
    }
};

#endif