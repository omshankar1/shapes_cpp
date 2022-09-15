#include <concepts>
#include <iostream>
#include <numbers>
#include <tuple>
#include <vector>

// make all && ./shapes_concepts

// type SHAPE must have a member class method 'area' with signature below
template <typename SHAPE_TYPE>
concept Shape = requires(SHAPE_TYPE shape) {
  { shape.area() } -> std::same_as<double>;
  // shape.area();
  // requires std::same_as<double, decltype(shape.area())>;
};

// Polymorphic function to get area of any "Shape" type thats passed
template <Shape T> auto get_area(T shape) -> double { return shape.area(); };

//***********************************************************************
// Circle
//***********************************************************************
struct Circle {
  double r{};
  explicit Circle(double radius) : r(radius) {}
  auto name() const -> std::string { return "Circle"; }
  auto area() const -> double { return std::numbers::pi * r * r; }
};
// Compile time check: Circle conforms to Shape concept
// static_assert forces conformity check at compile time
static_assert(Shape<Circle>);

//***********************************************************************
// Rectangle
//***********************************************************************
struct Rectangle {
  double w{}, h{};
  explicit Rectangle(double width, double height) : w(width), h(height) {}
  auto name() const -> std::string { return "Rectangle"; }
  auto area() const -> double { return w * h; }
};
// Compile time check
static_assert(Shape<Rectangle>);

//***********************************************************************
// Square
//***********************************************************************
struct Square {
  double s{};
  explicit Square(double side) : s(side) {}
  auto name() const -> std::string { return "Rectangle"; }
  auto area() const -> double { return s * s; }
};
// Compile time check
static_assert(Shape<Square>);

//***********************************************************************
// Triangle: Non conformance: No method 'area' defined
//***********************************************************************
struct Triangle {
  double s{};
  explicit Triangle(double side) : s(side) {}
  auto name() const -> std::string { return "Triangle"; }
};
// Compile time check
// static_assert(Shape<Triangle>);

auto main() -> int {
  auto c1 = Circle{1.0};
  auto c2 = Circle{2.0};
  auto r1 = Rectangle{2.0, 3.0};
  auto r2 = Rectangle{4.0, 7.0};
  auto s1 = Square{2.5};
  auto t1 = Triangle{2.5};
  std::cout << "Area c1: " << get_area(c1) << '\n';
  std::cout << "Area r1: " << get_area(r1) << '\n';
  std::cout << "Area s1: " << get_area(s1) << '\n';
  // compile time check for non conformance
  // std::cout << "Area t1: " << get_area(t1) << '\n';
  std::vector<Circle> circles = std::vector<Circle>{c1, c2};

  for (auto shape : circles) {
    std::cout << shape.area() << '\n';
    std::cout << get_area(shape) << '\n';
  }
  // Can't form a vector of shapes!
  // std::vector<Shape> shapes = std::vector<Circle>{c1, c2};
}
