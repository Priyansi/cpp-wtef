#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

#include "../header_files/graph.h"
using namespace std;

template <typename DataType>
bool Graph<DataType>::doesPathExists(DataType start_vertex, DataType end_vertex) {
    queue<DataType> vertices;
    unordered_set<DataType> visited = {start_vertex};
    vertices.push(start_vertex);
    DataType curr;
    while (!visited.empty()) {
        start_vertex = vertices.front();
        vertices.pop();
        for (Node<DataType> *edge = this->adj_list[start_vertex].getHead(); edge != nullptr; edge = edge->next) {
            if (edge->data == end_vertex) {
                return true;
            }
            if (visited.find(edge->data) == visited.end()) {
                vertices.push(edge->data);
                visited.insert(edge->data);
            }
        }
    }
    return false;
}

bool canMoveTo(const vector<vector<int>> &data, int to_row, int to_col, int from_node_val) {
    return to_row >= 0 && to_row < data.size() && to_col >= 0 && to_col < data[0].size() && data[to_row][to_col] <= from_node_val;
}

bool canReachMatrixEnd(const vector<vector<int>> &data) {
    Graph<int> g;
    int start_node = 1;
    for (int row = 0; row < data.size(); ++row) {
        for (int col = 0; col < data[row].size(); ++col) {
            g.addVertex(start_node);
            if (canMoveTo(data, row - 1, col, data[row][col])) {
                g.addEdge(start_node, start_node - data[0].size());
            }
            if (canMoveTo(data, row + 1, col, data[row][col])) {
                g.addEdge(start_node, start_node + data[0].size());
            }
            if (canMoveTo(data, row, col - 1, data[row][col])) {
                g.addEdge(start_node, start_node - 1);
            }
            if (canMoveTo(data, row, col + 1, data[row][col])) {
                g.addEdge(start_node, start_node + 1);
            }
            ++start_node;
        }
    }
    return g.doesPathExists(1, (data.size()) * (data[0].size()));
}

int main() {
    vector<vector<int>> data = {{25, 25, 40, 22},
                                {25, 25, 19, 18},
                                {40, 40, 40, 14},
                                {13, 12, 11, 10},
                                {9, 8, 7, 6}};
    cout << canReachMatrixEnd(data);
    return 0;
}