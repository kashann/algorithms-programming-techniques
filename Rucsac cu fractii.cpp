#include<stdio.h>
#include<conio.h>

#define N 10

//problema rucsacului, continua
// I: capacitate totala (q), nr. obiecte (n), capacitate ocupata (c), cistig (v)
// E: solutia x (x[i]= raportul in care e incarcat obiectul i)
void Rucsac_c(float q, int n, float* c, float* x)
{ float qr;
  int i,j;

  qr=q;               //capacitatea ramasa disponibila, initial capacitatea totala
  for(i=0; i<n && qr>0; i++)
    if(qr>=c[i])
    { x[i]=1;
      qr-=c[i];       //qr-=c[i]*x[i]
    }
    else
    { x[i]=qr/c[i];
      qr=0;           //qr-=c[i]*x[i]
      for(j=i+1;j<n;j++)
        x[j]=0;
    }
}


void main() 
{ float CT=33;                                  //capacitate totala de transport
  float date[2][N]={ {1,2,3,4,5,6,7,8,9,10},    //capacitati
                     {3,2,1,4,5,3,2,7,1,8}      //venituri
                   };
  float sol[N],a, cistig;
  int i,j;

  //prelucrare preliminara
  //sortarea obiectelor in ordinea in care vreau sa fie luate in considerare
  for(i=0;i<N-1;i++)
    for(j=i+1;j<N;j++)
      //if(date[0][i]<date[0][j])                           //capacitati    17.71
      //if(date[1][i]<date[1][j])                           //cistig        29.5
      if(date[1][i]/date[0][i] < date[1][j]/date[0][j])     //cistig unitar 30.5
      { a=date[0][i]; date[0][i]=date[0][j]; date[0][j]=a;
        a=date[1][i]; date[1][i]=date[1][j]; date[1][j]=a;
      }

  //apel functie
  Rucsac_c(CT, N, date[0], sol);

  //afisare rezultate
  cistig=0;
  for(i=0;i<N;i++)
  {  printf("\n%2d: c=%5.2f v=%5.2f %2f, cistig=%5.2f",i+1, date[0][i], date[1][i], sol[i], cistig+=date[1][i]*sol[i]);
  }
  _getch();

} 