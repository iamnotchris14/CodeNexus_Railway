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

    cout << "==========================="<<endl;
    cout << "Klang Valley Transit Route Planner" << endl;
    cout << "===========================" << endl;
    cout<< "\tKajang Line" << endl;
    cout << "Enter source station: ";
    getline(cin, source);
    cout << "Enter destination station: ";
    getline(cin, destination);

    return 0;
}

