//This program are the implementation of the constructors and/or function definition
//in Stock.h file
#include "Stock.h"
/*#define COLUMN_DATA 7*/
#define MAX_SIZE 16382

//To update the data in the stock record(csv file based on branch) based on Sales recorded
void Stock::updateStock(Sales sale) {
	//The variable are arrange based on the column in the csv file
	/*std::string* product_name = new std::string[MAX_SIZE];
	std::string* category = new std::string[MAX_SIZE];
	std::string* code = new std::string[MAX_SIZE];
	std::string* price = new std::string[MAX_SIZE];
	std::string* available = new std::string[MAX_SIZE];
	std::string* reorder_point = new std::string[MAX_SIZE];
	std::string* inventory_value = new std::string[MAX_SIZE];*/
	/*product_name = new std::string[MAX_SIZE];
	category = new std::string[MAX_SIZE];
	code = new std::string[MAX_SIZE];
	price = new std::string[MAX_SIZE];
	available = new std::string[MAX_SIZE];
	reorder_point = new std::string[MAX_SIZE];
	inventory_value = new std::string[MAX_SIZE];*/
	
	//To create file name based on the branch name
	std::string filename = sale.getBranch() + ".csv";

	//To read file
	/*std::ifstream iFile(filename);

	if (!iFile.is_open()) {
		std::cout << "Warnings!!! Error opening file..." << std::endl;
		return;
	}*/

	//To store all the available data from the csv file into the respective variable
	//variable 'row' are to hold the number of iteration as well as to count the number of row (lines) in the csv file
	/*int row;*/
	/*for(row = 0; getline(iFile, product_name[row], ','); row++){
		getline(iFile, category[row], ',');
		getline(iFile, price[row], ',');
		getline(iFile, code[row], ',');
		getline(iFile, available[row], ',');
		getline(iFile, reorder_point[row], ',');
		getline(iFile, inventory_value[row], '\n');
	}*/
	std::cout << row << std::endl;
	//To update the 'available' (Available Product) and inventory_value (Inventory Value (RM)) in the csv file (based on the branch)
	//in reference to the 'code' (Product Code)
	int _available = 0;
	double _inventory_value = 0;
	int row_change = 0;
	for (int i = 0; i < row; i++) {
		if (code[i].compare(sale.getCode()) == 0) {
			row_change = i;
			std::cout << "row change: " << row_change << std::endl;
			//To convert string (available[i]) to int (this->available)
			_available = std::stoi(available[i]);
			std::cout << "Available initial: " << _available << std::endl;
			//To calculate Available Product
			_available -= sale.getAmount();
			std::cout << "Available after (new): " << _available << std::endl;
			
			//To convert string (inventory_value[i]) to double(this->inventory_value)
			_inventory_value = std::stod(inventory_value[i]);
			std::cout << "Inventory Value initial: RM " << _inventory_value << std::endl;
			//To calculate Inventory Value (RM)
			_inventory_value -= (sale.getPrice() * sale.getAmount());
			std::cout << "Inventory Value after (new): RM " << _inventory_value << std::endl;
			break;
		}
	}

	/*iFile.close();*/

	//To write file
	std::ofstream oFile(filename);

	//To rewrite all information into the existing file
	//with some updated value (new value - column)
	for (int i = 0; i < row; i++) {
		if (i == row_change) {
			oFile << product_name[i] << "," << category[i] << "," << code[i] << ","
				<< price[i] << "," << _available << "," << reorder_point[i] << "," << _inventory_value << std::endl;
		}
		else {
			oFile << product_name[i] << "," << category[i] << "," << code[i] << ","
				<< price[i] << "," << available[i] << "," << reorder_point[i] << "," << inventory_value[i] << std::endl;
		}
	}

	oFile.close();

	/*delete[] product_name;
	delete[] category;
	delete[] code;
	delete[] price;
	delete[] available;
	delete[] reorder_point;
	delete[] inventory_value;*/
}

//To display all the data in the csv file (based on the branch)
//the parameter are to be considered to be change to getBranch
void Stock::displayRecord(Sales sale){
	//Arrange based on the column in the csv file
	/*std::string* product_name = new std::string[MAX_SIZE];
	std::string* category = new std::string[MAX_SIZE];
	std::string* code = new std::string[MAX_SIZE];
	std::string* price = new std::string[MAX_SIZE];
	std::string* available = new std::string[MAX_SIZE];
	std::string* reorder_point = new std::string[MAX_SIZE];
	std::string* inventory_value = new std::string[MAX_SIZE];*/
	product_name = new std::string[MAX_SIZE];
	category = new std::string[MAX_SIZE];
	code = new std::string[MAX_SIZE];
	price = new std::string[MAX_SIZE];
	available = new std::string[MAX_SIZE];
	reorder_point = new std::string[MAX_SIZE];
	inventory_value = new std::string[MAX_SIZE];

	//To open the file based on the branch name
	std::string filename = sale.getBranch() + ".csv";

	//To read file
	std::ifstream iFile(filename);

	if (!iFile.is_open()) {
		std::cout << "Warnings!!! Error opening file..." << std::endl;
		return;
	}

	//To store all the available data from the csv file into the respective variable
	/*int row;*/
	for (row = 0; getline(iFile, product_name[row], ','); row++) {
		getline(iFile, category[row], ',');
		getline(iFile, code[row], ',');
		getline(iFile, price[row], ',');
		getline(iFile, available[row], ',');
		getline(iFile, reorder_point[row], ',');
		getline(iFile, inventory_value[row], '\n');
	}

	//To display the current data in csv file based on the its type
	std::cout << std::left << std::setw(40)  << "Product Name" << std::left << std::setw(30) 
		<< "Category" << std::left << std::setw(25) << "Price per unit (RM)" << std::left << std::setw(15)
		<< "Product Code" << std::left << std::setw(20) << "Available Product" << std::left << std::setw(20)  
		<< "Reorder Point" << std::left << std::setw(15) << "Inventory Value (RM)" << std::endl;
	//To create a divider (-) by appending the '-' 170 times
	std::string divider;
	std::cout << divider.append(170u, '-') << std::endl;
	//To display the data row by row based on its category (column)
	for (int i = 0; i < row; i++) {
		std::cout << std::left << std::setw(40) << product_name[i] << std::left << std::setw(30) 
			<< category[i] << std::left << std::setw(25) << std::fixed << std::setprecision(2) << price[i] << std::left << std::setw(15)
			<< code[i] << std::left << std::setw(20) << available[i] << std::left << std::setw(20) 
			<< reorder_point[i] << std::left << std::setw(15) << inventory_value[i] << std::endl;
	}

	/*delete[] product_name;
	delete[] category;
	delete[] code;
	delete[] price;
	delete[] available;
	delete[] reorder_point;
	delete[] inventory_value;*/
	iFile.close();
}

void Stock::addNewItem() {

}