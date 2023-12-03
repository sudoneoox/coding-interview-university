#include "./arrays.h"

template <typename T>
DynamicArray<T>::DynamicArray()
{
    count = 0;
    memSize = 4;
    vals = new T[memSize];
}

template <typename T>
DynamicArray<T>::~DynamicArray()
{
    if (vals != nullptr)
    {
        delete[] vals;
    }
}

template <typename T>
void DynamicArray<T>::allocateMoreMem(int _newMem)
{
    memSize = _newMem;
    T *tmpvals = new T[memSize];
    for (int i = 0; i < count; i++)
        tmpvals[i] = vals[i];
    delete[] vals;
    vals = tmpvals;
}

template <typename T>
int DynamicArray<T>::capacity()
{
    return memSize;
}

template <typename T>
int DynamicArray<T>::size()
{
    return count;
}

template <typename T>
bool DynamicArray<T>::isEmpty()
{
    return count == 0;
}

template <typename T>
T DynamicArray<T>::at(int _idx)
{
    return vals[_idx];
}

template <typename T>
void DynamicArray<T>::push(T _val)
{
    if (count >= memSize)
    {
        allocateMoreMem(memSize * 2);
    }
    vals[count] = _val;
    ++count;
}

template <typename T>
void DynamicArray<T>::prepend(T _val)
{
    insert(0, _val);
}

template <typename T>
void DynamicArray<T>::insert(int _idx, T _val)
{

    if (count + 1 <= memSize)
    {
        ++count;
        bool append = false;
        T *tmpVals = new T[memSize];
        for (int i = 0; i < count; i++)
        {
            if (i == _idx)
            {
                tmpVals[i] = _val;
                append = true;
            }
            if (append)
                tmpVals[i + 1] = vals[i];
            else
                tmpVals[i] = vals[i];
        }
        delete[] vals;
        vals = tmpVals;
    }
    else
    {
        allocateMoreMem(memSize * 2);
        insert(_idx, _val);
    }
}

template <typename T>
void DynamicArray<T>::pop()
{
    --count;
    if (memSize / 4 > count)
    {
        allocateMoreMem(memSize / 2);
    }
    vals[count] = '\0';
}

template <typename T>
void DynamicArray<T>::remove(int _idx)
{
    if (_idx > count - 1)
    {
        std::cout << "Not a valid index" << std::endl;
        return;
    }
    T *tmpVals = new T[memSize];
    bool skipped = false;
    for (int i = 0; i < count; i++)
    {
        if (i == _idx)
            skipped = true;
        if (skipped)
        {
            tmpVals[i] = vals[i + 1];
        }
        else
        {
            tmpVals[i] = vals[i];
        }
    }
    --count;
    delete[] vals;
    vals = tmpVals;
    if (memSize / 4 > count)
    {
        allocateMoreMem(memSize / 2);
    }
}

// template <typename T>
// void DynamicArray<T>::removeItems(int _val)
// {
//     T *indexArr = new T[count];
//     indexArr = findItems(_val);
//     for (int i = 0; i < sizeof(indexArr); i++)
//     {
//         vals[indexArr[i]] = '\0';
//     }
// T *tmpVals = new T[count];
// for (int i = 0; i < count; i++)
// {
//     if (vals[i] == '\0')
//     {
//         --count;
//     }
// }
// }

template <typename T>
int DynamicArray<T>::find(T _val)
{
    for (int i = 0; i < count; i++)
    {
        if (vals[i] == _val)
            return i;
    }
    return -1;
}

template <typename T>
int *DynamicArray<T>::findItems(T _val)
{
    T *idx = new T[count];
    int j = 0;
    for (int i = 0; i < count; i++)
    {
        if (vals[i] == _val)
        {
            idx[j] = i;
            ++j;
        }
    }
    return idx;
}

template <typename T>
void DynamicArray<T>::print()
{
    for (int i = 0; i < count; i++)
    {
        std::cout << vals[i] << " ";
    }
    std::cout << '\n';
}