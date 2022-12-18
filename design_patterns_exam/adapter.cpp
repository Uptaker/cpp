/*

Allows objects with incompatible interfaces to work together.
Three main components: a target class, an adaptee class, and an adapter class

*/

#include <iostream>
#include <string>

using namespace std;

// target class
class UserAccount {
  public:
    virtual string getUsername() = 0;
    virtual int getBalance() = 0;
};

// class to be adapted
class LegacyUserAccount {
  public:
    LegacyUserAccount(string username, int balance) : username_(username), amount_(balance) {}
    string getName() { return username_; }
    int getAmount() { return amount_; }

  private:
    string username_;
    int amount_;
};

// adapter class
class UserAccountAdapter : public UserAccount {
  public:
    UserAccountAdapter(string username, int balance) : legacyAccount(username, balance) {}
    string getUsername() { return legacyAccount.getName(); }
    int getBalance() { return legacyAccount.getAmount(); }

  private:
    LegacyUserAccount legacyAccount;
};

int main() {
  UserAccount* account = new UserAccountAdapter("markus", 1000);

  cout << "Username: " << account->getUsername() << endl;
  cout << "Balance: " << account->getBalance() << endl;

  return 0;
}