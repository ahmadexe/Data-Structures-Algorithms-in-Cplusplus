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
    insertCars("Ahmad", "BMW", 1, 2);
    insertCars("Haider", "BMW", 2, 1);
    insertCars("A", "BMW", 3, 2);
    insertCars("Aad", "BMW", 4, 1);
    insertCars("AVB", "BMW", 5, 2);
    insertCars("Ahm", "BMW", 6, 2);

    insertRide("Try1", 10, 1);
    insertRide("Try2", 1, 1);
    insertRide("Try3", 3, 1);
    insertRide("Try4", 12, 1);
    insertRide("Try5", 2, 1);

    // displayCars();
    // displayRides(1);

    // displayTypeCar(2);

    cout << totalEarning(1) << endl;
    cout << displayEarningOfAllCars() << endl;
    return 0;
}