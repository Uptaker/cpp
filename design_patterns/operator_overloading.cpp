#include <iostream>
#include <cassert>

using namespace std;
class Vektor {
    int x, y;
    public:
    Vektor(int x, int y) {
        this->x = x;
        this->y = y;
    }

    int getX() { return x; }

    int getY() { return y; }

    void paremale() { x++; }

    friend ostream& operator<<(ostream& os, const Vektor& v);

    Vektor operator*(int arv) { return Vektor(x* arv, y*arv); }

    Vektor operator+(Vektor v) { return Vektor(x + v.x, y + v.y); }

    int operator[](int koht) {
        assert (koht == 1 || koht == 2); // throws Exception
        if (koht == 1) return x;
        if (koht == 2) return y;
        return -1;
    }

    int operator*(Vektor v) {
       return x * v.x + y * v.y;
    }

};

ostream& operator<<(ostream& os, const Vektor& v) {
    return os << "(" << v.x << "," << v.y << ")";
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

};

ostream& operator<<(ostream& os, const Time& v) {
    return os << "(" << v.hours << "," << v.minutes << "," << v.seconds << ")";
}

int main(void) {
    Time t1(22, 59, 58);
    cout << t1 << endl;

    t1++;
    cout << t1 << endl;

    t1++;
    cout << t1 << endl;

    Time t2(23, 59, 59);
    t2++;
    cout << t2 << endl;

    Time t3 = t2 + t2;
    cout << t3 << endl;



    Vektor v(70, 70);

    // Vektor v2 = v * 4;
    Vektor v2(3, 0);

    cout << v * v2 << endl;

    Vektor v3 = v + v2;

    v.paremale();

    cout << v << endl;
    cout << v2 << endl;
    cout << v3 << endl;
    cout << v3[1] << endl;
    cout << v3[2] << endl;
    // cout << v3[3] << endl; // Exception
}

