#include "ninja.h"

Ninja::Ninja(Point startLocation)
{
    _actualPosition = startLocation;
    _direction = SOUTH;
    _inverted = 1;
    _directionMap = {{'S', 0}, {'E', 1}, {'N', 2}, {'W', 3}};
    _shurikens = 3;
    _won = false;
    _breakerMode = false;
    _loop = false;
}

void Ninja::GoForIt(Map *map)
{
    char c = ' ';
    Point nextPosition;
    while(!_won && !_loop)
    {
        vector<Point> Obstacles;
        if(HaveShurikens())
        {
            bool foundHolySymbol = CheckForDestructibles(map, &Obstacles);
            if(foundHolySymbol)
            {
                DestroyHolySymbol(map, Obstacles[Obstacles.size() - 1]);
            }
            else if(FoundObstaclesToDestroy(Obstacles))
            {
                DestroyObstacles(map, Obstacles);
            }
        }
        if(!FoundObstaclesToDestroy(Obstacles))
        {
            Point nextPosition;
            CheckNextField(map, &c, &nextPosition);
            Act(map, &c, &nextPosition);
        }
    }
    if(_loop)
    {
        _logger.LogLoop();
    }
    else
    {
        _logger.LogDirection(_previousDirections);
    }
}

void Ninja::CheckNextField(Map *map, char *c, Point *nextPosition)
{
    *nextPosition = GetNewPoint(1, _direction);
    c[0] = map->GetElement(nextPosition->getX(), nextPosition->getY());
}

void Ninja::Act(Map *map, char *c, Point *nextPosition)
{
    if(c[0] >= 'F' && c[0] <= 'L')
    {
        MoveToNextPosition(nextPosition);
        SecretPathway(map, c[0]);
        return;
    }
    switch (c[0]) {
    case ' ':
    {
        MoveToNextPosition(nextPosition);
        break;
    }
    case '#':
    {
        SetPriority(&_direction);
        ChangeDirection(map);
        break;
    }
    case 'X':
    {
        if(!_breakerMode)
        {
            SetPriority(&_direction);
            ChangeDirection(map);
        }
        else
        {
            MoveToNextPosition(nextPosition);
            BreakWall(map);
        }
        break;
    }
    case '$':
    {
        if(!_breakerMode)
        {
            SetPriority(&_direction);
            ChangeDirection(map);
        }
        else
        {
            MoveToNextPosition(nextPosition);
            Win();
        }
        break;
    }
    case 'M':
    {
        MoveToNextPosition(nextPosition);
        Mirror();
        break;
    }
    case 'B':
    {
        MoveToNextPosition(nextPosition);
        Sake();
        break;
    }
    case '*':
    {
        MoveToNextPosition(nextPosition);
        PickUpShuriken(map);
        break;
    }
    default:
        MoveToNextPosition(nextPosition);
        ModifyPath(c);
        break;
    }
}

void Ninja::ChangeDirection(Map *map)
{
    bool found = false;
    int dir = (static_cast<int>(_direction));
    while(!found)
    {
        _direction = static_cast<Direction>(dir);
        Point p = GetNewPoint(1, _direction);
        if(map->GetElement(p.getX(), p.getY()) == '#')
        {
            dir +=_inverted;
            if(dir == 4)
            {
                dir = 0;
            }
            else if(dir == -1)
            {
                dir = 4;
            }
        }
        else
        {
            char c = map->GetElement(p.getX(), p.getY());
            if((c != 'X' && c != '$') || (_breakerMode))
            {
                found = true;
            }
            else
            {
                dir +=_inverted;
                if(dir == 4)
                {
                    dir = 0;
                }
                else if(dir == -1)
                {
                    dir = 4;
                }
            }
        }

    }
}

void Ninja::MoveToNextPosition(Point *nextPosition)
{
    _actualPosition.setValues(nextPosition->getX(), nextPosition->getY());
    LogPosition();
    LogDirection();
}

void Ninja::ModifyPath(char *c)
{
    _direction = static_cast<Direction>(_directionMap[c[0]]);
}

void Ninja::Mirror()
{
    _inverted *= - 1;
}

void Ninja::Sake()
{
    _breakerMode = !_breakerMode;
}

void Ninja::BreakWall(Map *map)
{
    map->setMap(_actualPosition.getX(), _actualPosition.getY(), ' ');
}

