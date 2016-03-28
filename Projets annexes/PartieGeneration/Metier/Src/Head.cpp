#include "../Include/Head.h"

using namespace std;

Head::Head() : Element("head") {}

Head::~Head() {}

string Head::toJson()
{
    string res="\t\t\t\"head\" : [\n";
    res+="\t\t\t\t{\"script\" : [";
    for(unsigned int i=0;i<m_scripts.size();i++)
    {
        if(i!=0){
            res+=", ";
        }
        res+="\""+m_scripts[i];
    }
    res+="]},\n";

    res+="\t\t\t\t{\"links\" : [";
    for(unsigned int i=0;i<m_links.size();i++)
    {
        if(i!=0){
            res+=", ";
        }
        res+="\""+m_links[i];
    }
    res+="]},\n";
    res+="\t\t\t\t{\"title\" : \""+m_title+"\"}\n";
    res+="\t\t\t],\n";
    return res;
}
