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
#include "Manager.h"

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
//
{

  //Lecteur l("test.log");
  //Renseignement* r = l.LireLigne ();
  //r = l.LireLigne ();
  if (argc==1)
  {
    Manager m("test.log");
    m.Execution();
  }
  else if (argc==2)
  {
    string option = argv[1];
    cout << option << endl;
    if (option == "-e"){
      Manager m("test.log",true, false);
      m.Execution();
    }
  }
  return 0;
} //----- fin de main

