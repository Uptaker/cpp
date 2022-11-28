#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <utility>

enum LiidesType {
    SUM, VECTOR
};

using namespace std;

class KaalumajaLiides {
    public:
    double virtual weight() = 0;
    void virtual add(int kg) = 0;
};

class SumArvutus : public KaalumajaLiides {
    double totalKg = 0;

    public:
    double weight() { return totalKg; }
    void add(int kg) { totalKg+= kg; }
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
};

class LiidesFactory {
    public:
    static KaalumajaLiides* getLiides(LiidesType liides = SUM) {
        switch (liides) {
        case SUM:
            return new SumArvutus();
            break;
        case VECTOR:
            return new VectorArvutus();
            break;
        default:
            return new SumArvutus();
        }
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
    KaalumajaLiides *sumKaaluja = new SumArvutus();
    KaalumajaLiides *vektorKaaluja = new VectorArvutus();

    Kaalumaja km1 = Kaalumaja("Aadress 1", LiidesFactory::getLiides());
    km1.weight(200);

    Kaalumaja km2 = Kaalumaja("Aadress 2", LiidesFactory::getLiides(VECTOR));
    km2.weight(2500);
    km2.add(2500);
    km2.weight(0);
}
