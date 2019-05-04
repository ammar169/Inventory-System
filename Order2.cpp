//This program are the implementation of the constructors and/or function definition
//in Order.h file
#include "Order.h"

Order(std::string* cn, std::string* pc, std::string* a, std::string* p, std::string* iv, int r = 0)
		:company_name(cn), product_code(pc), amount(a), price(p), row(r) 
{
		
}
	
void Order::readFile()
{
	company_name = new std::string[MAX_SIZE];
	product_code = new std::string[MAX_SIZE];
	amount = new std::string[MAX_SIZE];
	price = new std::string[MAX_SIZE];

	//To create file name based on the branch name
	std::string filename = stock.getBranch() + "Supplier.csv";

	//To read file
	std::ifstream iFile(Supplier.csv);

	if (!iFile.is_open()) {
		std::cout << "Warnings!!! Error opening file..." << std::endl;
		return;
	}

	//To store all the available data from the csv file into the respective variable
	//variable 'row' are to hold the number of iteration as well as to count the number of row (lines) in the csv file
	/*int row;*/
	for (row = 0; getline(iFile, company_name[row], ','); row++) {
		getline(iFile, product_code[row], ',');
		getline(iFile, amount[row], ',');
		getline(iFile, price[row], ',');
	}

	iFile.close();
}

void Order::updateStock(Stock stock)
{
	
}

void Order::displayRecord(Stock stock)
{
	std::cout << std::left << std::setw(40)  << "Company Name" << std::left << std::setw(30) 
		<< "Product Code" << std::left << std::setw(25) << "Amount" << std::left << std::setw(15)
		<< "Price per unit (RM)" << std::endl;
	//To create a divider (-) by appending the '-' 170 times
	std::string divider;
	std::cout << divider.append(170u, '-') << std::endl;
	//To display the data row by row based on its category (column)
	for (int i = 0; i < row; i++) {
		std::cout << std::left << std::setw(40) << company_name[i] << std::left << std::setw(30) 
			<< product_code[i] << std::left << std::setw(25) << std::fixed << std::setprecision(2) << amount[i] << std::left << std::setw(15)
			<< price[i] << std::endl;
	}
}

void Order::addNewCompany()
{
	
}

