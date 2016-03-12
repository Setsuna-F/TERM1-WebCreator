/**
 * @file Element.h
 * @brief Classe pour un Elément Web
 * @author {Lucas CHABALIER, Théophile MANDON}
 * @version 0.1
 * @date 05/03/2016
 * Classe représentant un élément web, avec ses attributs propres, inspiré du design pattern Composite.
 */

#ifndef ELEMENT_H
#define ELEMENT_H

#include <iostream>
#include <string>
#include <vector>


 /*
  * @class Element
  * Classe composite représentant un élément web (un <p>...</p> par exemple)
  */
class Element 
{
	private:
		std::string id; /*!< id de l'élément (pour la gestion du CSS) */
		std::string elementName; /*!< Nom de l'élément (p,h1,h2,etc...) */
		std::vector<std::string> attributes; /*!< Attributs HTML de l'élément (width,height pour une image par exemple) */
		std::vector<std::string> style; /*!< Style CSS propres à l'élément et ses éventuels fils */
		std::vector<Element> childElements; /*!< Eléments fils (le vector peut-être vide) */
		
		std::string content; /*!< Contenu de l'élément, du texte (utilisé au début du dev) */
		
	public:
		Element();
		Element(std::string);
		Element(std::string, std::string);
		~Element();
		
		//Getters for string attributes
		std::string getId()const;
		std::string getElementName()const;
		std::string getContent()const;
		//Setters for string attributes
		void setId(std::string);
		void setElementName(std::string);
		void setContent(std::string);
		
		//Getters for vector element
		std::string getAttribute(int);
	
};

std::string generateId(std::string);

#endif
