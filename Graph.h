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
    /****************************
     * CONSTRUCTOR & DESTRUCTOR *
     ****************************/
    Graph();
    ~Graph();

    /*************
     * ACCESSORS *
     *************/
    Location* findLocation(string name);

    /************
     * MUTATORS *
     ************/
    void addLocation(Location *newLocation);
    vector<Location> DFSTraversal(string startingPoint);

    /** Utility method for DFSTraversal */
    Location* findShortestPath(Location *currentLocation);

    void addPath(string location1, string location2, double distance);
    vector<Edge> getDiscoveredEdges();

    int getNumberOfLocations();
    string displayLocations();
    int numberOfLocations;

private:
    vector<Location> vertices;

};


#endif //GRAPH_H
