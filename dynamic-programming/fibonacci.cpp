#include <iostream>
using namespace std;

void fib(int a, int b) {
    if (b > 50) return;
    int c = a + b;
    cout << c << endl;
    fib(b, c);
}

int main(int argc, char const *argv[])
{
    fib(0, 1);
    return 0;
}
