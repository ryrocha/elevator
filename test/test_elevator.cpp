#include <catch2/catch_test_macros.hpp>
#include <elevator/elevator_controller.h>
#include <vector>
#include <iostream>

TEST_CASE("Normal elevator operations", "[nominal]") {
    std::vector<int> floors = {12, 2, 9, 1, 32};
    ElevatorController controller;
    RESULT result = controller.add_floors(floors);
    REQUIRE(result.travel_time == 560);
    REQUIRE(result.floors_visited == floors);
};

TEST_CASE("Repeated consecutive floors given", "[repeated]") {
    std::vector<int> floors = {12, 12, 2, 9, 9, 9, 1, 32, 32};
    ElevatorController controller;
    RESULT result = controller.add_floors(floors);
    REQUIRE(result.travel_time == 560);
    std::vector<int> floors_visited = {12, 2, 9, 1, 32};
    REQUIRE(result.floors_visited == floors_visited);
};

TEST_CASE("Modified floor travel time", "[floor_time]") {
    std::vector<int> floors = {12, 2, 9, 1, 32};
    double floor_time = 8.6;
    ElevatorController controller;
    RESULT result = controller.add_floors(floors, floor_time);
    int travel_time_comp = result.travel_time - 481.6;
    REQUIRE(travel_time_comp == 0);
    REQUIRE(result.floors_visited == floors);
};

TEST_CASE("First floor only", "[first_only]") {
    std::vector<int> floors = {12};
    ElevatorController controller;
    RESULT result = controller.add_floors(floors);
    REQUIRE(result.travel_time == 0);
    REQUIRE(result.floors_visited == floors);
};
