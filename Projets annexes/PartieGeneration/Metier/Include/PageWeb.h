#ifndef PAGEWEB_H
#define PAGEWEB_H

#include <iostream>
#include <string>
#include "Html.h"

//Contient un HTML
class PageWeb 
{
	private:
		std::string m_nom;
		Html m_root;
	public:
		PageWeb();
		PageWeb(std::string);

		std::string getNom()const;
		void setNom(std::string);

		Html* getRoot();

		void toString()const;
};

#endif