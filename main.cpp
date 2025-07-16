//
// Created by Christopher Lee Jia Yung on 12/07/2025.
//
#include <iostream>
#include <algorithm>
#include "lines.h"
using namespace std;

int main() {
    initializeLines();
    string source, destination;
    int choice;

    // display routes
    cout << "==========================="<<endl;
    cout << "Klang Valley Transit Route Planner" << endl;
    cout << "===========================" << endl;
    cout << "\tKajang Line" << endl;

    // monorail line
    cout << "Route (Monorail Line): " << endl;
    string mono[] = {"Titiwangsa", "Chow Kit", "Medan Tuanku", "Bukit Nanas", "Raja Chulan", "Bukit Bintang"};
    int monoSize = sizeof(mono) / sizeof(mono[0]);

    for (int i = 0; i < monoSize - 1; i++) {
        int u = getStationIndex(mono[i]);
        int v = getStationIndex(mono[i + 1]);
        int time = adjMatrix[u][v];
        cout << mono[i] << " -" << time << "min-> ";
    }
    cout << mono[monoSize - 1] << endl;
    // kajang line
    cout << "\nRoute (Kajang Line): " << endl;
    string kajang[] = {"Bukit Bintang", "Tun Razak Exchange TRX"};
    int kajangSize = sizeof(kajang) / sizeof(kajang[0]);

    for (int i = 0; i < kajangSize - 1; i++) {
        int u = getStationIndex(kajang[i]);
        int v = getStationIndex(kajang[i + 1]);
        int time = adjMatrix[u][v];
        cout << kajang[i] << " -" << time << "min-> ";
    }
    cout << kajang[kajangSize - 1] << endl;

    // putrajaya line
    cout << "\nRoute (Putrajaya Line): " << endl;
    string putra[] = {"Titiwangsa", "Hospital KL", "Raja Uda", "Ampang Park", "Persiaran KLCC", "Conlay", "Tun Razak Exchange TRX"};
    int putraSize = sizeof(putra) / sizeof(putra[0]);

    for (int i = 0; i < putraSize - 1; i++) {
        int u = getStationIndex(putra[i]);
        int v = getStationIndex(putra[i + 1]);
        int time = adjMatrix[u][v];
        cout << putra[i] << " -" << time << "min-> ";
    }
    cout << putra[putraSize - 1] << endl;

    // prompt user input
    do {
        cout << "\nEnter source station: ";
        getline(cin, source);

        cout << "Enter destination station: ";
        getline(cin, destination);

        cout << "\nCalculating shortest route..." << endl;
        cout << "Shortest route found!" << endl;

        //Options
        cout << "1 - Display shortest route only\n"
                "2 - Display all routes\n"
                "3 - Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: cout << "\nRoute: " << endl;
                    cout << "Total time taken: " << endl;
                    cout << "Total transfers: " << endl;
                    break;
            case 2: cout << "Route 1:  " << endl;
                    cout << "Total time taken: " << endl;
                    cout << "Total transfers: " << endl;
                    cout << "\nRoute 2: "<< endl;
                    cout << "Total time taken: " << endl;
                    cout << "Total transfers: " << endl;
                    break;
            case 3: cout << "Thank you for using our Railway System," << endl;
                    cout << "Have a safe trip and hope to see you again!" << endl;
                    break;
            default: cout << "Invalid choice" << endl;
        }
    }while (choice != 3);

    return 0;
}

