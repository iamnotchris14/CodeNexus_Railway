//
// Created by HASHIKA KESHREEN on 7/21/2025.
//
#ifndef LINES1_H
#define LINES1_H

#include <iostream>
#include <limits>
using namespace std;

struct Edge;
struct Station {
    string name;
    Edge* ed;
};

struct Edge {
    int weight;
    Station* to; //Address of destination station
    Edge* nxtE;
};

// Structure to store path information and path algorithm
struct PathInfo {
    int distance;
    Station* previous;
    bool visited;
};

// Global stations array
Station stations[12] = {
    {"Titiwangsa", nullptr}, {"Chow Kit", nullptr}, {"Medan Tuanku", nullptr},
    {"Bukit Nanas", nullptr}, {"Raja Chulan", nullptr}, {"Bukit Bintang", nullptr},
    {"Tun Razak Exchange (TRX)", nullptr}, {"Hospital Kuala Lumpur", nullptr},
    {"Raja Uda", nullptr}, {"Ampang Park", nullptr}, {"Persiaran KLCC", nullptr},
    {"Conlay", nullptr}
};

void createEdges(Station* from, Station* to, int w) {
    Edge* edge = new Edge;
    edge->to = to;
    edge->weight = w;
    edge->nxtE = from->ed;
    from->ed = edge;
}

void createBidirectionalEdges(Station* a, Station* b, int w) {
    createEdges(a, b, w);
    createEdges(b, a, w);
}

void buildGraph() {
    createBidirectionalEdges(&stations[0], &stations[1], 2); //Titiwangsa - ChowKit
    createBidirectionalEdges(&stations[1], &stations[2], 3); //ChowKit - Medan Tuanku
    createBidirectionalEdges(&stations[2], &stations[3], 2); //Medan Tuanku -Bukit Nanas
    createBidirectionalEdges(&stations[3], &stations[4], 2); //Bukit Nanas - Raja Chulan
    createBidirectionalEdges(&stations[4], &stations[5], 1); //Raja Chulan - Bukit Bintang
    createBidirectionalEdges(&stations[5], &stations[6], 1); //Bukit Bintang - TRX

    createBidirectionalEdges(&stations[0], &stations[7], 2); //Titiwangsa - HKL
    createBidirectionalEdges(&stations[7], &stations[8], 1); //HKL - Raja Uda
    createBidirectionalEdges(&stations[8], &stations[9], 3); //Raja Uda - Ampang Park
    createBidirectionalEdges(&stations[9], &stations[10], 2); //Ampang Park - PKLCC
    createBidirectionalEdges(&stations[10], &stations[11], 2); //PKLCC - Conlay
    createBidirectionalEdges(&stations[11], &stations[6], 3); //Conlay - TRX
}

int calculateWeight(Station* from, Station* to) {
    Edge* temp = from->ed;
    while (temp != nullptr) {
        if (temp->to == to) {
            return temp->weight;
        }
        temp = temp->nxtE;
    }
    return -1;
}

Station* findStation(string stName) {
    for (int i = 0; i < 12; ++i) {
        if (stations[i].name == stName)
            return &stations[i];
    }
    return nullptr;
}

void displayAllStations() {
    cout << "Available Stations:\n";
    cout << "----------------------------------------\n";
    cout << "1. Titiwangsa\n";
    cout << "2. Chow Kit\n";
    cout << "3. Medan Tuanku\n";
    cout << "4. Bukit Nanas\n";
    cout << "5. Raja Chulan\n";
    cout << "6. Bukit Bintang\n";
    cout << "7. Tun Razak Exchange (TRX)\n";
    cout << "8. Hospital Kuala Lumpur\n";
    cout << "9. Raja Uda\n";
    cout << "10. Ampang Park\n";
    cout << "11. Persiaran KLCC\n";
    cout << "12. Conlay\n";
    cout << "----------------------------------------\n";
}

int getStationIndex(Station* station) {
    for (int i = 0; i < 12; i++) {
        if (&stations[i] == station) {
            return i;
        }
    }
    return -1;
}

