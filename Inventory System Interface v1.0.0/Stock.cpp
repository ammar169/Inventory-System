//This program are the implementation of the constructors and function definition
//in Stock.h file
#include "Stock.h"
#define FILENAME "StockRecords.csv"

//Accept some data from class Sales
Stock::Stock(const Sales& sales) {
	product_name = sales.product_name;	std::cout << product_name << std::endl;
	code = sales.code;	std::cout << code << std::endl;
	price = sales.price;	std::cout << price << std::endl;
	amount = sales.amount;	std::cout << amount << std::endl;
	category = sales.category;	std::cout << category << std::endl;
}
//This class will update the Stock record based on the input of Sales record
void Stock::updateStock() {
	std::fstream File(FILENAME, std::ios::in);



	File.close();
}

void Stock::recordStock() {
	std::fstream File(FILENAME, std::ios::out);
	File << product_name << "," << category << "," << price << "," << code << "," << amount << std::endl;

	File.close();
}