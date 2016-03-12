#include "Element.h"

using namespace std;

Element::Element() : m_contenu(""), m_balise("") {}

Element::Element(string contenu,string balise,int x,int y, int xl, int yl) : m_contenu(contenu), m_balise(balise), m_x_position(x), m_y_position(y), m_x_longueur(xl), m_y_longueur(yl) {}

Element::~Element() {}

string Element::toString() const
{
	string ret = "<"+m_balise+">"+m_contenu;
	for(unsigned int i=0;i<m_elemFils.size();i++)
	{
		ret+="\n\t"+m_elemFils[i].toString();
	}
	ret+="</"+m_balise+">\n";
	return ret;
}

void Element::addElement(Element e)
{
	m_elemFils.push_back(e);
}

void Element::supprElement(Element e)
{
	for(unsigned int i=0;i<m_elemFils.size();i++)
	{
		if(m_elemFils[i] == e)
		{
			m_elemFils.erase(m_elemFils.begin()+i);
		}
	}
}

void Element::modifPosElem(Element e, int pos)
{
	if(pos >= m_elemFils.size())
	{
		cout << "Position trop élevée - Placement en dernier.." <<endl;
		this->supprElement(e);
		m_elemFils.push_back(e);
		return;
	}
	else
	{
		this->supprElement(e);
		m_elemFils.insert(m_elemFils.begin()+pos,e);
	}
}

int Element::getX(){
	return m_x_position;
}

int Element::getY(){
	return m_y_position;
}

int Element::getXLongueur(){
	return m_x_longueur;
}

int Element::getYLongueur(){
	return m_y_longueur;
}

int Element::getElemFilsSize(){
	return m_elemFils.size();
}

Element& Element::getElemFils(int i){
	return m_elemFils[i];
}

bool Element::operator==(const Element& e){
	return (this==&e);
}
