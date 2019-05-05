//This program are the implementation of the constructors and/or function definition
//in Sales.h file
#include "Sales.h"
#include "Stock.h"

void Sales::readSales(std::string _branch, int date, int month, int year) {
	branch = new std::string[MAX_SIZE];
	product_name = new std::string[MAX_SIZE];
	category = new std::string[MAX_SIZE];
	code = new std::string[MAX_SIZE];
	price = new std::string[MAX_SIZE];
	amount = new std::string[MAX_SIZE];
	_value = new std::string[MAX_SIZE];
	//To create name based on branch and date
	char m[12][10] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
	std::string filename = _branch + std::to_string(date) + static_cast<std::string>(m[month - 1]) + std::to_string(year) + ".csv";;

	std::ifstream iFile(filename);

	//To store all the available data from the csv file into the respective variable
	//variable 'row' are to hold the number of iteration as well as to count the number of row (lines) in the csv file
	for (iteration = 0; getline(iFile, product_name[iteration], ','); iteration++) {
		getline(iFile, category[iteration], ',');
		getline(iFile, code[iteration], ',');
		getline(iFile, price[iteration], ',');
		getline(iFile, amount[iteration], ',');
		getline(iFile, _value[iteration], '\n');
	}

	iFile.close();
}

//To record sales in a file
void Sales::recordSales(std::string branch) {
	Stock stock;
	stock.readFile(branch);
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

	

	for (int i = 0; i < stock.getRow(); i++) {
		if ((*code) == stock.getCode()[i]) {
			double value = stod(stock.getPrice()[i]) * stod(*amount);
			ofile << stock.getName()[i] << "," << stock.getCateg()[i] << "," << (*code) << "," 
				<< stock.getPrice()[i] << "," << (*amount) << "," << value << std::endl;
		}
	}

	std::cout << "Today's sales successfully recorded in " << file_name << " files." << std::endl;

	ofile.close();
}

//To print the record based on branch and date
void Sales::printSales() {
	//To display the current data in csv file based on the its type
	std::cout << std::left << std::setw(40) << "Product Name" << std::left << std::setw(30)
		<< "Category"<< std::left << std::setw(15) << "Product Code"  << std::left << std::setw(25) 
		<< "Price per unit (RM)" << std::left << std::setw(20) << "Available Product" << std::left << std::setw(15) 
		<< "Inventory Value (RM)" << std::endl;
	//To create a divider (-) by appending the '-' 170 times
	std::string divider;
	std::cout << divider.append(140u, '-') << std::endl;
	//To display the data row by row based on its category (column)
	for (int i = 0; i < iteration; i++) {
		std::cout << std::left << std::setw(40) << product_name[i] << std::left << std::setw(30)
			<< category[i] << std::left << std::setw(15) << std::left << std::setw(15) << code[i]  
			<< std::fixed << std::setprecision(2) << price[i]<< std::left << std::setw(20) << amount[i] << std::left << std::setw(20)
			<< _value[i] << std::endl;
	}
}