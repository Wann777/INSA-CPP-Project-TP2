sejours: Test.o Trajet.o TrajetSimple.o TrajetCompose.o Maillon.o ListeTrajet.o Catalogue.o
	g++ -o sejours -ansi -pedantic -Wall -std=c++11 -DMAP -g Test.o Trajet.o TrajetSimple.o TrajetCompose.o Maillon.o ListeTrajet.o Catalogue.o
Test.o: Test.cpp
	g++ -c -ansi -pedantic -Wall -std=c++11 -DMAP -g Test.cpp
Trajet.o: Trajet.cpp
	g++ -c -ansi -pedantic -Wall -std=c++11 -DMAP -g Trajet.cpp
TrajetSimple.o: TrajetSimple.cpp
	g++ -c -ansi -pedantic -Wall -std=c++11 -DMAP -g TrajetSimple.cpp
TrajetCompose.o: TrajetCompose.cpp
	g++ -c -ansi -pedantic -Wall -std=c++11 -DMAP -g TrajetCompose.cpp
Maillon.o: Maillon.cpp
	g++ -c -ansi -pedantic -Wall -std=c++11 -DMAP -g Maillon.cpp
ListeTrajet.o: ListeTrajet.cpp
	g++ -c -ansi -pedantic -Wall -std=c++11 -DMAP -g ListeTrajet.cpp
Catalogue.o: Catalogue.cpp
	g++ -c -ansi -pedantic -Wall -std=c++11 -DMAP -g Catalogue.cpp
clear:
	rm -f *.o sejours
