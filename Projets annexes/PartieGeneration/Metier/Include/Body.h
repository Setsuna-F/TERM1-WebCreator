/**
 * @file Body.h
 * @brief Classe représentant le body de la page web
 * @author {Lucas CHABALIER, Théophile MANDON}
 * @version 0.1
 * @date 19/03/2016
 * Classe représentant le body d'une page web, qui existe en un seul exemplaire (singleton)
 */

#ifndef BODY_H
#define BODY_H

#include <iostream>
#include "Element.h"


 /*
  * @class Body
  * Classe Singleton héritée d'Element qui contient l'ensemble des éléments de la page ( = <body>...</body>)
  */
class Body : public Element
{
public:
	static Body *getInstance();
private:
	static Body *m_instance; /*!< Représente l'unique instance du Body */
	Body();
	~Body();
	
};
#endif