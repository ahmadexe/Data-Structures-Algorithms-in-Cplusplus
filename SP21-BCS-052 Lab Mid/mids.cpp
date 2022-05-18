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
        next = NULL;
        customer = NULL;
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
    do
    {
        cout<<p->type<<" ";
        p =p->next;
    } while (p != head);
    
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
// For coffee
void addToCoffee(Shop** head, Customer* customer)
{
    Shop* p = *head;
    if (!p->customer)
    {
        p->customer = customer;
    }
    else
    {
        customer->next = p->customer;
        p->customer = customer;
    }
}

void addToIcecream(Shop** head, Customer* customer)
{
    Shop* p = *head;
    if (!p->customer)
    {
        p->customer = customer;
    }
    else
    {
        customer->next = p->customer;
        p->customer = customer;
    }
}

void addToPizza(Shop** head, Customer* customer)
{
    Shop* p = *head;
    if (!p->customer)
    {
        p->customer = customer;
    }
    else
    {
        customer->next = p->customer;
        p->customer = customer;
    }
}

void arrange(Shop** head)
{
    Shop* p = *head;
    Customer* cur = headCustomer;
    while (cur)
    {
        if (cur->item == "coffee")
        {
            while (p->type != "coffee")
            {
                p = p->next;
            }
            Customer* myCustomer = p->customer;
            if (myCustomer == NULL)
            {
                myCustomer = cur;
            }
            else
            {
               while(myCustomer->next != NULL)
               {
                   myCustomer = myCustomer->next;
               }
               myCustomer->next = cur;
            }
   
        }

        else if (cur->item == "icecream")
        {
            while (p->type != "icecream")
            {
                p = p->next;
            }
            Customer* myCustomer = p->customer;
            if (myCustomer == NULL)
            {
                myCustomer = cur;
            }
            else
            {
               while(myCustomer->next != NULL && myCustomer->next->quantity < cur->quantity)
               {
                   myCustomer = myCustomer->next;
               }
               myCustomer->next = cur;
            }
        }
        
        else if (cur->item == "pizza")
        {
            while (p->type != "pizza")
            {
                p = p->next;
            }
            Customer* myCustomer = p->customer;
            if (myCustomer == NULL)
            {
                myCustomer = cur;
            }
            else
            {
               cur->next = p->customer;
               p->customer = cur;
            }
        }
        
        cur = cur->next;
    }
}

int main(int argc, char const *argv[])
{

    Shop* headCoffee = new Shop("coffee",100);    
    Shop* iceCream = new Shop("icecream", 1);
    Shop* pizza = new Shop("pizza", 10);

    headCoffee->next = iceCream;
    iceCream->next = pizza;
    pizza->next = headCoffee;

    addCustomer("ahmad","coffee",1,10);
    addCustomer("abc","icecream",1,10);
    addCustomer("abcdef","icecream",1,20);
    addCustomer("h","coffee",1,10);
    addCustomer("xyz","pizza",1,10);
    // printCoffeeCustomer(headCoffee);

    arrange(&headCoffee);

    return 0;
}