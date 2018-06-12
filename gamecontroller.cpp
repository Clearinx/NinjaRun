#include "gamecontroller.h"

GameController::GameController()
{

}

void GameController::Start(string mapNameList)
{
    InputReader ir;
    ir.GetMapList(mapNameList);
    NameGenerator n;
    Logger log;
    string ninjaName = n.GenerateName("Horvath, Tamas");
    for(int i = 0; i < static_cast<int>(ir.GetMapListVector().size()); i++)
    {
        log.LogName(ninjaName);
        string currentMapName = ir.GetMapListVector()[i];
        Map m(ir.GetCurrentMap(currentMapName));
        Ninja n(m.GetStart());
        n.GoForIt(&m);
    }
}
