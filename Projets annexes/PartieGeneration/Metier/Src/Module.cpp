#include "../Include/Module.h"

using namespace std;

void moduleToElement(Element& e)
{
    string moduleName = e.getModuleName();
    /*if(moduleName == "")
      return;*/
    string path = "modules/"+moduleName+".json";
    cout << path <<endl;
    ifstream fichier(path, ios::in);  // on ouvre en lecture le fichier JSON
    if(fichier)
    {
        //Là on ouvre le fichier JSON et tout et tout
        string contenu;
        getline(fichier,contenu);
        e.setElementName(contenu);
        fichier.close();
    }
    else
        cerr << "Fichier impossible à ouvrir!" << endl;
}
