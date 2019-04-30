.PHONY: clean data test resultat valgrind

TARGET = tp3
OBJECTS = tp3.o
OUTILS = outils
STRUCTURE = structure
CODE = code.txt
CC = gcc
CFLAGS = -Wall -pedantic -std=c99
SOURCE = https://www.github.com/guyfrancoeur/INF3135_H2019/raw/master/tp1/data.zip
FILE := cp.txt
CP := $(shell cat ${FILE})

default: $(TARGET)

$(TARGET): $(OBJECTS) $(OUTILS).o $(STRUCTURE).o
	$(CC) $(CFLAGS) $(OBJECTS) $(OUTILS).o $(STRUCTURE).o -o $(TARGET) -lm

$(OBJECTS): $(TARGET).c 
	$(CC) $(CFLAGS) -c $(TARGET).c -o $(TARGET).o

$(STRUCTURE).o: $(STRUCTURE).c
	$(CC) $(CFLAGS) -c $(STRUCTURE).c -o $(STRUCTURE).o

$(OUTILS).o: $(OUTILS).c
	$(CC) $(CFLAGS) -c $(OUTILS).c -o $(OUTILS).o

clean:
	rm -rf $(TARGET) $(CODE) *.o *.out *.zip tp2
	rm -rf data wget-log wget-log.* *.guy *.correction

data:
	rm -rf ./data
	mkdir data
	wget $(SOURCE)
	unzip data.zip  -d ./data

test:
	./$(TARGET) -c $(CP) -i ~/depot/data1.in

resultat: 
	git add resultat.txt
	git commit -m "Poussez le resultat dans le projet"
	git push origin master

valgrind:
	gcc -g $(TARGET).c $(OUTILS).c $(STRUCTURE).c -o $(TARGET)
	valgrind --leak-check=full ./$(TARGET) -c $(CP) -i ~/depot/data1.in
