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
	Sales sales;
	Stock stock;
	Order order;
	string _branch;
	string* _product_name = new string[MAX_SIZE];
	string* _category = new string[MAX_SIZE];
	string* _price = new string[MAX_SIZE];
	string* _code = new string[MAX_SIZE];
	string* _amount = new string[MAX_SIZE];
	string* _reorder_point = new string[MAX_SIZE];
	string* _supplier = new string[MAX_SIZE];
	int choice, choi, c, line;
	int date, month, year;

	cout << "---> WELCOME TO INVENTORY SYSTEM <---" << endl << endl;

	cout << "What you can do with me?" << endl << endl;
	cout << "\t[1] Record today transaction" << endl;
	cout << "\t[2] View sales record" << endl;
	cout << "\t[3] View stock record" << endl;
	cout << "\t[4] View supplier record" << endl << endl;

	cout << "Your choice: ";
	cin >> choice;
	cout << endl;

	for (int i = 0; choice != 5; i++) {
	//Record today transaction
		if (choice == 1) {
			cout << "-> You have choose to record today transaction <-" << endl << endl;
			cout << "Enter branch name (Skudau, Pokok Sena, Kuala Berang, Besut): ";
			cin.ignore();
			getline(cin, _branch);
			stock.readFile(_branch);
			cout << endl;
			cout << "So, how many you want to put? ";
			cin >> c;
			cout << endl;
			cout << "Please enter the following information:" << endl << endl;
			for (int i = 0; i < c; i++) {
				cout << "\tProduct Code: ";
				cin.ignore();
				getline(cin, _code[i]);
				sales.setCode(&_code[i]);
				cout << "\tAmount: ";
				getline(cin, _amount[i]);
				sales.setAmount(&_amount[i]);
			//To record today transaction
				sales.recordSales(_branch);
				sales.setBranch(&_branch);
				stock.updateStock(_branch,_code[i],_amount[i]);
			}
		}
	//View sales record
		else if (choice == 2) {
			cout << "-> You have choose to view sales record <-" << endl << endl;
			cout << "Please choose which/when the file you want to display." << endl;
			cout << "\tBranch name (Skudau, Pokok Sena, Kuala Berang, Besut): ";
			cin.ignore();
			getline(cin, _branch);
			cout << "\tDate: ";
			cin >> date;
			cout << "\tMonth: ";
			cin >> month;
			cout << "\tYear: ";
			cin >> year;
			sales.readSales(_branch, date, month, year);
			sales.printSales();
		}
	//View stock record
		else if (choice == 3) {
			cout << endl;
			cout << "-> You have choose to view stock record <-" << endl << endl;
			cout << "\t[1] Display stock record" << endl;
			cout << "\t[2] Add new item" << endl;
			cout << "\t[3] Delete existing item" << endl;
			cout << "\t[4] Exit" << endl << endl;

			cout << "Your choice: ";
			cin >> choi;
			cout << endl;
		//Menu choice loop
			for (int i = 0; choi != 4; i++) {
			//Display stock record
				if (choi == 1) {
					cout << "> You have choose to display stock record <" << endl << endl;
					cout << "Enter branch name (Skudau, Pokok Sena, Kuala Berang, Besut): ";
					cin >> _branch;
					cout << endl;
				//To display the data in csv file based on the branch
					stock.readFile(_branch);
					stock.displayRecord();
				}
			//Add new item
				else if (choi == 2) {
					cout << "> You have choose to add new item <" << endl << endl;
					cout << "Enter branch name (Skudau, Pokok Sena, Kuala Berang, Besut): ";
					cin >> _branch;
					cout << endl;
					cout << "So, how many you want to put? ";
					cin >> c;
					cout << endl;
					cout << "Then, please enter the following information:" << endl << endl;
					for (int i = 0; i < c; i++) {
						cout << "\tProduct name: ";
						cin.ignore();
						getline(cin, _product_name[i]);
						stock.setName(&_product_name[i]);
						cout << "\tCategory: ";
						getline(cin, _category[i]);
						stock.setCateg(&_category[i]);
						cout << "\tPrice per Unit: ";
						getline(cin, _price[i]);
						stock.setPrice(&_price[i]);
						order.setItemPrice(&_price[i]);
						cout << "\tProduct Code: ";
						getline(cin, _code[i]);
						stock.setCode(&_code[i]);
						order.setItemCode(&_code[i]);
						cout << "\tAmount: ";
						getline(cin, _amount[i]);
						stock.setAmount(&_amount[i]);
						order.setOrderAmount(&_amount[i]);
						cout << "\tReorder point: ";
						getline(cin, _reorder_point[i]);
						stock.setReorder(&_reorder_point[i]);
						cout << "\tSupplier Company: ";
						getline(cin, _supplier[i]);
						order.setSupplier(&_supplier[i]);
					//Calculation for inventory value
						int inventory_value = stoi(_price[i]) * stoi(_amount[i]);
						stock.setInvent(&to_string(inventory_value));
					//To store into the csv file based on branch
						stock.addNewItem(_branch);
					//To store into the Supplier.csv
						order.addSupplier();
					}
				}
			//Delete existing item
				else if (choi == 3) {
					cout << "> You have choose to delete existing item <" << endl << endl;
					cout << "Enter branch name (Skudau, Pokok Sena, Kuala Berang, Besut): ";
					cin >> _branch;
					sales.setBranch(&_branch);
					cout << endl;
					cout << "So, how many you want to put? ";
					cin >> c;
					cout << endl;
					cout << "Please enter with data/item you want to delete:" << endl << endl;
					for (int i = 0; i < c; i++) {
						cout << "\tLine: ";
						cin >> line;
						stock.deleteItem(line, _branch);
					}
				}
			//Choice again
				cout << endl;
				cout << "\t[1] Display stock record" << endl;
				cout << "\t[2] Add new item" << endl;
				cout << "\t[3] Delete existing item" << endl;
				cout << "\t[4] Exit" << endl << endl;

				cout << "Your choice: ";
				cin >> choi;
				cout << endl;
			}
		}
	//View supplier record
		else if (choice == 4) {
			cout << endl;
			cout << "-> You have choose to view supplier record <-" << endl << endl;
			cout << "\t[1] Display supplier record" << endl;
			cout << "\t[2] Add new supplier" << endl;
			cout << "\t[3] Delete existing supplier" << endl;
			cout << "\t[4] Exit" << endl << endl;

			cout << "Your choice: ";
			cin >> choi;
			cout << endl;
		//Menu choice loop
			for (int i = 0; choi != 4; i++) {
			//Display supplier record
				if (choi == 1) {
					cout << "> You have choose to display supplier record <" << endl << endl;
					cout << "Enter branch name (Skudau, Pokok Sena, Kuala Berang, Besut): ";
					cin >> _branch;
					cout << endl;
				//To display the data in Supplier.csv
					order.read_File();
					order.displaySupplier();
				}
			//Add new supplier
				else if (choi == 2) {
					cout << "> You have choose to add new supplier <" << endl << endl;
					cout << "Enter branch name (Skudau, Pokok Sena, Kuala Berang, Besut): ";
					cin >> _branch;
					cout << endl;
					cout << "So, how many you want to put? ";
					cin >> c;
					cout << endl;
					cout << "Then, please enter the following information:" << endl << endl;
					for (int i = 0; i < c; i++) {
						cout << "\tSupplier Company: ";
						cin.ignore();
						getline(cin, _supplier[i]);
						order.setSupplier(&_supplier[i]);
						cout << "\tProduct Code: ";
						getline(cin, _code[i]);
						order.setItemCode(&_code[i]);
						cout << "\tAmount: ";
						getline(cin, _amount[i]);
						order.setItemCode(&_amount[i]);
						cout << "\tPrice per Unit: ";
						getline(cin, _price[i]);
						order.setItemPrice(&_price[i]);
					//To store into the Supplier.csv
						order.addSupplier();
					}
				}
			//Delete existing supplier
				else if (choi == 3) {
					cout << "> You have choose to delete existing supplier <" << endl << endl;
					cout << "Enter branch name (Skudau, Pokok Sena, Kuala Berang, Besut): ";
					cin >> _branch;
					cout << endl;
					cout << "So, how many you want to put? ";
					cin >> c;
					cout << endl;
					cout << "Please enter with supplier you want to delete:" << endl << endl;
					for (int i = 0; i < c; i++) {
						cout << "\tLine: ";
						cin >> line;
						order.deleteSupplier(line);
					}
				}
			//Choice again
				cout << endl;
				cout << "\t[1] Display supplier record" << endl;
				cout << "\t[2] Add new supplier" << endl;
				cout << "\t[3] Delete existing supplier" << endl;
				cout << "\t[4] Exit" << endl << endl;

				cout << "Your choice: ";
				cin >> choi;
				cout << endl;
			}
		}
		cout << "What you want to do next?" << endl << endl;
		cout << "\t[1] Record today transaction" << endl;
		cout << "\t[2] View sales record" << endl;
		cout << "\t[3] View stock record" << endl;
		cout << "\t[4] View supplier record" << endl;
		cout << "\t[5] Exit Program" << endl << endl;

		cout << "Your choice: ";
		cin >> choice;
		cout << endl;
	}

	cout << endl;
	cout << "---> THANK YOU <---" << endl;

	delete[] _product_name;
	delete[] _category;
	delete[] _price;
	delete[] _code;
	delete[] _amount;
	delete[] _reorder_point;
	delete[] _supplier;
	return 0;
}