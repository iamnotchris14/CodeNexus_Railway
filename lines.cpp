#include "lines.h"
#include <iostream>
using namespace std;

Station stationList[MAX_STATIONS];
int adjMatrix[MAX_STATIONS][MAX_STATIONS];
int stationCount = 0;

// Get or assign station index and update line info
int getStationIndex(string name, string line) {
    for (int i = 0; i < stationCount; i++) {
        if (stationList[i].name == name) {
            bool exists = false;
            for (int j = 0; j < stationList[i].lineCount; j++) {
                if (stationList[i].lines[j] == line) {
                    exists = true;
                    break;
                }
            }
            if (!exists && line != "")
                stationList[i].lines[stationList[i].lineCount++] = line;
            return i;
        }
    }
    stationList[stationCount].name = name;
    stationList[stationCount].index = stationCount;
    stationList[stationCount].lineCount = 0;
    if (line != "")
        stationList[stationCount].lines[stationList[stationCount].lineCount++] = line;
    return stationCount++;
}

// add bidirectional edge with travel time
void addEdge(string from, string to, int weight, string line) {
    int u = getStationIndex(from, line);
    int v = getStationIndex(to, line);
    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight;
}

// initalizing all 3 lines, putrajaya, monorail and kajang line
void initializeLines() {
    for (int i = 0; i < MAX_STATIONS; i++)
        for (int j = 0; j < MAX_STATIONS; j++)
            adjMatrix[i][j] = (i == j) ? 0 : INF;

    // Monorail
    string mono[] = {"Titiwangsa", "Chow Kit", "Medan Tuanku", "Bukit Nanas", "Raja Chulan", "Bukit Bintang"};
    for (int i = 0; i < 6; i++)
        if (i > 0) addEdge(mono[i - 1], mono[i], 2, "Monorail");

    // Kajang
    string kajang[] = {"Bukit Bintang", "Tun Razak Exchange TRX"};
    for (int i = 0; i < 2; i++)
        if (i > 0) addEdge(kajang[i - 1], kajang[i], 2, "Kajang");

    // Putrajaya
    string putra[] = {"Titiwangsa", "Hospital KL", "Raja Uda", "Ampang Park", "Persiaran KLCC", "Conlay", "Tun Razak Exchange TRX"};
    int weights[] = {2, 1, 3, 2, 2, 3};
    for (int i = 0; i < 7; i++)
        if (i > 0) addEdge(putra[i - 1], putra[i], weights[i - 1], "Putrajaya");
}

// returning the common line between two stations (if any)
string getCommonLine(int u, int v) {
    for (int i = 0; i < stationList[u].lineCount; i++) {
        for (int j = 0; j < stationList[v].lineCount; j++) {
            if (stationList[u].lines[i] == stationList[v].lines[j])
                return stationList[u].lines[i];
        }
    }
    return "";
}

// Dijkstra with transfer tracking

