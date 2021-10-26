#include "binary_image.h"

BinaryImage::BinaryImage()
{
	M = 0;
	N = 0;
	array = NULL;
} 

BinaryImage::BinaryImage(int M, int N)
{
	if(M<=0 || N<=0)
	{
		throw"The number of rows and columns should be >0";
	}
	this->M = M;
	this->N = N;
	array = new bool*[M];
	for (int i = 0; i < M; i++)
	{
		array[i] = new bool[N];
		for (int j = 0; j < N; j++)
		{
			array[i][j] = true;
		}
	}
}
const bool& BinaryImage::operator()(int i, int j) const
{
	if (i >= M || j >= N || i < 0 || j < 0)
	{
		throw"Values abroad";
	}
	return array[i][j];
}

bool& BinaryImage::operator()(int i, int j)
{
	if (i >= M || j >= N || i < 0 || j < 0)
	{
		throw"Values abroad";
	}
	return array[i][j];
} 

BinaryImage::BinaryImage(const BinaryImage& copy)
{
	M = copy.M;
	N = copy.N;
	array = new bool*[M];
	for (int i = 0; i < M; i++)
	{
		array[i] = new bool[N];
		for (int j = 0; j < N; j++)
		{
			array[i][j] = copy.array[i][j];
		}
	}
}

int BinaryImage::get_M() const
{
	return M;
}

int BinaryImage::get_N() const
{
	return N;
}

BinaryImage& BinaryImage::operator=(const BinaryImage &binaryimage)
{
	if (this == &binaryimage)
	{
		return *this;
	}
	M = binaryimage.M;
	N = binaryimage.N;
	for (int i = 0; i < M; i++)
	{
		array[i] = new bool[N];
		for (int j = 0; j < N; j++)
		{
			array[i][j] = binaryimage.array[i][j];
		}
	}
	return *this;
}

BinaryImage BinaryImage::operator*(const BinaryImage &second)
{
	int Mresult, Nresult; //max
	int Mmin, Nmin;
	if (this->M > second.M)
	{
		Mresult = this->M;
		Mmin = second.M;
	}
	else
	{
		Mresult = second.M;
		Mmin = this->M;
	}
	if (this->N > second.N)
	{
		Nresult = this->N;
		Nmin = second.N;
	}
	else
	{
		Nresult = second.N;
		Nmin = this->N;
	}
	BinaryImage result_image(Mresult, Nresult);
	bool value;
	for (int i = 0; i < Mmin; i++)
	{
		for (int j = 0; j < Nmin; j++)
		{
			if (array[i][j] && second.array[i][j])
			{
				value = true;
			}
			else
			{
				value = false;
			}
			result_image(i, j) = value;
		}
	}
	if (this->N > second.N) //если первая матрица шире второй 
	{
		for (int i = 0; i < this->M; i++) //захватывает все строчки из первой матрицы 
		{
			for (int j = Nmin; j < Nresult; j++) //толькр столбики, которые не пересекаются
			{
				result_image(i, j)= this->array[i][j];
			}
		}
	}
	else if (this->N < second.N)
	{
		for (int i = 0; i < second.M; i++)
		{
			for (int j = Nmin; j < Nresult; j++)
			{
				result_image(i, j)= second.array[i][j];
			}
		}
	}
	if (this->M > second.M)
	{
		for (int i = 0; i < this->N; i++)
		{
			for (int j = Mmin; j < Mresult; j++)
			{
				result_image(j, i)= this->array[j][i];
			}
		}
	}
	else if (this->M < second.M)
	{
		for (int i = 0; i < second.N; i++)
		{
			for (int j = Mmin; j < Mresult; j++)
			{
				result_image(j, i)= second.array[j][i];
			}
		}
	}
	return result_image;
}
BinaryImage BinaryImage::operator+(const BinaryImage &second)
{
	int Nmax, Mmax;
	int Nmin, Mmin;
	if (this->M > second.M)
	{
		Mmax = this->M;
		Mmin = second.M;
	}
	else
	{
		Mmax = second.M;
		Mmin = this->M;
	}
	if (this->N > second.N)
	{
		Nmax = this->N;
		Nmin = second.N;
	}
	else
	{
		Nmax = second.N;
		Nmin = this->N;
	}
	BinaryImage result_image(Mmax, Nmax);
	bool value;
	for(int i=0; i<Mmin; i++)
	{
		for(int j=0; j<Nmin; j++)
		{
			if(array[i][j]==false && second.array[i][j]==false)
			{
				value = false;
			}
			else
			{
				value = true;
			}
			result_image(i, j)= value;
		}
	}
	if (this->N > second.N)
	{
		for (int i = 0; i < this->M; i++)
		{
			for (int j = Nmin; j < Nmax; j++)
			{
				result_image(i, j)= this->array[i][j];
			}
		}
	}
	else if (this->N < second.N)
	{
		for (int i = 0; i < second.M; i++)
		{
			for (int j = Nmin; j < Nmax; j++)
			{
				result_image(i, j)= second.array[i][j];
			}
		}
	}
	else if (this->M > second.M)
	{
		for (int i = 0; i < this->N; i++)
		{
			for (int j = Mmin; j < Mmax; j++)
			{
				result_image(i, j)= this->array[i][j];
			}
		}
	}
	else if (this->M < second.M)
	{
		for (int i = 0; i < second.N; i++)
		{
			for (int j = Mmin; j < Mmax; j++)
			{
				result_image(i, j)= second.array[i][j];
			}
		}
	}
	return result_image;
}


BinaryImage BinaryImage::operator!()
{
	BinaryImage temp(M, N);
	for (int i = 0; i < temp.M; i++)
	{
		for (int j = 0; j < temp.N; j++)
		{
			temp.array[i][j] = !temp.array[i][j];
		}
	}
	return temp;
}

double BinaryImage::coefficient()
{
	int countElementsTrue=0;
	for (int i = 0; i < this->M; i++)
	{
		for (int j = 0; j < this->N; j++)
		{
			if (this->array[i][j])
			{
				countElementsTrue++;
			}
		}
	}
	int countElements = M * N;
	return (double)countElementsTrue/countElements;
}


BinaryImage::~BinaryImage()
{
	for(int i=0; i<M; i++)
	{
		delete[] array[i];
	}
	delete[] array;
}

BinaryImage BinaryImage::operator+(const bool value)
{
	BinaryImage resultImage(M, N);
	if (value) //вся матрица будет true
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				resultImage.array[i][j] = true;
			}
		}
	}
	else //ничего не изменится
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				resultImage.array[i][j] = array[i][j];
			}
		}
	}
	return resultImage;
}



BinaryImage BinaryImage::operator*(const bool value)
{
	BinaryImage resultImage(M, N);
	if (!value)
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				resultImage.array[i][j] = false;
			}
		}
	}
	else
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				resultImage.array[i][j] = array[i][j];
			}
		}
	}
	return resultImage;
}

 


bool BinaryImage::operator==(const BinaryImage& second)
{
	if (M != second.M || N != second.N)
	{
		return false;
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (array[i][j] != second.array[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

