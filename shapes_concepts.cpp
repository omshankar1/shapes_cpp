#include "shapes_concepts.hpp"
#include <concepts>
#include <iostream>
#include <numbers>
#include <tuple>
#include <vector>

//*************************************************************
// An instance of SHAPE_TYPE: 'must' have a member class method
// 'area' with signature below
template <typename SHAPE_TYPE>
concept Shape = requires(SHAPE_TYPE shape) {
  { shape.area() } -> std::same_as<double>;
};

// Polymorphic function to get area of any "Shape" type thats passed
template <Shape T> auto get_area(T shape) -> double { return shape.area(); };
//*************************************************************

// Compile time check: Circle conforms to Shape concept
// static_assert forces conformity check at compile time
static_assert(Shape<Circle>);
static_assert(Shape<Rectangle>);
static_assert(Shape<Square>);

// compile time check for non conformance
// static_assert(Shape<LineSegment>);

auto main() -> int {
  auto c1 = Circle{1.0};
  auto c2 = Circle{2.0};
  auto r1 = Rectangle{2.0, 3.0};
  auto r2 = Rectangle{4.0, 7.0};
  auto s1 = Square{2.5};
  auto l1 = LineSegment{2.5};
  std::cout << "Area c1: " << get_area(c1) << '\n';
  std::cout << "Area r1: " << get_area(r1) << '\n';
  std::cout << "Area s1: " << get_area(s1) << '\n';
  // compile time check for non conformance
  // std::cout << "Area l1: " << get_area(l1) << '\n';
  std::vector<Circle> circles = std::vector<Circle>{c1, c2};

  for (auto shape : circles) {
    std::cout << shape.area() << '\n';
    std::cout << get_area(shape) << '\n';
  }
  // Can't form a vector of shapes!
  // std::vector<Shape> shapes = std::vector<Circle>{c1, c2};
}
