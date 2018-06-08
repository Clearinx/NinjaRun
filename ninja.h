#ifndef NINJA_H
#define NINJA_H
#include "point.h"
#include "direction.h"
#include "map.h"
#include "logger.h"
#include <map>
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
    map<char, int> _directionMap;
    vector<Point> _previousPositions;
    vector<Direction> _previousDirections;
    Logger _logger;
    bool CheckForDestructibles(Map *map, vector<Point> *Obstacles);
    bool RayCast(Map *map, Direction throwPriority, vector<Point> *Obstacles);
    bool HaveShurikens();
    void DestroyHolySymbol(Map *map, Point p);
    Point GetNewPoint(int i, Direction direction);
    void DestroyObstacles(Map *map, vector<Point> Obstacles);
    void CheckNextField(Map *map, char *c, Point *nextPosition);
    void Act(Map *map, char *c, Point *nextPosition);
    void MoveToNextPosition(Point *nextPosition);
    void SetPriority(Direction *direction);
    void ChangeDirection(Map *map);
    void BreakWall(Map *map);
    bool FoundObstaclesToDestroy(vector<Point> Obstacles);
    void LogPosition();
    void LogDirection();
    void Win();
    void PickUpShuriken(Map *map);
    void LoopAlert(int i);
    void ModifyPath(char *c);
    void Mirror();
    void Sake();
    void SecretPathway(Map *map, char toFind);

public:
    Ninja(Point startLocation);
    void GoForIt(Map *map);
};

#endif // NINJA_H
