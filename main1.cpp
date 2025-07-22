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

    int choice;
    do {
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

        int subChoice;
        do {
            cout << "\nWhat would you like to do?\n";
            cout << "1 - Display shortest route only\n";
            cout << "2 - Display all possible routes\n";
            cout << "3 - Enter new source and destination\n";
            cout << "4 - Exit\n";
            cout << "Enter choice: ";
            cin >> subChoice;
            cin.ignore();

            switch (subChoice) {
                case 1: findShortestPath(source, destination);
                    break;
                case 2: findAllPathsArray(source, destination);
                    break;
                case 3: cout << "\nReturning to station input...\n";
                    break;
                case 4: cout << "\nThank you for using CodeNexus Transit Route Planner! We hope to see you again :)\n";
                    return 0;
                default: cout << "Invalid choice." << endl;
            }
        }while (subChoice != 3);
    }while (true);

    return 0;
}