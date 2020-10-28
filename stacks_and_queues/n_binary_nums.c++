#include "../header_files/queue_ll.h"

string* nBinaryNumbers(int n) {
    string* n_binary_nums = new string[n];
    Queue<string> q;
    q.enqueue("1");
    string curr;
    for (int i = 0; i < n; ++i) {
        curr = q.getFront()->data;
        n_binary_nums[i] = curr;
        q.dequeue();
        q.enqueue(curr + "0");
        q.enqueue(curr + "1");
    }
    return n_binary_nums;
}

int main(int argc, char* argv[]) {
    // assuming 1<= n
    int n = stoi(argv[1]);
    string* n_binary_nums = nBinaryNumbers(n);
    for (int i = 0; i < n; ++i) {
        cout << n_binary_nums[i] << " ";
    }
    return 0;
}