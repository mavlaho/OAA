#ifndef FLOYDWARSHALL_H
#define FLOYDWARSHALL_H

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <limits>


template <typename REAL>
void findMinDistances( int Nvertices , REAL **w , REAL **d )
{
	for(int i=0; i<Nvertices; ++i)
		for(int j=0; j<Nvertices; ++j)
			d[i][j] = ( (i==j) ? 0 : w[i][j] );

	for(int k=0; k<Nvertices; ++k)
	    for(int i=0; i<Nvertices; ++i)
			for(int j=0; j<Nvertices; ++j)
				d[i][j] = std::min( d[i][j] , d[i][k]+d[k][j] );
}

template <typename T>
T** allocMat(int m, int n)
{
    T ** mat;
    mat = new T*[m];
    for(int i=0; i<m; ++i)
        mat[i] = new T[n];

    return mat;
}

template <typename T>
void deallocMat(T **mat, int m, int n)
{
    for(int i=0; i<m; ++i)
        delete[] mat[i];

    delete[] mat;
}


bool readData( const char * inFile , int * Nvertices , double *** w )
{

	constexpr auto inf = std::numeric_limits<double>::infinity();


    FILE *fp = fopen( inFile , "r" );
    if( !fp ) return false;

    if( fscanf(fp," %d",Nvertices) != 1 ) return false;


    *w = allocMat<double>(*Nvertices,*Nvertices);


    for(int i=0; i<*Nvertices; ++i)
    {
        for(int j=0; j<*Nvertices; ++j)
        {

            char buffer[1024];
            fscanf(fp," %s",buffer);

            if( strcmp(buffer,"inf")==0 )
                (*w)[i][j] = +inf;
            else
            {
                if( sscanf(buffer," %lf",&(*w)[i][j]) != 1 ) return false;
            }
        }
    }

    return true;
}



#endif // FLOYDWARSHALL_H


