#include <iostream>
#include "Element.h"
#include <string>
#include <vector>

using namespace std;

void ajoutMalin(Element& root, Element& e){
	int i;
	Element* parent = &root;
	for(i=root.getElemFilsSize()-1;i>=0;i--){
		if(root.getElemFils(i).getX()<e.getX()&&root.getElemFils(i).getY()<e.getY()&&root.getElemFils(i).getX()+root.getElemFils(i).getXLongueur()>e.getX()+e.getXLongueur()&&root.getElemFils(i).getY()+root.getElemFils(i).getYLongueur()>e.getY()+e.getYLongueur()){
			parent = &(root.getElemFils(i));
		}
	}
	if(*(parent)==root){
        cout<<"bj";
        root.addElement(e);
		for(i=root.getElemFilsSize()-1;i>=0;i--){
			if(root.getElemFils(i).getX()<e.getX()&&root.getElemFils(i).getY()<e.getY()){
				root.modifPosElem(e,i);
				break;
			}
		}
	} else {
	    cout<<"av";
		parent->addElement(e);
	}
}

int main(int argc, char ** argv)
{
	Element root("","html",0,0,1280,720);
	cout << "Gestionnaire page web" <<endl;
	while(1)
	{
		cout << "Page HTML :\n";
		cout << root.toString();
		cout << "Que voulez-vous faire ?" <<endl << "\t1-Ajouter un élément"<<endl<<"\t2-Modifier la position d'un élément"<<endl;
		cout << "Votre choix :";
		int choix=0;
		cin >> choix;
		if (choix == 1)
		{
			int choixElem=0;
			cout <<"\n\nQuel élément ?\n\t1- div\n\t2- p\nVotre choix :";
			cin >> choixElem;
			cout << "contenu :";
			string content;
			cin >> content;
			int x,y,xl,yl;
			cout<<"Entrez la position en x du coin haut gauche"<<endl;
			cin >> x;
			cout<<"Entrez la position en y du coin haut gauche"<<endl;
			cin >> y;
			cout<<"Entrez la longeur en x"<<endl;
			cin >> xl;
			cout<<"Entrez la longeur en y"<<endl;
			cin >> yl;
			if (choixElem == 1)
			{
				ajoutMalin(root, *(new Element(content,"div",x,y,xl,yl)));
			}
			if (choixElem == 2)
			{
				ajoutMalin(root, *(new Element(content,"p",x,y,xl,yl)));
			}
		}
		else if (choix == 2)
		{

		}
		else
		{
			break;
		}
	}

	cout << endl << endl << "Page HTML :\n";
	cout << root.toString();

	return 0;
}
