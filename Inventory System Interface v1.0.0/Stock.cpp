//This program are the implementation of the constructors and function definition
//in Stock.h file
#include "Stock.h"

//Accept some data from class Sales
Stock::Stock(const Sales& sales) {
	this->product_name = sales.product_name;
	this->reference_no = sales.code;
	this->price_per_unit = sales.price;
	this->amount = sales.amount;
	this->category = sales.category;
}