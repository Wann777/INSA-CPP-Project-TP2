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
#include <fstream>
#include <string>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "ListeTrajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Filtre.h"
#include "FiltreSans.h"
#include "FiltreType.h"
#include "FiltreVille.h"
#include "FiltreInter.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC


//----------------------------------------------------- Méthodes publiques
void Catalogue::Menu()
// Algorithme :
//Proposer des services differents aux utilisateurs
{
	string input ;
	do 
	{
		cout<<endl;
		cout << "==================== MENU ====================" << endl;
        	cout << "Choisir un service: " << endl;
        	cout << "0 : Afficher les trajets disponibles" << endl;
       		cout << "1 : Rechercher des trajets" << endl;
			cout << "2 : Ajouter un nouveau trajet simple" << endl;
        	cout << "3 : Ajouter un nouveau trajet compose" << endl;
        	cout << "4 : Charger le contenu d'un fichier" << endl;
        	cout << "5 : Sauvegarder le catalogue actuel dans un fichier" << endl;
        	cout << "6 : Quitter l'application" << endl;
        	cout << "==============================================" << endl;
        	do {
				input = VerifierChaine();
			}
			while (input.size()!=1);
        	switch (input[0])
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
                	Charger();
                	break;
                case '5':
                	Sauvegarder();
                	break;
            	case '6':
                	cout << "Au revoir..." << endl;
                	break;
            	default:
                cout << "Choix invalide. Choisir l'une des valeurs entre 0 et 6" << endl;
        	}
    	} while (input[0]!='6');
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
	cout << "Donnez une ville de depart : "<<endl;
	string VD = VerifierChaine();
	cout <<"Donnez une ville d'arrivee : "<<endl;
	string VA = VerifierChaine();
	cout <<"Donnez un moyen de transport : "<<endl;
	string MT = VerifierChaine();
	cout <<"Donnez un nom de trajet : "<<endl;
	string Nom = VerifierChaine();
	TrajetSimple *unNouvSimp = new TrajetSimple(VD,VA,MT,Nom);
	ListeT.AjouterElemAlpha(unNouvSimp);
	cout<< "Le trajet simple nomme "<< Nom << " a ete ajoute au catalogue. " <<endl;

}

void Catalogue::AjouterTrajetCompose()
// Algorithme :
// Ajoute un trajet composé dans la liste des trajets
{
	cout <<"Donnez le nom du trajet compose : " <<endl;
    string Nom = VerifierChaine();
    TrajetCompose *nouvelTrajComp = new TrajetCompose(Nom,true);
    cout << "Veuillez ajouter au moins deux  sous-trajets ! " << endl;
    string etapePre;
    string etapeSui;
    string MT;
    string NomST;
    cout << "Donnez une ville de depart : "<<endl;
    etapePre = VerifierChaine ();
    cout << "Donnez une ville d'escale : "<<endl;
    etapeSui = VerifierChaine ();
    do
    {
		cout <<"Donnez un moyen de transport : "<<endl;
		MT = VerifierChaine ();
		cout <<"Donnez un nom de trajet : "<<endl;
        NomST = VerifierChaine ();
		TrajetSimple* unNouvST = new TrajetSimple(etapePre,etapeSui,MT,NomST);
		nouvelTrajComp->AjouterTrajetSimple(unNouvST);
		etapePre = etapeSui;
		cout <<"Donnez une ville d'escale (ou tapez 0 pour terminer ce trajet) : "<<endl;
		etapeSui= VerifierChaine();
    }
    while (etapeSui != "0");
    ListeT.AjouterElemAlpha(nouvelTrajComp);
    cout<< "Le trajet compose nomme "<< Nom << " a ete ajoute au catalogue. " <<endl;
}

