/*9.Write a C++ program to search for a specific customer account ID in a customer database.Implement both Linear Search and Binary Search algorithms to compare their performance and
usability on different types of lists, demonstrating their practical applications in e-commerce */
#include <iostream>
using namespace std;
class customerid
{
    int id;
    int a[10];
    int n;
public:
    void read();
    void linear();
    void binary();
};
void customerid::read(){
    cout << "Enter the number of customer id in database: ";
    cin >> n;
    if (n < 1 || n > 10)
    {
        cout << "Invalid number of customer IDs";
        n = 0;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the customer id: ";
        cin >> a[i];
    }
}
void customerid::linear(){
    read();
    if (n == 0)
        return;
    int x, found;
    found = 0;
    cout << "Enter the number to be search: ";
    cin >> x;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            cout << "Id found in customer database at "
                 << i + 1 << " position";
            found = 1;
            break;
        }
    }
    if (found == 0)
    {
        cout << "Id not found";
    }
}
void customerid::binary(){
    read();
    if (n == 0)
        return;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    cout << "Sorted customer IDs: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    int mid, low, high, x, found = 0;
    low = 0;
    high = n - 1;
    cout << "\nWhich customer id you want to search? ";
    cin >> x;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x == a[mid])
        {
            cout << "Customer id is present at position "
                 << mid + 1;
            found = 1;
            break;
        }
        else if (x > a[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (found == 0)
    {
        cout << "Customer id is not present";
    }
}
int main(){
    customerid n1;
    int choice, res;
    while (1)
    {
        cout << "\n**************Menu for search**************";
        cout << "\n1. For a linear search ";
        cout << "\n2. For a binary search";
        cout << "\n\nEnter the choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                n1.linear();
                break;
            case 2:
                n1.binary();
                break;
            default:
                cout << "Invalid Choice!";
        }
        cout << "\nDo u want to continue? \n1 to continue/0 to stop: ";
        cin >> res;
        if (res == 0)
        {
            break;
        }
    }
    return 0;
}
