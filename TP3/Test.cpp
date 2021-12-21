/*************************************************************************
                           Test  -  description
                             -------------------
    début                : $15/11/2021$
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
#include "TrajetCompose.h"
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
int main ()
// Algorithme :
//
{
  string s = "S-TS1:Lyon,Bordeaux,Train,";
  TrajetSimple t1(s);
 // t1.Afficher();
 std::cout<< t1.getDescription()<<endl; 
  string c = "C-TC2:TS2-1:Lyon,Bordeaux,Train,TS2-2:Toulouse,TGV,TS2-3:Nice,TER,";
  TrajetCompose t2(c);
  std::cout<< t2.getDescription()<<endl;  
 // t1.Afficher();
 t2.Afficher();
 // Catalogue c;
 // c.Menu();
  return 0;
} //----- fin de main

