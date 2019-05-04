//This program are the implementation of the constructors and/or function definition
//in Stock.h file
#include "Stock.h"

//To read the csv file and 
//store the contents in the variable (private) respectively
//Its actually to receive the branch name instead of object as parameter
void Stock::readFile(std::string branch) {
	product_name = new std::string[MAX_SIZE];
	category = new std::string[MAX_SIZE];
	code = new std::string[MAX_SIZE];
	price = new std::string[MAX_SIZE];
	available = new std::string[MAX_SIZE];
	reorder_point = new std::string[MAX_SIZE];
	inventory_value = new std::string[MAX_SIZE];

	//To create file name based on the branch name
	std::string filename = sale.getBranch() + ".csv";

	//To read file
	std::ifstream iFile(filename);

	if (!iFile.is_open()) {
		std::cout << "Warnings!!! Error opening file..." << std::endl;
		return;
	}

	//To store all the available data from the csv file into the respective variable
	//variable 'row' are to hold the number of iteration as well as to count the number of row (lines) in the csv file
	for (row = 0; getline(iFile, product_name[row], ','); row++) {
		getline(iFile, category[row], ',');
		getline(iFile, price[row], ',');
		getline(iFile, code[row], ',');
		getline(iFile, available[row], ',');
		getline(iFile, reorder_point[row], ',');
		getline(iFile, inventory_value[row], '\n');
	}

	iFile.close();
}

//To update the data in the stock record(csv file based on branch) based on Sales recorded
void Stock::updateStock(Sales sale) {
	//To create file name based on the branch name
	std::string filename = sale.getBranch() + ".csv";

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

	//To write file
	std::ofstream oFile(filename);

	//To rewrite all information into the existing file
	//with some updated value (new value - column)
	for (int i = 0; i < row; i++) {
		if (i == row_change) {
			oFile << product_name[i] << "," << category[i] << "," << price[i] << "," 
				<< code[i] << "," << _available << "," << reorder_point[i] << "," << _inventory_value << std::endl;
		}
		else {
			oFile << product_name[i] << "," << category[i] << "," << price[i] << "," 
				<< code[i] << "," << available[i] << "," << reorder_point[i] << "," << inventory_value[i] << std::endl;
		}
	}

	oFile.close();
}

//To display all the data in the csv file (based on the branch)
//the parameter are to be considered to be change to getBranch
void Stock::displayRecord(){
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
}

//To add new item into the csv file (based on branch)
//by appending it to new line (below)
void Stock::addNewItem(std::string branch) {
	std::string filename = branch + ".csv";

	std::ofstream oFile(filename, std::ios::app);

	//To store whatever information that tha user key in
	oFile << *product_name << "," << *category << "," << *price << ","
		<< *code << "," << *available << "," << *reorder_point << "," << *inventory_value << std::endl;

	oFile.close();
}

//To delete an item information in csv file
//based on the index input
void Stock::deleteItem(int index) {
	std::string filename = sale.getBranch() + ".csv";
	
	std::ofstream oFile(filename);

	//To delete the item based on index
	for (int i = 0; i < index; i++) {
		if (i == (index - 1)) {
			i++;
			oFile << product_name[i] << "," << category[i] << "," << price[i] << ","
				<< code[i] << "," << available[i] << "," << reorder_point[i] << "," << inventory_value[i] << std::endl;
		}
		oFile << product_name[i] << "," << category[i] << "," << price[i] << ","
			<< code[i] << "," << available[i] << "," << reorder_point[i] << "," << inventory_value[i] << std::endl;
	}

	oFile.close();
}