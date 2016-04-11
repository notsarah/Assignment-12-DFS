/*************************************************************************
 * AUTHOR          : Connor Peace & Sarah Singletary
 * ASSIGNMENT #12  : DFS
 * CLASS           : CS1C
 * SECTION         : MW: 4:30 - 7:50 PM
 * DUE DATE        : 4/11/16
 *************************************************************************/

#include "Location.h"

/*****************************************************************
 * Location(string newName)
 *    CONSTRUCTOR
 * The constructor initializes all attributes in
 * the class Location. The following attributes are:
 *     name,
 *     isVisited,
 *     lastVisisted,
 *     paths
 ****************************************************************/
Location::Location(string newName) {
    name = newName;
    isVisited = false;
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
 * vector<Edge> getAdjacentEdges()
 *    ACCESSOR
 * Return the adjacent edges of the location.
 ****************************************************************/
vector<Edge> Location::getAdjacentEdges() {
    return adjacentEdges;
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

}

