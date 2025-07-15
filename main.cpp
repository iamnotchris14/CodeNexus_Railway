//
// Created by Christopher Lee Jia Yung on 12/07/2025.
//
#include <iostream>
#include "lines.h"
using namespace std;

int main() {
    initializeLines();

    // algorithm and user input
    string source, destination;
    int choice;

    cout << "==========================="<<endl;
    cout << "Klang Valley Transit Route Planner" << endl;
    cout << "===========================" << endl;
    cout<< "\tKajang Line" << endl;
    do {
        cout << "Enter source station: ";
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

        switch (choice) {
            case 1: "\nRoute: " << endl;
                    "Total time taken: " << endl;

        }
    }while (choice != 3);

    return 0;
}

