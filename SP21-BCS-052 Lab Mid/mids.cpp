#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Customer
{
    string name;
    string item;
    int customerId;
    int quantity;
    Customer* next;
    Customer(string nameOfCustomer, string itemPurchase, int id, int quantityRequired)
    {
        name = nameOfCustomer;
        item = itemPurchase;
        customerId = id;
        quantity = quantityRequired;
        next = NULL;
    }  
};

struct Shop
{
    string type;
    int priceOfOneItem;
    Shop* next;
    Customer* customer;
    Shop(string typeOfShop, int price)
    {
        type = typeOfShop;
        priceOfOneItem = price;
    }
};

Customer* headCustomer = NULL;
Customer* tailCustomer = NULL;

void addCustomer(string nameOfCustomer, string itemPurchase, int id, int quantity)
{
    Customer* c= new Customer(nameOfCustomer, itemPurchase, id, quantity);
    if (!headCustomer && !tailCustomer)
    {
        headCustomer = c;
        tailCustomer = c;
    }
    else
    {
        tailCustomer->next = c;
        tailCustomer = c;
    }
}

void display(Shop* head)
{
    Shop* p = head;
    while (p)
    {
        cout<<p->type<<" ";
        p =p->next;
    }
}

void displayCustomerInfoAll(Customer* head)
{
    Customer* p = head;
    while (p)
    {
        cout<<p->name<<" ";
        p = p->next;
    }
}

int main(int argc, char const *argv[])
{

    Shop* headCoffee = new Shop("coffee",100);    
    Shop* iceCream = new Shop("iceCream", 1);
    Shop* pizza = new Shop("pizza", 10);

    headCoffee->next = iceCream;
    iceCream->next = pizza;
    pizza->next = NULL;
    // display(headCoffee);

    addCustomer("ahmad","coffee",1,10);
    addCustomer("abc","icecream",1,10);
    addCustomer("h","coffee",1,10);
    addCustomer("xyz","pizza",1,10);



    return 0;
}