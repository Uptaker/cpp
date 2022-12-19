#include <iostream>

using namespace std;

class PaymentGateway {
public:
    virtual void processPayment(double amount) = 0;
};

class PayPal : public PaymentGateway {
public:
    void processPayment(double amount) override {
        cout << "paying using PayPal API" << endl;
    }
};

class LHV : public PaymentGateway {
public:
    void processPayment(double amount) override {
        cout << "paying using LHV API" << endl;

    }
};

class Swedbank : public PaymentGateway {
public:
    void processPayment(double amount) override {
        cout << "paying using Swedbank API" << endl;
    }
};

void makePayment(PaymentGateway& gateway, double amount) {
    gateway.processPayment(amount);
}

int main() {
    PayPal paypal;
    makePayment(paypal, 100.00);

    LHV lhv;
    makePayment(lhv, 50.00);

    Swedbank swed;
    makePayment(swed, 50.00);

    return 0;
}