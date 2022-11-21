/* 
    Aine (mass, erisoojus, temperatuur)
    Komplekt, mille sees võib olla aine ja Komplekt

    Aine + Komplekt = soojendatav?

    kysiKg

    kysiJ/Kg

    - Koosta (abstraktne) ülemklass "soojendatav" käsklusega "kysiKg" kilogrammide arvu väljastamiseks
    - Loo soojendatavale alamklass AineKogus, millel väljaks koligrammide arv
    - Loo soojendatavale alamklass Komplekt, mille sisse saab panna teisi soojendatavaid (nii AineKogus-eid kui ka Komplekt-e). Katseta.

    - erisoojus * mass * absoluutne temp = jaulid

    + Lisa AineKogus-klassile erisoojus ning temperatuur Kelvinites.
    + Lisa käsklus AineKoguse eksemplaris leiduva soojusenergia koguse leidmiseks
    + Lisa soojusenergia (J) leidmise käsklus ka Soojendatavale ning Komplektile
    - Loo käsklus Soojendatava temperatuuri leidmiseks

    m1 * e1 * t1 + m1 * e2 * t2

    m = m1 + m2

    (m1 * e1 * t1 + m2 * e2 * t2) / (m1 * e1 + m2 * e2)

    - Looge Soojendatavale käsklus leidmaks, mitu J tuleb komponendile anda, et selle temperatuur tõuseks ühe kraadi võrra sum(mi*ei)
    - Lisage Soojendatavale käsklus ühtlustatud temperatuuri leidmiseks

    - Lisa käsklus Soojendatava detailide temperatuuride ühtlustamiseks - kõigile määratakse arvutatud temperatuur
    - Lisa Soojendatavale käsklus džaulide lisamiseks
    - Katseta - ühtlusta olemasolev süsteem. Lisa ühele AineKogusele 1500J. Ühtlusta süsteemi uuesti, kuva teise AineKoguse temperatuurid.
*/

#include <iostream>
#include <vector>
using namespace std;

const int ohkerisoojus = 1000;
const int puiterisoojus = 1760;
const double ohutihedus = 1.29;
const double puidutihedus = 500;
const double juhtivusTegur = 0.12;

class Soojendatav {

    public:
    virtual double kysiKg() = 0;
    virtual double kysiJ() = 0;
    virtual double kysiJK() = 0; // J K kohta
    virtual double kysiYhtlustunudTemperatuur() = 0;
    virtual void uusTemperatuur(double kelvinid) = 0;
    void yhtlusta() {
        uusTemperatuur(kysiYhtlustunudTemperatuur());
    };
};

class AineKogus : public Soojendatav {
    double kg;
    int erisoojus;
    double temp;

    public:
    AineKogus(double kg, int erisoojus, double temp) {
        this->kg = kg;
        this->erisoojus = erisoojus;
        this->temp = temp;
    }

    double kysiKg() { return kg; }
    double kysiJ() { return kg * erisoojus * temp; }
    double kysiJK() { return erisoojus * kg; }
    double kysiYhtlustunudTemperatuur() { return temp; }
    void uusTemperatuur(double kelvinid) {
        temp = kelvinid;
    }
};

class Komplekt: public Soojendatav {
    vector<Soojendatav*> detailid;

    public:
    void lisa(Soojendatav *s) {
        if (s == this) cout << "ise" << endl;
        detailid.push_back(s);
    }
    double kysiKg() {
        double sum = 0;
        for (int i = 0; i < detailid.size(); i++) {
            sum += detailid[i]->kysiKg();
        }
        return sum;
    }

    double kysiJ() {
        double sum = 0;
        for (int i = 0; i < detailid.size(); i++) {
            sum += detailid[i]->kysiJ();
        }
        return sum;
    }

    double kysiJK() {
        double sum = 0;
        for (int i = 0; i < detailid.size(); i++) {
            sum += detailid[i]->kysiJK();
        }
        return sum;
    }

    double kysiYhtlustunudTemperatuur() {
        return kysiJ() / kysiJK();
    }

    void uusTemperatuur(double kelvinid) {
        for (int i = 0; i < detailid.size(); i++) {
            detailid[i]->uusTemperatuur(kelvinid);
        }
    }
};

int main() {
    AineKogus taburett1(1.5, puiterisoojus, 293.15);
    AineKogus taburett2(2.5, puiterisoojus, 293.15);
    Komplekt k1;
    Komplekt k2;
    k1.lisa(&taburett1);
    k1.lisa(&taburett2);
    cout << k1.kysiKg() << endl;
    k2.lisa(&taburett1);
    k2.lisa(&k1);
    cout << k2.kysiKg() << endl;

    AineKogus tool1(3, puiterisoojus, 293.15);
    AineKogus tool2(5, puiterisoojus, 293.15);

    Komplekt toolid;
    toolid.lisa(&tool1);
    toolid.lisa(&tool2);

    Komplekt moobel;
    moobel.lisa(&k1);
    moobel.lisa(&toolid);

    cout << k1.kysiKg() << endl;
    cout << moobel.kysiKg() << endl;
    cout << moobel.kysiJ() << endl;
    cout << moobel.kysiJK() << endl;
    cout << moobel.kysiYhtlustunudTemperatuur() << endl;
    k1.yhtlusta();
    cout << k1.kysiYhtlustunudTemperatuur() << endl;
    moobel.yhtlusta();
    cout << moobel.kysiYhtlustunudTemperatuur() << endl;
    // Mitu komplekti ja omavahel kokku
    return 0;
}



