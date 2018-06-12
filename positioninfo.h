#ifndef POSITIONINFO_H
#define POSITIONINFO_H
#include "point.h"

class PositionInfo
{
    Point _position;
    int _inverted;
    bool _breakerMode;
public:
    PositionInfo();
    PositionInfo(Point position, int inverted, bool breakerMode);
    bool operator== (const PositionInfo & other) const;
};

#endif // POSITIONINFO_H
