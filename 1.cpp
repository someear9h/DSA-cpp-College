#include <iostream>
using namespace std;

class Student {
    int rollNo;
    string name;
    float sgpa;

public:
    // Default constructor
    Student() {
        rollNo = 0;
        name = "";
        sgpa = 0.0;
    }

    // Parameterized constructor
    Student(int r, string n, float s) {
        rollNo = r;
        name = n;
        sgpa = s;
    }

    // Get SGPA
    float getSGPA() {
        return sgpa;
    }

    // Get Roll Number
    int getRollNo() {
        return rollNo;
    }

    // Get Name
    string getName() {
        return name;
    }
};

// Function to display all students in a table
void displayAllStudents(Student students[], int n) {
    cout << "\nAll Students:\n";
    cout << "--------------------------------------------------------\n";
    cout << "| Roll No |        Name        |    SGPA   |\n";
    cout << "--------------------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << "| " << students[i].getRollNo();
        cout << string(8 - to_string(students[i].getRollNo()).length(), ' '); // Space after Roll No
        cout << "| " << students[i].getName();
        cout << string(18 - students[i].getName().length(), ' '); // Space after Name
        cout << "| " << students[i].getSGPA();
        cout << string(10 - to_string(students[i].getSGPA()).length(), ' '); // Space after SGPA
        cout << "|\n";
    }
    cout << "--------------------------------------------------------\n";
}

// Function to search students by SGPA
void searchBySGPA(Student students[], int n, float targetSGPA) {
    bool found = false;
    cout << "\nStudents with SGPA " << targetSGPA << ":\n";
    cout << "--------------------------------------------------------\n";
    cout << "| Roll No |        Name        |    SGPA   |\n";
    cout << "--------------------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        if (students[i].getSGPA() == targetSGPA) {
            cout << "| " << students[i].getRollNo();
            cout << string(8 - to_string(students[i].getRollNo()).length(), ' '); // Space after Roll No
            cout << "| " << students[i].getName();
            cout << string(18 - students[i].getName().length(), ' '); // Space after Name
            cout << "| " << students[i].getSGPA();
            cout << string(10 - to_string(students[i].getSGPA()).length(), ' '); // Space after SGPA
            cout << "|\n";
            found = true;
        }
    }
    cout << "--------------------------------------------------------\n";

    if (!found) {
        cout << "No students found with SGPA " << targetSGPA << "." << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student* students = new Student[n]; // Dynamically allocate memory for students

    // Input details for all students
    for (int i = 0; i < n; i++) {
        int rollNo;
        string name;
        float sgpa;

        cout << "\nEnter details for student " << (i + 1) << ":" << endl;
        cout << "Roll No: ";
        cin >> rollNo;
        cout << "Name: ";
        cin >> name;
        cout << "SGPA: ";
        cin >> sgpa;

        students[i] = Student(rollNo, name, sgpa); // Initialize student object
    }

    // Display all students in a table
    displayAllStudents(students, n);

    // Search for students by SGPA
    float targetSGPA;
    cout << "\nEnter SGPA to search for: ";
    cin >> targetSGPA;
    searchBySGPA(students, n, targetSGPA);

    delete[] students; // Free dynamically allocated memory
    return 0;
}
