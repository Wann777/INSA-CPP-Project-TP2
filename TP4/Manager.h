/*************************************************************************
                           Manager  -  description
                             -------------------
    début                : $10/01/2022$
    copyright            : (C) $2022$ par $tdang,esoulier$
    e-mail               : $thanh.dang@insa-lyon.fr, erwan.soulier@insa-lyon.fr$
*************************************************************************/

//---------- Interface de la classe <Manager> (fichier Manager.h) ----------------
#if ! defined ( MANAGER_H )
#define MANAGER_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Manager>
//
//
//------------------------------------------------------------------------

class Manager : public Ancetre
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    Manager & operator = ( const Manager & unManager );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Manager ( const Manager & unManager );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Manager ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Manager ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Manager>

#endif // MANAGER_H

