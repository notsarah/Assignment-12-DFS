//
// Created by Sarah Singletary on 4/7/16.
//

#include "Location.h"

/*****************************************************************
 * Location(string newName)
 *    CONSTRUCTOR
 * The constructor initializes all attributes in
 * the class Location. The following attributes are:
 *     name,
 *     isVisited
 ****************************************************************/
Location::Location(string newName) {
    name = newName;
    isVisited = false;
}

/*****************************************************************
 * Location(string newName,
 *          string edgeStart,
 *          string edgeEnd,
 *          double edgeDistance)
 *    CONSTRUCTOR
 * The constructor initializes all attributes in
 * the class Location and creates a new Edge at the same time.
 * The Location attributes are:
 *     name,
 *     isVisited
 * The Edge attributes are:
 *     fromLocation;
 *     toLocation;
 *     distance;
 *     isDiscovered
 ****************************************************************/
Location::Location(string newName,
                   string edgeStart,
                   string edgeEnd,
                   double edgeDistance)
{
    name      = newName;
    isVisited = false;

    Edge newEdge;
    newEdge.fromLocation = edgeStart;
    newEdge.toLocation   = edgeEnd;
    newEdge.distance     = edgeDistance;
    adjacentEdges.push_back(newEdge);
}

/*****************************************************************
 * Location(string newName)
 *    DESTRUCTOR
 * Sets all attributes to the default values.
 ****************************************************************/
Location::~Location() {
    isVisited = false;
    name = "";
}

/*****************************************************************
 * string getName()
 *    ACCESSOR
 * Returns the name of the location
 ****************************************************************/
string Location::getName() {
    return name;
}

/*****************************************************************
 * bool getIsVisited()
 *    ACCESSOR
 * Returns if the location has been visited already.
 ****************************************************************/
bool Location::getIsVisited() {
    return isVisited;
}

/*****************************************************************
 * void setIsVisited()
 *    MUTATOR
 * Sets if the location has been visited.
 ****************************************************************/
void Location::setVisited(bool newVisit) {
    isVisited = newVisit;
}

/*****************************************************************
 * bool setName(string newName)
 *    MUTATOR
 * Sets the name of the location.
 ****************************************************************/
void Location::setName(string newName) {
    name = newName;
}


