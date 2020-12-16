#include <limits.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

template <typename DataType>
class Node {
   public:
    DataType data;
    int weight;
    Node<DataType> *next;
    Node() {
        next = nullptr;
    }
};

template <typename DataType>
class SingleLinkedList {
    Node<DataType> *head;
    int length;

    void incrementLength() {
        ++length;
    }

   public:
    SingleLinkedList() {
        head = nullptr;
        length = 0;
    }

    Node<DataType> *getHead() {
        return this->head;
    }

    void insertNodeAtEnd(DataType val, int weight) {
        Node<DataType> *new_node = new (nothrow) Node<DataType>();  // to avoid bad alloc exception to be thrown
        if (!new_node) {
            cout << "Memory allocation failed\n";
            return;
        }
        new_node->data = val;
        new_node->weight = weight;
        if (head == nullptr) {
            head = new_node;
        } else {
            Node<DataType> *curr_node;
            for (curr_node = head; curr_node->next != nullptr; curr_node = curr_node->next)
                ;
            curr_node->next = new_node;
        }
        incrementLength();
    }

    bool search(DataType ele_to_search) {
        if (head != nullptr) {
            for (Node<DataType> *curr_node = head; curr_node != nullptr; curr_node = curr_node->next) {
                if (curr_node->data == ele_to_search) {
                    return true;
                }
            }
        }
        return false;
    }

    DataType findMin() {
        if (head != nullptr) {
            Node<DataType> *min_node = head;
            for (Node<DataType> *curr_node = head->next; curr_node != nullptr; curr_node = curr_node->next) {
                if (curr_node->weight < min_node->weight) {
                    min_node = curr_node;
                }
            }
            return min_node->data;
        }
        return 0;
    }

    void displayNodes() {
        if (head != nullptr) {
            for (Node<DataType> *curr_node = head; curr_node != nullptr; curr_node = curr_node->next) {
                cout << curr_node->data << " " << curr_node->weight << "->";
            }
        }
        cout << "NULL\n";
    }
};

template <typename DataType>
class Graph {
    unordered_map<DataType, SingleLinkedList<DataType>> adj_list;

   public:
    Graph() {
    }

    void dijkstraShortestPath(DataType start_vertex) {
        // creating a min heap with weight, vertex pairs
        priority_queue<pair<int, DataType>, vector<pair<int, DataType>>, greater<pair<int, DataType>>> visited_vertices_paths;
        unordered_map<DataType, int> shortest_paths;
        shortest_paths[start_vertex] = 0;
        visited_vertices_paths.push(make_pair(shortest_paths[start_vertex], start_vertex));

        while (!visited_vertices_paths.empty()) {
            start_vertex = (visited_vertices_paths.top()).second;
            visited_vertices_paths.pop();
            Node<DataType> *edge = this->adj_list[start_vertex].getHead();
            for (edge; edge != nullptr; edge = edge->next) {
                if ((shortest_paths.find(edge->data) == shortest_paths.end()) || (shortest_paths[start_vertex] + edge->weight < shortest_paths[edge->data])) {
                    shortest_paths[edge->data] = shortest_paths[start_vertex] + edge->weight;
                    visited_vertices_paths.push(make_pair(shortest_paths[edge->data], edge->data));
                }
            }
        }

        for (auto it : shortest_paths) {
            cout << "From " << to_string(start_vertex) << " to " << to_string(it.first) << " : " << to_string(it.second) << endl;
        }
    }

    bool addVertex(DataType vertex) {
        if (this->adj_list.find(vertex) == this->adj_list.end()) {
            SingleLinkedList<DataType> *edges = new SingleLinkedList<DataType>();
            this->adj_list[vertex] = *edges;
            return true;
        }
        return false;
    }

    bool addEdge(DataType start_vertex, DataType end_vertex, int weight) {
        if ((this->adj_list.find(start_vertex) != this->adj_list.end()) && ((this->adj_list[start_vertex]).search(end_vertex) == false)) {
            if (this->adj_list.find(end_vertex) == this->adj_list.end()) {
                this->addVertex(end_vertex);
            }
            this->adj_list[start_vertex].insertNodeAtEnd(end_vertex, weight);
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

int main(int argc, char *argv[]) {
    Graph<int> g;
    /*
    g.addVertex(0);
    g.addVertex(1);
    g.addVertex(2);

    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 1);

    g.dijkstraShortestPath(0);
    */

    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);
    g.addVertex(5);
    g.addVertex(6);

    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 4);
    g.addEdge(2, 3, 1);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 5, 3);
    g.addEdge(4, 6, 1);
    g.addEdge(5, 4, 2);
    g.addEdge(5, 6, 5);

    g.dijkstraShortestPath(1);

    return 0;
}