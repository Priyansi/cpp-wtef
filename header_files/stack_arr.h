#pragma once

#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;

template <typename DataType>
class Stack {
    DataType* data;
    int max_length;
    int top;

   public:
    Stack(int length) {
        data = new DataType[length];
        max_length = length;
        top = -1;
    }

    void push(DataType val) {
        if (top == max_length - 1) {
            cout << "Stack Overflow.\n";
            return;
        }
        ++top;
        data[top] = val;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow.\n";
            return;
        }
        --top;
    }

    DataType* peek() {
        if (isEmpty()) {
            return nullptr;
        }
        return &data[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    void display() {
        Stack<DataType> temp(max_length);
        DataType curr;
        while (!isEmpty()) {
            curr = *peek();
            pop();
            temp.push(curr);
            cout << curr << " ";
        }
        while (!temp.isEmpty()) {
            curr = *(temp.peek());
            temp.pop();
            push(curr);
        }
        cout << "\n";
    }
};