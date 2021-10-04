#include "binary_image.h"
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
		BinaryImage binaryImage1(createImage()); //с использованием конструктора копирования
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
					if (binaryImage1.checker_index(row - 1, col - 1))
					{
						cout << "Enter value: ";
						cin >> value;
						binaryImage1(row - 1, col - 1) = value; //оператор круглых скобок
					}
				}
				else
				{
					if (binaryImage2.checker_index(row - 1, col - 1))
					{
						cout << "Enter value: ";
						cin >> value;
						binaryImage2(row - 1, col - 1) = value;
					}
				}
			}
			break;
			case 1:
			{
				//BinaryImage binaryImageRes1(binaryImage1 * binaryImage2);
				//cout << binaryImageRes1;
				cout << binaryImage1 * binaryImage2; //копирования, перемножения, вывод
			}
			break;
			case 2:
			{
				BinaryImage binaryImageRes2(binaryImage1 + binaryImage2);
				//binaryImageRes = binaryImage1 + binaryImage2;
				cout << binaryImageRes2; //второй способ через посредственную переменную
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
				cout << "Enter value: ";
				cin >> value;
				if (choice == 1)
				{
					BinaryImage binaryImageRes3 = (binaryImage1 * value); //перемножения, присвоения
					cout << binaryImageRes3;
				}
				else
				{
					BinaryImage binaryImageRes4(binaryImage2 * value);
					cout << binaryImageRes4;
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
				cout << "Enter value: ";
				cin >> value;
				if (choice == 1)
				{
					BinaryImage binaryImageRes5(binaryImage1 + value);
					binaryImageRes5 = binaryImage1 + value;
					cout << binaryImageRes5;
				}
				else
				{
					BinaryImage binaryImageRes6(binaryImage1 + value);
					binaryImageRes6 = binaryImage1 + value;
					cout << binaryImageRes6;
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
					!binaryImage1;
					cout << binaryImage1;
				}
				else
				{
					!binaryImage2;
					cout << binaryImage2;
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
				cout << (binaryImage1 == binaryImage2);
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
		//сами объекты на стеке, сами данные в динамике
		//конструктор копирования(?), деструктор 