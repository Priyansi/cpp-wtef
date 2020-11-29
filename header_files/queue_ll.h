#pragma once

#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;

template <typename DataType>
class NodeQueue {
   public:
    DataType data;
    NodeQueue<DataType>* next;
    NodeQueue() {
        next = nullptr;
    }
};

template <typename DataType>
class Queue {
    NodeQueue<DataType>* front;
    NodeQueue<DataType>* rear;

   public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(DataType val) {
        NodeQueue<DataType>* new_node = new (nothrow) NodeQueue<DataType>();  // to avoid bad alloc exception to be thrown
        if (!new_node) {
            cout << "Memory allocation failed\n";
            return;
        }
        new_node->data = val;
        if (isEmpty()) {
            front = rear = new_node;
        } else {
            rear->next = new_node;
            rear = new_node;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        NodeQueue<DataType>* del_node = front;
        if (front == rear) {
            front = rear = nullptr;
        } else {
            front = front->next;
        }
        delete del_node;
    }

    NodeQueue<DataType>* getFront() {
        return front;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    int length() {
        if (front == rear) {
            return 1;
        }
        DataType curr = getFront()->data;
        dequeue();
        int len = length() + 1;
        enqueue(curr);
        return len;
    }

    void display() {
        Queue<DataType> temp;
        DataType curr;
        while (!isEmpty()) {
            curr = getFront()->data;
            dequeue();
            temp.enqueue(curr);
            cout << curr << " ";
        }
        while (!temp.isEmpty()) {
            curr = temp.getFront()->data;
            temp.dequeue();
            enqueue(curr);
        }
        cout << "\n";
    }
    void reverse() {
        if (isEmpty()) {
            return;
        }
        DataType curr = getFront()->data;
        dequeue();
        reverse();
        enqueue(curr);
    }
};