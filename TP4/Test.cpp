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
  /*if (argc==1)
  {
    Manager m("test.log");
    m.Execution();
  }
  else if (argc==2)
  {
    string option = argv[1];
    //cout << option << endl;
    if (option == "-e"){
      Manager m("test.log",true, false);
      m.Execution();
    }
  }
  else if (argc==3)
  {
    string option = argv[1];
    if (option == "-t"){
      string heureString = argv[2];
      int heure = std::stoi( heureString );
      Manager m("test.log",false, true, heure);
      m.Execution();
    }
  }
  else if (argc==4)
  {
    string option1 = argv[1];
    if (option1=="-e")
  }*/
  
  bool optE=false, optT=false, optG=false;
  int heure=0;
  int i;
  for(i=1;i<argc;++i)
  {
    string option = argv[i];
    if(option == "-e")
    {
      optE=true;
    }
    else if(option == "-t")
    {
      optT=true;
      string heureString = argv[i+1];
      heure = std::stoi( heureString );
      ++i;
    }
  }
  Manager m("test.log",optE, optT, heure);
  m.Execution();
  return 0;
} //----- fin de main

