#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stdexcept>
#include <algorithm>
using namespace std;

class Person {
private:
    string name;
    int age;
    string id;
    int contact;

public:
    Person(string name, int age, string id, int contact) 
        : name(name), age(age), id(id), contact(contact) {}

    string getName() const { return name; }
    int getAge() const { return age; }
    string getId() const { return id; }
    int getContact() const { return contact; }

    void setName(string n) {
        if (!n.empty()) name = n;
        else throw invalid_argument("Name cannot be empty.");
    }
    void setAge(int a) {
        if (a > 0 && a < 150) age = a;
        else throw invalid_argument("Invalid age value.");
    }

    virtual void displayDetails() const {
        cout << "Name: " << name << "\nAge: " << age
             << "\nID: " << id << "\nContact: " << contact << endl;
    }

    virtual double calculatePayment() const { return 0.0; }

    virtual ~Person() {}
};

class Student : public Person {
private:
    string enrollDate;
    string program;
    float gpa;

public:
    Student(string name, int age, string id, int contact, string enrollDate, string program, float gpa)
        : Person(name, age, id, contact), enrollDate(enrollDate), program(program), gpa(gpa) {}

    string getEnrollDate() const { return enrollDate; }
    string getProgram() const { return program; }
    float getGpa() const { return gpa; }

    void setGpa(float g) {
        if (g >= 0.0 && g <= 4.0) gpa = g;
        else throw invalid_argument("Invalid GPA value.");
    }

    void displayDetails() const override {
        Person::displayDetails();
        cout << "Enrollment Date: " << enrollDate
             << "\nProgram: " << program
             << "\nGPA: " << gpa << endl;
    }

    double calculatePayment() const override {
        return 500.0;
    }
};

class Professor : public Person {
private:
    string department;
    string specialization;
    string hiredDate;

public:
    Professor(string name, int age, string id, int contact, string department, string specialization, string hiredDate)
        : Person(name, age, id, contact), department(department), specialization(specialization), hiredDate(hiredDate) {}

    string getDepartment() const { return department; }
    string getSpecialization() const { return specialization; }
    string getHiredDate() const { return hiredDate; }

    void displayDetails() const override {
        Person::displayDetails();
        cout << "Department: " << department
             << "\nSpecialization: " << specialization
             << "\nHired Date: " << hiredDate << endl;
    }

    double calculatePayment() const override {
        return 3000.0;
    }
};

class Staff : public Person {
private:
    string role;
    string joiningDate;

public:
    Staff(string name, int age, string id, int contact, string role, string joiningDate)
        : Person(name, age, id, contact), role(role), joiningDate(joiningDate) {}

    string getRole() const { return role; }
    string getJoiningDate() const { return joiningDate; }

    void displayDetails() const override {
        Person::displayDetails();
        cout << "Role: " << role
             << "\nJoining Date: " << joiningDate << endl;
    }

    double calculatePayment() const override {
        return 2000.0;
    }
};

class Course {
private:
    string courseCode;
    string courseName;
    Professor* assignedProfessor;
    vector<Student*> enrolledStudents;

public:
    Course(string courseCode, string courseName)
        : courseCode(courseCode), courseName(courseName), assignedProfessor(nullptr) {}

    string getCourseCode() const { return courseCode; }
    string getCourseName() const { return courseName; }

    void assignProfessor(Professor* prof) {
        assignedProfessor = prof;
    }

    void enrollStudent(Student* student) {
        enrolledStudents.push_back(student);
    }

    void dropStudent(string studentId) {
        enrolledStudents.erase(remove_if(enrolledStudents.begin(), enrolledStudents.end(),
            [studentId](Student* s) { return s->getId() == studentId; }), enrolledStudents.end());
    }

    void displayEnrolledStudents() const {
        cout << "Course: " << courseName << " (" << courseCode << ")" << endl;
        cout << "Students enrolled: \n";
        for (auto s : enrolledStudents) {
            cout << " - " << s->getName() << " (ID: " << s->getId() << ")\n";
        }
    }
};

class Department {
private:
    string departmentName;
    vector<Professor*> professors;
    vector<Course*> courses;

public:
    Department(string departmentName) : departmentName(departmentName) {}

    void addProfessor(Professor* prof) { professors.push_back(prof); }
    void addCourse(Course* course) { courses.push_back(course); }

    void displayProfessors() const {
        cout << "Professors in Department " << departmentName << ":\n";
        for (auto prof : professors) {
            cout << " - " << prof->getName() << endl;
        }
    }
};

class Semester {
private:
    string semesterName;
    vector<Course*> activeCourses;

public:
    Semester(string semesterName) : semesterName(semesterName) {}

    void addCourse(Course* course) { activeCourses.push_back(course); }

