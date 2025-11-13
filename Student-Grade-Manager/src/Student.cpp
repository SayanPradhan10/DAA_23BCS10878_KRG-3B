#include "Student.h"

Student::Student() {}

Student::Student(int r, string n, float m) {
    roll = r;
    name = n;
    marks = m;
}

int Student::getRoll() { return roll; }
string Student::getName() { return name; }
float Student::getMarks() { return marks; }

void Student::display() {
    cout << "Roll: " << roll 
         << " | Name: " << name 
         << " | Marks: " << marks << endl;
}
