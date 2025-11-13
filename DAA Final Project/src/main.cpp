#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
#include "Student.h"
using namespace std;

vector<Student> students;

// Save to file
void saveToFile() {
    ofstream out("data/students.txt");
    for (auto &s : students) {
        out << s.getRoll() << " " << s.getName() << " " << s.getMarks() << endl;
    }
    out.close();
}

// Load from file
void loadFromFile() {
    ifstream in("data/students.txt");
    int roll;
    string name;
    float marks;
    while (in >> roll >> name >> marks) {
        students.push_back(Student(roll, name, marks));
    }
    in.close();
}

void addStudent() {
    int roll;
    string name;
    float marks;

    cout << "Enter roll number: ";
    while(!(cin >> roll)) {
        cout << "Please enter a valid integer for roll: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Enter name: ";
    cin >> ws;
    getline(cin, name);
    cout << "Enter marks: ";
    while(!(cin >> marks)) {
        cout << "Please enter a valid number for marks: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    students.push_back(Student(roll, name, marks));
    saveToFile();
    cout << "Student added successfully!" << endl;
}

void displayAll() {
    if (students.empty()) {
        cout << "No students found." << endl;
        return;
    }
    for (auto &s : students) s.display();
}

int main() {
    loadFromFile();
    int choice;

    while (true) {
        cout << "\n===== STUDENT GRADE MANAGER =====\n";
        cout << "1. Add Student\n";
        cout << "2. View All Students\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        if(!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice. Try again.\n";
        }
    }
}
