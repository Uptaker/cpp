#include <iostream>

using namespace std;

class Shape {
  public:
    virtual void draw() = 0;
};

class Circle : public Shape {
  public:
    void draw() { cout << "Drawing a circle." << endl; }
};

class ShapeDecorator : public Shape {
  public:
    ShapeDecorator(Shape* shape) : shape_(shape) {}
    void draw() { shape_->draw(); }

  private:
    Shape* shape_;
};

class RedShapeDecorator : public ShapeDecorator {
  public:
    RedShapeDecorator(Shape* shape) : ShapeDecorator(shape) {}
    void draw() {
        ShapeDecorator::draw();
        setRedBorder();
    }

  private:
    void setRedBorder() { cout << "Border color: red." << endl; }
};

int main() {
  Shape* circle = new Circle();
  circle->draw();

  Shape* redCircle = new RedShapeDecorator(new Circle());
  redCircle->draw();

  return 0;
}