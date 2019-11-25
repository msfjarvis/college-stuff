#include <iostream>
using namespace std;

class Student {
    int age;
    const int rollNumber;
    int &ageRef;

  public:
    Student(int age, int rno) : age(age), rollNumber(rno), ageRef(this->age) {
        cout << "Constructor called" << endl;
    }

    void display() {
        cout << "Age : " << this->age << " AgeRef : " << this->ageRef
             << " RollNumber : " << this->rollNumber << endl;
    }
};

int main() {
    Student s1(10, 1);
    s1.display();
}