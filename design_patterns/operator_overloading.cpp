#include <iostream>

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

};

ostream& operator<<(ostream& os, const Vektor& v) {
    return os << "(" << v.x << "," << v.y << ")";
}

int main(void) {
    Vektor v(3, 8);

    v.paremale();

    cout << v << endl;
}

