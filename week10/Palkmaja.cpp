/*  Kahe ruumiga palkmaja. Kõrgus 3m, otsasein 3m, külgsein 6m, pooleks kaheks võrdseks toast.
    Ühes toas 20C, teises aken lahti, õuetemperatuur 0C ka toas.

    Esialgu seinte soojusmahtuvust ei arvesta, küll aga soojusjuhtivust.
    Arvestame seina soojusjuhtivuseks võrdseks 20cm paksuse puitseinaga

    Puidu soojusjuhtivustegur 0.12 J/(m*K) ühe ruutmeetri ja meetripaksuse seina puhul.
    20cm paksuse sein laseb soojust läbi 0.6 W/(m*m*K)

    * Algtemperatuurid 0C ja 20C.
    * Arvuta kummagi ruumi temperatuur 1 minuti pärast
    * Arvestades ainult õhu soojusmahtuvust ning soojusenergia liikumist kahe toa vahel
    * Arvestades ka soojusenergia liikumist läbi välisseinte

    * Kokku 54m3, üks tuba 27m3

    * 20K, 9 ruutmeetrit, 0.6 * 9 * 20 = 108 J/s ~ 6480 J/min
    * Üks tuba 27m3
    * õhu mass: 27 * 1.29 = 34.8 kg õhku kummaski toas
    * 6480 / (1000 * 35)  ~= 0.185 kraadi
    
    Programm:
        * Klass Ruum, maht kuupmeetrites. temperatuur Celsiuses. 
        * Käsklus uue temperatuuri määramiseks vastavalt lisanduvatele džaulidele (ka negatiivne)
        * Ruumil viitage vektor paaridega, mis koosnevad viidast ruumile ning ühenduses olevast ruutmeetrite arvust
        * Lisa käsklus, millega muudetakse ruumi oma temperatuuri vastavalt seostele ühendatud ruumidega
        * Katseda mõne ruumi ühendamist, arvuta seostega liikuvad soojushulgad minutis
        * Koosta haldusklass Hoone, milles on vektor viitadest ruumidele
        * Lisa Hoonele käsklus arvutamaks ruumide temperatuurid ühe minuti pärast
        * Käsklused ruumide lisamiseks hoonele, ruumide sidumiseks seintega
        * Arvutatakse vaid seoste juures, kus väiksema id-ga ruum viitab suurema id-ga ruumile
        * Ruumile saab määrata omaduse, et temal on kindel temperatuur (saab sellist ruumi kasutada ka väliskeskkonnana)
*/

#include <vector>
#include <iostream>
#include <utility>

using namespace std;

class Ruum {
    double maht; // m3
    double temp = 20;
    vector<pair<Ruum*, double>> seosed;
    bool tempMuudetav;

    const int ohkerisoojus = 1000;
    const int puiterisoojus = 1500;
    const double ohutihedus = 1.29;
    const double puidutihedus = 500;
    const double juhtivusTegur = 0.12;

    public:
    Ruum(double x, double y, double z, bool tempMuudetav = true) {
        this->maht = x * y * z;
        this->tempMuudetav = tempMuudetav;
    }

    Ruum(double x, double y, double z, double temp, bool tempMuudetav = true) {
        this->maht = x * y * z;
        this->temp = temp;
        this->tempMuudetav = tempMuudetav;
    }

    // Looge uus fail, looge kolmas ruum õueks, jälgige temp muutusi kümne minuti jooksul
    void applyJoules(double joules) {
        if (tempMuudetav) {
            double airMass = maht * ohutihedus;
            temp += joules / (ohkerisoojus * airMass);
        }
    }

    void lisaSeos(Ruum *r, double ruutmeetrid) {
        pair<Ruum*, double> paar;
        paar.first = r;
        paar.second = ruutmeetrid;
        seosed.push_back(paar);
    }

    void arvutaTemperatuuriMuutus(int sek) {
        for (int i = 0; i < seosed.size(); i++) {
            cout << seosed[i].first->temp << endl;

            // Leiate temperatuuri vahe
            double vahe = seosed[i].first->temp - this->temp;

            // pindala ja aja järgi leiate liikuva soojushulga (kui viidatav ruum on jahedam, siis negatiivse)
            double soojushulk = 0.6 * seosed[i].second * vahe * sek;

            // arvutate ruumi uue temperatuuri
            applyJoules(soojushulk);

        }
    }

    double getTemp() {
        return temp;
    }
};

class Hoone {
    vector<Ruum*> ruumid;
};

int main(void) {
    Ruum r1(3, 3, 3);
    Ruum r2(3, 3, 3, 0, true);

    r1.lisaSeos(&r2, 9);
    r2.lisaSeos(&r1, 9);

    // r1.arvutaTemperatuuriMuutus(60);

    // r1.applyJoules(-6480);
    cout << r1.getTemp() << endl;

    for (int i = 0; i < 10000; i++) {
        r1.arvutaTemperatuuriMuutus(6);
        r2.arvutaTemperatuuriMuutus(6);

        cout << r1.getTemp() << " " << r2.getTemp() << endl;
    }
}