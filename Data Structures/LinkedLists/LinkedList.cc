#include "./LinkedList.h"

template <typename T>
LINKEDLIST<T>::LINKEDLIST()
{
    head.next = nullptr;
    head.prev = nullptr;
    count = 0;
}

template <typename T>
int LINKEDLIST<T>::size()
{
    return count;
}

template <typename T>
bool LINKEDLIST<T>::empty()
{
    return count == 0;
}

template <typename T>
T LINKEDLIST<T>::value_at(int _idx)
{
    return _idx;
}

template <typename T>
void LINKEDLIST<T>::push_front(T _val)
{
}

template <typename T>
std::ostream &operator<<(std::ostream &COUT, LINKEDLIST<T> &RHS)
{
    COUT << "LINKED LIST: " for (int i = 0; i < count; i++)
    {
        cout << RHS.next << " ";
    }
    return COUT;
}