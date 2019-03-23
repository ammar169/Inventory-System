//This program is for the manager to record the sales.
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
	int		date	= 1; //To hold current date
	int		month	= 1; //To hold current month
	int		year	= 1900; //To hold current year

	//To get current time
	time_t	Time;
	tm*		time_now;

	char d[7][10]	= { "Sunday","Monday","Teusday","Wednesday","Thursday","Friday","Saturday" };
	char m[12][10]	= { "January","February","March","April","May","June","July","August","September","October","November","December" };

	time(&Time);
	time_now = localtime(&Time);

	date	= time_now->tm_mday;			cout << "Date: " << date << endl;
	month	= time_now->tm_mon;				cout << "Month: " << month << endl;
	year	= 1900 + time_now->tm_year;		cout << "Year: " << year << endl;

	//Shows the current date
	cout << "Today's date: " << date << " " << m[month] << " " << year << endl;

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
