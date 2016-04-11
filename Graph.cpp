/*************************************************************************
 * AUTHOR          : Connor Peace & Sarah Singletary
 * ASSIGNMENT #12  : DFS
 * CLASS           : CS1C
 * SECTION         : MW: 4:30 - 7:50 PM
 * DUE DATE        : 4/11/16
 *************************************************************************/

#include "Graph.h"
#include <iostream>

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
    Location* previousLocation = NULL;

    currentLocation->setVisited(true);
    DFS.push_back(*currentLocation);

    /** Ensures it won't exceed the number of locations there are,
     * (it is numberOfLocations - 1, since we already visited the
     * the starting point). */
    int i = 0;
    while (i < numberOfLocations - 1) {

        /** Based off the current location, it determines the next path
         * to take (edge with shortest distance)
         * findShortestPath then returns the location is
         * will travel next to */
        previousLocation = currentLocation;
        currentLocation = findShortestPath(currentLocation);

        /** Sets the visit to true and adds the edge to the list */
        if(currentLocation != NULL) {
            currentLocation->setLastVisited(DFS.back().getName());

            currentLocation->setVisited(true);
            DFS.push_back(*currentLocation);
            i++;
        }
        else {
            /** If the current location sent back is NULL, it means
             * all paths to the next location have been visited,
             * therefore will reverse and check if there is an
             * available path to a location not visited yet */
                currentLocation = findLocation(previousLocation->getLastVisited());


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
    double shortestDistance;

    int start = 0;

    while(start < currentEdges.size()) {

        if(!findLocation(currentEdges[start].endLocation)->getIsVisited()) {

            shortestDistance = currentEdges[start].distance;
            break;
        }
        else {
            start++;

        }

    }

    index = start;


    for(int i = index; i < currentEdges.size(); ++i) {

        /** Checks if it the current edge is shorter than the current
         * shortest, also checks if the location has already been visited.
         * If not, it assigns the new shortestDistance */

        if(!findLocation(currentEdges[i].endLocation)->getIsVisited() && (shortestDistance > currentEdges[i].distance)) {
            index = i;
            shortestDistance = currentEdges[i].distance;
        }
    }

    if(index < currentEdges.size()) {

        currentEdges[index].isDiscovered = true;
        currentLocation->setIncidentEdges(currentEdges);
        return findLocation(currentEdges[index].endLocation);
    }
    else {
        return NULL;
    }
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

/*****************************************************************
 * void addPath(string location1,
 *              string location2,
 *              double distance)
 *    MUTATOR
 * Adds a new edge that connections location1 to location2
 ****************************************************************/
void Graph::addPath(string location1,
                    string location2,
                    double distance)
{
    Location* loc1 = findLocation(location1);
    Location* loc2 = findLocation(location2);

    loc1->createEdge(location2, distance);
    loc2->createEdge(location1, distance);
}


/*****************************************************************
 * string displayDiscoveredEdges(vector<Location> locations)
 *    ACCESSOR
 * RETURNS -> string of all the discovered edges and their
 *             distances
 ****************************************************************/
string Graph::displayDiscoveredEdges(vector<Location> locations)
{
    ostringstream out;
    double distance;

    for(int i = 0; i < locations.size() - 1; ++i)
    {

        distance = locations[i].getDistanceTo(locations[i+1].getName());

        int lastLocationIndex = i;

        if(distance != -1) {
            //Outputs the name of the current -> name of the next
            out << locations[i].getName() << " -> "
            << locations[i + 1].getName();

            //Outputs the distance between the two
            out << " (" << distance << ")";

            //Outputs a comma if it isn't the last edge to output
            if (i + 1 < locations.size() - 1) {
                out << ", \n";
            }
        }

        /** If distance was not found, it returns -1, reverses util it
         * backtracks it finds the correct next edge */
        while(distance == -1) {
            //Outputs the name of the current -> name of the next
            out << locations[lastLocationIndex].getName() << " -> "
            << locations[lastLocationIndex-1].getName();

            distance = locations[lastLocationIndex].getDistanceTo
                    (locations[lastLocationIndex-1].getName());

            //Outputs the distance between the two
            out << " (" << distance << ")" << endl;
            distance = locations[lastLocationIndex - 1].getDistanceTo
                    (locations[i+1].getName());

            lastLocationIndex--;
        }

    }
    out << ".";

    return out.str();
}