#ifndef HTML_H
#define HTML_H

#include <iostream>
#include "Element.h"
#include "Head.h"
#include "Body.h"

 /*
  * @class Html
  * Classe héritée d'Element qui contient l'ensemble de la page web
  */
class Html : public Element
{
public:
	Html();
	~Html();

	Body* getBody();
	Head* getHead();
private:
	Body *m_body;
	Head *m_head;

};

#endif