#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;


class Sales {
	std::string	product_name;
	std::string category;
	double price;
	int	code;
	int	amount;
	int	date; //To hold current date
	int	month; //To hold current month
	int	year; //To hold current year
public:
	//Default constructor
	Sales(double price = 0, int amount = 0, int date = 1, int month = 1, int year = 1900);
	Sales(const Sales &obj);
	void setProduct_name(string pname) {product_name=pname;}
	string getProduct_name() {return product_name;}
	void setCategory(string c) {category=c;}
	string getCategory() {return category;}
	void setPrice(double p) {price=p;}
	double getPrice() {return price;}
	void setCode(int co){code=co;}
	int getCode() {return code;}
	void setAmount(int a) {amount=a;}
	int getAmount() {return amount;}
	void setDate(int d) {date=d;}
	int getDate() {return date;}
	void setMonth(int m) {month=m;}
	int getMonth() {return month;}
	void setYear(int y) {year=y;}
	int getYear() {return year;}

	void recordSales();
	void currentDate();
};
//This constructor will receive and store the input from main in private members.
Sales::Sales(double price, int amount, int date, int month, int year) {
	this->product_name = product_name;
	this->category = category;
	this->price = price;
	this->code = code;
	this->amount = amount;
	this->date = date;
	this->month = month;
	this->year = year;
}

Sales::Sales(const Sales &obj)
{
	product_name = obj.product_name;
	category = obj.category;
	price = obj.price;
	code = obj.code;
	amount = obj.amount;
	date = obj.date;
	month = obj.month;
	year = obj.year;
}

//To get current time
void Sales::currentDate() {
	time_t	Time;
	tm*		time_now;

	char d[7][10]	= { "Sunday","Monday","Teusday","Wednesday","Thursday","Friday","Saturday" };
	char m[12][10]	= { "January","February","March","April","May","June","July","August","September","October","November","December" };

	//To get the local current time
	time(&Time);
	time_now = localtime(&Time);

	date	= time_now->tm_mday;				//std::cout << "Date: " << date << std::endl;
	month	= time_now->tm_mon;					//std::cout << "Month: " << month << std::endl;
	year	= 1900 + time_now->tm_year;			//std::cout << "Year: " << year << std::endl;

	//Shows the current date
	std::cout << "Today's date: " << date << " " << m[month] << " " << year << std::endl;
}
void Sales::recordSales()
{
	std::string fname;

	std::cout << "Insert file name: ";
	std::cin >> fname;

	fname += ".txt";

	std::ofstream ofile;

	ofile.open(fname.c_str());

	ofile << "Date: " << date << "/" << month << "/" << year << std::endl 
		  << product_name << " | " << category << " | " << price << "(MYR)\n  | " << code << " | " << amount << std::endl << std::endl;

	ofile.close();
}
int main() 
{
	string	product_name;
	string	category;
	double	price;
	int	code;
	int	amount;
	int	date	= 1;	//To hold current date
	int	month	= 1;	//To hold current month
	int	year	= 1900; //To hold current year

	Sales a;
	//Print current date
	a.currentDate();
	
	//Promt user to insert the numbers of sales they want to store
	int count;
	cout << "How many sales record you want to key in: ";
	cin >> count;
	cout << endl;

	for (int i = 0; i != 'n' || i != 'N'; i++) {
		int j = 0;
		for (; j < count; j++) {
			cout << "|::::::::::|:::::::::|::::::::::|::::::::::|::::::::::|::::::::::|" << endl;
			cout << endl;
			cout << "\tProduct name\t: ";
			cin >> product_name;
			cout << "\tProduct Reference No.\t: ";
			cin >> code;
			cout << "\tProduct Price (per unit)\t: ";
			cin >> price;
			cout << "\tProduct Amount\t: ";
			cin >> amount;
			cout << "\tProduct Category\t: ";
			cin >> category;
			cout << endl;

			a(product_name.c_str()).setProduct_name();
		}
		//recordSales(product_name, category, price, code, amount);
		char choice;
		cout << "Do you want to add more? (Y/N) --> ";
		cin >> choice;
		if (choice == 'y' || choice == 'Y') {
			cout << "How many sales record you want to key in: ";
			cin >> count;
			cout << endl;
		}
		else if(choice == 'n' || choice == 'N')
			break;
	}

	return 0;
}
