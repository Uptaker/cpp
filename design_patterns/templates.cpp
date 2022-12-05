#include <iostream>

using namespace std;

template <class T>
T suurim (T a, T b) {
    return a > b ? a : b;
}

int main(void) {
    cout << suurim<int>(3, 5) << endl;
    cout << suurim<>(3, 5) << endl;
    cout << suurim(3, 5) << endl;
}