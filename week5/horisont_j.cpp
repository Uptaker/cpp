#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

struct Range {
    double begin;
    double end;
};

int compare(const Range &a, const Range &b) {
    return a.begin - b.end;
}

int main(void) {
    int amount, x, y;
    cin >> amount;
    
    struct Range ranges[amount];
    for (int i = 0; i < amount; i++) {
        cin >> x >> y;
        int arrayOfX[4] = {x, x + 1, x, x + 1};
        int arrayOfY[4] = {y, y, y + 1, y + 1};
        double angles[4];

        for (int j = 0; j < 4; j++) {
            angles[j] = atan2(arrayOfY[i], arrayOfX[i]);
        }
        double *minAngle = min_element(angles, angles + 4);
        double *maxAngle = max_element(angles, angles + 4);
        cout << *minAngle << " " << *maxAngle << endl;
        ranges[i].begin = *minAngle;
        ranges[i].end = *maxAngle;

        // if on x scale
        if (ranges[i].begin < 0 && ranges[i].end > 3) {
            double temp = ranges[i].begin;
            ranges[i].begin = ranges[i].end;
            ranges[i].end = temp;
        }
    }

    // std::sort(ranges, &compare);
    for (int i = 0; i < amount - 1; i++) {
        for (int j = i + 1; j < amount; j++) {
            if (ranges[j].begin < ranges[i].begin) {
                struct Range temp = ranges[i];
                ranges[i] = ranges[j];
                ranges[j] = temp;
            }
        }
    }
    
    for (int i = 0; i < amount; i++) {
        cout << ranges[i].begin << " " <<  ranges[i].end << endl;
    }

}