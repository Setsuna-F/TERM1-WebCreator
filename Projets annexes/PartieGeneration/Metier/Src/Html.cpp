#include "../Include/Html.h"

using namespace std;

Html::Html() : Element("html") {
	m_body = new Body();
	m_head = new Head();
	this->addElement(*m_head);
	this->addElement(*m_body);
}

Html::~Html() {}

Body* Html::getBody() 
{
	return m_body;
}

Head* Html::getHead() 
{
	return m_head;
}
