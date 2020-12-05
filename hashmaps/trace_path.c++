#include <iostream>
#include <unordered_map>

using namespace std;

string tracePath(const unordered_map<string, string> &hash_map) {
    string path = "";
    for (int i = 0; i < size; ++i) {
        string first = to_string(arr[i][0]);
        string second = to_string(arr[i][1]);
        if (hash_table.find(second + "," + first) != hash_table.end()) {
            path.append("{" + first + ", " + second + "}{" + second + ", " + first + "}");
        } else {
            hash_table.insert(first + "," + second);
        }
    }
    return path;
}

int main() {
    unordered_map<string, string> hash_map = {{"NewYork", "Chicago"}, {"Boston", "Texas"}, {"Missouri", "NewYork"}, {"Texas", "Missouri"}};
    cout << tracePath(hash_map);
}