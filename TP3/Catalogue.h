/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $15/11/2021$
    copyright            : (C) $2021$ par $tdang,esoulier$
    e-mail               : $thanh.dang@insa-lyon.fr, erwan.soulier@insa-lyon.fr$
*************************************************************************/


//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( Catalogue_H )
#define Catalogue_H

//--------------------------------------------------- Interfaces utilisées
#include "ListeTrajet.h"
#include "Filtre.h"
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
// Permet d'afficher le menu d'interaction avec l'utilisateur et
// de stocker les trajets.
//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void Menu ();
    // Mode d'emploi :
    //	Faire apparaître le menu qui permet a l'utilisateur d'avoir l'acces
    //	aux services fournis par le catalogue
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    Catalogue ();
    // Mode d'emploi :
    //  Initialise la liste chainée du catalogue
    // Contrat :
    //

    virtual ~Catalogue ( );
    // Mode d'emploi :
    //  Détruit le catalogue
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

    void Afficher(void) const;
    // Mode d'emploi :
    // Faire apparaître le contenu du catalogue
    // Contrat :
    //

    void Rechercher() const;
    // Mode d'emploi :
    // Service qui permet de rechercher un seul trajet (simple ou compose)
    // entre deux villes,
    // Contrat :
    
    void AjouterTrajetSimple();
    // Mode d'emploi :
    // Service qui permet de ajouter un trajet simple entre deux villes,
    // Contrat :

    void AjouterTrajetCompose();
     // Mode d'emploi :
    // Service qui permet de ajouter un trajet compose entre deux villes,
    // Contrat :
    
    void Charger ( );
    // Mode d'emploi :
    // Service qui permet d'ajouter au catalogue des trajets à partir d'un fichier
    // Propose à l'utilisateur plusieurs filtres lors du chargement : Sans Critere, Type, Ville,
    //Intervalle.
 
    // Contrat :
    
    
    void Sauvegarder ( ) const;
    // Mode d'emploi :
    // Service qui permet de sauvegarder dans un fichier les trajets courants du Catalogue.
    // Ce fichier serait un fichier existant
    // ou un nouveau.
    // Propose à l'utilisateur plusieurs filtres lors de la sauvegarde: Sans Critere, Type, Ville,
    //Intervalle.
   
    // Contrat :
   
    std::string VerifierChaine (bool autoriseVide = false) const;
    // Mode d'emploi :
    // Service qui lit, verifie et retourne une nouvelle ligne sur l'entree
    // autoriseVide : si false, une chaine vide a l'entree n'est pas autorisee 
    // Contrat :
    // Rien
    unsigned int VerifierEntier() const;
    // Mode d'emploi :
    // Service qui lit, verifie et retourne un entier positif sur l'entree 
    // Contrat :
    // Rien
    void ChoisirFiltre (Filtre*& unPtrFiltre, std::string nomFicACharger = " ") const;
    // Mode d'emploi :
    // Service qui instancie dynamiquement un 
    //filtre demande par l'utilisateur
    // 
    // Contrat :
    // Rien
    unsigned int CompterLignes(std::string const& nomFic) const;
    // Mode d'emploi :
    // Retourne le nombre de lignes dans le fichier
    // nomFic
    // Contrat :
    // Rien

//----------------------------------------------------- Attributs protégés
    ListeTrajet ListeT;
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // Catalogue_H

