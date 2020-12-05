#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <utility>
/*
Description - 
Time Complexity - 
Space Complexity - 
*/

using namespace std;

template <typename DataType>
class Node {
   public:
    DataType data;
    Node<DataType> *next;
    Node() {
        next = nullptr;
    }
};

template <typename DataType>
class SingleLinkedList {
    Node<DataType> *head;
    int length;

    void incrementLength() {
        ++length;
    }

    void decrementLength() {
        --length;
    }

   public:
    SingleLinkedList() {
        head = nullptr;
        length = 0;
    }

    void insertNodeAtEnd(DataType val) {
        Node<DataType> *new_node = new (nothrow) Node<DataType>();  // to avoid bad alloc exception to be thrown
        if (!new_node) {
            cout << "Memory allocation failed\n";
            return;
        }
        new_node->data = val;
        if (head == nullptr) {
            head = new_node;
        } else {
            Node<DataType> *curr_node;
            for (curr_node = head; curr_node->next != nullptr; curr_node = curr_node->next)
                ;
            curr_node->next = new_node;
        }
        incrementLength();
    }

    void displayNodes() {
        if (head != nullptr) {
            for (Node<DataType> *curr_node = head; curr_node != nullptr; curr_node = curr_node->next) {
                cout << curr_node->data << "->";
            }
        }
        cout << "NULL\n";
    }

    friend SingleLinkedList<DataType> getIntersection(SingleLinkedList<DataType> list1, SingleLinkedList<DataType> list2) {
        SingleLinkedList<DataType> intersection_list;
        unordered_map<DataType, int> elements;
        Node<DataType> *curr_node;
        for (curr_node = list1.head; curr_node != nullptr; curr_node = curr_node->next) {
            if (elements.find(curr_node->data) != elements.end()) {
                ++elements[curr_node->data];
            } else {
                elements[curr_node->data] = 1;
            }
        }
        for (curr_node = list2.head; curr_node != nullptr; curr_node = curr_node->next) {
            if (elements.find(curr_node->data) != elements.end()) {
                ++elements[curr_node->data];
            } else {
                elements[curr_node->data] = 1;
            }
        }
        for (auto i : elements) {
            if (i.second > 1) {
                intersection_list.insertNodeAtEnd(i.first);
            }
        }
        return intersection_list;
    }
};

int main() {
    SingleLinkedList<int> list1;
    SingleLinkedList<int> list2;
    list1.insertNodeAtEnd(10);
    list1.insertNodeAtEnd(20);
    list1.insertNodeAtEnd(80);
    list1.insertNodeAtEnd(20);
    list1.insertNodeAtEnd(60);
    list2.insertNodeAtEnd(15);
    list2.insertNodeAtEnd(20);
    list2.insertNodeAtEnd(30);
    list2.insertNodeAtEnd(60);
    list2.insertNodeAtEnd(60);
    list2.insertNodeAtEnd(45);
    SingleLinkedList<int> intersection_list = getIntersection(list1, list2);
    intersection_list.displayNodes();
    return 0;
}