#include"(var3)struct.h"

int read_and_initialize(char *s, nod* **v, int *sursa, int *destinatie, long long *count)
{
    long long c=0;
	int i, dela, la, cost, j, n, m;
	FILE *in;
	nod* *v1;
    in = fopen(s,"r");  
    fscanf(in, "%d %d\n", &m, &n);
    fscanf(in, "%d %d\n", sursa, destinatie);
    v1 = malloc(n*sizeof(nod));
    for(i=0; i<n; i++)
    {
        c=c+2;
    	nod *santinela;
    	santinela = malloc(sizeof(nod));
    	santinela->val = -100;
    	santinela->cost = 0;
    	santinela->next = NULL;
    	santinela->prev = NULL;
    	v1[i] = santinela;
        c=c+10;
    }
    nod *puppet;
    for(i=0; i<m; i++)
    {
        c=c+2;
    	fscanf(in,"%d %d %d\n", &dela ,&la, &cost);
    	puppet = v1[dela];
        c=c+2;
    	while(puppet->next != NULL)
	    {
        	puppet = puppet->next;
            c=c+4;
        }
	    nod *new;
	    new = malloc(sizeof(nod));
	    new->val = la;
	    new->cost = cost;
	    new->prev = puppet;
	    puppet->next = new;
	    new->next = NULL;
        c=c+10;
	} 
	*v = v1;
    c=c+1;
    fclose(in);
    *count =*count +c;
return n;
}