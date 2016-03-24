#include "../Include/Site.h"

using namespace std;

Site::Site() : m_numberOfPagesMax(1), m_nomProjet("Sans titre") {}

Site::Site(string nom) : m_numberOfPagesMax(1), m_nomProjet(nom) {}

string Site::getNomProjet()const { return m_nomProjet;}
void Site::setNomProjet(string nom) {m_nomProjet = nom;}

PageWeb* Site::getPage(int i) 
{ 
	if(i >= m_numberOfPagesMax) 
		return NULL;
	return m_projet[i];
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
		m_projet.p
	}
}