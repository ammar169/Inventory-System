//Header files that contain Sales Record class
#ifndef _SALES_H //If Sales.h is not included
#define _SALES_H //define this so that compiler know it has been included
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "Stock.h"

class Sales {
	std::string product_name;
	std::string category;
	std::string code;
	double price;
	unsigned int amount;
	int	date = 1; //To hold current date
	int	month = 0; //To hold current month
	int	year = 1900; //To hold current year
public:
	Sales(std::string p_n = "", std::string ctg = "", std::string cd = "", double p = 0, unsigned int a = 0, int d = 1, int m = 0, int y = 1900) :
		product_name(p_n), category(ctg), code(cd), price(p), amount(a), date(d), month(m), year(y) {}	//Constructor that receive parameter from main function

	void recordSales();	//To record sales in files
	friend class Stock;
};

#endif // !SALES_H
