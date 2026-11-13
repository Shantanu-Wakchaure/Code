//14.Write a C++ program to implement a queue using the array,supporting basic operations such as enqueue, dequeue, and traversal to display the queue elements.
#include<iostream>
#define MAX 10
using namespace std;
class queue{
    int q[MAX];
    int front;
    int rear;
public:
    queue()
    {
        front = rear = -1;
    }
    void enqueue();
    void dequeue();
    void display();
};
void queue::enqueue(){
    int n;
    if (rear == MAX - 1)
    {
        cout << "Queue is Full!";
    }
    else
    {
        cout << "Enter the value: ";
        cin >> n;
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        q[rear] = n;
        cout << n << " is inserted";
    }
}
void queue::dequeue(){
    if (front == -1)
    {
        cout << "Queue is Empty!";
    }
    else
    {
        cout << q[front] << " is deleted";
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
    }
}
void queue::display(){
    if (front == -1)
    {
        cout << "Queue is Empty!";
    }
    else
    {
        cout << "Elements in the queue are: ";
        for (int i = front; i <= rear; i++)
        {
            cout << q[i] << "\t";
        }
    }
}
int main(){
    queue n1;
    int choice, res;
    while (1)
    {
        cout << "\n************Menu for Queue*************\n";
        cout << "\n1.enqueue";
        cout << "\n2.dequeue";
        cout << "\n3.display";
        cout << "\nEnter the choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1: n1.enqueue();
                    break;
            case 2: n1.dequeue();
                    break;
            case 3: n1.display();
                    break;
            default: cout << "Invalid Choice!";
        }
        cout << "\nDo u want to continue? \n(1 to continue/0 to stop): ";
        cin >> res;
        if(res == 0)
        {
            break;
        }
    }
    return 0;
}
