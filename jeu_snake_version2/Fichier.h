#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

class Fichier
{
private:
    std::string nomFichier;  // Attribut: nom du fichier

public:
    // Constructeur
    Fichier(const std::string& nom);

    // M�thode pour �crire dans le fichier avec ecrase de contenue precedent
    void ecrireDansFichier(const std::string& contenu);

    // M�thode pour lire le contenu du fichier
    std::string lireDuFichier()const;

    //ecrire sans ecraser le contenue de fichier
    void ecrireDansFichierSansEcraser(const std::string& contenu);
};


