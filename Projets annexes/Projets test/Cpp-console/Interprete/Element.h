#ifndef ELEM_H
#define ELEM_H

#include <iostream>
#include <string>
#include <vector>

class Element 
{
	private:
		std::string m_contenu;
		std::string m_balise;
		std::vector<Element> m_elemFils;
		int m_x_position, m_y_position, m_x_longueur, m_y_longueur;
	public:
		Element();
		Element(std::string,std::string,int,int,int,int);
		~Element();
		std::string toString() const;
		void addElement(Element e);
		void supprElement(Element e);
		void modifPosElem(Element e, int pos);
		int getX();
		int getY();
		int getXLongueur();
		int getYLongueur();
		int getElemFilsSize();
		Element& getElemFils(int);
		bool operator==(const Element&);
};

#endif
