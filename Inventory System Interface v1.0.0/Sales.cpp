//This program are the implementation of the constructors and function definition
//in Sales.h file
#include "Sales.h"

//This constructor will receive and store the input from main in private members.
Sales::Sales(std::string product_name, double price, char code[], unsigned int amount, std::string category) {
	this->product_name = product_name;
	this->price	= price;
	for (int i = 0; i < 50; i++)
		this->code[i] = code[i];
	this->amount = amount;
	this->category = category;
}
//To get current time
void Sales::currentDate() {
	time_t Time;
	tm* time_now;

	char d[7][10] = { "Sunday","Monday","Teusday","Wednesday","Thursday","Friday","Saturday" };
	char m[12][10] = { "January","February","March","April","May","June","July","August","September","October","November","December" };

	//To get the local current time
	time(&Time);
	time_now = localtime(&Time);

	date = time_now->tm_mday;				//std::cout << "Date: " << date << std::endl;
	month = time_now->tm_mon;				//std::cout << "Month: " << month << std::endl;
	year = 1900 + time_now->tm_year;		//std::cout << "Year: " << year << std::endl;

	//Shows the current date
	std::cout << "Today's date: " << date << " " << m[month] << " " << year << std::endl;
}
//To record sales in a file
void Sales::storeSales() {
	const char m[12][10] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
	std::string file_name; 
	file_name = std::to_string(date) + static_cast<std::string>(m[month]) + std::to_string(year) + ".txt";	//To create a string of name based on the date

	std::fstream outFile(file_name, std::ostream::out | std::ostream::app);	//To open a file named based on the date
	outFile << product_name << " " << code << " " << category << " " << price << " " << amount << std::endl;
	outFile.close();
}