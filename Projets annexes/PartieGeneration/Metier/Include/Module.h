#ifndef MODULE_H
#define MODULE_H

#include <iostream>
#include <string>
#include <fstream>
#include "Element.h"

/*
 * @fn moduleToElement
 * @brief Fonction qui va lire un .json pour permettre le passage du module à un Element de la page web
 * @param Element &elem : Un élément, qui a au moins un nom de module
 * @return Modifie l'élément si le JSON est correctement trouvé, sinon ne fait rien.
 */
void moduleToElement(Element& e);

#endif
