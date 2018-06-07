#include "namegenerator.h"

NameGenerator::NameGenerator()
{
    _nameMap = {{'a', "ka"}, {'b', "zu"}, {'c', "mi"}, {'d', "te"},
               {'e', "ku"}, {'f', "lu"}, {'g', "ji"}, {'h', "ri"},
               {'i', "ki"}, {'j', "zu"}, {'k', "me"}, {'l', "ta"},
               {'m', "rin"}, {'n', "to"}, {'o', "mo"}, {'p', "no"},
               {'q', "ke"}, {'r', "shi"}, {'s', "ari"}, {'t', "chi"},
               {'u', "do"}, {'v', "ru"}, {'w', "mei"}, {'x', "na"},
                {'y', "fu"}, {'z', "zi"}};
}

string NameGenerator::GenerateName(string name)
{
    int len = name.length();
    int i = 0;
    while(i < len && ((name[i] >= 'A' && name[i] <= 'Z') ||  (name[i] >= 'a' && name[i] <= 'z')))
    {
        i++;
    }
    string firstName = name.substr(0,i);
    firstName[0] = firstName[0] + 32;
    i++;
    while(i < len && !((name[i] >= 'A' && name[i] <= 'Z') ||  (name[i] >= 'a' && name[i] <= 'z')))
    {
        i++;
    }
    string secondName = name.substr(i,len-1);
    secondName[0] = secondName[0] + 32;
    string ninjaName = "";
    i = 0;
    int firstlen = firstName.length();

    while(i < firstlen && i < 4)
    {
        ninjaName += _nameMap[firstName[i]];
        i++;
    }
    ninjaName[0] -= 32;
    ninjaName += " ";
    int firstLetterofSecondName = ninjaName.length();
    int secondlen = secondName.length();
    i = 0;
    while(i < secondlen && i < 3)
    {
        ninjaName += _nameMap[secondName[i]];
        i++;
    }
    ninjaName[firstLetterofSecondName] -= 32;
    return ninjaName;
}
