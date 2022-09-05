#include <iostream>
#include <string>
using namespace std;

void calculate() {

}

int* split(string str, string delimiter, int *arr) {
    int start = 0;
    int index = 0;
    int end = str.find(" ");
    while (end != -1) {
        arr[index] = stoi(str.substr(start, end - start));
        start = end + delimiter.size();
        end = str.find(" ", start);
        if (end == -1) arr[index + 1] = stoi(str.substr(start, end));
    };
}

int main (void) {
    string inputsSpaceSeparated;
    int inputAmount = 100;
    cout << "Nupuvajutuste arv: ";
    cout << "Tühikutega eraldatud täisarvu: ";
    getline(cin, inputsSpaceSeparated);
    int inputs[inputAmount];

    for (int i = 0; i < inputAmount; i++) {
        inputs[i] = NULL;
    }

    split(inputsSpaceSeparated, " ", inputs);


    for (int const &input : inputs) {
        cout << input << endl;
        if (input == NULL) break;
    }

    // calculate();
}