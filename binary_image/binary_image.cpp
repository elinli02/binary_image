#include "binary_image.h"

BinaryImage::BinaryImage()
{
	M = 0;
	N = 0;
} 

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
			result_image(i, j, value);
		}
	}
	if (this->N > second.N) //если первая матрица шире второй 
	{
		for (int i = 0; i < this->M; i++) //захватывает все строчки из первой матрицы 
		{
			for (int j = Nmin; j < Nresult; j++) //толькр столбики, которые не пересекаются
			{
				result_image(i, j, this->array[i][j]);
			}
		}
	}
	else if (this->N < second.N)
	{
		for (int i = 0; i < second.M; i++)
		{
			for (int j = Nmin; j < Nresult; j++)
			{
				result_image(i, j, second.array[i][j]);
			}
		}
	}
	if (this->M > second.M)
	{
		for (int i = 0; i < this->N; i++)
		{
			for (int j = Mmin; j < Mresult; j++)
			{
				result_image(j, i, this->array[j][i]);
			}
		}
	}
	else if (this->M < second.M)
	{
		for (int i = 0; i < second.N; i++)
		{
			for (int j = Mmin; j < Mresult; j++)
			{
				result_image(j, i, second.array[j][i]);
			}
		}
	}
	return result_image;
}
BinaryImage& BinaryImage::operator+(BinaryImage second)
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
			result_image(i, j, value);
		}
	}
	if (this->N > second.N)
	{
		for (int i = 0; i < this->M; i++)
		{
			for (int j = Nmin; j < Nmax; j++)
			{
				result_image(i, j, this->array[i][j]);
			}
		}
	}
	else if (this->N < second.N)
	{
		for (int i = 0; i < second.M; i++)
		{
			for (int j = Nmin; j < Nmax; j++)
			{
				result_image(i, j, second.array[i][j]);
			}
		}
	}
	else if (this->M > second.M)
	{
		for (int i = 0; i < this->N; i++)
		{
			for (int j = Mmin; j < Mmax; j++)
			{
				result_image(i, j, this->array[i][j]);
			}
		}
	}
	else if (this->M < second.M)
	{
		for (int i = 0; i < second.N; i++)
		{
			for (int j = Mmin; j < Mmax; j++)
			{
				result_image(i, j, second.array[i][j]);
			}
		}
	}
	return result_image;
} 

void BinaryImage::operator!()
{
	for (int i = 0; i < this->M; i++)
	{
		for (int j = 0; j < this->N; j++)
		{
			this->array[i][j] = !this->array[i][j];
		}
	}
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

BinaryImage& operator+(const BinaryImage& start, const bool value)
{
	BinaryImage resultImage(start.M, start.N);
	if (value) //вся матрица будет true
	{
		for (int i = 0; i < start.M; i++)
		{
			for (int j = 0; j < start.N; j++)
			{
				resultImage.array[i][j] = true;
			}
		}
	}
	else //ничего не изменится
	{
		for (int i = 0; i < start.M; i++)
		{
			for (int j = 0; j < start.N; j++)
			{
				resultImage.array[i][j] = start.array[i][j];
			}
		}
	}
	return resultImage;
}

BinaryImage& operator+(const bool value, const BinaryImage& start)
{
	BinaryImage result = start + value; //используем оператор выше
	return result;
}

BinaryImage& operator*(const BinaryImage& start, const bool value)
{
	BinaryImage resultImage(start.M, start.N);
	if (!value)
	{
		for (int i = 0; i < start.M; i++)
		{
			for (int j = 0; j < start.N; j++)
			{
				resultImage.array[i][j] = false;
			}
		}
	}
	else
	{
		for (int i = 0; i < start.M; i++)
		{
			for (int j = 0; j < start.N; j++)
			{
				resultImage.array[i][j] = start.array[i][j];
			}
		}
	}
	return resultImage;
}

BinaryImage& operator*(const bool value, const BinaryImage& start)
{
	BinaryImage result = start * value;
	return result;
}

ostream& operator<<(ostream& os, const BinaryImage& image)
{
	for (int i = 0; i < image.M; i++)
	{
		for (int j = 0; j < image.N; j++)
		{
			if (image.array[i][j])
			{
				os << 1;
			}
			else
			{
				os << ".";
			}
		}
		os << endl;
	}
	return os;
}
