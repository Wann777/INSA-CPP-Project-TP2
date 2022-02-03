/*************************************************************************
                           Compteur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Compteur> (fichier Compteur.h) ----------------
#if ! defined ( COMPTEUR_H )
#define COMPTEUR_H

//--------------------------------------------------- Interfaces utilisées
#include "Renseignement.h"
#include <iostream>
#include <map>


//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
 typedef map<string,int> Tcompte;
 typedef multimap<int,string,greater<int>> Tcomptetrier; //structure pour le tri
//------------------------------------------------------------------------
// Rôle de la classe <Compteur>
// Compter le nombre de hits de chaque document et le trier 
// pour afficher les 10 documents les plus consultes
//
//------------------------------------------------------------------------

class Compteur
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    void Ajouter(Renseignement * r);
    // Mode d'emploi :
    // Ajouter l'objet de type Renseignement dans la struc Tcompte
    // Contrat : Pointeur est non null
    //
    void Trier(void);
    // Mode d'emploi :
    // Trier la map dans l'ordre decroissant du nombre de hits
    // Contrat : Pointeur est non null
    //


//------------------------------------------------- Surcharge d'opérateurs
   
    //std::ostream& operator << (std::ostream& os);
    friend std::ostream& operator << (std::ostream& os, const Compteur &c);
    // Mode d'emploi :
    // Afficher 10 cibles ayant le nb de hits le plus eleve
    // Contrat :

//-------------------------------------------- Constructeurs - destructeur
    //Compteur ( const Compteur & unCompteur );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Compteur ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Compteur ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
   
    Tcompte compteCibles;
    Tcomptetrier compteCiblesTrier;

};

//-------------------------------- Autres définitions dépendantes de <Compteur>

#endif // Compteur_H

