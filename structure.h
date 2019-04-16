// INF3135 Construction et maitenance de logiciel C
// Auteur: Jian Chen

#ifndef _STRUCTURE_H
#define _STRUCTURE_H

// Définition d'une structure en enum
typedef enum {
	false=0, true=1
}bool_t;
// Définition d'une structure en __int128
__extension__ typedef unsigned __int128 U128_t;

// Définition de la structure d'une dynamique array
typedef struct {
	long long usedSize;
	long long  maxSize;
	long long *data;
}arrayVector;

// Initialisation d'une structure de vector
void initVector(arrayVector *vector, long long maxSize);

// Ajouter de nouvelles données
void addVector(arrayVector *vector, long long value);

// Renvoie les données dans l'indice spécifié. S'il échoue, renvoie -1
long long getVector(arrayVector *vector, long long index);

// Définir la position spécifiée comme donnée spécifiée	
void setVector(arrayVector *vector, long long index, long long value);

// Redéfinir l'espace de stockage actuel de arrayVecotr
void resizeVector(arrayVector *vector);

// Libérer les donnees
void freeVector(arrayVector *vector);

#endif
