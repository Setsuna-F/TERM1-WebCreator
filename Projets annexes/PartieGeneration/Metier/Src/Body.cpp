#include "../Include/Body.h"

using namespace std;

Body::Body() : Element("body") {}

Body::~Body() {}

string Body::toJson()
{
    string res="\t\t\t\"body\" : [\n";
    res+="\t\t\t\t{ \"content\" : [\n";
    for(unsigned int i=0;i<m_childs.size();i++)
    {
        res+=m_childs[i].toJson();
    }
    res+="\t\t\t\t]}";
    res+="\t\t\t]\n";
    return res;
}
