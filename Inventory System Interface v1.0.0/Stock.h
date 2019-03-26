//This header file contain Stock Record
#ifndef _STOCK_H //If Sales.h is not included
#define _STOCK_H //define this so that compiler know it has been included
#include <iostream>
#include <string>
#include <fstream>
#include "Sales.h"

class Stock {
	std::string	product_name;
	std::string	category;
	int	reference_no;
	int	amount;
	int	available;
	double price_per_unit;
	int	inventory_value;
	int	reorder_point;
	int	order_quatity;
public:
	//Default constructor
	Stock(){}
	//Constructor that access the private member of class Sales in Sales.h file
	Stock(const Sales& sales);
};

#endif // !STOCK_H
