#pragma once
#ifndef MAPPING_H
#define MAPPING_H

#define MAP_ROWS 25
#define MAP_COLS 25
#define MAX_ROUTE 100
#define BLUE 2
#define GREEN 4
#define YELLOW 8
#define DIVERSION 16
#define MAX_WEIGHT_IN_KGS 2000
#define MAX_VOLUME_IN_CU_M 20
#define COLOR_BUILDING "\033[1;30m"
#define COLOR_GREEN_ROUTE "\033[1;32m"
#define COLOR_YELLOW_ROUTE "\033[1;33m"
#define COLOR_BLUE_ROUTE "\033[1;34m"
#define COLOR_OVERLAP "\033[1;35m"
#define COLOR_SHORTEST_PATH "\033[1;36m"
#define COLOR_MISC "\033[1;31m"
#define COLOR_RESET "\033[1;0m"

/**
 * A map is a 2D raster representation of a map with contents of the map encoded as numeric values.
 */
struct Map {
    int squares[MAP_ROWS][MAP_COLS];
    int numRows;
    int numCols;
};

/**
 * A point represents the row-column position of a square on a map.
 */
struct Point {
    char row;
    char col;
};

/**
 * A route is a collection of points that are adjacent to one another and constitute a path from the
 * first point on the path to the last.
 */
struct Route {
    struct Point points[MAX_ROUTE];
    int numPoints;
    char routeSymbol;
};
/**
 * Represents a shipment, consisting of a destination point on the map,
 * weight in kilograms, and volume in cubic meters.
 */
struct Shipment {
    struct Point destination;
    double weightInKGs;
    double volumeInCuMs;
};

/**
 * Represents a truck, which can carry multiple shipments.
 * It includes information about the truck's route, weight capacity, and volume capacity.
 */
struct Truck {
    struct Route route;
    double weightInKGs;
    double volumeInCuMs;
};

/**
 * Create a map with the position of all buildings in it.
 * @returns - a map with the position of all buildings added to it.
 */
struct Map populateMap();

/**
 * Get the number of rows in a map.
 * @param map - the map to query
 * @returns - the number of rows in the map.
 */
int getNumRows(const struct Map* map);

/**
 * Get the number of columns in a map.
 * @param map - the map to query
 * @returns - the number of columns in the map.
 */
int getNumCols(const struct Map* map);

/**
 * Print the symbol using color codes:
 * space = ignored (open space)
 * X = black (building)
 * B = blue (blue route)
 * G = green (green route)
 * Y = yellow (yellow route)
 * ., -, *, + = magenta (routes overlap)
 * P = cyan (shortest path)
 * @param map - symbol to print
 */
void printSymColor(const char sym);

/**
 * Print the map using the symbols:
 * space = open space
 * X = building
 * B = blue route
 * G = green route
 * Y = yellow route
 * . = B & G routes overlap
 * - = B & Y routes overlap
 * * = G & Y routes overlap
 * + = B & G & Y routes overlap
 * P = a shortest path or route from one point to another
 * @param map - map to print
 * @param base1 - if true print row indices from 1 up otherwise 0 up
 * @param alphaCols - if true print col header as letters, otherwise numbers
 */
void printMap(const struct Map* map, const int base1, const int alphaCols);

/**
 * Add a route to a map using the indicated symbol.
 * @param map - map to add route to
 * @param route - the route to add to the map
 * @returns a copy of the original map with the route added to it
 */
struct Map addRoute(const struct Map* map, const struct Route* route);

/**
 * Add a point to a route
 * @param route - the route to which the point should be added
 * @param point - the point to add to the route.
 */
void addPtToRoute(struct Route* route, struct Point pt);

/**
 * Add a point to a route if it is not equal to another point.
 * @param route - the route to which the point should be added
 * @param row - the row of the point to add to the route.
 * @param col - the column of the point to add to the route.
 * @param notThis - the point will be added to the route ONLY if it is not equal to this point.
 */
void addPointToRouteIfNot(struct Route* route, const int row, const int col, const struct Point notThis);

/**
 * Add a point to a route
 * @param route - the route to which the point should be added
 * @param point - the point to add to the route.
 */
void addPointToRoute(struct Route* route, const int row, const int col);

/**
 * Build and return the route for the blue trucks.
 * @returns - the route for the blue trucks.
 */
struct Route getBlueRoute();

/**
 * Build and return the route for the green trucks.
 * @returns - the route for the green trucks.
 */
struct Route getGreenRoute();

/**
 * Build and return the route for the yellow trucks.
 * @returns - the route for the yellow trucks.
 */
struct Route getYellowRoute();

/**
 * Calculate the Euclidian distance between two points.
 * @param p1 - the first point
 * @param p2 - the second point
 * @returns - the distance between p1 and p2.
 */
double distance(const struct Point* p1, const struct Point* p2);

/**
 * Calculate the shortest path between two points so that the path does not pass through buildings.
 * @param map - the map showing the location of buildings.
 * @param start - the point to start from
 * @param dest - the point to go to
 * @returns - the shortest path from start to dest. If there is no path, then a Route of zero length is returned.If start
 * and dest are the same point, it also returns a Route of zero length.
 */
struct Route shortestPath(const struct Map* map, const struct Point start, const struct Point dest);

