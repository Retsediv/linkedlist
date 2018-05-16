#ifndef LINKEDLIST_EXCEPTION_H
#define LINKEDLIST_EXCEPTION_H

#include <exception>

class ListException : public std::exception {
    const char *what() const noexcept {
        return "Exception occurred with List";
    }
};

class ListIteratorException : public std::exception {
    const char *what() const noexcept {
        return "Exception occurred with ListIterator";
    }
};

class OutOfBoundException : public ListIteratorException {
    const char *what() const noexcept {
        return "You are trying to get element from nonexistent pointer";
    }
};

#endif
