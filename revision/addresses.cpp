#include <iostream>
using namespace std;

// koosta alamprogramm, mis saab parameetriks viida massiivi esimesele elemendile ning massiivi pikkus
// Alamprogramm vahetab massiivi esimese ja viimase väärtuse

void swapEnds(int *arr, int size) {
    int temp = *arr;
    arr[0] = arr[size - 1];
    arr[size - 1] = temp;
}

int main(void) {
    int m[3] = {13, 15, 12};

    int *start = m;

    swapEnds(start, 3);

    cout << *start << endl;

    start++;
    cout << *start << endl;

    start++;
    cout << *start << endl;

}