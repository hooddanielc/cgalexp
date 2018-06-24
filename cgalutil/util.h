#pragma once

template <typename polyhedron_t, typename strm_t>
inline void convert_polyhedron_to_off(polyhedron_t &p, strm_t &ostrm) {
    // Write polyhedron in Object File Format (OFF).
    CGAL::set_ascii_mode(ostrm);
    ostrm << "OFF" << std::endl;
    ostrm << p.size_of_vertices() << ' '  << p.size_of_facets() << " 0" << std::endl;

    std::copy(
        p.points_begin(), p.points_end(),
        std::ostream_iterator<typename polyhedron_t::Point_3>(ostrm, "\n")
    );

    for (auto i = p.facets_begin(); i != p.facets_end(); ++i) {
        auto j = i->facet_begin();

        // Facets in polyhedral surfaces are at least triangles.
        CGAL_assertion( CGAL::circulator_size(j) >= 3);
        ostrm << CGAL::circulator_size(j) << ' ';

        do {
            ostrm << ' ' << std::distance(p.vertices_begin(), j->vertex());
        } while (++j != i->facet_begin());
        ostrm << std::endl;
    }
}
