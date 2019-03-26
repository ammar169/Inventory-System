//This program are the implementation of the constructors and function definition
//in Sales.h file
#include "Sales.h"

//This constructor will receive and store the input from main in private members.
Sales::Sales(std::string product_name, std::string category, double price, int code, int amount) {
	this->product_name = product_name;
	this->category = category;
	this->price	= price;
	this->code = code;
	this->amount = amount;
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
	month = time_now->tm_mon;					//std::cout << "Month: " << month << std::endl;
	year = 1900 + time_now->tm_year;			//std::cout << "Year: " << year << std::endl;

	//Shows the current date
	std::cout << "Today's date: " << date << " " << m[month] << " " << year << std::endl;
}
//To record sales in a file
std::ofstream& operator<<(std::ofstream& in, const Sales& sales) {
	const char m[12][10] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
	//String type variable to hold the file name based on the date
	std::string file_name; 
	//To create a string of name based on the date
	file_name = std::to_string(sales.date) + static_cast<std::string>(m[sales.month]) + std::to_string(sales.year) + ".txt";

	//To open a file named based on the date
	in.open(file_name, std::ostream::out | std::ostream::app);

	in << sales.product_name << " " << sales.code << " " << sales.category << " " << sales.price << " " << sales.amount << std::endl;
	
	in.close();
	return in;
}