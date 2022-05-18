#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Customer
{
    int id;
    string name;
    int shopID;
    Customer *next;
    Customer(int ID, string namePerson, int shopid)
    {
        id = ID;
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

void addCustomer(int ID, string namePerson, int shopid)
{
    Customer* p = new Customer()
    if (!headCustomer && !tailCustomer)
    {

    }
}

int main(int argc, char const *argv[])
{

    return 0;
}