#include "binary_image.h"
#include "functional_interface.h"
#include<iostream>
using namespace std;
BinaryImage createImage();
int main()
{
	 
	try
	{
		setlocale(LC_ALL, "Rus");
		int choice_menu;
		int choice;
		bool value;
		int row, col;
		BinaryImage binaryImage1(createImage()); 
		BinaryImage binaryImage2(createImage()); 
		do
		{
			cout << endl;
			cout << "0. Change image" << endl;
			cout << "1. Multiplication of two binary image" << endl;
			cout << "2. Addition of two binary image" << endl;
			cout << "3. Multiplication binary image with bool " << endl;
			cout << "4. Addition binary image and bool" << endl;
			cout << "5. Invert image values" << endl;
			cout << "6. Image occupancy factor" << endl;
			cout << "7. Image output" << endl;
			cout << "8. Comparison" << endl;
			cout << "9. Complete the work" << endl;
			cout << "Your choice: ";
			cin >> choice_menu;
			switch (choice_menu)
			{
			case 0:
			{
				do
				{
					cout << "Select picture: " << endl;
					cout << "For picture 1 - press 1" << endl;
					cout << "For picture 2 - press 2" << endl;
					cout << "Your choice: ";
					cin >> choice;
				} while (choice > 2 || choice < 0);
				cout << "Number row: ";
				cin >> row;
				cout << "Number col: ";
				cin >> col;
				if (choice == 1)
				{
					cout << "Enter value (0 or 1): ";
					cin >> value;
					binaryImage1(row - 1, col - 1) = value; 
				}
				else
				{
					cout << "Enter value (0 or 1): ";
					cin >> value;
					binaryImage2(row - 1, col - 1) = value;
				}
			}
			break;
			case 1:
			{
				cout << binaryImage1 * binaryImage2; 
			}
			break;
			case 2:
			{
				cout << binaryImage1 + binaryImage2;
			}
			break;
			case 3:
			{
				do
				{
					cout << "Select picture: " << endl;
					cout << "For picture 1 - press 1" << endl;
					cout << "For picture 2 - press 2" << endl;
					cout << "Your choice: ";
					cin >> choice;
				} while (choice > 2 || choice < 0);
				cout << "Enter value (0 or 1): ";
				cin >> value;
				if (choice == 1)
				{
					cout << binaryImage1 * value;
				}
				else
				{
					cout << binaryImage2 * value;
				}
			}
			break;
			case 4:
			{
				do
				{
					cout << "Select picture: " << endl;
					cout << "For picture 1 - press 1" << endl;
					cout << "For picture 2 - press 2" << endl;
					cout << "Your choice: ";
					cin >> choice;
				} while (choice > 2 || choice < 0);
				cout << "Enter value (0 or 1): ";
				cin >> value;
				if (choice == 1)
				{
					cout << binaryImage1 + value;
				}
				else
				{
					cout << binaryImage2 + value;
				}
			}
			break;
			case 5:
			{
				do
				{
					cout << "Select picture: " << endl;
					cout << "For picture 1 - press 1" << endl;
					cout << "For picture 2 - press 2" << endl;
					cout << "Your choice: ";
					cin >> choice;
				} while (choice > 2 || choice < 0);
				if (choice == 1)
				{
					cout << !binaryImage1;
				}
				else
				{
					cout << !binaryImage2;
				}
			}
			break;
			case 6:
			{
				do
				{
					cout << "Select picture: " << endl;
					cout << "For picture 1 - press 1" << endl;
					cout << "For picture 2 - press 2" << endl;
					cout << "Your choice: ";
					cin >> choice;
				} while (choice > 2 || choice < 0);
				if (choice == 1)
				{
					cout << binaryImage1.coefficient();
				}
				else
				{
					cout << binaryImage2.coefficient();
				}
			}
			break;
			case 7:
			{
				cout << "Image 1:" << endl;
				cout << binaryImage1;
				cout << endl;
				cout << "Image 2:" << endl;
				cout << binaryImage2;
			}
			break;
			case 8:
			{
				cout << "0 - Images are different" << endl;
				cout << "1 - Images are equal" << endl;
				cout << "Result: ";
				cout << (binaryImage1 == binaryImage2)<<endl;
			}
			case 9:
				break;
			}
		} while (choice_menu != 9);
	}
	catch (const char* message)
	{
		cout << message;
	}
}
BinaryImage createImage() 
{
	int rows, cols;
	cout << "Enter count of rows ";
	cin >> rows;
	cout << "Enter count of cols ";
	cin >> cols;
	BinaryImage temp(rows, cols);
	return temp;
}
