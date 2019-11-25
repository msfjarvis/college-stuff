#include <iostream>
using namespace std;

void print(int i) { cout << i << endl; }

void print(double i) {
    cout << i << endl;
    ;
}

void print(char const *c) {
    cout << c << endl;
    ;
}

int main() {
    print(10);
    print(10.25);
    print("one");
}