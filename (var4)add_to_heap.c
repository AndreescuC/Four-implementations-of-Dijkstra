void add(int heap[], int *dist, int n, int x, long long *count)
{
	long long c=0;
	int i;
	int aux;
	int parent;	
	for(i=0; i<n; i++)
	{
		c=c+4;
		if(heap[i] == x)
		{
			*count = *count +c;
			return;
		}
		c=c+2;
		if(heap[i] == -1)
			break;
	}
	c=c+3;
	heap[i] = x;
	if(i == 0)
	{
		*count = *count +c;
		return;
	}
	parent = (i+1)/2 -1;
	c=c+4;
	while( (i != 0) && (dist[x] < dist[ heap[parent] ]) )
	{
		c=c+18;
		aux = heap[i];
		heap[i] = heap[parent];
		heap[parent] = aux;
		i = parent;
		parent = (i+1)/2 -1; 
	}
	*count = *count +c;
}