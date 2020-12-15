#include <unordered_set>

#include "../header_files/graph.h"
#include "../header_files/stack_ll.h"

template <typename DataType>
void Graph<DataType>::depthFirstSearchVertex(DataType start_vertex, unordered_set<DataType>& visited_vertices) {
    if (visited_vertices.find(start_vertex) == visited_vertices.end()) {
        visited_vertices.insert(start_vertex);
        cout << start_vertex << " ";
    }
    Node<DataType>* edge = this->adj_list[start_vertex].getHead();
    for (edge; edge->next != nullptr; edge = edge->next) {
        if (visited_vertices.find(edge->data) == visited_vertices.end()) {
            visited_vertices.insert(edge->data);
            cout << edge->data << " ";
            this->depthFirstSearchVertex(edge->data, visited_vertices);
        }
    }
}

template <typename DataType>
void Graph<DataType>::depthFirstSearchRecursive(DataType start_vertex) {
    unordered_set<DataType> visited_vertices{start_vertex};
    cout << start_vertex << " ";
    this->depthFirstSearchVertex(start_vertex, visited_vertices);
    for (auto it : this->adj_list) {
        this->depthFirstSearchVertex(it.first, visited_vertices);
    }
    cout << endl;
}

template <typename DataType>
void Graph<DataType>::depthFirstSearch(DataType start_vertex) {
    Stack<DataType> vertices;
    vertices.push(start_vertex);
    unordered_set<DataType> visited_vertices = {start_vertex};
    while (!vertices.isEmpty()) {
        start_vertex = (vertices.peek())->data;
        cout << start_vertex << " ";
        vertices.pop();
        for (Node<DataType>* edge = this->adj_list[start_vertex].getHead(); edge != nullptr; edge = edge->next) {
            if (visited_vertices.find(edge->data) == visited_vertices.end()) {
                visited_vertices.insert(edge->data);
                vertices.push(edge->data);
            }
        }
    }
    cout << endl;
}

int main(int argc, char* argv[]) {
    Graph<char> g;

    g.addVertex('a');
    g.addVertex('b');
    g.addVertex('c');
    g.addVertex('d');
    g.addVertex('e');
    g.addVertex('f');

    g.addEdge('a', 'b');
    g.addEdge('a', 'f');
    g.addEdge('b', 'a');
    g.addEdge('b', 'e');
    g.addEdge('c', 'd');
    g.addEdge('c', 'e');
    g.addEdge('d', 'c');
    g.addEdge('d', 'e');
    g.addEdge('e', 'b');
    g.addEdge('e', 'c');
    g.addEdge('e', 'd');
    g.addEdge('f', 'a');

    g.depthFirstSearch('a');
    g.depthFirstSearchRecursive('a');

    return 0;
}