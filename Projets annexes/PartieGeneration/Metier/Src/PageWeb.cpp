#include "../Include/PageWeb.h"

using namespace std;

PageWeb::PageWeb() : m_nom("Sans titre") {}

PageWeb::PageWeb(string nom) : m_nom(nom) {}

string PageWeb::getNom()const {return m_nom;}
void PageWeb::setNom(string nom) {m_nom = nom;}

void PageWeb::toString()const
{
	cout << "PageWeb : " << m_nom << "\n";
	m_root.toString();
}

Html* PageWeb::getRoot() { return &m_root; }

string PageWeb::toJson()
{
    string res="{\n";
    res+="\t\"page\" : \""+m_nom+"\",\n";
    res+="\t\"content\" : {";
    res+=m_root.toJson();
    res+="\n\t}\n";
    res+="}";
    return res;
}

void PageWeb::sauvegarde()
{
    ofstream file(getNom()+".json", ios::out | ios::trunc);
	if(file)
    {
        file<<toJson();
    }
    else
    {
        cerr<<"Echec de la sauvegarde de la page " <<getNom()<<"\n";
    }
}
