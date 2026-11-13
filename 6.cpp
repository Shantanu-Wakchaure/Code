/*6..Develop a C++ program to implement a Student Marks Management System using a two
dimensional array. The program should accept the number of students and the number of
subjects as input and store the marks obtained by each student in different subjects using a 2D
array.
The program should perform the following operations:
1. Accept the names or roll numbers of students and their marks in multiple subjects.
2.Store the marks in a two-dimensional array,where each row represents a student and each
column represents a subject.
3. Display the student marks in a tabular format with appropriate row and column headings.
4. Calculate and display the total marks obtained by each student across all subjects.
5. Calculate and display the average marks obtained in each subject across all students.
6. Display the results in a properly formatted table.*/
#include <iostream>
#include <string>
using namespace std;
class Array {
    int a[20][20];
    int student, subject;
    string name[20];
public:
    void read();
    void display();
    void per();
    void avg();
};
void Array::read() {
    cout << "How many students? ";
    cin >> student;
    cout << "How many subjects? ";
    cin >> subject;
    for (int i = 0; i < student; i++) {
        cout << "\nEnter name of student " << i + 1 << ": ";
        cin >> ws;
        cin>>name[i];
        cout << "Enter marks of student " << i + 1 << endl;
        for (int j = 0; j < subject; j++) {
            cout << "Enter marks of subject " << j + 1 << ": ";
            cin >> a[i][j];
        }
    }
}
void Array::display() {
    cout << "\nStudent Marks Table\n";
    cout << "Name\t\t";
    for (int i = 0; i < subject; i++) {
        cout << "Sub" << i + 1 << "\t";
    }
    cout << endl;
    for (int i = 0; i < student; i++) {
        cout << name[i] << "\t\t";
        for (int j = 0; j < subject; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}
void Array::per() {
    int total;
    cout << "\nTotal Marks of Each Student\n";
    for (int i = 0; i < student; i++) {
        total = 0;
        for (int j = 0; j < subject; j++) {
            total += a[i][j];
        }
        cout << "Total marks of " << name[i] << ": "
             << total << endl;
    }
}
void Array::avg() {
    int total;
    float average;
    cout << "\nAverage Marks of Each Subject\n";
    for (int i = 0; i < subject; i++) {
        total = 0;
        for (int j = 0; j < student; j++) {
            total += a[j][i];
        }
        average = (float)total / student;
        cout << "Average marks of subject " << i + 1
             << ": " << average << endl;
    }
}
int main() {
    Array n1;
    n1.read();
    n1.display();
    n1.per();
    n1.avg();
    return 0;
}
