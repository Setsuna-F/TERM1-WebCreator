/**
 * @file Head.h
 * @brief Classe représentant le Head de la page web
 * @author {Lucas CHABALIER, Théophile MANDON}
 * @version 0.1
 * @date 19/03/2016
 * Classe représentant le Head d'une page web, qui existe en un seul exemplaire (singleton)
   Contient les liens vers les scripts JS, feuilles de style CSS, et définitions des métadonnées
 */

#ifndef HEAD_H
#define HEAD_H

#include <iostream> 


 /*
  * @class Head
  * Classe Singleton héritée d'Element qui contient l'ensemble des liens css,js, et les métadonnées d'une page web
  */
class Head : public Element
{
public:
	virtual static Head& getInstance();
private:
	//On empêche les operator= et les constructeurs par copie ici
	Head& operator=(const Head&) {}
	Head(const Head&) {}

	static Head m_instance; /*!< Représente l'unique instance du Head */
	Head();
	virtual ~Head();
};
#endif
