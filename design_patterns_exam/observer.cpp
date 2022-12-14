#include <iostream>
#include <vector>

using namespace std;

class Observer {
public:
  virtual void onStockPriceChanged(string stock, double price) = 0;
};

class StockExchange {
private:
  vector<Observer*> observers;

public:
  void addObserver(Observer* observer) {
    this->observers.push_back(observer);
  }


  void setStockPrice(string stock, double price) {
    // Update the stock price
    // ....

    // notify observers of the price change
    for (Observer* observer : this->observers) {
      observer->onStockPriceChanged(stock, price);
    }
  }
};

class ConsoleObserver : public Observer {
public:
  void onStockPriceChanged(string stock, double price) {
    cout << "OBSERVER: Stock price for " << stock << " has changed to " << price << endl;
  }
};

int main() {
  StockExchange exchange;
  ConsoleObserver observer;

  exchange.addObserver(&observer);

  exchange.setStockPrice("TALLINK", 1234.56);

  return 0;
}