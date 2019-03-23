#include "Sales.h"

Sales::Sales(char catg[] = 0, double pri = 0.0, int cod[] = 0, int amo = 0) {
	if(int i = 0; i < 50; i++)
		category[i] = catg[i]; 
	price = pri; 
	code = cod;
	amount = amo;
}

Sales::Sales(int d = 0, int m = 0, int y = 0) {
	date = d;
	month = m;
	year = y;
}