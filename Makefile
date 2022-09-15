CXX := clang++
CXXFLAGS := -std=c++20 -g

all: shapes_concepts shapes_dyn

largest: shapes_concept.cpp
	$(CXX) $(CXXFLAGS) shapes_concepts.cpp -o shapes_concepts

largest_concept: shapes_dyn.cpp
	$(CXX) $(CXXFLAGS) shapes_dyn.cpp -o shapes_dyn  

clean:
	rm -f *.o shapes_concepts shapes_dyn
	rm -rf shapes_dyn.dSYM shapes_concepts.dSYM
