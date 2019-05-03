//Header files that contain Stock Record class
#ifndef _STOCK_H //If Stock.h is not included
#define _STOCK_H //define this so that compiler know it has been included
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Sales.h"

class Stock {
	int available;
	int reorder_point;
	double inventory_value;
	int row;
public:
	/*Stock() :sale(NULL), available(0), reorder_point(0), inventory_value(0) {}*/
	Stock(int a = 0, int rp = 0, double iv = 0, int r = 0) :available(a), reorder_point(rp), inventory_value(iv), row(r) {}

	void updateStock(Sales sale);
	void displayRecord(Sales sale);
};

#endif // !STOCK_H
