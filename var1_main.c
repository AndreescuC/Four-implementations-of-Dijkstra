#include "(var1)header.h"

int main()
{
	//clock_t start,end;
	//start=clock();
	long long count=0;
    int n, sursa, destinatie, **A;
    n = read_and_initialize( "dijkstra.in", &A, &sursa, &destinatie, &count);
    Dijkstra_var1(A, sursa, destinatie, n, count);
   // end=clock();
	//double t=(double)(end-start);
	//printf("\n\n%lf\n",t);
	//int Digs = DECIMAL_DIG;
	//printf("%Lf", (long double)(end-start));
return 0;
}	