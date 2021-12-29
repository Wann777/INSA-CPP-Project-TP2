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
#include <string>
#include <fstream>
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
	string VD = VerifierChaine("Donnez une ville de depart : ");
	string VA = VerifierChaine("Donnez une ville d'arrivee : ");
	string MT = VerifierChaine("Donnez un moyen de transport : ");
	string Nom = VerifierChaine("Donnez un nom de trajet : ");
	TrajetSimple *unNouvSimp = new TrajetSimple(VD,VA,MT,Nom);
	ListeT.AjouterElemAlpha(unNouvSimp);
	cout<< "Le trajet simple nomme "<< Nom << " a ete ajoute au catalogue. " <<endl;

}

void Catalogue::AjouterTrajetCompose()
// Algorithme :
// Ajoute un trajet composé dans la liste des trajets
{
    string Nom = VerifierChaine("Donnez le nom du trajet compose : ");
    TrajetCompose *nouvelTrajComp = new TrajetCompose(Nom,true);
    cout << "Veuillez ajouter au moins deux  sous-trajets ! " << endl;
    string etapePre;
    string etapeSui;
    string MT;
    string NomST;
    etapePre = VerifierChaine ("Donnez une ville de depart : ");
    etapeSui = VerifierChaine ("Donnez une ville d'escale : ");
    do
    {
		MT = VerifierChaine ("Donnez un moyen de transport : ");
        NomST = VerifierChaine ("Donnez un nom de ce sous-trajet : ");
		TrajetSimple* unNouvST = new TrajetSimple(etapePre,etapeSui,MT,NomST);
		nouvelTrajComp->AjouterTrajetSimple(unNouvST);
		etapePre = etapeSui;
		etapeSui= VerifierChaine("Donnez une ville d'escale (ou tapez 0 pour terminer ce trajet) : ");
    }
    while (etapeSui != "0");
    ListeT.AjouterElemAlpha(nouvelTrajComp);
    cout<< "Le trajet compose nomme "<< Nom << " a ete ajoute au catalogue. " <<endl;
}

void Catalogue::Rechercher() const
// Algorithme :
// Permet de rechercher un trajet à partir d'une ville de départ et d'arrivé donnée par l'utilisateur
{
	
     string VD = VerifierChaine("Donnez une ville de depart a chercher : ");
     string VA = VerifierChaine("Donnez une ville d'arrivee a chercher : ");
    string res;
    const Trajet * tmp;
    int token=0;
    for (unsigned int i = 0; i<ListeT.getSize();i++)
	{
		tmp=ListeT.AccederElem(i);
		res=tmp->Rechercher(VD, VA);
		if (res.compare("non")!=0&&res.compare("VD")!=0)	
		{
			cout << "Le trajet " << res << " pourrait vous intéresser." << endl;
			token++;
		}
	}
	if (token==0)
		cout << "Desole, aucun trajet ne corespond à votre demande." << endl;
}
string Catalogue::VerifierChaine(string const& contenu, bool autoriseVide) const
// Algorithme :
// Verifie si une chaine de caractères est valide
{
    bool bonneSaisie;
    string chaine = " ";
    do
    {	
		bonneSaisie = true;
        if(!contenu.empty())
        {
            cout << contenu << flush;
	    //Afficher le contenu avant la saisie
        }
        getline(cin, chaine);
        if(cin.eof())
	//premier cas de figure: on est a la fin du fichier (EOF)
        {
            cout << endl << "La fin du flux est atteinte. Veuillez saisir une nouvelle chaine !" << endl;
            cin.clear();
            bonneSaisie = false;
        }
        else if(!autoriseVide && chaine.empty())
        {
	//deuxieme cas de figure: la chaine est vide
            cout << "Veuillez saisir une chaine non vide !" << endl;
            bonneSaisie = false;
        }
	else if(cin.fail())
        {
	//troisieme cas de figure: l'entree n'est pas de type string
            cout << endl << "Lecture invalide. Veuillez saisir une nouvelle chaine !" << endl;
            cin.clear();
            bonneSaisie = false;
        }

    }
    while(!bonneSaisie);
    return chaine;
} //----- Fin de lireChaine

