#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

long boxAmount;
int main(void) {
    cin >> boxAmount;
    string digitsAsString;
    char digitsAsChars[boxAmount];
    cin >> digitsAsString;
    strcpy(digitsAsChars, digitsAsString.c_str());

    int digits[boxAmount];
    for (int i = 0; i < boxAmount; i++) digits[i] = digitsAsChars[i] - '0';

    sort(digits, digits + boxAmount);

    string evenNum = "";
    string oddNum = ""; 

    for (int i = 0; i < boxAmount; i++) {
        if (digits[i] == 0) continue;
        if (digits[i] % 2 == 0) evenNum += to_string(digits[i]);
        else oddNum += to_string(digits[i]);
    }

    cout << (atoi(oddNum.c_str()) + atoi(evenNum.c_str())) << endl;
}