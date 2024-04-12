#pragma once
#include<memory>

using namespace std;
template<typename T>

struct Node
{
    T data;
    shared_ptr<Node<T>> next;
    weak_ptr<Node<T>> previous;

    Node(T value) : data{ value } {}
};

