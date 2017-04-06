void add(int heap[], int *dist, int n, int x, long long *count)
{
	int i;
	int aux;
	int parent;
	long long c=0;
	for(i=0; i<n; i++)
	{
		c=c+6;
		if(heap[i] == x)
		{
			*count = *count + c;
			return;
		}
		if(heap[i] == -1)
			break;
	}
	heap[i] = x;
	c=c+3;
	if(i == 0)
	{
		*count = *count + c;
		return;
	}
	parent = (i+1)/2 -1;
	c=c+4;
	while( (i != 0) && (dist[x] < dist[ heap[parent] ]) )
	{
		c=c+6;
		aux = heap[i];
		heap[i] = heap[parent];
		heap[parent] = aux;
		i = parent;
		parent = (i+1)/2 -1; 
		c=c+12;
	}
	*count=*count +c;
}