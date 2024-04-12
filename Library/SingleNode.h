#pragma once
#include <memory>

using namespace std;
template<typename T>
struct Node
{
	T data;
	unique_ptr<Node<T>> next;
	Node(T value) : data{ value }, next{ nullptr } {};
};

