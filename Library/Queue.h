#pragma once
#include "QueueNode.h"
#include <iostream>
#include <stdexcept>


using namespace std;
template<typename T>
class Queue
{
private:
	shared_ptr<Node<T>> front;
	weak_ptr<Node<T>> rear;
public:
    Queue() : front(nullptr), rear(nullptr){}
	void Enqueue(T data) {
		shared_ptr<Node<T>> newNode = make_shared<Node<T>>(data);
		if (IsEmpty()) {
			front = rear = newNode;
		}
		else {
			rear->next = newNode;
			newNode->prev = rear;
			rear = newNode;
		}

	}
	T Dequeue() {
		if (IsEmpty()) {
			throw out_of_range("Queue is empty");
		}
		T data = front->next;
		if (front == rear) {
			front = rear = nullptr;
		}
		else {
			front = front->next;
			front->prev = nullptr;
		}
		return data;
	}
	T Peek() {
		if (IsEmpty()) {
			throw out_of_range("Queue is empty");
		}
		return front->data;
	}
	bool IsEmpty() {
		return front == nullptr;
	}
};

