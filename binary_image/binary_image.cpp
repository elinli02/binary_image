#include "binary_image.h"

BinaryImage::BinaryImage(int M, int N)
{
	this->M = M;
	this->N = N;
	array = new bool*[M];
	for (int i = 0; i < M; i++)
	{
		array[i] = new bool[N];
	}
}

bool BinaryImage::operator()(int i, int j)
{
	return array[i][j];
}

void BinaryImage::operator()(int i, int j, bool value)
{
	array[i][j] = value;
}

BinaryImage& BinaryImage::operator*(BinaryImage second)
{
	int Mresult, Nresult;
	if (this->M > second.M)
	{
		Mresult = this->M;
	}
	else
	{
		Mresult = second.M;
	}
	if (this->N > second.N)
	{
		Nresult = this->N;
	}
	else
	{
		Nresult = second.N;
	}
	//
	BinaryImage result_image(Mresult, Nresult);
	bool value;
	for (int i = 0; i < Mresult; i++)
	{
		for (int j = 0; j < Nresult; j++)
		{
			true & false;
			result_image(i, j, value);
		}
	}
}
