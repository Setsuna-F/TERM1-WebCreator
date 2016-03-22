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

Element::Element() : m_id(""), m_elementName(""), m_content("") {}

Element::Element(string elementName) : m_content("")
{
    this->m_elementName = elementName;
    m_id = generateId(elementName);
}

Element::Element(string elementName, string content)
{
    this->m_elementName = elementName;
    this->m_content=content;
    m_id = generateId(elementName);
}

Element::~Element() {}

//Getters and Setters
string Element::getId() const {return m_id;}
string Element::getElementName() const {return m_elementName;}
string Element::getContent() const {return m_content;}

void Element::setContent(string content) {this->m_content=content;}
void Element::setElementName(string elementName) {this->m_elementName=elementName;}
void Element::setId(string id) {this->m_id=id;}

//Getters for map elements
string Element::getAttribute(string attributeName)
{
    string attribute = m_attributes[attributeName];
    if(attribute != "")
        return attribute;
    cout << "This attribute doesn't exist in the attributes map!" <<endl;
    return NULL;
}

string Element::getStyle(string styleName)
{
    string style = m_styles[styleName];
    if(style != "")
        return style;
    cout << "This style doesn't exist in the styles map!" <<endl;
    return NULL;
}

//Setters for map elements
void Element::setAttribute(string attributeName, string attribute)
{
    m_attributes[attributeName] = attribute;
}

void Element::setStyle(string styleName , string style)
{
    m_styles[styleName] = style;
}

void Element::addElement(Element& e) 
{
    m_childElements.push_back(&e);
}

void Element::toString() const 
{
    cout << "<" << m_elementName << ">";
    for(unsigned int i=0;i<m_childElements.size();i++) 
    {
        cout << "\n\t";
        m_childElements[i]->toString();
    }
    cout << "</" << m_elementName << ">";
}
