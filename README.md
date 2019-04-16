# Travail Pratique 2

## Discription

Ce projet utilise principalement le langage `C` pour calculer des nombres parfaits. Il permet de passer des arguments en ligne de commande avec deux types syntaxes suivants:
~~~~
$ ./tp2 -c CODE_permanent -i nom_du_fichier_en_entree.ext -o fichier_sortie.ext
~~~~
~~~~
$ ./tp2 -c CODE_permanent < nom_du_fichier_en_entree.ext > fichier_sortie.ext
~~~~
En outre, le projet gère automatiquement les données, les fichiers et les arguments de ligne de commande via `Make` et `Makefile`.
Les codes sources sont maintenus sur Github.

INF3135 - Construction et maintenance de logiciel en `C` (Université du Québec à Montréal)

## Auteur

Jian Chen (CHEJ19087301)

## Fonctionnement

Ce projet permet d'exécuter un `C` programme à partir de la ligne de commande pour trouver le nombre parfait et valider les arguments de la ligne de commande.  Il gère également automatiquement les données et les fichiers via `C`.
- Si on lance une commande `./tp2 -c CODE_permanent -i entree.txt -o sortie.txt`, le programme générera automatiquement un fichier `code.txt` contenant le Code Permanent passé par le paramètre `-c` et le fichier `sortie.txt`, qui contient tous les nombres parfaits trouvés en lisant le fichier d'entrée `entree.txt`.
- Si on exécute la commande `make clean` dans shell, tous les fichiers d'objet `*.o`, `code.txt` et le fichier exécutable `tp2` doivent être enlevés.
- Dans TP2, étant donné que les tâches répétitives sont fréquentes, une fonctionnalité essentielle a été ajoutée pour automatiser les tests via le fichier évaluateur.sh du script Bash.

## Contenu du projet

Ce projet contient principalement les fichiers suivants:
- Tout les codes sources du `C` programme dans ce projet, ainsi que la fonction `main`, sont inclus dans le fichier `tp2.c`.
- La description du projet, l'auteur, les fonctionnements, le contenu, les références et l'état sont listés dans le fichier `README.md`.
- Le code permanent en majuscule provient le contenu du fichier `cp.txt`.
- Dans ce projet, un fichier `Makefile` est créé pour gérer automatiquement la compilation, le traitement des données et le traitement des fichiers du code source. Il fournit les fonctions suivantes, notamment `make`, `make clean`, `make data`, `make test` et `make resultat`.
> Dans la fonction de `make test`, il peut tester pour créer le `CODE permanent` lu dans le fichier `cp.txt` par une variable `CP`. De plus, il a été testé pour lire les données d'un fichier `data.txt` dans le répertoire `./data` et afficher le résultat avec les nombres parfaits à l'écran.
- Un fichier `.gitignore` spécifie les fichiers intentionnellement non suivis que Git doit ignorer, y compris les fichiers d'objet, d'exécution et de package.
- Les fichiers outils.h et outils.c contenant le code source de mes fonctions.
- Un ficheer `evaluer.sh` est utilisé pour tester mon programme de façon automatisé.

## Références

Tous les travaux de ce projet sont basés sur les matériaux et les liens suivants, et je remercie pour leurs contributions.
- [C Programming Language Tutorial - Abhishek Ahlawat](https://www.studytonight.com/c/ "C")
- [The C Programming Language (Second Edition) - Brian W.Kernighan](https://archive.org/details/CProgrammingLanguage2ndEditionByBrianW.KernighanDennisM.Ritchie/page/n191)
- [Programming in C (UNIX System Calls and Subroutines using C) - A. D. Marshall](https://users.cs.cf.ac.uk/Dave.Marshall/C/CE.html)
- [The C Programming Language - TIOBE Graph](https://www.tiobe.com/tiobe-index/c/ "Langage C")


## Statut

Mon projet a été réalisé et complété conformément aux exigences du TP2.
