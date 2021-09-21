#include "binary_image.h"
#include<iostream>
using namespace std;
BinaryImage* createImage();
int main()
{
	setlocale(LC_ALL, "Rus");
	int choice_menu;
	BinaryImage *binaryImage1=NULL;
	BinaryImage* binaryImage2 = NULL;
	BinaryImage binaryImageRes;
	do
	{
		cout << endl;
		cout << "1. Create a binary image" << endl; //вынести за меню
		cout << "2. Multiplication of two binary image" << endl;
		cout << "3. Addition of two binary image" << endl;
		cout << "4. Multiplication binary image with bool " << endl;
		cout << "5. Addition binary image and bool" << endl;
		cout << "6. Invert image values" << endl;
		cout << "7. Image occupancy factor" << endl;
		cout << "8. Image output" << endl;
		cout << "9. Complete the work" << endl; 
		cout << "Your choice: ";
		cin >> choice_menu;
		switch (choice_menu)
		{
		case 1:
			binaryImage1=createImage(); //выделяем память внутри функции и возвращаем результат
			binaryImage2 = createImage();
			break;
		case 2:
			if (binaryImage1 != NULL && binaryImage2 != NULL)
			{
				binaryImageRes = (*binaryImage1) * (*binaryImage2);
				cout << binaryImageRes;
			}
			break;
		case 6:
			!(*binaryImage1);
			cout << *binaryImage1;
			break;
		case 8:
			if (binaryImage1 != NULL)
			{
				cout << *binaryImage1; 
			}
			else
			{
				cout << "Error";
			}
			break;
		}
	} while (choice_menu != 9); 
	/*BinaryImage first(3, 4);
	BinaryImage second(2, 5);
	cout << first;
	cout << endl;
	cout << second;
	cout << endl;
	second(0, 0, false);
	cout << second;
	cout << endl;
	//second(1, 1, false);
	BinaryImage third = first * second;
	cout << third;
	cout << endl;
	BinaryImage four = first + second;
	cout << four;
	cout << endl;
	!second;
	cout << second;
	BinaryImage fourth = second + true;
	double res_coef = second.coefficient(); double res=b->coef
	cout << res_coef; */
}
BinaryImage* createImage() //возвращаем указатель на новыц объект
{
	int rows, cols;
	cout << "Enter count of rows ";
	cin >> rows;
	cout << "Enter count of cols ";
	cin >> cols;
	return new BinaryImage(rows, cols);
}