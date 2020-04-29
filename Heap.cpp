#ifndef HEAP_CPP_
#define HEAP_CPP_

#include "Heap.h"

template<class T, int m_size>
Heap<T, m_size>::Heap() {
    this->m_currentSize = 0;
}



template<class T, int m_size>
Heap<T, m_size>::Heap(const Heap<T, m_size>& originHeap) {

    this->m_currentSize = originHeap.m_currentSize;

    for(int i = 0; i <= originHeap.m_currentSize; i++) {
        this->m_array[i] = originHeap.m_array[i];
    }
    delete originHeap;
}



template<class T, int m_size>
bool Heap<T, m_size>::Contains(const T& needle) const {

    for(int i = ROOT_INDEX; i < this->m_currentSize + 1; i++) {

        if(this->m_array[i] == needle) {
            return true;
        }

    }

    return false;

}



template<class T, int m_size>
const T* Heap<T, m_size>::Find(const T& needle) const {

    for(int i = ROOT_INDEX; i < this->m_currentSize + 1; i++) {

        if(this->m_array[i] == needle) {
            return this->m_array[i];
        }

    }

}



template<class T, int m_size>
T& Heap<T, m_size>::Remove() {

    if(isEmpty()) {
        throw HeapUnderflow("No nodes to remove");
    }

    T* toReturn = this->m_array[ROOT_INDEX];

    // Move the node at the rear to the front and sets the rear node to NULL.
    this->m_array[ROOT_INDEX] = this->m_array[m_currentSize];
    this->m_array[m_currentSize] = NULL;

    this->m_currentSize--;

    PercolateDown(ROOT_INDEX);

    return *toReturn;

}



template<class T, int m_size>
void Heap<T, m_size>::Insert(T& insertable) {

    if(this->m_currentSize + 1 > m_size) {
        throw HeapOverflow("The heap is at max capacity.");
    }

    this->m_currentSize++;

    this->m_array[m_currentSize] = &insertable;

    this->PercolateUp(m_currentSize);

}

template<class T, int m_size>
void Heap<T, m_size>::PercolateUp(int index) {

    // The parent index saved. This means we only have to call another method
    // logn + 1 times vs the 3logn we needed before.

    T* temp = this->m_array[index];

    for( ;
            index > 1 &&                                   // Make sure we aren't above the top yet
            temp->CompareTo(*(this->m_array[ index/2 ])) < 0;    // If temp is less than the parent, knock us up
            index /= 2 ) {                              // Set index to the parent.
        temp = this->m_array[ index ];
        this->m_array[ index ] = this->m_array[ index / 2 ];  // swap, from child to parent

    }

    this->m_array[ index ] = temp;


}



template<class T, int m_size>
void Heap<T, m_size>::PercolateDown(int index) {


    int child;
    T* tmp = this->m_array[ index ];

    for( ; index * 2 <= this->m_currentSize; index = child ) {


        child = index * 2;


        if(child != this->m_currentSize && this->m_array[ child + 1 ]->CompareTo(*(this->m_array[ child ])) < 0 ) {

            child++;
        }


        if( tmp->CompareTo(*(this->m_array[ child ])) > 0 ) {

            this->m_array[ index ] = this->m_array[ child ];
        } else {

            break;
        }
    }

    this->m_array[ index ] = tmp;

}

template<class T, int m_size>
int Heap<T,m_size>::GetParentIndex(int index) const {

    return index / 2;

}


template<class T, int m_size>
int Heap<T,m_size>::FindIndex(int pin) {

    for(int i = ROOT_INDEX; i < m_currentSize + 1; i++) {

        if(m_array[i]->GetKey() == pin) {
            return i;
        }

    }

}


// Checks to see if the heap is empty.
template<class T, int m_size>
bool Heap<T, m_size>::isEmpty() {
    return m_currentSize <= 0;
}


#endif /* HEAP_CPP_ */
