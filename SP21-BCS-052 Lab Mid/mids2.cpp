#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Customer
{
    string name;
    string item;
    int customerId;
    int quantity;
    Customer *next;
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
    Shop *next;
    Customer *customer;
    Shop(string typeOfShop, int price)
    {
        type = typeOfShop;
        priceOfOneItem = price;
        next = NULL;
        customer = NULL;
    }
};

Customer *headCustomer = NULL;
Customer *tailCustomer = NULL;
Shop *headCoffee = new Shop("coffee", 100);
Shop *iceCream = new Shop("icecream", 1);
Shop *pizza = new Shop("pizza", 10);

void form()
{
    headCoffee->next = iceCream;
    iceCream->next = pizza;
    pizza->next = headCoffee;
}

void addCustomer(string nameOfCustomer, string itemPurchase, int id, int quantity)
{
    Customer *c = new Customer(nameOfCustomer, itemPurchase, id, quantity);
    c->next = NULL;
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

void display()
{
    Shop *p = headCoffee;
    do
    {
        cout << p->type << " ";
        p = p->next;
    } while (p != headCoffee);
}

void displayCustomerInfoAll(Customer *head)
{
    Customer *p = head;
    while (p)
    {
        cout << p->name << " ";
        p = p->next;
    }
}

void arrange()
{
    Shop *p = headCoffee;
    Customer *cur = headCustomer;
    while (cur)
    {
        if (cur->item == "coffee")
        {
            while (p->type != "coffee")
            {
                p = p->next;
            }
            if (p->customer == NULL)
            {
                if (cur->item == "coffee")
                {
                    p->customer = cur;
                    cur = cur->next;
                    p->customer->next = NULL;
                }
            }
            else
            {
                Customer *myCustomer = p->customer;
                while ((myCustomer)->next != NULL)
                {
                    myCustomer = (myCustomer)->next;
                }
                if (cur->item == "coffee")
                {
                    (myCustomer)->next = cur;
                    cur = cur->next;
                    myCustomer->next->next = NULL;
                }
            }
        }

        else if (cur->item == "icecream")
        {

            while (p->type != "icecream")
            {
                p = p->next;
            }
            if (p->customer == NULL && cur->item == "icecream")
            {
                p->customer = cur;
                cur = cur->next;
                p->customer->next = NULL;
            }
            else
            {
                Customer *myCustomer = p->customer;
                while ((myCustomer)->next != NULL && (myCustomer)->next->quantity <= cur->quantity)
                {
                    myCustomer = (myCustomer)->next;
                }
                if (cur->item == "icecream")
                {
                    if (p->customer->quantity >= cur->quantity)
                    {
                        Customer* q = cur;
                        cur = cur->next;
                        Customer* temp = p->customer;
                        p->customer = q;
                        q->next = temp;
                    }
                    else if (myCustomer->next)
                    {
                        Customer* q = cur;
                        cur = cur->next;
                        Customer* temp = myCustomer->next;
                        myCustomer->next = q;
                        q->next = temp;
                    }
                    else
                    {
                        myCustomer->next = cur;
                        cur = cur->next;
                        myCustomer->next->next = NULL;
                    }
                }
            }
        }

        else if (cur->item == "pizza")
        {
            while (p->type != "pizza")
            {
                p = p->next;
            }
            if (p->customer == NULL && cur->item == "pizza")
            {
                p->customer = cur;
                cur = cur->next;
                p->customer->next = NULL;
            }
            else
            {
                if (cur->item == "pizza")
                {
                    Customer *q = cur;
                    cur = cur->next;
                    q->next = NULL;
                    q->next = p->customer;
                    p->customer = q;
                }
            }
        }
    }
}

void deliver(string shopType)
{
    Shop *p = headCoffee;
    do
    {
        p = p->next;
    } while (p != headCoffee && p->type != shopType);
    Customer *x = p->customer;
    if (x)
    {
        while (x)
        {
            if (x->item == shopType)
            {
                cout << "Name " << x->name << " ID " << x->customerId << endl;
            }
            x = x->next;
        }
    }
}

void serve(string shopType)
{
    Shop *p = headCoffee;
    do
    {
        p = p->next;
    } while (p != headCoffee && p->type != shopType);
    p->customer = p->customer->next;
}

int totalProfit(string shopType)
{
    Shop *p = headCoffee;
    do
    {
        p = p->next;
    } while (p != headCoffee && p->type != shopType);
    Customer *x = p->customer;
    int sum = 0;
    if (x)
    {
        while (x)
        {
            if (x->item == shopType)
            {
                sum += x->quantity * p->priceOfOneItem;
            }
            x = x->next;
        }
    }
    return sum;
}

int main(int argc, char const *argv[])
{

    form();
    while (true)
    {
        int choice;
        cout << "\n1. Add customers\n2. Arrange your customers\n3. Check customers for shop.\n4. Total Profit of a shop\n5. Serve\n6. Exit\n";
        cin >> choice;
        if (choice == 1)
        {
            string name, item;
            int id, quantity;
            cout << "Enter name, item, id and quantity" << endl;
            cin >> name >> item >> id >> quantity;
            addCustomer(name, item, id, quantity);
        }
        else if (choice == 2)
        {
            arrange();
        }
        else if (choice == 3)
        {
            string type;
            cout << "Enter shop type" << endl;
            cin >> type;
            deliver(type);
        }
        else if (choice == 4)
        {
            string type;
            cout << "Enter shop type" << endl;
            cin >> type;
            cout << totalProfit(type);
        }
        else if (choice == 5)
        {
            string type;
            cout << "Enter shop type" << endl;
            cin >> type;
            serve(type);
        }
        else if (choice == 6)
        {
            break;
        }
    }

    return 0;
}