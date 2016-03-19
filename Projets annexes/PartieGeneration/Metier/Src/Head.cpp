#include "../Include/Head.h"

using namespace std;

Head Head::m_instance = Head();

Head::Head() : Element("Head") {}

Head::~Head() {}

Head& Head::getInstance() 
{
	return m_instance;
}

