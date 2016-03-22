#include "../Include/Html.h"

using namespace std;

Html *Html::m_instance;

Html::Html() : Element("html") {
	this->addElement(*Head::getInstance());
	this->addElement(*Body::getInstance());
}

Html::~Html() {}

Html *Html::getInstance() 
{
	if(m_instance == NULL) {
		m_instance = new Html;
	}
	return m_instance;
}

