#include <iostream>

#include "drawable.h"

void Drawable::draw(){

    Fl_Box::draw();
   
    for(std::vector<cPolygon>::iterator idx = polygons.begin(); idx != polygons.end(); ++idx){
        //Get list of points for current polygon
	    std::vector<Point> points((*idx).toList());

        //Set color to default color, might be updated to use user-defined color
        fl_color(Fl_Box::color());

        //Draw the polygon
	    fl_begin_complex_polygon();

	        for(std::vector<Point>::iterator it = points.begin(); it != points.end(); ++it){
		        fl_vertex(it->x, it->y);
	        }

        fl_end_complex_polygon();
    }

    //Draw white border
    for(std::vector<cPolygon>::iterator idx = polygons.begin(); idx != polygons.end(); ++idx){

        //Get list of points for current polygon
	    std::vector<Point> points((*idx).toList());

        if(points.size() == 0)
            continue;

        //Set color to default color, might be updated to use user-defined color
        fl_color(FL_WHITE);

        //Draw lines to stroke
        std::vector<Point>::iterator it = points.begin();
        int mX = it->x,
            mY = it->y;
	    for(it = points.begin() + 1; it != points.end(); ++it){

		    fl_line(mX,mY, it->x, it->y);
            mX = it->x;
            mY = it->y;
	    }

        //Close polygon
        if(points.size() > 1){
            std::vector<Point>::iterator it = points.begin();
            fl_line(mX,mY, it->x, it->y);
        }
    }


}