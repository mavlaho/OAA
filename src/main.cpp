#include <cstdio>
#include <algorithm>
#include <limits>
#include "debug.hh"
#include "floydwarshall.hh"



int main( int argc , char *argv[] )
{
	constexpr double inf = std::numeric_limits<double>::infinity();


	// Primjer s prezentacije
	constexpr std::size_t Nvertices = 4;

    auto w = allocMat<double>(Nvertices,Nvertices);

    w[0][0] = 0;
    w[0][1] = +inf;
    w[0][2] = -2;
    w[0][3] = +inf;

    w[1][0] = +4;
    w[1][1] = +0;
    w[1][2] = +3;
    w[1][3] = +inf;

    w[2][0] = +inf;
    w[2][1] = +inf;
    w[2][2] = +0;
    w[2][3] = +2;

    w[3][0] = +inf;
    w[3][1] = -1;
    w[3][2] = +inf;
    w[3][3] = +0;


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
