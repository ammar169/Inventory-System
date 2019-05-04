#ifndef _ORDER_H //If Order.h is not included
#define _ORDER_H //define this so that compiler know it has been included
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Stock.h"

#define MAX_SIZE 16382

class Order 
{
private:
	std::string* company_name;
	std::string* product_code;
	std::string* amount;
	std::string* price;
	int row;
	
public:
	Order(std::string* cn, std::string* pc, std::string* a, std::string* p, std::string* iv, int r = 0)
		:company_name(cn), product_code(pc), amount(a), price(p), row(r) 
	{
		
	}
	
	~Order() 
	{
		delete[] company_name;
		delete[] product_code;
		delete[] amount;
		delete[] price;
	}

	void readFile(string sale);
	void updateStock(Sales sale);
	void displayRecord(Sales sale);
	void addNewCompany();
};

#endif // !ORDER_H
