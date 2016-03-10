#include "../Include/Element.h"

using namespace std;

/*
 * @fn generateId
 * @brief Fonction qui génère l'ID d'un élément (pour le CSS)
 * @param string elementName : le nom de l'élément
 * @return l'ID de l'élément, sous la forme : elementNameX (x étant la xième occurence du type de l'élément)
 */
string generateId(string elementName)
{
    return elementName;
}

Element::Element() : id(""), elementName(""), content("") {}

Element::Element(string elementName) : content("")
{
    this->elementName = elementName;
    id = generateId(elementName);
}

Element::Element(string elementName, string content)
{
    this->elementName = elementName;
    this->content=content;
    id = generateId(elementName);
}

Element::~Element() {}

string Element::getId() const {return id;}
string Element::getElementName() const {return elementName;}
string Element::getContent() const {return content;}

void Element::setContent(string content) {this->content=content;}
void Element::setElementName(string elementName) {this->elementName=elementName;}
void Element::setId(string id) {this->id=id;}




