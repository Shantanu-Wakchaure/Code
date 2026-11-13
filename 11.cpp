//11.Design a C++ program to sort employee salaries using both bubble Sort. The program should arrange the salaries in ascending order using each algorithm separately and then display the top five highest salaries from the sorted list.
#include<iostream>
using namespace std;
class sorting{
    int a[10];
    int n;
public:
    void read();
    void display();
    void bubble();
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
    cout << "\nSalaries in ascending order:";
    for(int i = 0; i < n; i++)
    {
        cout << "\nSalary of employee " << i + 1 << ": " << a[i];
    }
}
void sorting::bubble(){
    read();
    if(n == 0)
        return;
    int temp;
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    display();
    topfive();
}
void sorting::topfive(){
    int count = 0;
    cout << "\n\nTop five highest salaries:";
    for(int i = n - 1; i >= 0 && count < 5; i--)
    {
        cout << "\n" << a[i];
        count++;
    }
}
int main(){
    sorting n1;
    n1.bubble();
    return 0;
}
