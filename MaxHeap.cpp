//
// Created by jdlen on 4/15/2020.
//

#ifndef MAXHEAP_CPP_
#define MAXHEAP_CPP_


#include "MaxHeap.h"

template<class T, int m_size>
MaxHeap<T, m_size>::MaxHeap() {

    typename Heap<T, m_size>::Heap();
}




template<class T, int m_size>
void MaxHeap<T, m_size>::PercolateUp(int index) {
    T* temp = this->m_array[index];

    for( ;
            index > 1 &&
            temp->CompareTo(*(this->m_array[ index/2 ])) > 0;
            index /= 2 ) {
        temp = this->m_array[ index ];
        this->m_array[ index ] = this->m_array[ index / 2 ];

    }

    this->m_array[ index ] = temp;
}




template<class T, int m_size>
void MaxHeap<T, m_size>::PercolateDown(int index) {
    int child;
    T* tmp = this->m_array[ index ];

    for( ; index * 2 <= this->m_currentSize; index = child ) {


        child = index * 2;


        if(child != this->m_currentSize && this->m_array[ child + 1 ]->CompareTo(*(this->m_array[ child ])) > 0 ) {

            child++;
        }


        if( tmp->CompareTo(*(this->m_array[ child ])) < 0 ) {

            this->m_array[ index ] = this->m_array[ child ];
        } else {

            break;
        }
        this->m_array[ index ] = tmp;
    }
}


#endif /* MAXHEAP_CPP_ */