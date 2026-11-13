//10..Design a C++ program to sort employee salaries using both Selection Sort. The program should arrange the salaries in ascending order using each algorithm separately and then display the top five highest salaries from the sorted list.
#include<iostream>
using namespace std;
class sorting{
    int a[10];
    int n;
public:
    void read();
    void display();
    void selection();
    void topfive();
};
void sorting::read(){
    cout << "How many employee's salary in list: ";
    cin >> n;
    if(n < 1 || n > 10)
    {
        cout << "Invalid number of employees";
        n = 0;
        return;
    }
    for(int i = 0; i < n; i++)
    {
        cout << "\nEnter the salary of employee " << i + 1 << ": ";
        cin >> a[i];
    }
}
void sorting::display(){
    cout << "\nSalaries in ascending order: ";

    for(int i = 0; i < n; i++)
    {
        cout << "\nSalary of employee " << i + 1 << ": " << a[i];
    }
}
void sorting::selection(){
    read();
    if(n == 0)
        return;
    int minimum;
    int temp;
    for(int i = 0; i < n - 1; i++)
    {
        minimum = i;
        for(int j = i + 1; j < n; j++)
        {
            if(a[j] < a[minimum])
            {
                minimum = j;
            }
        }
        temp = a[i];
        a[i] = a[minimum];
        a[minimum] = temp;
    }
    display();
    topfive();
}
void sorting::topfive(){
    int count = 0;
    cout << "\n\nTop five highest salaries: ";
    for(int i = n - 1; i >= 0 && count < 5; i--)
    {
        cout << "\n" << a[i];
        count++;
    }
}
int main(){
    sorting n1;
    n1.selection();
    return 0;
}
