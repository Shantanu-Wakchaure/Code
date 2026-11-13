//15.Write a C++ program to implement a queue using the using linked list, supporting basic operations such as enqueue, dequeue, and traversal to display the queue elements.
#include <iostream>
using namespace std;
struct node{
    int data;
    node *next;
};
class linked_queue{
    node *head, *last;
public:
    linked_queue()
    {
        head = NULL;
        last = NULL;
    }
    void enqueue();
    void dequeue();
    void display();
};
void linked_queue::enqueue(){
    node *nn;
    nn = new node;
    cout << "Enter the data: ";
    cin >> nn->data;
    nn->next = NULL;
    if (head == NULL)
    {
        head = nn;
        last = nn;
    }
    else
    {
        last->next = nn;
        last = nn;
    }
    cout << "Element inserted successfully.\n";
}
void linked_queue::dequeue(){
    if (head == NULL)
    {
        cout << "Queue is empty!\n";
        return;
    }
    node *temp;
    temp = head;
    head = head->next;
    if (head == NULL)
    {
        last = NULL;
    }
    delete temp;
    cout << "Element deleted successfully.\n";
}
void linked_queue::display(){
    if (head == NULL)
    {
        cout << "Queue is empty!\n";
        return;
    }
    node *temp;
    cout << "Queue: ";
    for (temp = head; temp != NULL; temp = temp->next)
    {
        cout << temp->data;
        if (temp->next != NULL)
        {
            cout << " -> ";
        }
    }
    cout << endl;
}
int main(){
    linked_queue n1;
    int choice, res;
    while (1)
    {
        cout << "\n************ Menu for Queue ************\n";
        cout << "1. Enqueue an element\n";
        cout << "2. Dequeue an element\n";
        cout << "3. Display the queue\n";
        cout << "Enter the choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                n1.enqueue();
                break;
            case 2:
                n1.dequeue();
                break;
            case 3:
                n1.display();
                break;
            default:
                cout << "Invalid Choice!\n";
        }
        cout << "\nDo you want to continue?\n";
        cout << "(1 to continue / 0 to stop): ";
        cin >> res;
        if (res == 0)
        {
            break;
        }
    }
    return 0;
}
