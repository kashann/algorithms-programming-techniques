#include <stdio.h>
#include <conio.h>

typedef struct {
			char CNP [14];
			char nume [10];
			unsigned int nrmat;
			unsigned int gr;
			unsigned char an;
			char s;
			unsigned char note [20];
			}STUDENT;
/*
void main();
{
	FILE*f;
	STUDENT x;
	int i;
	char nume [20];
	printf_s("\n Nume fisier: ");
	gets_s(nume);
	fopen_s(&f,nume,"wb");
	printf_s("\n CNP (sau CTRL+Z): ");
	gets_s(x.CNP);
	while(!feof(stdin))
	{
		printf_s("Nume: ");
		gets_s(x.nume);
		printf_s("Nr matricol: ");
		scanf_s("%d",&x.nrmat);
		printf_s("Nr grupa: ");
		scanf_s("%d",&x.gr);
		printf_s("An: ");
		scanf_s("%d",&x.an);
		printf_s("Serie: ");
		fflush(stdin);
		x.s=_getch();
		for(i=0;i<20;i++)
			x.note[i]=0;
		fwrite(&x,sizeof(STUDENT),1,f);
		printf_s("\n\n CNP (sau CTRL+Z): ");
		fflush(stdin);
		gets_s(x.CNP)
	}
	felse(f);
	printf_s("\n\n Gata! Am creat fisierul %s",nume);
	printf_s("\n Acum apasa o tasta...");
	_getch();
}
*/

// /*
void main();
{
	FILE*f*g;
	STUDENT x;
	int i,nrcrt;
	char nume [20], numetext [20];
	printf_s("\n Nume fisier: ");
	gets_s(nume);
	fopen_s(&f,nume,"rb");
	if(!f)
		printf_s("\n Nu pot deschide fisierul %s",nume);
	else
	{
		printf_s("\n Nume fisier text: ");
		gets_s(numetext);
		fopen_s(&g,numetext,"wt");
		fprintf_s("\t\t Lista studenti: ");
		fprintf_s("\n\n nrcrt %-13s %-40s nrmat an grupa s note","CNP","Nume si Prenume");
		nrcrt=0;
		fread(&x,sizeof(STUDENT),1,f);
		while(!feof(f))
		{
			fprintf_s(g,"\n %3d %-13s %-40s %5d %2d %5d %c ",++nrcrt,x.CNP,x.nume,x.nrmat,x.an,x.grupa,x.s);
			for(i=0;i<20;i++)
				fprintf_s(g,"%2d ",x.note[i]);
			fread(&x,sizeof(STUDENT),1,f);
		}
		fclose(f);
		fclose(g);
		printf_s(\n\n Gata! Lista se afla in fisierul %s",numetext);
	}
	printf_s("\n\n Apasa o tasta...");
	_getch();
}
//*/