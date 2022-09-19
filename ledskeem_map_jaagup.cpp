#include <iostream>
#include <map>
#include <set>
#include <deque>

using namespace std;

/*
    1: [2, 3]
    2: [3]
*/
int outputAmount, diodeAmount;
map<int, set<int>> diodes;

int main(void) {
    cin >> outputAmount >> diodeAmount;

    int pairs[diodeAmount][2];


    int aniode, katiode;
    for (int i = 0; i < diodeAmount; i++) {
        cin >> aniode >> katiode;
        diodes[aniode].insert(katiode);
        pairs[i][0] = aniode;
        pairs[i][1] = katiode;
    }

    // eemaldage ja uurige esimest paari
    diodes[pairs[0][0]].erase(pairs[0][1]);

    for (int i = 0; i < diodeAmount; i++) {
        // Võtan i-nda paari seoste hulgast maha
        diodes[pairs[i][0]].erase(pairs[i][1]);

        int processed = pairs[i][0];
        deque<int> processing;
        set<int> found;
        found.insert(processed);
        processing.push_back(processed);

        // täienda sisendandmed
        // püüa leida ka algkohast kahe led-i kaugusel olevad väljundid
        while (processing.size() > 0) {
            cout << processing[0] << endl;
            processed = processing[0];
            for (set<int>::iterator it = diodes[processed].begin(); it != diodes[processed].end(); it++) {
                int value = *it;
                if (found.count(value) == 0) {
                    cout << " new " << value << endl;
                    found.insert(value);
                    processing.push_back(value);
                    // kuidas saaks kõik läbipääsetavad kohad teada?

                    
                }
            }
            processing.pop_front();
        }

        if (found.count(pairs[i][1] == 0)) cout << "JAH" << endl;
        else cout << "EI" << endl;
    }

    // for (int i = 0; i < diodeAmount; i++) {
    //     // Võtan i-nda paari seoste hulgast maha

    //     cout << diodes[pairs[i][0]].count(pairs[i][1]) << endl;

    //     diodes[pairs[i][0]].erase(pairs[i][1]);

    //     cout << diodes[pairs[i][0]].count(pairs[i][1]) << endl;
        
    //     // Leian, kas jäi suunatud ahel algusest lõppu
    //     // Panen i-nda paari seoste hulka
    //     diodes[pairs[i][0]].insert(pairs[i][1]);
    // }
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