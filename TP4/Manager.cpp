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
// Verifier si un objet de type Renseignement est valide au niveau de l'extension ou l'heure de consultation
// Si oui, ajouter cet objet dans les maps pour decompter le nombre de hits et creer le fichier .dot
{
	if(optionT) 
    {
	// Si l'option -t est activee, afficher l'avertissement sur le temps du hit
		cout << "Warning : only hits between "<<heure<<"h and "<<heure+1<<"h have been taken into account"<<endl;
	}
    Renseignement* r = lec->LireLigne ();
    if (r==NULL)
	{
		cerr << "Erreur d'ouverture / lecture du fichier log." << endl;
		return;
	}
    while(r != NULL)
    {
		//On recupere l'heure pour l'option -t
		int heureLigne = std::stoi(r->getHeure());
		int decal = r->getDecalage();
		bool heureValide = ComparerHeure(decal,heureLigne);
		
		//On verifie l'extension des documents
		bool extenValide = true;
        if(optionE) //l'option e est activee
        {
            string exten = getExtension (r->getCible());//On récupere l'extension du fichier
            static unsigned int nbExten = 8;
            static string extensAJeter[] = {"css","js","png","jpg","jpeg","gif","tiff","ico"};
            for (unsigned int i = 0 ; i<nbExten && extenValide ; i++)
            {
				if (exten == extensAJeter[i])
				{
					extenValide = false;
				}
			}
			if(extenValide)
			{
                if(optionT) //1e cas de figure: -e -t
                {
				// Si l'option -t est activee, on verifie d'abord le temps du hit
				cout << "Warning : only hits between "<<heureLigne<<"h and "<<heureLigne+1<<"h have been taken into account"<<endl;
                  
                    if (heureValide)
                    {
						compt->Ajouter(r);
						if (optionG) //2e cas: -e -g -t
						//On ajoute r dans le graphe si -g est present
						{
							graph->Ajouter(r);
	
						}
						
					}
				}
				else
				{
					compt->Ajouter(r); //3e cas de figure: -e simplement
					if(optionG) //4e cas de figure: -e -g
					{
						graph->Ajouter(r);
						
					}
				}
			}//--fin de VERIFICATION DE L'EXTENSION
		}// -- fin de optionE est vraie
		else //l'option e n'est pas activee
		{
			if (optionG)
			{
				if (optionT) //5e cas de figure: -g -t
				{
					
					if (heureValide)
                    {
						graph->Ajouter(r);
						compt->Ajouter(r);
					}
				}
				else //6e cas de figure: -g simplement
				{
					
					graph->Ajouter(r);
					compt->Ajouter(r);
				}
			}
			else
			{
				if (optionT) //7e cas de figure: -t simplement
				{
					if (heureValide)
					{
						compt->Ajouter(r);
					}
				}
				else //8e cas de figure: sans option
				{
					compt->Ajouter(r);
				}
                     
              }
              
		}//- fin de l'optionE est fausse
		r = lec->LireLigne ();  //On passe a la ligne suivante
	} //-----Fin de WHILE
    if (optionG)
    {  
    	//Si l'option T est activée, on cree un fichier pour construire le graphe
		graph-> CreerFicDot();
    }
    //On fait le tri et afficher 10 hits
    compt->Trier();
	cout<<*compt;
    
    
} //----- Fin de Execution

string getExtension (const string& nomFichier)
{
//Algorithme :



	string exten;
	stringstream ss;
	ss.str(nomFichier);
	getline (ss, exten, '.');
	getline (ss, exten); //On récupere l'extension du fichier
	return exten;
}//-- Fin de fonction ordinaire getExtension
//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur



Manager::Manager (const string& nomFic)
// Algorithme :
// Constructeur par defaut
{
#ifdef MAP
    cout << "Appel au constructeur de <Manager>" << endl;
#endif
    lec = new Lecteur(nomFic);
    compt = new Compteur();
    optionE = false;
    optionT = false;
    optionG = false;
} //----- Fin de Manager

Manager::Manager (const string& nomFic, const string& nomGraphe, bool opte, bool optt, bool optg, int h) : optionE(opte), optionT(optt), optionG(optg), heure(h)
// Algorithme :
// Effectuer une lecture ligne par ligne du fichier .log
// Demarrer le decomptage du nombre de hits
// Creer un fichier .dot pour le graphe si optionG est vraie
{
#ifdef MAP
    cout << "Appel au constructeur spécifique de <Manager>" << endl;
#endif
	lec = new Lecteur(nomFic);
	compt = new Compteur(); 
	//Premier cas de figure: L'option graphe n'est pas activee
	if (!optionG)
	{
		graph = NULL;
	}
	//Deuxieme cas de figure: L'option graphe est activee
	else 
	{
		graph = new Graphe (nomGraphe);
	}
	
} //----- Fin de Manager

Manager::~Manager ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Manager>" << endl;
#endif
	delete lec;
	delete compt;
	delete graph;
	
} //----- Fin de ~Manager


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
 bool Manager::ComparerHeure (const int decalage, int heureCible)
{
	// Algorithme :
	// Comparer l'heure saisie par l'utilisateur avec celle du hit 
	// heure locale en France +0200

	if (decalage != 2)
    {
		//si decalage n'est pas +0200
		heureCible = heureCible - (decalage -2); //calculer heure actuelle en France
	}
	return heureCible == heure;
}
