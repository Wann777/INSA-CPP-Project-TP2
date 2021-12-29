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
	result = "C-" + nomDeTrajet + ":";
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


void TrajetCompose::AjouterTrajetSimple(TrajetSimple* unTrajSimp)
{
//Algorithme: Ajouter un sous-trajet de type TrajetSimple pour fabriquer un trajet compose
//Contrat: La ville d'arrivee du sous-trajet n est la ville de depart du sous-trajet n+1 
	
	sousTrajets.AjouterElem(unTrajSimp);
}


const string TrajetCompose::Rechercher( const string&  VD, const string&  VA) const
{

// Algorithme : Parcourir la liste de sousTrajets pour verifier chaque 
// sous-trajet sa ville de depart et sa ville d'arrivee

    if((this->getVilleDepart()).compare(VD)==0 && 
	(this->getVilleArrive()).compare(VA)==0)
    {
		
		return nomDeTrajet;
    }
    else
    {    
		string res;
    	const Trajet * tmp;
    	unsigned int i = 0;
    	bool trouve = false;
    	bool potentiel = false;
		unsigned int size = sousTrajets.getSize();
		//cout << size <<endl;
    	while (i < size&&!trouve)
    	{
        	tmp=sousTrajets.AccederElem(i);
        	//cout << "check2" <<endl;
        	//On compare ville de depart et ville d'arrive chaque sous-trajet
        	res=tmp->Rechercher(VD, VA);
        	//cout << "check3" <<endl;
        	if (res.compare("VD")!=0&&res.compare("non")!=0)
        	// On a trouve la ville de dep et d'arrivee
        	{
				trouve = true;
			}
        	if (res.compare("VD")==0) 
        	{
				//cout << "check1" <<endl;
				//On a trouve la ville de depart mais pas d'arrivee, maintenant on cherche la ville d'arrivee
				potentiel = true;
				
			}
			if ((tmp->getVilleArrive()).compare(VA)==0&&potentiel) 
			{
				trouve = true;
			}
			++i;
			//cout << "check" <<endl;
			
			
		}
		if (trouve) 
		{ 
			//cout << "checktrouvevrai" <<endl;
			return nomDeTrajet;
			
		}
	
		else
		{
			//cout << "check" <<endl;
			return "non";
		}
	}
}
        	
const string& TrajetCompose::getVilleDepart() const
// Algorithme : 
//  Retourne la ville de départ du trajet composé, soit le premier élément de la liste
{
    return sousTrajets.AccederElem(0)->getVilleDepart();
}

const string& TrajetCompose::getVilleArrive() const
// Algorithme : 
//  Retourne la ville d'arrivée du trajet composé, soit la dernière ville de la liste
{
    return sousTrajets.AccederElem(sousTrajets.getSize()-1)->getVilleArrive();
}

const string& TrajetCompose::getNom() const
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
    string  nomSousTraj, vD, vA, mT;
    getline(ss,type,'-'); //On recupere le type de trajet, ici c'est C
    getline(ss,nomDeTrajet,':'); //On recupere le nom de trajet
    

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
TrajetCompose::TrajetCompose (const string&  Nom, bool activerNom): nomDeTrajet(Nom), sousTrajets()
// Algorithme :
//  Constructeur de Trajet composé qui créé une liste de trajets vides et applique le nom passé en paramètre
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de TrajetSimple


TrajetCompose::~TrajetCompose ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
	
    
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

