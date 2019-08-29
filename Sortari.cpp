#include<stdio.h>
#include<conio.h>
#include<malloc.h>



void vector(int **v, int *n)
{
	int i;
	printf("Introduceti numarul de elmente n="); scanf_s("%d", &(*n));
	(*v) = (int*)malloc((*n)*sizeof(int));
	for (i = 0; i < (*n); i++)
	{
		printf("v[%d]=", i + 1); scanf_s("%d", &(*v)[i]);
	}

}

void matrice(int ***a, int *m, int *o)
{
	int i, j;
	printf("Numarul de linii="); scanf_s("%d", &(*m));
	printf("Numarul de coloane="); scanf_s("%d", &(*o));
	(*a) = (int**)malloc((*m)*sizeof(int*));
	for (i = 0; i < (*m); i++)
		(*a)[i] = (int*)malloc((*o)*sizeof(int));

	for (i = 0; i < (*m);i++)
	for (j = 0; j < (*o); j++)
	{
		printf("a[%d][%d]=", i + 1, j + 1); scanf_s("%d", &(*a)[i][j]);
	}

}

void afisarevector(int *v, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("v[%d]=%d  ", i + 1,v[i]);
	}
	printf("\n");
}

void afisarematrice(int **a, int m, int o)
{
	int i, j;
	printf("Matricea introdusa:\n");
	for (i = 0; i < m; i++)
	{for (j = 0; j < o; j++)

		printf("%4.1d", a[i][j]);
	printf("\n");
	}

}

void bubblesort(int *v, int n)
{
	int i, aux, p;
	p = 1;
	while (p == 1)
	{
		p = 0;
		for (i = 0; i < n - 1; i++)
		if (v[i] > v[i + 1])
		{
			aux = v[i];
			v[i] = v[i + 1];
			v[i + 1] = aux;
			p = 1;
		}
	}
	printf("Vectorul sortat prin bubblesort este:\n");
}

void insertie(int *v, int n)
{
	int i, j, poz, aux;
	printf("Vectorul sortat prin insertie este:\n");
	for (i = 1; i < n; i++)
	{
		j = i - 1; poz = i;
		while (j >= 0)
		{
			if (v[i] < v[j]) poz = j;
			j--;
		}
		aux = v[i];
		for (j = i; j > poz; j--) v[j] = v[j - 1];
		v[poz] = aux;
	}
}

void selectie(int *v, int n)
{
	int i,j, aux;
	printf("Vectorul sortat prin selectie este:\n");
	for (i = 0; i < n - 1;i++)
		for (j = i + 1; j < n;j++)
			if (v[i]>v[j])
				{
					aux = v[i];
					v[i] = v[j];
					v[j] = aux;
				}
}

void merge(int *v, int p, int m, int u){ //interclasare
	int i, j, k, l, t;
	float *z;
	(z) = (float*)malloc((u + 1)*sizeof(int*));
	i = p;           //primul element
	j = m + 1;      //uramatoru element dupa mijloc(m)
	k = 0;         //inceputul de la 0
	while ((i <= m) && (j <= u))
	{
		if (v[i] < v[j]){
			z[k] = v[i]; i++; k++;
		}
		else                           //Interclasarea vectorilor
		{
			z[k] = v[j]; j++; k++;
		}

	}
	if (i <= m)
	for (l = i; l <= m; l++){
		z[k] = v[l]; k++;
	}                             // Includerea elementelor ce au ramasa in unul din vectori
	if (j <= u)
	for (l = j; l <= u; l++){
		z[k] = v[l]; k++;
	}
	t = p;
	for (k = 0; k < (u - p) + 1; k++)
		v[t++] = z[k];
	free(z);
}
void dividimp(int *v, int p, int u)
{
	int m;                        //Dividem vectorul in subvectori pana ce ajungem la vectori de 2 elemente
	if (p < u){
		m = (p + u) / 2;
		dividimp(v, p, m);         // de la primul la mijloc
		dividimp(v, m + 1, u);     // de la mijloc spre sfarsit
		merge(v, p, m, u);
	}


}

void numarare(int *v, int l)
{
	int i, j, *num;
	double *temp;
	temp = (double*)malloc(l*sizeof(double));
	num = (int*)malloc(l*sizeof(int));
	for (i = 0; i<l; i++)
		num[i] = 0;
	for (i = 0; i<l; i++)
		temp[i] = v[i];
	for (i = 0; i<l - 1; i++)
	for (j = i + 1; j<l; j++)
		if (v[j]<v[i])
			num[i] = num[i] + 1;
		else num[j] = num[j] + 1;
	for (i = 0; i<l; i++)
		v[num[i]] = temp[i];
	free(temp);
	free(num);
	printf("Vectorul sortat prin numarare este:");
}

void quicksort(int *v, int stanga, int dreapta)
{

		int i, j, mijloc, aux;
		i = stanga;
		j = dreapta;
		mijloc = v[(stanga + dreapta) / 2];
		while (i <= j)
		{
			while (v[i]<mijloc)
				i = i + 1;
			while (v[j]>mijloc)
				j = j - 1;
			if (i <= j)
			{
				aux = v[i]; v[i] = v[j]; v[j] = aux;
				i = i + 1; j = j - 1;
			}
		}
		if (stanga<j) quicksort(v, stanga, j);
		if (i<dreapta) quicksort(v, i, dreapta);
		printf("Vectorul sortat prin QuickSort este \n");
}



void main()
{
	int *v, **a, n, m, o,optiune;
	//n- numarul elemente vector
	//m- numarul de linii matrice
	//o- numarul de coloane matrice
	vector(&v, &n);
	printf("\n");
	printf("Vectorul introdus este:\n");
	afisarevector(v, n);
	printf("______________\n");
	printf("|    Meniu   |\n");
	printf("--------------\n");
	printf("1)Pentru Bubble Sort tastati 1\n");
	printf("2)Pentru Sortare prin selectie tastati 2\n");
	printf("3)Pentru Sortare prin insertie tastati 3\n");
	printf("4)Pentru Sortare prin interclasare tastati 4\n");
	printf("5)Pentru Sortare prin numarare tastati 5\n");
	printf("6)Pentru Sortare Rapida tastati 6\n");
	printf("Optiune -- "); scanf_s("%d", &optiune);
	switch (optiune)
	{
	case 1:
		bubblesort(v, n);
		break;
	case 2:
		selectie(v, n);
		break;
	case 3:
		insertie(v, n);
		break;
	case 4:
		printf("Vectorul sortat prin Interclasare este:");
		dividimp(v, 0, n - 1);
		break;
	case 5:
		numarare(v, n);
	case 6:
		quicksort(v, 0, n - 1);
		break;
	default:
		printf("Introduceti o optiune valida");

	}

	printf("\n");
	afisarevector(v, n);


}
