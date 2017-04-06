#include"(var2)add_to_heap.c"
#include"(var2)del_from_heap.c"
#include"print_structures.c"

void Dijkstra_var2(int **A, int sursa, int destinatie, int n, long long count)
{
	int i, j, prev[n], dist[n], current, selectat[n], heap[n];	
	for(i=0; i<n; i++)
	{
		selectat[i] = 0;
		heap[i] = -1;
		prev[i] = -1;
		dist[i] = A[sursa][i];
		count=count+11;
	}
	selectat[sursa] = 1;
	prev[sursa] = sursa;
	dist[sursa] = 0;
	count=count+6;
	for(i=0; i<n; i++)
	{
		count=count+4;
		if( A[sursa][i] != -1 )
		{
			add(heap, dist, n, i, &count);   
			prev[i] = sursa;
			count=count+2;
		}
	}
	while(heap[0] != -1)                             
	{
		count=count+2;
		current = pop(heap, dist, n, &count);	
		count=count+1;
		selectat[current] = 1;
		count=count+2; 
		for(i=0; i<n; i++)
		{
			count=count+16;
			if( (A[current][i] != -1) && (selectat[i] == 0) && ((dist[i]>= dist[current] + A[current][i]) || (dist[i] == -1)) )
			{
				count=count+5;
				if(dist[i] == dist[current] + A[current][i])
				{
					count=count+1;
					if(i < current)
						goto mark;
				}
				prev[i] = current;
				count=count+2;
mark:			
				dist[i] = dist[current] + A[current][i];
				count=count+5;
				add(heap, dist, n, i, &count);				
			}
		}
	}	
	FILE *out;
    out = fopen("Dijkstra2.out","a");  
     fprintf(out, "*** Dijkstra2 - adjacency matrix & heap ***\nDistance to destination : ");
    fprintf(out, "%d\n",dist[destinatie]);
	int path[n];
	int path_size = 0;
	i = destinatie;
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
	fprintf(out, "Number of basic operations performed: %llo", count);
	fclose(out);
}