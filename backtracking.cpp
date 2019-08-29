#include<stdio.h>
#include<conio.h>// PERMUTARI
const MAX=20;
int n,v[30],p ; //n-nr. de elemente, v[20]-vectorul în care construim solutia
int valid(int k);
int solutie(int k);
void afisare(int k);
void BK(int k);
int main()
{printf("n=");
scanf("%d", &n); //se citeste n
BK(1);
return 0; //apelam functia BK pentru completarea pozitiei 1din vectorul v
}
void BK(int k)
{int i; //i-elementul selectat din multimea Sk, trebuie sa fie variabila locala, pentru
// a se memora pe stiva
for (i=1;i<=n;i++) //parcurgem elementele multimii Sk
 {v[k]=i; //selectam un element din multimea Sk
 if (valid(k)) //verificam daca eelementul ales îndeplineste condiiile de continuare
 {if (solutie(k)) //verificam daca am obtinut o solutie
 afisare(k); //se afiseaza solutia obtinuta
 else
 BK(k+1); //reapelam functia pentru pozitia k+1 din vectorul v
 }
}
}
int valid(int k) //verificam conditiile de continuare
{int i;
for (i=1;i<=k-1;i++) //comparam fiecare element din vectorul v cu ultimul element selectat
 if (v[i]==v[k]) //deoarece într-o permutare elementele nu au voie sa se repete,
 return 0; //returnam 0 în cazul în care elementul selectat, a mai fost selectat o data
return 1; //returnam 1 în cazul în care elementul nu mai apare în vector
}
int solutie(int k) //verificam daca am obtinut o solutie
{if (k==n) //am obtinut o permutare, daca am reusit sa depunem în vector n elemente
 return 1; // daca sunt aranjamente conditia devine (k==p)
return 0;
}
void afisare(int k) //afiseaza continutul vectorului v
{int i;
for (i=1;i<=k;i++)
    printf("%d", v[i]);
    printf("\n");
_getch();

}
2. damele
#include <math.h>
#include<conio.h>
#include<stdio.h>
int n,v[30],sol;
int valid(int k);
int solutie(int k);
void afisare();
void BK(int k);
void main()
{printf("n= ");scanf("%d", &n);
 BK(1);
}
void BK(int k)
{int i;
for (i=1;i<=n;i++)
 {v[k]=i;
 if (valid(k)==1)
 {if (solutie(k)==1)
 afisare();
 else
 BK(k+1);
 }
 }
}
int valid(int k)
{int i;
for (i=1;i<=k-1;i++)
 if ((v[i]==v[k])||(abs(v[k]-v[i])==(k-i)))
 return 0;
return 1;}
int solutie(int k)
{if (k==n)
 return 1;
return 0;}
void afisare() //afisam solutiile sub forma unei matrice
{int i,j,x;
sol++;
 printf("\n Solutia: "); printf("%d", sol); printf("\n");
for (i=1;i<=n;i++)
 {for (j=1;j<=n;j++)
 if (v[i]==j) printf("D ");
 else printf("_ ");
 printf("\n");
 }
}
