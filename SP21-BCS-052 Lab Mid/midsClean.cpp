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
    Customer *p = new Customer(amount, namePerson, shopid);
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
    Customer *current = headCustomer;
    while (current)
    {
        // Add in Coffee
        if (current->shopID == 1)
        {
            Customer *toBeAdded = current;
            current = current->next;
            Shop *p = coffee;
            if (!p->customer)
            {
                p->customer = toBeAdded;
                toBeAdded->next = NULL;
            }
            else
            {
                Customer *moveForward = p->customer;
                while (moveForward->next)
                {
                    moveForward = moveForward->next;
                }
                moveForward->next = toBeAdded;
                toBeAdded->next = NULL;
            }
        }

        // Adding in icecream
        else if (current->shopID == 2)
        {
            Customer *toBeAdded = current;
            current = current->next;
            Shop *p = iceCream;
            if (!p->customer)
            {
                p->customer = toBeAdded;
                toBeAdded->next = NULL;
            }
            else if (!p->customer->next)
            {

                if (toBeAdded->quantity <= p->customer->quantity)
                {
                    toBeAdded->next = p->customer;
                    p->customer = toBeAdded;
                }
                else
                {
                    p->customer->next = toBeAdded;
                    toBeAdded->next = NULL;
                }
            }

            else
            {
                Customer* q = p->customer;
                while ((q->next != NULL) && q->next->quantity < toBeAdded->quantity)
                {
                    q = q->next;
                }
                if (!q->next)
                {
                    q->next = toBeAdded;
                    toBeAdded->next = NULL;
                }
                else
                {
                    toBeAdded->next = q->next;
                    q->next = toBeAdded;
                }
            }
        }

        // Adding in pizza

        else if (current->shopID == 3)
        {
            Customer *toBeAdded = current;
            current = current->next;
            Shop *p = pizza;
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
    }
}

void display(int ID)
{
    if (ID == 1)
    {
        Customer* q = coffee->customer;
        while (q)
        {
            cout<<"Name "<<q->name<<endl;
            cout<<"Bought coffee in Quantity "<<q->quantity<<endl;
            q = q->next;
        }
    }

    else if (ID == 2)
    {
        Customer* q = iceCream->customer;
        while (q)
        {
            cout<<"Name "<<q->name<<endl;
            cout<<"Bought ice cream in Quantity "<<q->quantity<<endl;
            q = q->next;
        }
    }
    else if (ID == 3)
    {
        Customer* q = pizza->customer;
        while (q)
        {
            cout<<"Name "<<q->name<<endl;
            cout<<"Bought pizza in Quantity "<<q->quantity<<endl;
            q = q->next;
        }
    }
    else
    {
        cout<<"Customer with a wrong ID detected"<<endl;
    }
}

void serve(int ID)
{
    if (ID == 1)
    {
        Customer* q = coffee->customer;
        cout<<"Served coffee to "<<q->name<<endl;
        coffee->customer = coffee->customer->next;
    }

    else if (ID == 2)
    {
        Customer* q = iceCream->customer;
        cout<<"Served ice cream to "<<q->name<<endl;
        iceCream->customer = iceCream->customer->next;
    }
    else if (ID == 3)
    {
        Customer* q = pizza->customer;
        cout<<"Served Pizza to "<<q->name<<endl;
        pizza->customer = pizza->customer->next;
    }
    else
    {
        cout<<"Customer with a wrong ID detected"<<endl;
    }
}

int main(int argc, char const *argv[])
{

    form();
    while (1)
    {
        int choice;
        cout
        <<"1. Add customers in line"<<endl
        <<"2. Send the customers to shops."<<endl
        <<"3. View customers at a shop"<<endl
        <<"4. Serve at shop"<<endl
        <<"5. Exit"<<endl;
        cin>>choice;
        
    }
       
    
    return 0;
}