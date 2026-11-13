//1.Create a Student ADT in C++ to manage student details and compare two students based on their marks.
#include <iostream>
#include <string>
using namespace std;
class Student {
private:
    int rollNo;
    string name;
    float marks;
public:
    void createRecord() {
        cout<<"Enter Roll Number: ";
        cin>>rollNo;
        cin.ignore();
        cout<<"Enter Name: ";
        cin>>name;
        cout<<"Enter Marks: ";
        cin>>marks;
    }
    void displayRecord() {
        cout<<"Roll No: "<<rollNo<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Marks: "<<marks<<endl;
    }
    void updateMarks(float newMarks) {
        marks = newMarks;
    }
    float getMarks() {
        return marks;
    }
    string getName() {
        return name;
    }
    void compareStudents(Student &s2) {
        if(marks>s2.marks)
            cout<<name<<" scored more than "<<s2.name<<endl;
        else if(marks<s2.marks)
            cout<<s2.name<<" scored more than "<<name<<endl;
        else
            cout<<"Both students scored equal marks"<<endl;
    }
};
int main() {
    Student s1, s2;
    float newMarks;
    cout<<"----- Enter details of Student 1 -----"<<endl;
    s1.createRecord();
    cout<<"\n----- Enter details of Student 2 -----"<<endl;
    s2.createRecord();
    cout<<"\n--- Student 1 Record ---"<<endl;
    s1.displayRecord();
    cout<<"\n--- Student 2 Record ---"<<endl;
    s2.displayRecord();
    cout<<"\nEnter updated marks for Student 1: ";
    cin>>newMarks;
    s1.updateMarks(newMarks);
    cout<<"\nAfter updating Student 1 marks:"<<endl;
    s1.displayRecord();
    cout<<"\n--- Comparing Student 1 and Student 2 ---"<<endl;
    s1.compareStudents(s2);
    return 0;
}
