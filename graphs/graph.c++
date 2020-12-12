#include <iostream>
#include <unordered_map>

#include "../header_files/sll.h"

using namespace std;

template <typename DataType>
class Graph {
    int num_vertices;
    unordered_map<DataType, SingleLinkedList<DataType>> adj_list;

    void incrementVertices() {
        ++this->num_vertices;
    }

    void decrementVertices() {
        --this->num_vertices;
    }

   public:
    Graph() {
        this->num_vertices = 0;
    }

    bool addVertex(DataType vertex) {
        if (this->adj_list.find(vertex) == this->adj_list.end()) {
            SingleLinkedList<DataType>* edges = new (nothrow) SingleLinkedList<DataType>();
            this->adj_list[vertex] = *edges;
            return true;
        }
        return false;
    }

    bool addEdge(DataType start_vertex, DataType end_vertex) {
        if (this->adj_list.find(start_vertex) != this->adj_list.end() && this->adj_list[start_vertex].search(end_vertex) == false) {
            if (this->adj_list.find(end_vertex) == this->adj_list.end()) {
                this->addVertex(end_vertex);
            }
            this->adj_list[start_vertex].insertNodeAtEnd(end_vertex);
            return true;
        }
        return false;
    }

    bool removeEdge(DataType start_vertex, DataType end_vertex) {
        if (this->adj_list.find(start_vertex) != this->adj_list.end()) {
            return this->adj_list[start_vertex].deleteNode(end_vertex);
        }
        return false;
    }

    bool removeVertex(DataType vertex) {
        if (this->adj_list.find(vertex) != this->adj_list.end()) {
            this->adj_list.erase(vertex);
            return true;
        }
        return false;
    }

    void printGraph() {
        for (auto it : this->adj_list) {
            cout << "Vertex : " << it.first << "\tEdges : ";
            (it.second).displayNodes();
        }
    }
};

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

    g.printGraph();
    cout << endl;

    g.removeEdge('c', 'e');
    g.removeEdge('f', 'a');
    g.printGraph();
    cout << endl;

    g.removeVertex('f');

    g.printGraph();
    return 0;
}