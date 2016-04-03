#include "../Include/Html.h"

using namespace std;

Html::Html(){
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

string Html::toJson()
{
    string res="\t\t\"html\" : {\n";
    res+=m_head->toJson();
    res+=m_body->toJson();
    res+="\t\t}";
    return res;
}
