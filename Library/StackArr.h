#pragma once


#include <stdexcept>
#define MAX_SIZE 20



using namespace std;
template<typename T>
class StackArr
{
    private:
    T arr[MAX_SIZE];
    int size;
public:
    StackArr() : size{ 0 } {}

    StackArr(T data) : size{ 1 } { arr[0] = data; }

    void push(T data) {
        if (size == 0) throw std::overflow_error("Stack overflow!");

        arr[size] = data;
        size++;
    }

    T pop() {
        if (size == MAX_SIZE) throw std::out_of_range("Stack is empty!");

        size--;
        return arr[size];
    }

    T peek() { return arr[size - 1]; }

    bool isEmpty() { return size == 0; }

    bool isFull() { return size == MAX_SIZE; }
};

