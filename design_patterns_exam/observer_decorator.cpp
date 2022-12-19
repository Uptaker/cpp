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
  StockExchange* decoratedExchange_;
  vector<Observer*> observers_;

public:
  StockExchangeDecorator(StockExchange* exchange = new StockExchange()) : decoratedExchange_(exchange) {}

  void setStockPrice(string stock, double price) {
    decoratedExchange_->setStockPrice(stock, price);

    for (Observer* observer : this->observers_) {
      observer->onStockPriceChanged(stock, price);
    }
  }

  void addObserver(Observer* observer) {
    this->observers_.push_back(observer);
  }
};


int main() {
  StockExchangeDecorator exchange = new StockExchangeDecorator();
  ConsoleObserver observer;

  exchange.addObserver(&observer);

  exchange.setStockPrice("TALLINK", 1234.56);

  return 0;
}