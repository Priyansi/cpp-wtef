#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;

template <typename DataType>
class Stack {
    DataType* data;
    int max_length;
    int top_left, top_right;

   public:
    Stack(int length) {
        data = new DataType[length];
        max_length = length;
        top_left = top_right = -1;
    }

    void pushLeft(DataType val) {
        if (top_left + top_right == max_length - 1) {
            cout << "Stack Overflow.\n";
            return;
        }
        ++top_left;
        data[top_left] = val;
    }

    void pushRight(DataType val) {
        if (top_left + top_right == max_length - 1) {
            cout << "Stack Overflow.\n";
            return;
        }
        ++top_right;
        data[top_right] = val;
    }

    void popLeft() {
        if (top_left == -1) {
            cout << "Stack Underflow.\n";
            return;
        }
        --top_left;
    }

    void popRight() {
        if (top_right == -1) {
            cout << "Stack Underflow.\n";
            return;
        }
        --top_right;
    }

    DataType* peekLeft() {
        if (is_empty()) {
            return nullptr;
        }
        return &data[top_left];
    }

    DataType* peekRight() {
        if (is_empty()) {
            return nullptr;
        }
        return &data[top_right];
    }

    bool
    isEmpty() {
        return top_left == -1 && top_right == -1;
    }
};

int main(int argc, char* argv[]) {
    Stack<int> s(10);
}