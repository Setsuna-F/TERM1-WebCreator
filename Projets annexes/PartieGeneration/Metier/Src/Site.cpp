#include "../Include/Site.h"

using namespace std;

Site::Site() : m_numberOfPagesMax(1), m_nomProjet("Sans titre") {}

Site::Site(string nom) : m_numberOfPagesMax(1), m_nomProjet(nom) {}

string Site::getNomProjet()const { return m_nomProjet;}
void Site::setNomProjet(string nom) {m_nomProjet = nom;}

PageWeb* Site::getPage(unsigned int i)
{
	if(i >= m_numberOfPagesMax)
		return NULL;
	return &m_projet[i];
}

void Site::addPage()
{
	if(m_projet.size() == m_numberOfPagesMax)
	{
		cout << "Nombre max de pages atteint!" << endl;
	}
	else
	{
		PageWeb p;
		m_projet.push_back(p);
	}
}

void Site::generate()
{
	cout << "Projet site web : " << m_nomProjet <<endl;
  for(unsigned int i=0;i<m_projet.size();i++)
	{
		cout << "Page numero " << i << "\n\n";
		m_projet[i].toString();
	}
}

string Site::toJson()
{
    string res ="{\n";
    res+="\t\"nom\" : \""+m_nomProjet+"\",\n";
    res+="\t\"type\" : \"projet\",\n";
    res+="\t\"html\" : [";
    for(unsigned int i=0;i<m_projet.size();i++)
    {
        res+="\""+m_projet[i].getNom()+".json\"";
        if(i<m_projet.size()-1)
        {
            res+=", ";
        }
    }
    res+="]\n";
    res+="}";
    return res;
}

void Site::sauvegarde()
{
    ofstream file(getNomProjet()+".json", ios::out | ios::trunc);
	if(file)
    {
        file<<toJson();
        for(unsigned int i=0;i<m_projet.size();i++)
        {
            m_projet[i].sauvegarde();
        }
    }
    else
    {
        cerr<<"Echec de la sauvegarde du projet "<<getNomProjet()<<"\n";
    }
}
