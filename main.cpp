#include "namegenerator.h"
#include "inputreader.h"
#include "gamecontroller.h"
int main(int argc, char *argv[])
{

    GameController gc;
    gc.Start("input-all.list");
    return 0;
}
