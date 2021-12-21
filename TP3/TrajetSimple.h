/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $15/11/2021$
    copyright            : (C) $2021$ par $tdang,esoulier$
    e-mail               : $thanh.dang@insa-lyon.fr, erwan.soulier@insa-lyon.fr$
*************************************************************************/


//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#if ! defined ( TrajetSimple_H )
#define TrajetSimple_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include <string>
#include <cstring>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
//  La classe Trajet Simple est une descendante de la classe Trajet
//  Elle corespond à un voyage direct d'une ville de départ à une ville d'arrivée
//
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    
    void Afficher(void) const;
    // Mode d'emploi :
    //  Permet d'afficher le trajet simple
    // Contrat :
    //

    string getDescription ()const;
    //Mode d'emploi:
    // Service permettant de retourner les infos d'un trajet simple en chaine 
    // de caracteres
    // Contrat: 
    // un trajet valide

    char * Rechercher(const char * VD, const char * VA) const;
    // Mode d'emploi :
    //  Service permettant de vérifier si la ville de départ du trajet est la même
    //  que VD passée en paramètre et si la ville d'arrivée est la même
    //  que VA passée en paramètre
    // Contrat :
    //
    char * getVilleDepart() const;
    // Mode d'emploi :
    //  Service permettant de retourner la ville de depart du trajet
    // Contrat :
    //
    char * getVilleArrive() const;
    // Mode d'emploi :
    //  Service permettant de retourner la ville d'arrivee du trajet
    // Contrat :
    //
     char * getNom() const;
    // Mode d'emploi :
    //  Service permettant de retourner le nom du trajet
    // Contrat :
    //

      char * getMoyen() const;
    // Mode d'emploi :
    //  Service permettant de retourner le moyen de transport du trajet
    // Contrat :
    //



//-------------------------------------------- Constructeurs - destructeur
    TrajetSimple ( const TrajetSimple & unTrajetSimple );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    TrajetSimple (const string& uneDescription);
    // Mode d'emploi :
    //  Permet d'initialiser un trajet simple à partir d'une description 
    //  qui contient des infos de trajet
    //  Contrat: description est une chaine de caracteres

    TrajetSimple (const char * VD, const char * VA, const char * MT, const char * Nom);
    // Mode d'emploi :
    //  Permet d'initialiser un trajet simple à partir d'une ville de départ passée
    //  en paramètre (VD), d'une ville d'arrivée passée en paramètre (VA), d'un moyen
    //  de transport passé en paramètre (MT) et d'un com de trajet passé en paramètre (Nom)
    // Contrat :
    //

    virtual ~TrajetSimple ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
string convertirChar (const char* unPtrChar)const;

//----------------------------------------------------- Attributs protégés
    char * VilleDepart;
    char * VilleArrive;
    char * MoyenDeTransport;
    char * NomTrajet;

};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TrajetSimple_H

