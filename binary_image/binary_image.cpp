#include "binary_image.h"

template<typename T, T valuePositive, T valueNegative>
void BinaryImage<T, valuePositive, valueNegative>::reset()
{
	for (int i = 0; i < rows; i++)
	{
		delete[] array[i];
	}
	delete[] array;
	rows = 0;
	cols = 0;
	array = nullptr;
}
template<typename T, T valuePositive, T valueNegative>
BinaryImage<T, valuePositive, valueNegative>::BinaryImage()
{
	rows = 0;
	cols = 0;
	array = NULL;
} 
template<typename T, T valuePositive, T valueNegative>
BinaryImage<T, valuePositive, valueNegative>::BinaryImage(int rows, int cols)
{
	if(rows<=0 || cols<=0)
	{
		throw"The number of rows and columns should be >0";
	}
	this->rows = rows;
	this->cols = cols;
	array = new T*[rows];
	for (int i = 0; i < rows; i++)
	{
		array[i] = new T[cols];
		for (int j = 0; j < cols; j++)
		{
			array[i][j] = valuePositive;
		}
	}
}


template<typename T, T valuePositive, T valueNegative>
T& BinaryImage<T, valuePositive, valueNegative >::operator()(int i, int j) 
{
	if (i >= rows || j >= cols || i < 0 || j < 0)
	{
		throw"Values abroad";
	}
	//if (array[i][j] != valuePositive && array[i][j] != valueNegative && array[i][j]!=true && array[i][j]!=false)
	if (array[i][j] != valuePositive && array[i][j] != valueNegative)
	{
		throw"Incorrect values";
	}
	return static_cast<T&>(array[i][j]); //преобразуем к необходимому типу
}

template<typename T, T valuePositive, T valueNegative>
const bool& BinaryImage<T, valuePositive, valueNegative>::operator()(int i, int j) const
{
	if (i >= rows || j >= cols || i < 0 || j < 0)
	{
		throw"Values abroad";
	}
	if (array[i][j] == valuePositive)
	{
		return true;
	}
	return false;
	//return array[i][j];
} 
template<typename T, T valuePositive, T valueNegative>
BinaryImage<T, valuePositive, valueNegative>::BinaryImage(const BinaryImage<T, valuePositive, valueNegative>& copy)
{
	rows = copy.rows;
	cols = copy.cols;
	array = new T*[rows];
	for (int i = 0; i < rows; i++)
	{
		array[i] = new T[cols];
		for (int j = 0; j < cols; j++)
		{
			array[i][j] = copy.array[i][j];
		}
	}
}
template<typename T, T valuePositive, T valueNegative>
int BinaryImage<T, valuePositive, valueNegative>::getRows() const
{
	return rows;
}
template<typename T, T valuePositive, T valueNegative>
int BinaryImage<T, valuePositive, valueNegative>::getCols() const
{
	return cols;
}
template<typename T, T valuePositive, T valueNegative>
BinaryImage<T, valuePositive, valueNegative> BinaryImage<T, valuePositive, valueNegative>::operator=(const BinaryImage<T, valuePositive, valueNegative>&binaryimage)
{
	if (this == &binaryimage)
	{
		return *this;
	}
	reset();
	rows = binaryimage.rows;
	cols = binaryimage.cols;
	array = new T* [rows];
	for (int i = 0; i < rows; i++)
	{
		array[i] = new T[cols];
		for (int j = 0; j < cols; j++)
		{
			array[i][j] = binaryimage.array[i][j];
		}
	}
	return binaryimage;
}
template<typename T, T valuePositive, T valueNegative>
BinaryImage<T, valuePositive, valueNegative> BinaryImage<T, valuePositive, valueNegative>::operator*(const BinaryImage<T, valuePositive, valueNegative>&second) const
{
	int Mresult, Nresult; //max
	int Mmin, Nmin;
	if (this->rows > second.rows)
	{
		Mresult = this->rows;
		Mmin = second.rows;
	}
	else
	{
		Mresult = second.rows;
		Mmin = this->rows;
	}
	if (this->cols > second.cols)
	{
		Nresult = this->cols;
		Nmin = second.cols;
	}
	else
	{
		Nresult = second.cols;
		Nmin = this->cols;
	}
	BinaryImage<T, valuePositive, valueNegative> result_image(Mresult, Nresult);
	T value;
	for (int i = 0; i < Mmin; i++)
	{
		for (int j = 0; j < Nmin; j++)
		{
			if (array[i][j] ==valuePositive && second.array[i][j]==valuePositive)
			{
				value = valuePositive;
			}
			else
			{
				value = valueNegative;
			}
			result_image(i, j) = value;
		}
	}
	if (this->cols > second.cols) //если первая матрица шире второй 
	{
		for (int i = 0; i < this->rows; i++) //захватывает все строчки из первой матрицы 
		{
			for (int j = Nmin; j < Nresult; j++) //толькр столбики, которые не пересекаются
			{
				result_image(i, j)= this->array[i][j];
			}
		}
	}
	else if (this->cols < second.cols)
	{
		for (int i = 0; i < second.rows; i++)
		{
			for (int j = Nmin; j < Nresult; j++)
			{
				result_image(i, j)= second.array[i][j];
			}
		}
	}
	if (this->rows > second.rows)
	{
		for (int i = 0; i < this->cols; i++)
		{
			for (int j = Mmin; j < Mresult; j++)
			{
				result_image(j, i)= this->array[j][i];
			}
		}
	}
	else if (this->rows < second.rows)
	{
		for (int i = 0; i < second.cols; i++)
		{
			for (int j = Mmin; j < Mresult; j++)
			{
				result_image(j, i)= second.array[j][i];
			}
		}
	}
	return result_image;
}
template<typename T, T valuePositive, T valueNegative>
BinaryImage<T, valuePositive, valueNegative > BinaryImage<T, valuePositive, valueNegative>::operator+(const BinaryImage<T, valuePositive, valueNegative>&second) const
{
	int Nmax, Mmax;
	int Nmin, Mmin;
	if (this->rows > second.rows)
	{
		Mmax = this->rows;
		Mmin = second.rows;
	}
	else
	{
		Mmax = second.rows;
		Mmin = this->rows;
	}
	if (this->cols > second.cols)
	{
		Nmax = this->cols;
		Nmin = second.cols;
	}
	else
	{
		Nmax = second.cols;
		Nmin = this->cols;
	}
	BinaryImage<T, valuePositive, valueNegative> result_image(Mmax, Nmax);
	T value;
	for(int i=0; i<Mmin; i++)
	{
		for(int j=0; j<Nmin; j++)
		{
			if(array[i][j]==valueNegative && second.array[i][j]==valueNegative)
			{
				value = valueNegative;
			}
			else
			{
				value = valuePositive;
			}
			result_image(i, j)= value;
		}
	}
	if (this->cols > second.cols)
	{
		for (int i = 0; i < this->rows; i++)
		{
			for (int j = Nmin; j < Nmax; j++)
			{
				result_image(i, j)= this->array[i][j];
			}
		}
	}
	else if (this->cols < second.cols)
	{
		for (int i = 0; i < second.rows; i++)
		{
			for (int j = Nmin; j < Nmax; j++)
			{
				result_image(i, j)= second.array[i][j];
			}
		}
	}
	else if (this->rows > second.rows)
	{
		for (int i = 0; i < this->cols; i++)
		{
			for (int j = Mmin; j < Mmax; j++)
			{
				result_image(i, j)= this->array[i][j];
			}
		}
	}
	else if (this->rows < second.rows)
	{
		for (int i = 0; i < second.cols; i++)
		{
			for (int j = Mmin; j < Mmax; j++)
			{
				result_image(i, j)= second.array[i][j];
			}
		}
	}
	return result_image;
}

