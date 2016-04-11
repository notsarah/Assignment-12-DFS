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

/*****************************************************************
 * vector<Location> DFSTraversal(string startingPoint)
 *    ACCESSOR
 * This method implements a DFSTraversal
 * RETURNS -> vector in the depth-first search traversal order.
 ****************************************************************/
vector<Location> Graph::DFSTraversal(string startingPoint) {
    vector<Location> DFS;

    Location* currentLocation = findLocation(startingPoint);

    currentLocation->setVisited(true);
    DFS.push_back(*currentLocation);

    /** Ensures it won't exceed the number of locations there are,
     * (it is numberOfLocations - 1, since we already visited the
     * the starting point). */
    int i = 0;
    while (i < numberOfLocations) {

        /** Based off the current location, it determines the next path
         * to take (edge with shortest distance)
         * findShortestPath then returns the location is
         * will travel next to */
        currentLocation = findShortestPath(currentLocation);

        /** Sets the visit to true and adds the edge to the list */
        if(currentLocation != NULL) {
            currentLocation->setVisited(true);
            DFS.push_back(*currentLocation);
            i++;
        }
        else {
            /** If the current location sent back is NULL, it means
             * all paths to the next location have been visited,
             * therefore will reverse and check if there is an
             * available path to a location not visited yet */
            currentLocation = &DFS[DFS.size() - 1];
        }
    }

    return DFS;

}

/*****************************************************************
 * Location* findShortestPath(Location *currentLocation)
 *    ACCESSOR
 * Finds the shortest path, used as a utility method for
 * DFS traversal method.
 ****************************************************************/
Location* Graph::findShortestPath(Location *currentLocation) {
    vector<Edge> currentEdges = currentLocation->getIncidentEdges();

    int index = 0; // index of the shortest distance
    double shortestDistance = currentEdges[0].distance;

    for(int i = 1; i < currentEdges.size(); i++) {

        /** Checks if it the current edge is shorter than the current
         * shortest, also checks if the location has already been visisted.
         * If not, it assigns the new shortestDistance */


}

/*****************************************************************
 * Location* findLocation(string name)
 *    ACCESSOR
 * Finds if the location exist within the graph.
 * RETURNS -> the found location or null if not found
 ****************************************************************/
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

//void Graph::addPath(string to, string from, double distance) {
//    Edge newEdge;
//    newEdge.endLocation = to;
//    newEdge.fromLocation = from;
//    newEdge.distance = distance;
//
//    edges.push_back(newEdge);
//}

/*****************************************************************
 * int getNumberOfLocations()
 *    ACCESSOR
 * RETURNS -> The # of locations within the graph.
 ****************************************************************/
int Graph::getNumberOfLocations() {
    return numberOfLocations;
}

/*****************************************************************
 * string displayLocations()
 *    ACCESSOR
 * Outputs each location within the graph.
 * RETURNS -> string of locations
 ****************************************************************/
string Graph::displayLocations() {
    ostringstream output;
    for(int i = 0; i < numberOfLocations; i++) {
        output << vertices[i].getName()
        << (i == numberOfLocations - 1 ? "\n" : ", ");
    }

    return output.str();
}
