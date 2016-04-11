/*************************************************************************
 * AUTHOR          : Connor Peace & Sarah Singletary
 * ASSIGNMENT #12  : DFS
 * CLASS           : CS1C
 * SECTION         : MW: 4:30 - 7:50 PM
 * DUE DATE        : 4/11/16
 *************************************************************************/

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <sstream>
#include <string>
#include "Location.h"

using namespace std;

class Graph {

public:
    Graph();
    ~Graph();
    void addLocation(Location *newLocation);
    void DFSTraversal(string startingPoint);

    Location* findLocation(string name);

    /** Utility method for DFSTraversal */
//    Location* findNextEdge(Location *currentLocation);


    void addPath(string to, string from, double distance);
//    vector<Edge> getDiscoveredEdges();
    vector<Edge> getPaths();

    int getNumberOfLocations();
    string displayLocation();


private:
    vector<Location> vertices;
    vector<Edge> edges;
    int numberOfLocations;
};


#endif //GRAPH_H
