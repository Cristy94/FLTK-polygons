#include "polygonList.h"

void PolygonList::addPolygon(){
    data.push_back(cPolygon());
}


std::vector<cPolygon>::iterator PolygonList::begin(){
    return data.begin();
}
std::vector<cPolygon>::iterator PolygonList::end(){
    return data.end();
}
size_t PolygonList::size(){
    return data.size();
}

void PolygonList::addPoint(int x, int y, int index){

    if(index > (int)data.size() || data.size() == 0)
        return;

    //By default add point to the last polygon
    if(index == -1)
        index = data.size() - 1;
    data[index].addPoint(x,y);
}

void PolygonList::addPoint(const Point &p, int index){

    if(index > (int)data.size() || data.size() == 0)
        return;

    if(index == -1)
        index = data.size() - 1;
    data[index].addPoint(p);
}

void PolygonList::arrangeExpanded(){

    if(data.size() == 0)
        return;

    int startX = 0;
    int startY = 0;
    for(std::vector <cPolygon> :: iterator it = data.begin(); it != data.end(); ++it){
        it->setPosition(Point(startX,startY));

        //Place next polygon after this one
        startX = it->getPos().x + it->getSize().x;

        //So they are not in line
        startY += 10;
    }

}


void PolygonList::arrangeContracted(){

    int startX = 0;
    int startY = 0;

    //Simply stack them up
    for(std::vector <cPolygon> :: iterator it = data.begin(); it != data.end(); ++it)
        it->setPosition(Point(startX,startY));

}