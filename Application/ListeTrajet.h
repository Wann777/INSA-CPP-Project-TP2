/*************************************************************************
                           ListeTrajet  -  description
                             -------------------
    début                : $15/11/2021$
    copyright            : (C) $2021$ par $tdang,esoulier$
    e-mail               : $thanh.dang@insa-lyon.fr, erwan.soulier@insa-lyon.fr$
*************************************************************************/

//---------- Interface de la classe <ListeTrajet> (fichier ListeTrajet.h) ----------------
#if ! defined ( ListeTrajet_H )
#define ListeTrajet_H

//--------------------------------------------------- Interfaces utilisées
#include "Maillon.h"

//------------------------------------------------------------------ Types
//class Trajet;

//Maillon de la ListeTrajet
//struct Maillon {
//	Trajet *trajet; //pointeur sur le Trajet associé au Maillon
//	Maillon *suiv; //pointeur sur le Maillon suivant
//};

//------------------------------------------------------------------------
// Rôle de la classe <ListeTrajet>
// Une ListeTrajet est une collection ordonnée de Trajets
// La ListeTrajet permet d'ajouter un Trajet, et d'accéder à un Trajet
// Attributs :
// - racine : le premier maillon de la liste chainee
// - taille : nombre de Trajets dans la liste (nombre de maillons)
//
//------------------------------------------------------------------------

class ListeTrajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void AjouterElem (const TrajetSimple* unTrajet);
    // Mode d'emploi :
    // Ajoute le Trajet pointé par unTrajet à la listeTrajet, en faisant une
    // copie en profondeur du trajet à ajouter
    // Contrat :
    // unTrajet pointe vers un Trajet valide
    const Trajet* AccederElem (unsigned int pos) const;
   // Mode d'emploi :
    // Retourne un pointeur vers le Trajet a la position pos  de la liste
    // chainee
    // Contrat :
    // pos < taille de la liste
    unsigned int getSize () const;
    //Mode d'emploi :
    // Retourne la taille de la listeTrajet (nb de trajets dans la liste)
    // 0 si ListeTrajet est vide
    // Contrat: 


//-------------------------------------------- Constructeurs - destructeur
    ListeTrajet ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    ListeTrajet ( const ListeTrajet & uneListe );
    // Mode d'emploi (constructeur de copie) :
    // Recopie en profondeur de uneListe
    // Contrat :

    virtual ~ListeTrajet ();
    // Mode d'emploi : Liberer la memoire allouee
    // Contrat :

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
   Maillon *racine;
   unsigned int taille;

};

//-------------------------------- Autres définitions dépendantes de <ListeTrajet>

#endif // ListeTrajet_H

