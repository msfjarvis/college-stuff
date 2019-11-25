#include <iostream>
using namespace std;

class StaticUse {
    static int a;

  public:
    static int b;
};

int StaticUse::a = 100;
int StaticUse::b = 110;

int main() {
    // cout << "a : " << StaticUse :: a << endl; Cannot use private static in
    // main
    cout << "b : " << StaticUse ::b << endl;

    StaticUse obj;
    cout << "b : " << obj.b << endl; // Okay but don't do this
}