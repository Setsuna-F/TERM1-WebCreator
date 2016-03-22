#include <iostream>
#include <vector>
#include "../Include/Html.h"
#include "../Include/Element.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
	Html* html = Html::getInstance();
	Body* body = Body::getInstance();
	Head* head = Head::getInstance();
	Element e("p","Coucou");
	body->addElement(e);
	html->toString();
	cout << "\n";
    return 0;
}
