#include <iostream>
using namespace std;

void fib(int a, int b, int n) {
    if (b > n) return;
    int c = a + b;
    cout << c << endl;
    fib(b, c, n);
}

int getNthFibElement(int n) {
    if (n == 1) return 0;
    else if (n == 2) return 1;
    return getNthFibElement(n - 1) + getNthFibElement(n - 2);
}

int main(int argc, char const *argv[])
{
    fib(0, 1, 50);
    cout << getNthFibElement(6) << endl;
    return 0;
}
