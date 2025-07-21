// //
// // Created by VICTUS on 18/7/2025.
// //
// //
// // Created by Christopher Lee Jia Yung on 12/07/2025.
// //
// #include <iostream>
// #include <algorithm>
// #include <limits.h>
// #include "lines.h"
// using namespace std;
//
// // Dijkstra with transfer tracking
// void dijkstra(int src, int dest, int dist[], int prev[])
// {
//     bool visited[MAX_STATIONS] = {false}; //error if dont include braces
//
//     //Initialise distances to infinity and mark all vertices as unvisited
//     for (int i = 0; i < stationCount; i++)
//     {
//         dist[i] = INT_MAX;
//         prev[i] = -1; //initialise to 0, meaning "no previous"
//     }
//
//     /*Set source to itself as 0*/
//     dist[src] = 0;
//
//     /*Find shortest path to all vertices*/
//     for (int count = 0; count < stationCount - 1; count++)
//     {
//         //Find the unvisited station with shortest distance
//         int minDist = INT_MAX; //minDist: tracks the smallest distance found so far
//         int minIndex = -1; //minIndex: stores which vertex has the minimum distance
//
//         //loop to check all stations
//         for (int j = 0; j < stationCount; j++)
//         {
//             //!visited[j] : only consider unvisited
//             if (!visited[j] && dist[j] < minDist)
//             {
//                 minDist = dist[j];
//                 minIndex = j;
//             }
//         }
//
//         //Mark the picked vertex as visited
//         visited[minIndex] = true;
//
//         //Update distances of adjacent vertices
//         for (int v = 0; v < stationCount; v++)
//         {
//             // Update dist[v] if:
//             // 1. v is not visited
//             // 2. There is an edge from minIndex to v (unvisited)
//             // 3. Total weight of path from source to v through minIndex is smaller
//             if (!visited[v] &&
//                 adjMatrix[minIndex][v] > 0 &&
//                 dist[minIndex] + adjMatrix[minIndex][v] < dist[v])
//             {
//                 dist[v] = dist[minIndex] + adjMatrix[minIndex][v];
//                 prev[v] = minIndex;
//             }
//         }
//     }
// }
//
// void printPath(int prev[], int station, int &transferCount)
// {
//     if (prev[station] == -1)
//     {
//         cout << stationList[station].name;
//         return;
//     }
//     printPath(prev, prev[station], transferCount);
//
//     if (stationList[station].lineCount > 0 &&
//     stationList[prev[station]].lineCount > 0)
//     {
//         if (stationList[station].lines[0] != stationList[prev[station]].lines[0])
//         {
//             transferCount++;
//         }
//     }
//
//     cout << " -> " << stationList[station].name;
// }
//
// int main() {
//     initializeLines();
//     string source, destination;
//     int choice;
//
//     // display routes
//     cout << "==========================="<<endl;
//     cout << "Klang Valley Transit Route Planner" << endl;
//     cout << "===========================" << endl;
//     cout << "\tKajang Line" << endl;
//
//     // monorail line
//     cout << "Route (Monorail Line): " << endl;
//     string mono[] = {"Titiwangsa", "Chow Kit", "Medan Tuanku", "Bukit Nanas", "Raja Chulan", "Bukit Bintang"};
//     int monoSize = sizeof(mono) / sizeof(mono[0]);
//
//     for (int i = 0; i < monoSize - 1; i++) {
//         int u = getStationIndex(mono[i]);
//         int v = getStationIndex(mono[i + 1]);
//         int time = adjMatrix[u][v];
//         cout << mono[i] << " -" << time << "min-> ";
//     }
//     cout << mono[monoSize - 1] << endl;
//     // kajang line
//     cout << "\nRoute (Kajang Line): " << endl;
//     string kajang[] = {"Bukit Bintang", "Tun Razak Exchange TRX"};
//     int kajangSize = sizeof(kajang) / sizeof(kajang[0]);
//
//     for (int i = 0; i < kajangSize - 1; i++) {
//         int u = getStationIndex(kajang[i]);
//         int v = getStationIndex(kajang[i + 1]);
//         int time = adjMatrix[u][v];
//         cout << kajang[i] << " -" << time << "min-> ";
//     }
//     cout << kajang[kajangSize - 1] << endl;
//
//     // putrajaya line
//     cout << "\nRoute (Putrajaya Line): " << endl;
//     string putra[] = {"Titiwangsa", "Hospital KL", "Raja Uda", "Ampang Park", "Persiaran KLCC", "Conlay", "Tun Razak Exchange TRX"};
//     int putraSize = sizeof(putra) / sizeof(putra[0]);
//
//     for (int i = 0; i < putraSize - 1; i++) {
//         int u = getStationIndex(putra[i]);
//         int v = getStationIndex(putra[i + 1]);
//         int time = adjMatrix[u][v];
//         cout << putra[i] << " -" << time << "min-> ";
//     }
//     cout << putra[putraSize - 1] << endl;
//
//     // prompt user input
//     do {
//         cout << "\nEnter source station: ";
//         getline(cin, source);
//
//         cout << "Enter destination station: ";
//         getline(cin, destination);
//
//         cout << "\nCalculating shortest route..." << endl;
//         cout << "Shortest route found!" << endl;
//
//         //Options
//         cout << "1 - Display shortest route only\n"
//                 "2 - Display all routes\n"
//                 "3 - Exit" << endl;
//         cout << "Enter choice: ";
//         cin >> choice;
//         cin.ignore();
//
//         switch (choice) {
//             // case 1: cout << "\nRoute: " << endl;
//             //         cout << "Total time taken: " << endl;
//             //         cout << "Total transfers: " << endl;
//             //         break;
//             case 1: {
//                 int src = getStationIndex(source);
//                 int dest = getStationIndex(destination);
//
//                 if (src == -1 || dest == -1) {
//                     cout << "Invalid station names. Please try again." << endl;
//                     break;
//                 }
//
//                 int dist[MAX_STATIONS];
//                 int visited[MAX_STATIONS];
//                 int transferCount = 0;
//
//                 dijkstra(src, dest, dist, visited);
//
//                 if (dist[dest] == INT_MAX) {
//                     cout << "No available path between " << source << " and " << destination << "." << endl;
//                 } else
//                 {
//                     cout << "\nRoute: ";
//                     printPath(visited, dest, transferCount);
//                     cout << "\nTotal time taken: " << dist[dest] << " minutes" << endl;
//                     cout << "Total transfers: " << transferCount << endl;
//                 }
//                 break;
//             }
//
//             case 2:
//             {
//                 cout << "Route 1:  " << endl;
//                 cout << "Total time taken: " << endl;
//                 cout << "Total transfers: " << endl;
//                 cout << "\nRoute 2: "<< endl;
//                 cout << "Total time taken: " << endl;
//                 cout << "Total transfers: " << endl;
//                 break;
//             }
//
//             case 3:
//             {
//                 cout << "Thank you for using our Railway System," << endl;
//                 cout << "Have a safe trip and hope to see you again!" << endl;
//                 break;
//             }
//
//             default:
//             {
//                 cout << "Invalid choice" << endl;
//             }
//         }
//     }while (choice != 3);
//
//     return 0;
// }
//
//
