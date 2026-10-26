
#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int rollNo;
    float marks;

    void input() {
        cout << "Enter student name: ";
        getline(cin >> ws, name);

        cout << "Enter roll number: ";
        cin >> rollNo;

        cout << "Enter marks out of 100: ";
        cin >> marks;

        while (marks < 0 || marks > 100) {
            cout << "Invalid marks! Enter marks between 0 and 100: ";
            cin >> marks;
        }
    }

    void display() {
        cout << "\nName: " << name << endl;
        cout << "Roll Number: " << rollNo << endl;
        cout << "Marks: " << marks << endl;

        if (marks >= 90)
            cout << "Grade: A+" << endl;
        else if (marks >= 80)
            cout << "Grade: A" << endl;
        else if (marks >= 70)
            cout << "Grade: B" << endl;
        else if (marks >= 60)
            cout << "Grade: C" << endl;
        else if (marks >= 40)
            cout << "Grade: D" << endl;
        else
            cout << "Grade: F" << endl;
    }
};

int main() {
    Student students[100];
    int count = 0;
    int choice;

    do {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. View All Students" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (count < 100) {
                students[count].input();
                count++;
                cout << "Student added successfully!" << endl;
            } else {
                cout << "Student limit reached!" << endl;
            }
            break;

        case 2:
            if (count == 0) {
                cout << "No student records available." << endl;
            } else {
                for (int i = 0; i < count; i++) {
                    cout << "\n--- Student " << i + 1 << " ---";
                    students[i].display();
                }
            }
            break;

        case 3:
            cout << "Thank you for using the system!" << endl;
            break;

        default:
            cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 3);

    return 0;
}
