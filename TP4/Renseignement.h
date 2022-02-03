/*************************************************************************
                           Renseignement  -  description
                             -------------------
    début                : $10/01/2022$
    copyright            : (C) $2022$ par $tdang,esoulier$
    e-mail               : $thanh.dang@insa-lyon.fr, erwan.soulier@insa-lyon.fr$
*************************************************************************/

//---------- Interface de la classe <Renseignement> (fichier Renseignement.h) ----------------
#if ! defined ( RENSEIGNEMENT_H )
#define RENSEIGNEMENT_H
#include <string>
using namespace std;

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Renseignement>
// Transformer les documents dans le fichier .log en elements comme cible, referer et moment
//
//------------------------------------------------------------------------
struct MOMENT
{
    string date;
    string mois;
    string an;
    string heure;
    string minute;
    string seconde;
    string decalage;
};


class Renseignement
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    const string& getCible();
    const string& getReferer();
    const string& getHeure();
    int getDecalage (); 

//-------------------------------------------- Constructeurs - destructeur
    Renseignement ( const Renseignement & unRenseignement );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Renseignement ( string source, string destination, string moment);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Renseignement ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    void makeMomentPrecis (const string& moment);

//----------------------------------------------------- Attributs protégés
    string cible;
    string referer;
    MOMENT unMoment;

};

//-------------------------------- Autres définitions dépendantes de <Renseignement>

#endif // RENSEIGNEMENT_H

