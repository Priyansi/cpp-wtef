#include <algorithm>
#include <iostream>
#include <utility>

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
class Stack {
    Node<DataType>* top;

   public:
    Stack() {
        top = nullptr;
    }

    void push(DataType val) {
        Node<DataType>* new_node = new (nothrow) Node<DataType>();  // to avoid bad alloc exception to be thrown
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

    Node<DataType>* peek() {
        return top;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void displayIter() {
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
    void displayRecr() {
        if (isEmpty()) {
            return;
        }
        cout << peek()->data << " ";
        pop();
        displayRecr();
        push(peek()->data);
    }
};

int main(int argc, char* argv[]) {
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.displayIter();
    /* 
    Output -
    
    */

    s.pop();
    s.displayRecr();
    /* 
    Output -
    2 1
    */

    cout << ((s.peek() == nullptr) ? "" : to_string(s.peek()->data)) << "\n";
    /* 
    Output -
    2
    */

    s.pop();
    s.pop();
    cout << ((s.peek() == nullptr) ? "" : to_string(s.peek()->data)) << "\n";
    /* 
    Output -
    
    */

    cout << (s.isEmpty() ? "True" : "False") << "\n";
    /* 
    Output -
    True
    */
    return 0;
}