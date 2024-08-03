//
// Created by dang1 on 8/3/2024.
//
#include <Graph.h>
#include <iostream>
#include <unordered_set>
#include <fstream>
#include <sstream>

using namespace std;

std::string createUniqueKey(const TrafficData &entry) {
    return std::to_string(entry.segment_id) + "|" + entry.from + "|" + entry.to;
}



std::vector<TrafficData> parseCSV(string filename) {
    //Create data vector and initialize file name
    std::vector<TrafficData> data;
    std::ifstream file(filename);
    std::unordered_set<std::string> uniqueEntries;
    std::string line;

    //Checks if file is open
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return data;
    }

    // Read the header line and ignore it
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        TrafficData entry;
        std::string temp;

        // Parse the fixed fields
        std::getline(ss, temp, ','); entry.id = std::stoi(temp);
        std::getline(ss, temp, ','); entry.segment_id = std::stoi(temp);
        std::getline(ss, entry.roadway_name, ',');
        std::getline(ss, entry.from, ',');
        std::getline(ss, entry.to, ',');
        std::getline(ss, entry.direction, ',');
        std::getline(ss, entry.date, ',');

        // Parse hourly volumes
        while (std::getline(ss, temp, ',')) {
            entry.hourly_volumes.push_back(std::stoi(temp));
        }

        // Create a unique key for the entry
        std::string key = createUniqueKey(entry);

        // Check if the entry is unique
        if (uniqueEntries.find(key) == uniqueEntries.end()) {
            // Entry is unique, add to data vector and set
            data.push_back(entry);
            uniqueEntries.insert(key);
        }
    }

    return data;
}



int main () {
    Graph graph;

    std::vector<TrafficData> traffic = parseCSV("Traffic_Volume_Counts_20240803.csv");

    graph.buildGraph(traffic);


}

