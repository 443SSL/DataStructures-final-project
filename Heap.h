#ifndef HEAP_H_
#define HEAP_H_

#include<stdexcept>
#include<string>



// An exception that is thrown when you try to do something with too few items
// in the heap.
class HeapUnderflow : public std::underflow_error {

public:

    HeapUnderflow(const std::string& what) : std::underflow_error(what) { }

} ;


// An exception that is thrown when you try to do something with too many items
// in the heap.
class HeapOverflow : public std::overflow_error {

public:

    HeapOverflow(const std::string& what) : std::overflow_error(what) { }

} ;





template<class T, int m_size> class Heap{

public:

    // required functions by UML
    Heap();
    Heap(const Heap<T, m_size>& origHeap);

    bool Contains(const T& needle) const;

    const T* Find(const T& needle) const;

    T& Remove();

    void Insert(T& insertable);

    virtual void PercolateUp(int index);

    virtual void PercolateDown(int index);


protected:

    // UML-required member variables
    // Doc says we can promote from private to protected if we override
    T* m_array[m_size + 1];
    int m_currentSize;


    // These get the pointers to a nodes children and parents based on the pin
    // number.
    //
    // Take:        The pin number of a node.
    // Returns:     A pointer to that node's child or parent. NULL if it has none.


    int GetParentIndex(int index) const;


    int FindIndex(int pin);

    bool isEmpty();
private:

    // This is to prevent magic numbers.
    static const int ROOT_INDEX = 1;
};

#include "Heap.cpp"

#endif /* HEAP_H_ */
