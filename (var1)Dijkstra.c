#include"(var1)add_to_vec.c"
#include"(var1)del_from_vec.c"


void Dijkstra_var1(int **A, int sursa, int destinatie, int n, long long count)
{
	int i, j, prev[n], dist[n], vect[n], current, selectat[n];
	for(i=0; i<n; i++)
	{
		count=count+2;
		vect[i] = -1;
		prev[i] = -1;
		dist[i] = A[sursa][i];
		selectat[i] = 0;
		count=count+8;
	}
	selectat[sursa] = 1;
	prev[sursa] = sursa;
	dist[sursa] = 0;
	count=count+6;
	for(i=0; i<n; i++)
	{
		count=count+2;
		if( A[sursa][i] != -1 )
		{
			count=count+2;
			add(vect, dist, n, i, &count);
			prev[i] = sursa;
			count=count+2;
		}
	}
	while(vect[0] != -1)
	{
		count=count+2;
		current = pop(vect,n, &count);
		count=count+1;
		selectat[current] = 1;
		count=count+2;
		for(i=0; i<n; i++)
		{
			count=count+2;
			if( (A[current][i] != -1) && (selectat[i] == 0) && ((dist[i] >= dist[current] + A[current][i]) || (dist[i] == -1)) )
			{
				count=count+14;
				if(dist[i] == dist[current] + A[current][i])
				{	
					count=count+1;
					if(i < current)
						goto mark;
				}
				count=count+5;
				prev[i] = current;
				count=count+1;
mark:			
				dist[i] = dist[current] + A[current][i];
				count=count+5;
				add(vect, dist, n, i, &count);		
			}
		}
	}

	FILE *out;
    out = fopen("Dijkstra1.out","a");  
    fprintf(out, "*** Dijkstra1 - adjacency matrix & vector ***\n");
    fprintf(out, "Distance to destination : %d\n",dist[destinatie]);
	int path[n];
	int path_size = 0;
	i = destinatie;
	count=count+1;
	while(i != sursa)
	{
		path[path_size] = i;
		path_size++;
		i = prev[i];
	}
	path[path_size] = i;
	fprintf(out, "Path to destination : ");
	for(i=path_size; i>0; i--)
		fprintf(out, "%d ", path[i]);
	fprintf(out, "%d\n", path[0]);
	fprintf(out, "Number of basic operations performed : %llo", count);
	fclose(out);
}