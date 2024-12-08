#include <iostream>
#include <cmath>

using namespace std;

/* Using binet's formula;
   Logic-> fibo(n) = ((phi^n) - ((1-phi)^n)) / sqrt(5)
           where, phi = (1 + sqrt(5)) / 2 */
long long Fibo(int n)
{
    double goldenRatio = (1 + sqrt(5)) / 2;
    double fib = (pow(goldenRatio, n) - pow((1 - goldenRatio), n)) / sqrt(5);
    return round(fib);
}

int main()
{
    int n;
    cout << "Enter the position of fibonacci term you want to find: ";
    cin >> n;
    cout << "The Fibonacci term at position " << n << " is " << Fibo(n);
    return 0;
}