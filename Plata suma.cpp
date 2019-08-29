#include<stdio.h>
#include<conio.h>

#define N 7
char r='n';

//pentru a evita translatia indicilor, masivele sint alocate cu n+1 elemente
//si se ignora elementul cu indicele zero.

int posibil(int* x, int i, int n, int s, int c)
{ if(i==n)
    return s==c;
  else
    return s>=c;
}

void retine(int* t, int* x, int n, int ns)
{ int i,s;
  s=0;
  printf("\n\nSolutia numarul %d", ns);
  for(i=1;i<=n;i++)
    printf("\n %3d * %2d = %4d, suma=%4d",t[i],x[i],t[i]*x[i],s+=t[i]*x[i]);
   if(r=='n')
  { printf("\n\nUrmatoarea (n) sau Ultima (l)?");
    r=_getch();
  }
}

int plata(int suma, int crt, int* t, int* nr, int n, int ns, int i, int* x)
{ int j;
  if(i==(n+1) )
    retine(t, x, n, ++ns);
  else
  { for(j=0; j<=nr[i]; j++)
    { x[i]=j;
      crt+=t[i]*j;
      if( posibil(x, i, n, suma,crt) )
        ns=plata(suma, crt, t, nr, n, ns, i+1, x);
      crt-=t[i]*j;
    }
  }
  return ns;
}

void main()
{ int t[N+1]={0,1,5,10,50,100,200,500};
  int nr[N+1]={0,20,20,20,20,20,20,20};
  int S,ns;
  int* sol;

  S=1234;
  ns=0;
  sol=new int[N+1];

  ns=plata(S, 0, t, nr, N, ns, 1, sol);

  printf("\nNumarul de solutii este: %d",ns);

  delete sol;

  _getch();
}