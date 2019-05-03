//This program are the implementation of the constructors and/or function definition
//in Sales.h file
#include "Sales.h"

//To record sales in a file
void Sales::recordSales() {
	Time t;
	char m[12][10] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
	
	//To create a string of name based on the date
	std::string file_name;
	file_name = branch + std::to_string(t.getDate()) + static_cast<std::string>(m[t.getMonth()]) + std::to_string(t.getYear()) + ".csv";	
	/*std::cout << file_name << std::endl;*/
	
	//each input will be append to the new lines (new row)
	std::ofstream ofile(file_name, std::ofstream::app);
	if (!ofile.is_open()) {
		std::cout << "Warnings!!! Error opening file..." << std::endl;
		return;
	}

	ofile << product_name << "," << category << "," << price << "," << code << "," << amount << std::endl;

	std::cout << "Today's sales successfully recorded in " << file_name << " files." << std::endl;

	ofile.close();
}