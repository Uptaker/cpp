#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <utility>
#include <map>

enum LiidesType {
    SUM, VECTOR
};

using namespace std;

class KaalumajaLiides {
    public:
    virtual double weight() = 0;
    virtual void add(int kg) = 0;
    virtual KaalumajaLiides* copy() = 0;
};

class SumArvutus : public KaalumajaLiides {
    double totalKg = 0;

    public:
    double weight() { return totalKg; }
    void add(int kg) { totalKg+= kg; }
    SumArvutus* copy() {
        return new SumArvutus();
    }
};

class VectorArvutus : public KaalumajaLiides {
    vector<pair<double, time_t>> addedKgs;

    public:
    double weight() {
        double sum = 0;
        for (int i = 0; i < addedKgs.size(); i++) {
            sum += addedKgs[i].first;
        }
        return sum;
    }

    void add(int kg) { 
        auto end = std::chrono::system_clock::now();
        std::time_t time = std::chrono::system_clock::to_time_t(end);
        addedKgs.push_back(make_pair(kg, time));
        cout << "Lisatud " << kg << " kell: " << time << endl;
    }

    VectorArvutus* copy() {
        return new VectorArvutus();
    }
};

class LiidesFactory {
    map<LiidesType, KaalumajaLiides*> liidesed = {
        {SUM, new SumArvutus()},
        {VECTOR, new VectorArvutus()},
    };

    public:
    KaalumajaLiides* getLiides(LiidesType liides = SUM) {
        return liidesed[liides];
    }
};


class Kaalumaja {
    KaalumajaLiides *arvutus;
    string aadress;

    public:
    Kaalumaja(string aadress, KaalumajaLiides *kaaluja) {
        this->aadress = aadress;
        this->arvutus = kaaluja;
    }

    void add(int kg) {
        arvutus->add(kg);
    }

    double weight(double kgs) {
        if (kgs > 0) arvutus->add(kgs);
        cout << "Uus kaal: " << arvutus->weight() << endl;
        return arvutus->weight();

    }
};

int main(void) {
    LiidesFactory lf;
    KaalumajaLiides *sumKaaluja = new SumArvutus();
    KaalumajaLiides *vektorKaaluja = new VectorArvutus();

    Kaalumaja km1 = Kaalumaja("Aadress 1", lf.getLiides());
    km1.weight(200);

    Kaalumaja km2 = Kaalumaja("Aadress 2", lf.getLiides(VECTOR));
    km2.weight(2500);
    km2.add(2500);
    km2.weight(0);
}
