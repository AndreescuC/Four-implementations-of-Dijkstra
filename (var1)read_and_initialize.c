int read_and_initialize( char* s, int ***A, int *sursa, int *destinatie, long long *count)
{
    int m,n,i,j,k,cost,**init_A;
    long long c=0;
    FILE *in;
    in = fopen(s,"r");    
    fscanf(in, "%d %d\n", &m, &n);
    fscanf(in, "%d %d\n", sursa, destinatie);
    init_A = calloc(n, sizeof(int*));    
    c =+ n;
    for(i = 0; i<n; i++)                      
    {
        c = c + 2;
        init_A[i] = calloc(n, sizeof(int));    
        c =c + n;
    }
    for(i=0; i<n; i++)
    {
       c =c + 2;
        for(j=0; j<n; j++)       
        {
            c =c + 2;
            init_A[i][j] = -1;   
            c =c + 2;
        }
    }
    for( k=0; k<m; k++)  
    {
        c =c + 2;
        fscanf(in,"%d %d %d\n", &i ,&j, &cost);
        init_A[i][j] = cost;                                    
        c =c + 2;
    }  
    fclose(in);
    *A = init_A;                                               
    c ++;
    *count = *count + c;
return n;
}