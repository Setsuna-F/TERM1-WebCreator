#ifndef HTML_H
#define HTML_H

#include <iostream>
#include "Element.h"
#include "Head.h"
#include "Body.h"

 /*
  * @class Html
  * Classe Singleton héritée d'Element qui contient l'ensemble de la page web
  */
class Html : public Element
{
public:
	static Html& getInstance();
private:
	//On empêche les operator= et les constructeurs par copie ici
	Html(const Html&) {}
	Body m_body;
	Head m_head;
	static Html m_instance; /*!< Représente l'unique instance du Html */
	Html();
	virtual ~Html();
};

#endif