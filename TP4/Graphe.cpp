/*************************************************************************
                           Graphe  -  description
                            -------------------
    début                : $10/01/2022$
    copyright            : (C) $2022$ par $tdang,esoulier$
    e-mail               : $thanh.dang@insa-lyon.fr, erwan.soulier@insa-lyon.fr$
*************************************************************************/

//---------- Réalisation de la classe <Graphe> (fichier Graphe.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>
#include <string>

//------------------------------------------------------ Include personnel
#include "Graphe.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Compteur::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
void Graphe::Ajouter(Renseignement * r)
{
// Algorithme :
//
//




	// Etape 1: Ajouter la cible et le referer dans la liste de Noeuds
	// le set nous aide a supprimer les doublons
	
	string cle = r->getCible();
	string refAChercher = r->getReferer();
	listeN.insert(cle);
	listeN.insert(refAChercher);
	refMap secondElem; // il s'agit de la structure map<string,int>
	
	//Etape 2: Ajouter le renseignement r dans la structure de donnees Tgraphe
	Tgraphe::iterator cleTrouvee;
	refMap::iterator estPresent;
	cleTrouvee = logGraphe.find(cle);  //On cherche la cle dans la map
    if(cleTrouvee == logGraphe.end())
    {
		//1e cas de figure: La cle n'est pas encore presente, on l'ajoute
		string ref = r->getReferer();
		secondElem.insert(make_pair(ref,1));
		logGraphe.insert(make_pair(cle,secondElem));
		
		
		
    }
    else 
    {
		//2e cas de figure: La cle est deja dans la map
		//On doit verifier si le couple cible - referer est deja present
		
		secondElem = cleTrouvee->second;
		estPresent = secondElem.find(refAChercher);
		if (estPresent == secondElem.end())
		{
			//Si le referer n'est pas encore dans la map refMap, on insere le couple (ref,1)
			(cleTrouvee->second).insert(make_pair(refAChercher,1));
			
		}
		else 
		{
			//Si le referer est deja dans la map refMap, on augmente le nb d'occurences par 1
			++((cleTrouvee->second).find(refAChercher)-> second); //ca marche!
			//++(estPresent->second); ca ne marche pas
		}
	}
		
}

void Graphe::CreerFicDot()
{
// Algorithme :
//
//



	// Etape 1: Verification du fichier de l'entree
	if (nomFicDot.empty())
	{
		cerr<< "Nom de fichier est vide ! "<<endl;
		return;
	}
	else
	{
		// Un cas particulier: le fichier existe deja
		ifstream ifsNomFic(nomFicDot.c_str());
		ios_base::openmode mode = ios_base::out;
		if(ifsNomFic)
		{
			ifsNomFic.close();
			mode = ios_base::trunc; //Effacer le contenu actuel du fichier
		}
		ofstream ofsNomFic(nomFicDot.c_str(), mode); 
		// Etape 2: Ouvrir le fichier nomme nomFic en ecriture
		if(ofsNomFic.is_open())
		{
			ofsNomFic<< "digraph {" <<endl;
			int indice = 0;
			//Etape 3: Ecrire la description des noeuds du graphe
			for (Tnoeud::iterator it = listeN.begin(); it != listeN.end(); it ++)
			{
				ofsNomFic << "node"<< indice << " [label = \"" << *it << "\"];" << endl;
				++indice;
			}
			
			// Etape 4: Ecrire les liens entre noeuds
			for (Tgraphe::iterator it = logGraphe.begin(); it != logGraphe.end(); it ++)
			{
				string destination = it-> first;
				//cout<<destination<<endl;
				//On cherche la cible dans la liste des noeuds
				Tnoeud::iterator posDes = listeN.find(destination);
				int indDes = distance(listeN.begin(), posDes);
				for (refMap::iterator itbis = it->second.begin(); itbis != it->second.end(); itbis ++)
				{
					string source = itbis->first;
					Tnoeud::iterator posSource = listeN.find(source);
					int indS = distance(listeN.begin(), posSource);
					int nbHits = itbis ->second;
					//cout<< "node"<< indS << " -> node" << indDes << " [label=\"" << nbHits << "\"];" << endl;
					ofsNomFic << "node"<< indS << " -> node" << indDes << " [label=\"" << nbHits << "\"];" << endl;
				}// ---Fin de la creation des liens entre noeuds
			}
			ofsNomFic << "}" <<endl;
			cout << "Dot-File " << nomFicDot << " generated" << endl;
		}
	}
		
}//---Fin de CreerFic



//------------------------------------------------- Surcharge d'opérateurs
/*Graphe & Graphe::operator = ( const Graphe & unGraphe )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Graphe::Graphe ( const Graphe & unGraphe )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Graphe>" << endl;
#endif
} //----- Fin de Graphe (constructeur de copie)
*/

Graphe::Graphe (const string& nomGraphe) : nomFicDot(nomGraphe)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Graphe>" << endl;
#endif
} //----- Fin de Graphe


Graphe::~Graphe ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Graphe>" << endl;
#endif
} //----- Fin de ~Graphe


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