bool Ninja::FoundObstaclesToDestroy(vector<Point> Obstacles)
{
    return Obstacles.size() != 0;
}

void Ninja::SetPriority(Direction *direction)
{
    if(_inverted == 1)
    {
        *direction = SOUTH;
    }
    else
    {
        *direction = WEST;
    }
}

bool Ninja::HaveShurikens()
{
    return _shurikens > 0;
}

bool Ninja::CheckForDestructibles(Map *map, vector<Point> *Obstacles)
{
    Direction throwPriority;
    SetPriority(&throwPriority);
    bool foundHolySymbol = false;
    int i = 0;
    while(i < 4 && !foundHolySymbol)
    {
        foundHolySymbol = RayCast(map, throwPriority, Obstacles);
        i++;
        int dir = (static_cast<int>(throwPriority));
        dir += _inverted;
        if(dir == 4)
        {
            dir = 0;
        }
        else if(dir == -1)
        {
            dir = 4;
        }
        throwPriority = (static_cast<Direction>(dir));

    }
    return foundHolySymbol;
}

bool Ninja::RayCast(Map *map, Direction throwPriority, vector<Point> *Obstacles)
{
    bool foundHolySymbol = false;
    Point newPosition;

        int i = 1;
        char c;
        do
        {
            newPosition = GetNewPoint(i, throwPriority);
            c = map->GetElement(newPosition.getX(), newPosition.getY());
            if(c == '$')
            {
                foundHolySymbol = true;
                Obstacles->push_back(newPosition);
            }
            if(c == 'X')
            {
                Obstacles->push_back(newPosition);
            }
            i++;
        }while(c != '#' && !foundHolySymbol);
        if(foundHolySymbol)
        {
            return true;
        }
        else
        {
            return false;
        }
}

void Ninja::DestroyHolySymbol(Map *map, Point p)
{
    map->setMap(p.getX(), p.getY(), '*');
    _won = true;
}

Point Ninja::GetNewPoint(int i, Direction direction)
{
    Point p;
    switch (direction) {
        case SOUTH:
        {
            p = Point(_actualPosition.getX() + i, _actualPosition.getY());
            break;
        }
        case EAST:
        {
            p = Point(_actualPosition.getX(), _actualPosition.getY() + i);
            break;
        }
        case NORTH:
        {
            p = Point(_actualPosition.getX() - i, _actualPosition.getY());
            break;
        }
        case WEST:
        {
            p = Point(_actualPosition.getX(), _actualPosition.getY() - i );
            break;
        }
    }
    return p;
}

void Ninja::DestroyObstacles(Map *map, vector<Point> Obstacles)
{
    int i = 0;
    while(i < Obstacles.size() && _shurikens > 0)
    {
        map->setMap(Obstacles[i].getX(), Obstacles[i].getY(), '*');
        _shurikens--;
        i++;
    }
}

void Ninja::LogPosition()
{
    for(int i = static_cast<int>(_previousPositions.size() - 1); i >= 0 ; i--)
    {
        if(_previousPositions[i].getX() == _actualPosition.getX() && _previousPositions[i].getY() == _actualPosition.getY())
        {
            LoopAlert(i);
        }
    }
    _previousPositions.push_back(_actualPosition);
}

void Ninja::LogDirection()
{
    _previousDirections.push_back(_direction);
}

void Ninja::Win()
{
    _won = true;
}

void Ninja::PickUpShuriken(Map *map)
{
    _shurikens++;
    map->setMap(_actualPosition.getX(), _actualPosition.getY(), ' ');
}

void Ninja::LoopAlert(int i)
{
    int count = static_cast<int>(_previousPositions.size() - 1) - i;
    int j = count;
    i--;
    while(i >= 0 && j >= 0 && (_previousPositions[i].getX() == _previousPositions[count + i + 1].getX()) && (_previousPositions[i].getY() == _previousPositions[count + i + 1].getY()))
    {
        j--;
        i--;
    }
    if(j == 0)
    {
        _loop = true;
    }
}

void Ninja::SecretPathway(Map *map, char toFind)
{
    Point newPosition = map->GetPathwayEndLocation(_actualPosition, toFind);
    _actualPosition.setValues(newPosition.getX(), newPosition.getY());
}
