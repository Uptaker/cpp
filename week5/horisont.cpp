#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

struct Box {
    int x;
    int y;
};

struct Ray {
    double angle;
    int value;
};

long boxAmount;
double answer = 0;

double PI = 3.14159265358979323846;


void solve(struct Box boxes[], long amount) {

    vector<struct Ray> rays;

    for (int i = 0; i < amount; i++) {
        int x = boxes[i].x;
        int y = boxes[i].y;

        int leftMostX = y >= 0 ? x : x + 1;
        int leftMostY = x >= 0 ? y + 1 : y;
        int rightMostX = y >= 0 ? x + 1 : x;
        int rightMostY = x >= 0 ? y : y + 1;

        double leftAngle = atan2(leftMostY, leftMostX) / 2 / PI;
        if (leftAngle < 0) leftAngle += 1;
        double rightAngle = atan2(rightMostY, rightMostX) / 2 / PI;
        if (rightAngle <= 0) rightAngle += 1;

        rays.push_back({leftAngle, 1});
        rays.push_back({rightAngle, -1});
    }

        std::sort(std::begin(rays), std::end(rays), [](const Ray &a, const Ray &b) {
            return a.angle < b.angle;
        });

        int count = 0;
        double answer = 0;
        double prev = 0;
        for (int i = 0; i < amount; i++)
        {
            // if (count == 0) answer += rays[i].angle - prev;
            prev = rays[i].angle;
            count += rays[i].value;
        }
        answer += 1 - prev;

        cout << answer << endl;
}

int main(void) {
    cin >> boxAmount;
    struct Box boxes[boxAmount];

    int x, y;
    for (int i = 0; i < boxAmount; i++) {
        cin >> boxes[i].x >> boxes[i].y;
    }

    solve(boxes, boxAmount);
}

/*
7
1 1
-2 -2
-4 -2
-4 -1
-4 0
-4 1
-2 1
*/