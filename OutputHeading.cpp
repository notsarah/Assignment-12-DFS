/*************************************************************************
 * AUTHOR          : Connor Peace & Sarah Singletary
 * ASSIGNMENT #12  : DFS
 * CLASS           : CS1C
 * SECTION         : MW: 4:30 - 7:50 PM
 * DUE DATE        : 4/11/16
 *************************************************************************/

#include "Header.h"

string OutputHeading() {

    ostringstream output;

    output << "+-------------------------------------------+\n"
           << "|                                           |\n"
           << "|   ASSIGNMENT #12                          |\n"
           << "|          Depth-First Search (DFS)         |\n"
           << "|                                           |\n"
           << "|                                           |\n"
           << "|                  by:                      |\n"
           << "|      Connor Peace & Sarah Singletary      |\n"
           << "|                                           |\n"
           << "+-------------------------------------------+\n\n";

    output << "DESCRIPTION:\n"
           << "--------------------------------------------------\n"
           << "This program implements a graph that performs a \n"
           << " depth-first search that starts at Dallas using \n"
           << " the map of the United States. It always chooses\n"
           << " the edge with the smallest mileage. It also    \n"
           << " outputs all edges that were discovered.        \n\n";

    return output.str();

}