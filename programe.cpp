//factorial

int factorial(int n)
{
	if(n==0)
		return 1;
	else
		return n*factorial(n-1);
}

void main()
{
	int n;
	printf_s("n=");
	scanf_s("%d",&n);
	printf_s("%d",factorial(n));
	_getch();
}



//numarul de zerouri dintr-un vector

int zerouri(int x[100],int n)
{
	int i, nr=0;
	for(i=0;i<n;i++)
		if(x[i]==0)
			nr++;
	return nr;

}

void main()
{
	int n,i,x[100];
	printf_s("n=");
	scanf_s("%d",&n);
	for(i=0;i<n;i++)
	{
		printf_s("x[%d]=",i);
		scanf_s("%d",&x[i]);
	}
	
	printf_s("Avem %d zerouri in vector",zerouri(x,n));
	_getch();

}



//fibonacci

int fibonacci(int n)
{
	if(n==0||n==1)
		return 1;
	else
		return fibonacci(n-1)+fibonacci(n-2);
}

void main()
{
	int n;
	printf_s("n=");
	scanf_s("%d",&n);
	printf_s("%d",fibonacci(n));
	_getch();

}


//ackermann

int ack(int m,int n)
{
	if(m==0)
		return n+1;
	if(n==0)
		return ack(m-1,1);
	else
		return ack(m-1,ack(m,n-1));
}

void main()
{
	int m,n;
	printf_s("n=");
	scanf_s("%d",&n);
	printf_s("m=");
	scanf_s("%d",&m);
	printf_s("%d",ack(m,n));
	_getch();
}



//suma elem dintr-un vector

int suma(int x[100],int n)
{
	int i,s=0;
	for(i=0;i<n;i++)
		s=s+x[i];
	return s;
}


void main()
{
	int n,i,x[100];
	printf_s("n=");
	scanf_s("%d",&n);
	for(i=0;i<n;i++)
		scanf_s("%d",&x[i]);
	printf_s("Suma este=%d",suma(x,n));
	_getch();
}



//suma elem dintr-un vector (recursiv)

int suma(int x[100],int n)
{
	int i;
	for(i=0;i<n;i++)
		if(n==0)
			return 0;
		else
	return x[n-1]+suma(x,n-1);
}


void main()
{
	int n,i,x[100];
	printf_s("n=");
	scanf_s("%d",&n);
	for(i=0;i<n;i++)
		scanf_s("%d",&x[i]);
	printf_s("Suma este=%d",suma(x,n));
	_getch();
}



//suma maxima dintr-un vector

int suma_max(int x[100],int n)
{
	int i,s=0;
	for(i=0;i<n;i++)
		if(x[i]>0)
			s=s+x[i];
	return s;
}

void main()
{
	int n,i,x[100];
	printf_s("n=");
	scanf_s("%d",&n);
	for(i=0;i<n;i++)
		scanf_s("%d",&x[i]);
		printf_s("Suma maxima este:%d",suma_max(x,n));
	_getch();

}



//combinari

int comb(int n,int k)
{
	if(k>n)
		return 0;
	if(k==0||k==n)	
		return 1;
	else
		return comb(n-1,k)+comb(n-1,k-1);
}

void main()
{
	int n,k;
	printf_s("n=");
	scanf_s("%d",&n);
	printf_s("k=");
	scanf_s("%d",&k);
	printf_s("%d",comb(n,k));
	_getch();
}



//compunere de functii

float f(float x)
{
	if(x<5)
		return 2*pow(x,3)+1;
	if(x>=5&&x<=8)
		return pow(x,4)+2;
	if(x>8)
		return 3;
}

float g(float x)
{
	if(x<=1)
		return 5*pow(x,2)-3*x+2;
	if(x>1)
		return pow(x,3)-x+5;
}

float h(float x)
{
	return f(g(f(x)));
}

void main()
{
	int x;
	printf_s("x=");
	scanf_s("%f",&x);
	printf_s("%f",h(x));
	_getch();
}



