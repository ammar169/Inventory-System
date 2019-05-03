//This program is for the manager to record the sales in a day.
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include "Time.h"
#include "Sales.h"
#include "Stock.h"
using namespace std;

int main() {
	Time time;
	Sales sales;
	Stock stock;
	time.printTime();
	
	string branch[3] = { "Skudau" };
	//each of these item and its info will be recorded in each of the branch
	string product_name[3] = { "Toothbrush" };
	string category[3] = { "Bath Toiletries" };
	string code[3] = { "BE0001BT0001" };
	double price[3] = { 2.90 };
	unsigned int amount[3] = { 30 };

	for (int i = 0; i < 1; i++) {
		sales.setBranch(branch[i]);
		for (int j = 0; j < 1; j++) {
			sales.setName(product_name[j]);
			sales.setCateg(category[j]);
			sales.setCode(code[j]);
			sales.setPrice(price[j]);
			sales.setAmount(amount[j]);
			sales.recordSales();
		}
	}

	stock.readFile(sales);
	stock.displayRecord(sales);
	stock.updateStock(sales);
	stock.readFile(sales);
	stock.displayRecord(sales);

	return 0;
}