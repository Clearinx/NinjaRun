#ifndef LOGGER_H
#define LOGGER_H
#include <iostream>
#include <vector>
#include "direction.h"
#include <string>
using namespace std;

class Logger
{
    string _directionStrings[4];
public:
    Logger();
    void LogDirection(vector<Direction> _previousDirections);
    void LogLoop();
    void LogName(string name);
    void LogThrow();
    ~Logger();
};

#endif // LOGGER_H
