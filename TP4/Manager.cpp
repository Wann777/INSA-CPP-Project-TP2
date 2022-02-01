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
                    int heureLigne = std::stoi(r->getHeure());
                    if (heure==heureLigne)
                    {
						if (optionG) //2e cas: -e -g -t
						//On construit le graphe si -g est present
						{
							graph->Ajouter(r);
							compt->Ajouter(r);
						}
						else 
						{
							//Sinon, on fait un decompte normal
							compt->Ajouter(r);
						}
					}
				}
				else
				{
					if(optionG) //3e cas de figure: -e -g
					{
						graph->Ajouter(r);
						compt->Ajouter(r);
						
					}
					else //4e cas de figure: -e simplement
					{
						compt->Ajouter(r);
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
					int heureLigne = std::stoi(r->getHeure());
                    if (heure==heureLigne)
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
					int heureLigne = std::stoi(r->getHeure());
					if (heure==heureLigne)
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
	compt->Afficher();
    
    
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
//
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
//
{
#ifdef MAP
    cout << "Appel au constructeur spécifique de <Manager>" << endl;
#endif
	lec = new Lecteur(nomFic);
	//Premier cas de figure: L'option graphe n'est pas activee
	if (!optionG)
	{
		
		compt = new Compteur();
		graph = NULL;
	}
	//Deuxieme cas de figure: L'option graphe est activee
	else 
	{
		compt = new Compteur();
		//compt = NULL;
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

