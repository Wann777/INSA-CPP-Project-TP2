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

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Renseignement>
//
//
//------------------------------------------------------------------------

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


//-------------------------------------------- Constructeurs - destructeur
    Renseignement ( const Renseignement & unRenseignement );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Renseignement ( string source, string destination, string heure);
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

//----------------------------------------------------- Attributs protégés
    string cible;
    string referer;
    string date;

};

//-------------------------------- Autres définitions dépendantes de <Renseignement>

#endif // RENSEIGNEMENT_H

