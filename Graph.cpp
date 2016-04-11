/*************************************************************************
 * AUTHOR          : Connor Peace & Sarah Singletary
 * ASSIGNMENT #12  : DFS
 * CLASS           : CS1C
 * SECTION         : MW: 4:30 - 7:50 PM
 * DUE DATE        : 4/11/16
 *************************************************************************/

#include "Graph.h"

Graph::Graph() {
    numberOfLocations = 0;

}

Graph::~Graph() {

}

void Graph::addLocation(Location *newLocation) {

    vertices.push_back(*newLocation);

    /** Increments every time a location is added */
    numberOfLocations++;
}

//This should return a vector of the Locations to visit, in order
void Graph::DFSTraversal(string startingPoint) {
    /** needs a stack in here */
    Location* currentLocation;

    //PSEUDOCODE

    //Finds the edge with the shortest distance

    //Adds the edge to the list






}

Location* Graph::findLocation(string name) {
    bool found              = false;
    Location *foundLocation = NULL;
    int index               = 0;

    /** Finds the specific location by name
     * within the graph */
    while(!found && index != numberOfLocations) {
        if(vertices[index].getName() == name) {
            found = true;
            foundLocation = &vertices[index];
        }

        index++;
    }

    return foundLocation;
}

vector<Edge> Graph::getPaths() {
    return edges;
}

void Graph::addPath(string to, string from, double distance) {
    Edge newEdge;
    newEdge.toLocation = to;
    newEdge.fromLocation = from;
    newEdge.distance = distance;

    edges.push_back(newEdge);
}

int Graph::getNumberOfLocations() {
    return numberOfLocations;
}

string Graph::displayLocation() {
    ostringstream output;
    for(int i = 0; i < numberOfLocations; i++) {
        output << vertices[i].getName()
        << (i == numberOfLocations - 1 ? "\n" : ", ");
    }

    return output.str();
}
