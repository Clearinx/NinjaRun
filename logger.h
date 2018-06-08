#ifndef LOGGER_H
#define LOGGER_H
#include <iostream>
#include <vector>
#include "direction.h"
using namespace std;

class Logger
{
    string _directionStrings[4];
public:
    Logger();
    void LogDirection(vector<Direction> _previousDirections);
    void LogLoop();
    ~Logger();
};

#endif // LOGGER_H
