//
//  NodeGeom.h
//  videoGeom
//
//  Created by Johann Diedrick on 10/18/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef videoGeom_NodeGeom_h
#define videoGeom_NodeGeom_h

#include "NodeBase.h"
#include "cinder/Vector.h"
#include "cinder/Color.h"

#include <iostream>
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;



class NodeGeom : public NodeBase{
    
public:
    
    NodeGeom();
    
    NodeGeom(Vec3f iPosition, Vec3f iRotation, Vec3f iScale);
    
    Vec3f mPosition;
    Vec3f mRotation;
    Vec3f mScale;
    
    Color mColor;
    
    float mSideLength; 
    
    Vec3f getPosition();
    
    Vec3f getRotation();
    
    Vec3f getScale();
    
    void setPosition(Vec3f iValue);
    
    void setRotation(Vec3f iValue);
    
    void setScale(Vec3f iValue);
    
    Color getColor();
    
    void setColor(Color iColor);
    
    float getSideLength();
    
    void setSideLength(float iLength);
    
    void draw();
    
};


#endif
