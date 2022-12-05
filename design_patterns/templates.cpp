#include <iostream>

using namespace std;

template <class T>
T suurim (T a, T b) {
    return a > b ? a : b;
}

template <class T2>
T2 suurimHoidlast(T2 *massiiv, int kogus) {
    T2 v = massiiv[0];
    for (int i = 1; i < kogus; i++) {
        if (massiiv[i] > v) v = massiiv[i];
    }
    return v;
}

class Time {
    int hours, minutes, seconds;

    public:
    Time(int hours, int minutes, int seconds) {
        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
    }

    friend ostream& operator<<(ostream& os, const Time& v);


    Time operator++(int) {
        seconds++;

        if (seconds >= 60) {
            seconds = 0;
            minutes++;
        }

        if (minutes >= 60) {
            minutes = 0;
            hours++;
        }

        if (hours >= 24) hours = 0;
        return Time(hours, minutes, seconds);
    }

    Time operator+(Time t) {
        // TODO git history for working version
        int totalInSeconds = seconds + t.seconds;
        totalInSeconds+= (minutes + t.minutes) / 60;
        totalInSeconds+= (hours + t.hours) / 3600;
        return Time(totalInSeconds / 3600, totalInSeconds % 3600 / 60, totalInSeconds % 3600);
    }

    bool operator>(Time t) {
        int left = seconds + minutes / 60 + hours / 3600;
        int right = t.seconds + t.minutes / 60 + t.hours / 3600;

        return left > right;
    }

};

ostream& operator<<(ostream& os, const Time& v) {
    return os << "(" << v.hours << "," << v.minutes << "," << v.seconds << ")";
}

int main(void) {
    double arvud[4] = {2, 9, 7, 6};
    double a2 = suurimHoidlast(arvud, 4);
    cout << a2 << endl;

    cout << suurim<int>(3, 5) << endl;
    cout << suurim<>(3, 5) << endl;
    cout << suurim(3, 5) << endl;

    cout << suurim(Time(12, 12, 12), Time(11, 11, 11)) << endl;
}