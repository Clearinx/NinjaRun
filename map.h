#ifndef MAP_H
#define MAP_H
#include<vector>
#include "point.h"
using namespace std;

class Map
{
    vector<std::vector<char>> _map;
public:
    Map(vector<std::vector<char>> map);
    void setMap(int height, int width, char c);
    Point GetStart();
    char GetElement(int x, int y);
    Point GetPathwayEndLocation(Point actualPosition, char toFind);
};

#endif // MAP_H
