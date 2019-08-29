#include <iostream>
#include<conio.h>

void citire( int a[][100],int *m, int *n)
{
	FILE *f;
	int i, u,v;
	char nume[20];
	fflush(stdin);
	gets(nume);
	f=fopen(nume,"r");
	if (!f) printf ("nu se poate deschide fisierul");
	else {
			fscanf(f,"%i",m);
			fscanf(f,"%i",n);
				for(i=0;i<*m;i++)
				{ 
					fscanf(f,"%i",&u);
					fscanf(f,"%i",&v);
						a[u][v]=a[v][u]==1;
				}
				fclose(f);
	}
}


int verificare( int a[][100], int n)
{
	int i,j,ok;
	ok=1;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if( a[i][j]==1) ok=0;
	if(ok) return 1;
	else return 0;
}

void main()
{
	int n,m, a[100][100];
	citire(a,&m,&n);
	if(verificare(a,n))
		printf("graful are numai noduri izolate");
	else printf("nu sunt izolate");
	getche();
}