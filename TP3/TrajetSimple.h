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

    const string Rechercher(const string& VD, const string& VA) const;
    // Mode d'emploi :
    //  Service permettant de vérifier si la ville de départ du trajet est la même
    //  que VD passée en paramètre et si la ville d'arrivée est la même
    //  que VA passée en paramètre
    // Contrat :
    //
    const string& getVilleDepart() const;
    // Mode d'emploi :
    //  Service permettant de retourner la ville de depart du trajet
    // Contrat :
    //
    const string& getVilleArrive() const;
    // Mode d'emploi :
    //  Service permettant de retourner la ville d'arrivee du trajet
    // Contrat :
    //
     const string& getNom() const;
    // Mode d'emploi :
    //  Service permettant de retourner le nom du trajet
    // Contrat :
    //

     const string& getMoyen() const;
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


    TrajetSimple ( const std::string& VD, const std::string& VA, const std::string& MT, const std::string&Nom );
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

//----------------------------------------------------- Attributs protégés
    string VilleDepart;
    string VilleArrive;
    string MoyenDeTransport;
    string NomTrajet;

};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TrajetSimple_H

