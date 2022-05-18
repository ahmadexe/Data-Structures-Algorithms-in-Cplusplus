#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Customer
{
    int id;
    string name;
    int shopID;
    Customer* next;
    Customer(int ID, string namePerson, int shopid)
    {
        id = ID;
        name = namePerson;
        shopID = shopid,
        next = NULL;
    }
};

//1 coffee, 2 icecream, 3 pizza
struct Shop
{
    int id;
    Shop* next;
    Customer* customer;
    
};

int main(int argc, char const *argv[])
{

    


    return 0;
}