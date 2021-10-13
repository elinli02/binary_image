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
	int get_M() const;
	int get_N() const;
	BinaryImage& operator=(const BinaryImage &binaryimage);
	/*void swap(BinaryImage& binaryimage) {
		std::swap(M, binaryimage.M);
		std::swap(N, binaryimage.N);
		std::swap(array, binaryimage.array);
	}
	void operator=(const BinaryImage& binaryimage); */
	BinaryImage operator *(const BinaryImage &second);
	BinaryImage operator +(const BinaryImage &second);
	BinaryImage operator +(const bool value); 
	BinaryImage operator *(const bool value);
	friend ostream& operator<<(ostream& os, const BinaryImage& image); 
	//void operator !();
	BinaryImage operator !();
	double coefficient();
	bool operator==(const BinaryImage& second); 
	~BinaryImage();
};

