#include <stdio.h>
#include <conio.h>

typedef struct {
	char cnp [14];
	char nume [40];
	unsigned int nrmat;
	unsigned int grupa;
	unsigned char an;
	unsigned char serie;
	unsigned char note[20];
	} student;
/*
void main ()
{
	FILE *a,*b;
	char n1[21],n2[21];
	student temp;
	printf_s("output: ");
	gets(n2);
	fopen_s(&b,n2,"wb");
	printf_s("fisier: "); //de concatenat
	gets(n1);
	while(!feof(stdin))
	{
		fopen_s(&a,n1,"rb");
		fread(&temp,sizeof(student),1,a)
			if(!a)
				printf_s("nasol cu %s",n1);
			else
			{
				while(!feof(a))
					{
						fwrite(7temp,sizeof(student),1,b);
						fread(&temp,sizeof(student),1,a);
					}
				fclose(a);
			}
		printf_s("fisier de concatenat: ");
		gets(n1);
	}
	fclose(b);
	printf_s("Gata!");
	_getch();
}
*/

//se scade 1 pct din nota la atp pt toti studentii din toate grupele care nu si au facut tema. 


void main ()
{
	FILE *f;
	char nume[20];
	student x;
	int gr;
	printf_s("\n Nume fisier: ");
	gets_s(nume);
	fopen_s(&f,nume,"rb+");
	if(!f)
		printf_s("\n Nu se poate deschide fisierul %s",nume);
	else
	{
		printf_s("\n Numar grupa:");
		scanf_s("%d",&gr);
		while(!feof(stdin))
		{
			rewind(f);
			fread(&x,sizeof(student),1,f);
			while(!feof(f))
			{
				if(x.grupa==gr&&x.nota[4]>1)
				{
					x.nota[4]--;
					fseek(f,ftell(f)-sizeof(student),SEEK_SET);
					fwrite(&x,sizeof(student),1,f);
				}
				fread(&x,sizeof(student),1,f);
			}
			printf_s("\n Nr grupa (sau ctrl z):");
			scanf_s("%d",&gr);
		}
		fclose(f);
		printf_s("\n\n Gata!");
	}
	printf_s("\n Apasa o tasta");
	_getch;
}
