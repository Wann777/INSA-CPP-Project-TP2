analog: Test.o Renseignement.o Lecteur.o Manager.o Compteur.o
	g++ -o analog -ansi -pedantic -Wall -std=c++11 -g Test.o Renseignement.o Lecteur.o Manager.o Compteur.o
Test.o: Test.cpp
	g++ -c -ansi -pedantic -Wall -std=c++11 -g Test.cpp
Renseignement.o: Renseignement.cpp
	g++ -c -ansi -pedantic -Wall -std=c++11 -g Renseignement.cpp
Lecteur.o: Lecteur.cpp
	g++ -c -ansi -pedantic -Wall -std=c++11 -g Lecteur.cpp
Manager.o: Manager.cpp
	g++ -c -ansi -pedantic -Wall -std=c++11 -g Manager.cpp
Compteur.o: Compteur.cpp
	g++ -c -ansi -pedantic -Wall -std=c++11 -g Compteur.cpp
clear:
	rm -f *.o analog

