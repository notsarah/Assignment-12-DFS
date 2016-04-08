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

class Location {

public:
    Location(string newName);
    ~Location();

    string getName();
    bool getIsVisited();

    void setVisited(bool newVisit);
    void setName(string newName);


private:
    /** name represent a single vertices */
    string name;
    /** checks if the location been visited yet or not */
    bool isVisited;
};

#endif //LOCATION_H
