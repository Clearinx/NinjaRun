#ifndef NINJA_H
#define NINJA_H
#include "point.h"
#include "direction.h"
#include "map.h"
using namespace std;

class Ninja
{
    Point _actualPosition;
    Direction _direction;
    int _inverted;
    int _shurikens;
    bool _won;
    bool _breakerMode;
    bool _loop;
    bool CheckForDestructibles(Map *map, vector<Point> *Obstacles);
    bool RayCast(Map *map, Direction throwPriority, vector<Point> *Obstacles);
    void DestroyHolySymbol(Map *map, Point p);
    Point GetNewPoint(int i, Direction direction);
    void DestroyObstacles(Map *map, vector<Point> Obstacles);

public:
    Ninja(Point startLocation);
    void GoForIt(Map *map);
    bool HaveShurikens();
};

#endif // NINJA_H
