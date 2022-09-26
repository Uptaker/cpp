#include <iostream>
#include <cmath>

using namespace std;

long days;
int main(void) {
    cin >> days;

	for (int i = 1; i <= days; i++) {
        cout << (days - i + 1) * i << endl;
	}
}