#include <iostream>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Polyhedron_3.h>
#include <CGAL/IO/Polyhedron_iostream.h>
#include <CGAL/draw_polyhedron.h>
#include <fstream>


typedef CGAL::Exact_predicates_inexact_constructions_kernel  Kernel;
typedef CGAL::Polyhedron_3<Kernel>                       Polyhedron;


int main(int argc, char* argv[]) {
  std::cout << "0" << std::endl;
  Polyhedron P;
  std::cout << "1" << std::endl;
  std::ifstream in1("data/cross.off");
  std::cout << "2" << std::endl;
  in1 >> P;
  std::cout << "3" << std::endl;
  CGAL::draw(P);
  return 0;
}
