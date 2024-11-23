#include "Fichier.h"

//----------> Constructeur qui initialise le nom du fichier
Fichier::Fichier(const std::string& nom) : nomFichier(nom) {}



//----------> Méthode pour écrire dans le fichier
void Fichier::ecrireDansFichier(const std::string& contenu)
{
    //ouvre le fichier en mode ecrases l'ancien contenue
    std::ofstream fichier(nomFichier, std::ios::trunc);
    if (fichier.is_open()) 
    {
        fichier << contenu << std::endl; //ecrire le contenue
        fichier.close();  //fermer le fichier
    }
    else 
    {
        std::cerr << "Erreur d'ouverture du fichier pour écriture.\n";
    }
}



//----------> Méthode pour lire le contenu du fichier
std::string Fichier::lireDuFichier()const
{
    std::ifstream fichier(nomFichier);  // Ouvre le fichier en mode lecture
    std::string contenu, ligne;
    if (fichier.is_open()) 
    {
        while (std::getline(fichier, ligne)) //on lit ligne par ligne
        {
            contenu += ligne + "\n";
        }
        fichier.close(); //fermer le fichier
    }
    else 
    {
        std::cerr << "Erreur d'ouverture du fichier pour lecture.\n";
    }
    return contenu; //retourner le contenue lu
}


//----------> Méthode pour ecrire dans un fichier mais sans l'ecraser
void Fichier::ecrireDansFichierSansEcraser(const std::string& contenu)
{
    std::ofstream fichier(nomFichier, std::ios::app);// Ouvre le fichier en mode ajout (append)
    if (fichier.is_open())
    {
        fichier << contenu << std::endl; //ajouter contenue 
        fichier.close();  //fermer le fichier
    }
    else
    {
        std::cerr << "Erreur d'ouverture du fichier pour écriture.\n";
    }
}

