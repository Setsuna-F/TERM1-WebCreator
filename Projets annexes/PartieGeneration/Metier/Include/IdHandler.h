#ifndef IDHANDLER_H
#define IDHANDLER_H

#include <iostream>
#include <string>
#include <map>

static std::map<std::string, int> ids;

/*
 * @fn generateId
 * @brief Fonction qui génère l'ID d'un élément (pour le CSS)
 * @param string elementName : le nom de l'élément
 * @return l'ID de l'élément, sous la forme : elementNameX (x étant la xième occurence du type de l'élément)
 */
std::string generateId(std::string);

#endif