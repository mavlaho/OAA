#include <cstdio>
#include <algorithm>
#include <limits>
#include "debug.hh"




int main( int argc , char *argv[] )
{
	constexpr double inf = std::numeric_limits<double>::infinity();


	// Primjer s prezentacije
	constexpr std::size_t Nvertices = 4;
	
	const double w[Nvertices][Nvertices] = { {   +0 , +inf ,   -2 , +inf } ,
											 {   +4 ,   +0 ,   +3 , +inf } ,
											 { +inf , +inf ,   +0 ,   +2 } ,
											 { +inf ,   -1 , +inf ,   +0 }
										   };
	
	
	double d[Nvertices][Nvertices];
	for(int i=0; i<Nvertices; ++i)
		for(int j=0; j<Nvertices; ++j)
			d[i][j] = ( (i==j) ? 0 : w[i][j] );
	for(int k=0; k<Nvertices; ++k)
	    for(int i=0; i<Nvertices; ++i)
			for(int j=0; j<Nvertices; ++j)
				d[i][j] = std::min( d[i][j] , d[i][k]+d[k][j] );
	
	
	for(int i=0; i<Nvertices; ++i)
	{	for(int j=0; j<Nvertices; ++j)
			printf("%6.2f" , d[i][j]);
		printf("\n");
	}
			
    return 0;
}
