/*************************************************************************
                           Graphe  -  description
                            -------------------
    début                : $10/01/2022$
    copyright            : (C) $2022$ par $tdang,esoulier$
    e-mail               : $thanh.dang@insa-lyon.fr, erwan.soulier@insa-lyon.fr$
*************************************************************************/

//---------- Interface de la classe <Graphe> (fichier Graphe.h) ----------------
#if ! defined ( Graphe_H )
#define Graphe_H

//--------------------------------------------------- Interfaces utilisées
#include "Renseignement.h"
#include <map>
#include <string>
#include <set>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef map<string,int> refMap;
//------------------------------------------------------------------------
// Rôle de la classe <Graphe>
//
//
//------------------------------------------------------------------------

class Graphe
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
    void Afficher(void);
    void CreerFicDot();


//------------------------------------------------- Surcharge d'opérateurs
    //Compteur & operator = ( const Compteur & unCompteur );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    //Compteur ( const Compteur & unCompteur );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Graphe (const std::string& nomGraphe);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Graphe ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
 	
    	typedef map<string,refMap> Tgraphe;
    	typedef set<string> Tnoeud;
    	Tgraphe logGraphe;
    	Tnoeud listeN;
    	string nomFicDot;
    	

};

//-------------------------------- Autres définitions dépendantes de <Compteur>

#endif // Compteur_H

