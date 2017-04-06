void add(int v[], int dist[], int n, int elem,long long *count)
{
	int i=0;
	long long c=0;
	if(v[0] == -1)
	{	
		v[0] = elem;
		c=c+3;
		*count = *count + c;
		return;
	}
	while( (v[i] != -1) && (i < n) )
	{	
		c=c+5;
		if( v[i] == elem)
			break;	
		i ++;
		c=c+1;
	}
	int j=i-1;
	c=c+2;
	while( (j>=0) && (dist[ v[j] ] > dist[elem] ) )
	{	
		c=c+6;
		v[j+1] = v[j];
		j--;
		c=c+4;
	}
	v[j+1] = elem;
	c=c+2;
	*count =*count + c;
}