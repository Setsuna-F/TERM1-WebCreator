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


 /*
  * @class Body
  * Classe Singleton héritée d'Element qui contient l'ensemble des éléments de la page ( = <body>...</body>)
  */
class Body : public Element
{
public:
	virtual static Body& getInstance();
private:
	//On empêche les operator= et les constructeurs par copie ici
	Body& operator=(const Body&) {}
	Body(const Body&) {}

	static Body m_instance; /*!< Représente l'unique instance du Body */
	Body();
	virtual ~Body();
};
#endif