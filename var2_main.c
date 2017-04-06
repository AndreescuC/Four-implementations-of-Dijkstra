#include "(var2)header.h"

int main()
{
	long long count =0;
    int n, sursa, destinatie, i, **A, *path, size = 0;
    n = read_and_initialize( "dijkstra.in", &A, &sursa, &destinatie, &count);
    Dijkstra_var2(A, sursa, destinatie, n, count);
return 0;
}	