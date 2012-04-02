/*
 *
 *
 */

#ifndef _EDGE_H
#define _EDGE_H

#include <ostream>

class Edge {
    int v; // starting vertex
    int w; // ending vertex
    
    bool visible;
public:
    Edge();
    Edge(int v_p, int w_p);
    ~Edge() {}
    
    bool isVisible();
    void setVisible(bool vis_p);
    
    void getVertices(int& p_v, int& p_w);
    friend std::ostream& operator<<(std::ostream& lhs, const Edge& rhs);
};

#endif /* _EDGE_H */
