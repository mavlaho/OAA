#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "debug.hh"


constexpr int MaxNvertices = 10000;		
double w[MaxNvertices][MaxNvertices];
double d[MaxNvertices][MaxNvertices];
	

int main( int argc , char *argv[] )
{
	srand(0);
	

	
	printf("[\n");
	for(int Nvertices = 1000 ; Nvertices<=MaxNvertices; Nvertices+=100)
	{
		for(int i=0; i<Nvertices; ++i)
			for(int j=0; j<Nvertices; ++j)
				w[i][j] = double(rand())/RAND_MAX;
		
		
		
		clock_t start = clock();
		for(int irun=0; irun<1; ++irun )
		{
			for(int i=0; i<Nvertices; ++i)
				for(int j=0; j<Nvertices; ++j)
					d[i][j] = ( (i==j) ? 0 : w[i][j] );
			for(int k=0; k<Nvertices; ++k)
				for(int i=0; i<Nvertices; ++i)
					for(int j=0; j<Nvertices; ++j)
						if( d[i][k]+d[k][j] < d[i][j] ) 
							d[i][j] = d[i][k]+d[k][j];
		}
		clock_t end = clock();
		double time = double(end-start)/CLOCKS_PER_SEC;
		
		printf("%d , %f ; ...\n", Nvertices, time);
	}
	printf("];");
	
	

    return 0;
}
