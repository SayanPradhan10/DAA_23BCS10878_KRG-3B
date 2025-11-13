#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;

class Student {
private:
    int roll;
    string name;
    float marks;

public:
    Student();
    Student(int r, string n, float m);

    void display();
    int getRoll();
    string getName();
    float getMarks();
};

#endif
