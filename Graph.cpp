//
// Created by dang1 on 8/3/2024.
//

#include "Graph.h"

void Graph::addNode(int id) {
    nodes[id] = Node{id};
}

void Graph::addEdge(int from, int to, double dist, double traffic) {
    nodes[from].edges.push_back({to, dist, traffic});
}

double Graph::getWeight(const Edge &edge) const {
    return edge.distance + edge.traffic; // add the weight formula we decide to use
}