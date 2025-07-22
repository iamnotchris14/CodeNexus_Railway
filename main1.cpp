//
// Created by HASHIKA KESHREEN on 7/21/2025.
//
#include <iostream>
#include "lines1.h"

Station* getStationInput(const string& prompt) {
    string stationName;
    Station* station = nullptr;

    while (true) {
        cout << prompt;
        getline(cin, stationName);

        station = findStation(stationName);
        if (station != nullptr) {
            return station;
        } else {
            cout << "Invalid station name. Please try again.\n";
            displayAllStations();
        }
    }
}

int main() {
    // Build the graph
    buildGraph();

    cout << "Welcome to CodeNexus Transit Route Planner!\n";
    cout << "========================================\n\n";

    // Display all stations
    displayAllStations();

    // Get source and destination stations
    Station* source = getStationInput("Enter Source Station: ");
    Station* destination = getStationInput("Enter Destination Station: ");

    // Check if source and destination are the same
    while (source == destination) {
        cout << "Source and destination cannot be the same. Please enter different stations.\n";
        source = getStationInput("Enter Source Station: ");
        destination = getStationInput("Enter Destination Station: ");
    }

    // Find and display the shortest path
    findShortestPath(source, destination);

    cout << "\nThank you for using CodeNexus Transit Route Planner! We hope to see you again :)\n";
    return 0;
}