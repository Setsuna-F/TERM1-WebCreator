#include <iostream>
#include <vector>
#include "../Include/Html.h"
#include "../Include/Element.h"
#include "../Include/PageWeb.h"

using namespace std;

int main(int argc, char *argv[])
{
	PageWeb web("TestPage");
	Html* html = web.getRoot();
	Body* body = html->getBody();
	Element e("p","Coucou");
	body->addElement(e);
	Element e2("p","C'est le projet");
	body->addElement(e2);
	web.toString();
	cout << "\n";
    return 0;
}
