#include"(var4)add_to_heap.c"
#include"(var4)del_from_heap.c"

void Dijkstra_var4(nod* v[], int sursa, int destinatie, int n, long long count)
{
	int i, j, current, prev[n], dist[n], selectat[n], heap[n];
	nod* puppet;	
	for(i=0; i<n; i++)
	{
		count = count+14;
		heap[i] = -1;
		prev[i] = -1;
		dist[i] = -1;
		selectat[i] = 0;
		puppet = v[sursa];
		puppet = puppet->next;	
		while(puppet != NULL)
		{
			count = count+5;
			if(puppet->val == i)
			{
				count = count+3;
				dist[i] = puppet->cost;
			}
			puppet = puppet->next;
		}	
	}
	selectat[sursa] = 1;
	prev[sursa] = sursa;
	dist[sursa] = 0;

	puppet = v[sursa];
	puppet = puppet->next;
	count = count+10;
	while(puppet != NULL)
	{
		count = count+6;
		add(heap, dist, n, puppet->val, &count);
		prev[puppet->val] = sursa;
		puppet = puppet->next;
	}
	while(heap[0] != -1)
	{
		count = count+9;
		current = pop(heap, dist, n,&count);
		selectat[current] = 1;
		puppet = v[current];
		puppet = puppet->next;
		while(puppet != NULL)
		{
			count = count+14;
			i = puppet->val;
			if( (selectat[i] == 0) && ( (dist[i] >= dist[current] + puppet->cost) || (dist[i] == -1) ) )
			{	
				count = count+7;
				if(dist[i] == dist[current] + puppet->cost)
				{
					count = count+1;
					if(i < current)
						goto mark;	
				}	
				prev[i] = current;
mark:			
				dist[i] = dist[current] + puppet->cost;
				add(heap, dist, n, i, &count);
				count = count+5;
			}
			puppet = puppet->next;
			count = count+2;
		}
	}	
	FILE *out;
    out = fopen("Dijkstra4.out","a");  
    fprintf(out, "*** Dijkstra1 - adjacency list & heap ***\nDistance to destination : ");
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
	fprintf(out, "Number of basic operations performed : %llo", count);
	fclose(out);
}