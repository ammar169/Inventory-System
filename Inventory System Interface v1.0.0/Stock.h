//Header files that contain Stock Record class
#ifndef _STOCK_H //If Stock.h is not included
#define _STOCK_H //define this so that compiler know it has been included
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Sales.h"

#define MAX_SIZE 16382

class Stock {
	Sales sale;
	std::string* product_name;
	std::string* category;
	std::string* price;
	std::string* code;
	std::string* available;
	std::string* reorder_point;
	std::string* inventory_value;
	/*int available;
	int reorder_point;
	double inventory_value;*/
	int row;
public:
	/*Stock() :sale(NULL), available(0), reorder_point(0), inventory_value(0) {}*/
	/*Stock(int a = 0, int rp = 0, double iv = 0, int r = 0) :available(a), reorder_point(rp), inventory_value(iv), row(r) {}*/
	Stock() :product_name(0), category(0), price(0), code(0), available(0), reorder_point(0), inventory_value(0), row(0) {}
	Stock(std::string* pn, std::string* ct, std::string* cd, std::string* p, std::string* a, std::string* rp, std::string* iv, int r = 0)
		:product_name(pn), category(ct), price(p), code(cd), available(a), reorder_point(rp), inventory_value(iv), row(r) {}
	~Stock() {
		delete[] product_name;
		delete[] category;
		delete[] price;
		delete[] code;
		delete[] available;
		delete[] reorder_point;
		delete[] inventory_value;
	}

	void readFile(Sales sale);
	void updateStock(Sales sale);
	void displayRecord(Sales sale);
	void addNewItem();
};

#endif // !STOCK_H
