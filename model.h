/*
 * model.h
 *
 *
 */
 
#ifndef _MODEL_H
#define _MODEL_H

#include "path.h"

class Model
{
    Path path;
public:
    Model();
    Model(Path const& path_p);
    ~Model();
    
    void getModelWire();

};


#endif /* _MODEL_H */
