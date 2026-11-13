//5.Design a C++ program to perform basic operations on arrays.The program should first use a 1D array to insert, delete, search, and update elements.
#include <iostream>
using namespace std;
class Array {
    int n;
    int a[20];
public:
    void read();
    void display();
    void insert();
    void search();
    void update();
    void del();
};
void Array::read() {
    cout << "How many values of array: ";
    cin >> n;
    cout << "\nEnter the values: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}
void Array::display() {
    cout << "\nArray Values: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}
void Array::insert() {
    int pos, value;
    cout << "\nEnter at which position new value is to be added: ";
    cin >> pos;
    cout << "\nEnter the value to be added: ";
    cin >> value;
    if (pos < 0 || pos > n || n >= 20) {
        cout << "\nInvalid Position!";
        return;
    }
    for (int i = n; i > pos; i--) {
        a[i] = a[i - 1];
    }
    a[pos] = value;
    n++;
    display();
}
void Array::search() {
    int x, found = 0;
    cout << "\nEnter the number to be found: ";
    cin >> x;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            cout << "\n" << x << " found at index: " << i;
            found = 1;
            break;
        }
    }
    if (found == 0)
        cout << "\nNumber Not found!";
}
void Array::update() {
    int y, index;
    cout << "\nEnter the index to be updated: ";
    cin >> index;
    if (index < 0 || index >= n) {
        cout << "\nInvalid Index!";
        return;
    }
    cout << "\nEnter the value: ";
    cin >> y;
    a[index] = y;
    cout << "\nUpdated Successfully";
    display();
}
void Array::del() {
    int z;
    cout << "\nEnter the index to be deleted: ";
    cin >> z;
    if (z < 0 || z >= n) {
        cout << "\nInvalid Index!";
        return;
    }
    for (int i = z; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    cout << "\nElement is deleted";
    n--;
    display();
}
int main() {
    Array n1;
    int res, choice;
    n1.read();
    n1.display();
    while (1) {
        cout << "\nBasic operations on array:" << endl;
        cout << "1. Insert\n2. Search\n3. Update\n4. Delete\n";
        cout << "Enter the choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                n1.insert();
                break;
            case 2:
                n1.search();
                break;
            case 3:
                n1.update();
                break;
            case 4:
                n1.del();
                break;
            default:
                cout << "Invalid Choice!";
        }
        cout << "\nDo you want to continue? (1 to continue / 0 to stop): ";
        cin >> res;
        if (res == 0)
            break;
    }
    return 0;
}
