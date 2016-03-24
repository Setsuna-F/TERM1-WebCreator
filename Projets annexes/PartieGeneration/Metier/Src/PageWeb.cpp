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