//7.Create a C++ program to implement a singly linked list with operations for insertion,deletion and traverse
#include <iostream>
#include <cstdlib>
using namespace std;
struct node{
    int data;
    node *next;
};
class SLL{
    node *head, *last;
public:
    SLL()
    {
        head = last = NULL;
    }
    void insertfirst();
    void insertlast();
    void insertspecific();
    void display();
    void delfirst();
    void dellast();
    void delspecific();
};
void SLL::insertfirst(){
    node *nn;
    nn = new node;
    cout << "Enter data part: ";
    cin >> nn->data;
    nn->next = NULL;
    if (head == NULL)
    {
        head = last = nn;
    }
    else
    {
        nn->next = head;
        head = nn;
    }
}
void SLL::insertlast(){
    node *nn;
    nn = new node;
    cout << "Enter data part: ";
    cin >> nn->data;
    nn->next = NULL;
    if (head == NULL)
    {
        head = last = nn;
    }
    else
    {
        last->next = nn;
        last = nn;
    }
}
void SLL::insertspecific(){
    int pos;
    node *temp, *nn;
    cout << "At which position u want to insert? ";
    cin >> pos;
    if (pos < 1)
    {
        cout << "Invalid position";
        return;
    }
    nn = new node;
    cout << "Enter data part: ";
    cin >> nn->data;
    nn->next = NULL;
    if (pos == 1)
    {
        nn->next = head;
        head = nn;
        if (last == NULL)
        {
            last = nn;
        }
        cout << "Inserted";
        return;
    }
    else
    {
        temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Invalid position";
            delete nn;
            return;
        }
        nn->next = temp->next;
        temp->next = nn;
        if (temp == last)
        {
            last = nn;
        }
        cout << "Inserted";
    }
}
void SLL::display(){
    node *temp;
    for (temp = head; temp != NULL; temp = temp->next)
    {
        cout << temp->data << "->";
    }
    cout << "NULL\n";
}
void SLL::delfirst()
{
    node *temp;
    if (head == NULL)
    {
        cout << "Linked list is empty";
        return;
    }
    temp = head;
    head = head->next;
    delete (temp);
    if (head == NULL)
    {
        last = NULL;
    }
    display();
}
void SLL::dellast()
{
    if (head == NULL)
    {
        cout << "LL is empty";
        return;
    }
    node *temp = head;
    if (head->next == NULL)
    {
        head = last = NULL;
        delete (temp);
        return;
    }
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete (temp->next);
    temp->next = NULL;
    last = temp;
}
void SLL::delspecific(){
    int pos;
    node *d, *temp;
    cout << "Which position no. you want to delete? ";
    cin >> pos;
    if (head == NULL)
    {
        cout << "LL is empty";
        return;
    }
    if (pos < 1)
    {
        cout << "Invalid position";
        return;
    }
    if (pos == 1)
    {
        delfirst();
        return;
    }
    temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL)
    {
        cout << "Invalid position";
        return;
    }
    d = temp->next;
    temp->next = d->next;
    if (d == last)
    {
        last = temp;
    }
    delete (d);
    display();
}
int main()
{
    SLL s;
    char res;
    int choice;
    while (1){
        cout << "\nBasic operation on SLL" << endl;
        cout << "1.create \n2.display \n3.insertfirst";
        cout << "\n4.insertlast \n5.insertspecific";
        cout << "\n6.deletefirst \n7.deletelast";
        cout << "\n8.delete specific \n9.Exit \n";
        cout << "Enter the choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                s.insertlast();
                break;
            case 2:
                s.display();
                break;
            case 3:
                s.insertfirst();
                break;
            case 4:
                s.insertlast();
                break;
            case 5:
                s.insertspecific();
                break;
            case 6:
                s.delfirst();
                break;
            case 7:
                s.dellast();
                break;
            case 8:
                s.delspecific();
                break;
            case 9:
                exit(0);
            default:
                cout << "Invalid choice";
        }
        cout << "\nDo u want to continue? [y,n]: ";
        cin >> res;
        if (res == 'n' || res == 'N')
        {
            break;
        }
    }
    return 0;
}
