/*************************************************************************
 * AUTHOR          : Connor Peace & Sarah Singletary
 * ASSIGNMENT #12  : DFS
 * CLASS           : CS1C
 * SECTION         : MW: 4:30 - 7:50 PM
 * DUE DATE        : 4/11/16
 *************************************************************************/

#ifndef LOCATION_H
#define LOCATION_H


#include <string>
#include <vector>

using namespace std;

struct Edge {
    /** represents the name of the ending Location of the edge */
    string endLocation;
    /** distance represents the weight, to help determine the shortest distance */
    double distance;
    /** sets if the edge was discovered or if the path was taken */
    bool isDiscovered = false;
};

class Location {

public:
    /*****************************
     * CONSTRUCTORS & DESTRUCTOR *
     *****************************/
    Location(string newName);
    Location(string newName,
             string edgeEnd,
             double edgeDistance);
    ~Location();

    /*************
     * ACCESSORS *
     *************/
    string getName();
    bool getIsVisited();
    vector<Edge> getIncidentEdges();

    /************
     * MUTATORS *
     ************/
    void setVisited(bool newVisit);
    void setName(string newName);
    void createEdge(string edgeEnd,
                    double edgeDistance);
    bool deleteEdge(string endingLocation);



private:
    /** name represent a single vertices */
    string name;
    /** checks if the location been visited yet or not */
    bool isVisited;
    /** all of the incident edges to this location */
    vector<Edge> incidentEdges;
};

#endif //LOCATION_H
