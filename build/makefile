# Variables
TIME =$(LOGPATH)$(shell date)
# Object Vars
OBJECTS = main.o vocabulary.o preProcesser.o Chrono.o token.o
# Compilation flags
CFLAGS = -c -std=c++17 -Wall

textClassifier: $(OBJECTS)
	g++ $(OBJECTS) -o textClassifier
	mv textClassifier ../bin

main.o: ../src/main.cpp
	g++ $(CFLAGS) ../src/main.cpp

vocabulary.o: ../src/vocabulary.cpp ../include/vocabulary.hpp
	g++ $(CFLAGS) ../src/vocabulary.cpp

preProcesser.o: ../src/preProcesser.cpp ../include/preProcesser.hpp
	g++ $(CFLAGS) ../src/preProcesser.cpp

Chrono.o: ../src/Chrono.cpp ../include/Chrono.hpp
	g++ $(CFLAGS) ../src/Chrono.cpp

token.o: ../src/token.cpp ../include/token.hpp
	g++ $(CFLAGS) ../src/token.cpp


.PHONY: clean
clean:
	rm -rf ../build/*.o
	rm -rf ../bin/*

help:
	../bin/textClassifier --help

fullRun:
	make clean
	make
	make runVocabulary


runVocabulary:
	../bin/textClassifier --vocabulary ../inputs/COV_train.csv ../outputs/vocabulary.txt ../inputs/stopWords.txt
