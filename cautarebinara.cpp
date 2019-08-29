#include<conio.h>
#include<iostream>

int cauta( int v[], int p, int u, int k)
{
	int m;

	if (p>u) return -1;
	else {
			m=(p+u)/2;
			if (k<v[m]) return cauta(v,m-1,u,k);
			else if (k>v[m]) return cauta(v,p,m+1,k);
	}
}

void main()
{
	int a[100],n,i,p,u,k; float C;
    
	printf("n="); scanf("%i",&n);
	printf("u="); scanf("%i",&u);
	printf("p="); scanf("%i",&p);
	printf("k="); scanf("%i",&k);
	for(i=0;i<n;i++)
	{ printf("a[i]="); scanf("%i",&a[i]);}
	C=cauta(a,p,u,k);
	printf("rezultatul final este:%f", C);
	getche();
	}