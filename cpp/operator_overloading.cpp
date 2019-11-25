#include <iostream>
using namespace std;

class Fraction {
    int numerator;
    int denominator;

  public:
    Fraction(int num, int den) {
        numerator = num;
        denominator = den;
    }

    void display() {
        cout << "Numerator : " << numerator << " Denominator : " << denominator
             << endl;
    }

    Fraction operator+(Fraction const &f) {
        int lcm = denominator * f.denominator;
        Fraction fnew(numerator * f.denominator + f.numerator * denominator,
                      lcm);
        fnew.simplify();
        return fnew;
    }

    Fraction operator-(Fraction const &f) {
        int lcm = denominator * f.denominator;
        Fraction fnew(numerator * f.denominator - f.numerator * denominator,
                      lcm);
        fnew.simplify();
        return fnew;
    }

    Fraction operator*(Fraction const &f) {
        Fraction fnew(numerator * f.numerator, denominator * f.denominator);
        fnew.simplify();
        return fnew;
    }

    Fraction operator/(Fraction const &f) {
        Fraction fnew(numerator * f.denominator, denominator * f.numerator);
        fnew.simplify();
        return fnew;
    }

    bool operator==(Fraction const &f) {
        if (f.numerator == numerator && f.denominator == denominator)
            return true;
        return false;
    }

    // Pre-Increment
    /*
        Here we are returning by reference. Returning by reference helps it as
       now the function can also be used as an lvalue. Noice.
     */
    Fraction &operator++() {
        numerator += denominator;
        simplify();
        return *this;
    }

    // Post increment
    // Nesting of PI operator is not allowed
    Fraction operator++(int) {
        Fraction fnew(numerator, denominator);
        numerator += denominator;
        simplify();
        return fnew;
    }

    Fraction &operator+=(Fraction const &f) {
        int lcm = denominator * f.denominator;
        numerator = numerator * f.denominator + f.numerator * denominator;
        denominator = lcm;
        simplify();
        return *this;
    }

    void simplify() {
        int m = min(numerator, denominator);
        for (int i = 2; i <= m; i++) {
            if (numerator % i == 0 && denominator % i == 0) {
                this->numerator /= i;
                this->denominator /= i;
                i--;
            }
        }
    }

    int min(int a, int b) {
        if (a <= b) {
            return a;
        } else {
            return b;
        }
    }
};

int main() {
    Fraction f1(1, 2);
    Fraction f2(1, 2);
    if (f1 == f2) {
        Fraction f3 = f1 + f2;
        f3.display();
    }
    ++(++f1);
    f1.display();
}