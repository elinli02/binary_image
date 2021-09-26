#include "binary_image.h"
#include<iostream>
using namespace std;
BinaryImage* createImage();
int main()
{
	setlocale(LC_ALL, "Rus");
	int choice_menu;
	int choice;
	bool value;
	BinaryImage* binaryImage1=NULL;
	BinaryImage* binaryImage2 = NULL;
	BinaryImage binaryImageRes;
	binaryImage1 = createImage(); //выделяем память внутри функции и возвращаем результат
	binaryImage2 = createImage();
	do
	{
		cout << endl;
		cout << "1. Multiplication of two binary image" << endl;
		cout << "2. Addition of two binary image" << endl;
		cout << "3. Multiplication binary image with bool " << endl;
		cout << "4. Addition binary image and bool" << endl;
		cout << "5. Invert image values" << endl;
		cout << "6. Image occupancy factor" << endl;
		cout << "7. Image output" << endl;
		cout << "8. Complete the work" << endl; 
		cout << "Your choice: ";
		cin >> choice_menu;
		switch (choice_menu)
		{
		case 1:
			if (binaryImage1 != NULL && binaryImage2 != NULL)
			{
				binaryImageRes = (*binaryImage1) * (*binaryImage2);
				cout << binaryImageRes;
			}
			break;
		case 2:
			if (binaryImage1 != NULL && binaryImage2 != NULL)
			{
				binaryImageRes = (*binaryImage1) + (*binaryImage2);
				cout << binaryImageRes;
			}
			break;
		case 3:
			if (binaryImage1 != NULL && binaryImage2 != NULL)
			{
				do
				{
					cout << "Select picture: " << endl;
					cout << "For picture 1 - press 1" << endl;
					cout << "For picture 2 - press 2" << endl;
					cout << "Your choice: ";
					cin >> choice;
				} while (choice > 2 || choice < 0);
				cout << "Enter value: ";
				cin >> value;
				if (choice == 1)
				{
					binaryImageRes = (*binaryImage1) * value;
				}
				else
				{
					binaryImageRes = (*binaryImage2) * value;
				}
				cout << binaryImageRes;
			}
			break;
		case 4:

			break;
		case 5:
			do
			{
				cout << "Select picture: " << endl;
				cout << "For picture 1 - press 1" << endl;
				cout << "For picture 2 - press 2" << endl;
				cout << "Your choice: ";
				cin >> choice;
			} while (choice >2 || choice<0);
			if (choice == 1)
			{
				!(*binaryImage1);
				cout << *binaryImage1;
			}
			else
			{
				!(*binaryImage2);
				cout << *binaryImage2;
			}
			//!(*binaryImage1);
			//cout << *binaryImage1;
			break;
		case 6:
			do
			{
				cout << "Select picture: " << endl;
				cout << "For picture 1 - press 1" << endl;
				cout << "For picture 2 - press 2" << endl;
				cout << "Your choice: ";
				cin >> choice;
			} while (choice > 2 || choice<0);
			if (choice == 1)
			{
				cout<<(*binaryImage1).coefficient();
			}
			else
			{
				cout << (*binaryImage2).coefficient();
			}
			break;
		case 7:
			if (binaryImage1 != NULL && binaryImage2!=NULL)
			{
				cout << "Image 1:" << endl;
				cout << *binaryImage1; 
				cout << endl;
				cout << "Image 2:" << endl;
				cout << *binaryImage2;
			}
			else
			{
				cout << "Error";
			}
			break;
		case 8:
			break;
		}
	} while (choice_menu != 8); 
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