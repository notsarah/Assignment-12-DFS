/*************************************************************************
 * AUTHOR          : Connor Peace & Sarah Singletary
 * ASSIGNMENT #12  : DFS
 * CLASS           : CS1C
 * SECTION         : MW: 4:30 - 7:50 PM
 * DUE DATE        : 4/11/16
 *************************************************************************/

#include "Header.h"

int main() {
    Graph map;
    vector<Location> DFS;

    cout << OutputHeading();

    map.addLocation(new Location("Dallas"));
    map.addLocation(new Location("Seattle"));
    map.addLocation(new Location("San Francisco"));
    map.addLocation(new Location("Los Angeles"));
    map.addLocation(new Location("Denver"));
    map.addLocation(new Location("Kansas City"));
    map.addLocation(new Location("Chicago"));
    map.addLocation(new Location("Houston"));
    map.addLocation(new Location("Boston"));
    map.addLocation(new Location("Atlanta"));
    map.addLocation(new Location("Miami"));
    map.addLocation(new Location("New York"));

    /** Testing if locations are being added & output properly,
     * can delete this later!! */
    cout << "*** TESTING ***\n";
    cout << "Number of locations: " << map.getNumberOfLocations() << endl;
    cout << map.displayLocations();

    /* Commented out until needed */
//    DFS = map.DFSTraversal("Dallas");

    //Output the discovered edges
    cout << map.displayDiscoveredEdges(DFS);

    //Output the total mileage for the DFS





    return 0;

}