/*************************************************************************
 * AUTHOR          : Connor Peace & Sarah Singletary
 * ASSIGNMENT #12  : DFS
 * CLASS           : CS1C
 * SECTION         : MW: 4:30 - 7:50 PM
 * DUE DATE        : 4/11/16
 *************************************************************************/

#include "Location.h"
#include <iostream>

using namespace std;

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
    lastVisisted = "";
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
 *     endLocation,
 *     distance,
 *     isDiscovered
 ****************************************************************/
Location::Location(string newName,
                   string edgeEnd,
                   double edgeDistance)
{
    name      = newName;
    isVisited = false;

    Edge newEdge;
    newEdge.endLocation   = edgeEnd;
    newEdge.distance     = edgeDistance;
    incidentEdges.push_back(newEdge);
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
 * string getName() const
 *    ACCESSOR
 * Returns the name of the location
 ****************************************************************/
string Location::getName() const {
    return name;
}

/*****************************************************************
 * bool getIsVisited() const
 *    ACCESSOR
 * Returns if the location has been visited already.
 ****************************************************************/
bool Location::getIsVisited() const {
    return isVisited;
}

/*****************************************************************
 * double getDistanceTo(string otherLocation) const
 *    ACCESSOR
 * Returns the distance to the otherLocation, or -1 if there is
 *  no edge to that location
 ****************************************************************/
double Location::getDistanceTo(string otherLocation) const
{
    double distance = -1;


    for(int i = 0; i < incidentEdges.size(); ++i)
    {
        if(incidentEdges[i].endLocation == otherLocation)
        {
            distance = incidentEdges[i].distance;
        }
    }


    return distance;
}

/*****************************************************************
 * vector<Edge> getIncidentEdges() const
 *    ACCESSOR
 * Return the incident edges of the location.
 ****************************************************************/
vector<Edge> Location::getIncidentEdges() const {
    return incidentEdges;
}
/*****************************************************************
 * string getLastVisited() const
 *    ACCESSOR
 * Return the last visited location.
 ****************************************************************/
string Location::getLastVisited() const {
    return lastVisisted;
}

/*****************************************************************
 * void setLastVisited(string newLastVisited)
 *    MUTATOR
 * Sets last visited to
 ****************************************************************/
void Location::setLastVisited(string newLastVisited) {
    lastVisisted = newLastVisited;
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
 * void setName(string newName)
 *    MUTATOR
 * Sets the name of the location.
 ****************************************************************/
void Location::setName(string newName) {
    name = newName;
}

/*****************************************************************
 * void setIncidentEdges(vector<Edge> newEdges)
 *    MUTATOR
 * Sets the incident edges of the location.
 ****************************************************************/
void Location::setIncidentEdges(vector<Edge> newEdges) {
    incidentEdges = newEdges;
}
/*****************************************************************
 * void createEdge(string edgeStart,
 *                 string edgeEnd,
 *                 double edgeDistance)
 *    MUTATOR
 * Creates a new edge and adds it to the list of incident edges
 ****************************************************************/
void Location::createEdge(string edgeEnd,
                          double edgeDistance)
{
    Edge newEdge;
    newEdge.endLocation   = edgeEnd;
    newEdge.distance      = edgeDistance;
    incidentEdges.push_back(newEdge);
}

/*****************************************************************
 * bool deleteEdge(string endingLocation)
 *    MUTATOR
 * Deletes the Edge from the incidentEdges vector with the
 *  ending location specified.
 * Returns true if the Edge was found and deleted
 ****************************************************************/
bool Location::deleteEdge(string endingLocation)
{
    bool deleted = false;

    //Loops through the incident edges
    for(int i = 0; i < incidentEdges.size(); ++i)
    {
        //If the ending location of the edge at index i matches
        // the ending location of the edge to delete
        if(incidentEdges[i].endLocation == endingLocation)
        {
            //Deletes the edge
            incidentEdges.erase(incidentEdges.begin() + i);
            deleted = true;
        }
    }

    return deleted;
}
