// INF3135 Construction et maitenance de logiciel C
// Auteur: Jian Chen

// Librairies
#include <stdio.h>
#include <stdlib.h>
#include "structure.h"

// Initialisation
void initVector(arrayVector_s *vector, U128_s maxSize){
	// Initialisation de la taille maximale et de la longeur du tableau utilisé
	vector->usedSize = 0;
	vector->maxSize = maxSize;

	// Ouvrez un espace pour stocker des données réelles
	vector->data = (U128_s*)malloc(sizeof(U128_s) * vector->maxSize);

	// Initialisation des éléments à zéro
	for (U128_s i=vector->usedSize; i < vector->maxSize; ++i) {
    	setVector(vector, i, 0);
    }
}

// Ajouter une valeur
void addVector(arrayVector_s *vector, U128_s value){
	// L'espace n'est pas suffisant, il faut augmenter
	resizeVector(vector);

	//Ajouter de nouvelles données à la fin du tableau
	vector->data[vector->usedSize++] = value;
}

// Obtenir une valeur
U128_s getVector(arrayVector_s *vector, U128_s index){
	// Si les données d'entrée sont inférieures à 0 ou à la valeur de stockage maximale de la grande 
	// matrice résiduelle, quittez le programme directement car les données sont illégales
	if(index >= vector->usedSize || index < 0){
		exit(1);
	}
	// Si l'entrée est une donnée légale, les données correspondantes sont renvoyées
	return vector->data[index];
}

// Réglage une valeur
void setVector(arrayVector_s *vector, U128_s index, U128_s value){
	if (index < vector->usedSize && index >= 0) {
    	vector->data[index] = value;
	}else if(index >= vector->usedSize){
		addVector(vector, 0);
	}
}

// Élargir l'espace
void resizeVector(arrayVector_s *vector){
	if (vector->usedSize >= vector->maxSize) {
    	// Augmenter la taille du tableau à deux fois la taille actuelle
    	vector->maxSize *= 2;
    	vector->data = (U128_s*)realloc(vector->data, sizeof(U128_s) * vector->maxSize);
    }
}

// Libérer de l'espace
void freeVector(arrayVector_s *vector){
	free(vector->data);
}
