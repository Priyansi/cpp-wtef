#pragma once

#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>

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

    auto _reverseNodesRecursive(Node<DataType> *curr) {
        if (curr->next == nullptr) {
            head = curr;
            return curr;
        }
        Node<DataType> *prev = _reverseNodesRecursive(curr->next);
        prev->next = curr;
        curr->next = nullptr;
        return curr;
    }

    Node<DataType> *merge(Node<DataType> *head1, Node<DataType> *head2) {
        Node<DataType> *sorted_head = nullptr;
        if (head1 == nullptr) {
            return head2;
        }
        if (head2 == nullptr) {
            return head1;
        }
        if (head1->data < head2->data) {
            sorted_head = head1;
            sorted_head->next = merge(head1->next, head2);
        } else {
            sorted_head = head2;
            sorted_head->next = merge(head1, head2->next);
        }
        return sorted_head;
    }

    pair<Node<DataType> *, Node<DataType> *> split(Node<DataType> *head) {
        pair<Node<DataType> *, Node<DataType> *> two_halves;
        Node<DataType> *slow_ptr = head;
        Node<DataType> *fast_ptr = slow_ptr->next;
        // to find the mid node
        while (fast_ptr != nullptr) {
            fast_ptr = fast_ptr->next;
            if (fast_ptr != nullptr) {
                slow_ptr = slow_ptr->next;
                fast_ptr = fast_ptr->next;
            }
        }
        two_halves.first = head;
        two_halves.second = slow_ptr->next;
        slow_ptr->next = nullptr;
        return two_halves;
    }

    Node<DataType> *sortRecursive(Node<DataType> *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        pair<Node<DataType> *, Node<DataType> *> two_halves = split(head);
        two_halves.first = sortRecursive(two_halves.first);
        two_halves.second = sortRecursive(two_halves.second);
        return merge(two_halves.first, two_halves.second);
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

    void insertNodeAtIndex(DataType val, int ind_to_insert) {
        Node<DataType> *new_node = new (nothrow) Node<DataType>();  // to avoid bad alloc exception to be thrown
        if (!new_node) {
            cout << "Memory allocation failed\n";
            return;
        }
        new_node->data = val;
        if (head == nullptr) {
            head = new_node;
        } else if (ind_to_insert == 0) {  // insert at head
            new_node->next = head;
            head = new_node;
        } else {
            Node<DataType> *curr_node = head;
            Node<DataType> *prev_node;
            int curr_ind = 0;
            while (curr_ind < ind_to_insert && curr_node != nullptr) {  // insert at index or insert at last if index not found
                ++curr_ind;
                prev_node = curr_node;
                curr_node = curr_node->next;
            }
            new_node->next = curr_node;
            prev_node->next = new_node;
        }
        incrementLength();
    }

    void deleteNodeAtEnd() {
        if (head == nullptr) {
            cout << "Empty list. No node to delete.\n";
        } else {
            Node<DataType> *curr_node;
            Node<DataType> *prev_node;
            for (curr_node = head, prev_node; curr_node->next != nullptr; prev_node = curr_node, curr_node = curr_node->next)
                ;
            if (curr_node == head) {
                head = nullptr;
            } else {
                prev_node->next = nullptr;
            }
            delete curr_node;
            decrementLength();
        }
    }

    void deleteNodeAtIndex(int ind_to_delete) {
        if (head == nullptr) {
            cout << "Empty list. No node to delete.\n";
        } else {
            Node<DataType> *curr_node = head;
            Node<DataType> *prev_node;
            int curr_ind = 0;
            while (curr_ind < ind_to_delete && curr_node->next != nullptr) {  // delete at index or delete at last if index not found
                ++curr_ind;
                prev_node = curr_node;
                curr_node = curr_node->next;
            }
            if (curr_node == head) {
                head = head->next;
            } else {
                prev_node->next = curr_node->next;
            }
            delete curr_node;
            decrementLength();
        }
    }

    void reverseNodesRecursive() {
        if (head != nullptr) {
            _reverseNodesRecursive(head);
        }
    }

    void reverseNodesIterative() {
        Node<DataType> *prev_node = nullptr;
        Node<DataType> *curr_node = head;
        Node<DataType> *next_node = nullptr;
        while (curr_node != nullptr) {
            next_node = curr_node->next;
            curr_node->next = prev_node;
            prev_node = curr_node;
            curr_node = next_node;
        }
        head = prev_node;
    }

    bool search(int ele_to_search) {
        if (head != nullptr) {
            for (Node<DataType> *curr_node = head; curr_node != nullptr; curr_node = curr_node->next) {
                if (curr_node->data == ele_to_search) {
                    return true;
                }
            }
        }
        return false;
    }

    void sort() {
        if (length > 1) {
            head = sortRecursive(head);
        }
    }

    void displayNodes() {
        if (head != nullptr) {
            for (Node<DataType> *curr_node = head; curr_node != nullptr; curr_node = curr_node->next) {
                cout << curr_node->data << "->";
            }
        }
        cout << "NULL\n";
    }
};