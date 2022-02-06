#make file - this is a comment section

modele.o: modele.cpp
	g++ -c modele.cpp

modele-test.o: modele-test.cpp
	g++ -c modele-test.cpp

2048_0.o: 2048_0.cpp
	g++ -c 2048_0.cpp

executable_modele: modele.o 2048_0.o
	g++ -o executable_modele 2048_0.o modele.o

modele: executable_modele
	./executable_modele

executable_modele-test: modele-test.o modele.o
	g++ -o executable_modele-test modele-test.o modele.o

modele-test: executable_modele-test
	./executable_modele-test





executable_niveau_2: niveau_2.o 2048_2.o
	g++ -o executable_niveau_2 niveau_2.o 2048_2.o -lncurses

niveau_2-test: niveau_2.o niveau_2-test.o
	g++ -o niveau_2-test niveau_2.o niveau_2-test.o -lncurses

niveau_2.o: niveau_2.cpp
	g++ -c -Wall niveau_2.cpp

2048_2.o: 2048_2.cpp
	g++ -c -Wall 2048_2.cpp

niveau_2-test.o: niveau_2-test.cpp
	g++ -c -Wall niveau_2-test.cpp

niveau_2: executable_niveau_2
	./executable_niveau_2


clean:
	rm -rf *.o



niveau_3.o: niveau_3.cpp
	g++ -c niveau_3.cpp

niveau_3_bis.o: niveau_3_bis.cpp
	g++ -c niveau_3_bis.cpp

2048_3.o: 2048_3.cpp
	g++ -c 2048_3.cpp

executable_niveau_3: niveau_3.o niveau_3_bis.o 2048_3.o
	g++ niveau_3.o niveau_3_bis.o 2048_3.o -o executable_niveau_3 -lsfml-graphics -lsfml-window -lsfml-system

niveau_3: executable_niveau_3
	./executable_niveau_3



