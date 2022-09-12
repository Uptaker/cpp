#include <iostream>

using namespace std;

int main(void) {
    // Aniood > Katiood to turn on, else off

    int outputAmount, diodeAmount;
    cin >> outputAmount >> diodeAmount;
    int v[outputAmount + 1];
    int d[diodeAmount][2];
    for (int i = 0; i < diodeAmount; i++) {
        cin >> d[i][0] >> d[i][1];
    }
    for (int i = 0; i < outputAmount + 1; i++) v[i] = 0;

    for (int j = 0; j < 8; j++) {
        int last = outputAmount;
        while (v[last] == 1) last--;

        if (last > 0) {
            if (v[last] == 0) v[last] = 1;
            while(last < outputAmount) {
                last++;
                v[last] = 0;
            }
        }
    }

    for(int i = 0; i < diodeAmount; i++) {
        if (v[d[i][0]] == 1 && v[d[i][1]] ==0) {
            cout << "d " << i << endl;
        }
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