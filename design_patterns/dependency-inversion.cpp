#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <utility>

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


class Logger {
    KaalumajaLiides *arvutus;
    string aadress;

    public:
    Logger(string aadress, KaalumajaLiides *kaaluja) {
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

    Logger km1 = Logger("Aadress 1", sumKaaluja);
    km1.weight(200);

    Logger km2 = Logger("Aadress 2", vektorKaaluja);
    km2.weight(2500);
    km2.add(2500);
    km2.weight(0);
}
