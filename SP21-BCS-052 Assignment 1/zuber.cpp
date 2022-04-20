#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int chargeOneKm = 100;

struct ride
{
    int km;
    int charges;
    string ridersName;
    ride *next;
};

struct cars
{
    string driversName;
    string carName;
    int regNo;
    int carType;
    cars *next;
    ride *carRides;
};

cars *headCar = NULL;
cars *tailCar = NULL;

void insertCars(string dn, string cn, int rn, int ct)
{
    if (!headCar && !tailCar)
    {
        cars *c = new cars();
        c->driversName = dn;
        c->carName = cn;
        c->regNo = rn;
        c->carType = ct;
        c->next = NULL;
        c->carRides = NULL;
        headCar = c;
        tailCar = c;
    }
    else
    {
        cars *c = new cars();
        c->driversName = dn;
        c->carName = cn;
        c->regNo = rn;
        c->carType = ct;
        c->next = NULL;
        c->carRides = NULL;
        tailCar->next = c;
        tailCar = c;
    }
}

void displayCars()
{
    cars *p = headCar;
    while (p)
    {
        cout << "Name of driver: " << p->driversName << endl;
        cout << "Car: " << p->carName << endl;
        cout << "Registration number: " << p->regNo << endl;
        cout << "Type of car: " << p->carType << endl;
        p = p->next;
    }
}

void insertRide(string name, int d, int reg)
{
    cars *p = headCar;

    while (p)
    {
        if (p->regNo == reg)
        {
            break;
        }
        p = p->next;
    }
    if (p->carRides == NULL)
    {
        ride *m = new ride();
        m->ridersName = name;
        m->km = d;
        m->charges = d * chargeOneKm;
        m->next = NULL;
        p->carRides = m;
    }
    else
    {
        ride *m = new ride();
        m->ridersName = name;
        m->charges = d * chargeOneKm;
        m->km = d;
        m->next = p->carRides;
        p->carRides = m;
    }
}

void displayRides(int reg)
{
    cars *p = headCar;
    while (p)
    {
        if (p->regNo == reg && p)
        {
            break;
        }
        p = p->next;
    }
    if (!p->carRides)
    {
        cout << "The car has no rides" << endl;
    }
    else
    {
        ride *r = p->carRides;
        cout << "-------------------------------" << endl;
        cout << "Name of driver: " << p->driversName << endl;
        cout << "Car: " << p->carName << endl;
        while (r)
        {
            cout << "Riders name: " << r->ridersName << endl;
            cout << "Distance for ride: " << r->km << endl;
            cout << "Charges for the ride: " << r->charges << endl;
            r = r->next;
        }
    }
}

void displayTypeCar(int type)
{
    cars *p = headCar;
    while (p)
    {
        if (p->carType == type)
        {
            cout << "Name of driver: " << p->driversName << endl;
            cout << "Car: " << p->carName << endl;
            cout << "Registration number: " << p->regNo << endl;
            cout << "Type of car: " << p->carType << endl;
        }
        p = p->next;
    }
}

int totalEarning(int reg)
{
    cars *p = headCar;
    while (p->regNo != reg && p != NULL)
    {
        p = p->next;
    }
    if (p->carRides)
    {
        int sum = 0;
        ride *m = p->carRides;
        while (m)
        {
            sum += m->charges;
            m = m->next;
        }
        return sum;
    }
    else
    {
        cout << "No ride" << endl;
        return 0;
    }
}

int displayEarningOfAllCars()
{
    int totalSum = 0;
    cars *p = headCar;
    while (p)
    {
        int sum = 0;
        if (p->carRides)
        {

            ride *r = p->carRides;
            while (r)
            {
                sum += r->charges;
                r = r->next;
            }
        }
        totalSum += sum;
        p = p->next;
    }
    return totalSum;
}

int main(int argc, char const *argv[])
{
    while (true)
    {
        int choiceMain;
        cout << "1. Register new car\n2. Display details of all car.\n3. Display type of car.\n4. Add new ride.\n5. Display ride with detail.\n6. Total earning of a car.\n7. Display earning of all car.\n8. Exit\n";
        cin >> choiceMain;
        if (choiceMain == 1)
        {
            string dn, cn;
            int reg; 
            int type;
            cout << "Enter name of driver: " << endl;
            cin >> dn;
            cout << "Enter name of car: " << endl;
            cin >> cn;
            cout << "Enter registration number of car: " << endl;
            cin >> reg;
            cout << "Enter type of car "<< endl;
            cin >> type;
            while (!(type < 3 && type > 0)){
                cout << "Invalid car type, enter either 1 or 2 "<< endl;
                cin >> type;
            }
            insertCars(dn, cn, reg, type);
        }
        else if (choiceMain == 2)
        {
            displayCars();
        }
        else if (choiceMain == 3)
        {
            int type;
            cout << "Enter type of car " << endl;
            cin >> type;
            while (!(type < 3 && type > 0)){
                cout << "Invalid car type, enter either 1 or 2 "<< endl;
                cin >> type;
            }
            displayTypeCar(type);
        }
        else if (choiceMain == 4)
        {
            int km;
            int regg;
            string ridersName;
            cout<<"Enter riders name: "<<endl;
            cin>>ridersName;
            cout<<"Enter car's registration: "<<endl;
            cin>>regg;
            cout<<"Enter distance: "<<endl;
            cin>>km;
            insertRide(ridersName,km,regg);
        }
        else if (choiceMain == 5)
        {
            int reg;
            cout<<"Enter registration number: "<<endl;
            cin>>reg;
            displayRides(reg);
        }
        else if (choiceMain == 6)
        {
            int reg;
            cout<<"Enter registration number: "<<endl;
            cin>>reg;
            cout<<totalEarning(reg)<<endl;
        }
        else if (choiceMain == 7)
        {
            cout<<displayEarningOfAllCars()<<endl;
        }
        else if (choiceMain == 8)
        {
            break;
        }
        else
        {
            cout<<"Invalid choice"<<endl;
        }
    }

    return 0;
}