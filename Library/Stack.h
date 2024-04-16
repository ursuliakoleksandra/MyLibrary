#pragma once
#include "StackNode.h"
#include <iostream>
#include <stdexcept>


using namespace std;
template <typename T>
class Stack
{
private:
	unique_ptr<Node<T>> top;
public:
	Stack() : top(nullptr) {}
	void Push(T data) {
		unique_ptr<Node<T>> newNode = make_unique<Node<T>>(data);
		newNode->next = move(top);
		top = move(newNode);
	}
	T Pop() {
		if (IsEmpty()) {
			throw out_of_range("Stack is empty");
		}
		T data = top->data;
		top = move(top->next);
		return data;
	}
	T Peek() {
		if (IsEmpty()) {
			throw out_of_range("Stack is empty");
		}
		return top->data;
	}
	bool IsEmpty() {
		return top == nullptr;
	}
};

