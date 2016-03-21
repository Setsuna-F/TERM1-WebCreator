#include "../Include/Html.h"

using namespace std;

Html Html::m_instance = Html();

Html::Html() : Element("Html") {

}

Html::~Html() {}

Html& Html::getInstance() 
{
	return m_instance;
}

