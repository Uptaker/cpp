#include <iostream>
#include <string>
using namespace std;

// endl places a new line

int main (void) {
    string firstName, lastName;
    int age;
    cout << "Enter your first name ";
    cin >> firstName;
    cout << "Enter your last name ";
    cin >> lastName;
    cout << "Enter your age ";
    cin >> age;

    if (age == 666) cout << "The number of the beast!" << endl;
    else cout << "Hello, " << firstName << " " << lastName << ", born circa " << (2022 - age) << endl;
}