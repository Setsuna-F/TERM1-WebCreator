/**
 * @file Head.h
 * @brief Classe représentant le Head de la page web
 * @author {Lucas CHABALIER, Théophile MANDON}
 * @version 0.1
 * @date 19/03/2016
 * Classe représentant le Head d'une page web
   Contient les liens vers les scripts JS, feuilles de style CSS, et définitions des métadonnées
 */

#ifndef HEAD_H
#define HEAD_H

#include <iostream>
#include "Element.h"

 /*
  * @class Head
  * Classe  héritée d'Element qui contient l'ensemble des liens css,js, et les métadonnées d'une page web
  */
class Head : public Element
{
public:
	Head();
	~Head();

	std::string toJson();
private:
    std::string m_title;
    std::vector<std::string> m_scripts;
    std::vector<std::string> m_links;
};
#endif
