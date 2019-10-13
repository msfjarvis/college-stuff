#include <iostream>
using namespace std;

/*
    Only functions that do not modify the property can be set as const functions.
    Const objects can only call const functions.
 */

class Student {
    int age;
    int rno;

    public:

    Student(int age, int rno) {
        this -> age = age;
        this -> rno = rno;
    }

    int getAge() const {
        return age;
    }

    int getRno() const {
        return rno;
    }

// Calling these will show error

    void setAge(int age) {
        this -> age = age;
    }

    void setRno() {
        this -> rno = rno;
    }
};

int main() {
    const Student s1(10, 11);
    cout << "Age : " << s1.getAge() << " Rno : " << s1.getRno() << endl;

    // s1.setAge(111);
    cout << "Age : " << s1.getAge() << " Rno : " << s1.getRno() << endl;
}