#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <utility>

using namespace std;

bool isOperator(char ch) {
    unordered_set<char> operators = {'+', '-', '*', '/'};
    if (operators.find(ch) != operators.end()) {
        return true;
    }
    return false;
}

template <typename DataType>
DataType operate(DataType operand1, char op, DataType operand2) {
    switch (op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
    }
}

int toInteger(char ch) {
    return ch - '0';
}

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

    DataType eval(string postfix) {
        DataType operand1, operand2;
        for (auto ch : postfix) {
            if (isOperator(ch)) {
                operand2 = *peek();
                pop();
                operand1 = *peek();
                pop();
                push(operate(operand1, ch, operand2));
            } else {
                push(toInteger(ch));
            }
        }
        return *peek();
    }
};

int main(int argc, char* argv[]) {
    Stack<int> s(10);
    string postfix = argv[1];
    cout << s.eval(postfix);
}