/*************************************************************************
                           Test -  description
                             -------------------
    début                : $10/01/2022$
    copyright            : (C) $2021$ par $tdang,esoulier$
    e-mail               : $thanh.dang@insa-lyon.fr, erwan.soulier@insa-lyon.fr$
*************************************************************************/

//---------- Réalisation du module <Test> (fichier Test.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Test.h"
#include <string>
#include <iostream>
#include "Manager.h"
#include <sstream>

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées
//static type nom ( liste de paramètres )
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
//{
//} //----- fin de nom

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
int main (int argc, char *argv[])
// Algorithme :
// Faire la lecture de commande saisie par l'ultisateur 
{  
	bool optE=false, optT=false, optG=false, argValide = true;
	string nomGraphe,nomFicLog;
	string dernierArg = argv[argc - 1];
	int heure=0;
	int i;
	/*
	// Premiere verification: le fichier donne est l'un de type .log
	if (!dernierArg.empty())
	{
		//On récupere l'extension du fichier et verifie si c'est un .dot
		string exten = getExtension (dernierArg);
		if (exten != "log")
		{
			cerr<< "Nom de fichier log non valide !" << endl;
			argValide = false;
		}
		else 
		{
			nomFicLog = argv[argc-1];
		}
		
	}//--Fin de verification du nom de fichier .log
	*/
	if (argc == 1)
	{
		//Si la chaine est vide
		argValide = false;
		cerr << "Aucun argument saisi !" <<endl;
	} //-- Fin de verification d'argument vide

	if(dernierArg == "-e" || dernierArg == "-g" || dernierArg == "-t")
	{
		//1e contrainte: -g, -e, -t ne peuvent pas se situer a la fin de ligne
		argValide = false;
		cerr << "Placement du fichier log invalide !" << endl;
	}
		
	// On fait un parcours du tableau des arguments
	for(i=1;i<argc && argValide;++i)
	{
		string option = argv[i];
		if (option.empty())
		{
			//Si la chaine est vide
			argValide = false;
			cerr << "Argument saisi non valide !" <<endl;
		} //-- Fin de verification d'argument vide
		else
		{
			if (i == argc - 1 && option != "-e" && option != "-g" && option != "-t")
			{
				//On récupere l'extension du fichier et verifie si c'est un .dot
				string exten = getExtension (dernierArg);
				if (exten != "log")
				{
					cerr<< "Nom de fichier log non valide !" << endl;
					argValide = false;
				}
				else 
				{
					nomFicLog = argv[argc-1];
				}
			}
			else
			{
				if (option == "-g")
				{
					optG = true;
					string exten = getExtension(argv[i+1]);
					//On récupere l'extension du fichier et verifie si c'est un .dot
					if (exten != "dot")
					{
						cerr<< "Nom de fichier pour le graphe non valide !" << endl;
						argValide = false;
					}
					else 
					{
						//On recupere le nom du graphe
						nomGraphe = argv[i+1];
					}
					++i;
				} //-- Fin de l'option -g
				else if (option == "-e")
				{
					optE = true;
				}
				else if (option == "-t")
				{
					optT = true;
					// On recupere l'heure en parametre pour construire un intervalle
					string heureString = argv[i+1];
					heure = std::atoi( argv[i+1] );
					if (heure < 0 || heure > 24 || (heure==0 && heureString != "0"))
					{
						cerr<< "Heure pour l'option -t non valide !" << endl;
						argValide = false;
					}
					++i;
				} //-- Fin de l'option -t
				else
				{
					cerr<< "Option non reconnue, fin du programme." << endl;
					argValide = false;
				}
			}//-- Fin de else quand -g -e -t sont au milieu 
		}//-- Fin de else quand argv[i] est non vide
	} //-- Fin de la boucle for
	if (!argValide)
	{
		cerr<< "Lecture de commande echouee !" <<endl;
	}
	else
	{
		Manager m(nomFicLog,nomGraphe,optE, optT, optG, heure);
		m.Execution();
	}
    return 0;
}//-- Fin de MAIN


