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
*/



// C++ program to calculate the area of a square and a circle

#include <iostream>
#include <vector>
using namespace std;

class Soojendatav {
    int erisoojus;
    int temperatuur; 

    public:
    float dimension;

    virtual double kysiKg() = 0;
};

class AineKogus : public Soojendatav {
    double kg;

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
    /*
    Puit square;
    Ohk circle;

    cout << "Enter the length of the square: ";
    square.getDimension();
    cout << "Area of square: " << square.kysiKg() << endl;

    cout << "\nEnter radius of the circle: ";
    circle.getDimension();
    cout << "Area of circle: " << circle.kysiKg() << endl;
    */

    AineKogus taburett1(1.5);
    AineKogus taburett2(2.5);
    Komplekt k1;asd
    k1.lisa(&taburett1);asda

    k1.lisa(&taburett2);
    k1.lisa(&k1);
    cout << k1.kysiKg() << endl;

    // Soojendatav ese = taburett;
    // cout << ese.kysiKg() << endl;

    Soojendatav *ese = &taburett1;
    cout << ese->kysiKg() << endl;

    return 0;
}



