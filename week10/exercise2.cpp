// Toa temperatuur on 20 C
// Välisseina mõõdud on 5x3x0.2 meetrit
//Õue temperatuur on 0 C
// Männipalgi soojusjuhtivustegur on 0.12 W*/(m*K*) ruutmeetrisel pinnal

// Leia seinast läbi minev soojustvoog vattides

// k = Qd/SΔT

// k on keskkonna soojusjuhtivustegur (W/(m·K)),
// Q on ajaühikus pinda läbiv soojushulk (W),
// S on pindala (m2),
// d on pinna paksus (m),
// ΔT on temperatuurierinevus pinna erinevatel külgedel (°C).
// q on soojusvoog

// q = k*ΔT

// V: (0.12 * 15 * 20)/0.2 = 180 W

// Palkmaja palgiosa mõõtmed on 6x5x3 meetrit, palgi paksus seintes, põrandal ja laes  20cm.
// Välisõhu ja maapinna temperatuur 0 C.
// Leia kogu palkmajast väljuv soojusvoog vattides, maja sisetemperatuur 20 C.
// V: ~= 1512 W

// Kütmine lõpetati. Milline oleks õhutemperatuur 1 minuti pärast, kui..
// ..samasugune soojusvoog välja jätkub.
// *Arvestades vaid toas oleva õhu soojusenergiat
// *Arvestades ka seintes leiduvat soojusenergiat
// Seinte temperatuuriks võib lugeda kummalgi pool oleva õhu temperatuuride keskmise

// Puidu erisoojus 1760 J/(kg*K)
// Tihedus 500 kg/m3

// Õhu erisoojus ca 1000 J/(kg*K)
// Õhu temperatuur 1.29 kg/m3

// Õhuga
// õhu mass: 90 * 1.29 = 116 kg
// J 0C suhtes: 116 * 20C * 1000 = 2 320 000 J
// kui palju energiat selle aja jooksul ruumis lahkub
// J/min = 1512 * 60 = 90 720 J
// Järgi jääb: 2 320 000 - 90 720 = 2 229 280
// 2 229 280 / 1000 / 116 ~= 19.2

// Seintega
// Seinte pindala = 2*5*3 + 2*6*3 + 2*5*6 = 126 m2
// Seinte ruumala = 126 * 0.2 = 25.2 m3
// Seinte mass: 12.6 tonni
// Energia (J) 0C suhtes: 12600 * 10C *1760 = 221 760 000 J
// Võtame maha eelnevast ülesandest: 221 760 000 - 90 720 = 221 669 280 J
// 221669280 / 1760 / 126000 = 9.9996 (kust tuli tahvlil 9.96???) - see vist 10C puhul?

// Suhe: 2 302 000 / 221 760 000 = 0.01...
// 116 * 1^6 * 1000 = 116 000
// 20 - 90720 * 0.01 / 116 000 ~= 19.992

// Klass:
// Risttahukakujuline ruum väliskeskkonnas (0C)
// Ruumi kolm mõõdet meetrites, seina paksus meetrites
// Puitsein, siseruumi algtemp 20C

// Käsklus minuti jagu jahtumise arvestamiseks
// Leia ruumi sisetemperatuur etteantud minutite pärast
// Kuva sisetemperatuuri 10 minutist vahedega

// Lisa klassile käsklus poolestusaja leidmiseks (katseliselt, minuti täpsusega)

// Lisa klassile käsklus küsimaks soovitud temperatuurini jahtumiseks kuluvat aega (logaritmi ja poolestusaja kokku)

#include <iostream>

using namespace std;

class HouseTemp {
    double volume, area, temp, thickness, airmass, woodmass;
    double outertemp = 0;
    double puitjkraad, ohkjkraad, kokkujkraad;
    const int ohkErisoojus = 1012;
    const int puitErisoojus = 1500;
    const double airDensity = 1.29;
    const double woodDensity = 500;
    const double juhtivusTegur = 0.12;

    public:
    HouseTemp(double x, double y, double z, double thickness, double algtemp = 20, double outertemp = 0) {
        this->temp = algtemp;
        this->volume = x * y * z;
        this->area = 2 * x * y + 2 * x * z + 2 * y * z;
        this->thickness = thickness;
        this->outertemp = outertemp;
        this->airmass = volume * airDensity;
        this->woodmass = area * thickness * woodDensity;
        this->ohkjkraad = airmass * ohkErisoojus;
        this->puitjkraad = woodmass * puitErisoojus / 2; // sõltub  blah blah..
        this->kokkujkraad = ohkjkraad + puitjkraad;
    }
    double soojusvoog() {
        return juhtivusTegur * area * (temp - outertemp) / thickness;
    }

    void arvutaJahtumisMinut() {
        temp -= soojusvoog() * 60 / kokkujkraad;
    }

    void jahtu(int minuteid) {
        for (int i = 0; i < minuteid; i++) {
            arvutaJahtumisMinut();
        }
    }

    // minutes
    int findTimeFor(int temperature) {
        int i = 0;
        while (getTemp() > 10) {
            i++;
            jahtu(1);
        }
        cout << i << endl;
        return i;
    }

    double getTemp() {
        return temp;
    }

    int calculateTimeFor(int temperature) {
    // where to get 28.3?
    // 28.3 = mitu tundi läheb (läbi katselise tee)
    // 20/2^(x/28.3) = 7
    // 20/7 = 2^(x/28.3)
    // y = x/28.3
    // 20/7 = 2^y
    // y = ln(20/7) / ln(2)
    // x = y * 28.3
    }
};

int main(void) {
    // Something's wrong :c
    HouseTemp ht1(5, 6, 3, 0.2, 20, 0);
    // cout << ht1.soojusvoog() << endl;
    // ht1.arvutaJahtumisMinut();
    // cout << ht1.getTemp() << endl;
    // ht1.jahtu(10);
    // cout << ht1.getTemp() << endl;
    // for (int i = 0; i < 24; i++) {
    //     ht1.jahtu(60);
    //     cout << ht1.getTemp() << endl;
    // }
    int i = 0;

    // Poolestusaeg (katseliselt) 1700 x 60 = 102 000
    // Temperatuur pärast 100 tundi
    // while (ht1.getTemp() > 10) {
    //     i++;
    //     ht1.jahtu(1);
    //     cout << i << endl;
    // }

    // Viie kraadini katseliselt:
    // while (ht1.getTemp() > 5) {
    // i++;
    // ht1.jahtu(1);
    // cout << "Viie kraadini " << i << endl;
    // }

    ht1.findTimeFor(10);

    // 28.3 = mitu tundi läheb (läbi katselise tee)
    // 20/2^(x/28.3) = 7
    // 20/7 = 2^(x/28.3)
    // y = x/28.3
    // 20/7 = 2^y
    // y = ln(20/7) / ln(2)
    // x = y * 28.3

    // Pärast 100 tundi
    // ht1.jahtu(6000);
    // cout << ht1.getTemp() << endl;

    // Arvuta viienda kraadini
}
