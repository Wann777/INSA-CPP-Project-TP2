sejours: Test.o Renseignement.o Lecteur.o
	g++ -o analog -ansi -pedantic -Wall -std=c++11 -g Test.o Renseignement.o Lecteur.o
Test.o: Test.cpp
	g++ -c -ansi -pedantic -Wall -std=c++11 -g Test.cpp
Renseignement.o: Renseignement.cpp
	g++ -c -ansi -pedantic -Wall -std=c++11 -g Renseignement.cpp
Lecteur.o: Lecteur.cpp
	g++ -c -ansi -pedantic -Wall -std=c++11 -g Lecteur.cpp

clear:
	rm -f *.o analog

