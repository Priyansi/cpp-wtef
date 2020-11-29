#include "../header_files/stack_ll.h"

using namespace std;

template <typename DataType>
class MinStack {
    Stack<DataType> stack;
    Stack<DataType> min_stack;

   public:
    void push(DataType val) {
        stack.push(val);
        if (min_stack.isEmpty() || min_stack.peek()->data > val) {
            min_stack.push(val);
        }
    }

    void pop() {
        DataType deleted_val = stack.peek()->data;
        stack.pop();
        if (!min_stack.isEmpty() && deleted_val == min_stack.peek()->data) {
            min_stack.pop();
        }
    }

    Node<DataType>* peek() {
        return stack.peek();
    }

    DataType min() {
        return min_stack.peek()->data;
    }

    bool isEmpty() {
        return stack.isEmpty();
    }
};

int main(int argc, char* argv[]) {
    MinStack<int> ms;
    ms.push(5);
    ms.push(2);
    ms.push(4);
    ms.push(1);
    ms.push(3);
    ms.push(9);

    cout << ms.min() << endl;
    ms.pop();
    ms.pop();
    ms.pop();
    cout << ms.min() << endl;
}