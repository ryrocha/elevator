#include <catch2/catch_test_macros.hpp>
#include <elevator/elevator_controller.h>
#include <vector>
#include <iostream>

TEST_CASE("Modified floor travel time", "[floor_time]") {
    std::vector<int> floors = {12, 2, 9, 1, 32};
    double floor_time = 8.6;
    ElevatorController controller;
    RESULT result = controller.add_floors(floors, floor_time);
    int travel_time_comp = result.travel_time - 361.2;
    REQUIRE(travel_time_comp == 0);
    std::vector<int> floors_visited = {12, 9, 2, 1, 32};
    REQUIRE(result.floors_visited == floors_visited);
};

TEST_CASE("First floor only", "[first_only]") {
    std::vector<int> floors = {12};
    ElevatorController controller;
    RESULT result = controller.add_floors(floors);
    REQUIRE(result.travel_time == 0);
    REQUIRE(result.floors_visited == floors);
};

TEST_CASE("No floors given", "[no_floors]") {
    std::vector<int> floors = {};
    ElevatorController controller;
    RESULT result = controller.add_floors(floors);
    REQUIRE(result.travel_time == 0);
    REQUIRE(result.floors_visited == floors);
};

TEST_CASE("Optimal travel time downwards", "[optimal]") {
    std::vector<int> floors = {12, 12, 2, 9, 1, 8, 8};
    ElevatorController controller;
    RESULT result = controller.add_floors(floors);
    REQUIRE(result.travel_time == 110);
    std::vector<int> floors_visited = {12, 9, 8, 2, 1};
    REQUIRE(result.floors_visited == floors_visited);
};

TEST_CASE("Optimal travel time upwards", "[optimal]") {
    std::vector<int> floors = {12, 32, 25, 32, 13, 13, 27, 25};
    ElevatorController controller;
    RESULT result = controller.add_floors(floors);
    REQUIRE(result.travel_time == 200);
    std::vector<int> floors_visited = {12, 13, 25, 27, 32};
    REQUIRE(result.floors_visited == floors_visited);
};

TEST_CASE("Optimal travel time down first", "[optimal]") {
    std::vector<int> floors = {12, 12, 32, 9, 27, 11, 9, 11};
    ElevatorController controller;
    RESULT result = controller.add_floors(floors);
    REQUIRE(result.travel_time == 260);
    std::vector<int> floors_visited = {12, 11, 9, 27, 32};
    REQUIRE(result.floors_visited == floors_visited);
};

TEST_CASE("Optimal travel time up first", "[optimal]") {
    std::vector<int> floors = {12, 1, 12, 1, 19, 3, 15, 15, 15};
    ElevatorController controller;
    RESULT result = controller.add_floors(floors);
    REQUIRE(result.travel_time == 250);
    std::vector<int> floors_visited = {12, 15, 19, 3, 1};
    REQUIRE(result.floors_visited == floors_visited);
};
