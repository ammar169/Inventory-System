//This program are the implementation of the constructors and function definition
//in Sales.h file
#include "Sales.h"

//This constructor will receive and store the input from main in private members.
Sales::Sales(char category[] = 0, double price = 0, int code[] = 0, int amount = 0, int date = 1, int month = 1, int year = 1900) {
	this->product_name = product_name;
	for (int i = 0; i < 50; i++) 
		this->category[i] = category[i];
	this->price = price;
	this->code[8] = code[8];
	this->amount = amount;
	this->date = date;
	this->month = month;
	this->year = year;
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