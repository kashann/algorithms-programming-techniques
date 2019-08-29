#include<stdio.h>
#include<conio.h>
#include<string.h>

//element al listei de vectori: adresa vector si dimensiune vector
typedef struct { double* a;
                 int l;
               }VECTORI;

// Interclasarea a doi vectori
// I: adresa vector 1, lungime vector 1, adresa vector 2, lungime vector 2
// E: adresa vector rezultat, lungime vector rezultat
void interclasare2(double* v1, int l1, double* v2, int l2, double* &r, int &lr)
{ int i,j,t;
  
  r=new double[l1+l2];
  i=j=lr=0;
  while(i<l1 && j<l2)
    if(v1[i]<v2[j])
      r[lr++]=v1[i++];
    else
      r[lr++]=v2[j++];
  for(t=i;t<l1;t++)
    r[lr++]=v1[t];
  for(t=j;t<l2;t++)
    r[lr++]=v2[t];
}

// interclasare optima 
// I: lista vectori de interclasat (l), lungime lista (n)
// E: lista vectori (l), lungime lista (n)
// la final lista contine un singur vector, rezultatul interclasarii. vectorii initiali se pierd
void interclasare_optima(VECTORI* l, int &n)
{ int i,j,k,nr;
  double* t;
  int d, gata;

  //prelucrare preliminara: aranjare vectori in ordinea crescatoare a lungimii
  //se interclaseaza cei mai scurti doi vectori
  for(i=0;i<n-1;i++)
    for(j=i;j<n;j++)
      if(l[i].l>l[j].l)
      { t=l[i].a; l[i].a=l[j].a; l[j].a=t;
        d=l[i].l; l[i].l=l[j].l; l[j].l=d;
      }

 
  //se fac n-1 interclasari
  nr=n;
  for(i=0;i<nr-1;i++)
  { //la pasul i se interclaseaza vectorii de pe pozitiile 0 si 1
    //rezulta vectorul cu adresa t si lungimea d
    interclasare2(l[0].a, l[0].l, l[1].a, l[1].l, t, d);
    
    //vectorul obtinut se insereaza in lista, astfel incit ea sa ramina sortata
    
    delete l[0].a;
    delete l[1].a;
    for(j=2;j<n;j++)
    { l[j-2].a=l[j].a;
      l[j-2].l=l[j].l;
    }
    n=n-2;
    
    //pozitia pe care trebuie inserat noul vector va fi j
    gata=0;
    for(j=0;j<n && !gata; j++)
      if(l[j].l>d)
        gata=1;
    for(k=n;k>j;k--)
    { l[k].a=l[k-1].a;
      l[k].l=l[k-1].l;
    }
    l[j].a=t;
    l[j].l=d;
    n++; 
  }
}

void main()
{ int nr;       //numar vectori
  VECTORI* v;   //lista de vectori pentru interclasare
  FILE* f;      //fisierul din care se preiau vectorii
  char numef[30];  //nume extern fisier 
  int i,j;


  //vectorii care urmeaza sa fie interclasati se preiau dintr-un fisier text
  //pe prima linie e numarul de vectori
  //pe fiecare din liniile urmatoare e cite un vector cu elemente reale: (dim, v[0], v[1], v[2], ... v[dim-1]
  strcpy(numef,"vectori.txt");
  fopen_s(&f, numef,"r");
  if(!f)
    printf("\nFisierul %s nu poate fi deschis");
  else
  { //preluare date din fisierul text
    fscanf(f,"%d",&nr);
    v=new VECTORI[nr];
    for(i=0;i<nr;i++)
    { fscanf(f,"%d",&v[i].l);
      v[i].a=new double[ v[i].l ];
      for(j=0;j<v[i].l;j++)
        fscanf(f,"%lf",&v[i].a[j]);
    }

    printf("\n Initial sint %d vectori:",nr);
    for(i=0;i<nr;i++)
    { printf("\n%2d: ",v[i].l);
      for(j=0;j<v[i].l;j++)
        printf("%5.2lf ",v[i].a[j]);
    }

    interclasare_optima(v, nr);
   
    printf("\n\n Vectorul rezultat:");
    for(i=0;i<nr;i++)
    { printf("\n%2d: ",v[i].l);
      for(j=0;j<v[i].l;j++)
        printf("%5.2lf ",v[i].a[j]);
    }

  }





  printf("\nGata, apasa o tasta.");
  _getch();
}