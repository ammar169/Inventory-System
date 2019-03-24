//Header files that contain Sales Record class
#ifndef _SALES_H //If Sales.h is not included
#define _SALES_H //define this so that compiler know it has been included
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

class Sales {
	std::string	product_name;
	std::string category;
	double price;
	int	code[8];
	int	amount;
	int	date; //To hold current date
	int	month; //To hold current month
	int	year; //To hold current year
public:
	//Default constructor
	Sales(double price = 0, int amount = 0, int date = 1, int month = 1, int year = 1900);

	void recordSales();
	void currentDate();
};

#endif // !SALES_H
