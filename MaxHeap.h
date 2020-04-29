//
// Created by jdlen on 4/15/2020.
//

#ifndef PROJ4_MAXHEAP_H
#define PROJ4_MAXHEAP_H

#include "Heap.h"

template<class T, int m_size>
class MaxHeap : public Heap<T, m_size> {
public:
    MaxHeap();

    MaxHeap(const Heap<T, m_size>& heap) : Heap<T, m_size>::Heap(heap) {};

    void PercolateUp(int index);

    void PercolateDown(int index);

};

#include "MaxHeap.cpp"
#endif //PROJ4_MAXHEAP_H