Station* findMinDistanceStation(PathInfo* pathInfo) {
    int minDistance = numeric_limits<int>::max();
    Station* minStation = nullptr;

    for (int i = 0; i < 12; i++) {
        if (!pathInfo[i].visited && pathInfo[i].distance < minDistance) {
            minDistance = pathInfo[i].distance;
            minStation = &stations[i];
        }
    }
    return minStation;
}

void findShortestPath(Station* source, Station* destination) {
    PathInfo pathInfo[12];

    // Initialize path info
    for (int i = 0; i < 12; i++) {
        pathInfo[i].distance = numeric_limits<int>::max();
        pathInfo[i].previous = nullptr;
        pathInfo[i].visited = false;
    }

    // setting distance for source station
    int sourceIndex = getStationIndex(source);
    pathInfo[sourceIndex].distance = 0;

    // the main loop
    for (int count = 0; count < 11; count++) {
        Station* current = findMinDistanceStation(pathInfo);
        if (!current) break;

        int currentIndex = getStationIndex(current);
        pathInfo[currentIndex].visited = true;

        // updates distances for adjacent stations
        Edge* edge = current->ed;
        while (edge != nullptr) {
            int neighborIndex = getStationIndex(edge->to);
            if (!pathInfo[neighborIndex].visited) {
                int newDistance = pathInfo[currentIndex].distance + edge->weight;
                if (newDistance < pathInfo[neighborIndex].distance) {
                    pathInfo[neighborIndex].distance = newDistance;
                    pathInfo[neighborIndex].previous = current;
                }
            }
            edge = edge->nxtE;
        }
    }

    // checking if the path exists
    int destIndex = getStationIndex(destination);
    if (pathInfo[destIndex].distance == numeric_limits<int>::max()) {
        cout << "\nNo path exists between " << source->name << " and " << destination->name << ".\n";
        return;
    }

    // Reconstruct path - for backtracking like TRX --> Titiwangsa
    Station* path[12];
    int pathLength = 0;
    Station* current = destination;

    while (current != nullptr) {
        path[pathLength++] = current;
        int currentIndex = getStationIndex(current);
        current = pathInfo[currentIndex].previous;
    }

    // reversing the path
    for (int i = 0; i < pathLength / 2; i++) {
        Station* temp = path[i];
        path[i] = path[pathLength - 1 - i];
        path[pathLength - 1 - i] = temp;
    }

    // Display the path
    cout << "\nShortest path from " << source->name << " to " << destination->name << ":\n";
    for (int i = 0; i < pathLength; i++) {
        cout << path[i]->name;
        if (i < pathLength - 1) {
            cout << " -> ";
        }
    }
    cout << "\nTotal estimated time: " << pathInfo[destIndex].distance << " minutes\n";
}

void dfsAllPathsArray(Station* current, Station* destination, bool visited[], Station* path[], int pathLen, int totalTime) {
    if (current == destination) {
        // Print the path
        for (int i = 0; i < pathLen; i++) {
            cout << path[i]->name;
            if (i < pathLen - 1) cout << " -> ";
        }
        cout << "\nTotal estimated time: " << totalTime << " minutes\n\n";
        return;
    }

    int currentIndex = getStationIndex(current);
    visited[currentIndex] = true;

    Edge* edge = current->ed;
    while (edge != nullptr) {
        int neighborIndex = getStationIndex(edge->to);
        if (!visited[neighborIndex]) {
            path[pathLen] = edge->to;
            dfsAllPathsArray(edge->to, destination, visited, path, pathLen + 1, totalTime + edge->weight);
        }
        edge = edge->nxtE;
    }

    visited[currentIndex] = false; // Backtrack
}
void findAllPathsArray(Station* source, Station* destination) {
    bool visited[12] = {false};
    Station* path[12];
    path[0] = source;

    cout << "\nAll possible paths from " << source->name << " to " << destination->name << ":\n";
    dfsAllPathsArray(source, destination, visited, path, 1, 0);
}


#endif //LINES1_H
