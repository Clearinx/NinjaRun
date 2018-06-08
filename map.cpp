#include "map.h"

Map::Map(vector<std::vector<char>> map)
{
    _map = map;
}

void Map::setMap(int height, int width, char c)
{
    _map[height][width] = c;
}

Point Map::GetStart()
{
    bool found = false;
    unsigned i = 0;
    unsigned j = 0;
    while(i < _map.size() && !found)
    {
        j = 0;
        while(j < _map[0].size() && !found)
        {
            if(_map[i][j] == '@')
            {
               found = true;
            }
            else
            {
                j++;
            }
        }
        if(!found)
        {
            i++;
        }
    }


    return Point(i,j);
}

char Map::GetElement(int x, int y)
{
    return _map[x][y];
}

Point Map::GetPathwayEndLocation(Point actualPosition, char toFind)
{
    for(int i = 1; i< static_cast<int>(_map.size() - 1); i++)
    {
        for(int j = 1; j< static_cast<int>(_map[0].size() - 1); j++)
        {
            if(_map[i][j] == toFind && (i != actualPosition.getX() || j != actualPosition.getY()))
            {
                return Point(i,j);
            }
        }
    }
    throw "Pathway endpoint not found!";
}
