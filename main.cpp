#include "namegenerator.h"
#include "inputreader.h"
#include "gamecontroller.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{

    GameController gc;
    gc.Start(argv[1]);
    return 0;
}
