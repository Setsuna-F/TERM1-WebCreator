#ifndef SITE_H
#define SITE_H

#include <iostream>
#include <vector>
#include <string>
#include <PageWeb.h>

//Contient un ensemble de pages web
class Site
{
private:
	int m_numberOfPagesMax;
	std::string m_nomProjet;
	std::vector<PageWeb> m_projet;
public:
	Site();
	Site(std::string);

	std::string getNomProjet()const;
	void setNomProjet(std::string);

	PageWeb* getPage(int);
	void addPage();
	void generate();{}
};

#endif
