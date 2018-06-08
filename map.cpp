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
