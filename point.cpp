#include "point.h"

void Point::setValues(int x, int y)
{
    _x = x;
    _y = y;
}

int Point::getX()
{
    return _x;
}

int Point::getY()
{
    return _y;
}

bool Point::operator==(const Point &other) const
{
    if(other._x == this->_x && other._y == this->_y)
    {
        return true;
    }
    return false;
}

Point::Point()
{
}

Point::Point(int x, int y)
{
    _x = x;
    _y = y;
}
