#include "binary_image.h"

void BinaryImage::reset()
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

BinaryImage::BinaryImage()
{
	rows = 0;
	cols = 0;
	array = NULL;
} 

BinaryImage::BinaryImage(int rows, int cols)
{
	if(rows<=0 || cols<=0)
	{
		throw"The number of rows and columns should be >0";
	}
	this->rows = rows;
	this->cols = cols;
	array = new bool*[rows];
	for (int i = 0; i < rows; i++)
	{
		array[i] = new bool[cols];
		for (int j = 0; j < cols; j++)
		{
			array[i][j] = true;
		}
	}
}
const bool& BinaryImage::operator()(int i, int j) const
{
	if (i >= rows || j >= cols || i < 0 || j < 0)
	{
		throw"Values abroad";
	}
	return array[i][j];
}

bool& BinaryImage::operator()(int i, int j)
{
	if (i >= rows || j >= cols || i < 0 || j < 0)
	{
		throw"Values abroad";
	}
	return array[i][j];
} 

BinaryImage::BinaryImage(const BinaryImage& copy)
{
	rows = copy.rows;
	cols = copy.cols;
	array = new bool*[rows];
	for (int i = 0; i < rows; i++)
	{
		array[i] = new bool[cols];
		for (int j = 0; j < cols; j++)
		{
			array[i][j] = copy.array[i][j];
		}
	}
}

int BinaryImage::getRows() const
{
	return rows;
}

int BinaryImage::getCols() const
{
	return cols;
}

BinaryImage BinaryImage::operator=(const BinaryImage &binaryimage)
{
	if (this == &binaryimage)
	{
		return *this;
	}
	reset();
	rows = binaryimage.rows;
	cols = binaryimage.cols;
	array = new bool* [rows];
	for (int i = 0; i < rows; i++)
	{
		array[i] = new bool[cols];
		for (int j = 0; j < cols; j++)
		{
			array[i][j] = binaryimage.array[i][j];
		}
	}
	return binaryimage;
}

BinaryImage BinaryImage::operator*(const BinaryImage &second) const
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
BinaryImage BinaryImage::operator+(const BinaryImage &second) const
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


BinaryImage BinaryImage::operator!() const
{
	BinaryImage temp(rows, cols);
	for (int i = 0; i < temp.rows; i++)
	{
		for (int j = 0; j < temp.cols; j++)
		{
			temp.array[i][j] = !temp.array[i][j];
		}
	}
	return temp;
}

double BinaryImage::coefficient() const
{
	int countElementsTrue=0;
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
		{
			if (this->array[i][j])
			{
				countElementsTrue++;
			}
		}
	}
	int countElements = rows * cols;
	return (double)countElementsTrue/countElements;
}


BinaryImage::~BinaryImage()
{
	reset();
}

BinaryImage BinaryImage::operator+(const bool value) const
{
	BinaryImage resultImage(rows, cols);
	if (value) //вся матрица будет true
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				resultImage.array[i][j] = true;
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



BinaryImage BinaryImage::operator*(const bool value) const
{
	BinaryImage resultImage(rows, cols);
	if (!value)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				resultImage.array[i][j] = false;
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

 


bool BinaryImage::operator==(const BinaryImage& second) const
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

