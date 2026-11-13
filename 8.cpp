//8.Create a C++ program to implement a singly linked list with operations for insertion,deletion and searching using dynamic memory allocation.
#include <iostream>
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
    void search();
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
void SLL::insertspecific()
{
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
    }
    cout << "Inserted";
}
void SLL::display(){
    node *temp;
    for (temp = head; temp != NULL; temp = temp->next)
    {
        cout << temp->data << "->";
    }
    cout << "NULL\n";
}
void SLL::search(){
    int x;
    cout << "Which no. u want to search? ";
    cin >> x;
    if (head == NULL)
    {
        cout << "List is empty";
        return;
    }
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == x)
        {
            cout << "No. found";
            return;
        }
        temp = temp->next;
    }
    cout << "No. not found";
}
void SLL::delfirst(){
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
void SLL::dellast(){
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
void SLL::delspecific()
{
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
    while (1)
    {
        cout << "\nBasic operation on SLL" << endl;
        cout << "1.create \n2.display \n3.insertfirst";
        cout << "\n4.insertlast \n5.insertspecific";
        cout << "\n6.search \n7.deletefirst";
        cout << "\n8.deletelast \n9.delete specific";
        cout << "\n10.Exit \n";
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
                s.search();
                break;
            case 7:
                s.delfirst();
                break;
            case 8:
                s.dellast();
                break;
            case 9:
                s.delspecific();
                break;
            case 10:
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
