//Header files that contain Sales Record class
#ifndef _SALES_H //If Sales.h is not included
#define _SALES_H //define this so that compiler know it has been included
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "Time.h"

#define MAX_SIZE 16382

class Sales {
	Time t;
	std::string* branch;
	std::string* product_name;
	std::string* category;
	std::string* code;
	std::string* price;
	std::string* amount;
	std::string* _value;
	int iteration;
public:
	Sales() :branch(0), product_name(0), category(0), code(0), price(0), amount(0), _value(0), iteration(0) {}
	Sales(std::string* b, std::string* p_n, std::string* ctg, std::string* cd, std::string* p, std::string* a,std::string* v, int i)
		:branch(b), product_name(p_n), category(ctg), code(cd), price(p), amount(a),_value(v), iteration(i) {}
	~Sales() {
		delete[] branch;
		delete[] product_name;
		delete[] category;
		delete[] code;
		delete[] price;
		delete[] amount;
		delete[] _value;
	}

	void readSales(std::string _branch, int date, int month, int year);
	void recordSales(std::string branch);
	void printSales();
	void setBranch(std::string* b) {
		branch = b;
	}
	void setName(std::string* name) { 
		product_name = name;
	}
	void setCateg(std::string* categ) {
		category = categ;
	}
	void setCode(std::string* c) {
		code = c;
	}
	void setPrice(std::string* p) {
		price = p;
	}
	void setAmount(std::string* a) {
		amount = a;
	}
	std::string* getBranch() {
		return branch;
	}
	std::string* getName() {
		return product_name;
	}
	std::string* getCateg() {
		return category;
	}
	std::string* getCode() {
		return code;
	}
	std::string* getPrice() {
		return price;
	}
	std::string* getAmount() {
		return amount;
	}
};

#endif // !SALES_H