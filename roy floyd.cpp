#include<conio.h>
#include<stdio.h>

//roy floyd


int rf(int a[100][100], int n, int m[100][100],int max)
{
	int i,j,k;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			m[i][j]=a[i][j];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(m[i][j]<max)
				for(k=0;k<n;k++)
					if(m[i][k]>m[i][j]+m[j][k])
						m[i][k]=m[i][j]+m[j][k];
	return m[i][j];

}


void main()
{
	
   int i,j,n,a[100][100],m[100][100],max=100;
   printf("n=");
   scanf("%i",&n);
   for(i=0;i<n;i++)
    for(j=0;j<n;j++)
		scanf("%i", &a[i][j]);
    rf(a,n,m,max);
    for(i=0;i<n;i++)
        {for(j=0;j<n;j++)
            printf("%i",m[i][j]);
            printf("\n");}
	_getch();
}
