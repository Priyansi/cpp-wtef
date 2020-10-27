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
        if (top == -1) {
            cout << "Stack Underflow.\n";
            return;
        }
        --top;
    }

    DataType* peek() {
        if (is_empty()) {
            return nullptr;
        }
        return &data[top];
    }

    bool
    is_empty() {
        return top == -1;
    }

    void display_iter() {
        Stack<DataType> temp(max_length);
        DataType curr;
        while (!is_empty()) {
            curr = *peek();
            pop();
            temp.push(curr);
            cout << curr << " ";
        }
        while (!temp.is_empty()) {
            curr = *(temp.peek());
            temp.pop();
            push(curr);
        }
        cout << "\n";
    }

    void display_recr() {
        if (is_empty()) {
            return;
        }
        cout << *peek() << " ";
        pop();
        display_iter();
        push(*peek());
    }
};

int main(int argc, char* argv[]) {
    Stack<int> s(3);
    s.push(1);
    s.push(2);
    s.push(3);
    s.display_iter();
    /* 
    Output -
    
    */

    s.pop();
    s.display_recr();
    /* 
    Output -
    2 1
    */

    cout << ((s.peek() == nullptr) ? "" : to_string(*s.peek())) << "\n";
    /* 
    Output -
    2
    */

    s.pop();
    s.pop();
    cout << ((s.peek() == nullptr) ? "" : to_string(*s.peek())) << "\n";
    /* 
    Output -
    
    */

    cout << (s.is_empty() ? "True" : "False") << "\n";
    /* 
    Output -
    True
    */
    return 0;
}