#pragma once
#ifndef BINARYIMAGE
#define BINARYIMAGE
#include "cardinal_direction.h"
#include <iostream>
using namespace std;
template <typename T=bool, T valuePositive=1, T valueNegative=0>
class BinaryImage
{
private:
	T** array;
	int rows, cols;
	void reset();
public:
	BinaryImage();
	BinaryImage(int rows, int cols);
	T& operator()(int i, int j);
	const bool& operator()(int i, int j) const;
	BinaryImage(const BinaryImage& copy);
	int getRows() const;
	int getCols() const;
	BinaryImage operator=(const BinaryImage &binaryimage);
	BinaryImage operator *(const BinaryImage &second) const;
	BinaryImage operator +(const BinaryImage &second) const;
	BinaryImage operator +(const T value) const; 
	BinaryImage operator *(const T value) const;
	BinaryImage operator !() const;
	double coefficient() const;
	bool operator==(const BinaryImage& second) const; 
	~BinaryImage();
};

template class BinaryImage<int, 3, 7>;
template class BinaryImage<bool, 1, 0>;
template class BinaryImage<CardinalDirection, CardinalDirection::NORTH, CardinalDirection::SOUTH>;
#endif
