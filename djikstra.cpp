typedef struct {
	float cost;
	int varf;
#define INF 100000
}ETICHETA;
//date intrare: nr de varfuri, matricea ponderilor, varful initial
//date iesire: vector de etichete
eticheta* dijkstra (int n, float** a, int )
{ 
	int *A, *B;	
	int i, j, poz, la, lb;
	eticheta* r;
	r = new ETICHETA[n];
	for (i=0;i<n;i++)
		r[i].cost=INF;
	r[u0-1].cost=0;
	r[u0-1].varf=-1;
	A=new int[n];
	A[0]=u0;
	la=1;
	B=new int[n-1];
	lb=0;
	for (i=1;i<=n;i++)
		if (i!=u0)
			{	B[lb]=i;
				lb++;
			}
	for (i=1;i<n;i++)
	{
		for (j=0;j<lb;j++)
			if (r[B[j]-1].cost > r[A[la-1]-1].cost+m[A[la-1]-1][B[j]-1])
			{
				r[B[j]-1].cost=r[A[la-1]-1].cost+m[A[la-1]-1][B[j]-1];
				r[B[j]-1].varf=A[la-1];
			}
	poz=0;
	for (j=0;j<lb;j++)
		if (r[B[j]-1].cost<r[B[poz]-1].cost) 
			poz=j;
	A[la++]=B[poz];
	for (j=poz+1; j<lb;j++)
			B[j-1]=B[j];
	lb--;
	delete A;
	delete B;
	return r;
	}
		
