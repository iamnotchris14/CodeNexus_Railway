// #ifndef LINES_H
// #define LINES_H
//
// #include <string>
// using namespace std;
//
// const int INF = 9999;
// const int MAX_STATIONS = 50;
//
// // declare station and line in a structure
// struct Station {
//     string name;
//     int index;
//     string lines[3];
//     int lineCount;
// };
//
// // declare global arrays
// extern Station stationList[MAX_STATIONS];
// extern int adjMatrix[MAX_STATIONS][MAX_STATIONS];
// extern int stationCount;
//
// // function declarations
// int getStationIndex(string name, string line = "");
// void addEdge(string from, string to, int weight, string line);
// void initializeLines();
// string getCommonLine(int u, int v);
//
// #endif
