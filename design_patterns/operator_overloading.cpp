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

};

ostream& operator<<(ostream& os, const Vektor& v) {
    return os << "(" << v.x << "," << v.y << ")";
}

int main(void) {
    Vektor v(3, 8);

    Vektor v2 = v * 2;

    Vektor v3 = v + v2;

    v.paremale();

    cout << v << endl;
    cout << v2 << endl;
    cout << v3 << endl;
    cout << v3[1] << endl;
    cout << v3[2] << endl;
    cout << v3[3] << endl;
}

