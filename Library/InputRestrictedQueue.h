#pragma once


#include "QueueNode.h"
#include <iostream>
#include <stdexcept>


using namespace std;
template<typename T>
class InputRestrictedQueue
{
private:
	shared_ptr<Node<T>> front;
	weak_ptr<Node<T>> rear;
public:
	Queue() : front(nullptr), rear(nullptr) {}
	void EnqueueFront(T item) {
		shared_ptr<Node<T>> newNode = make_shared<Node<T>>(item);
		if (!front) {
			front = newNode;
			rear = front;
		}
		else {
			newNode->next = front;
			front->prev = newNode;
			front = newNode;
		}
	}
	void EnqueueBack(T item) {
		shared_ptr<Node<T>> newNode = make_shared<Node<T>>(item);
		if (!rear) {
			front = newNode;
			rear = front;
		}
		else {
			shared_ptr<Node<T>> rearptr = rear.lock();
			rearptr->next = newNode;
			newNode->prev = rearptr;
			rear = newNode;
		}
	}
	T DequeueFront() {
		if (IsEmpty()) {
			throw out_of_range("Queue is empty");
		}
		T item = front->data;
		front = front->next;
		if (front) {
			front->prev.reset();
		}
		else {
			rear.reset();
		}
		return item;
	}
	T PeekFront() {
		if (IsEmpty()) {
			throw out_of_range("Queue is empty");
		}
		return front->data;
	}
	bool IsEmpty() {
		return front == nullptr;
	}
};

