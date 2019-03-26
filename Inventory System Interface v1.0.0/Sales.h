//Header files that contain Sales Record class
#ifndef _SALES_H //If Sales.h is not included
#define _SALES_H //define this so that compiler know it has been included
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "Stock.h"

class Sales {
	std::string	product_name;
	std::string	category;
	double price;
	int	code;
	int	amount;
	int	date; //To hold current date
	int	month; //To hold current month
	int	year; //To hold current year
public:
	//Default constructor
	Sales(double price = 0, int amount = 0, int date = 1, int month = 1, int year = 1900){}
	//Constructor that receive parameter from main function
	Sales(std::string,std::string, double, int, int);
	
	//To get current date
	void currentDate();
	//To record sales in files
	friend std::ofstream& operator<<(std::ofstream& in, const Sales& sales);
	//Allow class Stock in Stoch.h file to access the private member of this class (Sales class)
	friend class Stock;
};

#endif // !SALES_H
