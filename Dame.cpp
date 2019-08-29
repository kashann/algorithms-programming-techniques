#include<stdio.h>
#include<conio.h>
#include<math.h>

char r;


// Retine o configuratie solutie (afisare)
// I: nr. solutie (nr), nr dame (n), vector solutie
// E: -
void retine_solutia(int nr, int n, int* x)
{ int i,j;

  printf("\n Solutia numarul %d\n",nr);
  for(i=1; i<=n; i++)
  { for(j=1; j<=n; j++)
      printf("%c ",j==x[i]?'D':'x');
    printf("\n");
  }
  if(r=='n')
  { printf("\n\nUrmatoarea (n) sau Ultima (l)?");
    r=_getch();
  }
}

// Conditia de continuare: damele i si j nu se ataca daca 
// - nu sint pe aceeasi coloana
// - distantele pe verticala si orizontala sint diferite
// I: solutia partiala (x), numarul de elemente (i)
// E: 1 daca e acceptabila, 0 daca nu e acceptabila
int posibil(int *x, int i)
{ int j, p;
  p=1;
  for( j=1; j<i; j++)
    if( x[i]==x[j] || abs(i-j)==abs(x[i]-x[j]) )
      p=0;
  return p;
}

// Problema celor n dame
// I: numar dame/dimensiune tabla (n)
// E: numar solutii
int dame(int n)
{ int nr;
  int* x;
  int i, am;

  x=new int[n+1];       //vectorul solutie
  nr=0;                 //numar solutii
  i=1;
  x[1]=0;               //prima valoare minus ratia
  while(i>0)            //cit timp nu am ajuns la configuratia finala
  { am=0;
    while( x[i]<n && !am) //alege urmatoarea valoare acceptabila pentru x[i]
    { x[i]++;             //urmatoarea valoare pentru x[i]  
      am=posibil(x,i);    //este acceptabila?
    }
    if(!am)               //impas, revenire
      i--;
    else
      if( i==n )        //configuratie solutie
        retine_solutia(++nr,n,x);
      else
        x[++i]=0;       //prima valoare minus ratia
  }
  delete x;
  return nr;
}


// Problema celor n dame, recursiv
// I: numar dame (n), element curent (i), vector solutie (x), numar solutii (nr)
// E: nr. solutii
int dame_r(int n, int i, int* x, int nr)
{ int j;

  if( i==n+1)
    retine_solutia(++nr,n,x);
  else
    for(j=1; j<=n; j++ )
    { x[i]=j;
      if( posibil(x,i) )
        nr=dame_r(n,i+1,x,nr);
    }
  return nr;
}

void main()
{ 
  int n;

  n=8;
  r='n';

  //iterativ
  //printf("\n\nNumarul de solutii este %d ", dame(n));

  //recursiv
  int* x=new int[n+1];
  int nr=0;
  printf("\n\nNumarul de solutii este %d ", dame_r(n,1,x,nr));
  delete x;

  printf("\n Gata, apasa o tasta!");
  _getch();
}