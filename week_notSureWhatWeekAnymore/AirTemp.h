class AirTemp {
    double area, temp;
    int erisoojus = 1012;
    double erikaal = 1.29;

    public:
    AirTemp(double pikkus, double laius, double korgus, double algtemp);

    void addHeat(int joules);

    double getC();

};