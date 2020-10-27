#include <vector>
#include "../header_files/stack_arr.h"

template <typename DataType>
void nextGreaterElement(vector<DataType> data) {
    Stack<DataType> s(data.size());
    s.push(data.front());
    for (typename vector<DataType>::iterator val = next(data.begin()); val != data.end(); ++val) {
        while (!s.isEmpty() && *(s.peek()) < *val) {
            cout << *val << " ";
            s.pop();
        }
        s.push(*val);
    }
    while (!s.isEmpty()) {
        cout << "-1 ";
        s.pop();
    }
    cout << "\n";
}

int main(int argc, char* argv[]) {
    int length = stoi(argv[1]);
    vector<int> data;
    int input;
    while (length--) {
        cin >> input;
        data.push_back(input);
    }
    nextGreaterElement(data);
}