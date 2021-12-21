sejours: Test.o Trajet.o TrajetSimple.o TrajetCompose.o Maillon.o ListeTrajet.o Catalogue.o
	g++ -o sejours -ansi -pedantic -Wall -std=c++11 -g Test.o Trajet.o TrajetSimple.o TrajetCompose.o Maillon.o ListeTrajet.o Catalogue.o
Test.o: Test.cpp
	g++ -c -ansi -pedantic -Wall -std=c++11 -g Test.cpp
Trajet.o: Trajet.cpp
	g++ -c -ansi -pedantic -Wall -std=c++11 -g Trajet.cpp
TrajetSimple.o: TrajetSimple.cpp
	g++ -c -ansi -pedantic -Wall -std=c++11 -g TrajetSimple.cpp
TrajetCompose.o: TrajetCompose.cpp
	g++ -c -ansi -pedantic -Wall -std=c++11 -g TrajetCompose.cpp
Maillon.o: Maillon.cpp
	g++ -c -ansi -pedantic -Wall -std=c++11 -g Maillon.cpp
ListeTrajet.o: ListeTrajet.cpp
	g++ -c -ansi -pedantic -Wall -std=c++11 -g ListeTrajet.cpp
Catalogue.o: Catalogue.cpp
	g++ -c -ansi -pedantic -Wall -std=c++11 -g Catalogue.cpp
clear:
	rm -f *.o sejours
map: Test2.o Trajet2.o TrajetSimple2.o TrajetCompose2.o Maillon2.o ListeTrajet2.o Catalogue2.o
	g++ -o sejours -ansi -pedantic -Wall -std=c++11 -DMAP -g Test.o Trajet.o TrajetSimple.o TrajetCompose.o Maillon.o ListeTrajet.o Catalogue.o
Test2.o: Test.cpp
	g++ -c -ansi -pedantic -Wall -std=c++11 -DMAP -g Test.cpp
Trajet2.o: Trajet.cpp
	g++ -c -ansi -pedantic -Wall -std=c++11 -DMAP -g Trajet.cpp
TrajetSimple2.o: TrajetSimple.cpp
	g++ -c -ansi -pedantic -Wall -std=c++11 -DMAP -g TrajetSimple.cpp
TrajetCompose2.o: TrajetCompose.cpp
	g++ -c -ansi -pedantic -Wall -std=c++11 -DMAP -g TrajetCompose.cpp
Maillon2.o: Maillon.cpp
	g++ -c -ansi -pedantic -Wall -std=c++11 -DMAP -g Maillon.cpp
ListeTrajet2.o: ListeTrajet.cpp
	g++ -c -ansi -pedantic -Wall -std=c++11 -DMAP -g ListeTrajet.cpp
Catalogue2.o: Catalogue.cpp
	g++ -c -ansi -pedantic -Wall -std=c++11 -DMAP -g Catalogue.cpp