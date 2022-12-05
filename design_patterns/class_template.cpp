#include <iostream>
using namespace std;

template<class T>

class Ajavahemik {
    public:
    T sekundid;
    Ajavahemik(int tunnid, int minutid, T sekundid) {
        this-> sekundid = tunnid * 3600 + minutid * 60 + sekundid;
    };

    void operator++(int) { sekundid+= 1; }

    int kysiTunnid() { return (int) sekundid / 3600; }

    int kysiMinutid() { return (int) sekundid % 3600 / 60; }

    T kysiSekundid() { return sekundid - kysiMinutid() * 60; }

    int operator>(Ajavahemik vahemik) { return sekundid > vahemik.sekundid; }

    int operator==(Ajavahemik vahemik) { return sekundid == vahemik.sekundid; }
};

int main(void) {
    // TODO, should work tho
}