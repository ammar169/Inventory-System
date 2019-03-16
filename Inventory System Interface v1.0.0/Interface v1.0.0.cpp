#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main()
{
	string branch;
	char opt;
	float price[] = { 0 }, amount[] = { 0 }, paid[] = { 0 };
	int code[] = { 0 }, item;
	ofstream file;

	opt = 'y';

	cout << "Insert Branch name: ";
	cin >> branch;
	cout << "How many item you want to insert?: ";
	cin >> item;
	cout << "-----------------------------------------------------------------------------------------------";
	cout << endl;

	while (opt == 'y' || opt == 'Y')
	{

		for (int i = 0; i < item; i++)
		{
			cout << "Enter code item (" << i + 1 << ") : ";
			cin >> code[i];
			cout << "Enter price per unit item (MYR): ";
			cin >> price[i];
			cout << "Enter the number of unit item sold: ";
			cin >> amount[i];
			cout << endl;

			paid[i] = price[i] * amount[i];
		}
		cout << "_______________________________________________________________________________________________";
		cout << endl;
		cout << "Branch name: " << branch.c_str() << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		cout << endl;


		for (int j = 0; j < item; j++)
		{
			cout << fixed << setprecision(2) << "Item code: " << code[j] << endl << "Number of Item sold: " << amount[j]
				<< endl << "Price per unit item: " << price[j] << endl << "Total paid (amount x price) : " << paid[j] << endl;
			cout << endl;
		}

		cout << "_______________________________________________________________________________________________";
		cout << endl << "Want to add new branch (y/n) ?: ";
		cin >> opt;

		while (opt != 'y' && opt != 'Y' && opt != 'n' && opt != 'N')
		{
			cout << "Error! Please insert again: ";
			cin >> opt;
		}
		cout << "_______________________________________________________________________________________________";
		cout << endl;
		if (opt == 'y' || opt == 'Y')
		{
			cout << "Insert Branch name: ";
			cin >> branch;
			cout << "How many item you want to insert?: ";
			cin >> item;
			cout << "-----------------------------------------------------------------------------------------------";
		}
		cout << endl;
	}


	return 0;
}