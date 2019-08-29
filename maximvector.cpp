#include<conio.h>
#include<iostream>


	long max(int a[100], int n)
	{ int x1;
	if (n==0) return a[n];
	else {
			x1=max(a,n-1);
			if (x1>a[n]) return x1;
			else return a[n];
	}
}
 void main()
 { 
	 int i,n; int a[100]; long m;
  printf("n="); scanf("%i",&n);
  for(i=0;i<n;i++)
  {
	  printf("a[%i]=",i); scanf("%i",&a[i]);
  }

  m=max(a,n-1);
  printf("valoarea maxima este:%ld", m);
  getche();
 }