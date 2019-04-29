// INF3135 Construction et maitenance de logiciel C
// Auteur: Jian Chen

#ifndef _STRUCTURE_H
#define _STRUCTURE_H
#define TSIZE 20

// Définition d'une structure en enum
typedef enum {
	false=0, true=1
}bool_s;

// Définition d'une structure en __int128
__extension__ typedef unsigned __int128 U128_s;

//
typedef struct tableau{
	U128_s tab[TSIZE];
	int data;
}Tableau_s;

// Définition de la structure d'une dynamique array
typedef struct {
	U128_s usedSize;
	U128_s  maxSize;
	U128_s *data;
}arrayVector_s;

// Initialisation d'une structure de vector
void initVector(arrayVector_s *vector, U128_s maxSize);

// Ajouter de nouvelles données
void addVector(arrayVector_s *vector, U128_s value);

// Renvoie les données dans l'indice spécifié. S'il échoue, renvoie -1
U128_s getVector(arrayVector_s *vector, U128_s index);

// Définir la position spécifiée comme donnée spécifiée	
void setVector(arrayVector_s *vector, U128_s index, U128_s value);

// Redéfinir l'espace de stockage actuel de arrayVecotr
void resizeVector(arrayVector_s *vector);

// Libérer les donnees
void freeVector(arrayVector_s *vector);

#endif
