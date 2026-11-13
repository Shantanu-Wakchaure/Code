//13..Design a C++ menu-driven program to implement a Stack using an Linked List .The program  should allow users to perform operations such as push,pop,peek,and display.This will help students understand LIFO behavior and stack operations through interactive execution.
#include <iostream>
using namespace std;
struct node{
    int data;
    node *next;
};
class linked_stack{
    node *head;
public:
    linked_stack()
    {
        head = NULL;
    }
    void push();
    void peek();
    void pop();
    void display();
};
void linked_stack::push(){
    node *nn;
    nn = new node;
    cout << "\nEnter the data: ";
    cin >> nn->data;
    nn->next = NULL;
    if (head == NULL)
    {
        head = nn;
    }
    else
    {
        nn->next = head;
        head = nn;
    }
    cout << nn->data << " is pushed into the stack.";
}
void linked_stack::pop(){
    if (head == NULL)
    {
        cout << "Stack Underflow! Stack is empty.";
    }
    else
    {
        node *temp;
        temp = head;
        cout << temp->data << " is popped out of the stack.";
        head = head->next;
        delete (temp);
    }
}
void linked_stack::peek(){
    if (head == NULL)
    {
        cout << "Stack is empty!";
    }
    else
    {
        cout << head->data << " is at top position in stack.";
    }
}
void linked_stack::display(){
    if (head == NULL)
    {
        cout << "Stack is empty!";
    }
    else
    {
        node *temp;
        cout << "Elements in the stack are: ";
        for (temp = head; temp != NULL; temp = temp->next)
        {
            cout << temp->data;
            if (temp->next != NULL)
            {
                cout << "->";
            }
        }
    }
}
int main(){
    linked_stack n1;
    int choice, res;
    while (1)
    {
        cout << "\n****** MENU for linked stack *****";
        cout << "\n1.push";
        cout << "\n2.pop";
        cout << "\n3.peek";
        cout << "\n4.display";
        cout << "\nEnter the choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            n1.push();
            break;
        case 2:
            n1.pop();
            break;
        case 3:
            n1.peek();
            break;
        case 4:
            n1.display();
            break;
        default:
            cout << "Invalid Choice!";
        }
        cout << "\nDo you want to continue? \n1 to continue / 0 to stop: ";
        cin >> res;
        if (res == 0)
        {
            break;
        }
    }
    return 0;
}
