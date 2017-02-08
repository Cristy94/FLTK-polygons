#ifndef __DRAWABLE_H__
#define __DRAWABLE_H__

#include <vector>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_draw.H>
#include <FL/Fl_Browser.H>


#include "polygonlist.h"

class Drawable : public Fl_Box{

	private:
		
	public:
        PolygonList polygons;
		Drawable(int X,int Y,int W,int H,const char*L=0): Fl_Box(X,Y,W,H,L){
		}

		void draw();
};

#endif