#include<stdio.h>
#include<conio.h>

#define N 14

// Submultimea care da suma maxima: se iau doar elementele (strict) pozitive
// I: multimea (a), numar de elemente (n)
// E: submultimea (b), numar de elemente (nr)
void suma_maxima(float* a, int n, float *b, int &nr)
{ int i;
  nr=0;
  for(i=0;i<n;i++)
    if(a[i]>=0)       // = pentru zero, care nu afecteaza suma. depinde de problema daca se ia sau nu
      b[nr++]=a[i];
}


void main()
{ float multime[N]={1,2,3,-2,4,-4,-3,5,6,7,-1,8,9,0};     //multime de test
  int lm=N;
  float subm[N];
  int ls;
  int i;
  float suma;

  suma_maxima(multime,lm,subm,ls);
  for(i=0,suma=0; i<ls; i++)
    printf("\n%5.2f suma=%5.2f",subm[i], suma+=subm[i]);

  _getch();
}