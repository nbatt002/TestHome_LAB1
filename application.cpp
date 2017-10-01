#include "application.h"

#include <iostream>
#include <cassert>
#include <cstdio>

#ifndef __APPLE__
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#endif

using namespace std;

application::application()
{
}

application::~application()
{
}

// triggered once after the OpenGL context is initialized
void application::init_event()
{

    cout << "CAMERA CONTROLS: \n  LMB: Rotate \n  MMB: Move \n  RMB: Zoom" << endl;
    cout << "KEYBOARD CONTROLS: \n  '=': Toggle wireframe mode" << endl;

    const GLfloat ambient[] = { 0.15, 0.15, 0.15, 1.0 };
    const GLfloat diffuse[] = { 0.6, 0.6, 0.6, 1.0 };
    const GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };

    // enable a light
    glLightfv(GL_LIGHT1, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, specular);
    glEnable(GL_LIGHT1);

    // enable depth-testing, colored materials, and lighting
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    // normalize normals so lighting calculations are correct
    // when using GLUT primitives
    glEnable(GL_NORMALIZE);

    // enable smooth shading
    glShadeModel(GL_SMOOTH);

    set_camera_for_box(vec3(-1,-1,-1),vec3(1,1,1));
}

// triggered each time the application needs to redraw
void application::draw_event()
{
    // apply our camera transformation
    apply_gl_transform();

    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE); //  this will enable wire-frame mode
    // draw first triangle
    glPushMatrix();
    glBegin(GL_TRIANGLES);
    glColor3f(1,0,0); glVertex3f(1,0,0);
    glColor3f(0,1,0); glVertex3f(-1,0,0);
    glColor3f(0,0,1); glVertex3f(0,1,0);
    glEnd();
    glPopMatrix();

    // draw second triangle
    glPushMatrix();
    glTranslatef(0,-0.5,0);
    glBegin(GL_TRIANGLES);
    glColor3f(1,1,1); glVertex3f(1,0,0);
    glColor3f(0,0,1); glVertex3f(-1,0,0);
    glColor3f(1,1,1); glVertex3f(0,1,0);
    glEnd();
    glPopMatrix();
}

// triggered when mouse is clicked
void application::mouse_click_event(int button, int button_state, int x, int y)
{
}

// triggered when mouse button is held down and the mouse is
// moved
void application::mouse_move_event(int x, int y)
{
}

// triggered when a key is pressed on the keyboard
void application::keyboard_event(unsigned char key, int x, int y)
{
}
