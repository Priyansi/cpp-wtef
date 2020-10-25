
#include <algorithm>
#include <iostream>
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
    Node<DataType>* next;
    Node() {
        next = nullptr;
    }
};

template <typename DataType>
class SingleLinkedList {
    Node<DataType>* head;
    int length;

   public:
    SingleLinkedList() {
        head = nullptr;
        length = 0;
    }

    void incrementLength() {
        ++length;
    }

    void decrementLength() {
        --length;
    }

    void insertNodeAtEnd(DataType val) {
        Node<DataType>* new_node = new (nothrow) Node<DataType>();  // to avoid bad alloc exception to be thrown
        if (!new_node) {
            cout << "Memory allocation failed\n";
            return;
        }
        new_node->data = val;
        if (head == nullptr) {
            head = new_node;
        } else {
            Node<DataType>* curr_node;
            for (curr_node = head; curr_node->next != nullptr; curr_node = curr_node->next)
                ;
            curr_node->next = new_node;
        }
        incrementLength();
    }

    void insertNodeAtIndex(DataType val, int ind_to_insert) {
        Node<DataType>* new_node = new (nothrow) Node<DataType>();  // to avoid bad alloc exception to be thrown
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
            Node<DataType>* curr_node = head;
            Node<DataType>* prev_node;
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
            Node<DataType>* curr_node;
            Node<DataType>* prev_node;
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
            Node<DataType>* curr_node = head;
            Node<DataType>* prev_node;
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
    auto _reverseNodesRecursive(Node<DataType>* curr) {
        if (curr->next == nullptr) {
            head = curr;
            return curr;
        }
        Node<DataType>* prev = _reverseNodesRecursive(curr->next);
        prev->next = curr;
        curr->next = nullptr;
        return curr;
    }

    void reverseNodesRecursive() {
        if (head != nullptr) {
            _reverseNodesRecursive(head);
        }
    }

    void reverseNodesIterative() {
        Node<DataType>* prev_node = nullptr;
        Node<DataType>* curr_node = head;
        Node<DataType>* next_node = nullptr;
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
            for (Node<DataType>* curr_node = head; curr_node != nullptr; curr_node = curr_node->next) {
                if (curr_node->data == ele_to_search) {
                    return true;
                }
            }
        }
        return false;
    }

    void displayNodes() {
        if (head != nullptr) {
            for (Node<DataType>* curr_node = head; curr_node != nullptr; curr_node = curr_node->next) {
                cout << curr_node->data << "->";
            }
        }
        cout << "NULL\n";
    }
};

int main(int argc, char* argv[]) {
    SingleLinkedList<int> sll;
    sll.insertNodeAtEnd(2);
    sll.insertNodeAtEnd(3);
    sll.insertNodeAtEnd(5);
    sll.insertNodeAtIndex(1, 0);  // insert at head
    sll.insertNodeAtIndex(6, 9);  // insert at end
    sll.insertNodeAtIndex(4, 3);  // insert at index 3
    sll.displayNodes();
    /* 
    Output -
    1->2->3->4->5->6->NULL
    */

    sll.reverseNodesIterative();
    sll.displayNodes();
    /* 
    Output -
    6->5->4->3->2->1->NULL
    */
    sll.reverseNodesRecursive();
    sll.displayNodes();
    /* 
    Output -
    1->2->3->4->5->6->NULL
    */
    sll.deleteNodeAtEnd();
    sll.deleteNodeAtIndex(11);
    sll.deleteNodeAtIndex(0);
    sll.deleteNodeAtIndex(1);
    sll.displayNodes();

    /*
    Output -
    2->4->NULL
    */

    cout << sll.search(4);

    /*
    Output -
    1
    */
    return 0;
}