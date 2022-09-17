#include <concepts>
#include <iostream>
#include <numbers>

/*




*/

//***********************************************************************
// Circle
//***********************************************************************
struct Circle {
  double r{};
  explicit Circle(double radius) : r(radius) {}
  auto name() const -> std::string { return std::string{"Circle"}; }
  auto area() const -> double { return std::numbers::pi * r * r; }
};

//***********************************************************************
// Rectangle
//***********************************************************************
struct Rectangle {
  double w{}, h{};
  explicit Rectangle(double width, double height) : w(width), h(height) {}
  auto name() const -> std::string { return std::string{"Rectangle"}; }
  auto area() const -> double { return w * h; }
};

//***********************************************************************
// Square
//***********************************************************************
struct Square {
  double s{};
  explicit Square(double side) : s(side) {}
  auto name() const -> std::string { return std::string{"Square"}; }
  auto area() const -> double { return s * s; }
};

//***********************************************************************
// LineSegment: Non conformance: No method 'area' defined
//***********************************************************************
struct LineSegment {
  double l{};
  explicit LineSegment(double side) : l(side) {}
  auto name() const -> std::string { return std::string{"LineSegment"}; }
};
