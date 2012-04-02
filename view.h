/*
 * view.h
 *
 */

#ifndef _VIEW_H
#define _VIEW_H

#include "model.h"

class View
{

    const Model& model;
    int width, height;
    int posX, posY;

    bool shutdown;
    
    double timeLastFrame;
    
public:

 
    View(const Model& model_p, int width=800, int height=600);
    ~View();
    
    void CallBackDisplayFunc();
    void CallBackReshapeFunc(int w, int h);
    void CallBackKeyboardFunc(unsigned char key, int x, int y);
};

void createView(const Model& model);

#endif /* _VIEW_H */
