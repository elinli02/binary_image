#include "functional_interface.h"

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