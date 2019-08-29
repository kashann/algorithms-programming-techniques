Sa se calculeze n! in varianta recursiva.
// factorial(3)=3*factorial(2)=3*2*factorial(1)=3*2*1
#include<stdio.h>
long int factorial (int n)
{
	if (n==1) return 1;
	else return n*factorial(n-1);
}
void main()
{
	int n;
	printf("Introduceti n= ");
	scanf("%d", &n);
	
	if(!n)
		printf("0!=1\n");
	else
		printf("%d!=%ld\n",n,factorial(n));
 
 	getchar();
  	int var;
  	scanf("%d", var);
}


Sa se scrie un program C, pentru rezolvarea cmmdc-ului a n numere întregi fara semn 
(pentru determinarea cmmdc-ului vom folosi algritmul lui Euclid prin scaderi). Varianta recursiva.


#include <stdio.h>
#include <conio.h>

unsigned int cmmdc_2(unsigned int a, unsigned int b)
{
	if(a==b) return a;
	if(a>b) return cmmdc_2(a-b,b);
	else
	return cmmdc_2(a,b-a);
}
unsigned int cmmdc_n(unsigned int x[], int n)
{
	if (n==2) return cmmdc_2(x[0],x[1]);
	else	return cmmdc_2(cmmdc_n(x,n-1),x[n-1]);
}
void main()
{
	unsigned int x[20];
	int n;
	printf("Introduceti n: "); 
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("elementul %d= ",i+1);
		scanf("%u",&x[i]);
	}
	if (n==1)
	printf("\nCmmdc-ul numerelor: %u",x[0]);
	else
	printf("\nCmmdc-ul numerelor: %u",cmmdc_n(x,n));
 
	getch();
}



//adunarea componentelor unui sir varianta recursiva
int suma(vector x,int n) //n in acest caz il consideram fiind indice element dinsir
{
if(n==-1) return 0; //situatia in care nu mai sunt elemente in sir, pozitia n=-1  nefiind in sir
	else return x[n]+suma(x,n-1);
}
//produsul componentelor unui vector varianta recursiva
int produs(vector x,int n)
{
	if(n==-1) return 1;
	else return x[n]*produs(x,n-1);
}

//media aritmetica a componentelor sirului varianta recursiva
float media(vector x, int m, int n) //cu m am notat indicele elementelor, iar cu n dimensiunea reala a sirului
{
	return (float)x[m]/n + ((m!=0)?media(x,m-1,n):0);
	/* - am folosit expresia (float) pentru o conversie explicita a rezultatului
	spre un tip real
	- prin x[m]/n intelegem un element (in prima faza, acesta fiind ultimul
	element din sir) impartit la numarul total de componente */
}




Se considera sirul lui Fibonacci (Un) definit astfel: 	 0, n=0
Un=      1, n=1
	 Un-1+Un-2, altfel

 Se citeste n, un numar natural. Sa se calculeze Un, in varianta recursiva.

#include<stdio.h>
#include<conio.h>

int U (int n)
{
	if (!n) return 0;
	else	if (n==1) return 1;
	else	return U(n-1)+U(n-2);
}
 
void main()
{
	int n;
	printf("Introduceti n=");	
	scanf("%d",&n);
 
	printf("Valoarea sirului in n este: %d",U(n));
 
	getch();

}

