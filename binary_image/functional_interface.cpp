#include "functional_interface.h"
template<typename T, T valuePositive, T valueNegative>
ostream& operator<<(ostream& os, const BinaryImage<T, valuePositive, valueNegative>& image)
{
	for (int i = 0; i < image.getRows(); i++)
	{
		for (int j = 0; j < image.getCols(); j++)
		{
			//if (image(i, j)==valuePositive || image(i, j)==true)
			if (static_cast<T>(image(i, j))==valuePositive)
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
