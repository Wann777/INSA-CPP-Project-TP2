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
#include <string>
#include <sstream>

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

string TrajetCompose::getDescription () const
{
// Algorithme :
// Retourne une chaine de caracteres qui decrit les infos de trajet
// chaque element de trajet se separe par un ,
	string result;
	result = "C-" + convertirChar(nomDeTrajet) + ":";
	string desTraj = (sousTrajets.AccederElem(0))->getDescription();
	desTraj.assign(desTraj.begin()+2, desTraj.end());
	//on supprime les 2 premieres caracteres dans la description d'un trajet simple
	result += desTraj;
	
	for (unsigned int i = 1; i<sousTrajets.getSize();++i)
	{
	// pour tous les autres sous trajets, on affiche que la ville d'arrivee
		desTraj = (sousTrajets.AccederElem(i))->getDescription();
		string copie = desTraj;	
		desTraj.assign(desTraj.begin()+2, desTraj.begin()+desTraj.find(':'));
		//on affect le nom du sous trajet dans la description
		result += desTraj+":"; 
		
		copie.assign(copie.begin()+copie.find(',')+1, copie.end());
		result += copie;
		//on affecte la ville d'arrivee et le moyen de transport
    	}
	return result;
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

char * TrajetCompose::getVilleDepart() const
// Algorithme : 
//  Retourne la ville de départ du trajet composé, soit le premier élément de la liste
{
    return sousTrajets.AccederElem(0)->getVilleDepart();
}

char * TrajetCompose::getVilleArrive() const
// Algorithme : 
//  Retourne la ville d'arrivée du trajet composé, soit la dernière ville de la liste
{
    return sousTrajets.AccederElem(sousTrajets.getSize()-1)->getVilleArrive();
}

char * TrajetCompose::getNom() const
{
    return nomDeTrajet;
}

//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose ( const TrajetCompose & unTrajetCompose )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetCompose>" << endl;
#endif
    
} //----- Fin de TrajetCompose (constructeur de copie)

TrajetCompose::TrajetCompose (const string& uneDescription)
{
	
	stringstream ss;
    ss.str(uneDescription);
    string type;
    string nT, nomSousTraj, vD, vA, mT;
    getline(ss,type,'-'); //On recupere le type de trajet, ici c'est C
    getline(ss,nT,':'); //On recupere le nom de trajet
    
    nomDeTrajet = new char[nT.length()+1];
    strcpy(nomDeTrajet,nT.c_str());

    getline(ss,nomSousTraj,':'); //On recupere le nom du premier sous trajet
    getline(ss,vD,','); //On recupere le nom de ville de depart du premier sous trajet


    while (!ss.eof())
    {
    	getline(ss,vA,',');
	//On recupere le nom de ville d'arrivee du premier sous trajet
	// il est aussi le nom de ville de depart du sous trajet suivant
    	getline(ss,mT,',');
	string uneDes = "S-" + nomSousTraj + ":" + vD + "," + vA + "," + mT + ","; 
	TrajetSimple* unSousTrajet= new TrajetSimple(uneDes);//creation un nouveau sous trajet
	sousTrajets.AjouterElem(unSousTrajet); //ajout ce sous trajet dans la liste
	getline(ss,nomSousTraj,':');//on recupere le nom de sous trajet suivant
	vD = vA; //ville de Depart de sous Trajet suivant
    }

}
TrajetCompose::TrajetCompose (const char * Nom): sousTrajets()
// Algorithme :
//  Constructeur de Trajet composé qui créé une liste de trajets vides et applique le nom passé en paramètre
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
std::string TrajetCompose::convertirChar (const char* unPtrChar)const
{
        string s(unPtrChar);
        return s;
}

