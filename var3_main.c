#include "(var3)header.h"
#include"(var3)struct.h"

int main()
{
	long long count=0;
    int n, sursa, destinatie, i;
    nod* *v;
    n = read_and_initialize( "dijkstra.in", &v, &sursa, &destinatie,&count);
    nod *puppet;
    Dijkstra_var3(v, sursa, destinatie, n, count);
return 0;
}	