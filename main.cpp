
#include <iostream>
#include "path.h"
#include "view.h"
using std::cout; using std::endl;

int main(int argc, char **argv)
{
    Path p;
    p.addVertex(1,.3,.7);
    p.connectVertices(0, 1);
    p.addVertex(Vector3<float>(2,3,4));
    p.connectVertices(1,2);
    
    cout << p << endl;
    Model m;
    createView(m);
    return 0;
}
