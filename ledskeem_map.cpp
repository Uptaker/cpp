#include <iostream>
#include <map>
#include <vector>

using namespace std;

/*
    1: [2, 3]
    2: [3]
*/

int main(void) {
    // Aniood > Katiood to turn on, else off

    int outputAmount, diodeAmount;
    cout << "Kontrolleri väljundite arv ja dioodide arv:" << endl;
    cin >> outputAmount >> diodeAmount;

    map<int, vector<int>> diodes;
    int aniode, katiode;
    for (int i = 0; i < diodeAmount; i++) {
        cout << "Aniood ja Katiood veel " << (diodeAmount - i) << " korda" << endl;
        cin >> aniode >> katiode;
        vector<int> diodeVector = diodes.at(aniode);
        diodeVector.insert(diodeVector.end(), katiode);
    }

    for (int i = 0; i < diodeAmount; i++) {
        for (int j = 0; j < outputAmount; j++) {
            if (answersMatrix[i][j] == 'A') aIndex = j;
            if (answersMatrix[i][j] == 'K') kIndex = j;
        }

        bool valid = false;
        if (aIndex + 1 == kIndex) valid = true;
        cout << (valid ? "JAH" : "EI") << endl;
    }
}

/*
Sisend
3 3
1 2
2 3
1 3
Väljund
JAH
JAH
EI

1: [2]
2: [1, 3]
3: [2]

Sisend
3 4
1 2
2 1
2 3
3 2
Väljund
JAH
JAH
JAH
JAH
*/