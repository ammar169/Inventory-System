//This program are the implementation of the constructors and function definition
//in Sales.h file
#include "Sales.h"

//This constructor will receive and store the input from main in private members.
Sales::Sales(double price, int amount, int date, int month, int year) {
	this->product_name = product_name;
	this->category = category;
	this->price = price;
	this->code = code;
	this->amount = amount;
	this->date = date;
	this->month = month;
	this->year = year;
}

Sales::Sales(const Sales &obj)
{
	product_name = obj.product_name;
	category = obj.category;
	price = obj.price;
	code = obj.code;
	amount = obj.amount;
	date = obj.date;
	month = obj.month;
	year = obj.year;
}

//To get current time
void Sales::currentDate() {
	time_t	Time;
	tm*		time_now;

	char d[7][10]	= { "Sunday","Monday","Teusday","Wednesday","Thursday","Friday","Saturday" };
	char m[12][10]	= { "January","February","March","April","May","June","July","August","September","October","November","December" };

	//To get the local current time
	time(&Time);
	time_now = localtime(&Time);

	date	= time_now->tm_mday;				//std::cout << "Date: " << date << std::endl;
	month	= time_now->tm_mon;					//std::cout << "Month: " << month << std::endl;
	year	= 1900 + time_now->tm_year;			//std::cout << "Year: " << year << std::endl;

	//Shows the current date
	std::cout << "Today's date: " << date << " " << m[month] << " " << year << std::endl;
}
void Sales::recordSales()
{
	std::string fname;

	std::cout << "Insert file name: ";
	std::cin >> fname;

	fname += ".txt";

	std::ofstream ofile;

	ofile.open(fname.c_str());

	ofile << "Date: " << date << "/" << month << "/" << year << std::endl 
		  << product_name << " | " << category << " | " << price << "(MYR)\n  | " << code << " | " << amount << std::endl << std::endl;

	ofile.close();
}