template<typename T, T valuePositive, T valueNegative>
BinaryImage<T, valuePositive, valueNegative> BinaryImage<T, valuePositive, valueNegative>::operator!() const
{
	BinaryImage<T, valuePositive, valueNegative> temp(rows, cols);
	for (int i = 0; i < temp.rows; i++)
	{
		for (int j = 0; j < temp.cols; j++)
		{

			if (temp.array[i][j] == valuePositive)
			{
				temp.array[i][j] = valueNegative;
			}
			else
			{
				temp.array[i][j] = valuePositive;
			}

		}
	}
	return temp;
}
template<typename T, T valuePositive, T valueNegative>
double BinaryImage<T, valuePositive, valueNegative>::coefficient() const
{
	int countElementsTrue=0;
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
		{
			if (this->array[i][j]==valuePositive)
			{
				countElementsTrue++;
			}
		}
	}
	int countElements = rows * cols;
	return (double)countElementsTrue/countElements;
}

template<typename T, T valuePositive, T valueNegative>
BinaryImage<T, valuePositive, valueNegative>::~BinaryImage()
{
	reset();
}
template<typename T, T valuePositive, T valueNegative>
BinaryImage<T, valuePositive, valueNegative> BinaryImage<T, valuePositive, valueNegative>::operator+(const T value) const
{
	BinaryImage<T, valuePositive, valueNegative> resultImage(rows, cols);
	if (value==valuePositive) //вся матрица будет true
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				resultImage.array[i][j] = valuePositive;
			}
		}
	}
	else //ничего не изменится
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				resultImage.array[i][j] = array[i][j];
			}
		}
	}
	return resultImage;
}


template<typename T, T valuePositive, T valueNegative>
BinaryImage<T, valuePositive, valueNegative> BinaryImage<T, valuePositive, valueNegative>::operator*(const T value) const
{
	BinaryImage<T, valuePositive, valueNegative> resultImage(rows, cols);
	if (value==valueNegative)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				resultImage.array[i][j] = valueNegative; 
			}
		}
	}
	else
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				resultImage.array[i][j] = array[i][j];
			}
		}
	}
	return resultImage;
}

template<typename T, T valuePositive, T valueNegative>
bool BinaryImage<T, valuePositive, valueNegative>::operator==(const BinaryImage<T, valuePositive, valueNegative>& second) const
{
	if (rows != second.rows || cols != second.cols)
	{
		return false;
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (array[i][j] != second.array[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

/*template<typename T, T valuePositive, T valueNegative>
ostream& operator<<(ostream& os, const BinaryImage<T, valuePositive, valueNegative>& image)
{
	for (int i = 0; i < image.getRows(); i++)
	{
		for (int j = 0; j < image.getCols(); j++)
		{
			//if (image(i, j) == valuePositive)
			if (image.array[i][j] == valuePositive)
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
}  */