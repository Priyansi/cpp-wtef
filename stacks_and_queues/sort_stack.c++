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

    DataType sort() {
        Stack<DataType> temp(max_length);
        DataType curr, curr_temp;
        while (!isEmpty()) {
            curr = *peek();
            pop();
            while (!temp.isEmpty() && curr > *(temp.peek())) {
                curr_temp = *(temp.peek());
                temp.pop();
                push(curr_temp);
            }
            temp.push(curr);
        }
        *this = temp;
    }
};

int main(int argc, char* argv[]) {
    Stack<int> s(10);
    s.push(2);
    s.push(97);
    s.push(4);
    s.push(42);
    s.push(12);
    s.push(60);
    s.push(23);
    s.display();
    s.sort();
    s.display();
    /*Output-
    23 60 12 42 4 97 2 
    2 4 12 23 42 60 97 
    */
}