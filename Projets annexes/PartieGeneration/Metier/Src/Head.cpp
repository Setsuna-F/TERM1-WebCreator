#include "../Include/Head.h"

using namespace std;

Head *Head::m_instance;

Head::Head() : Element("Head") {}

Head::~Head() {}

Head *Head::getInstance() 
{
	if(m_instance == NULL) {
		m_instance = new Head;
	}
	return m_instance;
}