void Catalogue::Rechercher() const
// Algorithme :
// Permet de rechercher un trajet à partir d'une ville de départ et d'arrivé donnée par l'utilisateur
{
	cout << "Donnez une ville de depart a chercher: "<<endl;
     string VD = VerifierChaine();
     cout << "Donnez une ville d'arrivee a chercher : "<<endl;
     string VA = VerifierChaine();
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

void Catalogue::Charger ( )
// Algorithme :
// Etape 1: Le nom du fichier a charger donne par l'utilisateur
// Vérifie si ce fichier existe et est non vide 
// Etape 2: Le filtre de sélection des trajets choisi par l'utilisateur
// à charger dans le fichier.
// Etape 3: Créer dynamiquement le filtre choisi
// Etape 4: Chercher des trajets conformes en parcourant toute la ligne du fichier 
// Etape 5: Ajouter ces trajets dans le Catalogue courant
{
    string nomFic;
    // Etape 1: Verification du nom de fichier donne par l'utilisateur
    bool unFicValide;
    do
    {
        unFicValide = true;
        cout << "Donnez un nom de fichier a charger (mettez un nom vide dans le cas d'annulation de chargement): "<<endl;
        nomFic = VerifierChaine(true);
        if(nomFic.empty())
        {
            cout << "Le chargement a ete annulee !" << endl;
            return;
        }
        
        size_t found = nomFic.find("/");
        
        if(found != string::npos)
        {
			
            cout << "Nom de fichier ne peut pas contenir / !" << endl;
            unFicValide = false;
        }
        
        ifstream ifsNomFic (nomFic.c_str());
        if (!ifsNomFic) 
		{
			cout << "Le fichier nomme " << nomFic << " n'existe pas ! "<<endl;
			unFicValide = false;
		}
		else if (ifsNomFic.peek()==EOF)
		{
			cout << "Le fichier nomme " << nomFic << " est vide ! "<<endl;
			unFicValide = false;
		}
		ifsNomFic.close();	  
    }
    while(!unFicValide);

   
    // Etape 2: Préciser le filtre utilisé lors de la sauvegarde des trajets
    // Etape 3: Créer dynamiquement le filtre choisi
    
    Filtre *unPtrFil = NULL;
    ChoisirFiltre (unPtrFil, nomFic);
    
	// Etape 4: Chercher des trajets conformes en parcourant toute la ligne du fichier

    
    ifstream ifsNomFic(nomFic.c_str()); //ouvrir le fichier nomme nomFic en lecture
    unsigned int nomTrajChar = 0;
    if(ifsNomFic.is_open())
    {
		//Lecture de chaque ligne du fichier
		string unDesTraj;
		while (getline(ifsNomFic, unDesTraj))
		{
			Trajet* unPtrTraj = NULL;
			//si c'est une ligne qui décrit un trajet simple
			if (unDesTraj.size()!=0 && unDesTraj[0]=='S')
			{
				
				unPtrTraj = new TrajetSimple (unDesTraj);
				
			}
			
			if (unDesTraj.size()!=0 && unDesTraj[0]=='C')
			{
				unPtrTraj = new TrajetCompose (unDesTraj);
				
			}
			
            if(unPtrTraj !=NULL && unPtrFil->Valide(*unPtrTraj)) 
            {
                ListeT.AjouterElemAlpha(unPtrTraj); //Ajout dans la liste des trajets
                ++nomTrajChar;
                 cout << "Le trajet ayant la description " << unDesTraj << " a ete charge dans le Catalogue ! " << endl;
            }
            //delete unPtrTraj;
        }
        ifsNomFic.close();
        cout << nomTrajChar <<" trajet" << (nomTrajChar > 1 ?"s ont ete sauvegardes dans le Catalogue." :" a ete sauvegarde dans le Catalogue.") << endl;
    }
    else
    {
        cout << "La lecture de ce fichier n'est pas autorisee !"<< endl;
    }
    delete unPtrFil;
}


void Catalogue::Sauvegarder ( ) const
// Algorithme :
// Etape 1: Le nom du fichier de sauvegarde donne par l'utilisateur
// Si on a déjà ce fichier, demande à l'utilisateur à choisir l'écraser  
// ou ajouter la sauvegarde des trajets à la fin du fichier.
// Etape 2: Le filtre de sélection des trajets choisi par l'utilisateur
// à sauvegarder dans le fichier.
// Etape 3: Créer dynamiquement le filtre choisi
// Etape 4: Chercher des trajets conformes en parcourant tout le catalogue et 
// Etape 5: Ajouter ces trajets dans le fichier
{
	unsigned int nbTraj = ListeT.getSize();
	if(nbTraj==0)
    {
        cout << "Le catalogue actuel ne contient aucun trajet à sauvegarder !" << endl;
        return;
    }
    string nomFic;
    // Etape 1: Verification du nom de fichier donne par l'utilisateur
    bool unFicValide;
    do
    {
        unFicValide = true;
        cout << "Donnez un nom de fichier a sauvegarder (mettez un nom vide dans le cas d'annulation de sauvegarde): "<<endl;
        nomFic = VerifierChaine(true);
        if(nomFic.empty())
        //
        {
            cout << "La sauvegarde a ete annulee !" << endl;
            return;
        }
        size_t found = nomFic.find("/");
        
        if(found != string::npos)
        {
			
            cout << "Nom de fichier ne peut pas contenir / !" << endl;
            unFicValide = false;
        }
    }
    while(!unFicValide);

    // Un cas particulier: le fichier existe deja
    ifstream ifsNomFic(nomFic.c_str());
    ios_base::openmode mode = ios_base::out;
    if(ifsNomFic)
    {
        ifsNomFic.close();
        bool modeValide;
       
        do
        {
            modeValide = true;
            cout << "Ce fichier existe deja. Veuillez choisir une operation" << endl;
            cout << "0 : Ajouter des donnees dans un nouveau fichier en revenant au menu principal" << endl;
            cout << "1 : Effacer le contenu actuel du fichier" << endl;
            cout << "2 : Ajouter des donnees a la fin du fichier" << endl;
            cout << "==============================================" << endl;
          
             string input;
             do
             {
				input = VerifierChaine();
			 } 
			 while (input.size()!=1);
        	switch (input[0])
        	{	
            	case '0':
                	return;
                	break;
            	case '1':
                	mode = ios_base::trunc;
                	break;
            	case '2':
					mode = ios_base::app;
                	break;
            	default:
            	modeValide = false;
                cout << "Choix invalide. Choisir l'une des valeurs entre 0 et 2" << endl;
        	}
        }
        while(!modeValide);
    }

    // Etape 2: Préciser le filtre utilisé lors de la sauvegarde des trajets
    // Etape 3: Créer dynamiquement le filtre choisi
    
     Filtre *unPtrFil = NULL;
    ChoisirFiltre (unPtrFil);
    
	// Etape 4: Chercher des trajets conformes en parcourant tout le catalogue

    
    ofstream ofsNomFic(nomFic.c_str(), mode); //ouvrir le fichier nomme nomFic en ecriture
    unsigned int nomTrajSauv = 0;
    if(ofsNomFic.is_open())
    {
       
        // Parcours des trajets du Catalogue
        for(unsigned int i=0; i<nbTraj; ++i)
        {
            // Etape 5: Ajouter ces trajets dans le fichier
            const Trajet* t = ListeT.AccederElem(i);
            if(unPtrFil->Valide(*t))
            {
                ofsNomFic<<t->getDescription()<<endl;
                if(ofsNomFic.good())
                {
                    ++nomTrajSauv;
                    cout << "Le trajet ayant la description " <<t->getDescription() << " a ete sauvegarde dans le fichier ! " << endl;
                }
                else
                {
                    cout << "Une erreur s'est produite :( " << endl;
                }
            }
        }
        ofsNomFic.close();
        cout << nomTrajSauv <<" trajet" << (nomTrajSauv > 1 ?"s ont ete sauvegardes dans le Catalogue." :" a ete sauvegarde dans le Catalogue.") << endl;
    }
    else
    {
        cout << "L'ecriture de ce fichier n'est pas autorisee !"<< endl;
    }
    delete unPtrFil;
}


string Catalogue::VerifierChaine(bool autoriseVide) const
// Algorithme :
// Verifie si une chaine de caractères d'entrée est valide
{
    bool bonneSaisie;
    string chaine;
    do
    {	
		bonneSaisie = true;
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
} //----- Fin de VerifierChaine

unsigned int Catalogue::VerifierEntier() const
// Algorithme :
// Verifie si un entier positif d'entrée est valide
{
    bool bonneSaisie;
    int ent;
    do
    {	
		bonneSaisie = true;
        cin >> ent;
        if(cin.eof())
	//premier cas de figure: on est a la fin du fichier (EOF)
        {
            cout << endl << "La fin du flux est atteinte. Veuillez saisir un nouvel entier  !" << endl;
            cin.clear();
            bonneSaisie = false;
        }
        else if(ent<0)
        {
	//deuxieme cas de figure: l'entier est negatif
            cout << "Veuillez saisir un entier positif !" << endl;
            bonneSaisie = false;
        }
		else if(cin.fail())
        {
	//troisieme cas de figure: l'entree n'est pas de type string
            cout << endl << "Lecture invalide. Veuillez saisir un nouvel entier !" << endl;
            cin.clear();
            bonneSaisie = false;
        }
        cin.ignore(); //Extrait des caractères du flux d’entrée et les ignore
    }
    while(!bonneSaisie);
    return (unsigned int)ent;
} //----- Fin de VerifierChaine

void Catalogue::ChoisirFiltre (Filtre*& unPtrFiltre, string nomFicACharger) const
{
// Algorithme :
// Demande de l'utilisateur de choisir un type de filtre et puis l'instancie dynamiquement
	unsigned int m,n,nbTraj; //pour le filtre d'intervalle
	if (nomFicACharger == " ") 
	{
		nbTraj = ListeT.getSize(); //le cas de sauvegarde
	}
	else 
	{
		nbTraj = CompterLignes(nomFicACharger);// le cas de chargement
	}
    bool filValide;
    string input;
    do
    {
		filValide = true;
        cout << "Veuillez choisir un type de filtres :" << endl;
		cout << "0 : Filtre sans criteres - Sauvegarder tous les trajets" << endl;
		cout << "1 : Filtre selon le type des trajets" << endl;
		cout << "2 : Filtre selon la ville de depart et/ou d'arrivee" << endl;
		cout << "3 : Filtre selon une selection de trajets" << endl;
        cout << "==============================================" << endl;
        do
        {
			input = VerifierChaine();
		} 
		while (input.size()!=1);
        switch (input[0])
        {	
			case '0':
              	unPtrFiltre = new FiltreSans;
				break;
            case '1':
            {
                	cout << "Veuillez choisir le type des trajets a filtrer :" << endl;
					cout << "0 : Sauvegarder les trajets simples (par defaut)" << endl;
					cout << "1 : Sauvegarder les trajets composes" << endl;
					string typeFil;
					cin >> typeFil;
					if (typeFil == "1")
					{
						unPtrFiltre = new FiltreType (true);
					}
					else unPtrFiltre = new FiltreType ();
                	break;
            }
            case '2':
            {
                	cout << "Veuillez donner une ville de depart et/ou une ville d'arrivee a filtrer :" << endl;
                	cout << "Ville de depart (ou 0 pour filtrer aucune ville): "<<endl;
					string depart = VerifierChaine();
					cout << "Ville d'arrivee (ou 0 pour filtrer aucune ville): "<<endl;
					string arrivee = VerifierChaine();
					unPtrFiltre = new FiltreVille(depart,arrivee);
                	break;
            }
			case '3':
			{
				bool bonneSaisie;
					cout << "Veuillez selectionner un intervalle de trajets dans le catalogue :" << endl;
					cout << "Entrez deux entiers positifs entre 0 et " << nbTraj-1 << endl;
					do
					{
						bonneSaisie = true;
						cout<< "Borne inferieure : " <<endl;
						n = VerifierEntier();
						cout<< "Borne superieure : " <<endl;
						m = VerifierEntier();
						if(n > m || n >= nbTraj)
						{
							cout << "Attention : l'intervalle [" << n << ";" << m << "] est invalide!" << endl;
							bonneSaisie = false;
						}
					}
					while (!bonneSaisie);
					unPtrFiltre = new FiltreInter(n, m);
					break;
			}
            default:
            {
					filValide = false;
					cout << "Choix invalide. Choisir l'une des valeurs entre 0 et 3" << endl;
			}
        }
      
    }
    while(!filValide);
}

unsigned int Catalogue::CompterLignes(string const& nomFic) const
// Algorithme :
// Service qui permet d'ouvrir le fichier en lecture et compte le nombre de lignes du fichier
// Tant que l'état du flux n'est pas eof, il reste des lignes à lire.
{
    unsigned int compte = 0;
    ifstream fichier(nomFic.c_str());
    if(fichier.is_open())
    {
        string uneLigne;
        while(getline(fichier, uneLigne))
        {
            ++compte;
        }
    }
    fichier.close();
    return compte;
} //----- Fin de compterLignes
