class Radiator {
    const double tkoef = 4.5;
    double powerP, tempC, algtempC, erisoojus, pindala;

    public:
    Radiator(double algtempC, double powerP, double tempC, double erisoojus = 412, double pindala = 1);

    double getTempC();

    void heatUp(int seconds);

    double harmoniseTemp(double goalTemp);

    double harmoniseTemp(double goalTemp, int seconds);
};