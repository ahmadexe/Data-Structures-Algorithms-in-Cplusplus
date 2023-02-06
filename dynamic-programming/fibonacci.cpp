#include <iostream>
using namespace std;

void fib(int a, int b) {
    if (b > 50) return;
    int c = a + b;
    cout << c << endl;
    fib(b, c);
}

int getNthFibElement(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    return getNthFibElement(n - 1) + getNthFibElement(n - 2);
}

int main(int argc, char const *argv[])
{
    fib(0, 1);
    cout << getNthFibElement(6) << endl;
    return 0;
}
