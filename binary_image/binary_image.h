#pragma once
class BinaryImage
{
private:
	bool** array;
	int M, N;
public:
	BinaryImage(int M, int N);
	bool operator()(int i, int j); //чтение
	void operator()(int i, int j, bool value); //запись
	BinaryImage& operator *(BinaryImage second);
};

