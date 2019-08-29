// seminar 13.cpp 
/*Kruskal - arbore partial de cost minim
A = 2 3 1 --
	1 6 2 -- 
	2 4 2 --
	1 5 3 --
	3 4 3 
	1 2 4 --
	4 6 8
	5 6 8
	3 6 9

	tata[i]=-1 i=1->6 
	vector parinte: (-1,-1,-1,-1,-1,-1) -- se considera ca nici un varf nu are parinte
	avem nevoie de un subprogram care sa ne determine parintele
	vom testa daca cele doua varfuri ale muchiei mele au acelasi parinte. 
	daca au acelasi parinte se formeaza un ciclu.
	daca valoarea < -1 se intoarce i
	cel mai mic va fi parinte pt cel mare
	in constructia facuta daca tata[p]<tata[k] => tata[p]=tata[p]+tata[k] ; tata[k]=p;

	1) (2,3) cost 1
	v1=2, v2=3
	tata[2]=-1 <0 =>p=2
	tata[3]=-1 <0 =>k=3
	(p!=k) tata[2]<=tata[3] => tata[2]=tata[2]+tata[3]=2 ; tata[3]=2;

	algoritmul continua pana la n-1 muchii.

	cost minim = 12 
*/ 

#include <stdio.h>
int radacina (int v, int *tata)
{
	int u=v;
	while(tata[u]>=0) u=tata[u];
	return u;
}
int kruskal(int a[][3], int nv, int nm, int b[][3], int *l)
{
	int tata[50],i,j;
	int c=0;
	*l=0;
	for(i=0;i<nv;i++) tata[i]=-1;
	for(j=i=0;i<nv;j++)
	{
		int v1=a[j][0]; int v2=a[j][1];
		int k=radacina(v2,tata); int p=radacina(v1,tata);
		if (k!=p)
		{
			if(tata[p]<=tata[k])
			{
				tata[p]+=tata[k];
				tata[k]=p;
			}
			else
			{
				tata[k]+=tata[p];
				tata[p]=k;
			}
			c+=a[j][2];
			//printf("%i -> %i cost %i\n",v1+1,v2+1,a[j][2]);
			/*b[*l][0]=a[j][0]; //carte^
			b[*l][1]=a[j][1];
			b[*l][2]=a[j][2];
			(*l)=(*l)+1;*/
			i++;
		}
	}
	return c;
}


void main ()
{
	int nv, nm, a[50][3],i,j,b[50][3];
	printf("Numarul de varfuri:"); scanf_s("%d",&nv);
	printf("numarul de muchii:"); scanf_s("%d",&nm);
	printf("Matricea reprezentare\n");
	for (i=0;i<nm;i++)
	{
		printf("vi="); scanf_s("%d",&a[i][0]);
		printf("vf="); scanf_s("%d",&a[i][1]);
		printf("cost="); scanf_s("%d",&a[i][2]);
	}
	for (i=0;i<nm;i++)
	{
		printf("\n");
		for(j=0;j<3;j++)
			printf("%d",a[i][j]);
	}
	printf("\nArborele de cost nimim; \n);
		int l=0;
	int cost=kruskal(a,nv,nm,b,&l);
	printf("\ncostul=%i\n",cost);
	for(i=0;i<l;i++)
	{
		for(j=0;j<3;j++)
			printf("%d",b[i][j]);
		printf("\n");
	}

}