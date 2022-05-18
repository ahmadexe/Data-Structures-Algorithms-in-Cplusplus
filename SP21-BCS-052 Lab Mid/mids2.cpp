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
// For coffee

// void arrange(Shop** head)
// {
//     Shop* p = *head;
//     Customer* cur = headCustomer;
//     while (cur)
//     {
//         if (cur->item == "coffee")
//         {
//             while (p->type != "coffee")
//             {
//                 p = p->next;
//             }
//             Customer** myCustomer = &p->customer;
//             if (*myCustomer == NULL)
//             {
//                 *myCustomer = cur;
//                 (*myCustomer)->next = NULL;
//             }
//             else
//             {
//                while((*myCustomer)->next != NULL)
//                {
//                    *myCustomer = (*myCustomer)->next;
//                }
//                (*myCustomer)->next = cur;
//             }
//         }

//         else if (cur->item == "icecream")
//         {
//             while (p->type != "icecream")
//             {
//                 p = p->next;
//             }
//             Customer** myCustomer = &p->customer;
//             if (*myCustomer == NULL)
//             {
//                 *myCustomer = cur;
//             }
//             else
//             {
//                while((*myCustomer)->next != NULL && (*myCustomer)->next->quantity < cur->quantity)
//                {
//                    *myCustomer = (*myCustomer)->next;
//                }
//                (*myCustomer)->next = cur;
//             }
//         }

//         else if (cur->item == "pizza")
//         {
//             while (p->type != "pizza")
//             {
//                 p = p->next;
//             }
//             Customer** myCustomer = &p->customer;
//             if (*myCustomer == NULL)
//             {
//                 *myCustomer = cur;
//             }
//             else
//             {
//                cur->next = *myCustomer;
//                p->customer = cur;
//             }
//         }

//         cur = cur->next;
//     }
// }

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
                p->customer = cur;
                cur = cur->next;
                p->customer->next = NULL;
            }
            else
            {
                Customer *myCustomer = p->customer;
                while ((myCustomer)->next != NULL)
                {
                    myCustomer = (myCustomer)->next;
                }
                (myCustomer)->next = cur;
                cur = cur->next;
            }
        }

        else if (cur->item == "icecream")
        {

            while (p->type != "icecream")
            {
                p = p->next;
            }
            if (p->customer == NULL)
            {
                p->customer = cur;
                cur = cur->next;
                p->customer->next = NULL;
            }
            else
            {
                Customer *myCustomer = p->customer;
                while ((myCustomer)->next != NULL && (myCustomer)->next->quantity < cur->quantity)
                {
                    myCustomer = (myCustomer)->next;
                }
                (myCustomer)->next = cur;
                cur = cur->next;
            }
        }

        else if (cur->item == "pizza")
        {
            while (p->type != "pizza")
            {
                p = p->next;
            }
            // Customer **myCustomer = &p->customer;
            if (p->customer == NULL)
            {
                p->customer = cur;
                cur = cur->next;
                p->customer->next = NULL;
            }
            else
            {
                Customer * q = cur;
                cur = cur->next;
                q->next = NULL;
                q->next = p->customer;
                p->customer = q;

            }
        }

        // cur = cur->next;
        // cout<<cur->name;
    }
}

void deliver()
{
    Shop *p = headCoffee;
    do
    {
        Customer *x = p->customer;
        while (x)
        {
            if (x->item == p->type){
                cout << x->name << " ";
            }
            x = x->next;
        }
        cout<<endl;
        p = p->next;
    } while (p != headCoffee);
}

int main(int argc, char const *argv[])
{
    addCustomer("ahmad", "coffee", 1, 10);
    addCustomer("abc", "icecream", 1, 10);
    addCustomer("abcdef", "icecream", 1, 5);
    addCustomer("h", "coffee", 1, 10);
    addCustomer("xyz", "pizza", 1, 10);
    form();
    // display();
    arrange();
    Shop * s = headCoffee;
    cout<<s->customer->name<<" ";
    cout<<s->customer->next->name<<" ";


    deliver();
    return 0;
}