#include <iostream>
#include <unordered_map> 
using namespace std;

#define mod 100000047

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

int memoizedSearched(int n) {
    static unordered_map<int, int> memo;
    if (memo.find(n) != memo.end()) return memo[n];
    if (n == 1) return 0;
    else if (n == 2) return 1;
    memo[n] = memoizedSearched(n - 1) + memoizedSearched(n - 2);
    return memo[n] % mod;
}

int main(int argc, char const *argv[])
{
    // fib(0, 1, 50);
    // cout << getNthFibElement(6) << endl;
    cout << memoizedSearched(50) << endl;
    return 0;
}
