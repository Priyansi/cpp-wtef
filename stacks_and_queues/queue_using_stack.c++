#include "../header_files/stack_arr.h"

using namespace std;

template <typename DataType>
class Queue {
    Stack<DataType> stack1;  // for pushing elements
    Stack<DataType> stack2;  // for popping elements
    int max_length;

   public:
    Queue(int length) : stack1(length), stack2(length) {
        max_length = length;
    }

    void enqueue(DataType val) {
        stack1.push(val);
    }

    void dequeue() {
        if (stack2.isEmpty()) {
            DataType curr;
            while (!stack1.isEmpty()) {
                curr = *(stack1.peek());
                stack1.pop();
                stack2.push(curr);
            }
        }
        stack2.pop();
    }

    DataType* getFront() {
        if (stack1.isEmpty() && stack2.isEmpty()) {
            return nullptr;
        }
        return stack2.peek();
    }

    bool isEmpty() {
        return stack1.isEmpty() && stack2.isEmpty();
    }

    void display() {
        Stack<DataType> temp(max_length);
        DataType curr;
        while (!stack2.isEmpty()) {
            curr = *(stack2.peek());
            stack2.pop();
            temp.push(curr);
            cout << curr << " ";
        }
        while (!temp.isEmpty()) {
            curr = *(temp.peek());
            temp.pop();
            stack2.push(curr);
        }
        while (!stack1.isEmpty()) {
            curr = *(stack1.peek());
            stack1.pop();
            temp.push(curr);
        }
        while (!temp.isEmpty()) {
            curr = *(temp.peek());
            temp.pop();
            stack1.push(curr);
            cout << curr << " ";
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

int main(int argc, char* argv[]) {
    Queue<int> q(3);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.display();
    /* 
    Output -
    1 2 3
    */

    q.dequeue();
    q.display();
    /* 
    Output -
    2 3
    */

    cout << ((q.getFront() == nullptr) ? "" : to_string(*(q.getFront()))) << "\n";
    /* 
    Output -
    2
    */

    cout << (q.isEmpty() ? "True" : "False") << "\n";
    /* 
    Output -
    False
    */
    return 0;
}