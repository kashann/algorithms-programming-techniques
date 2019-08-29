#include <stdio.h>
#include <conio.h>

//---BF---

int insereaza_coada(int *coada, int n, int vf)
{ 
	coada[n]=vf;
	n++;
	return n;
}

int extrage_coada(int *coada, int n, int *vf)
{
	int  i;
	*vf=coada[0];
	for(i=0;i<n-1;i++)
		coada[i]=coada[i+1];
	n--;
	return n;
}

//alocare matrice
int** aloca(int linii, int coloane)
{
	int **a,i;
	a=new int* [linii];
	for(i=0;i<linii;i++)
		a[i]=new int [coloane];
	return a;
}

//dezalocare matrice
int** dezaloca(int **a, int linii)
{
	int i;
	for(i=0;i<linii;i++)
		delete a[i];
	delete a;
	return a;
}

//parcurgerea bf
void breadth_first(int v0, int **a, int n)
{
	int *coada, *m,i,nr_c,k;
	coada=new int[n];
	m=new int[n];
	for(i=0;i<n;m[i++]=0);
	nr_c=0;
	nr_c=insereaza_coada(coada,nr_c,v0);
	m[v0]=1;
	while(nr_c)
	{
		nr_c=extrage_coada(coada,nr_c,&i);
		printf("\n%i",i+1);
		for(int k=0;k<n;k++)
			if((a[i][k]==1)&&(c[k]==0))
			{
				nr_c=insereaza_coada(coada,nr_c,k);
				c[k]=1;
			}
	}
	delete coada;
	delete m;
}

void main()
{
	int n,v0,**a,m,i,j,vf1,vf2;
	//graful este preluat de la tastatura
	//datele citite sunt:nr de varfuri, nr de muchii
	//si muchiile date prin perechi (vf initia,vf final)
	printf("Numarul de varfuri:");
	scanf("%i",&n);
	a=aloca(n,n);
	for(i=0;i<n;i++)
		for(int j=0;j<=i;j++)
			a[j][i]=a[i][j]=0;
	printf("\nNumarul de muchii:");
	scanf("%i",&m);
	for(i=0;i<m;i++)
	{
		printf("Varf initial:");
		scanf("%i",&vf1);
		printf("Varf final:");
		scanf("%i",&vf2);
		a[vf1-1][vf2-1]=a[vf2-1][vf1-1]=1;
	}
	printf("\nVarful initial pt parcurgerea BF ");
	scanf("%i",&v0);
	printf("\nOrdinea de vizitare a varfurilor grafului este:");
	breadth_first(v0-1,a,n);
	a=dezaloca(a,n);
	getch();
}


//---DF---


int insereaza_stiva(int *stiva,int n, int vf)
{
	int i;
	for(i=n-1;i>=0;i--)
		stiva[i+1]=stiva[i];
	stiva[0]=vf;
	n++;
	return n;
}

int sterge_stiva(int *stiva,int n)
{
	int i;
	for(i=0;i<n-1;i++)
		stiva[i]=stiva[i+1];
	n--;
	return n;
}

int citeste_stiva(int *stiva, int n)
{
	return stiva[0];
}

//alocare matrice
int** aloca(int linii, int coloane)
{
	int **a,i;
	a=new int* [linii];
	for(i=0;i<linii;i++)
		a[i]=new int [coloane];
	return a;
}

//dezalocare matrice
int** dezaloca(int **a, int linii)
{
	int i;
	for(i=0;i<linii;i++)
		delete a[i];
	delete a;
	return a;
}

//parcurgerea df
void depth_first(int v0, int **a, int n)
{
	int *stiva, *m,i,nr_c,gasit;
	stiva=new int[n];
	m=new int[n];
	for(i=0;i<n;m[i++]=0);
	nr_c=0;
	nr_c=insereaza_stiva(stiva,nr_c,v0);
	m[v0]=1;
	printf("\n%i",v0+1);
	while(nr_c)
	{
		i=citeste_stiva(stiva,nr_c);
		gasit=0;
		for(int k=0;(k<n)&&!gasit;k++)
			if((a[i][k]==1)&&(m[k]==0))
			{
				nr_c=insereaza_stiva(stiva,nr_c,k);
				m[k]=1;
				printf("\n%i",k+1);
				gasit=1;
			}
			if(!gasit)
				nr_c=sterge_stiva(stiva,nr_c);
	}
	delete stiva;
	delete m;
}

void main()
{
	int n,v0,**a,m,i,j,vf1,vf2;
	//graful este preluat de la tastatura
	//datele citite sunt:nr de varfuri, nr de muchii
	//si muchiile date prin perechi (vf initia,vf final)
	printf("Numarul de varfuri:");
	scanf("%i",&n);
	a=aloca(n,n);
	for(i=0;i<n;i++)
		for(int j=0;j<=i;j++)
			a[j][i]=a[i][j]=0;
	printf("\nNumarul de muchii:");
	scanf("%i",&m);
	for(i=0;i<m;i++)
	{
		printf("Varf initial:");
		scanf("%i",&vf1);
		printf("Varf final:");
		scanf("%i",&vf2);
		a[vf1-1][vf2-1]=a[vf2-1][vf1-1]=1;
	}
	printf("\nVarful initial pt parcurgerea DF ");
	scanf("%i",&v0);
	printf("\nOrdinea de vizitare a varfurilor grafului este:");
	depth_first(v0-1,a,n);
	a=dezaloca(a,n);
	getch();
}