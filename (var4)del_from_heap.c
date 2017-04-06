int pop(int *heap, int *dist, int n, long long *count)
{
	long long c=0;
	int i, aux, ret = heap[0];
	c=c+2;
	for(i=0; i<n; i++)
	{
		c=c+4;
		if(heap[i] == -1)
			break;
	}
	heap[0] = heap[i-1];	
	heap[i-1] = -1;
	i = 0;
	c=c+7;
	while( ( (heap[(i+1)*2-1] != -1)&&(dist[ heap[i] ] > dist[ heap[(i+1)*2-1] ]) ) || ( (heap[(i+1)*2] != -1)&&(dist[ heap[i] ] >  dist[ heap[(i+1)*2] ]) )  )
	{
		c=c+31;
		if(heap[(i+1)*2] == -1)
			goto first;
		c=c+4;
		if(heap[(i+1)*2] == -1)
			goto second;
		c=c+10;
		if( dist[ heap[(i+1)*2-1] ] <  dist[ heap[(i+1)*2] ] )
		{
first:		c=c+24;
			aux = heap[(i+1)*2-1];
			heap[(i+1)*2-1] = heap[i];
			heap[i] = aux;
			i = (i+1)*2-1;
			if( ((i+1)*2-1 > n-1) || (heap[(i+1)*2-1] == -1) )
				break;
			continue;
		}
		else
		{
second:		c=c+25;
			aux = heap[(i+1)*2];
			heap[(i+1)*2] = heap[i];
			heap[i] = aux;
			i = (i+1)*2;
			if( ((i+1)*2-1 > n-1) || (heap[(i+1)*2-1] == -1) )
				break;
		}
	}
	*count = *count +c;
return ret;
}