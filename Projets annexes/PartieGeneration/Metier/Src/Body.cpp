#include "../Include/Body.h"

using namespace std;

Body::Body() {}

Body::~Body() {}

Element* Body::getChild(unsigned int i)
{
    if(i<m_childs.size())
    {
        return &m_childs[i];
    }
    return NULL;
}

void Body::addChild(Element child)
{
    m_childs.push_back(child);
}

void Body::removeChild(unsigned int i)
{
    if(i<m_childs.size())
    {
        m_childs.erase(m_childs.begin()+i);
    }
}

void Body::toString() const
{
    cout << "<body>\n";
    for(unsigned int i=0;i<m_childs.size();i++)
    {
        m_childs[i].toString();
    }
    cout << "</body>\n";
}

string Body::toJson()
{
    string res="\t\t\t\"body\" : [\n";
    res+="\t\t\t\t{ \"content\" : [\n";
    for(unsigned int i=0;i<m_childs.size();i++)
    {
        if(i>0)
        {
            res+=", \n";
        }
        res+=m_childs[i].toJson();
    }
    res+="\t\t\t\t]}";
    res+="\t\t\t]\n";
    return res;
}
