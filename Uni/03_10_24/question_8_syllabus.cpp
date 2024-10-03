//Design three classes: Student, Exam and Result. 
//The student class has data members such as roll no, name etc. 
//Create a class Exam by inheriting the Student class. 
//The Exam class adds data members representing the marks scored in six subjects. 
//Derive the Result from class Exam and it has its own members such as total marks. 
//Write an interactive program to model this relationship. What type of inheritance this model belongs to? do it in C++ 
//Answer - This model uses multilevel inheritance, as Exam inherits from Student, and Result inherits from Exam.

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Student { // this is derived class
protected:
    int roll_no;
    string name;

public:
    Student(int r, string n) : roll_no(r), name(n) {}

    void displayInfo() {
        cout << "Roll No: " << roll_no << endl;
        cout << "Name: " << name << endl;
    }
};


class Exam : public Student { //this is derived class
protected:
    vector<float> marks;

public:
    Exam(int r, string n, vector<float> m) : Student(r, n), marks(m) {}

    void displayMarks() {
        cout << "Marks in Subjects:" << endl;
        for (size_t i = 0; i < marks.size(); ++i) {
            cout << "Subject " << (i + 1) << ": " << marks[i] << endl;
        }
    }
};

class Result : public Exam { //another derived class
private:
    float total_marks;

public:
    Result(int r, string n, vector<float> m) : Exam(r, n, m) {
        total_marks = calculateTotal();
    }

    float calculateTotal() {
        return accumulate(marks.begin(), marks.end(), 0.0);
    }

    void displayResult() {
        displayInfo();
        displayMarks();
        cout << "Total Marks: " << total_marks << endl;
    }
};

int main() {
    int roll_no;
    string name;
    vector<float> marks(6);

    cout << "Enter Student Details:" << endl;
    cout << "Roll No: ";
    cin >> roll_no;
    cout << "Name: ";
    getline(cin, name);

    for (int i = 0; i < 6; ++i) {
        cout << "Enter marks for Subject " << (i + 1) << ": ";
        cin >> marks[i];
    }

    Result result(roll_no, name, marks);
    cout << "\nStudent Result:" << endl;
    result.displayResult();

    return 0;
}
//Answer - This uses multilevel inheritance, as Exam inherits from Student, and Result inherits from Exam.