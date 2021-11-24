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
    cout << "Nom du Trajet Compose : " << nomDeTrajet << endl;
    cout<< "Le trajet compose contient actuellement "<<sousTrajets.getSize();
    cout<< " trajet" << (sousTrajets.getSize()> 1 ?"s." :".")<<endl;
    for (unsigned int i = 0; i<sousTrajets.getSize();i++)
    {
        sousTrajets.AccederElem(i)->Afficher();
    }
}

void TrajetCompose::AjouterTrajetSimple()
{
    char * VD=new char[50];
    cout << "Donnez une ville de depart : " << endl;
    cin >> VD;
    char * VA=new char[50];
    cout << "Donnez une ville d'arrivee : " << endl;
    cin >> VA;
    char * MT=new char[50];
    cout << "Donnez le moyen de transport : " << endl;
    cin >> MT;
    char * Nom=new char[50];
    cout << "Donnez le nom du trajet : " << endl;
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
    //cout << "Check" << endl;
    char * res;
    const Trajet * tmp;
    const char * tmpVD=VD;
    for (unsigned int i = 0; i<sousTrajets.getSize();i++)
    {
        //cout << "Check1" << endl;
        tmp=sousTrajets.AccederElem(i);
        //cout << "Check2" << endl;
        res=tmp->Rechercher(tmpVD, VA);
        if (strcmp(res,"non")==0)
        {
            //cout << "Check" << endl; 
            delete [] res;
        }
        else
        {
            return nomDeTrajet;
        }
        //cout << "Check3" << endl;
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

