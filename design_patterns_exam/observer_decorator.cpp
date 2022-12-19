#include <iostream>
#include <vector>

using namespace std;

class StockExchange {
public:
  void setStockPrice(string stock, double price) {
    // Update the stock price
    // ....
    cout << "StockExchange: Stock updated" << endl;
  }
};

class Observer {
public:
  virtual void onStockPriceChanged(string stock, double price) = 0;
};

class ConsoleObserver : public Observer {
public:
  void onStockPriceChanged(string stock, double price) {
    cout << "OBSERVER: Stock price for " << stock << " has changed to " << price << endl;
  }
};

class StockExchangeDecorator : public StockExchange {
private:
  StockExchange* decoratedExchange;
  vector<Observer*> observers;

public:
  StockExchangeDecorator(StockExchange* decoratedExchange) : decoratedExchange(decoratedExchange) {}

  void setStockPrice(string stock, double price) {
    decoratedExchange->setStockPrice(stock, price);

    for (Observer* observer : this->observers) {
      observer->onStockPriceChanged(stock, price);
    }
  }

  void addObserver(Observer* observer) {
    this->observers.push_back(observer);
  }
};


int main() {
  StockExchangeDecorator exchange = new StockExchangeDecorator(new StockExchange());
  ConsoleObserver observer;

 
  exchange.addObserver(&observer);

  exchange.setStockPrice("TALLINK", 1234.56);

  return 0;
}