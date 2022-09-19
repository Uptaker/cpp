#include <iostream>

using namespace std;

/*
        m1 m2 m3... (outputAmount)
    n1  A  K  -         true
    n2  -  A  K         true
    n3  A  -  K         false
    ..
    (diodeAmount)

        m1 m2 m3... (outputAmount)
    n1  A  K  -         true
    n2  A  -  K         true
    n3  -  A  K         true
    n4  -  K  A         true  
*/

int main(void) {
    // Aniood > Katiood to turn on, else off

    int outputAmount, diodeAmount;
    cout << "Kontrolleri väljundite arv ja dioodide arv:" << endl;
    cin >> outputAmount >> diodeAmount;

    char answersMatrix[diodeAmount][outputAmount];
    int aniode, katiode;
    for (int i = 0; i < diodeAmount; i++) {
        cout << "Aniood ja Katiood veel " << (diodeAmount - i) << " korda" << endl;
        cin >> aniode >> katiode;
        for (int j = 0; j < outputAmount; j++) answersMatrix[i][j] = '-';
        answersMatrix[i][katiode - 1] = 'K';
        answersMatrix[i][aniode - 1] = 'A';
    }

    for (int i = 0; i < diodeAmount; i++) {
        int kIndex = 0;
        int aIndex = 0;
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