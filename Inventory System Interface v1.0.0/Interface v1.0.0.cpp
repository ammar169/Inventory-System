//This program is for the manager to record the sales in a day.
#include <iostream>
#include <string>
#include <cstring>
#include "Sales.h"
#include "Stock.h"
using namespace std;

int main() {
	string product_name;
	string category;
	double price;
	char code[50];
	unsigned int amount;

	Sales a;
	a.currentDate();	//Print current date

	cout << "\tProduct name: ";
	getline(cin, product_name);
	cout << "\tProduct Category: ";
	getline(cin, category);
	cout << "\tProduct Reference No.: ";
	cin >> code;	
	cout << "\tProduct Price (per unit): ";
	cin >> price; 
	cout << "\tProduct Amount: ";
	cin >> amount; 

	Sales b(product_name, price, code, amount, category);
	b.storeSales();

	return 0;
}