/**
 * Calculate all adjacent squares to a given point so that the squares do not overpal a building and do not include the backpath.
 * @param map - the map showing the location of buildings.
 * @param p1 - the point to calculate possible moves for
 * @param backpath - the previous point we visited on the path we travelled so we will exclude travelling backwards.
 * @returns - a collection of adjacent points we could potentially move to.
 */
struct Route getPossibleMoves(const struct Map* map, const struct Point p1, const struct Point backpath);

/**
 * Calculates the Euclidian distance from every point in a route to a single point and returns the
 * index of the point in the route which is closest to the point.
 * @param route - the route to use to find the closest point
 * @param pt - the point to to find the member of the route which is closest to this point
 * @returns - the index of the closest point on the route to the point or -1 if the route is empty.
 */
int getClosestPoint(const struct Route* route, const struct Point pt);

/**
 * Compare two points for equality.
 * @param p1 - the first point
 * @param p2 - the second point
 * @returns - true if p1 is equal to p2
 */
int eqPt(const struct Point p1, const struct Point p2);
/**
 * Adds a shipment to the best suitable truck from the given list of trucks.
 * The function determines the best truck based on available room, limiting factor, and least diversion.
 * If a suitable truck is found, the shipment is added to that truck.
 *
 * @param trucks      An array of trucks to consider for the shipment.
 * @param map         The map with the buildings on it.
 * @param shipment    The shipment to be assigned.
 * @param numOfTrucks The number of trucks in the array.
 * @returns           The index of the assigned truck, or -1 if no suitable truck is found.
 */
int addShipmentToBestTruck(struct Truck* trucks, const struct Map* map, const struct Shipment* shipment, const int numOfTrucks);

/**
 * Finds the best suitable truck for a shipment from the given list of trucks.
 * The function determines the best truck based on available room, limiting factor, and least diversion.
 *
 * @param trucks      An array of trucks to consider for the shipment.
 * @param map         The map with the buildings on it.
 * @param shipment    The shipment to be assigned to a truck.
 * @param numOfTrucks The number of trucks in the array.
 * @returns           The index of the best truck, or -1 if no suitable truck is found.
 */
int findTruckForShipment(const struct Truck* trucks, const struct Map* map, const struct Shipment* shipment, const int numOfTrucks);

/**
 * Compares two trucks to determine their suitability for a shipment.
 * The function compares the trucks based on limiting factor and least diversion,
 * The comparison result indicates which truck is better suited for the shipment.
 *
 * @param left        Pointer to the left truck for comparison.
 * @param right       Pointer to the right truck for comparison.
 * @param map         The map with the buildings on it.
 * @param shipment    The shipment to be assigned to a truck.
 * @returns           A value indicating the comparison result:
 *                    - Positive value if the left truck is better suited for the shipment.
 *                    - Negative value if the right truck is better suited for the shipment.
 *                    - Zero if the trucks are considered equal.
 */
int compareTrucksForShipment(const struct Truck* left, const struct Truck* right, const struct Map* map, const struct Shipment* shipment);

/**
 * Checks if a truck has enough room to accommodate a shipment.
 * The function compares the truck's weight and volume with the shipment's weight and volume
 * to determine if there is sufficient room in the truck for the shipment.
 *
 * @param truck     The truck to check for room.
 * @param shipment  The shipment to be assigned to a truck.
 * @returns         True if the truck has enough room, false otherwise.
 */
int hasTruckRoomForShipment(const struct Truck* truck, const struct Shipment* shipment);

/**
 * Calculates the limiting factor of a truck for a given shipment.
 * The limiting factor is calculated by comparing the truck's weight or volume (whichever is larger)
 * with the corresponding weight or volume of the shipment.
 *
 * @param truck     The truck for which to calculate the limiting factor.
 * @returns         The limiting factor as a percentage.
 */
int calculateLimitingFactor(const struct Truck* truck);

/**
 * Adds a shipment to a specific truck.
 * The function subtracts the shipment's weight and volume from the truck's available weight and volume.
 *
 * @param truck     The truck to which the shipment should be added.
 * @param shipment  The shipment to be added to the truck.
 */
void addShipmentToTruck(struct Truck* truck, const struct Shipment* shipment);

/**
 * Prints the path or route information of a truck.
 * The function displays the route, destination, or any other relevant information of the truck.
 *
 * @param truck     The truck for which to print the path.
 * @param map       The map with the buildings on it.
 * @param shipment  The shipment to be added to the truck.
 */
void printTruckPath(const struct Truck* truck, const struct Map* map, const struct Shipment* shipment);
/**
 * Displays the header for the shipping application.
 */
void header();

/**
 * Displays the footer message for the shipping application.
 */
void footer();

/**
 * Prints an error message based on the given error code.
 *
 * @param errorCode The error code to determine the error type.
 */
void printErrorCode(int errorCode);

/**
 * Processes the input.
 * The function checks the shipment by validating weigth, volume and its destination.
 *
 * @param map       The map with the buildings on it.
 * @param shipment  The shipment to be added.
 * @returns         The error code 0 if valid, 1 if null, 2 if invalid destination
 *                  3 if invalid weight and 4 if invalid volume of the shipment.
 */
int processInput(const struct Shipment* shipment, const struct Map* map);

/**
 * The main function that runs the shipping application.
 * It initializes the map and trucks, takes input for shipments,
 * validates them, and assigns them to the best truck.
 * It then prints the truck path for each shipment.
 */
void run();

#endif
