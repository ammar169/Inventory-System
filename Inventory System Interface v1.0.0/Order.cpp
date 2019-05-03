//This program are the implementation of the constructors and/or function definition
//in Order.h file
#include "Order.h"

//To read the Supplier.csv file and store it in the 
//respective variable
void Order::read_File() {
	supplier = new std::string[MAX_SIZE];
	item_code = new std::string[MAX_SIZE];
	order_amount = new std::string[MAX_SIZE];
	item_price = new std::string[MAX_SIZE];

	std::ifstream iFile("Supplier.csv");

	if (!iFile.is_open()) {
		std::cout << "Warnings!!! Error opening file..." << std::endl;
		return;
	}

	//To store the data in csv file into
	//the respective variable
	for (line = 0; getline(iFile, supplier[line], ','); line++) {
		getline(iFile, item_code[line], ',');
		getline(iFile, order_amount[line], ',');
		getline(iFile, item_price[line], '\n');
	}

	iFile.close();
}

//To display data that being read (stored in the private)
void Order::displaySupplier() {
	std::cout << std::left << std::setw(40) << "Supplier Company Name" << std::left << std::setw(15)
		<< "Product Code" << std::left << std::setw(15) << "Amount" << std::left << std::setw(20) << "Price per Unit (RM)" << std::endl;
	
	std::string divider;
	std::cout << divider.append(90u, '-') << std::endl;

	for (int i = 0; i < line; i++) {
		std::cout << std::left << std::setw(40) << supplier[i] << std::left << std::setw(15)<< item_code[i] << std::left << std::setw(15) 
			<< order_amount[i] << std::left << std::setw(20) << std::fixed << std::setprecision(2) << item_price[i] << std::endl;
	}
}