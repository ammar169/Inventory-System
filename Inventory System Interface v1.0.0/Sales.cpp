//This program are the implementation of the constructors and function definition
//in Sales.h file
#include "Sales.h"

//To record sales in a file
void Sales::recordSales()
{
	char m[12][10] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
	std::string file_name;
	file_name = std::to_string(date) + static_cast<std::string>(m[month]) + std::to_string(year) + ".csv";	//To create a string of name based on the date
	//std::cout << file_name << std::endl;
	
	std::ofstream ofile(file_name.c_str());
	if (!ofile.is_open()) {
		std::cout << "Warnings!!!!!!!" << std::endl;
	}
	ofile << product_name << "," << category << "," << price << "," << code << "," << amount << std::endl;

	ofile.close();
}