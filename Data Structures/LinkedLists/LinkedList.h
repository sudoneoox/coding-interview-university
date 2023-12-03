#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <fstream>

template <typename T>
struct NODE
{
    T val;
    struct NODE *next;
    struct NODE *prev;
    struct NODE(T _val) : val(_val);
};

template <typename T>
class LINKEDLIST
{
private:
    struct NODE *head;
    int count;

public:
    LINKEDLIST();
    ~LINKEDLIST();
    int size();
    bool empty();
    T value_at(int _idx);
    void push_front(T _val);
    void pop_front();
    T front();
    T back();
    void insert(T _idx, T _val);
    void erase(T _idx);
    void value_n_from_end(int _n);
    void reverse();
    void remove_value(T _val);
    friend std::ostream &operator<<(std::ostream &COUT, LINKEDLIST<T> &RHS);
};

#endif // LINKEDLIST_H