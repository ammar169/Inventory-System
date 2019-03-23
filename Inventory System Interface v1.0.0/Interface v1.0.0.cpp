//This program is for the manager to record the sales in a day.
#include <iostream>
#include <string>
#include <ctime>
#include "Sales.h"
using namespace std;

int main() {
	string	product_name;
	string	category;
	double	price;
	int	code;
	int	amount;
	int	date	= 1;	//To hold current date
	int	month	= 1;	//To hold current month
	int	year	= 1900; //To hold current year

	Sales a;
	//Print current date
	a.currentDate();
	
	//Promt user to insert the numbers of sales they want to store
	int count;
	cout << "How many sales record you want to key in: ";
	cin >> count;
	cout << endl;

	for (int i = 0; i != 'n' || i != 'N'; i++) {
		int j = 0;
		for (; j < count; j++) {
			cout << "|::::::::::|:::::::::|::::::::::|::::::::::|::::::::::|::::::::::|" << endl;
			cout << endl;
			cout << "\tProduct name\t: ";
			cin >> product_name;
			cout << "\tProduct Reference No.\t: ";
			cin >> code;
			cout << "\tProduct Price (per unit)\t: ";
			cin >> price;
			cout << "\tProduct Amount\t: ";
			cin >> amount;
			cout << "\tProduct Category\t: ";
			cin >> category;
			cout << endl;
		}
		char choice;
		cout << "Do you want to add more? (Y/N) --> ";
		cin >> choice;
		if (choice == 'y' || choice == 'Y') {
			cout << "How many sales record you want to key in: ";
			cin >> count;
			cout << endl;
		}
		else if(choice == 'n' || choice == 'N')
			break;
	}

	return 0;
}
