#include <iostream>
#include <string>

using namespace std;

class UserAccount {
  public:
    virtual string getUsername() = 0;
    virtual int getBalance() = 0;
};

class LegacyUserAccount {
  public:
    LegacyUserAccount(string username, int balance) : username_(username), amount_(balance) {}
    string getName() { return username_; }
    int getAmount() { return amount_; }

  private:
    string username_;
    int amount_;
};

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