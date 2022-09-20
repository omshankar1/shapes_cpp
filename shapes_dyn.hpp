#include <iostream>
#include <numbers>
#include <vector>

//  make clean && make all && ./shapes_dyn

// Pattern:
//   1. Interface definition
//   2. Struct definition
//   3. Struct conformance to Interface
//   4. Polymorphic function that takes a generic interface input
//   5. Possibility of creating a list of interface instances

//*************************************************************
// Base virtual class
//*************************************************************

//*************************************************************
// virtual
//   - Late binding
//   - embeds vtable
struct DynShape {
  // double area() const { return -1.0; }
  virtual double area() const { return 1.0; }
};

//***********************************************************************
// Derived classes
//***********************************************************************

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
