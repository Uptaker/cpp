#include <iostream>

using namespace std;

int christmasDays;

int main(void) {
    // cin >> christmasDays;
    christmasDays = 2;

    int giftAmountByCategory[christmasDays];

    for (int i = 0; i < christmasDays; i++) {
        giftAmountByCategory[i] = i + 1;
    }

    int gifts;
    for (int k = 0; k < christmasDays; k++) {
        int result = 0;
        for (int i = 0; i < k; i++) {
            result = result + giftAmountByCategory[i];
        }
        result = result + (giftAmountByCategory[k] + (k + 1));
        cout << result << endl;
    }
}