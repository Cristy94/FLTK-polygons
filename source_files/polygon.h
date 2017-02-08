#ifndef __cPolygon_H__
#define __cPolygon_H__

#include <vector>

#include "point.h"

class cPolygon {
	private:
		std::vector <Point> points;
	public:
		cPolygon();
		~cPolygon();
		void addPoint(Point last);
		void addPoint(const int x, const int y);
		void translate(Point change);
		void setPosition(Point topLeft);

        Point getPos();
        Point getSize();
		std::vector<Point> toList() const;
        std::string toText();
};

#endif