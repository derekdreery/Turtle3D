/*
 * path.h
 *
 * This class holds all the data for a turtle path/tree, and dispaches
 * it to the model for rendering
 */

#ifndef _PATH_H
#define _PATH_H

#include <vector>
#include "vector3.h"
#include "edge.h"

class Path {
public:
    std::vector<Vector3<float> > vert_vec;
    std::vector<Edge> edge_vec;
public:
    
    Path();
    ~Path();
    
    inline void addVertex(const float& x, const float& y, const float& z)
    {
        vert_vec.push_back(Vector3<float>(x,y,z));
    }
        
    inline void addVertex(const Vector3<float>& vec)
    {
        vert_vec.push_back(vec);
    }
        
    inline void updateVertex(float x, float y, float z)
    {
        vert_vec.back().setCoords(x,y,z);
    }
        
    void connectVertices(int v_p, int w_p);
    
    bool edgeExists(int v_p, int w_p);
    
    friend std::ostream& operator<<(std::ostream& stream, const Path& rhs);
}; // class Path

#endif /* _PATH_H */
