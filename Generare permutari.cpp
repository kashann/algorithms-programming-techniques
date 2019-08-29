#include<stdio.h>
#include<conio.h>

char r='n';

// Verifica daca valoarea elementului i este acceptabila (diferita de cele anterioare)
int posibil( int* v, int i)
{ int j, r;
  r=1;
  for(j=0;j<i;j++)
    if(v[i]==v[j])
      r=0;
  return r;
}


// Afisare solutie pe ecran
// I: numarul solutiei (num), dimensiunea permutarii (nr), permutarea (v)
void retine_solutia(int num, int nr, int* v)
{ int i;


  printf("\n\n Solutia numarul %d\n",num);
  for(i=0; i<nr; i++)
    printf("%2d ",v[i]);
  
  if(r=='n')
  { printf("\n\nUrmatoarea (n) sau Ultima (l)?");
    r=_getch();
  }
}
 


// Genereaza permutari de n elemente (1..n)
// I: n
// E: numar permutari
int permutari(int n)
{ int* p,i,am,nr;
 
  // pentru ca se folosste un vector de dimensiune n, cu indici de la 0 la n-1 (in loc de 1..n)
  // indicele i arata o configuratie solutie daca i==n-1, configuratie finala daca i=-1

  p=new int[n];         //vectorul solutie
  nr=0;                 //numar solutii
  i=0;
  p[0]=0;               //prima valoare minus ratia
  while(i>=0)            //cit timp nu am ajuns la configuratia finala
  { am=0;
    while( p[i]<n && !am) //alege urmatoarea valoare acceptabila pentru x[i]
    { p[i]++;             //urmatoarea valoare pentru x[i]  
      am=posibil(p,i);    //este acceptabila?
    }
    if(!am)               //impas, revenire
      i--;
    else
      if( i==n-1 )        //configuratie solutie
        retine_solutia(++nr,n,p);
      else
        p[++i]=0;       //prima valoare minus ratia
  }
  delete p;
  return nr;
}


void main()
{ int n,nr;


  printf("\nGenereaza permutari de n elemente. n= ");
  scanf("%d",&n);


  nr=permutari(n);

  printf("\n\n Sint %d permutari posibile",nr);

  printf("\n\nGata. Apasa o tasta.");
  _getch();
}