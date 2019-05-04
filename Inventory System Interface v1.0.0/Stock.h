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
protected:
	Sales sale;
	std::string* product_name;
	std::string* category;
	std::string* price;
	std::string* code;
	std::string* available;
	std::string* reorder_point;
	std::string* inventory_value;
	int row;
public:
	Stock() :product_name(0), category(0), price(0), code(0), available(0), reorder_point(0), inventory_value(0), row(0) {}
	Stock(std::string* pn, std::string* ct, std::string* cd, std::string* p, std::string* a, std::string* rp, std::string* iv, int r)
		:product_name(pn), category(ct), price(p), code(cd), available(a), reorder_point(rp), inventory_value(iv), row(0) {}
	~Stock() {
		delete[] product_name;
		delete[] category;
		delete[] price;
		delete[] code;
		delete[] available;
		delete[] reorder_point;
		delete[] inventory_value;
	}

	void readFile(std::string branch);
	void updateStock(Sales sale);
	void displayRecord();
	void addNewItem(std::string branch);
	void deleteItem(int index);
	
	void setName(std::string* name) {
		product_name = name;
	}
	void setCateg(std::string* categ) {
		category = categ;
	}
	void setPrice(std::string* p) {
		price = p;
	}
	void setCode(std::string* c) {
		code = c;
	}
	void setAmount(std::string* a) {
		available = a;
	}
	void setReorder(std::string* rp) {
		reorder_point = rp;
	}
	void setInvent(std::string* iv) {
		inventory_value = iv;
	}
};

#endif // !STOCK_H
