#pragma once
#ifndef FUNCTIONALINTERFACE
#define FUNCTIONALINTERFACE
#include <iostream>
#include "binary_image.h"
#include "cardinal_direction.h"
using namespace std;
template<typename T, T valuePositive, T valueNegative>
ostream& operator<<(ostream& os, const BinaryImage<T, valuePositive, valueNegative>& image);
template ostream& operator<< (ostream& os, const BinaryImage<bool, 1, 0>& image);
template ostream& operator<< (ostream& os, const BinaryImage<int, 3, 7>& image);
template ostream& operator<< (ostream& os, const BinaryImage<CardinalDirection, CardinalDirection::NORTH, CardinalDirection::SOUTH>& image);
#endif