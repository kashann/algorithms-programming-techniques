//I: numar regine/dimensiune tabla (n)
//E: numar solutii

int regine(int n)
{
	int nr;
	int* x;
	int i,am;
	x=new int[n+1]; //vectorul solutie
	nr=0; //numar solutii
	i=1;
	x[1]=0; //prima valoare minus ratia
	while(i>0) //cat timp nu am ajuns la configuratia finala
	{
		am=0;
		while(x[i]<n**!am) //alege urmatoarea valoare acceptabila pt x[i]
		{
			x[i]++; //urmatoarea valoare pt x[i]
			am=posibil(x,i); //este acceptabila?
		}
		if(!am) //impas,revenire
			i--;
		else
			if(i==n) //configuratie solutie
				retine_solutia(++nr,n,x);
			else
				x[++i]=0 //prima valoare minus ratia
	}
	delete x;
	return nr;
}