/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $15/11/2021$
    copyright            : (C) $2021$ par $tdang,esoulier$
    e-mail               : $thanh.dang@insa-lyon.fr, erwan.soulier@insa-lyon.fr$
*************************************************************************/


//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type TrajetSimple::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void TrajetCompose::Afficher() const
{
// Algorithme : Parcourir la liste sousTrajets pour afficher tous les sous-trajets

	cout << "TRAJET COMPOSE: " << nomDeTrajet << endl; 
    cout<< "Ce trajet compose contient actuellement "<<sousTrajets.getSize();
    cout<< " sous-trajet" << (sousTrajets.getSize()> 1 ?"s." :".")<<endl;
    cout << endl;
    for (unsigned int i = 0; i<sousTrajets.getSize();i++)
    {
        sousTrajets.AccederElem(i)->Afficher();
        cout << endl;
    }
}

void TrajetCompose::AjouterTrajetSimple()
{
//Algorithme: Ajouter un sous-trajet de type TrajetSimple pour fabriquer un trajet compose
//Contrat: La ville d'arrivee du sous-trajet n est la ville de depart du sous-trajet n+1 
    char * VD=new char[50];
    cout << "Donnez une ville de depart : " << endl;
    cin >> VD;
    while (sousTrajets.getSize()!=0 && strcmp(VD,(sousTrajets.AccederElem(sousTrajets.getSize()-1))->getVilleArrive())!=0)
	 {
		 cout<< "La ville de depart de ce sous-trajet est incoherente !" <<endl;
		 cout << "Donnez une ville de depart valide : " << endl;
    		cin >> VD; 
	 }
    char * VA=new char[50];
    cout << "Donnez une ville d'arrivee : " << endl;
    cin >> VA;
    char * MT=new char[50];
    cout << "Donnez le moyen de transport : " << endl;
    cin >> MT;
    char * Nom=new char[50];
    cout << "Donnez le nom du sous trajet : " << endl;
    cin >> Nom;
    TrajetSimple *nouvelTraj = new TrajetSimple(VD,VA,MT,Nom);
    sousTrajets.AjouterElem(nouvelTraj);
    delete [] VD;
    delete [] VA;
    delete [] MT;
    delete [] Nom;
}

char * TrajetCompose::Rechercher(const char * VD, const char * VA) const
{

// Algorithme : Parcourir la liste de sousTrajets pour verifier chaque sous-trajet
// sa ville de depart et sa ville d'arrivee


    char * res;
    const Trajet * tmp;
    const char * tmpVD=VD;
    for (unsigned int i = 0; i<sousTrajets.getSize();i++)
    {
        tmp=sousTrajets.AccederElem(i);
        res=tmp->Rechercher(tmpVD, VA);
        if (strcmp(res,"non")==0)
        {
            delete [] res;
        }
        else
        {
            return nomDeTrajet;
        }
        if (strcmp(tmp->getVilleDepart(),tmpVD)==0)
        {
            tmpVD=tmp->getVilleArrive();
        }
        else
            break;
    }

    char * tmpReturn=new char[4];
    strcpy(tmpReturn,"non");
    return tmpReturn;
}


//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose ( const TrajetCompose & unTrajetCompose )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;
#endif
    
} //----- Fin de TrajetCompose (constructeur de copie)


TrajetCompose::TrajetCompose (const char * Nom): sousTrajets()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
    nomDeTrajet = new char[strlen(Nom)+1];

    strcpy(nomDeTrajet,Nom);
} //----- Fin de TrajetSimple


TrajetCompose::~TrajetCompose ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
    delete [] nomDeTrajet;
    
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

