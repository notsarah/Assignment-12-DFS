/*************************************************************************
 * AUTHOR          : Connor Peace & Sarah Singletary
 * ASSIGNMENT #12  : DFS
 * CLASS           : CS1D
 * SECTION         : MW: 4:30 - 7:50 PM
 * DUE DATE        : 4/11/16
 *************************************************************************/

#include "Header.h"

int main() {
    Graph map;            //Simulates the map of the United States
    vector<Location> DFS; //Stores the DFS traversal of the graph

    //Outputs the heading for the assignment
    cout << OutputHeading();

    //Adds all of the vertices to the graph
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

    //Adds all of the edges to the graph
    map.addPath("Dallas", "Houston", 239);
    map.addPath("Dallas", "Los Angeles", 1435);
    map.addPath("Dallas", "Kansas City", 496);
    map.addPath("Dallas", "Atlanta", 781);

    map.addPath("Seattle", "San Francisco", 381);
    map.addPath("Seattle", "Denver", 1331);
    map.addPath("Seattle", "Chicago", 2097);

    map.addPath("San Francisco", "Denver", 1267);
    map.addPath("San Francisco", "Los Angeles", 381);

    map.addPath("Los Angeles", "Denver", 1015);
    map.addPath("Los Angeles", "Kansas City", 1663);

    map.addPath("Denver", "Chicago", 1003);
    map.addPath("Denver", "Kansas City", 599);

    map.addPath("Kansas City", "Chicago", 533);
    map.addPath("Kansas City", "Atlanta", 864);
    map.addPath("Kansas City", "New York", 1260);

    map.addPath("Chicago", "New York", 787);
    map.addPath("Chicago", "Boston", 983);

    map.addPath("Houston", "Atlanta", 810);
    map.addPath("Houston", "Miami", 1187);

    map.addPath("Boston", "New York", 214);

    map.addPath("Atlanta", "Miami", 661);
    map.addPath("Atlanta", "New York", 888);

    //Performs a Depth-First Search on the graph
    DFS = map.DFSTraversal("Dallas");

    //Displays the cities in the order in which they are visited
    cout << "+------------------------+\n"
         << "|      DFS TRAVERSAL     |\n"
         << "+------------------------+\n";
    for(int i = 0; i < DFS.size(); i++) {
        cout << i + 1 << ":\t" << DFS[i].getName() << "\n";
    }

    //Displays all of the discovered edges
    cout << "\n+------------------------+\n"
         << "|    DISCOVERED EDGES    |\n"
         << "+------------------------+\n";
    cout << map.displayDiscoveredEdges(DFS);

    return 0;
}