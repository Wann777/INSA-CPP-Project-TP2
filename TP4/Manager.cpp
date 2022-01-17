/*************************************************************************
                           Manager  -  description
                             -------------------
    début                : $10/01/2022$
    copyright            : (C) $2022$ par $tdang,esoulier$
    e-mail               : $thanh.dang@insa-lyon.fr, erwan.soulier@insa-lyon.fr$
*************************************************************************/

//---------- Réalisation de la classe <Manager> (fichier Manager.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Manager.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Manager::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Manager::Execution(void)
//Algorithme :
{
    Renseignement* r = lec->LireLigne ();
    while(r != NULL)
    {
        if(optionE)
        {
            string exten;
            stringstream ss;
            ss.str(r->getCible());
            getline (ss, exten, '.');
            getline (ss, exten);
            if(exten!="jpg" && exten!="css" && exten!="js" && exten!="png")
            {
                if(optionT)
                {
                    int heureLigne = std::stoi(r->getHeure());
                    if (heure==heureLigne)
                        compt->Ajouter(r);
                }
                else
                    compt->Ajouter(r);
            }
        }
        else if(optionT)
        {
            int heureLigne = std::stoi(r->getHeure());
            if (heure==heureLigne)
                compt->Ajouter(r);
        }
        else
        {
            compt->Ajouter(r);
        }
        r = lec->LireLigne ();
    }
    compt->Trier();
    compt->Afficher();
    
} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur



Manager::Manager (string nomFic)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Manager>" << endl;
#endif
    lec = new Lecteur(nomFic);
    compt = new Compteur();
    optionE = false;
    optionT = false;
} //----- Fin de Manager

Manager::Manager (string nomFic, bool opte, bool optt, int h) : optionE(opte), optionT(optt), heure(h)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur spécifique de <Manager>" << endl;
#endif
    lec = new Lecteur(nomFic);
    compt = new Compteur();
} //----- Fin de Manager

Manager::~Manager ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Manager>" << endl;
#endif
} //----- Fin de ~Manager


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

