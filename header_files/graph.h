#pragma once

#include <iostream>
#include <unordered_map>

#include "sll.h"

using namespace std;

template <typename DataType>
class Graph {
    int num_vertices;
    unordered_map<DataType, SingleLinkedList<DataType>> adj_list;

    void breadthFirstSearchVertex(DataType, unordered_set<DataType>&);
    void depthFirstSearchVertex(DataType, unordered_set<DataType>&);

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

    void breadthFirstSearch(DataType);
    void depthFirstSearch(DataType);

    bool addVertex(DataType vertex) {
        if (this->adj_list.find(vertex) == this->adj_list.end()) {
            SingleLinkedList<DataType>* edges = new SingleLinkedList<DataType>();
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