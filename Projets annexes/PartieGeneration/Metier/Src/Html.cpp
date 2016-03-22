#include "../Include/Html.h"

using namespace std;

Html *Html::m_instance;

Html::Html() : Element("Html") {
	m_body = Body::getInstance();
	m_head = Head::getInstance();
}

Html::~Html() {}

Html *Html::getInstance() 
{
	if(m_instance == NULL) {
		m_instance = new Html;
	}
	return m_instance;
}

