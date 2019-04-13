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
	std::string code;
	double price;
	unsigned int amount;
	unsigned int available;
	unsigned int inventory_value;
	unsigned int reorder_point;
	unsigned int order_quantity;
public:
	friend class Time;
	friend class Sales;

	Stock() {}	//Default constructor
	Stock(const Sales&);	//Constructor that access the private member of class Sales in Sales.h file

	void recordStock();
};

#endif // !STOCK_H
