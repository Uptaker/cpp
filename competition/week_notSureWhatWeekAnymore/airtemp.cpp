/*
    Ruumi mõõtmed 8x7x2 meetrit
    Algtemp 20 C
    Saab juurde 60000 J
    Leida lõpptemperatuur (algul ainult õhku)

    õhu erisoojus 1012 J/(kg*K)
    õhu erikaal (tihedus) 1.29 kg/m3

    112m^3 * 1.29 kg/m3 = 144.5 kg
    144.5 * 1012 ~= 15000 J/K
    60000 J/15000(J/K) ~= 0.4 K

    Koostage klass ruumi õhu tarbeks - pikkus, laius, kõrgus, algtemp
    Juurde käsklus džaulide lisamiseks - igal korral arvutatakse uus temperatuur

    Koosta süsteem radiaatorist ja ruumi õhust
    Lülita 10 kg 1kW radiaator kümneks minutiks sisse
    Arvuta temperatuure iga sekundi tagant
    kuva radiaatori ja õhu temperatuuri iga minuti tagant 20 minuti jooksul
*/
#include <iostream>

using namespace std;

class AirTemp {
    double area, temp;
    int erisoojus = 1012;
    double erikaal = 1.29;

    public:
    AirTemp(double pikkus, double laius, double korgus, double algtemp) {
        this->temp = algtemp;
        this->area = korgus * laius * pikkus;
    }

    void addHeat(int joules) {
        double mass = area * erikaal;
        double jaulePerKelvin = mass * erikaal;
        double deltaT = joules / jaulePerKelvin; // deltaT is the new added temp
        temp += deltaT;
    }

    double getC() {
        return temp;
    }

};

int main(void) {
    AirTemp at1(7, 8, 2, 20);
    at1.addHeat(60000);
    cout << at1.getC() << endl;
}