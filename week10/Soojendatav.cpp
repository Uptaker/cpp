/* 
    Aine (mass, erisoojus, temperatuur)
    Komplekt, mille sees võib olla aine ja Komplekt

    Aine + Komplekt = soojendatav?

    kysiKg

    kysiJ/Kg

    - Koosta (abstraktne) ülemklass "soojendatav" käsklusega "kysiKg" kilogrammide arvu väljastamiseks
    - Loo soojendatavale alamklass AineKogus, millel väljaks koligrammide arv

    const int ohkerisoojus = 1000;
    const int puiterisoojus = 1500;
    const double ohutihedus = 1.29;
    const double puidutihedus = 500;
    const double juhtivusTegur = 0.12;

    - Loo soojendatavale alamklass Komplekt, mille sisse saab panna teisi soojendatavaid (nii AineKogus-eid kui ka Komplekt-e). Katseta.

    - erisoojus * mass * absoluutne temp = jaulid

    - Lisa AineKogus-klassile erisoojus ning temperatuur Kelvinites.
    - Lisa käsklus AineKoguse eksemplaris leiduva soojusenergia koguse leidmiseks
    - Lisa soojusenergia (J) leidmise käsklus ka Soojendatavale ning Komplektile
    - Loo käsklus Soojendatava temperatuuri leidmiseks
*/

#include <iostream>
#include <vector>
using namespace std;

class Soojendatav {

    public:
    float dimension;

    virtual double kysiKg() = 0;
};

class AineKogus : public Soojendatav {
    double kg;
    int erisoojus;
    double temp;

    public:
    AineKogus(float kg) {
        this->kg = kg;
    }

    double kysiKg() { return kg; }
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
};

class Puit : public Soojendatav {
   int erisoojus = 1500; 

   public:
    double kysiKg() {
        return dimension * dimension;
    }
};

class Ohk : public Soojendatav {
   int erisoojus = 1000; 

   public:
    double kysiKg() {
        return 3.14 * dimension * dimension;
    }
};

int main() {
    AineKogus taburett1(1.5);
    AineKogus taburett2(2.5);
    Komplekt k1;
    Komplekt k2;
    k1.lisa(&taburett1);
    k1.lisa(&taburett2);
    cout << k1.kysiKg() << endl;
    k2.lisa(&taburett1);
    k2.lisa(&k1);
    cout << k2.kysiKg() << endl;

    AineKogus tool1(3);
    AineKogus tool2(5);

    Komplekt toolid;
    toolid.lisa(&tool1);
    toolid.lisa(&tool2);

    Komplekt moobel;
    moobel.lisa(&k1);
    moobel.lisa(&toolid);

    cout << k1.kysiKg() << endl;
    cout << moobel.kysiKg() << endl;


    return 0;
}



