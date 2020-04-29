//
// Created by jdlen on 4/15/2020.
//

#ifndef PROJ4_MINHEAP_H
#define PROJ4_MINHEAP_H

#include "Heap.h"


template<class T, int m_size>
class MinHeap : public Heap<T, m_size> {
public:
    MinHeap();

    MinHeap(const Heap<T, m_size>& heap) : Heap<T, m_size>::Heap(heap) {};

    void PercolateUp(int index);

    void PercolateDown(int index);
};

#include "MinHeap.cpp"

#endif //PROJ4_MINHEAP_H
