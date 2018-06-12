#include "positioninfo.h"

PositionInfo::PositionInfo()
{

}

PositionInfo::PositionInfo(Point position, int inverted, bool breakerMode)
{
    _position = position;
    _inverted = inverted;
    _breakerMode = breakerMode;
}

bool PositionInfo::operator==(const PositionInfo &other) const
{
    if(other._position == this->_position && other._inverted == this->_inverted && other._breakerMode == this->_breakerMode)
    {
        return true;
    }
    return false;
}
