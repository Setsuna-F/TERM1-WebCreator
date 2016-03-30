#include <iostream>
#include <vector>
#include "../Include/Html.h"
#include "../Include/Element.h"
#include "../Include/PageWeb.h"
#include "../Include/Site.h"


using namespace std;

int main(int argc, char *argv[])
{
	Site s;
	s.addPage();
	PageWeb* web = s.getPage(0);
	web->setNom("Test");
	Html* html = web->getRoot();
	Body* body = html->getBody();
	Element e("p","Coucou");
	body->addChild(e);
	Element e2("p","C'est le projet");
	body->addChild(e2);
	s.generate();
	cout << "\n";
	cout<<endl<<endl<<s.toJson();
	cout<<endl<<endl<<s.getPage(0)->toJson();
	cout<<endl<<endl<<html->toJson();
	s.sauvegarde();
  return 0;
}
