#include <iostream>
#include <vector>

using namespace std;

class Visitor;

class Employee {
 public:
  virtual void accept(Visitor* visitor) = 0;
  virtual string getName() const = 0;
  virtual double getSalary() const = 0;
};

class Manager : public Employee {
 private:
  string name_;
  double salary_;

 public:
  Manager(string name, double salary) : name_(name), salary_(salary) {}
  void accept(Visitor* visitor) override;
  string getName() const override { return name_; }
  double getSalary() const override { return salary_; }
  void setSalary(double salary) { salary_ = salary; }
};

class Developer : public Employee {
 private:
  string name_;
  double salary_;

 public:
  Developer(string name, double salary) {
    this->name_ = name;
    this->salary_ = salary;
  }

  void accept(Visitor* visitor) override;
  string getName() const override { return name_; }
  double getSalary() const override { return salary_; }
  void setSalary(double salary) { salary_ = salary; }
};

class Visitor {
 public:
  virtual void visit(Manager* manager) = 0;
  virtual void visit(Developer* developer) = 0;
};

class SalaryRaiser : public Visitor {
 public:
  void visit(Manager* manager) override {
    double raise = manager->getSalary() * 0.1;
    manager->setSalary(manager->getSalary() + raise);
    cout << manager->getName() << " received a salary raise of $" << raise << endl;
  }
  void visit(Developer* developer) override {
    double raise = developer->getSalary() * 0.2;
    developer->setSalary(developer->getSalary() + raise);
    cout << developer->getName() << " received a salary raise of $" << raise << endl;
  }
};

void Manager::accept(Visitor* visitor) {
  visitor->visit(this);
}

void Developer::accept(Visitor* visitor) {
  visitor->visit(this);
}

int main() {
  Manager karl("Karl", 100000);
  Developer markus("Markus", 100000);
  Developer siim("Siim", 75000);

  vector<Employee*> employees = {&karl, &markus, &siim};

  SalaryRaiser visitor;
  for (auto employee : employees) {
    employee->accept(&visitor);
  }

  cout << "New salary of " << karl.getName() << ": " << karl.getSalary() << endl;
  cout << "New salary of " << markus.getName() << ": " << markus.getSalary() << endl;

  return 0;
}
