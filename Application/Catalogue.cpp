/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $15/11/2021$
    copyright            : (C) $2021$ par $tdang,esoulier$
    e-mail               : $thanh.dang@insa-lyon.fr, erwan.soulier@insa-lyon.fr$
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "TrajetSimple.h"
//#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC


//----------------------------------------------------- Méthodes publiques
void Catalogue::Menu()

// Algorithme :
//Proposer des services differents aux utilisateurs
{
	char input = '0';
	do 
	{
		cout<<endl;
		cout << "==================== MENU ====================" << endl;
        	cout << "Choisir un service: " << endl;
        	cout << "0 : Afficher les trajets disponibles" << endl;
       		cout << "1 : Rechercher des trajets" << endl;
		cout << "2 : Ajouter un nouveau trajet simple" << endl;
        	cout << "3 : Ajouter un nouveau trajet compose" << endl;
        	cout << "4 : Quitter l'application" << endl;
        	cin >> input;
        	cout << "==============================================" << endl;
        	switch (input)
        	{	
            	case '0':
                	Afficher();
                	break;
            	case '1':
                	//Rechercher();
                	break;
            	case '2':
                	//AjouterTrajetSimple();
                	break;
            	case '3':
                	//AjouterTrajetCompose();
                	break;
            	case '4':
                	cout << "Au revoir..." << endl;
                	break;
            	default:
                cout << "Choix invalide. Choisir l'une des valeurs entre 0 et 4" << endl;
        	}
    	} while (input != '4');
} //----- Fin de Méthode Menu

//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue (): ListeT()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
}
//----- Fin de Catalogue


Catalogue::~Catalogue ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void Catalogue::Afficher()const
{
	cout<< "Le catalogue contient actuellement "<<ListeT.getSize();
	cout<< " trajet" << (ListeT.getSize()> 1 ?"s." :".")<<endl;
	for (unsigned int i = 0; i<ListeT.getSize();i++)
	{
		ListeT.AccederElem(i)->Afficher();
	}
} // Fin de methode Afficher()

