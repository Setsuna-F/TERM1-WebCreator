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

//Getters and Setters
string Element::getId() const {return id;}
string Element::getElementName() const {return elementName;}
string Element::getContent() const {return content;}

void Element::setContent(string content) {this->content=content;}
void Element::setElementName(string elementName) {this->elementName=elementName;}
void Element::setId(string id) {this->id=id;}

//Getters for map elements
string Element::getAttribute(string attributeName) const
{
    string attribute = attributes[attributeName];
    if(attribute != "")
        return attribute;
    cout << "This attribute doesn't exist in the attributes map!" <<endl;
    return null;
}

string Element::getStyle(string styleName) const
{
    string style = styles[styleName];
    if(style != "")
        return style;
    cout << "This style doesn't exist in the styles map!" <<endl;
    return null;
}

//Setters for map elements
void Element::setAttribute(string attributeName, string attribute)
{
    attributes[attributeName] = attribute;
}

void Element::setStyle(string styleName , string style)
{
    styles[styleName] = style;
}
