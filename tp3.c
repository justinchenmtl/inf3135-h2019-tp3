// INF-3135 Construction et maintenance de logiciel en C
// Auteur: Jian Chen

// Librairies
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <math.h>
#include "outils.h"
#include "structure.h"

// Fonctions main
int main(int argc, char** argv) {

    // Déclaration des variables
    FILE *entree = NULL;
    FILE *sortie = NULL;
    FILE *code = NULL; 
    long long tete=0l, tail=0l;
    int count = argc;

    // Validations des arguments
    for(int i = 0; i < count; i++){
        entree = stdin;
        sortie = stdout;

        if(entree == NULL){
            return 5;
        }else if(sortie == NULL){
            return 6;
        }

        if(count < 2 || strcmp(argv[1], "-c") != 0){
            fprintf(stderr, "La ligne de commande doit être sous la forme suivante: %s <-c CODEpermanent> [-i fichier.in] [-o fichier.out] \n", argv[0]);
            return 1;
        }

        if(strcmp(argv[1], "-c") == 0 && (count == 2 || strlen(argv[2]) != 12)){
            return 2;
        }
		
		if(count == 4){
			if(strcmp(argv[3], "-i") != 0 && strcmp(argv[3], "-o") != 0){
				return 3;
			}else if(strcmp(argv[3], "-i") == 0){
				return 5;
			}else if(strcmp(argv[3], "-o") == 0){
				return 6;
			}
		}

        if(count == 5){ 
            if(strcmp(argv[3], "-i") != 0 && strcmp(argv[3], "-o") != 0){
                return 3;
            }else if(strcmp(argv[3], "-i") == 0 ){
                entree = freopen(argv[4], "r", stdin);
                if(entree == NULL)
                    return  5;
            }else if(strcmp(argv[3], "-o") == 0){
                sortie = freopen(argv[4], "w", stdout);
                if(sortie == NULL)
                    return 6;
            }
         }

		if(count == 6){
			if((strcmp(argv[3], "-i") != 0 && strcmp(argv[3], "-o") != 0) || (strcmp(argv[5], "-i") != 0 && strcmp(argv[5], "-o") != 0)){
				return 3;
			}else if(strcmp(argv[3], "-i") == 0 && strcmp(argv[5], "-o") == 0){
				entree = freopen(argv[4], "r", stdin);
				sortie = freopen(argv[6], "w", stdout);
				if(entree == NULL){
				    return 5;
				}else if(sortie == NULL){
					return 6;
				}
			}else if(strcmp(argv[3], "-o") == 0 && strcmp(argv[5], "-i") == 0){
				sortie = freopen(argv[4], "w", stdout);
				entree = freopen(argv[6], "r", stdin);
				if(entree == NULL){
					return 5;
				}else if(sortie == NULL){
					return 6;
				}
			}
		}

	    if(count >= 7){
            if((strcmp(argv[3], "-i") != 0 && strcmp(argv[3], "-o") != 0) || (strcmp(argv[5], "-i") != 0 && strcmp(argv[5], "-o") != 0)){
	        return 3;
	        }else if(strcmp(argv[3], "-i") == 0 && strcmp(argv[5], "-o") == 0){
                entree = freopen(argv[4], "r", stdin);
                sortie = freopen(argv[6], "w", stdout);
                if(entree == NULL){
                    return 5;
                }else if(sortie == NULL){
                    return 6;
                }
             }else if(strcmp(argv[3], "-o") == 0 && strcmp(argv[5], "-i") == 0){
                sortie = freopen(argv[4], "w", stdout);
                entree = freopen(argv[6], "r", stdin);
                if(entree == NULL){
                    return 5;
                }else if(sortie == NULL){
                    return 6;
                }
            }
	    }
    }
	
	U128_t n =0;
	n = ~n;
	int128();


	arrayVector inVector;
	initVector(&inVector, 2);

	// Créer un fichier code.txt qui contient le code permanent qui est passé par l'argument -c
    code = fopen("code.txt", "w");
    fprintf(code, "%s\n", argv[2]);
    fclose(code);

    // Validation des intervalles dans le fichier entrée 
    long long a = scanf("%lld", &tete);
    long long b = scanf("%lld", &tail);
    if(a != 1 || b != 1 || tete < 0 || tail < 0 ){
       return 4;
    }

    // Déterminer le nombre minimal et maximal et echanger
	echange(&tete, &tail);
    fclose(entree);

	setVector(&inVector, 0, tete);
	setVector(&inVector, 1, tail);
//	printf("valeur a l'index 0: %lld\n", getVector(&inVector, 0));
//	printf("valeur a l'index 1: %lld\n", getVector(&inVector, 1));

    // Calculer les nombres parfaits entre les intervalles
    nbParfait(getVector(&inVector, 0), getVector(&inVector, 1));
	freeVector(&inVector);
    return 0;
} 

