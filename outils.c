// INF3135 Construction et maitenance de logiciel C
// Auteur: Jian Chen

// Librairies
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "structure.h"

#define EXPO 55
/*
void scanInt128(U128_t &x)
{
    x = 0;
    int f = 1;
    char ch;
    if((ch = getchar()) == '-') f = -f;
    else x = x*10 + ch-'0';
    while((ch = getchar()) >= '0' && ch <= '9')
        x = x*10 + ch-'0';
    x *= f;
}
*/
U128_s readInt128()
{
    U128_s x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}

U128_s printInt128(U128_s m)
{
    U128_s n = m;
    enum { base = 10, max_width = 39 };
    char a[max_width + 1] = { '\0' };
    char *p = a + max_width;
    for (; n != 0; n /= base) *--p = (char)('0' + n % base);
    printf("%s\n",p);
    return n;
}

// Fonction d'echange les deux nombres
long long echange(long long *c, long long *d)
{
	long long temp;
	if(*c > *d)
	{
		temp = *c;
		*c = *d;
		*d = temp;
	}
	return 0;
}

// Fonction de calculer les puissances
U128_s indice(U128_s bas, U128_s puiss) {
    U128_s resultat = 1;
    for(U128_s k = 0 ; k < puiss ; k++){resultat *= bas;}
	return resultat;
}
 
// Fonction de trouver les nombre parfaits entre deux intervalles 
U128_s nbParfait(U128_s debut, U128_s fin)
{
    bool_s flag = true;
    U128_s p = EXPO;
    U128_s nb, n=1;
    Tableau_s tableau;
 
    for(U128_s i = 3; i <= p; i+=1)
    {
	flag = true;
        U128_s carre = (indice(2, i)-1);
        for(U128_s j = 2; j*j < carre; j++)
        {
            if( (carre % j == 0) ){
            flag = false;
            break;
            }
        }
        if(flag)
        {
            nb = indice(2, i-1)*(indice(2,i)-1);
            tableau.tab[0] = 6;
	    tableau.tab[n] = nb;
	    n++;
	}
    }
    for(int m=n-1; m>=0; --m){
        if(tableau.tab[m] >= debut && tableau.tab[m] <= fin){
            printInt128(tableau.tab[m]);
        }
    }
    return 0;
}

