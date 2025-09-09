#include "pch.h"
#include "CppUnitTest.h"
#include "mapping_r.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MSUnitTest
{
    TEST_CLASS(BLACK_BOX_TEST)
    {
    public:

      // Test case: Test with valid shipment and available trucks
    TEST_METHOD(TestAddShipmentToBestTruck_ValidShipmentAndAvailableTrucks) {
        struct Truck trucks[] = {
            { getBlueRoute(), 200, 10 },
            { getGreenRoute(), 150, 8 },
            { getYellowRoute(), 120, 6 } };
        int numOfTrucks = 3;

        struct Map map = populateMap();
        struct Shipment shipment = { { 5, 5 }, 110, 6 };

        int result = addShipmentToBestTruck(trucks, &map, &shipment, numOfTrucks);

        Assert::AreNotEqual(1, result);
    }

    // Test case: Test with an empty list of trucks
    TEST_METHOD(TestAddShipmentToBestTruck_EmptyListOfTrucks)
    {
        struct Truck* trucks = NULL;
        int numOfTrucks = 0;

        struct Map map = populateMap();
        struct Shipment shipment = { { 5, 5 }, 110, 6 };

        int result = addShipmentToBestTruck(trucks, &map, &shipment, numOfTrucks);

        Assert::AreEqual(-1, result);
    }

    // Test case: Test with a shipment that exceeds the weight capacity of all trucks
    TEST_METHOD(TestAddShipmentToBestTruck_ExceedsWeightCapacityOfAllTrucks)
    {
        struct Truck trucks[] = {
            { getBlueRoute(), 500, 30 },
            { getGreenRoute(), 400, 25 },
            { getYellowRoute(), 450, 15 }
        };
        int numOfTrucks = 3;

        struct Map map = populateMap();
        struct Shipment shipment = { { 5, 5 }, 600, 20 };

        int result = addShipmentToBestTruck(trucks, &map, &shipment, numOfTrucks);

        Assert::AreEqual(-1, result);
    }

    // Test case: Test with a shipment that exceeds the volume capacity of all trucks
    TEST_METHOD(TestAddShipmentToBestTruck_ExceedsVolumeCapacityOfAllTrucks)
    {
        struct Truck trucks[] = {
            { getBlueRoute(), 200, 20 },
            { getGreenRoute(), 180, 25 },
            { getYellowRoute(), 250, 22 }
        };
        int numOfTrucks = 3;

        struct Map map = populateMap();
        struct Shipment shipment = { { 5, 5 }, 110, 30 };

        int result = addShipmentToBestTruck(trucks, &map, &shipment, numOfTrucks);

        Assert::AreEqual(-1, result);
    }

    // Test case: Test with a destination outside the map boundaries
    TEST_METHOD(TestAddShipmentToBestTruck_DestinationOutsideMapBoundaries)
    {
        struct Truck trucks[] = {
            { getBlueRoute(), 200, 10 },
            { getGreenRoute(), 150, 8 },
            { getYellowRoute(), 120, 6 }
        };
        int numOfTrucks = 3;

        struct Map map = populateMap();
        struct Shipment shipment = { { 100, 100 }, 110, 5 };

        int result = addShipmentToBestTruck(trucks, &map, &shipment, numOfTrucks);

        Assert::AreEqual(-1, result);
    }

    // Test case: Test with a destination that has no valid route for any truck
    TEST_METHOD(TestAddShipmentToBestTruck_NoValidRouteToDestination)
    {
        struct Truck trucks[] = {
            { getBlueRoute(), 200, 10 },
            { getGreenRoute(), 150, 8 },
            { getYellowRoute(), 120, 6 }
        };
        int numOfTrucks = 3;

        struct Map map = populateMap();
        struct Shipment shipment = { { 12, 12 }, 110, 5 };

        int result = addShipmentToBestTruck(trucks, &map, &shipment, numOfTrucks);

        Assert::AreEqual(-1, result);
    }

   
    // Test case: Test with a negative number of trucks
    TEST_METHOD(TestAddShipmentToBestTruck_NegativeNumberOfTrucks)
    {
        struct Truck trucks[] = {
            { getBlueRoute(), 200, 10 },
            { getGreenRoute(), 150, 8 },
            { getYellowRoute(), 120, 6 }
        };
        int numOfTrucks = -1;

        struct Map map = populateMap();
        struct Shipment shipment = { { 5, 5 }, 110, 5 };

        int result = addShipmentToBestTruck(trucks, &map, &shipment, numOfTrucks);

        Assert::AreEqual(-1, result);
    }





    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////NEXT FUNCTION///////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////


  
    // Test case: Trucks with different limiting factor and diversions factors. General case.
    TEST_METHOD(TrucksWithDifferentLimitingFactorsAndDiversions) {
        struct Map TestMap = populateMap();
        struct Truck leftTruck = { getBlueRoute(), 100, 20 };
        struct Truck rightTruck = { getGreenRoute(), 100, 20 };
        struct Shipment shipments = { { 7, 17 }, 50, 10 };

        int result = compareTrucksForShipment(&leftTruck, &rightTruck, &TestMap, &shipments);

        Assert::IsTrue(result < 0);
    }

    // Test case: Trucks with same limiting factor and different diversions factors.
    TEST_METHOD(TrucksWithDifferentLimitingFactorsAndDiffDiversions)
    {
        struct Map TestMap = populateMap();
        struct Truck leftTruck = { getBlueRoute(), 150, 30 };
        struct Truck rightTruck = { getGreenRoute(), 150, 30 };
        struct Shipment shipments = { { 3, 16 }, 100, 5 };

        int result = compareTrucksForShipment(&leftTruck, &rightTruck, &TestMap, &shipments);

        Assert::IsTrue(result < 0);
    }

    // Test case: Trucks with same limiting factor and same diversions factors.
    TEST_METHOD(TrucksWithDifferentLimitingFactorsAndSameDiversions)
    {
        struct Map TestMap = populateMap();
        struct Truck leftTruck = { getBlueRoute(), 100, 20 };
        struct Truck rightTruck = { getBlueRoute(), 100, 20 };
        struct Shipment shipments = { { 8, 12 }, 50, 10 };

        int result = compareTrucksForShipment(&leftTruck, &rightTruck, &TestMap, &shipments);

        Assert::IsTrue(result == 0);
    }

    // Test case: Trucks with insufficient capacity.
    TEST_METHOD(TrucksWithInsufficientCapacity)
    {
        struct Map TestMap = populateMap();
        struct Truck leftTruck = { getBlueRoute(), 100, 30 };
        struct Truck rightTruck = { getGreenRoute(), 100, 30 };
        struct Shipment shipments = { { 8, 12 }, 101, 10 };

        int result = compareTrucksForShipment(&leftTruck, &rightTruck, &TestMap, &shipments);

        Assert::IsTrue(result == 0);
    }
    

    // Test case: Verify if the function handles the scenario when the list of trucks is empty.
    TEST_METHOD(FindTruckForShipment_EmptyTrucksList) {
        int numOfTrucks = 0;
        struct Truck trucks[1] = { { getBlueRoute(), 0, 0 } };

        struct Map map = populateMap();
        struct Shipment shipment = { { 5, 5 }, 100, 5 };

        int result = findTruckForShipment(trucks, &map, &shipment, numOfTrucks);

        Assert::AreEqual(-1, result);
    }

    // Test case: Verify if the function correctly assigns the shipment to the only truck when it has sufficient capacity.
    TEST_METHOD(FindTruckForShipment_SingleTruckWithSufficientCapacity)
    {
        int numOfTrucks = 1;
        struct Truck trucks[1] = { { getBlueRoute(), 200, 10 } };

        struct Map map = populateMap();
        struct Shipment shipment = { { 5, 5 }, 100, 5 };

        int result = findTruckForShipment(trucks, &map, &shipment, numOfTrucks);

        Assert::AreEqual(0, result);
    }

    // Test case: Verify if the function correctly handles the case when the only truck does not have enough capacity for the shipment.
    TEST_METHOD(FindTruckForShipment_SingleTruckWithInsufficientCapacity)
    {
        int numOfTrucks = 1;
        struct Truck trucks[1] = { { getBlueRoute(), 100, 5 } };

        struct Map map = populateMap();
        struct Shipment shipment = { { 5, 5 }, 150, 5 };

        int result = findTruckForShipment(trucks, &map, &shipment, numOfTrucks);

        Assert::AreEqual(-1, result);
    }

    // Test case: Verify if the function selects the best suitable truck from a list of trucks with different capacities.
    TEST_METHOD(FindTruckForShipment_MultipleTrucksWithDifferentCapacities)
    {
        int numOfTrucks = 3;
        struct Truck trucks[3] = {
            { getBlueRoute(), 100, 5 },
            { getGreenRoute(), 200, 10 },
            { getBlueRoute(), 150, 7 }
        };

        struct Map map = populateMap();
        struct Shipment shipment = { { 5, 5 }, 200, 10 };

        int result = findTruckForShipment(trucks, &map, &shipment, numOfTrucks);

        Assert::AreEqual(1, result);
    }

  
   

    // Test case: Test if the function correctly handles the case when the shipment has zero weight and volume.
    TEST_METHOD(FindTruckForShipment_ShipmentWithZeroWeightAndVolume)
    {
        int numOfTrucks = 2;
        struct Truck trucks[2] = {
            { getBlueRoute(), 100, 5 },
            { getGreenRoute(), 200, 10 }
        };

        struct Map map = populateMap();
        struct Shipment shipment = { { 5, 5 }, 0, 0 };

        int result = findTruckForShipment(trucks, &map, &shipment, numOfTrucks);

        Assert::IsTrue(result == 0 || result == 1);
    }

    // Test case: Test if the function correctly handles the case when all trucks have insufficient capacity for the shipment.
    TEST_METHOD(FindTruckForShipment_AllTrucksWithInsufficientCapacity)
    {
        int numOfTrucks = 3;
        struct Truck trucks[3] = {
            { getBlueRoute(), 50, 2 },
            { getGreenRoute(), 80, 4 },
            { getBlueRoute(), 70, 3 }
        };

        struct Map map = populateMap();
        struct Shipment shipment = { { 3, 3 }, 100, 5 };

        int result = findTruckForShipment(trucks, &map, &shipment, numOfTrucks);

        Assert::AreEqual(-1, result);
    }
    /////////////////////////////////////////////////////
  ///////////////////  NEXT FUNCTION////////////////////////////////
    

    // Test case: Empty truck and empty shipment
    TEST_METHOD(TestHasTruckRoomForShipment_EmptyTruckAndEmptyShipment) {
        struct Truck truck = { 0 };
        struct Shipment shipment = { 0 };
        Assert::IsTrue(hasTruckRoomForShipment(&truck, &shipment));
    }

    // Test case: Empty truck and non-empty shipment
    TEST_METHOD(TestHasTruckRoomForShipment_EmptyTruckAndNonEmptyShipment)
    {
        struct Truck truck = { { 0 }, 500, 10 };
        struct Shipment shipment = { { 5, 5 }, 500, 10 };
        Assert::IsTrue(hasTruckRoomForShipment(&truck, &shipment));
    }

   

    // Test case: Truck weight limit exceeded
    TEST_METHOD(TestHasTruckRoomForShipment_TruckWeightLimitExceeded)
    {
        struct Truck truck = { { 0 }, 500, 30 };
        struct Shipment shipment = { { 5, 5 }, 600, 20 };
        Assert::IsFalse(hasTruckRoomForShipment(&truck, &shipment));
    }

    // Test case: Truck capacity not exceeded
    TEST_METHOD(TestHasTruckRoomForShipment_TruckCapacityNotExceeded)
    {
        struct Truck truck = { { 0 }, 1000, 20 };
        struct Shipment shipment = { { 5, 5 }, 500, 10 };
        Assert::IsTrue(hasTruckRoomForShipment(&truck, &shipment));
    }

   

    // Test case: Truck volume limit exceeded
    TEST_METHOD(TestHasTruckRoomForShipment_TruckVolumeLimitExceeded)
    {
        struct Truck truck = { { 0 }, 1000, 10 };
        struct Shipment shipment = { { 5, 5 }, 800, 15 };
        Assert::IsFalse(hasTruckRoomForShipment(&truck, &shipment));
    }

    // Test case: Negative values
    TEST_METHOD(TestHasTruckRoomForShipment_NegativeValues)
    {
        struct Truck truck = { { 0 }, -500, -10 };
        struct Shipment shipment = { { 5, 5 }, -200, -5 };
        Assert::IsFalse(hasTruckRoomForShipment(&truck, &shipment));
    }

    TEST_METHOD(CalculateLimitingFactor_ZeroTruckWeightAndVolume) {
        struct Truck truck = { { 0 }, 0, 0 };

        int result = calculateLimitingFactor(&truck);

        Assert::AreEqual(0, result);
    }
   
    };



    TEST_CLASS(WHITE_BOX_TEST)
    {
    public:
        TEST_METHOD(TestAddShipmentToBestTruck_ExceedsWeightCapacityOfAllTrucks) {
            struct Map map = populateMap();
            struct Shipment shipment = { { 5, 5 }, 600, 20 };
            struct Truck trucks[] = {
                { getBlueRoute(), 500, 30 },
                { getGreenRoute(), 450, 15 },
                { getYellowRoute(), 420, 25 }
            };
            int numOfTrucks = 3;

            int result = addShipmentToBestTruck(trucks, &map, &shipment, numOfTrucks);

            Assert::AreEqual(-1, result);
        }
       
        TEST_METHOD(TestAddShipmentToBestTruck_ExceedsVolumeCapacityOfAllTrucks)
        {
            struct Map map = populateMap();
            struct Shipment shipment = { { 5, 5 }, 130, 30 };
            struct Truck trucks[] = {
                { getBlueRoute(), 200, 20 },
                { getGreenRoute(), 250, 22 },
                { getYellowRoute(), 120, 25 }
            };
            int numOfTrucks = 3;

            int result = addShipmentToBestTruck(trucks, &map, &shipment, numOfTrucks);

            Assert::AreEqual(-1, result);
        }
        TEST_METHOD(TestAddShipmentToBestTruck_EmptyTruck)
        {
            struct Map map = populateMap();
            struct Shipment shipment = { { 5, 5 }, 120, 5 };
            struct Truck truck = { getBlueRoute(), 0, 0 };

            int result = addShipmentToBestTruck(&truck, &map, &shipment, 1);

            Assert::AreEqual(-1, result);
        }

        
        TEST_METHOD(TestAddShipmentToBestTruck_MaxWeightAndVolumeCapacity)
        {
            struct Map map = populateMap();
            struct Shipment shipment = { { 5, 5 }, MAX_WEIGHT_IN_KGS, MAX_VOLUME_IN_CU_M };
            struct Truck trucks[] = {
                { getBlueRoute(), MAX_WEIGHT_IN_KGS, MAX_VOLUME_IN_CU_M },
                { getGreenRoute(), 800, 20 },
                { getYellowRoute(), 750, 30 }
            };
            int numOfTrucks = 3;

            int result = addShipmentToBestTruck(trucks, &map, &shipment, numOfTrucks);

            Assert::AreEqual(0, result);
        }

       
        TEST_METHOD(TestAddShipmentToBestTruck_NullPointers)
        {
            struct Map map = populateMap();
            struct Shipment shipment = { { 5, 5 }, 175, 3 };
            struct Truck trucks[] = {
                { getBlueRoute(), 200, 10 },
                { getGreenRoute(), 120, 6 },
                { getYellowRoute(), 140, 8 }
            };
            int numOfTrucks = 3;

            int result1 = addShipmentToBestTruck(NULL, &map, &shipment, numOfTrucks);
            int result2 = addShipmentToBestTruck(trucks, NULL, &shipment, numOfTrucks);
            int result3 = addShipmentToBestTruck(trucks, &map, NULL, numOfTrucks);

            Assert::AreEqual(-1, result1);
            Assert::AreEqual(-1, result2);
            Assert::AreEqual(-1, result3);
        }

        TEST_METHOD(TestAddShipmentToBestTruck_NegativeNumberOfTrucks)
        {
            struct Map map = populateMap();
            struct Shipment shipment = { { 5, 5 }, 142, 3 };
            struct Truck trucks[] = {
                { getBlueRoute(), 200, 10 },
                { getGreenRoute(), 150, 8 },
                { getYellowRoute(), 120, 6 }
            };
            int numOfTrucks = -1;

            int result = addShipmentToBestTruck(trucks, &map, &shipment, numOfTrucks);

            Assert::AreEqual(-1, result);
        }
        ////////////////////////////////////////////////////////////
        //////////////////next function
        //////////////////////////////////////////////////
        TEST_METHOD(FindTruckForShipment_EmptyTrucksList) {
            int numOfTrucks = 0;
            struct Truck trucks[1] = { { getBlueRoute(), 0, 0 } };

            struct Map map = populateMap();
            struct Shipment shipment = { { 5, 5 }, 200, 10 };

            int result = findTruckForShipment(trucks, &map, &shipment, numOfTrucks);

            Assert::AreEqual(-1, result);
        }

        // Test case: Correct Assignment of Shipment to a Single Truck
        TEST_METHOD(FindTruckForShipment_SingleTruckWithSufficientCapacity)
        {
            int numOfTrucks = 1;
            struct Truck trucks[1] = { { getBlueRoute(), 400, 20 } };

            struct Map map = populateMap();
            struct Shipment shipment = { { 5, 5 }, 200, 10 };

            int result = findTruckForShipment(trucks, &map, &shipment, numOfTrucks);

            Assert::AreEqual(0, result);
        }

        // Test case: Correct Selection of Best Suitable Truck with Different Capacities
        TEST_METHOD(FindTruckForShipment_MultipleTrucksWithDifferentCapacities)
        {
            int numOfTrucks = 3;
            struct Truck trucks[3] = {
                { getBlueRoute(), 100, 5 },
                { getGreenRoute(), 400, 10 },
                { getBlueRoute(), 150, 7 }
            };

            struct Map map = populateMap();
            struct Shipment shipment = { { 5, 5 }, 400, 10 };

            int result = findTruckForShipment(trucks, &map, &shipment, numOfTrucks);

            Assert::AreEqual(1, result);
        }

        // Test case: Correct Selection of Best Suitable Truck with Equal Capacities
        TEST_METHOD(FindTruckForShipment_MultipleTrucksWithEqualCapacities)
        {
            int numOfTrucks = 2;
            struct Truck trucks[2] = {
                { getBlueRoute(), 100, 5 },
                { getBlueRoute(), 100, 5 }
            };

            struct Map map = populateMap();
            struct Shipment shipment = { { 5, 5 }, 100, 5 };

            int result = findTruckForShipment(trucks, &map, &shipment, numOfTrucks);

            Assert::IsTrue(result == 0 || result == 1);
        }
        TEST_METHOD(HasTruckRoomForShipment_ValidInput_ReturnsTrue) {
            struct Map map = populateMap();
            struct Shipment shipment1 = { { 5, 5 }, 100, 5 };
            struct Truck truck1 = { { 0 }, 200, 10 };

            bool result = hasTruckRoomForShipment(&truck1, &shipment1);

            Assert::IsTrue(result);
        }

       //exact values
        TEST_METHOD(HasTruckRoomForShipment_ExactWeightAndVolume_ReturnsTrue)
        {
            struct Map map = populateMap();
            struct Shipment shipment2 = { { 10, 10 }, 100, 5 };
            struct Truck truck2 = { { 0 }, 100, 5 };

            bool result = hasTruckRoomForShipment(&truck2, &shipment2);

            Assert::IsTrue(result);
        }

        // Test case: Truck does not have enough weight capacity
        TEST_METHOD(HasTruckRoomForShipment_InsufficientWeight_ReturnsFalse)
        {
            struct Map map = populateMap();
            struct Shipment shipment3 = { { 3, 3 }, 100, 5 };
            struct Truck truck3 = { { 0 }, 50, 10 };

            bool result = hasTruckRoomForShipment(&truck3, &shipment3);

            Assert::IsFalse(result);
        }

        // Test case : Truck does not have enough volume capacity
        TEST_METHOD(HasTruckRoomForShipment_InsufficientVolume_ReturnsFalse)
        {
            struct Map map = populateMap();
            struct Shipment shipment4 = { { 7, 7 }, 100, 5 };
            struct Truck truck4 = { { 0 }, 100, 2 };

            bool result = hasTruckRoomForShipment(&truck4, &shipment4);

            Assert::IsFalse(result);
        }

        // Test case : Invalid input (NULL truck)
        TEST_METHOD(HasTruckRoomForShipment_NullTruck_ReturnsFalse)
        {
            struct Map map = populateMap();
            struct Shipment shipment5 = { { 5, 5 }, 100, 5 };

            bool result = hasTruckRoomForShipment(nullptr, &shipment5);

            Assert::IsFalse(result);
        }

        // Test case : Invalid input (NULL shipment)
        TEST_METHOD(HasTruckRoomForShipment_NullShipment_ReturnsFalse)
        {
            struct Map map = populateMap();
            struct Truck truck6 = { { 0 }, 200, 10 };

            bool result = hasTruckRoomForShipment(&truck6, nullptr);

            Assert::IsFalse(result);
        }

        TEST_METHOD(CalculateLimitingFactor_ZeroTruckWeightAndVolume) {
            struct Truck truck = { { 0 }, 0, 0 };

            int result = calculateLimitingFactor(&truck);

            Assert::AreEqual(0, result);
        }

      

        TEST_METHOD(AnyOfInputPointerIsNull) {
            struct Map TestMap = populateMap();
            struct Truck* leftTruck = NULL;
            struct Truck rightTruck = { getGreenRoute(), 100, 20 };
            struct Shipment shipments = { { 7, 17 }, 50, 10 };

            int result = compareTrucksForShipment(leftTruck, &rightTruck, &TestMap, &shipments);

            Assert::AreEqual(0, result);
        }

        // Test case: Trucks with same diversion and different limiting factor.
        TEST_METHOD(TrucksWithSameDiversionAndDifferentLimitingFactor) {
            struct Map TestMap = populateMap();
            struct Truck leftTruck = { getBlueRoute(), 500, 25 };
            struct Truck rightTruck = { getGreenRoute(), 600, 27 };
            struct Shipment shipments = { { 8, 12 }, 50, 10 };

            int result = compareTrucksForShipment(&leftTruck, &rightTruck, &TestMap, &shipments);

            Assert::AreEqual(1, result);
        }

       
    };
    TEST_CLASS(USERACCEPTANCETests)
    {
    public:
        // Test case: Null shipment
        TEST_METHOD(TestNullShipment)
        {
            struct Shipment* shipment = NULL;
            struct Map map = populateMap();

            int errorCode = processInput(shipment, &map);

            Assert::AreEqual(1, errorCode);
        }

        // Test case: Invalid destination
        TEST_METHOD(TestInvalidDestination)
        {
            struct Shipment shipment = { { 50, 10 }, 50, 0.5 };
            struct Map map = populateMap();

            int errorCode = processInput(&shipment, &map);

            Assert::AreEqual(2, errorCode);
        }

        // Test case: No possible moves
        TEST_METHOD(TestNoPossibleMoves)
        {
            struct Shipment shipment = { { 12, 12 }, 50, 0.5 };
            struct Map map = populateMap();

            int errorCode = processInput(&shipment, &map);

            Assert::AreEqual(2, errorCode);
        }

        // Test case: Invalid weight
        TEST_METHOD(TestInvalidWeight)
        {
            struct Shipment shipment = { { 1, 1 }, 0, 0.5 };
            struct Map map = populateMap();

            int errorCode = processInput(&shipment, &map);

            Assert::AreEqual(3, errorCode);
        }

        // Test case: Invalid volume
        TEST_METHOD(TestInvalidVolume)
        {
            struct Shipment shipment = { { 1, 1 }, 50, 2.0 };
            struct Map map = populateMap();

            int errorCode = processInput(&shipment, &map);

            Assert::AreEqual(4, errorCode);
        }

        // Test case: Valid input
        TEST_METHOD(TestValidInput)
        {
            struct Shipment shipment = { { 1, 1 }, 50, 0.5 };
            struct Map map = populateMap();

            int errorCode = processInput(&shipment, &map);

            Assert::AreEqual(0, errorCode);
        }
    };

    TEST_CLASS(INTEGRATION_TESTS) {
    public:
        TEST_METHOD(integratedShipmentFunctions) {
            struct Map map = populateMap();
            struct Shipment shipment = { { 5, 5 }, 200, 10 };
            struct Truck trucks[] = {
                { getBlueRoute(), MAX_WEIGHT_IN_KGS, MAX_VOLUME_IN_CU_M },
                { getGreenRoute(), 800, 20 },
                { getYellowRoute(), 750, 30 }
            };
            int numOfTrucks = 3;

            int result = addShipmentToBestTruck(trucks, &map, &shipment, numOfTrucks);
            int result2 = findTruckForShipment(trucks, &map, &shipment, numOfTrucks);

            Assert::AreEqual(1, result + result2);
        }

           TEST_METHOD(integratedHasRoomAndAddShipmentFunctions) {
            struct Shipment shipment = { { 3, 3 }, 100, 8 };
            struct Truck truck = { getBlueRoute(), 200, 15 };

            int hasRoom = hasTruckRoomForShipment(&truck, &shipment);

            addShipmentToTruck(&truck, &shipment);
            int hasRoomAfter = hasTruckRoomForShipment(&truck, &shipment);

            Assert::IsTrue(hasRoom);
            Assert::IsFalse(hasRoomAfter);
        }

        TEST_METHOD(integratedCompareAndHasRoomFunctions)
        {
            struct Map map = populateMap();
            struct Shipment shipment = { { 5, 5 }, 200, 10 };
            struct Truck trucks[] = {
                { getBlueRoute(), 300, 20 },
                { getGreenRoute(), 850, 5 },
                { getYellowRoute(), 300, 15 }
            };

            // Check if trucks have enough room for the shipment
            int hasRoom1 = hasTruckRoomForShipment(&trucks[0], &shipment);
            int hasRoom2 = hasTruckRoomForShipment(&trucks[1], &shipment);
            int hasRoom3 = hasTruckRoomForShipment(&trucks[2], &shipment);

            // Compare trucks for shipment suitability
            int compareResult1 = compareTrucksForShipment(&trucks[0], &trucks[1], &map, &shipment);
            int compareResult2 = compareTrucksForShipment(&trucks[1], &trucks[2], &map, &shipment);

            // Check expected outcomes
            Assert::IsTrue(hasRoom1);
            Assert::IsFalse(hasRoom2);
            Assert::IsTrue(hasRoom3);

            Assert::AreEqual(1, compareResult1);
            Assert::AreEqual(1, compareResult2);
        }

       

    };
   
    }
    
