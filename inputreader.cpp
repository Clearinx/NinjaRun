#include "inputreader.h"

InputReader::InputReader()
{

}

void InputReader::GetMapList(string mapListFileName)
{
    ifstream file(mapListFileName);
    if(file.is_open())
    {
        while(!file.eof())
        {
            string temp = "";
            file >> temp;
            if(temp != "")
            {
                _maplistVector.push_back(temp);
            }
        }
    }

}

vector<string> InputReader::GetMapListVector()
{
    return this->_maplistVector;
}

vector<std::vector<char> > InputReader::GetCurrentMap(string mapname)
{
    vector<vector<char>> map;
    ifstream file(mapname);
    if(file.is_open())
    {
        while(!file.eof())
        {
            string temp = "";
            getline(file, temp);
            if(temp != "")
            {
                vector<char> line;
                for(int i = 0; i<temp.length(); i++)
                {
                    line.push_back(temp[i]);
                }
                map.push_back(line);
            }
        }
    }
    return map;
}









