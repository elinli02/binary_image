#pragma once
#include <iostream>
using namespace std;
class BinaryImage
{
private:
	bool** array;
	int rows, cols;
	void reset();
public:
	BinaryImage();
	BinaryImage(int rows, int cols);
	bool& operator()(int i, int j);
	const bool& operator()(int i, int j) const;
	BinaryImage(const BinaryImage& copy);
	int getRows() const;
	int getCols() const;
	BinaryImage operator=(const BinaryImage &binaryimage);
	BinaryImage operator *(const BinaryImage &second) const;
	BinaryImage operator +(const BinaryImage &second) const;
	BinaryImage operator +(const bool value) const; 
	BinaryImage operator *(const bool value) const;
	//friend ostream& operator<<(ostream& os, const BinaryImage& image); 
	BinaryImage operator !() const;
	double coefficient() const;
	bool operator==(const BinaryImage& second) const; 
	~BinaryImage();
};
