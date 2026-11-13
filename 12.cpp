//12.Design a C++ menu-driven program to implement a Stack using an array.The program should allow users to perform operations such as push,pop,peek,and display.This will help students understand LIFO behavior and stack operations through interactive execution.
#include<iostream>
using namespace std;
class stack{
    int n[10];
    int top;
public:
    stack()
    {
        top = -1;
    }
    void push();
    void pop();
    void peek();
    void display();
};
void stack::push(){
    int s;
    if(top == 9)
    {
        cout << "Stack Overflow!";
    }
    else
    {
        cout << "Enter value to be push in stack: ";
        cin >> s;
        top++;
        n[top] = s;
        cout << s << " is pushed in the stack";
    }
}
void stack::pop(){
    if(top == -1)
    {
        cout << "Stack Underflow!";
    }
    else
    {
        int temp;
        temp = n[top];
        cout << temp << " is popped out of the stack";
        top--;
    }
}
void stack::peek(){
    if(top == -1)
    {
        cout << "Stack is empty!";
    }
    else
    {
        cout << n[top] << " is the element at top of the stack";
    }
}
void stack::display(){
    if(top == -1)
    {
        cout << "Stack is empty!";
    }
    else
    {
        cout << "Elements in the stack are : ";
        for(int i = 0; i <= top; i++)
        {
            cout << "\n" << n[i];
        }
    }
}
int main(){
    stack n1;
    int choice, res;
    while (1)
    {
        cout << "\n**************Menu for Stack**************";
        cout << "\n1.push ";
        cout << "\n2.pop";
        cout << "\n3.peek";
        cout << "\n4.display";
        cout << "\nEnter the choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1: n1.push();
                    break;
            case 2: n1.pop();
                    break;
            case 3: n1.peek();
                    break;
            case 4: n1.display();
                    break;
            default: cout << "Invalid Choice!";
        }
        cout << "\nDo u want to continue? \n1 to continue/0 to stop: ";
        cin >> res;
        if(res == 0)
        {
            break;
        }
    }
    return 0;
}
