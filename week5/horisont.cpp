#include <iostream>
#include <cstring>

using namespace std;

struct Box {
    int x;
    int y;
};

long boxAmount;
double answer = 0;
int main(void) {
    cin >> boxAmount;
    struct Box boxes[boxAmount];

    int x, y;
    for (int i = 0; i < boxAmount; i++) {
        cin >> boxes[i].x >> boxes[i].y;
    }

    solve(boxes, boxAmount);
}

void solve(struct Box boxes[], long amount) {

}