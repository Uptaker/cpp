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

    # Koostage klass ruumi õhu tarbeks - pikkus, laius, kõrgus, algtemp:
    Juurde käsklus džaulide lisamiseks - igal korral arvutatakse uus temperatuur

    # Koosta süsteem radiaatorist ja ruumi õhust:
    Lülita 10 kg 1kW radiaator kümneks minutiks sisse
    Arvuta temperatuure iga sekundi tagant
    Kuva radiaatori ja õhu temperatuuri iga minuti tagant 20 minuti jooksul

    # Lisa süsteemile juurde klass - ruumi seinad, seina paksus ja materjal:
    Arvutage 7x8x2m 20cm palkseina ja põrandate 1 kraadi jagu soojendamiseks kuluv energia
*/
#include <iostream>

using namespace std;

class Radiator {
    const double tkoef = 4.5;
    double powerP, tempC, algtempC, erisoojus, pindala;

    public:
    Radiator(double algtempC, double powerP, double tempC, double erisoojus = 412, double pindala = 1) {
        this->algtempC = algtempC;
        (*this).tempC = tempC;
        this->powerP = powerP;
        this->erisoojus = erisoojus;
        this->pindala = pindala;
    }

    double getTempC() {
        return tempC;
    }

    void heatUp(int seconds) {
        double j = seconds * powerP;
        double deltaT = j / (algtempC * erisoojus);
        tempC += deltaT;
    }

    double harmoniseTemp(double goalTemp) {
        double outerDeltaT = goalTemp - tempC;
        double joules =  tkoef * outerDeltaT * pindala;
        double innerDeltaT = joules / (algtempC * erisoojus);
        tempC += innerDeltaT;
        return -joules;
    }

    double harmoniseTemp(double goalTemp, int seconds) {
        double jouleSum = 0;
        for (int i = 0; i < seconds; i++) {
            jouleSum+= harmoniseTemp(goalTemp);
        }
        return jouleSum;
    }
};

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
    AirTemp air(7, 8, 2, 20);
    Radiator r1(10, 1000, 20);

    for (int i = 0; i < 3600; i++) {
        if (i < 1800) r1.heatUp(1);

        double j = r1.harmoniseTemp(air.getC());
        air.addHeat(j);

        if (i % 60 == 0) cout << r1.getTempC() << " " << air.getC() << endl;
    }
}