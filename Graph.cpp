//
// Created by dang1 on 8/3/2024.
//

#include <fstream>
#include <unordered_set>
#include <sstream>
#include "Graph.h"




//Helper Function to determine if data is not duplicated


void Graph::addEdge(string from, string to, double dist, double traffic) {
    nodes[from].streets.push_back(Street(to, dist, traffic));
}

double Graph::getWeight(const Street &edge) const {
    return edge.distance + edge.traffic; // add the weight formula we decide to use
}

void Graph::buildGraph(std::vector<TrafficData> &trafficData) {
    //Insert edges
    for (const auto &entry : trafficData) {
        const std::string &fromIntersection = entry.from;
        const std::string &toIntersection = entry.to;

        // Average of traffic data
        int totalVolume = 0;
        for (int volume : entry.hourly_volumes) {
            totalVolume += volume;
        }
        int averageVolume = totalVolume / entry.hourly_volumes.size();

        this->addEdge(fromIntersection, toIntersection, averageVolume, 0);
    }

}

