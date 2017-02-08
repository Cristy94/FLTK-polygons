#ifndef __POLYGONLIST_H__
#define __POLYGONLIST_H__

#include <vector>

#include "polygon.h"

class PolygonList {

    public:
        std::vector<cPolygon> data;

        //List methods
        std::vector<cPolygon>::iterator begin();
        std::vector<cPolygon>::iterator end();
        size_t PolygonList::size();

        //Update list or component methods
        void addPolygon();
        void addPoint(int x, int y, int index = -1);
        void addPoint(const Point &p, int index = -1);
        void arrangeExpanded();
        void arrangeContracted();

};

#endif