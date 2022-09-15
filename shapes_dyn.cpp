#include <concepts>
#include <iostream>
#include <numbers>
#include <tuple>
#include <vector>

//  make all && ./shapes_dyn
//*************************************************************
// Way of inheritance
struct DynShape {
  // virtual double area() const { return 10; }
  virtual double area() const { return 10; }
};
//*************************************************************

// Polymorphic function that can take any object that is
// subclass of DynShape
double get_area(DynShape *shape) {
  std::cout << "get_area raw ptr"
            << "\t";
  return shape->area();
};

double get_area(std::unique_ptr<DynShape> shape) {
  std::cout << "get_area unique ptr"
            << "\t";
  return shape->area();
};

//*************************************************************
struct Circle : public DynShape {
  double r;
  explicit Circle(double radius) : r(radius) {}
  auto name() const -> std::string { return "Circle"; }
  double area() const override { return std::numbers::pi * r * r; }
};

//*************************************************************
struct Rectangle : public DynShape {
  double w, h;
  explicit Rectangle(double width, double height) : w(width), h(height) {}
  auto name() const -> std::string { return "Rectangle"; }
  double area() const override { return w * h; }
};
//*************************************************************

struct Square : public DynShape {
  double s;
  explicit Square(double side) : s(side) {}
  auto name() const -> std::string { return "Rectangle"; }
  double area() const override { return s * s; }
};
//*************************************************************

auto main() -> int {

  // Assign Circle concrete instance to base pointer
  DynShape *c1 = new Circle{1.0}; // 'new' considered harmful!
  DynShape *r1 = new Rectangle{2.0, 3.0};
  DynShape *s1 = new Square{2.5};
  std::cout << "c1: " << get_area(c1) << '\n';
  std::cout << "r1: " << get_area(r1) << '\n';
  std::cout << "s1: " << get_area(s1) << '\n';
  //*************************************************************

  // Vector of Circles
  // std::cout << '\n';
  // std::cout << "Vector of Circles: " << '\n';
  // auto circles = std::vector<Circle>{Circle{1.0}, Circle{2.0}};
  // for (auto circle : circles) {
  //   std::cout << get_area(&circle) << '\n';
  // }

  //*************************************************************
  std::cout << '\n';
  std::cout << "Vector of DynShape: " << '\n';
  std::vector<DynShape *> shapes{c1, r1, s1};

  for (auto shape : shapes) {
    std::cout << get_area(shape) << '\n';
  }
  //*************************************************************
  delete c1;
  delete r1;
  delete s1;

  //*************************************************************
  // Unique Pointers
  std::unique_ptr<Circle> cu1 = std::make_unique<Circle>(Circle{10});
  std::unique_ptr<Rectangle> ru1 =
      std::make_unique<Rectangle>(Rectangle{10, 10});
  std::unique_ptr<Square> su1 = std::make_unique<Square>(Square{13});

  std::vector<std::unique_ptr<DynShape>> vec;
  vec.push_back(std::move(cu1));
  vec.push_back(std::move(ru1));

  for (auto &shape : vec) {
    std::cout << get_area(std::move(shape)) << '\n';
  }

  // g++ -g -std=c++20 shapes_dyn.cpp -o shapes_dyn && ./shapes_dyn
  // leaks -atExit -- ./shapes_dyn
}
