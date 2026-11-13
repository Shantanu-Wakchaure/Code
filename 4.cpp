
//4.Write a recursive function to find sum of numbers
#include <iostream>
using namespace std;
int sum(int n) {
    if (n == 0)
        return 0;
    return n + sum(n - 1);
}
int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    if (num < 0) {
        cout << "Please enter a non-negative number." << endl;
        return 0;
    }
    cout << "Sum of numbers from 0 to " << num << " = " << sum(num) << endl;
    return 0;
}