#pragma once

#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;

template <typename DataType>
class Queue {
    DataType* data;
    int max_length;
    int front;
    int rear;

   public:
    Queue(int length) {
        data = new DataType[length];
        max_length = length;
        front = rear = -1;
    }

    void enqueue(DataType val) {
        if (length() == max_length) {
            cout << "Queue is full.\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % max_length;
        }
        data[rear] = val;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % max_length;
        }
    }

    DataType* getFront() {
        if (isEmpty()) {
            return nullptr;
        }
        return &data[front];
    }

    bool isEmpty() {
        return front == -1;
    }

    int length() {
        if (isEmpty()) {
            return 0;
        }
        return (rear - front + max_length) % max_length + 1;
    }

    void display() {
        Queue<DataType> temp(max_length);
        DataType curr;
        while (!isEmpty()) {
            curr = *getFront();
            dequeue();
            temp.enqueue(curr);
            cout << curr << " ";
        }
        while (!temp.isEmpty()) {
            curr = *(temp.getFront());
            temp.dequeue();
            enqueue(curr);
        }
        cout << "\n";
    }
    void reverse() {
        if (isEmpty()) {
            return;
        }
        DataType curr = *getFront();
        cout << curr << " ";
        dequeue();
        reverse();
        enqueue(curr);
    }
};