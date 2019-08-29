#include <conio.h>
#include <iostream>
 
 long suma( long v[], int n)
{ 
	if (n==0) return 0;
	else return v[n-1] + suma(v,n-1);
}
void main()
{
	int n,i; long s,a[10];
	printf("n="); scanf("%d", &n);
	for (i=0; i<n;i++)
	{printf("a[i]="); scanf("%d", &a[i]);}
	

	s=suma(a,n);
	printf("valoarea sumei este:%ld", s);
	getche();
}
