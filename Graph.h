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

struct Street { // defines what information will be represented in a given edge
    string to;
    int distance;
    int traffic;

    Street(string t, int d, int x) {
        to = t;
        distance = d;
        traffic = x;
    }

};

struct TrafficData { // defines what information will be represented in a given edge
    int id;
    int segment_id;
    std::string roadway_name;
    std::string from;
    std::string to;
    std::string direction;
    std::string date;
    std::vector<int> hourly_volumes;
};

struct Intersections { // a node and its edges in a vector
    int id;
    vector<Street> streets;
};

class Graph {
    private:

    unordered_map<std::string, struct Intersections> nodes;
public:
    //Kinda deleted this function no cap
    void addIntersections(int id); // adds a node to the graph based on whatever criteria we decide for our nodes
    void addEdge(string from, string to, double dist, double traffic); // will take in starting location, destination,
    // distance, and the traffic (however we decide to handle that)
    double getWeight(const Street& edge) const; // will return the weight of the edge using whatever formula we decide to use
    void buildGraph(std::vector<TrafficData> &trafficData);
};