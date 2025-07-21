//
// Created by HASHIKA KESHREEN on 7/21/2025.
//

#ifndef LINES1_H
#define LINES1_H

#include <iostream>
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

//Declare and initialize the array of Stations
Station stations[12] = {{"Titiwangsa", NULL},{"Chow Kit", NULL}, {"Medan Tuanku", NULL},
                   {"Bukit Nanas", NULL}, {"Raja Chulan", NULL}, {"Bukit Bintang", NULL},
                   {"Tun Razak Exchange (TRX)", NULL },{"Hospital Kuala Lumpur", NULL}, {"Raja Uda", NULL},
                      {"Ampang Park", NULL}, {"Persiaran KLCC", NULL}, {"Conlay", NULL}};

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
    while (temp != NULL) {
        if (temp->to == to) {
            return temp->weight;
        }
        temp = temp->nxtE;
    }
    return -1;
}

Station* findStation(string stName) {
    for (int i = 0; i < 11; ++i) {
        if (stations[i].name == stName)
            return &stations[i];
    }
    return nullptr;
}
#endif //LINES1_H
