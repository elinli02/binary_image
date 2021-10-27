#include "functional_interface.h"

ostream& operator<<(ostream& os, const BinaryImage& image)
{
	for (int i = 0; i < image.getRows(); i++)
	{
		for (int j = 0; j < image.getCols(); j++)
		{
			if (image(i, j))
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