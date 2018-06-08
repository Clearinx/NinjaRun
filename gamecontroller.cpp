#include "gamecontroller.h"

GameController::GameController()
{

}

void GameController::Start(string mapNameList)
{
    InputReader ir;
    ir.GetMapList(mapNameList);
    NameGenerator n;
    string ninjaName = n.GenerateName("Horvath, Tamas");
    for(int i = 0; i<ir.GetMapListVector().size(); i++)
    {
        string currentMapName = ir.GetMapListVector()[i];
        ir.GetCurrentMap(currentMapName);
    }
}
