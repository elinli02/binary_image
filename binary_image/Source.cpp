#include "binary_image.h"
#include "functional_interface.h"
#include "cardinal_direction.h"
#include<iostream>
using namespace std;
template<typename T = bool, T valuePositive = 1, T valueNegative = 0>
BinaryImage<T, valuePositive, valueNegative> createImage();
void choiceType();
template<typename T = bool, T valuePositive = 1, T valueNegative = 0>
void operation(BinaryImage<T, valuePositive, valueNegative> binaryImage1, BinaryImage<T, valuePositive, valueNegative> binaryImage2, string infoInput);
int main()
{
	setlocale(LC_ALL, "Rus");
	try
	{
		choiceType();
		

		//test1
		/*bool value;
		const bool vP = true, vN = false;
		string infoInput = "1, 0";
		BinaryImage<bool, vP, vN> binaryImage1(createImage<bool, vP, vN>());
		BinaryImage<bool, vP, vN> binaryImage2(createImage<bool, vP, vN>()); */
		
		//test2
		/*
		const int vP = 3, vN = 7;
		int value;
		string infoInput = "0, 1/3, 7";
		BinaryImage<int, vP, vN> binaryImage1(createImage<int, vP, vN>());
		BinaryImage<int, vP, vN> binaryImage2(createImage<int, vP, vN>());  */
		
		/*do
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
					cout << "Enter value ("<<infoInput<<"): ";
					cin >> value;
					binaryImage1(row - 1, col - 1) = value;
				}
				else
				{
					cout << "Enter value  (" << infoInput << "): ";
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
		} while (choice_menu != 9); */
	}
	catch (const char* message)
	{
		cout << message;
	}
}
template<typename T = bool, T valuePositive = 1, T valueNegative = 0>
BinaryImage<T, valuePositive, valueNegative> createImage()
{
	int rows, cols;
	cout << "Enter count of rows ";
	cin >> rows;
	cout << "Enter count of cols ";
	cin >> cols;
	BinaryImage<T, valuePositive, valueNegative> temp(rows, cols);
	return temp;
}


void choiceType()
{
	int choice;
	cout << "Select the type of elements in the binary image" << endl;
	cout << "1. Bool" << endl;
	cout << "2. Integer" << endl;
	cout << "3. Cardinal Direction" << endl;
	cin >> choice;
	if (choice == 1)
	{
		const bool vP = true, vN = false;
		string infoInput = "1, 0";
		BinaryImage<bool, vP, vN> binaryImage1(createImage<bool, vP, vN>());
		BinaryImage<bool, vP, vN> binaryImage2(createImage<bool, vP, vN>());
		operation(binaryImage1, binaryImage2, infoInput);
	}
	if (choice == 2)
	{
		const int vP = 3, vN = 7;
		string infoInput = "3, 7/ 1, 0";
		BinaryImage<int, vP, vN> binaryImage1(createImage<int, vP, vN>());
		BinaryImage<int, vP, vN> binaryImage2(createImage<int, vP, vN>());
		operation(binaryImage1, binaryImage2, infoInput);
	}
	if (choice == 3)
	{
		const CardinalDirection vP = CardinalDirection::NORTH, vN = CardinalDirection::SOUTH;
		string infoInput = "NORTH(1), SOUTH(0)/ 1, 0";
		BinaryImage<CardinalDirection, vP, vN> binaryImage1(createImage<CardinalDirection, vP, vN>());
		BinaryImage<CardinalDirection, vP, vN> binaryImage2(createImage<CardinalDirection, vP, vN>());
		operation(binaryImage1, binaryImage2, infoInput);
	}
}
template<typename T = bool, T valuePositive = 1, T valueNegative = 0>
void operation(BinaryImage<T, valuePositive, valueNegative> binaryImage1, BinaryImage<T, valuePositive, valueNegative> binaryImage2, string infoInput)
{
	int choice_menu;
	int choice;
	int row, col;
	int value;
	T valueType;
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
				cout << "Enter value (" << infoInput << "): ";
				cin >> value;
				if (value == static_cast<int>(valuePositive) || value== static_cast<int>(valueNegative) || value==1 || value==0)
				{
					valueType = static_cast<T>(value);
					binaryImage1(row - 1, col - 1) = valueType;
				}
				else
				{
					throw("Incorrect value");
				}
			}
			else
			{
				cout << "Enter value (" << infoInput << "): ";
				cin >> value;
				if (value == static_cast<int>(valuePositive) || value == static_cast<int>(valueNegative))
				{
					valueType = static_cast<T>(value);
					binaryImage2(row - 1, col - 1) = valueType;
				}
				else
				{
					throw("Incorrect value");
				}

				/*cout << "Enter value  (" << infoInput << "): ";
				cin >> value;
				valueType = static_cast<T>(value);
				binaryImage2(row - 1, col - 1) = valueType; */
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
			valueType = static_cast<T>(value);
			if (choice == 1)
			{
				cout << binaryImage1 * valueType;
			}
			else
			{
				cout << binaryImage2 * valueType;
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
			valueType = static_cast<T>(value);
			if (choice == 1)
			{
				cout << binaryImage1 + valueType;
			}
			else
			{
				cout << binaryImage2 + valueType;
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
			cout << (binaryImage1 == binaryImage2) << endl;
		}
		case 9:
			break;
		}
	} while (choice_menu != 9);
}
