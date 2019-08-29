#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

// generate random real numbers and write them to a text file
// I: n - nr. of values, min.max - range, name - file name
// E: -
void random_numbers(int n, double min, double max, char* name)
{
  int i;
  FILE* f;
  double r;
  // r= fisier existent; w= creeare de fisier nou; b= fisier binar; t= fisier text; a= deschide fisier existent de text.
  fopen_s(&f,name,"wt"); //deschide fisier; fopen(nume,mod); fopen_s(&f,nume,mod)
  for(i=0;i<n;i++)
  { r=rand()*(max-min)/(RAND_MAX+1)+min; // r= rand()* b-a/RAND_MAX+1 +a; un numar din intervalul 0-RandMax sa il bag in intervalul a-b
    fprintf_s(f,"%7.2lf ",r);
    // note that if the above write format is replaced with " %7.2lf" (space before number, no space after)
    // the file will end "abruptly" causing problems when numbers are read from file: last number will not be counted
    //it is best to comply to text file format: add newline and EOF after last number
    //fprintf_s(f,"\n%c",27);
  }
  fclose(f);
}
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!TEMA Refacem textul de mai sus, insa programul sa aiba o linie in plus (fprintf_s(f, \n) )!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// read numbers from text file into a dynamic vector
// I: name - file name
// E: v - address of vector (NULL if file cant be opened), n - nr. of elements
// version 1: use temporary storage for elements while traversing the file
//improvement: instead of static vector "a", allocated in stack, use a dynamically allocated vector
double* read_file_1(char* name, int*n)
{ FILE* f;
  int i;
  double* v, a[100];

  v=NULL;
  *n=0;
  fopen_s(&f,name,"r");
  if(f)
  { fscanf_s(f,"%lf",&a[0]);
    while(!feof(f))
    { (*n)++;
      fscanf_s(f,"%lf",&a[*n]);
    }
    fclose(f);
    v=new double[*n];
    for(i=0;i<*n;i++)
      v[i]=a[i];
  }
  return v;
}

// read numbers from text file into a dynamic vector
// I: name - file name
// E: v - address of vector (NULL if file cant be opened), n - nr. of elements
// version 2: no temporary storage, need to traverse the file 2 times: onece to count elements, once to store them in memory
double* read_file_2(char* name, int*n)
{ FILE* f;
  int i;
  double* v,a;

  v=NULL;
  *n=0;
  fopen_s(&f,name,"r");
  if(f)
  { //traverse file to count values
    fscanf_s(f,"%lf",&a);
    while(!feof(f))
    { (*n)++;
      fscanf(f,"%lf",&a);
    }
    rewind(f);
    v=new double[*n];
    *n=0;
    //traverse file to store values in memory
    fscanf_s(f,"%lf",&v[*n]);
    while(!feof(f))
      fscanf_s(f,"%lf",&v[++(*n)]);
    fclose(f);
  }
  return v;
}

// convert data in text file to binary file
// I: namet - name of text file, nameb - name of binary file
// E: er (0 - success, 1 - cannot open text file)
int convert(char* namet, char* nameb)
{ double a;
  FILE* f, *g;
  int er;

  fopen_s(&f,namet,"r");
  if(!f)
    er=1;
  else
  { er=0;
    fopen_s(&g,nameb,"wb");
    fscanf_s(f,"%lf",&a);
    while(!feof(f))
    { fwrite(&a,sizeof(double),1,g);
      fscanf_s(f,"%lf",&a);
    }
    fclose(f);
    fclose(g);
  }
  return er;
}

// read data from binary file and display on screen
// I: name - name of file
// E: er - 1 if file cant be opened, 0 otherwise
int display(char* name)
{ FILE* f;
  double a;
  int er;

  fopen_s(&f,name,"rb");
  if(!f)
  { er=1;
    printf_s("\nCant open binary file\n");
  }
  else
  { er=0;
    printf_s("\nReal numbers from binary file: \n");
    fread(&a,sizeof(double),1,f);
    while(!feof(f))
    { printf_s("%7.2lf ",a);
      fread(&a,sizeof(double),1,f);
    }
    fclose(f);
  }
  return er;
}

void main()
{
  int n,i,lx,er;
  char fname[20];
  char fnameb[20];
  double a,b;
  double* x;

  printf_s("\nNr.="); scanf_s("%d",&n);
  printf_s("\nMin="); scanf_s("%lf",&a);
  printf_s("\nMax="); scanf_s("%lf",&b); 
  printf_s("\nText file name="); fflush(stdin); gets_s(fname);  //fflush=goleste buffer-ul fisierului    //elimina enter-ul din buffer
  //printf_s("\nBinary file name="); fflush(stdin); gets_s(fnameb);

  random_numbers(n,a,b,fname);

  x=read_file_1(fname,&lx);
  //x=read_file_2(fname,&lx);
  if(!x)
    printf_s("\nCant open the file");
  else
  { printf_s("\nI have read %d elements:\n",lx);
    for(i=0;i<lx;i++)
      printf_s("%7.2lf ",x[i]);
    delete x;
  }

  /*er=convert(fname, fnameb);
  if(!er)
    printf_s("\nBinary file ready");
  else
    printf_s("\nCant open text file to convert data into binary");*/
 
  //er=display(fnameb);

  printf_s("\n\nDone. Press a key.");
  _getch();

}

//Cum verifica sfarsitul unui fisier:
//incearca citire ->x
// cat timp reuseste
// prelucreaza x               se numara, varianta cu 2 treceri; aloc un vector dinamic si scriu in el; rewind:trece la inceputul fisierului
// incearca citire ->x

//stdout= fisier standard de iesire, 
//stdin= fisier standard de intrare, asociat cu tastatura
// >> reasociaza iesirea
// << reasociaza iesirea
// gigel >>iesire.txt (o sa scrie in fisierul iesire.txt)
// gigel<<intrare.txt 
// gigel|ionel (iesirea de la aplicatia gigel este trimisa catre inceputul de la aplicatia ionel)
