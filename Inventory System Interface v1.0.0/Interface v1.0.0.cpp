//This program is for the manager to record the sales in a day.
#include <iostream>
#include <string>
#include <cstring>
#include "Time.h"
#include "Sales.h"
#include "Stock.h"
using namespace std;

int main() {
	string product_name;
	string category;
	string code;
	double price;
	unsigned int amount;

	Time t;

	Sales a("Berus Gigi", "Alatan Mandi", "A18CS0116", 2.90, 30, t.getDate(), t.getMonth(), t.getYear());
	a.recordSales();
	Stock s(a);
	s.recordStock();

	return 0;
}
