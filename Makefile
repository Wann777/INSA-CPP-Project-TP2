main: Test.o Trajet.o TrajetSimple.o Maillon.o ListeTrajet.o Catalogue.o
	g++ -o main Test.o Trajet.o TrajetSimple.o Maillon.o ListeTrajet.o
Test.o: Test.cpp
	g++ -c Test.cpp
Trajet.o: Trajet.cpp
	g++ -c Trajet.cpp
TrajetSimple.o: TrajetSimple.cpp
	g++ -c TrajetSimple.cpp
Maillon.o: Maillon.cpp
	g++ -c Maillon.cpp
ListeTrajet.o: ListeTrajet.cpp
	g++ -c ListeTrajet.cpp
Catalogue.o: Catalogue.cpp
	g++ -c Catalogue.cpp