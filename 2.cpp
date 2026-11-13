//2.Write a recursive function to find the factorial of a number.
#include <iostream>
using namespace std;
int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}
int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    if (num < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
        return 0;
    }
    cout << "Factorial of " << num << " = " << factorial(num) << endl;
    return 0;
}
