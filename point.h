#ifndef POINT_H
#define POINT_H


class Point
{
    int _x;
    int _y;
public:
    Point();
    Point(int x, int y);
    void setValues(int x, int y);
    int getX();
    int getY();
};

#endif // POINT_H
