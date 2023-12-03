#ifndef ARRAYS_H
#define ARRAYS_H
#include <iostream>

// Vector Dynamic Array
template <typename T>
class DynamicArray
{
private:
    int count;
    T *vals;
    int memSize;
    void allocateMoreMem(int _newmem);
    int *findItems(T _val);

public:
    DynamicArray();
    ~DynamicArray();
    int capacity();
    int size();
    bool isEmpty();
    T at(int _idx);
    void push(T _val);
    void insert(int _idx, T _val);
    void pop();
    void remove(int _idx);
    // void removeItems(int _val); // implement later
    void print();
    void prepend(T _val);

    int find(T _val);
};

#endif // ARRAYS_H