#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Customer
{
    int quantity;
    string name;
    int shopID;
    Customer *next;
    Customer(int amount, string namePerson, int shopid)
    {
        quantity = amount;
        name = namePerson;
        shopID = shopid,
        next = NULL;
    }
};

// 1 coffee, 2 icecream, 3 pizza
struct Shop
{
    int id;
    Shop *next;
    Customer *customer;
    Shop(int ID)
    {
        id = ID;
        next = NULL;
        customer = NULL;
    }
};

Shop *coffee = new Shop(1);
Shop *iceCream = new Shop(2);
Shop *pizza = new Shop(3);

Customer *headCustomer = NULL;
Customer *tailCustomer = NULL;

void form()
{
    coffee->next = iceCream;
    iceCream->next = pizza;
    pizza->next = coffee;
}

void addCustomer(int amount, string namePerson, int shopid)
{
    Customer* p = new Customer(amount, namePerson, shopid);
    if (!headCustomer && !tailCustomer)
    {
        headCustomer = p;
        tailCustomer = p;
    }
    else
    {
        tailCustomer->next = p;
        tailCustomer = p;
    }
}

void assemble()
{
    Customer* current = headCustomer;
    while (current)
    {
        // Add in Coffee
        if (current->shopID == 1)
        {
            Customer* toBeAdded = current;
            current = current->next;
            Shop* p = coffee;
            if (!p->customer)
            {
                p->customer = toBeAdded;
                toBeAdded->next = NULL;
            }
            else
            {
                toBeAdded->next = p->customer;
                p->customer = toBeAdded;
            }
        }

        // Adding in icecream 
        else if (current->shopID == 2)
        {
            
        }
    }   
}

int main(int argc, char const *argv[])
{

    return 0;
}