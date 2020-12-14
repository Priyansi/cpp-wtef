#include <unordered_set>

#include "../header_files/graph.h"
#include "../header_files/queue_ll.h"

template <typename DataType>
void Graph<DataType>::breadthFirstSearch(DataType start_vertex) {
    Queue<DataType> vertices;
    vertices.enqueue(start_vertex);
    unordered_set<DataType> visited_vertices = {start_vertex};
    while (!vertices.isEmpty()) {
        start_vertex = (vertices.getFront())->data;
        cout << start_vertex << " ";
        vertices.dequeue();
        for (Node<DataType>* edge = this->adj_list[start_vertex].getHead(); edge != nullptr; edge = edge->next) {
            if (visited_vertices.find(edge->data) == visited_vertices.end()) {
                visited_vertices.insert(edge->data);
                vertices.enqueue(edge->data);
            }
        }
    }
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

    g.breadthFirstSearch('a');

    return 0;
}