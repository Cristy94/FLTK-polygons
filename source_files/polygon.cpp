#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

#include "polygon.h"


cPolygon::cPolygon() {


}


cPolygon::~cPolygon(){

}

void cPolygon::addPoint(Point last){
	points.push_back(last);
}

void cPolygon::addPoint(const int x, const int y){
	addPoint(Point(x,y));
}

void cPolygon::translate(Point change){
	for(std::vector<Point>::iterator it = points.begin(); it != points.end(); ++it){
		(*it).x += change.x;
		(*it).y += change.y;
	}
}

void cPolygon::setPosition(Point topLeft){

	if(points.size() == 0)
		return;

    Point change = getPos();
	change.x = topLeft.x - change.x;
	change.y = topLeft.y - change.y;
	translate(change);
}

std::vector<Point> cPolygon::toList() const{
	return points;
}

std::string cPolygon::toText(){

    std::stringstream ss;
    ss << " -> ";

    for(std::vector<Point>::iterator it = points.begin(); it != points.end(); ++it){
        ss <<"{" << it->x <<  ":" << it->y << "} ";
	}

    std::string s  = ss.str();
    return s;
}

Point cPolygon::getPos(){

    if(points.size() == 0)
        return Point(0,0);

    Point pos(10000,10000);
    for(std::vector<Point>::iterator it = points.begin(); it != points.end(); ++it){
        pos.x = std::min(it->x, pos.x);
        pos.y = std::min(it->y, pos.y);
    }

    return pos;
}


Point cPolygon::getSize(){
     if(points.size() == 0)
        return Point(0,0);

    Point pos = getPos();

    Point size(0,0);
    for(std::vector<Point>::iterator it = points.begin(); it != points.end(); ++it){
        size.x = std::max(size.x, it->x - pos.x);
        size.y = std::max(size.y, it->y - pos.y);
    }

    return size;

}