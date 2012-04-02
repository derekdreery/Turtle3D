#include "edge.h"

Edge::Edge()
    : v(0), w(0)
{
}

Edge::Edge(int v_p, int w_p)
    : v(v_p), w(w_p)
{
}

void Edge::getVertices(int& v_p, int& w_p)
{
    v_p = v;
    w_p = w;
}

std::ostream& operator<<(std::ostream& lhs, const Edge& rhs)
{
    lhs << "Edge(" << rhs.v << ", " << rhs.w << ")";
    return lhs;
}
