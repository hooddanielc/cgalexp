#include <iostream>
#include <CGAL/Simple_cartesian.h>
#include <CGAL/Polyhedron_3.h>
#include <cgalutil/util.h>
#include <fstream>

typedef CGAL::Simple_cartesian<double>               Kernel;
typedef Kernel::Point_3                              Point_3;
typedef CGAL::Polyhedron_3<Kernel>                   Polyhedron;
typedef Polyhedron::Facet_iterator                   Facet_iterator;
typedef Polyhedron::Halfedge_around_facet_circulator Halfedge_facet_circulator;

int main(int, char*[]) {
  using polyhedron_t = CGAL::Polyhedron_3<CGAL::Simple_cartesian<double>>;
  using point_t = polyhedron_t::Point_3;
  point_t p(0.0, 0.0, 0.0);
  point_t q(1.0, 0.0, 0.0);
  point_t r(0.0, 1.0, 0.0);
  point_t s(0.0, 0.0, 1.0);
  Polyhedron polyhedron;
  polyhedron.make_tetrahedron(p, q, r, s);
  convert_polyhedron_to_off(polyhedron, std::cout);
  return 0;
}
