#include "SimpleList.h"
#include "EmptyListException.h"
#include "FullListException.h"
#include "InvalidIndexException.h"
#include <type_traits>

using namespace std;

template <class T>
SimpleList<T>::SimpleList() {
    elements = new T[CAPACITY];
    numElements = 0;
}

template <class T>
void destroy(T element) {
}

template <class T>
void destroy(T* element) {
    delete element;
}

template <class T>
SimpleList<T>::~SimpleList() {
    if (is_pointer<T>::value) {
        for (int i = 0; i < numElements; i++) {
            destroy(elements[i]);
        }
        delete [] elements;
    }
    else {
        delete [] elements;
    }
}

template <class T>
T SimpleList<T>::at(int index) const throw(InvalidIndexException) {
    if (index < 0 || index >= numElements) {
        InvalidIndexException a;
        throw a;
    }
    else {
        return elements[index];
    }
}

template <class T>
bool SimpleList<T>::empty() const {
    if (numElements == 0) {
        return true;
    }
    else {
        return false;
    }
}

template <class T>
T SimpleList<T>::first() const throw (EmptyListException) {
    if (numElements == 0) {
        EmptyListException b;
        throw b;
    }
    else {
        return elements[0];
    }
}

template <class T>
T SimpleList<T>::last() const throw (EmptyListException) {
    if (numElements == 0) {
        EmptyListException b;
        throw b;
    }
    else {
        return elements[numElements - 1];
    }
}

template<class T>
int SimpleList<T>::getNumElements() const {
    return numElements;
}

template<class T>
void SimpleList<T>::insert(T item) throw (FullListException) {
    if (numElements == CAPACITY) {
        FullListException c;
        throw c;
    }
    else {
        elements[numElements] = item;
        numElements ++;
    }
}

template<class T>
void SimpleList<T>::remove(int index) throw (InvalidIndexException, EmptyListException) {
    if (numElements == 0) {
        EmptyListException b;
        throw b;
    }
    else if (index < 0 || index >= numElements) {
        InvalidIndexException a;
        throw a;
    }
    else {
        destroy(elements[index]);
        for (int i = index; i < numElements; i++) {
            elements[i] = elements[i + 1];
        }
        numElements --;
    }
}
