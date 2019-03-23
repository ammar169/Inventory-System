//This program is for the manager to record the sales in a day.
#include <iostream>
#include <string>
#include <ctime>
#include "Sales.h"
using namespace std;

int main() {
	string	product_name;
	char	category[50];
	double	price;
	int		code[8];
	int		amount;
	int		date	= 1;	//To hold current date
	int		month	= 1;	//To hold current month
	int		year	= 1900; //To hold current year

	Sales a;
	//Print current date
	a.currentDate();
	
	//Promt user to insert the numbers of sales they want to store
	int count;
	cout << "How many sales record you want to key in: ";
	cin >> count;
	cout << endl;

	for (int i = 0; i != 'x' || i != 'X'; i++) {
		for (int j = 0; j < count; j++) {
			cout << "|::::::::::|:::::::::|::::::::::|::::::::::|::::::::::|::::::::::|" << endl;
			cout << endl;
			cout << "\tProduct " << i + 1 << "name\t: ";
			cin >> product_name;
			cout << endl;
			cout << "\tProduct" << i + 1 << "Reference No.\t: ";
			cin >> code[8];
			cout << endl;
			cout << "\tProduct" << i + 1 << "Price (per unit)\t: ";
			cin >> price;
			cout << endl;
			cout << "\tProduct" << i + 1 << "Amount\t: ";
			cin >> amount;
			cout << endl;
			cout << "\tProduct" << i + 1 << "Category\t: ";
			cin >> category;
			cout << endl;
			cout << "|::::::::::|:::::::::|::::::::::|::::::::::|::::::::::|::::::::::|" << endl;
		}
		char choice;
		cout << "Do you want to add more? (Y/N) --> ";
		cin >> choice;
		if (choice == 'y' || choice == 'Y') {
			cout << "How many sales record you want to key in: ";
			cin >> count;
			cout << endl;
		}
		else if (choice == 'n' || choice == 'N')
			break;
	}

	return 0;
}
