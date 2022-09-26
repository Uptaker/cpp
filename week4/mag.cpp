#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

long numOfMagnets;
int main(void) {
    cin >> numOfMagnets;
    string digitsAsString;
    char digitsAsChars[numOfMagnets];
    cin >> digitsAsString;
    strcpy(digitsAsChars, digitsAsString.c_str());

    int digits[numOfMagnets];
    for (int i = 0; i < numOfMagnets; i++) digits[i] = digitsAsChars[i] - '0';

    sort(digits, digits + numOfMagnets);

    string evenNum = "";
    string oddNum = ""; 

    for (int i = 0; i < numOfMagnets; i++) {
        if (digits[i] == 0) continue;
        if (digits[i] % 2 == 0) evenNum += to_string(digits[i]);
        else oddNum += to_string(digits[i]);
    }

    cout << (atoi(oddNum.c_str()) + atoi(evenNum.c_str())) << endl;
}