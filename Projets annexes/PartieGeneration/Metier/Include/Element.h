/**
 * @file Element.h
 * @brief Classe pour un Elément Web
 * @author {Lucas CHABALIER, Théophile MANDON}
 * @version 0.1.1
 * @date 05/03/2016
 * Classe représentant un élément web, avec ses attributs propres, inspiré du design pattern Composite.
   Changelog :
   - v0.1 : première version
   - v0.1.1 : Ajout du mot-clé virtual aux méthodes
 */

#ifndef ELEMENT_H
#define ELEMENT_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "IdHandler.h"



 /*
  * @class Element
  * Classe composite représentant un élément web (un <p>...</p> par exemple)
  */
class Element
{
	private:
		std::string m_id; /*!< id de l'élément (pour la gestion du CSS) */
		std::string m_moduleName; /*!< Nom du module utilisé */
		std::string m_elementName; /*!< Nom de l'élément (p,h1,h2,etc...) */
		std::map<std::string, std::string> m_attributes; /*!< Attributs HTML de l'élément (width,height pour une image par exemple) */
        std::map<std::string, std::string> m_styles; /*!< Style CSS propres à l'élément et ses éventuels fils */
		std::vector<Element> m_childElements; /*!< Eléments fils (le vector peut-être vide) */
		std::string m_content; /*!< Contenu de l'élément, du texte (utilisé au début du dev) */

	public:
		Element();
		Element(std::string);
		Element(std::string, std::string);
		virtual ~Element();

		//Getters for string attributes
		virtual std::string getId()const;
		virtual std::string getElementName()const;
		virtual std::string getContent()const;
		virtual std::string getModuleName()const;
		//Setters for string attributes
		virtual void setId(std::string);
		virtual void setElementName(std::string);
		virtual void setContent(std::string);

        //Getters for map elements
        virtual std::string getAttribute(std::string);
        virtual std::string getStyle(std::string);
        //Setters for map elements
		virtual void setAttribute(std::string, std::string);
		virtual void setStyle(std::string, std::string);

		virtual void addElement(Element);
		virtual void toString()const;

		virtual std::string toJson();
};



#endif
