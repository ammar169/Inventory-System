//This program is for the manager to record the sales in a day.
#include <iostream>
#include <string>
#include <cstring>
#include "Time.h"
#include "Sales.h"
#include "Stock.h"
using namespace std;

int main() {
	Sales a;
	Time t;
	t.printTime();
	
	string branch[3] = { "Skudau", "Pokok Sena", "Besut" };
	//each of these item and its info will be recorded in each of the branch
	string product_name[3] = { "Tooth Brush", "Sabun Mandi", "Ubat Gigi" };
	string category[3] = { "Bath Toiletries","Bath Toiletries","Bath Toiletries" };
	string code[3] = { "A18CS0116","A18CS0117","A18CS0118" };
	double price[3] = { 2.90, 10.55, 4.00 };
	unsigned int amount[3] = { 30, 20, 40 };

	for (int i = 0; i < 3; i++) {
		a.setBranch(branch[i]);
		for (int j = 0; j < 3; j++) {
			a.setName(product_name[j]);
			a.setCateg(category[j]);
			a.setCode(code[j]);
			a.setPrice(price[j]);
			a.setAmount(amount[j]);
			a.recordSales();
		}
	}

	return 0;
}
