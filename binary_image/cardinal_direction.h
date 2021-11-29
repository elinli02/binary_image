#pragma once
#include <stdexcept>
#include<iostream>
#ifndef CARDINALDIRECTION
#define CARDINALDIRECTION

using namespace std;
enum class CardinalDirection {
    NORTH = 1, EAST = 2, SOUTH = 0, WEST = 4
};
istream& operator>> (istream& in, CardinalDirection& x);
//bool operator==(CardinalDirection first, CardinalDirection second);
/*bool operator==(CardinalDirection first, CardinalDirection second)
{
    return static_cast<int>(first) == static_cast<int>(second);
} */

#endif // !CARDINALDIRECTION