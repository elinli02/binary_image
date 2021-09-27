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
	bool operator()(int i, int j); //чтение
	void operator()(int i, int j, bool value); //запись
	BinaryImage& operator *(BinaryImage second);
	BinaryImage& operator +(BinaryImage second);
	friend BinaryImage& operator +(const BinaryImage& start, const bool value);
	friend BinaryImage& operator +(const bool value, const BinaryImage& start);
	friend BinaryImage& operator *(const BinaryImage& start, const bool value);
	friend BinaryImage& operator *(const bool value, const BinaryImage& start);
	friend ostream& operator<<(ostream& os, const BinaryImage& image); //поток вывода
	void operator !();
	double coefficient();
	bool checker_index(int row, int col);
};

