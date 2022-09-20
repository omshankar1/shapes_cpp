#include <iostream>
#include <numbers>
#include <vector>

//  make clean && make all && ./shapes_dyn

//*************************************************************
// Base virtual class
// virtual
//   - Late binding
//   - embeds vtable
struct DynShape {
  // double area() const { return -1.0; }
  virtual double area() const { return 1.0; }
};

//***********************************************************************
// Circle
//***********************************************************************
struct Circle : public DynShape {
  double r;
  explicit Circle(double radius) : r(radius) {}
  auto name() const -> std::string { return std::string{"Circle"}; }
  double area() const override { return std::numbers::pi * r * r; }
};

//***********************************************************************
// Rectangle
//***********************************************************************
struct Rectangle : public DynShape {
  double w, h;
  explicit Rectangle(double width, double height) : w(width), h(height) {}
  auto name() const -> std::string { return std::string{"Rectangle"}; }
  double area() const override { return w * h; }
};

//***********************************************************************
// Square
//***********************************************************************

struct Square : public DynShape {
  double s;
  explicit Square(double side) : s(side) {}
  auto name() const -> std::string { return std::string{"Rectangle"}; }
  double area() const override { return s * s; }
};

//***********************************************************************
// LineSegment: Non conformance: No method 'area' defined
//***********************************************************************
struct LineSegment {
  double l{};
  explicit LineSegment(double side) : l(side) {}
  auto name() const -> std::string { return std::string{"LineSegment"}; }
};
