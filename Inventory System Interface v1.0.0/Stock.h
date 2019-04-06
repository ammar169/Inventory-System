//This header file contain Stock Record
#ifndef _STOCK_H //If Sales.h is not included
#define _STOCK_H //define this so that compiler know it has been included
#include <iostream>
#include <string>
#include <fstream>
#include "Sales.h"

class Stock {
	std::string product_name;
	std::string category;
	double price;
	char code[50];
	unsigned int amount;
	unsigned int available;
	unsigned int inventory_value;
	unsigned int reorder_point;
	unsigned int order_quatity;
public:
	Stock() {}	//Default constructor
	Stock(const Sales& sales);	//Constructor that access the private member of class Sales in Sales.h file
	
	friend class Sales;
};

#endif // !STOCK_H
