// INF3135 Construction et maitenance de logiciel C
// Auteur: Jian Chen
#include "structure.h"

#ifndef _OUTILS_H
#define _OUTILS_H

extern U128_s nbParfait(U128_s debut, U128_s fin);
extern U128_s indice(U128_s bas, U128_s puiss);
extern long long echange(long long *c, long long *d);
extern U128_s printInt128(U128_s x);
//extern void scanInt128(U128_t &z);
extern U128_s readInt128();
#endif
