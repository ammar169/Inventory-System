//Header files that contain Sales Record class
#ifndef _Sales_H //If Sales.h is not included
#define _Sales_H //define this so that compilerknow it has been included

class Sales {
	string	product_name;
	char	category[50];
	double	price;
	int		code[8];
	int		amount;
	int		date = 1; //To hold current date
	int		month = 1; //To hold current month
	int		year = 1900; //To hold current year
public:
	Sales(char, double, int, int);
	Sales(int, int, int);
};

#endif // !Sales.h

