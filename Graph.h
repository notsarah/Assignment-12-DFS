/*************************************************************************
 * AUTHOR          : Connor Peace & Sarah Singletary
 * ASSIGNMENT #12  : DFS
 * CLASS           : CS1D
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
    vector<Location> DFSTraversal(string startingPoint) const;
    /** Utility method for DFSTraversal */
    Location* findShortestPath(Location *currentLocation) const;
    Location* findLocation(string name) const;
    int getNumberOfLocations() const;
    string displayLocations() const;

    /************
     * MUTATORS *
     ************/
    void addLocation(Location *newLocation);
    void addPath(string location1, string location2, double distance);
    string displayDiscoveredEdges(vector<Location> locations);

private:
    /** Holds all of the vertices */
    vector<Location> vertices;
    /** Counts the number of vertices */
    int numberOfLocations;
};

#endif //GRAPH_H
