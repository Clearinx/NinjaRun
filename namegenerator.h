#ifndef NAMEGENERATOR_H
#define NAMEGENERATOR_H
#include <map>
#include <string>
#include <sstream>
using namespace std;

class NameGenerator
{
    map<char, string> _nameMap;
public:
    NameGenerator();
    string GenerateName(string name);
};

#endif // NAMEGENERATOR_H
