#include "binary_image.h"
#include<iostream>
using namespace std;
int main()
{
	BinaryImage first(3, 4);
	BinaryImage second(2, 5);
	cout << first;
	cout << second;
	/*for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			first(i, j, false);
		}
	} */
	second(0, 0, false);
	second(1, 1, false);
	BinaryImage third = first * second;
	cout << third;
	!second;
	cout << second;
	BinaryImage fourth = second + true;
	double res_coef = fourth.coefficient();
	cout << res_coef;
}