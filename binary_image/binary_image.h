#pragma once
class BinaryImage
{
private:
	bool** array;
	int M, N;
public:
	BinaryImage(int M, int N);
	bool operator()(int i, int j); //������
	void operator()(int i, int j, bool value); //������
	BinaryImage& operator *(BinaryImage second);
};

