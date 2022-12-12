#include <iostream>

using namespace std;

// Koostage alamprogramm parameetri väärtuse suurendamiseks ühe võrra
// parameeter on viit
// parameeter on alias
// parameeter on konstant, uus väärtus tagastatakse

void increment(int *num) {
    (*num)++;
}

void increment2(int& num) {
    num++;
}



int increment(const int num) {
    return num + 1;
}



int main(void) {

    const int constant = 10;

    int a = 7;

    int& b = a; // alias, more modern approach

    // viit, mis näitab a aadressi
    int *viit = &a;
    cout << &viit << endl;

    // muuda viida kaudu väärtust

    *viit = 3;

    // trükige a väärtus

    cout << a << " " << *viit << " " << b << endl;

    increment(viit);
    increment2(b);
    cout << increment(constant) << " " << *viit << " " << b << endl;

}