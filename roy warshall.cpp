// seminar11.cpp
/*
A=      0 1 1 1
	1 0 0 0
	1 0 0 1
	1 0 1 0

	aij= max(aij,min(aik, akj))
k=0;
	i=0;
		j=0;

		a00=0;
		a00=max(a00,min(a00,a00));

j=1; a01=1
j=2; a02=1
j=3; a03=1

i=1
j=0 a10=1
j=1 a11=max(a11(min(a10,a01)=1
.........
rezulta matricea inversa

A^(-1) = 0 1 1 1 
		 1 1 1 1
		 1 1 1 1 
		 1 1 1 1

A^(-2)= 1 1 1 1 
		1 1 1 1
		1 1 1 1
		1 1 1 1




*/

#include<stdio.h>
#include<conio.h>
#include<malloc.h>

void citire(int ***a, int *n)
{
	int i,j, nm,vi,vf;
	printf("n="); scanf_s("%d",&(*n));
	*a=(int**)malloc((*n)*sizeof(int*));
	for (i=0;i<(*n);i++)
		*(a+i)=(int**)malloc((*n)*sizeof(int));
	for (i=0;i<(*n);i++)
		for (j=0;j<(*n);j++)
			*(*((*a)+i)+j)=0;
	printf("nm="); scanf_s("%d", &nm);
	for (i=0;i<nm;i++)
	{
		printf("vi="); scanf_s("%d", &vi);
		printf("vf="); scanf_s("%d", &vf);
		(*a)[vi-1][vf-1]=(*a)[vf-1][vi-1]=1;
	}
}
void afisare(int **a, int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		printf("%d", a[i][j]);
	printf("\n");
	}
}

void Roy_Warshal(int **a, int ***m, int n)
{
	int i,j,k;
	//int **m;

	(*m)=(int**)malloc(n*sizeof(int*));
	for (i=0;i<n;i++)
	*(a+i)=(int*)malloc(n*sizeof(int));

	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			(*m)[i][j]=a[i][j];

	for (k=0;k<n;k++)
		for(i=0;i<n;i++)
			for (j=0;j<n;j++)
				if((*m)[i][j]==0) (*m)[i][j]=(*m)[i][k]*(*m)[k][j];
}

int **Roy_Warshal1 (int **a, int n)
{
	int i,j,k;
	int **m;
	m=(int**)malloc(n*sizeof(int*));
	for(i=0;i<n;i++)
		*(m+i)=(int*)malloc(n*sizeof(int));
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			m[i][j]=a[i][j];
	for(k=0;k<n;k++)
		for (i=0;i<n;i++)
			for (j=0;j<n;j++)
				if(a[i][j]==0) 
					m[i][j]=m[i][k]*m[k][j];
	return m;
}
void main()
{
	int **a,n,**b,**c;
	citire(&a,&n);
	afisare(a,n);
	Roy_Warshal(a,&b,n);
	afisare(b,n);
	c=Roy_Warshal1(a,n);
	afisare(b,n);
}


void Roy_W(int a[][100], int n, int m[][100]) //din manual
{
	int i,j,k;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			m[i][j]=a[i][j];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(m[i][j]==0)
				for(k=0;k<n;k++)
					if(m[i][k]&&m[k][j])
						m[i][j]=1;
}