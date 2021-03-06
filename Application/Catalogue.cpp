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
#include "TrajetCompose.h"

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
                	Rechercher();
                	break;
            	case '2':
                	AjouterTrajetSimple();
                	break;
            	case '3':
                	AjouterTrajetCompose();
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
// Appeller tout simplement le constructeur de ListeTrajet sur ListeT
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
}
//----- Fin de Catalogue


Catalogue::~Catalogue ()
// Algorithme :
// Destructeur de Catalogue
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void Catalogue::Afficher()const
// Algorithme :
// Affiche le catalogue, soit tout les trajets présents dans le catalogue
{
	cout<< "Le catalogue contient actuellement "<<ListeT.getSize();
	cout<< " trajet" << (ListeT.getSize()> 1 ?"s." :".")<<endl;
	cout << endl;
	for (unsigned int i = 0; i<ListeT.getSize();i++)
	{
		cout << "==============================================" << endl;
		ListeT.AccederElem(i)->Afficher();
	}
} // Fin de methode Afficher()

void Catalogue::AjouterTrajetSimple()
// Algorithme :
// Ajoute un trajet simple dans la liste des trajets
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
	Trajet *nouvelTraj = new TrajetSimple(VD,VA,MT,Nom);
	//ListeT.AjouterElem(nouvelTraj);
	//
	//Ajouter un element en respectant l'ordre alphaberique
	ListeT.AjouterElemAlpha(nouvelTraj);
	delete [] VD;
	delete [] VA;
	delete [] MT;
	delete [] Nom;
}

void Catalogue::AjouterTrajetCompose()
// Algorithme :
// Ajoute un trajet composé dans la liste des trajets
{
	char * NomC=new char[50];
    cout << "Donnez le nom du trajet compose : " << endl;
    cin >> NomC;
    TrajetCompose *nouvelTrajComp = new TrajetCompose(NomC);
    cout << "Veuillez ajouter au moins deux trajets simples : " << endl;
    nouvelTrajComp->AjouterTrajetSimple();
    nouvelTrajComp->AjouterTrajetSimple();
    char input = '0';
    do
    {
    	cout << "Tapez 0 pour entrer un sous-trajet." << endl;
    	cout << "Tapez 1 pour terminer." << endl;
    	cin >> input;
    	switch (input)
        {	
            case '0':
            	nouvelTrajComp->AjouterTrajetSimple();
            	break;
            case '1':
            	cout << "L'ajout d'un trajet compose est termine !" << endl;
                break;
        	default:
            cout << "Choix invalide. Choisir l'une des valeurs entre 0 et 1" << endl;
        }

    } while (input != '1');

	//ListeT.AjouterElem(nouvelTrajComp);
	ListeT.AjouterElemAlpha(nouvelTrajComp);
	delete [] NomC;
}

void Catalogue::Rechercher() const
// Algorithme :
// Permet de rechercher un trajet à partir d'une ville de départ et d'arrivé donnée par l'utilisateur
{
	char * VD=new char[50];
    cout << "Donnez une ville de depart : " << endl;
    cin >> VD;
    char * VA=new char[50];
    cout << "Donnez une ville d'arrivee : " << endl;
    cin >> VA;

    char * res;
    const Trajet * tmp;
    int token=0;
    //cout << "Check" << endl;
    for (unsigned int i = 0; i<ListeT.getSize();i++)
	{
		//cout << "Check" << endl;
		tmp=ListeT.AccederElem(i);
		//cout << "Check" << endl;
		res=tmp->Rechercher(VD, VA);
		if (strcmp(res,"non")==0)
		{
			//cout << "Check" << endl;
			delete [] res;
		}
		else
		{
			cout << "Le trajet " << res << " pourrait vous intéresser." << endl;
			token++;
		}
	}
	if (token==0)
		cout << "Desole, aucun trajet ne corespond à votre demande." << endl;

    delete [] VD;
	delete [] VA;
}
