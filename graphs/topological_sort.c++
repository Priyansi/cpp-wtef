#include <unordered_set>
#include <vector>

#include "../header_files/graph.h"

template <typename DataType>
void Graph<DataType>::topologicalSortRecursive(DataType start_vertex, unordered_set<DataType>& visited_vertices, Stack<DataType>& sorted) {
    visited_vertices.insert(start_vertex);
    Node<DataType>* edge = (this->adj_list[start_vertex]).getHead();
    for (edge; edge != nullptr; edge = edge->next) {
        if (visited_vertices.find(edge->data) == visited_vertices.end()) {
            this->topologicalSortRecursive(edge->data, visited_vertices, sorted);
        }
    }
    sorted.push(start_vertex);
}

template <typename DataType>
void Graph<DataType>::topologicalSort() {
    unordered_set<DataType> visited_vertices;
    Stack<DataType> sorted;
    for (auto it : this->adj_list) {
        if (visited_vertices.find(it.first) == visited_vertices.end()) {
            this->topologicalSortRecursive(it.first, visited_vertices, sorted);
        }
    }
    sorted.display();
}

int main(int argc, char* argv[]) {
    Graph<int> g;

    g.addVertex(0);
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);
    g.addVertex(5);

    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(5, 0);
    g.addEdge(5, 2);

    g.topologicalSort();

    return 0;
}