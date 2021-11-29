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
#include "Trajet.h"
#include "TrajetSimple.h"

//------------------------------------------------------------------ Types


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
    void AjouterElem (Trajet* unTrajet);
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
    void AjouterElemAlpha (Trajet* unTrajet);
   // Mode d'emploi :
    // Ajoute un element dans la liste en respectant l'ordre alphaberique 
    // de ville de depart et d'arrivee
    // Contrat :
    // unTrajet pointe vers un Trajet valide



//-------------------------------------------- Constructeurs - destructeur
    ListeTrajet ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//    ListeTrajet ( const ListeTrajet & uneListe );
    // Mode d'emploi (constructeur de copie) :
    // Recopie en profondeur de uneListe
    // Contrat :

    virtual ~ListeTrajet ();
    // Mode d'emploi : Liberer la memoire allouee
    // Contrat :

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

    int Comparer (Trajet* t1, Trajet* t2) const;
    // Mode d'emploi :
    // Compare la ville de depart et d'arrivee de t1 et t2 par order alphaberique
    // Retourne 0 si pareil
    //-1 si t1 est plus petit que t2 dans l'ordre lexicographique, par exemple Bordeaux vs Lyon
    // 1 si t1 est plus grand que t2, par ex Lyon vs Paris
    // Contrat :
    // t1 et t2 sont valides

//----------------------------------------------------- Attributs protégés
   Maillon *racine;
   unsigned int taille;

};

//-------------------------------- Autres définitions dépendantes de <ListeTrajet>

#endif // ListeTrajet_H

