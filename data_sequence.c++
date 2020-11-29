#include <iostream>
#include <vector>

using namespace std;

template <typename DataType>
class Sequence {
    vector<DataType> data;
    bool is_sorted;
    DataType mean;
    DataType median;
    DataType mode;
    DataType q1;
    DataType q3;

    void compute_stats() {
    }

   public:
    Sequence() {
        is_sorted = false;
    }

    int getSize() {
    }

    void sort() {
    }

    bool search(DataType val) {
    }

    void insert() {
    }

    void display() {
        for (DataType val : data) {
            cout << val << " ";
        }
        cout << "\n";
    }

    void show_stats() {
    }
};