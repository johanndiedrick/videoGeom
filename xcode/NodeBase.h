//
//  NodeBase.h
//  videoGeom
//
//  Created by Johann Diedrick on 10/18/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef videoGeom_NodeBase_h
#define videoGeom_NodeBase_h

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class NodeBase{
public:
    
    NodeBase();
    
    string mName;
    NodeBase* mParent;
    vector<NodeBase*> mChildren;
    
    bool mVisibility;
    
    void setName(string iName);
    
    void addChild(NodeBase* iChild);
    
    void setParent(NodeBase* iParent);
    
    bool getVisibility();
    
    int getChildCount();
    
    void toggleVisibility();
    
    void print();
    
    virtual void draw();
    
    NodeBase* getChild(int iIndex);
    
};

#endif
