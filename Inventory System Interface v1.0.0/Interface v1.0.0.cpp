//This program is for the manager to record the sales in a day.
#include <iostream>
#include <string>
#include <ctime>
#include "Sales.h"
#include "Stock.h"
using namespace std;

int main() {
	string product_name[] = { " " };
	string category[] = { " " };
	double price[] = { 0 };
	int	code[] = { 0 };
	int	amount[] = { 0 };
	
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
			cin >> product_name[j];
			cout << "\tProduct Reference No.\t: ";
			cin >> code[j];
			cout << "\tProduct Price (per unit)\t: ";
			cin >> price[j];
			cout << "\tProduct Amount\t: ";
			cin >> amount[j];
			cout << "\tProduct Category\t: ";
			cin >> category[j];
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

	for (int i = 0; i < count; i++) {
		//Pass the value to the Sales constructor
		Sales b(product_name[i], category[i], price[i], code[i], amount[i]);
	}

	return 0;
}
