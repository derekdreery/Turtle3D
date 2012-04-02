

#include "path.h"
#include "exceptions.h"

Path::Path()
    : vert_vec()
{
    vert_vec.push_back(Vector3<float>(0,0,0));
}

Path::~Path()
{

}

void Path::connectVertices(int v_p, int w_p)
{
    if (edgeExists(v_p, w_p))
    {
        throw invalid_params("Adding an edge that already exists is not allowed");
    }
    
    edge_vec.push_back(Edge(v_p, w_p));
}

bool Path::edgeExists(int v_p, int w_p)
{
    std::vector<Edge>::iterator it;
    int v, w;
    for(it=edge_vec.begin(); it<edge_vec.end(); it++)
    {
        it->getVertices(v, w);
        if ((v == v_p && w == w_p) || (v == w_p && w == v_p))
        {
            return true;
        }
    }
    return false;
}

std::ostream& operator<<(std::ostream& stream, const Path& rhs)
{
    stream << "Path( Vertices: ";
    std::vector<Vector3<float> >::const_iterator it;
    for(it=rhs.vert_vec.begin(); it<(rhs.vert_vec.end()-1); it++)
    {
        stream << *it << ", ";
    }
    it = rhs.vert_vec.end()-1;
    stream << *it << ", Edges: ";
    std::vector<Edge>::const_iterator jt;
    for(jt=rhs.edge_vec.begin(); jt<(rhs.edge_vec.end()-1); jt++)
    {
        stream << *jt << ", ";
    }
    jt = rhs.edge_vec.end()-1;
    stream << *jt << " )";
    return stream;
}
