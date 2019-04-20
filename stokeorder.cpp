#include <iostream>
#include <string>
using namespace std;

class Inventory{
    char productName[20];
    int productCode;
    double price;
    double quantity;
    string supplier;
    public:
    void getdata();
    void showdata();
};

void Inventory :: getdata()
{
    cout<<"\nEnter Product Name : ";
    cin>>productName;
    
    cout<<"Enter Product Code : ";
    cin>>productCode;
    
    cout<<"Enter Price : ";
	cin>>price;
	
    cout<<"Enter Quantity : ";
    cin>>quantity;
    cout<<"Enter Supplier Name (Company) : ";
    cin>>supplier;
}

void Inventory::showdata()
{
    
    cout<<productName;

    cout<<productCode;

    cout<<price;
    
    cout<<quantity;
    
    cout<<supplier;
}

int main(){
    int i,n;

    cout<<"\n=====Inventory Management=====\n";
    cout<<"\nHow many Records to be created : ";
    cin>>n;

    cout<<"Enter "<<n<<" Records\n";

    cout<<"\n\n---Stock Information---\n";
    cout<<"\n"<<"\nProduct Name                : "
        <<"\n"<<"Product Code                : "
        <<"\n"<<"Price                       : "
        <<"\n"<<"Quantity                    : "
        <<"\n"<<"Supplier Name (Company)     : "<<endl;

    return 0;
}
