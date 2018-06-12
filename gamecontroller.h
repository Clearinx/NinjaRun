#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include "inputreader.h"
#include "namegenerator.h"
#include "map.h"
#include "ninja.h"
#include <string>
#include <vector>

class GameController
{
public:
    GameController();
    void Start(string mapNameList);
};

#endif // GAMECONTROLLER_H
