/*
 * view.cpp
 *
 */
 
#include "view.h"
#include "model.h"

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <GL/glfw.h>

#include <boost/thread.hpp>
#include <boost/bind.hpp>

View::View(const Model& model_p, int width_p, int height_p)
    : model(model_p), width(width_p), height(height_p), shutdown(false)
{
    double timeSinceLastFrame;
    double timeThisFrame;

    glfwInit();
    
    glfwOpenWindow( width, height, 0,0,0,0,0,0, GLFW_WINDOW);
    
    glViewport(0, 0, width, height);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glOrtho(-80.f, 80.f, -80.f, 80.f, -500.f, 500.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glRotatef(60, 1, 1, 1);
    glColor4f(1., 0., 0., 1.);
    
    timeLastFrame = glfwGetTime();
    while(shutdown == false)
    {
        timeThisFrame = glfwGetTime();
        timeSinceLastFrame = timeThisFrame - timeLastFrame;
        timeLastFrame = timeThisFrame;
        
        
        
        CallBackDisplayFunc();
        if(!glfwGetWindowParam( GLFW_OPENED ))
            shutdown = true;
        boost::this_thread::sleep(boost::posix_time::milliseconds(50));
    }
    
}

View::~View()
{
    glfwTerminate();
    //todo maybe dispatch exit event
}

void View::CallBackDisplayFunc()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    //gluDisk(50);
    glfwSwapBuffers();
}

void View::CallBackReshapeFunc(int w, int h)
{
    width = w;
    height = h;
    glViewport(0, 0, width, height);
    CallBackDisplayFunc();
}

void View::CallBackKeyboardFunc(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'q':
        shutdown = true;
        break;
    default:
        break;
    }
}

// ========================

void dispatchGlfwThread(const Model& model)
{
    View model_view(model);
}

void createView(const Model& model)
{
    boost::thread view_thread(boost::bind(dispatchGlfwThread, model));
    view_thread.join();
}

