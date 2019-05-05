//This program are the implementation of the constructors and/or function definition
//in Order.h file
#include "Order.h"

//To check the amount to be restock from
//the corresponding supplier
void Order::check(std::string code) {
	Sales sale;
	for (int i = 0; i < line; i++) {
		//Compare item_code with the Sales::code
		if (item_code[i] == sale.getCode()[i]) {
			std::cout << "Amount (Order): " << order_amount[i] << std::endl;
			//Pass the value (store) in the Sales::amount
			sale.setAmount(&order_amount[i]);
			std::cout << "Amount (Order): " << sale.getAmount() << std::endl;
			break;
		}
	}
}

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
	std::cout << "   " << std::left << std::setw(37) << "Supplier Company Name" << std::left << std::setw(15)
		<< "Product Code" << std::left << std::setw(15) << "Amount" << std::left << std::setw(20) << "Price per Unit (RM)" << std::endl;
	
	std::string divider;
	std::cout << divider.append(90u, '-') << std::endl;

	for (int i = 0; i < line; i++) {
		if (i < 9)
			std::cout << i + 1 << "  ";
		else
			std::cout << i + 1 << " ";
		std::cout << std::left << std::setw(37) << supplier[i] << std::left << std::setw(15)<< item_code[i] << std::left << std::setw(15) 
			<< order_amount[i] << std::left << std::setw(20) << std::fixed << std::setprecision(2) << item_price[i] << std::endl;
	}
}

//To add new supplier company into the csv file
void Order::addSupplier() {
	std::ofstream oFile("Supplier.csv", std::ios::app);

	if (!oFile.is_open()) {
		std::cout << "Warnings!!! Error opening file..." << std::endl;
		return;
	}

	oFile << (*supplier) << "," << (*item_code) << "," << (*order_amount) << "," << (*item_price) << std::endl;

	oFile.close();
}

//To delete the data based on the index
void Order::deleteSupplier(int index) {
	std::ofstream oFile("Supplier.csv", std::ios::app);

	if (!oFile.is_open()) {
		std::cout << "Warnings!!! Error opening file..." << std::endl;
		return;
	}

	for (int i = 0; i < line; i++) {
		if (i == (index - 1)) {
			i++;
			oFile << supplier[i] << "," << item_code[i] << "," << order_amount[i] << "," << item_price[i] << std::endl;
		}
		else
			oFile << supplier[i] << "," << item_code[i] << "," << order_amount[i] << "," << item_price[i] << std::endl;
	}

	oFile.close();
}