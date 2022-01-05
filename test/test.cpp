#include <cstdio>
#include <algorithm>
#include <limits>
#include "debug.hh"
#include "floydwarshall.hh"
#include <cstdio>


int main( int argc , char *argv[] )
{

    int Nvertices;
    double ** w;

    if( !readData( "./in/test.in" , &Nvertices , &w ) )
    {
        printf("reading from input file failed!\n");
        exit(1);
    }

    auto d = allocMat<double>(Nvertices,Nvertices);

    findMinDistances(Nvertices, w, d);

	for(int i=0; i<Nvertices; ++i)
	{	for(int j=0; j<Nvertices; ++j)
			printf("%6.2f" , d[i][j]);
		printf("\n");
	}


    deallocMat(w, Nvertices, Nvertices);
	deallocMat(d, Nvertices, Nvertices);

    return 0;
}
