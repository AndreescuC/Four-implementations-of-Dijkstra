int pop(int v[], int n, long long *count)
{
	long long c=0;
	int ret = v[0];
	c=c+1;
	int i;
	for(i=0; i<n-2; i++)
		v[i] = v[i+1];
	c=c+5*n;
	v[n-1] = -1;
	c=c+2;
	*count = *count + c;
return ret;
}