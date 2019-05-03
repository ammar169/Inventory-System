//This program is for the manager to record the sales in a day.
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include "Time.h"
#include "Sales.h"
#include "Stock.h"
#include "Order.h"
using namespace std;

#define MAX_SIZE 16382

int main() {
	Time time;
	Sales sales;
	Stock stock;
	Order order;
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
	stock.displayRecord();
	stock.updateStock(sales);
	stock.readFile(sales);
	stock.displayRecord();

	order.read_File();
	order.displaySupplier();

	//Enter new item 
	string _branch[4] = {};
	string* _product_name = new string[MAX_SIZE];
	string* _category = new string[MAX_SIZE];
	string* _price = new string[MAX_SIZE];
	string* _code = new string[MAX_SIZE];
	string* _amount = new string[MAX_SIZE];
	string* _reorder_point = new string[MAX_SIZE];
	string* _inventory_value = new string[MAX_SIZE]; //amount*price

	int num;
	cout << "How many item you want to add? --> ";
	cin >> num;

	for (int i = 0; i < num; i++) {
		cout << "Branch: ";
		cin.ignore();
		getline(cin, _branch[i]);
		cout << "Product name: ";
		getline(cin, _product_name[i]);
		cout << "Category: ";
		getline(cin, _category[i]);
		cout << "Price: ";
		getline(cin, _price[i]);
		cout << "Code: ";
		getline(cin, _code[i]);
		cout << "Amount: ";
		getline(cin, _amount[i]);
		cout << "Reorder point: ";
		getline(cin, _reorder_point[i]);
		cout << "Inventory Value: ";
		getline(cin, _inventory_value[i]);
	}

	for (int i = 0; i < num; i++) {
		stock.setName(&_product_name[i]);
		stock.setCateg(&_category[i]);
		stock.setPrice(&_price[i]);
		stock.setCode(&_code[i]);
		stock.setAmount(&_amount[i]);
		stock.setReorder(&_reorder_point[i]);
		stock.setInvent(&_inventory_value[i]);
		stock.addNewItem(_branch[i]);
	}

	stock.readFile(sales);
	stock.displayRecord();
	//string supplier = "Takpaweyh Brands Malaysia Sdn Bhd";

	return 0;
}