//cmmdc

int cmmdc(int a,int b)
{
	if(a=b)
		return a;
	if(a>b)
		return cmmdc(a-b,b);
	if(b>a)
		return cmmdc(a,b-a);
}

void main()
{
	int a,b;
	printf_s("a=");
	scanf_s("%d",&a);
	printf_s("b=");
	scanf_s("%d",&b);
	printf_s("%d",cmmdc(a,b));
	_getch();
}



//aranjamente

int aranjmente(int n,int k)
{
	int a;
	if(k==1)
		a=n;
	else
		a=n*aranjamente(n-1,k-1);
	return a;
}

void main()
{
	int nr, citire, ar;
	ar = aranjamente(nr,citire);
}



//recursiv suma elemente

double suma_r(double v[],int l)
{
	double s;
	if(l==0)
		s=0;
	else
		s=v[l-1]+suma_r(v,l-1);
	return s;
}

void main()
{
	double *v,sum;
	int n;
	sum=suma_r(v,n);
}



//sortare bule

void sort_bule(double v[],int l)
{
	i, gata;
	double a;
	gata = 0;
	while(!gata)
	{
		gata=1;
		for(i=0;i<l-1;i++)
			if(v[i]>v[i+1])
			{
				gata=0;
				a=v[i];
				v[i]=v[i+1];
				v[i+1]=a;
			}
	}
}

void main()
{
	double v[20};
	int n;
	sort_bule(v,n);
}



//sortare interschimbare

void sort_intershimbare(double v[], int l)
{
	int i,j;
	double a;
	for(i=0;i<l-1;i++)
		for(j=i+1;j<l;j++)
			if(v[i]>v[j])
			{
				a=v[i];
				v[i]=v[j];
				v[j]=a;
			}
}

void main()
{
	double v[20];
	int n;
	sort_interschimbare(v,n);
}



//sortare selectie

void sort_selectie(double v[],int l)
{
	int i,j,p;
	double a;
	for(i=0;i<l-1;i++)
	{
		p=i;
		for(j=i+1;j<l;j++)
			if(v[j]<v[p])
				p=j;
		a=v[p];
		v[p]=v[i];
		v[i]=a;
	}
}

void main()
{
	Double v[20];
	int n;
	sort_selectie(v,n);
}



//sortare numarare

void sort_numarare(double v[] ,int l)
{
	int i,j,*num;
	double *temp;
	temp=(double*)malloc(l*sizeof(double));
	num=(int*)malloc(l*sizeof(int));
	for(i=0;i<l;i++)
		num[i]=0;
	for(i=0;i<l-1;i++)
		for(j=i+1;j<l;j++)
			if(v[j]<v[i])
				num[i]++;
			else
				num[j]++;
	for(i=0;i<l;i++)
		temp[num[i]]=v[i];
	for(i=0;i<l;i++)
		v[i]=temp[i];
	free(temp);
	free(num);
}

void main()
{
	double v[20];
	int n;
	sort_numarare(v,n);
}



//sortare shell

void sort_shell(double v[], int l)
{
	int i,j,inc;
	double a;
	for(incl/2;inc>0;inc=inc/2)
		for(i=inc;i<l;i++)
			for(j=i-inc;(j>=0)&&(v[j]>v[j+inc]);j=j-inc)
			{
				a=v[j];
				v[j]=v[j+inc];
				v[j+inc]=a;
			}
}

void main()
{
	Double v[20];
	int n;
	sort_shell(v,n);
}



//sortare elemente de pe linia k

void sort_linie_m(double **a,int m,int n,int k)
{
	int i,j,gata;
	double t;
	gata=0;
	while(!gata)
	{
		gata=1;
		for(i=0;i<n-1;i++)
			if(a[k][i]>a[k][i+1])
				for(j=0;j<n;j++)
				{
					t=a[j][i];
					a[j][i]=a[j][i+1];
					a[j][i+1]=t;
					gata=0;
				}
	}
}

void main()
{
	
}