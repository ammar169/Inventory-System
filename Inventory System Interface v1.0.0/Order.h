//Header files that contain Stock Reorder class
#ifndef _ORDER_H //If Order.h is not included
#define _ORDER_H //define this so that compiler know it has been included
#include <iostream>
#include <string>
#include <fstream>
#include "Stock.h"

#define MAX_SIZE 16382

class Order :public Stock {
	std::string* supplier;
	std::string* item_code;
	std::string* order_amount;
	std::string* item_price;
	int line;
public:
	Order() :supplier(0), item_code(0), order_amount(0), item_price(0), line(0) {}
	Order(std::string* s, std::string* ic, std::string* oa, std::string* ip, int l) 
		:supplier(s), item_code(ic), order_amount(oa), item_price(ip), line(l) {}
	~Order() {
		delete[] supplier;
		delete[] item_code;
		delete[] order_amount;
		delete[] item_price;
	}

	void read_File();
	void displaySupplier();
};

#endif // !ORDER_H