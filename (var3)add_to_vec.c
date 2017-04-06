void add(int v[], int dist[], int n, int elem, long long *count)
{
	long long c=0;
	int i=0;
	c=c+1;
	if(v[0] == -1)
	{	
		c=c+4;
		v[0] = elem;
		*count = *count + c;
		return;
	}
	while( (v[i] != -1) && (i < n) )
	{	
		c=c+6;
		if( v[i] == elem)
			break;	
		i ++;
		c=c+1;
	}
	int j=i-1;
	c=c+2;
	while( (j>=0) && (dist[ v[j] ] > dist[elem] ) )
	{	
		c=c+10;
		v[j+1] = v[j];
		j--;
	}
	v[j+1] = elem;
	c=c+2;
	*count = *count +c;
}