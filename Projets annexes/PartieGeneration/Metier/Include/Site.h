/**
 * @file Site.h
 * @brief Classe repr�sentant l'ensemble du site web
 * @author {Lucas CHABALIER, Th�ophile MANDON}
 * @version 0.1
 * @date 19/03/2016
 * Classe repr�sentant l'ensemble du site web
   Contient le nombre de pages max autoris�es, le nom du projet et toutes les pages web contenues dans le projet
 */

#ifndef SITE_H
#define SITE_H

#include <iostream>
#include <vector>
#include <string>
#include "PageWeb.h"

//Contient un ensemble de pages web
class Site
{
    private:
        unsigned int m_numberOfPagesMax;
        std::string m_nomProjet;
        std::vector<PageWeb> m_projet;
    public:
        Site();
        Site(std::string, int);

        void charger(std::string);
        void clearProjet();

        std::string getNomProjet()const;
        void setNomProjet(std::string);

        PageWeb* getPage(unsigned int);
        void addPage();
        void generate();

        std::string toJson();
        void sauvegarde();
};

#endif
