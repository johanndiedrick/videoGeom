//
//  NodeGeom.cpp
//  videoGeom
//
//  Created by Johann Diedrick on 10/18/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "NodeGeom.h"


NodeGeom::NodeGeom(){
    
    mPosition = Vec3f(0.0f, 0.0f, 0.0f);
    
    mRotation = Vec3f(0.0f, 0.0f, 0.0f);
    
    mScale = Vec3f(1.0f, 1.0f, 1.0f);
    
    mColor = Color(255, 255, 255);
    
    mSideLength = 1.0f;
    
    
}

NodeGeom::NodeGeom(Vec3f iPosition, Vec3f iRotation, Vec3f iScale){
    mPosition = iPosition;
    
    mRotation = iRotation;
    
    mScale = iScale;
    
    mColor = Color(255, 255, 255);
    
    mSideLength = 1.0f;
}

void NodeGeom::draw(){
    if (getVisibility()) {
        
        gl::pushMatrices();
        
        gl::translate(mPosition.x, mPosition.y, mPosition.z);
        
        gl::scale(mScale.x, mScale.y, mScale.z);
        
        gl::rotate( Vec3f( mRotation.x, mRotation.y, mRotation.z ) );
        
        //draw node's contents
        
        gl::color(mColor);
        
        Rectf rect( -mSideLength/2.0, -mSideLength/2.0, mSideLength, mSideLength);
        
        // gl::Texture mTex;
        
        //mTex.enableAndBind();
        
        gl::drawSolidRect( rect);
       
        //mTex.unbind();
        
        
        //draw children
        
        int tChildCount = getChildCount();
        
        
        for (int i=0; i<tChildCount; i++){
            cout<<"i'm now going to draw this child: " << mName << "w/ children # " << mChildren.size() << endl;
            
            //mChildren[i]->draw();
            
            mChildren.at(i)->draw();
        }
        
        gl::popMatrices();
        
        
        
        
    }
}


Vec3f NodeGeom::getPosition(){
    return mPosition;
}

Vec3f NodeGeom::getRotation(){
    return mRotation;
}

Vec3f NodeGeom::getScale(){
    return mScale;
}

void NodeGeom::setPosition(Vec3f iValue){
    mPosition = iValue;
}

void NodeGeom::setRotation(Vec3f iValue){
    mRotation = iValue;
}

void NodeGeom::setScale(Vec3f iValue){
    mScale = iValue;
}

Color NodeGeom::getColor(){
    return mColor;
}

void NodeGeom::setColor(Color iColor){
    mColor = iColor;
}

float NodeGeom::getSideLength(){
    return mSideLength;
}

void NodeGeom::setSideLength(float iLength){
    mSideLength = iLength;
}