#include <iostream>
#include <numbers>
#include <vector>

//  make clean && make all && ./shapes_dyn

//*************************************************************
// Run time Polymorphism
//*************************************************************

//*************************************************************
// Base virtual class
struct DynShape {
  // double area() const { return -1.0; }
  //   - Late binding
  //   - embeds vtable
  virtual double area() const { return 1.0; }
};

//***********************************************************************
// Derived classes
//***********************************************************************

//***********************************************************************
// 1. Circle
//***********************************************************************
struct Circle : public DynShape {
  double r;
  explicit Circle(double radius) : r(radius) {}
  double area() const override { return std::numbers::pi * r * r; }
  auto name() const -> std::string { return std::string{"Circle"}; }
};

//***********************************************************************
// 2. Rectangle
//***********************************************************************
struct Rectangle : public DynShape {
  double w, h;
  explicit Rectangle(double width, double height) : w(width), h(height) {}
  double area() const override { return w * h; }
  auto name() const -> std::string { return std::string{"Rectangle"}; }
};

//***********************************************************************
// 3. Square
//***********************************************************************

struct Square : public DynShape {
  double s;
  explicit Square(double side) : s(side) {}
  double area() const override { return s * s; }
  auto name() const -> std::string { return std::string{"Rectangle"}; }
};

//***********************************************************************
// 4. LineSegment: Non conformance: No method 'area' defined
//***********************************************************************
struct LineSegment {
  double l{};
  explicit LineSegment(double side) : l(side) {}
  auto name() const -> std::string { return std::string{"LineSegment"}; }
};
