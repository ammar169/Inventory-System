//Header files that contain Sales Record class
#ifndef _SALES_H //If Sales.h is not included
#define _SALES_H //define this so that compiler know it has been included
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstring>
#include "Stock.h"

class Sales {
	std::string product_name;
	std::string category;
	double price;
	char code[50];
	unsigned int amount;
	int	date; //To hold current date
	int	month; //To hold current month
	int	year; //To hold current year
public:
	Sales(char code = 0, double price = 0, unsigned int amount = 0, int date = 1, int month = 1, int year = 1900) {}	//Default constructor
	Sales(std::string, double, char[], unsigned int, std::string);	//Constructor that receive parameter from main function
	
	void currentDate();	//To get current date
	void storeSales();	//To record sales in files
	friend class Stock;	//Allow class Stock in Stoch.h file to access the private member of this class (Sales class)
};

#endif // !SALES_H
