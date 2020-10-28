#pragma once

#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;

template <typename DataType>
class NodeStack {
   public:
    DataType data;
    NodeStack<DataType>* next;
    NodeStack() {
        next = nullptr;
    }
};

template <typename DataType>
class Stack {
    NodeStack<DataType>* top;

   public:
    Stack() {
        top = nullptr;
    }

    void push(DataType val) {
        NodeStack<DataType>* new_node = new (nothrow) NodeStack<DataType>();  // to avoid bad alloc exception to be thrown
        if (!new_node) {
            cout << "Memory allocation failed\n";
            return;
        }
        new_node->data = val;
        new_node->next = top;
        top = new_node;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack Underflow.\n";
            return;
        }
        Node<DataType>* del_node = top;
        top = top->next;
        delete del_node;
    }

    NodeStack<DataType>* peek() {
        return top;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void display() {
        Stack<DataType> temp;
        DataType curr;
        while (!isEmpty()) {
            curr = peek()->data;
            pop();
            temp.push(curr);
            cout << curr << " ";
        }
        while (!temp.isEmpty()) {
            curr = temp.peek()->data;
            temp.pop();
            push(curr);
        }
        cout << "\n";
    }
};