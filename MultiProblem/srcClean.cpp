#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define oneCoffee 100
#define oneIcecream 250
#define onePizza 1200

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
                Customer *q = p->customer;
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

int calculateTotalProfit(int idShop)
{
    int total = 0;
    if (idShop == 1)
    {
        Customer *q = coffee->customer;
        while (q)
        {
            total += q->quantity * oneCoffee;
            q = q->next;
        }
    }
    else if (idShop == 2)
    {
        Customer *q = iceCream->customer;
        while (q)
        {
            total += q->quantity * oneIcecream;
            q = q->next;
        }
    }
    else if (idShop == 3)
    {
        Customer *q = pizza->customer;
        while (q)
        {
            total += q->quantity * onePizza;
            q = q->next;
        }
    }
    else
    {
        cout << "The id is invalid" << endl;
    }
    return total;
}

void display(int ID)
{
    if (ID == 1)
    {
        Customer *q = coffee->customer;
        while (q)
        {
            cout << "Name " << q->name << endl;
            cout << "Bought coffee in Quantity " << q->quantity << endl;
            q = q->next;
        }
    }

    else if (ID == 2)
    {
        Customer *q = iceCream->customer;
        while (q)
        {
            cout << "Name " << q->name << endl;
            cout << "Bought ice cream in Quantity " << q->quantity << endl;
            q = q->next;
        }
    }
    else if (ID == 3)
    {
        Customer *q = pizza->customer;
        while (q)
        {
            cout << "Name " << q->name << endl;
            cout << "Bought pizza in Quantity " << q->quantity << endl;
            q = q->next;
        }
    }
    else
    {
        cout << "Customer with a wrong ID detected" << endl;
    }
}

void serve(int ID)
{
    if (ID == 1)
    {
        Customer *q = coffee->customer;
        cout << "Served coffee to " << q->name << endl;
        coffee->customer = coffee->customer->next;
    }

    else if (ID == 2)
    {
        Customer *q = iceCream->customer;
        cout << "Served ice cream to " << q->name << endl;
        iceCream->customer = iceCream->customer->next;
    }
    else if (ID == 3)
    {
        Customer *q = pizza->customer;
        cout << "Served Pizza to " << q->name << endl;
        pizza->customer = pizza->customer->next;
    }
    else
    {
        cout << "Customer with a wrong ID detected" << endl;
    }
}

int main(int argc, char const *argv[])
{

    form();
    while (1)
    {
        int choice;
        cout
            << "1. Add customers in line" << endl
            << "2. Send the customers to shops." << endl
            << "3. View customers at a shop" << endl
            << "4. Serve at shop" << endl
            << "5. Calculate total profit" << endl
            << "6. Exit" << endl;
        cin >> choice;
        if (choice == 1)
        {
            int amount, shopid;
            string namePerson;
            cout << "Enter qunatity: " << endl;
            cin >> amount;
            cout << "Enter the ID\n1. Coffee\n2. Ice Cream\n3. Pizza" << endl;
            cin >> shopid;
            getchar();
            cout << "Enter the name of customer: " << endl;
            getline(cin, namePerson);
            addCustomer(amount, namePerson, shopid);
        }
        else if (choice == 2)
        {
            assemble();
        }
        else if (choice == 3)
        {
            int idView;
            cout << "Enter Shop ID you want to view customers of,\n1. Coffee\n2. Ice Cream\n3. Pizza" << endl;
            cin >> idView;
            display(idView);
        }
        else if (choice == 4)
        {
            int id;
            cout << "Enter Shop ID you want to serve at\n1. Coffee\n2. Ice Cream\n3. Pizza" << endl;
            cin >> id;
            serve(id);
        }
        else if (choice == 5)
        {
            int id;
            cout << "Enter Shop ID you want to serve at\n1. Coffee\n2. Ice Cream\n3. Pizza" << endl;
            cin >> id;
            cout << calculateTotalProfit(id) << endl;
        }
        else if (choice == 6)
        {
            break;
        }
        else
        {
            cout << "Invalid chocie" << endl;
        }
    }

    return 0;
}