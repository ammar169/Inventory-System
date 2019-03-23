//This program is for the manager to record the sales.
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int main() {
	string product_name;
	char category[100];
	char date[7][10] = { "Sunday","Monday","Teusday","Wednesday","Thursday","Friday","Saturday" };
	char month[12][10] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
	double price;
	int code[8]; 
	int item; 
	int amount; 
	int year[4];
	int day[31];

	cout << "Today's date: ";


	for (int i = 0; i != 'x' || i != 'X'; i++) {
		cout << endl;
		cout << "\tProduct name\t: ";
		cin >> product_name;
		cout << endl;
		cout << "\tProduct Reference No.\t: ";
		cin >> code[8];
		cout << endl;
		cout << "\tProduct Price (per unit)\t: ";
		cin >> price;
		cout << endl;
		cout << "\tProduct Amount\t: ";
		cin >> amount;
		cout << endl;
		cout << "\tProduct Category\t: ";
		cin >> category;
		cout << endl;
	}

	return 0;
}
