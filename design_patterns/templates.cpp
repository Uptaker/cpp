#include <iostream>
#include <vector>

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

template <class T2>
vector<T2> suurimad(T2 *massiiv, int kogus) {
    T2 abi = suurimHoidlast(massiiv, kogus);
    vector<T2> hoidla;
    for (int i = 0; i < kogus; i++) {
        if (massiiv[i] == abi) hoidla.push_back(massiiv[i]);
    }
    return hoidla;
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

    bool operator==(Time t) {
        return seconds == t.seconds && minutes == t.minutes && hours == t.hours;
    }

};

ostream& operator<<(ostream& os, const Time& v) {
    return os << "(" << v.hours << "," << v.minutes << "," << v.seconds << ")";
}

int main(void) {
    double arvud[5] = {2, 9, 7, 6, 9};
    vector<double> a2 = suurimad(arvud, 5);

    for (int i = 0; i < a2.size(); i++) {
        cout << a2[i] << endl;
    }

    Time times[4] = {Time(12, 12, 12), Time(11, 11, 11), Time(23, 23, 23), Time(23, 23, 23)};
    cout << "Biggest: " << suurimHoidlast(times, 4) << endl;

    vector<Time> biggestTimes = suurimad(times, 4);

    for (int i = 0; i < biggestTimes.size(); i++) {
        cout << biggestTimes[i] << endl;
    }

    cout << suurim<int>(3, 5) << endl;
    cout << suurim<>(3, 5) << endl;
    cout << suurim(3, 5) << endl;

    cout << suurim(Time(12, 12, 12), Time(11, 11, 11)) << endl;
}