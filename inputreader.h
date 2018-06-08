#ifndef INPUTREADER_H
#define INPUTREADER_H
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class InputReader
{
    vector<string>_maplistVector;
public:
    InputReader();
    void GetMapList(string s);
    vector<string>GetMapListVector();
    static std::vector<std::vector<char>> GetCurrentMap(string mapname);
};

#endif // INPUTREADER_H
