int pop(int v[], int n, long long *count)
{
	long long c=0;
	int ret = v[0];
	c=c+2;
	for(int i=0; i<n-2; i++)
	{	
		c=c+5;
		v[i] = v[i+1];
	}
	v[n-1] = -1;
	c=c+2;
	*count = *count + c;
return ret;
}