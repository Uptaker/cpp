#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

long squares;
long specials;
int main(void) {
    cin >> squares >> specials;
    map<int, int> specialMap;

    int key, value;
    for (int i = 0; i < specials; i++) {
        cin >> key >> value;
        specialMap.insert(pair<int, int>(key, value));
    }

    vector<int> steps;
    int sum = 1;
    bool gameFail = false;
    while (sum != squares) {
        int bestLadder = 0;
        int bestStep = 0;
        map<int, int> cantUse;

        // find snake/ladder best paths
        for (int i = 1; i <= 6; i++) {
            if (specialMap.count(sum + i) == 0) continue;

            int value = specialMap.at(sum + i);
            if (value <= sum + i) {
                cantUse.insert(pair<int, int>(sum + i, value));
                continue;
            }
            if (value >= (sum + 6) && value > bestLadder) {
                bestLadder = value;
                bestStep = i;
            }
        }

        // if a ladder was found that leads player to sum >= 6, use it.
        if (bestLadder >= (sum + 6)) {
            sum = bestLadder;
            steps.push_back(bestStep);
            continue;
        }

        // calculate paths
        if (cantUse.count(sum + 6) == 0 && sum + 6 <= squares) bestStep = 6;
        else if (cantUse.count(sum + 5) == 0 && sum + 5 <= squares) bestStep = 5;
        else if (cantUse.count(sum + 4) == 0 && sum + 4 <= squares) bestStep =  4;
        else if (cantUse.count(sum + 3) == 0 && sum + 3 <= squares) bestStep =  3;
        else if (cantUse.count(sum + 2) == 0 && sum + 2 <= squares) bestStep =  2;
        else if (cantUse.count(sum + 1) == 0 && sum + 1 <= squares) bestStep =  1;
        else {
            gameFail = true;
            break;
        }

        sum += bestStep;
        steps.push_back(bestStep);
    }    

    if (gameFail) {
        cout << "EI SAA" << endl;
    } else {
        cout << steps.size() << endl;
        for (int i = 0; i < steps.size(); i++) {
            cout << steps[i];
        }
    }

}