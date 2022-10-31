#include <iostream>
#include <string>
#include <map>

// This proves just how bad my physics education was, I can't make any of these calculations up myself :(

/*
    Leia radiaatori temp 1 minuti pärast kui soojuskadusid ei arvestata
        radiatorKG = 10;
        erisoojusJ = 412;
        voimsusKW = 1;
        algTemperatuurC = 20;

    412 * 10 = 4120 J/C
    1W = 1 J/s
    1 * 6- * 1000 = 60000J
    60000 / 4120 = 14.56
    20 + 14.56 ~= 35

    Koostage radiaatori klass. Andke ette mass, võimsus ja algtemperatuur.
    Lisage käsklus, mille abil radiaator soovitud arvuks sekunditeks sisse lülitada.
    Radiaatori käest saab küsida hetketemperatuuri.

    Katse tulemus: 1 ruutmeetrise pinnaga 10kg raudradiaator
    jahtub 1 minutiga 35 kraadi C pealt 34 peale.
    Toa temperatuur on 20 kraadi C.

    Leia soojusvahetustegur J/(m2*K*s) kohta.

    4120 J/60s
    4120 / 60 = ~= 68.7
    deltaT = 15K
    68.7 / 15 = 4.5 J(n^2 * K)

    Leia radiaatori temperatuur igal minutil 10 minuti jooksul sama teguri juures.

    Lisa radiaatorile käsklus temperatuuri ühtlustumiseks - parameetriteks etteantud temperatuur ja sekundite arv
*/

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
        cout << "Running for " << seconds << " seconds.." << endl;

        // double joulesC = erisoojus * 10;
        // double totalJ = 1 * seconds * 1000;
        // double tempAfter = totalJ / joulesC + algtempC; seems to also be correct

        double j = seconds * powerP;
        double deltaT = j / (algtempC * erisoojus);
        tempC += deltaT;

        cout << "Temp now: " << deltaT << endl;
    }

    double harmoniseTemp(double goalTemp) {
        double outerDeltaT = goalTemp - tempC;
        double joules =  tkoef * outerDeltaT * pindala;
        double innerDeltaT = joules / (algtempC * erisoojus);
        tempC += innerDeltaT;
        return -joules;
    }

    // Funktsioon soovitud arvu sekundite jagu ühtlustamiseks
    // Tagastab eraldunud soojushulga (wtf)

};

int main(void) {
  Radiator r1(10, 1000, 20);

  cout << r1.getTempC() << endl;

  r1.heatUp(60);

  cout << r1.getTempC() << endl;
  cout << r1.harmoniseTemp(20) << endl;
  cout << r1.getTempC() << endl;
}