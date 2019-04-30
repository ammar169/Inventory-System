//Header files that contain Sales Record class
#ifndef _SALES_H //If Sales.h is not included
#define _SALES_H //define this so that compiler know it has been included
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "Stock.h"
#include "Time.h"

class Sales {
	std::string branch;
	std::string product_name;
	std::string category;
	std::string code;
	double price;
	unsigned int amount;
public:
	//Default Constructor that receive parameter from main function
	Sales(std::string b = "", std::string p_n = "", std::string ctg = "", std::string cd = "", double p = 0, unsigned int a = 0) :
		branch(b), product_name(p_n), category(ctg), code(cd), price(p), amount(a) {}	

	void recordSales();
	void setBranch(std::string b) {
		branch = b;
	}
	void setName(std::string name) { 
		product_name = name;
	}
	void setCateg(std::string categ) {
		category = categ;
	}
	void setCode(std::string c) {
		code = c;
	}
	void setPrice(double p) {
		price = p;
	}
	void setAmount(unsigned int a) {
		amount = a;
	}
	std::string getBranch() {
		return branch;
	}
	std::string getName() {
		return product_name;
	}
	std::string getCateg() {
		return category;
	}
	std::string getCode() {
		return code;
	}
	double getPrice() {
		return price;
	}
	unsigned int getAmount() {
		return amount;
	}
};

#endif // !SALES_H
