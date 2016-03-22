#include "../Include/Body.h"

using namespace std;

Body *Body::m_instance;

Body::Body() : Element("body") {}

Body::~Body() {}

Body *Body::getInstance() 
{
	if(m_instance == NULL) {
		m_instance = new Body();
	}
	return m_instance;
}

