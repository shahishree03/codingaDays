#include<iostream>
#include<vector>
using namespace std;
//This is not followed Set responsobiliy model
class Customer{
private:
string name;
int id;
vector<Item> items;
float totalAmount;

public:
void setName(string name);
string getName();
void addItem(Item item);
void removeItem(Item item);
float calculateTotalAmount();
string generateInvoice();
};

class CustomerDetails{
private:
string name;
int id;

public:
void setName(string name);
string getName();
void setId(int id);
int getId();

};


class BillingCalculator{
private:
vector<Item> items;
public:
void addItem(Item item);
void removeItem(Item item);
float calculateTotalAmount();
string generateInvoice();
};

class InvoiceGenerator{
public:
string generateInvoice(CustomerDetails cust,  BillingCalculator bill);
}


