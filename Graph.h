//
// Created by dang1 on 8/3/2024.
//

#ifndef GOTIME_GRAPH_H
#define GOTIME_GRAPH_H


#endif //GOTIME_GRAPH_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <limits>
#include <cmath>
using namespace std;


struct Edge { // defines what information will be represented in a given edge
    int destination;
    double distance;
    double traffic;
};

struct Node { // a node and its edges in a vector
    int id;
    vector<Edge> edges;
};

class Graph {
    unordered_map<int, Node> nodes;
public:
    void addNode(int id); // adds a node to the graph based on whatever criteria we decide for our nodes
    void addEdge(int to, int from, double dist, double traffic); // will take in starting location, destination,
    // distance, and the traffic (however we decide to handle that)
    double getWeight(const Edge& edge) const; // will return the weight of the edge using whatever formula we decide to use

};