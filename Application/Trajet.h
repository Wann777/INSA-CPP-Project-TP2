/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $15/11/2021$
    copyright            : (C) $2021$ par $tdang,esoulier$
    e-mail               : $thanh.dang@insa-lyon.fr, erwan.soulier@insa-lyon.fr$
*************************************************************************/


//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( Trajet_H )
#define Trajet_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
//  La classe Trajet est la classe mère de Trajet simple et composé
//  Elle permet d'utiliser le polymorphisme afin de ne pas différencier
//  ses deux classes filles dans la liste de trajet
//
//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual void Afficher(void) const;
    // Mode d'emploi :
    //  Service permettant d'afficher le trajet
    //  N'est jamais utilisé par trajet, plutôt par ses descendants Trajets simple et composé
    // Contrat :
    //
    virtual char * getVilleDepart() const;
    // Mode d'emploi :
    //  Service permettant de retourner la ville de départ du trajet
    //  N'est jamais utilisé par trajet, plutôt par ses descendants Trajets simple et composé
    // Contrat :
    //
    virtual char * getVilleArrive() const;
    // Mode d'emploi :
    //  Service permettant de retourner la ville d'arrivée du trajet
    //  N'est jamais utilisé par trajet, plutôt par ses descendants Trajets simple et composé
    // Contrat :
    //
    /*virtual char * getMoyenDeTransport() const;
    virtual char * getNomTrajet() const;*/
    virtual char * Rechercher(const char * VD, const char * VA) const;
    // Mode d'emploi :
    //  Service permettant de rechercher si la ville de départ du trajet coresponds à
    //  VD passé en paramètre et si la ville d'arrivée corespond à VA passé en paramètre
    //  N'est jamais utilisé par trajet, plutôt par ses descendants Trajets simple et composé
    // Contrat :
    //
//-------------------------------------------- Constructeurs - destructeur
    Trajet ( const Trajet & unTrajet );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    //Trajet (const char * VD, const char * VA);
    // Mode d'emploi :
    //
    // Contrat :
    //

    Trajet ();

    virtual ~Trajet ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    //char * VilleDepart;
    //char * VilleArrive;
};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // Trajet_H

