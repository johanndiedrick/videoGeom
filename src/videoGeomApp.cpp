#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

#include "NodeBase.h"
#include "NodeGeom.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class videoGeomApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    
    NodeGeom root;
    
    NodeGeom childA;
    
    NodeGeom childA1;
    
    NodeGeom childA1A;
    
    NodeGeom childB;
    
    NodeGeom childC;
    
    NodeGeom childB1;
    
    NodeGeom childC1;
    
    NodeGeom childA2;
     
    
};

void videoGeomApp::setup()
{
    
    root = NodeGeom();
    root.setName( "root" );
    root.setColor(Color(255,255,255));
    root.setPosition(Vec3f(getWindowWidth()/2, getWindowHeight()/2, 0.0));
    root.setSideLength(50.0);
    
    
    //child A, parent is root
    childA = NodeGeom();
    childA.setName( "childA" );
    childA.setColor(Color(255, 0, 0));
    childA.setPosition(Vec3f(-100.0, 0.0, 0.0));
    childA.setSideLength(25.0);
    
    root.addChild(&childA);
    
    //child B, parent is root
    childB = NodeGeom();
    childB.setName( "childB" );
    childB.setColor( Color(0, 255, 0));
    childB.setPosition(Vec3f (0.0, 100.0, 0.0));
    childB.setSideLength(25.0);
    
    root.addChild(&childB);
    
    //child C, parent is root
    childC = NodeGeom();
    childC.setName( "childC" );
    childC.setColor( Color(0, 0, 255));
    childC.setPosition(Vec3f (100.0, 0.0, 0.0));
    childC.setSideLength(25.0);
    
    root.addChild(&childC);
    
    //child A1, parent is A
    childA1 = NodeGeom();
    childA1.setName( "childA1" );
    childA1.setColor( Color(255, 128, 0));
    childA1.setPosition(Vec3f (-50.0, 0.0, 0.0));
    childA1.setSideLength(12.5);
    
    childA.addChild(&childA1);
    
    
    //child A1A, parent is A1
    childA1A = NodeGeom();
    childA1A.setName( "childA1A" );
    childA1A.setColor( Color(255, 128, 128));
    childA1A.setPosition(Vec3f (-25.0, 0.0, 0.0));
    childA1A.setSideLength(6.25);
    
    childA1.addChild(&childA1A);
    
    //child B1, parent is B
    childB1 = NodeGeom();
    childB1.setName( "childB1" );
    childB1.setColor( Color(0, 255, 128));
    childB1.setPosition(Vec3f (0.0, 50.0, 0.0));
    childB1.setSideLength(12.5);
    
    childB.addChild(&childB1);
    
    //child C1, parent is C
    childC1 = NodeGeom();
    childC1.setName( "childC1" );
    childC1.setColor( Color(0, 128, 255));
    childC1.setPosition(Vec3f (50.0, 0.0, 0.0));
    childC1.setSideLength(12.5);
    
    childC.addChild(&childC1);
    
    //child A2, parent is A
    childA2 = NodeGeom();
    childA2.setName( "childA2" );
    childA2.setColor( Color(255, 0, 128));
    childA2.setPosition(Vec3f (0.0, 50.0, 0.0));
    childA2.setSideLength(12.5);
    
    childA.addChild(&childA2);
    
    gl::translate(getWindowWidth()/2, getWindowHeight()/2);

    
}

void videoGeomApp::mouseDown( MouseEvent event )
{
}

void videoGeomApp::update()
{
}

void videoGeomApp::draw()
{
	// clear out the window with black
    gl::clear( Color( 0, 0, 0 ) );

    //gl::translate(getWindowWidth()/2, getWindowHeight()/2);
    

    
    // childA.draw();
//    childA1.draw();
    
    Vec3f newRotation = root.getRotation();
    newRotation = newRotation + Vec3f(0.0, 0.0, 0.1);
    root.setRotation(newRotation);
    
    root.print();
    
    root.draw();
    
    
     childA.toggleVisibility();
    


}


CINDER_APP_BASIC( videoGeomApp, RendererGl )
