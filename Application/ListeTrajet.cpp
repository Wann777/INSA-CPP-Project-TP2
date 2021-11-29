/*************************************************************************
                           ListeTrajet  -  description
                             -------------------
    début                : $15/11/2021$
    copyright            : (C) $2021$ par $tdang,esoulier$
    e-mail               : $thanh.dang@insa-lyon.fr, erwan.soulier@insa-lyon.fr$
*************************************************************************/


//---------- Réalisation de la classe <ListeTrajet> (fichier ListeTrajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
//------------------------------------------------------ Include personnel
#include "ListeTrajet.h"


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void ListeTrajet::AjouterElem (Trajet* unTrajet)
// Algorithme :
// Allocation mémoire d'un nouveau maillon et copie en profondeur d'unTrajet
// Insertion en fin de liste
{
	//Allocation de memoire
	Maillon *nouveauMaill = new Maillon();
	nouveauMaill->setSuivNull();
	//copie en profondeur
	nouveauMaill->setTrajet(unTrajet);

	//Insertion en fin de la liste
	if (racine == NULL) //la liste est vide
	{
		racine = nouveauMaill;
	}
	else
	{
		Maillon * tmp = racine;
		while(tmp->getSuiv())
		{
			//Parcourir jusqu'a la fin de la liste
			tmp=tmp->getSuiv();
		}
		tmp->setSuiv(nouveauMaill);
	}
	//else
	//{
		//nouveauMaill->setSuiv(racine);
		//racine = nouveauMaill;
	//}
	
	++taille;
}	//---Fin de methode AjouterElem

void ListeTrajet::AjouterElemAlpha (Trajet* unTrajet)
{
// Algorithme :
// Allocation mémoire d'un nouveau maillon et copie en profondeur d'unTrajet
// Chercher la position dans la liste ou on peut inserer le nouvel element
// Insertion en position

	//Allocation de memoire
        Maillon *nouveauMaill = new Maillon();
        nouveauMaill->setSuivNull();
        //copie en profondeur
        nouveauMaill->setTrajet(unTrajet);

        //Premier cas de figure: la liste est vide
        if (racine == NULL)
        {
                racine = nouveauMaill;
        }
	else
	{
		//2e cas de figure: l'insertion en début de liste
		if (Comparer(nouveauMaill->getTrajet(),racine->getTrajet())==-1)
		{
			nouveauMaill->setSuiv(racine);
			racine = nouveauMaill;
		}
		//3e cas de figure: l'insertion en milieu ou en fin de liste
		else
		{
			Maillon* courant = racine;
			Maillon* suivant = courant->getSuiv();
			while (suivant!=NULL)
			{
				if (Comparer(nouveauMaill->getTrajet(),suivant->getTrajet())==1)
				{
					courant = suivant;
					suivant = courant->getSuiv();
				}
				else 
				{
					nouveauMaill->setSuiv(suivant);
					courant->setSuiv(nouveauMaill);
					++taille;
					return;
				}

			}
			// On est arrive a la fin de liste
			nouveauMaill->setSuivNull();
			courant->setSuiv(nouveauMaill);
		}
	}
	++taille;

}				


const Trajet* ListeTrajet::AccederElem (unsigned int pos) const
{
	if (pos>=taille)
	{ 
		return 0; //position est invalide
	}
	else
	{
		Maillon* courant = racine;
		unsigned int posCour= 0;
		while (courant->getSuiv() && posCour<pos)
		{
			courant = courant->getSuiv();
			posCour++;
		}	
		return courant->getTrajet();
	}
} //--Fin de methode AccederElem


unsigned int ListeTrajet::getSize () const
{
	return taille;
}



//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
ListeTrajet::ListeTrajet(): racine (0),taille(0)
{
// Constructeur par defaut
#ifdef MAP
    cout << "Appel au constructeur de <ListeTrajet>" << endl;
#endif
}//--Fin de ListeTrajet

/*ListeTrajet::ListeTrajet (const ListeTrajet & uneListe): racine(NULL),taille(0)
// Algorithme :Constructeur de copie 
// Copie en prof tous les elements d'uneListe
{
#ifdef MAP
    cout << "Appel au constructeur de <ListeTrajet>" << endl;
#endif 
    for (unsigned int i = 0;i<uneListe.taille;i++)
	{
	    AjouterElem(uneListe.AccederElem(i));
	} //----- Fin de ListeTrajet (const ListeTrajet & uneListe)
}
*/
ListeTrajet::~ListeTrajet ()
// Algorithme :	Parcourir la liste pour liberer la zone de memoire allouee par 
// chaque maillon
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ListeTrajet>" << endl;
#endif
    Maillon* courant = racine;
    while(courant)
    {
        delete courant->getTrajet();
        Maillon* suivant = courant->getSuiv();
        delete courant;
        courant = suivant;
    }
    delete courant;
   
} //----- Fin de ~ListeTrajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
int ListeTrajet::Comparer ( Trajet* t1, Trajet* t2) const
{
// Algorithme :
// Compare la ville de dep et d'arrivee de 2 trajets t1 et t2
// retourne 0 si t1 et t2 ont les memes villes
// -1 si t1 est plus petit que t2 dans l'ordre lexicographique, ex Bordeaux et Lyon
// 1 si t1 est plus grand que t2 dans l'ordre lexicographique, ex Paris et Lyon
// Note:  si t1 et t2 sont les trajets composes, on compare
// la ville de depart du premier sous trajet
// et la ville d'arrivee du dernier sous trajet
	int compareDep = strcmp(t1->getVilleDepart(),t2->getVilleDepart());
	if (compareDep < 0) return -1;
	if (compareDep >0) return 1;
	else
	{
		int compareArriv = strcmp(t1->getVilleArrive(),t2->getVilleArrive());
		if (compareArriv < 0) return -1;
	        if (compareArriv >0) return 1;
		else return 0;
	}
}


