#include <iostream>

using namespace std;

int main(void) {
    int a = 7;

    int& b = a; // alias, more modern approach

    // viit, mis näitab a aadressi
    int *viit = &a;
    cout << &viit << endl;

    // muuda viida kaudu väärtust

    *viit = 3;

    // trükige a väärtus

    cout << a << " " << *viit << " " << b << endl;
}