#include <iostream>
#include <cstring>

using namespace std;

long stepsAmount;
int main(void) {
    cin >> stepsAmount;

    char steps[stepsAmount];

    cin >> steps;

    int nAmount = 0;
    int sAmount = 0;
    int wAmount = 0;
    int eAmount = 0;
    for (int i = 0; i < stepsAmount; i ++) {
        if (steps[i] == 'W') wAmount++;
        if (steps[i] == 'N') nAmount++;
        if (steps[i] == 'S') sAmount++;
        if (steps[i] == 'E') eAmount++;
    }

    int answer = (sAmount > nAmount ? sAmount - nAmount : nAmount - sAmount) + (wAmount > eAmount ? wAmount - eAmount : eAmount - wAmount);

    cout << answer << endl;
}