#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    float cgpa;
    vector<string> courses;

public:
    Student() : name("Unknown"), rollNumber(0), cgpa(0.0f) {}

    Student(string name, int rollNumber, float cgpa) {
        this->name = name;
        this->rollNumber = rollNumber;
        if (cgpa >= 0.0f && cgpa <= 10.0f)
            this->cgpa = cgpa;
        else {
            this->cgpa = 0.0f;
            cout << "Invalid CGPA. Set to 0.0 by default.\n";
        }
    }

    Student(const Student& other) {
        name = other.name;
        rollNumber = other.rollNumber;
        cgpa = other.cgpa;
        courses = other.courses;
    }

    ~Student() {
    }

    void addCourse(const string& course) {
        if (course.empty()) {
            cout << "Course name cannot be empty!\n";
            return;
        }
        courses.push_back(course);
    }

    void updateCGPA(float newCGPA) {
        if (newCGPA >= 0.0f && newCGPA <= 10.0f)
            cgpa = newCGPA;
        else
            cout << "Invalid CGPA. Must be between 0.0 and 10.0\n";
    }

    void displayInfo() const {
        cout << "Name: " << name << "\n";
        cout << "Roll Number: " << rollNumber << "\n";
        cout << "CGPA: " << cgpa << "\n";
        cout << "Courses: ";
        if (courses.empty()) {
            cout << "None";
        } else {
            for (const string& course : courses)
                cout << course << " ";
        }
        cout << "\n-------------------------\n";
    }

    int getRollNumber() const {
        return rollNumber;
    }
};

class StudentManagementSystem {
private:
    vector<Student> students;

public:
    void addStudent(const Student& s) {
        students.push_back(s);
    }

    Student* searchStudent(int rollNo) {
        for (auto& s : students) {
            if (s.getRollNumber() == rollNo)
                return &s;
        }
        return nullptr;
    }

    void displayAllStudents() const {
        if (students.empty()) {
            cout << "No student records found.\n";
            return;
        }
        for (const auto& s : students) {
            s.displayInfo();
        }
    }
};

int main() {
    StudentManagementSystem sms;
    int choice;

    do {
        cout << "\n----- Student Management System -----\n";
        cout << "1. Add New Student\n";
        cout << "2. Add Course to Student\n";
        cout << "3. Update CGPA\n";
        cout << "4. Search Student by Roll Number\n";
        cout << "5. Display All Students\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            int roll;
            float cgpa;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Roll Number: ";
            cin >> roll;
            cout << "Enter CGPA: ";
            cin >> cgpa;
            Student s(name, roll, cgpa);
            sms.addStudent(s);
            cout << "Student added successfully.\n";
        }
        else if (choice == 2) {
            int roll;
            string course;
            cout << "Enter Roll Number: ";
            cin >> roll;
            Student* s = sms.searchStudent(roll);
            if (s) {
                cout << "Enter Course Name: ";
                cin.ignore();
                getline(cin, course);
                s->addCourse(course);
                cout << "Course added.\n";
            } else {
                cout << "Student not found.\n";
            }
        }
        else if (choice == 3) {
            int roll;
            float newCGPA;
            cout << "Enter Roll Number: ";
            cin >> roll;
            Student* s = sms.searchStudent(roll);
            if (s) {
                cout << "Enter New CGPA: ";
                cin >> newCGPA;
                s->updateCGPA(newCGPA);
                cout << "CGPA updated.\n";
            } else {
                cout << "Student not found.\n";
            }
        }
        else if (choice == 4) {
            int roll;
            cout << "Enter Roll Number: ";
            cin >> roll;
            Student* s = sms.searchStudent(roll);
            if (s) {
                s->displayInfo();
            } else {
                cout << "Student not found.\n";
            }
        }
        else if (choice == 5) {
            sms.displayAllStudents();
        }
        else if (choice == 0) {
            cout << "Exiting program.\n";
        }
        else {
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}
