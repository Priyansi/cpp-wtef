#pragma once

#include <iostream>
#include <unordered_map>
#include <unordered_set>

#include "../header_files/stack_ll.h"
#include "sll.h"

using namespace std;

template <typename DataType>
class Graph {
    unordered_map<DataType, SingleLinkedList<DataType>> adj_list;

    void breadthFirstSearchVertex(DataType, unordered_set<DataType>&);
    void depthFirstSearchVertex(DataType, unordered_set<DataType>&);
    void topologicalSortRecursive(DataType, unordered_set<DataType>&, Stack<DataType>&);
    void dijkstraShortestPathFromVertex(DataType, unordered_set<DataType>&, unordered_map<DataType, int>&);

   public:
    Graph() {
    }

    void breadthFirstSearch(DataType);
    void depthFirstSearch(DataType);
    void depthFirstSearchRecursive(DataType);
    void topologicalSort();
    void dijkstraShortestPath(DataType);
    bool doesPathExists(DataType, DataType);

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