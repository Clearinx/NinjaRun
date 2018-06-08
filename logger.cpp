#include "logger.h"

Logger::Logger()
{
    _directionStrings[0] = "SOUTH";
    _directionStrings[1] = "EAST";
    _directionStrings[2] = "NORTH";
    _directionStrings[3] = "WEST";

}

void Logger::LogDirection(std::vector<Direction> _previousDirections)
{
    for(int i = 0; i < static_cast<int>(_previousDirections.size()); i++)
    {
        cout << _directionStrings[static_cast<int>(_previousDirections[i])] << endl;
    }
    cout << "Game Over" << endl;
}

void Logger::LogLoop()
{
    cout << "LOOP" << endl;
}

Logger::~Logger()
{

}

