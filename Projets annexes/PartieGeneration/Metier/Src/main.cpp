#include <iostream>
#include <vector>
#include "../Include/Html.h"
#include "../Include/Element.h"
#include "../Include/PageWeb.h"
#include "../Include/Site.h"


using namespace std;

int main(int argc, char *argv[])
{
	Site s("proj",15);
	s.addPage();
	PageWeb* web = s.getPage(0);
	web->setNom("Test");
	Html* html = web->getRoot();
	html->getHead()->setTitle("Le projet");
	Body* body = html->getBody();
	Element e("p","Coucou");
	body->addChild(e);
	Element e2("p","C'est le projet");
	body->addChild(e2);
	s.generate();
	cout << "\n";
	cout<<endl<<endl<<s.toJson();
	cout<<endl<<endl<<s.getPage(0)->toJson();
	s.sauvegarde();
    s.charger("Test.json");
    s.generate();

    /*cout<<endl<<endl;
	Element r("p_perso"); //Je like cette petite guerre des commentaires ou on commente les tests de l'autre
	r.toString();*/
  return 0;
}
