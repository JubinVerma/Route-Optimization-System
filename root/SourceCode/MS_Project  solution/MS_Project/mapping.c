#define _CRT_SECURE_NO_WARNINGS

#include "mapping.h"

#include <math.h>
#include <stdio.h>

struct Map populateMap()
{
    struct Map result = {
        // 0	1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
        // A B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y
        {
            { 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // 0
            { 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0 }, // 1
            { 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0 }, // 2
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // 3
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // 4
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // 5
            { 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0 }, // 6
            { 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1 }, // 7
            { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1 }, // 8
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // 9
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // 10
            { 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1 }, // 11
            { 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1 }, // 12
            { 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1 }, // 13
            { 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1 }, // 14
            { 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1 }, // 15
            { 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // 16
            { 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // 17
            { 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, // 18
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // 19
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // 20
            { 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0 }, // 21
            { 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 }, // 22
            { 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1 }, // 23
            { 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } // 24
        },
        MAP_ROWS, MAP_COLS
    };
    return result;
}

int getNumRows(const struct Map* map)
{
    return map->numRows;
}

int getNumCols(const struct Map* map)
{
    return map->numCols;
}

void printSymColor(const char sym)
{
    switch (sym) {
    case 'X':
        printf(COLOR_BUILDING);
        break;
    case 'B':
        printf(COLOR_BLUE_ROUTE);
        break;
    case 'G':
        printf(COLOR_GREEN_ROUTE);
        break;
    case 'Y':
        printf(COLOR_YELLOW_ROUTE);
        break;
    case 'P':
        printf(COLOR_SHORTEST_PATH);
        break;
    case '.':
    case '-':
    case '*':
    case '+':
        printf(COLOR_OVERLAP);
        break;
    }

    printf("%c" COLOR_RESET, sym);
}

void printMap(const struct Map* map, const int base1, const int alphaCols)
{
    //              01234567890123456
    //              1248F
    char sym[] = { " XB?G?.?Y?-?*?+?P" };
    int r, c, rowMax;

    rowMax = map->numRows + base1;

    printf("%4s", " ");
    for (c = 0; c < map->numCols; c++) {
        if (alphaCols)
            printf("%c", 'A' + c);
        else
            printf("%d", c % 10);
    }
    printf("\n");
    printf("%4s", " ");
    for (c = 0; c < map->numCols; c++) {
        printf("-");
    }
    printf("\n");

    for (r = base1; r < rowMax; r++) {
        printf("%3d|", r);
        for (c = 0; c < map->numCols; c++) {
            printSymColor(sym[map->squares[r - base1][c]]);
        }
        printf("\n");
    }
}
struct Route getBlueRoute()
{
    struct Route result = {
        {
            { 0, 0 },
            { 1, 0 },
            { 2, 0 },
            { 3, 0 },
            { 4, 0 },
            { 4, 1 },
            { 4, 2 },
            { 4, 3 },
            { 4, 4 },
            { 4, 5 },
            { 4, 6 },
            { 4, 7 },
            { 4, 8 },
            { 4, 9 },
            { 5, 9 },
            { 6, 9 },
            { 7, 9 },
            { 8, 9 },
            { 9, 9 },
            { 10, 9 },
            { 10, 10 },
            { 11, 10 },
            { 12, 10 },
            { 13, 10 },
            { 14, 10 },
            { 15, 10 },
            { 16, 10 },
            { 17, 10 },
            { 17, 11 },
            { 17, 12 },
            { 17, 13 },
            { 17, 14 },
            { 17, 15 },
            { 17, 16 },
            { 17, 17 },
            { 17, 18 },
            { 17, 19 },
            { 17, 20 },
            { 17, 21 },
            { 17, 22 },
            { 17, 23 },
            { 17, 24 },
        },
        42, BLUE
    };
    return result;
}

struct Route getGreenRoute()
{
    struct Route result = {
        { { 0, 0 },
            { 1, 0 },
            { 2, 0 },
            { 3, 0 },
            { 4, 0 }, { 4, 1 }, { 4, 2 }, { 4, 3 }, { 4, 4 }, { 4, 5 }, { 4, 6 }, { 4, 7 }, { 4, 8 }, { 4, 9 }, { 4, 10 }, { 4, 11 },
            { 3, 11 },
            { 2, 11 },
            { 1, 11 },
            { 0, 11 }, { 0, 12 }, { 0, 13 }, { 0, 14 }, { 0, 15 }, { 0, 16 }, { 0, 17 }, { 0, 18 }, { 0, 19 },
            { 1, 19 },
            { 2, 19 },
            { 3, 19 },
            { 4, 19 },
            { 5, 19 },
            { 6, 19 },
            { 7, 19 },
            { 8, 19 },
            { 9, 19 }, { 9, 20 }, { 9, 21 }, { 9, 22 }, { 9, 23 }, { 9, 24 }

        },
        42, GREEN
    };
    return result;
}

struct Route getYellowRoute()
{
    struct Route result = {
        { { 0, 0 },
            { 1, 0 },
            { 2, 0 },
            { 3, 0 },
            { 4, 0 }, { 4, 1 }, { 4, 2 }, { 4, 3 },
            { 5, 3 },
            { 6, 3 },
            { 7, 3 },
            { 8, 3 },
            { 9, 3 }, { 9, 2 }, { 9, 1 },
            { 10, 1 },
            { 11, 1 },
            { 12, 1 },
            { 13, 1 },
            { 14, 1 },
            { 15, 1 },
            { 16, 1 },
            { 17, 1 },
            { 18, 1 },
            { 19, 1 }, { 19, 2 }, { 19, 3 }, { 19, 4 }, { 19, 5 }, { 19, 6 }, { 19, 7 }, { 19, 8 }, { 19, 9 }, { 19, 10 }, { 19, 11 }, { 19, 12 },
            { 19, 13 }, { 19, 14 }, { 19, 15 }, { 19, 16 }, { 19, 17 }, { 19, 18 }, { 19, 19 }, { 19, 20 }, { 19, 21 }, { 19, 22 }, { 19, 23 }, { 19, 24 } },
        48, YELLOW
    };
    return result;
}
struct Map addRoute(const struct Map* map, const struct Route* route)
{
    int r, c;
    struct Map result = { { 0 }, 0, 0 };

    for (r = 0; r < map->numRows; r++) {
        for (c = 0; c < map->numCols; c++) {
            result.squares[r][c] = map->squares[r][c];
        }
    }
    result.numRows = map->numRows;
    result.numCols = map->numCols;

    for (r = 0; r < route->numPoints; r++) {
        result.squares[route->points[r].row][route->points[r].col] += route->routeSymbol;
    }

    return result;
}

void addPtToRoute(struct Route* route, struct Point pt)
{
    route->points[route->numPoints++] = pt;
}

void addPointToRoute(struct Route* route, const int row, const int col)
{
    struct Point pt = { row, col };
    addPtToRoute(route, pt);
}

void addPointToRouteIfNot(struct Route* route, const int row, const int col, const struct Point notThis)
{
    struct Point pt = { row, col };
    if (notThis.row != row || notThis.col != col)
        addPtToRoute(route, pt);
}

double distance(const struct Point* p1, const struct Point* p2)
{
    int deltaRow = p2->row - p1->row;
    int deltaCol = p2->col - p1->col;

    return sqrt((double)(deltaRow * deltaRow + deltaCol * deltaCol));
}

struct Route shortestPath(const struct Map* map, const struct Point start, const struct Point dest)
{
    struct Route result = { { 0 }, 0, DIVERSION };
    struct Point last = { -1, -1 };
    struct Point current = start;
    struct Route possible = { { 0 }, 0, 0 };
    int minDistance = !!map->squares[dest.row][dest.col];
    int close = 0;

    while (distance(&current, &dest) > minDistance && close >= 0 && result.numPoints < MAX_ROUTE) {
        possible = getPossibleMoves(map, current, last);
        close = getClosestPoint(&possible, dest);
        if (close >= 0) {
            last = current;
            current = possible.points[close];
            addPtToRoute(&result, current);
        }
    }

    return result;
}

struct Route getPossibleMoves(const struct Map* map, const struct Point p1, const struct Point backpath)
{
    struct Route result = { { 0 }, 0, DIVERSION };

    if (p1.row > 0) {
        if (map->squares[p1.row - 1][p1.col] != 1)
            addPointToRouteIfNot(&result, p1.row - 1, p1.col, backpath); // square above
        if (p1.col > 0 && map->squares[p1.row - 1][p1.col - 1] != 1)
            addPointToRouteIfNot(&result, p1.row - 1, p1.col - 1, backpath); // top left
        if (p1.col < (map->numCols - 1) && map->squares[p1.row - 1][p1.col + 1] != 1)
            addPointToRouteIfNot(&result, p1.row - 1, p1.col + 1, backpath); // top right
    }
    if (p1.col > 0 && map->squares[p1.row][p1.col - 1] != 1)
        addPointToRouteIfNot(&result, p1.row, p1.col - 1, backpath); // left
    if (p1.col < (map->numCols - 1) && map->squares[p1.row][p1.col + 1] != 1)
        addPointToRouteIfNot(&result, p1.row, p1.col + 1, backpath); // right
    if (p1.row < (map->numRows - 1)) {
        if (map->squares[p1.row + 1][p1.col] != 1)
            addPointToRouteIfNot(&result, p1.row + 1, p1.col, backpath); // square below
        if (p1.col > 0 && map->squares[p1.row + 1][p1.col - 1] != 1)
            addPointToRouteIfNot(&result, p1.row + 1, p1.col - 1, backpath); // bot left
        if (p1.col < (map->numCols - 1) && map->squares[p1.row + 1][p1.col + 1] != 1)
            addPointToRouteIfNot(&result, p1.row + 1, p1.col + 1, backpath); // top right
    }

    return result;
}

int getClosestPoint(const struct Route* route, const struct Point pt)
{
    int i, closestIdx = -1;
    double closestDist = 999999.9, dist;

    for (i = 0; i < route->numPoints; i++) {
        dist = distance(&pt, &route->points[i]);
        if (dist < closestDist) {
            closestDist = dist;
            closestIdx = i;
        }
    }
    return closestIdx;
}

int eqPt(const struct Point p1, const struct Point p2)
{
    return p1.row == p2.row && p1.col == p2.col;
}
int addShipmentToBestTruck(struct Truck* trucks, const struct Map* map, const struct Shipment* shipment, const int numOfTrucks)
{
    if (!trucks || !map || !shipment || numOfTrucks < 1)
        return -1;

    int bestTruckIndex = findTruckForShipment(trucks, map, shipment, numOfTrucks);

    if (bestTruckIndex >= 0)
        addShipmentToTruck(&trucks[bestTruckIndex], shipment);

    return bestTruckIndex;
}

int findTruckForShipment(const struct Truck* trucks, const struct Map* map, const struct Shipment* shipment, const int numOfTrucks)
{
    if (!trucks || !map || !shipment || numOfTrucks < 1)
        return -1;

    struct Point orgin = { 0, 0 };
    struct Route route = getPossibleMoves(map, shipment->destination, orgin);

    if (!route.numPoints)
        return -1;

    if (shipment->destination.row > map->numRows || shipment->destination.col > map->numCols)
        return -1;

    int bestTruckIndex = -1;

    for (int i = 0; i < numOfTrucks; i++) {
        if (!hasTruckRoomForShipment(&trucks[i], shipment))
            continue;

        if (bestTruckIndex < 0)
            bestTruckIndex = i;

        int best = compareTrucksForShipment(&trucks[i], &trucks[bestTruckIndex], map, shipment);
        if (best > 0)
            bestTruckIndex = i;
    }

    return bestTruckIndex;
}

int hasTruckRoomForShipment(const struct Truck* truck, const struct Shipment* shipment)
{
    if (!truck || !shipment)
        return 0;

    return (truck->weightInKGs >= shipment->weightInKGs) && (truck->volumeInCuMs >= shipment->volumeInCuMs);
}

int compareTrucksForShipment(const struct Truck* left, const struct Truck* right, const struct Map* map, const struct Shipment* shipment)
{
    if (!left || !right || !map || !shipment)
        return 0;

    if (!hasTruckRoomForShipment(left, shipment) && !hasTruckRoomForShipment(right, shipment))
        return 0;

    struct Point leftClosest = left->route.points[getClosestPoint(&left->route, shipment->destination)];
    struct Point rightClosest = right->route.points[getClosestPoint(&right->route, shipment->destination)];
    struct Route leftDiversion = shortestPath(map, leftClosest, shipment->destination);
    struct Route rightDiversion = shortestPath(map, rightClosest, shipment->destination);
    int leftLimitingFactor = calculateLimitingFactor(left);
    int rightLimitingFactor = calculateLimitingFactor(right);

    if (leftDiversion.numPoints == rightDiversion.numPoints) {
        if (leftLimitingFactor > rightLimitingFactor)
            return 1;
        if (leftLimitingFactor < rightLimitingFactor)
            return -1;
        else
            return 0;
    }

    if (leftDiversion.numPoints < rightDiversion.numPoints)
        return 1;
    else
        return -1;

    return 0;
}

int calculateLimitingFactor(const struct Truck* truck)
{
    if (!truck)
        return 0;

    int weightFactor = (truck->weightInKGs * 100) / MAX_WEIGHT_IN_KGS;
    int volumeFactor = (truck->volumeInCuMs * 100) / MAX_VOLUME_IN_CU_M;

    return (weightFactor > volumeFactor) ? weightFactor : volumeFactor;
}

void addShipmentToTruck(struct Truck* truck, const struct Shipment* shipment)
{
    if (!truck || !shipment)
        return;

    if (hasTruckRoomForShipment(truck, shipment)) {
        truck->weightInKGs -= shipment->weightInKGs;
        truck->volumeInCuMs -= shipment->volumeInCuMs;
    }
}

void printTruckPath(const struct Truck* truck, const struct Map* map, const struct Shipment* shipment)
{
    printf("Ship on ");

    switch (truck->route.routeSymbol) {
    case 2:
        printf("BLUE");
        break;
    case 4:
        printf("GREEN");
        break;
    case 8:
        printf("YELLOW");
        break;
    }

    printf(" LINE, ");

    int closestPoint = getClosestPoint(&truck->route, shipment->destination);
    struct Route diversion = shortestPath(map, truck->route.points[closestPoint], shipment->destination);

    if (!diversion.numPoints) {
        printf("no diversion\n");
        return;
    }

    printf("divert: ");

    for (int i = 0; i < diversion.numPoints; i++) {
        printf("%d%c", diversion.points[i].row + 1, diversion.points[i].col + 'A');
        if (i != diversion.numPoints - 1)
            printf(", ");
    }

    putchar('\n');
}
void header()
{
    printf("=================\n"
        "Seneca Deliveries\n"
        "=================\n");
}

void footer()
{
    printf("Thanks for shipping with Seneca!\n");
}

void printErrorCode(int errorCode)
{
    switch (errorCode) {
    case 2:
        printf("Invalid destination\n");
        break;
    case 3:
        printf("Invalid weight (must be 1-2000 Kg.)\n");
        break;
    case 4:
        printf("Invalid size\n");
    }
}

int processInput(const struct Shipment* shipment, const struct Map* map)
{
    if (!shipment)
        return 1;

    if (shipment->destination.row > map->numRows || shipment->destination.col > map->numCols)
        return 2;

    struct Point origin = { 0, 0 };
    struct Route route = getPossibleMoves(map, shipment->destination, origin);

    if (!route.numPoints)
        return 2;

    if (shipment->weightInKGs < 3 || shipment->weightInKGs > MAX_WEIGHT_IN_KGS)
        return 3;

    if (shipment->volumeInCuMs != 0.25 && shipment->volumeInCuMs != 0.50 && shipment->volumeInCuMs != 1.00)
        return 4;

    return 0;
}


void run()
{
    struct Map map = populateMap();
    struct Truck trucks[] = {
        { getBlueRoute(), MAX_WEIGHT_IN_KGS, MAX_VOLUME_IN_CU_M },
        { getGreenRoute(), MAX_WEIGHT_IN_KGS, MAX_VOLUME_IN_CU_M },
        { getYellowRoute(), MAX_WEIGHT_IN_KGS, MAX_VOLUME_IN_CU_M },
    };

    double shipmentWeight = 0;
    double shipmentVolume = 0;
    struct Point destination = { 0, 0 };

    header();

    while (1) {
        printf("Enter shipment weight, box size and destination (0 0 x to stop): ");
        scanf("%lf %lf", &shipmentWeight, &shipmentVolume);

        if (!shipmentWeight && !shipmentVolume)
            break;

        scanf(" %d%c%*c", (int*)&destination.row, &destination.col);

        const struct Shipment currentShipment = {
            { destination.row - 1, destination.col - 'A' },
            shipmentWeight,
            shipmentVolume
        };

        int errorCode = processInput(&currentShipment, &map);

        if (errorCode) {
            printErrorCode(errorCode);
            continue;
        }

        int truckIndex = addShipmentToBestTruck(trucks, &map, &currentShipment, 3);

        printTruckPath(&trucks[truckIndex], &map, &currentShipment);
    }

    footer();
}