    void displayCourses() const {
        cout << "Courses for Semester " << semesterName << ":\n";
        for (auto c : activeCourses) {
            cout << " - " << c->getCourseName() << " (" << c->getCourseCode() << ")\n";
        }
    }
};

class GradeBook {
private:
    map<pair<string, string>, float> grades;

public:
    void addGrade(string studentId, string courseCode, float grade) {
        if (grade < 0.0 || grade > 4.0)
            throw invalid_argument("Grade must be between 0.0 and 4.0");
        grades[{studentId, courseCode}] = grade;
    }

    float getGrade(string studentId, string courseCode) const {
        auto it = grades.find({studentId, courseCode});
        if (it != grades.end())
            return it->second;
        else
            throw runtime_error("Grade not found for student in this course.");
    }

    void displayAllGrades() const {
        for (auto& entry : grades) {
            cout << "Student ID: " << entry.first.first
                 << ", Course Code: " << entry.first.second
                 << ", Grade: " << entry.second << endl;
        }
    }
};

int main() {
    vector<Student*> students;
    vector<Professor*> professors;
    vector<Course*> courses;
    vector<Semester*> semesters;
    GradeBook gradebook;

    while (true) {
        cout << "\n-------------------------- MENU --------------------------\n";
        cout << "1. Create New Semester\n";
        cout << "2. Enroll Student in a Course\n";
        cout << "3. Assign Professor to a Course\n";
        cout << "4. Enter Grade for Student\n";
        cout << "5. View All Grades\n";
        cout << "6. Generate Reports\n";
        cout << "7. Exit\n";
        cout << "----------------------------------------------------------\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        try {
            if (choice == 1) {
                string semesterName;
                cout << "Enter Semester Name: ";
                cin >> semesterName;
                Semester* semester = new Semester(semesterName);
                semesters.push_back(semester);
                cout << "Semester " << semesterName << " created successfully.\n";
            } 
            else if (choice == 2) {
                string studentId, courseCode;
                cout << "Enter Student ID: ";
                cin >> studentId;
                cout << "Enter Course Code: ";
                cin >> courseCode;

                Student* student = nullptr;
                for (auto s : students) {
                    if (s->getId() == studentId) {
                        student = s;
                        break;
                    }
                }
                if (!student) throw invalid_argument("Student not found!");

                Course* course = nullptr;
                for (auto c : courses) {
                    if (c->getCourseCode() == courseCode) {
                        course = c;
                        break;
                    }
                }
                if (!course) throw invalid_argument("Course not found!");

                course->enrollStudent(student);
                cout << studentId << " enrolled in " << courseCode << " successfully.\n";
            } 
            else if (choice == 3) {
                string professorId, courseCode;
                cout << "Enter Professor ID: ";
                cin >> professorId;
                cout << "Enter Course Code: ";
                cin >> courseCode;

                Professor* professor = nullptr;
                for (auto p : professors) {
                    if (p->getId() == professorId) {
                        professor = p;
                        break;
                    }
                }
                if (!professor) throw invalid_argument("Professor not found!");

                Course* course = nullptr;
                for (auto c : courses) {
                    if (c->getCourseCode() == courseCode) {
                        course = c;
                        break;
                    }
                }
                if (!course) throw invalid_argument("Course not found!");

                course->assignProfessor(professor);
                cout << professorId << " assigned to course " << courseCode << " successfully.\n";
            } 
            else if (choice == 4) {
                string studentId, courseCode;
                float grade;
                cout << "Enter Student ID: ";
                cin >> studentId;
                cout << "Enter Course Code: ";
                cin >> courseCode;
                cout << "Enter Grade (0.0 - 4.0): ";
                cin >> grade;

                gradebook.addGrade(studentId, courseCode, grade);
                cout << "Grade for " << studentId << " in " << courseCode << " entered successfully.\n";
            } 
            else if (choice == 5) {
                gradebook.displayAllGrades();
            } 
            else if (choice == 6) {
                string reportType;
                cout << "Enter Report Type (Courses / Professors / Students): ";
                cin >> reportType;

                if (reportType == "Courses") {
                    for (auto course : courses) {
                        course->displayEnrolledStudents();
                    }
                } 
                else if (reportType == "Professors") {
                    for (auto professor : professors) {
                        professor->displayDetails();
                    }
                } 
                else if (reportType == "Students") {
                    for (auto student : students) {
                        student->displayDetails();
                    }
                } 
                else {
                    cout << "Invalid report type.\n";
                }
            } 
            else if (choice == 7) {
                cout << "Exiting program.\n";
                break;
            } 
            else {
                cout << "Invalid choice, please try again.\n";
            }
        } 
        catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    for (auto s : students) delete s;
    for (auto p : professors) delete p;
    for (auto c : courses) delete c;
    for (auto s : semesters) delete s;

    return 0;
}
