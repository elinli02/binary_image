#pragma once
#include <iostream>
using namespace std;
class BinaryImage
{
private:
	bool** array;
	int M, N;
public:
	BinaryImage();
	BinaryImage(int M, int N);
	bool& operator()(int i, int j);
	const bool& operator()(int i, int j) const;
	BinaryImage(const BinaryImage& copy);
	BinaryImage& operator=(const BinaryImage &binaryimage);
	BinaryImage operator *(BinaryImage second);
	BinaryImage operator +(BinaryImage second);
	friend BinaryImage operator +(const BinaryImage& start, const bool value);
	friend BinaryImage operator +(const bool value, const BinaryImage& start);
	friend BinaryImage operator *(const BinaryImage& start, const bool value);
	friend BinaryImage operator *(const bool value, const BinaryImage& start);
	friend ostream& operator<<(ostream& os, const BinaryImage& image); 
	void operator !();
	double coefficient();
	bool checker_index(int row, int col);
	friend bool operator==(const BinaryImage& first, const BinaryImage& second);
	~BinaryImage();
};

