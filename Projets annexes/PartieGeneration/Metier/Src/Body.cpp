#include "../Include/Body.h"

using namespace std;

Body Body::m_instance = Body();

Body::Body() : Element("body") {}

Body::~Body() {}

Body& Body::getInstance() 
{
	return m_instance;
}

