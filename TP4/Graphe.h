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
typedef map<string,int> refMap; //la map pour <referer,hits>
//------------------------------------------------------------------------
// Rôle de la classe <Graphe>
// Creer le fichier .dot
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
    // Mode d'emploi :
    // Ajouter l'objet de type Renseignement dans la struc Tgraphe
    // Contrat : Pointeur est non null
    //
    void CreerFicDot();
     // Mode d'emploi :
    //Creer le fichier dot a partir de l'attribut logGraphe
    // Contrat : rien
    //


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
    	Tnoeud listeN; //stocker les noeuds du graphe
    	string nomFicDot;
    	

};

//-------------------------------- Autres définitions dépendantes de <Compteur>

#endif // Compteur_H

