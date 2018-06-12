#ifndef POINT_H
#define POINT_H
using namespace std;

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
    bool operator== (const Point & other) const;
};

#endif // POINT_H
